//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_SYSTEM_H
#define SOFTWAREENG_SYSTEM_H
#include <vector>
#include <fstream>

#include "Building.h"
#include "Catering.h"
#include "input.h"
#include "Meeting.h"
#include "Participation.h"
#include "Renovation.h"
#include "Campus.h"

using namespace std;

#include "Room.h"


class System
{
private:
    Input input_bestand;
    System* _initcheck;
    vector<Room*> rooms;
    vector<Meeting*> meetings;
    vector<Participation*> participations;

    vector<Renovation*> renovations;
    vector<Catering*> caterings;
    vector<Campus*> campuses;
    vector<Building*> buildings;

    double totalCo2 = 0.0;

public:
    System(const char* xmldoc);
    /*
     * Constructor voor System.
     * het XML-bestand lezen en initialiseren .
     *
     \n REQUIRE(xmldoc != NULL, "Er is geen XML bestand opgegeven");
     \n ENSURE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     */


    System();
    /*
    * Default constructor
    *
    \n ENSURE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
   */

    ~System();
    /*
     * Destructor van System.
     */

    void addRoom(Room* room);
    /*
     * Room toevoegen
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(room != NULL, "Er is geen ROOM");
     \n ENSURE(!rooms.empty() && rooms.back() == room,
              "ROOM is niet toegevoegd");
     */
    void addMeeting(Meeting* meeting);
    /*
     * Meeting toevoegen
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(meeting != NULL, "Er is geen Meeting");

     \n ENSURE(!meetings.empty() && meetings.back() == meeting,"Meeting is niet toegevoegd");
     */
    void addParticipation(Participation* participation);
    /*
    * Participation toevoegen
    *
    \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    \n REQUIRE(participation != NULL, "Er is geen participation");
    \n ENSURE(!participations.empty() &&participations.back() == participation,"Participation is niet toegevoegd");
    */

    void addBuilding(Building* building);
     /*
     * Building toevoegen
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(building != NULL, "Er is geen Building");
     \n ENSURE(!buildings.empty() && buildings.back() == building,"Building is niet toegevoegd");
     */

    void addCatering(Catering* catering);
    /*
     * Catering toevoegen
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(catering != NULL, "Er is geen Catering");
     \n ENSURE(!caterings.empty() && caterings.back() == catering,"Catering is niet toegevoegd");
     */
    void addCampus(Campus* campus);
    /*
     * Campus toevoegen
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(campus != NULL, "Er is geen Campus");
     \n ENSURE(!campuses.empty() && campuses.back() == campus,"Campus is niet toegevoegd");
     */
    void addRenovation(Renovation* renovation);
    /*
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(renovation != NULL, "Er is geen Renovation");
     \n ENSURE(!renovations.empty() && renovations.back() == renovation,"Renovation is niet toegevoegd");
     */
    Input getInput();
    /*
      *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
      */
    vector<Meeting*> getMeeting();
      /*
      *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
      */
    vector<Room*> getRooms();
    /*
     *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
     */
    vector<Participation*> getParticipations();
    /*
     *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
     */
    vector<Catering*> getCatering();
    /*
    *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
    */
    vector<Campus*> getCampus();
    /*
     *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
     */
    vector<Building*> getBuilding();
    /*
     *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
     */
    vector<Renovation*> getRenovations();
    /*
     *\n REQUIRE(properlyInitialized(),"SYSTEM is niet geinitialiseerd");
     */


    bool properlyInitialized();
    /*
     * Controleert of het System correct geïnitialiseerd is.
     */


    string getCampusFromRoom(const string& roomId);
    /*
    *
    \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    \n REQUIRE(!roomId.empty(), "Er is geen room id");
    */


    void takesPlace(Meeting* meeting);
     /*
     * Laat een meeting plaatsvinden
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(meeting != NULL, "Er is geen Meeting");
     \n ENSURE(meeting->getBezig() || meeting->getCanceled(),"Meeting is niet correct verwerkt");
     */

    void handleCatering(Meeting* meeting);
    /*
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(meeting != NULL, "Er is geen meeting");
     */

    void takePlaceEveryMeeting();
    /*
    \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    \n REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    \n REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
    \n REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");
    */


    void trackOccupancy(Meeting* meeting);
    /*
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(meeting != NULL, "Er is geen Meeting");
     \n ENSURE(!roomFound || meeting->getOccupancy() == participantsCount,"Occupancy is niet correct");
     */

    void trackCo2(Meeting* meeting);
    /* Co2 van een meeting bijhouden
     *
     \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     \n REQUIRE(meeting != NULL, "Er is geen Meeting");
     \n ENSURE(meeting->getCo2Tracked(),"CO2 moet als getracked gemarkeerd zijn");
     \n ENSURE(totalCo2 == oldTotalCo2 + meetingCo2,"totalCo2 is niet correct updated");
     */

    double getTotalCo2();
    /*
     *
    \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
     */

    void statisticsReport(const string& filename);
    /*
    *  Statistisch rapport schrijven.
    *
    \n REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    \n REQUIRE(!filename.empty(), "Er is geen bestandsnaam opgegeven");
    */



};


#endif //SOFTWAREENG_SYSTEM_H