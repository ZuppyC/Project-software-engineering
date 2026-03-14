//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_SYSTEM_H
#define SOFTWAREENG_SYSTEM_H
#include <vector>
#include <fstream>
#include "Meeting.h"
#include "Participation.h"
#include "../xmlparser/tinyxml.h"
using namespace std;

#include "Room.h"


class System
{
private:
    System* _initcheck;
    ofstream meetingPlanner;
    vector<Room*> rooms;
    vector<Meeting*> meetings;
    vector<Participation*> participations;
public:
    System();
    void addRoom(Room* room);
    void addMeeting(Meeting* meeting);

    vector<Meeting*> getMeeting();





    /*
     * de volgende 3 require zijn om te checken of er in de xmlfile minstens 1 ROOM, MEETING EN PARTICIPATION zit
    *    REQUIRE( s != nullptr && s->FirstChildElement("ROOM") != nullptr, "De XML bestand moet ROOM element hebben.");
    REQUIRE(s != nullptr && s->FirstChildElement("PARTICIPATION") != nullptr, "De XML bestand moet PARTICIPATION element hebben.");
    REQUIRE(s != nullptr && s->FirstChildElement("MEETING") != nullptr, "De XML bestand moet MEETINGS element hebben.");
     *
     *
     */
    System* parser(const char* doc);
    /*
     *    IF ROOM
     *  voor elke room checkt deze require checkt of capacity bij room een int getal is en of het een grotere getal is dan 0
    REQUIRE(false, "CAPACITY moet een int zijn");
    REQUIRE(cap>0, "CAPACITY moet groter zijn dan 0");
    hiermee checht het of er een NAME element is in een ROOM

    ELSE IF MEETING checken of elke element die moet voorkomen voorkomt
    ENSURE(!meetNgreet->getId().empty(), "Er is geen IDENTIFIER gelezen");
    ENSURE(!meetNgreet->getLabel().empty(), "Er is geen LABEL gelezen");
    ENSURE(!meetNgreet->getRoom().empty(), "Er is geen ROOM gelezen");
    ENSURE(meetNgreet->getDate() != nullptr, "Er is geen DATE gelezen");
    ELSE IF PARTICIPATION
    checken of elke element die moet voorkomen voorkomt
    ENSURE(!participatie->getUser().empty(), "Er is geen USER gelezen");
    ENSURE(!participatie->getmeeting().empty(), "Er is geen MEETING gelezen");
     *
     *
     *extra checks zoals:
     *checken of elke meeting een VALID ROOM heeft
     *ENSURE(gevonden, "MEETING wijst naar ROOM die niet bestaat");
     *
     *checken of elke participatie een VALID MEETING hebben
     *ENSURE(found, "PARTICIPATION wijst naar een MEETING die niet bestaat");
     *
     *checken of er zeker genoeg ruimte is voor elke meeting
     *REQUIRE(teller<= r->getCapacity(), "Aantal PARTITCIPATIONs is groter dan ROOM CAPACITY");
     *
     * GEEN DUBBELE ID ZIJN voor een meeting
     *ENSURE(meetings[i]->getId() != meetings[j]->getId(),"Dubbele MEETING IDENTIFIER");
     *EN GEEN DUBBELE ID voor een room
     *ENSURE(rooms[i]->getIdentifier() != rooms[j]->getIdentifier(),"Dubbele ROOM IDENTIFIER");
     *
     *
     *en uiteindelijk of alles juist geinitialiseerd is in het systeem
    *ENSURE(!rooms.empty(),"geen room");
    ENSURE(!meetings.empty(),"geen meeting");
    ENSURE(!participations.empty(),"geen participatie");
    ENSURE(system->properlyInitialized(), "de systeem is fout geinitialiseerd");
     *
     *
     *
     */


    void printBlok(ofstream& outputFile, Meeting* m);
 /*
  * hulp functie voor print functie
  *
  */


    void print(string filename);
 /*
  * de SYSTEEM IS JUIST geinitialiseerd
  *REQUIRE(this->properlyInitialized(),"De systeem is fout geinitialiseerd");
 * REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
   REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
   REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");
  *
  * post conditie de output file is correct aangemaakt
  * ENSURE(outputFile.is_open() && !outputFile.fail(), "Output bestand is niet correct gemaakt");
  */



    bool properlyInitialized();
 /*checkt of de SYSTEM juist geinitialiseerd is
  */



    void takesPlace(Meeting* meeting);
    /*
     * checkt voor de ingegeven meeting of die kan beginnen en print een message of die wel of niet kan
     * de systeem is juist geinitialiseerd
     * REQUIRE(this->properlyInitialized(),"De systeem is fout geinitialiseerd");
 *     REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
       REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
       REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");

       post conditie de meeting wordt of geaccepterd of gecancelled
       ENSURE(meeting->getBezig() || meeting->getCanceled(), "Meeting hasnt taken place, or hasnt been canceled.");
     */


    void takePlaceEveryMeeting();
    /*
     *checkt voor elke meeting in de volgorde van de XML file of die wel of niet kunnen doorgaan
 *  REQUIRE(this->properlyInitialized(),"De systeem is fout geinitialiseerd");
    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
    REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");
     *
     *
     *post conditie
     *ENSURE(m->getBezig() || m->getCanceled(), "Meeting hasnt taken place, or hasnt been canceled.");
     *elke meeting is of gecancelled of niet en gaat dus door.
     */


};


#endif //SOFTWAREENG_SYSTEM_H