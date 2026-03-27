//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_MEETING_H
#define SOFTWAREENG_MEETING_H
#include <string>
#include "Participation.h"
using namespace std;

class Meeting
{
private:
    Meeting* _initCheck;
    string label;
    string identifier;
    string room;
    tm* date= nullptr;
    vector<Participation*> participants;
    bool isBezig= false;
    bool isCanceled= false;
public:

    Meeting();
    /*
     * Constructor voor Meeting
     */


    bool properlyInitialized();

    void setLabel(string label);
    string getLabel();
    /*
     *getters en setters voor de meeting LABEL
     *
     */

    void setId(string id);
    string getId();
    /*
     *
     * getters en setters voor de meetingID
     */

    void setRoom(string roomnr);
    string getRoom();
    /*
     *
     * getters en setters voor een room
     */

    void setDate(const string& string);
    tm* getDate() const;

    void setPart(Participation* part);
    vector<Participation*> getPart() const;
    /*
     *getters en setters voor users die participeren in de meeting
     */

    tm* strToTm(const string& datum);

    bool isPast();
    /*
     *functie dat kijkt of het meeting al in het verleden was of niet
     */

    bool conflictsWith(Meeting *m);
    /*
     *
     * functie die checkt of een gegeven meeting conflicts met eender andere meeting in het systeem
     */

    bool getBezig();
    void setBezig(bool bezig);
    /*
     * getters en setters voor bezig,
     * zet een meeting in een status 'has taken place'
     */


    bool getCanceled();
    void setCanceled(bool canceled);
    /*
     * getters en setters voor canceled,
     * om te zien of een meeting gecancelled is of niet
     *
     */






};


#endif //SOFTWAREENG_MEETING_H