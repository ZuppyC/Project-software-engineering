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
    string label = "";
    string identifier = "";
    string Room = "";
    tm* date= nullptr;
    Participation* participants= nullptr;
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
    Participation* getPart() const;

    tm* strToTm(const string& datum);

    bool isPast();


};


#endif //SOFTWAREENG_MEETING_H