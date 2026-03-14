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
    string label;
    string identifier;
    string room;
    tm* date= nullptr;
    vector<Participation*> participants;
    bool isBezig= false;
    bool isCanceled= false;
public:
    void setLabel(string label);
    string getLabel();

    void setId(string id);
    string getId();

    void setRoom(string roomnr);
    string getRoom();

    void setDate(const string& string);
    tm* getDate() const;

    void setPart(Participation* part);
    vector<Participation*> getPart() const;

    tm* strToTm(const string& datum);

    bool isPast();

    bool conflictsWith(Meeting *m);

    bool getBezig();
    void setBezig(bool bezig);

    bool getCanceled();
    void setCanceled(bool canceled);






};


#endif //SOFTWAREENG_MEETING_H