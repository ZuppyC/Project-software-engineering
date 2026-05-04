#ifndef SOFTWAREENG_MEETING_H
#define SOFTWAREENG_MEETING_H

#include <string>
#include "Catering.h"
#include "Participation.h"

using namespace std;

class Meeting {
private:
    Meeting* _initCheck;
    string label;
    string identifier;
    string room;
    tm* date = nullptr;
    bool isOnline = false;
    vector<Participation*> participants;
    bool isBezig = false;
    bool hasCatering = false;
    bool hasExternals = false;
    bool isCanceled = false;
    int hour;
    int occupancy = 0;
    bool co2Tracked = false;

public:

    Meeting();
    /*
     * Constructor voor Meeting
     */

    bool properlyInitialized();

    void setLabel(string label);
    /*
     * getters en setters voor de meeting LABEL
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(!label.empty(), "Er is geen LABEL");
     \n ENSURE(this->label==label, "LABEL is niet gelezen");
     */
    string getLabel();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    void setId(string id);
    /*
     * getters en setters voor de meetingID
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(!id.empty(), "Er is geen MEETING");
     \n ENSURE(this->identifier==id, "MEETING is niet gelezen");
     */
    string getId();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    void setRoom(string roomnr);
    /*
     * getters en setters voor een room
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(!roomnr.empty(), "Er is geen ROOM");
     \n ENSURE(this->room==roomnr, "ROOM is niet gelezen");
     */
    string getRoom();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    void setDate(const string& string);
    /*
     * getters en setters voor de meeting DATE
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(string.size() == 10 && string[4]=='-' && string[7]=='-', "DATE moet formaat YYYY-MM-DD zijn");
     \n ENSURE(date != nullptr, "DATE is niet gelezen");
     */
    tm* getDate() const;

    void setPart(Participation* part);
    /*
     * getters en setters voor participations in de meeting
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(part != nullptr, "Er is geen PARTICIPATION");
     \n ENSURE(part_in_p, "PARTICIPATION is niet gelezen");
     */
    vector<Participation*> getPart() const;

    tm* strToTm(const string& datum);
    /*
     * functie die een string omzet naar tm
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(datum.size() == 10 && datum[4]=='-' && datum[7]=='-', "DATE moet formaat YYYY-MM-DD zijn");
     \n ENSURE(maand<13, "De maand kan niet hoger zijn dan 12");
     \n ENSURE(maand>0, "De maand kan niet kleiner zijn dan 1");
     \n ENSURE(dag>0,"De dag kan niet kleiner zijn dan 1");
     \n ENSURE((dag<30 && dertig) || (dag<31 && !dertig), "De dag kan niet groter zijn dan 30 of 31");
     */

    bool isPast();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    bool conflictsWith(Meeting *m);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(m != nullptr, "Er is geen MEETING");
     */

    bool getBezig();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */
    void setBezig(bool bezig);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n ENSURE(isBezig==bezig, "isBezig variabele niet goed ingesteld");
     */

    bool getCanceled();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */
    void setCanceled(bool canceled);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n ENSURE(isCanceled==canceled, "IsCanceled variabele niet goed ingesteld");
     */

    bool getOnline();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */
    void setOnline(bool online);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    int getHour();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */
    void setHour(int h);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(h >= 0 && h <= 23, "Hour moet tusssen 0 en 23 zijn ");
     \n ENSURE(hour == h, "Hour is niet correct gezet");
     */

    bool getCo2Tracked();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */
    void setCo2Tracked(bool tracked);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n ENSURE(co2Tracked==true||co2Tracked==false, "CO2tracking is niet goed gelezen.");
     */

    bool getCatering();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */
    void setCatering(string catering);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(catering=="true"||catering=="false", "De CATERING variabele mag alleen 'true' of 'false' zijn.");
     \n ENSURE(hasCatering==true && catering=="true"||hasCatering==false && catering=="false", "De EXTERNALS variabele is niet juist gelezen.");
     */

    bool getExternals();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */
    void setExternals(string externals);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(externals=="true"||externals=="false", "De EXTERNALS variabele mag alleen 'true' of 'false' zijn.");
     \n ENSURE(hasExternals==true && externals=="true"||hasExternals==false && externals=="false", "De EXTERNALS variabele is niet juist gelezen.");
     */

    void setOccupancy(int occupancy);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     \n REQUIRE(occupancy>1, "Er moeten 2 or meer mensen in de ROOM kunnen");
     \n ENSURE(occupancy==occupancy, "OCCUPANCY is niet goed ingesteld");
     */
    int getOccupancy();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    void printMeeting(ofstream& outputFile);
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    double co2ZonderCatering();
    /*
     \n REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
     */

    ~Meeting();
    /*
     * destructor van Meeting
     */
};

#endif //SOFTWAREENG_MEETING_H