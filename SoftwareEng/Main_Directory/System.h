//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_SYSTEM_H
#define SOFTWAREENG_SYSTEM_H
#include <vector>

#include "Meeting.h"
#include "Participation.h"
#include "../xmlparser/tinyxml.h"
using namespace std;

#include "Room.h"


class System
{
private:
    System* _initcheck;
    vector<Room*> rooms;
    vector<Meeting*> meetings;
    vector<Participation*> participations;
public:
    System();
    void addRoom(Room* room);
    void addMeeting(Meeting* meeting);
    void addParticipation(Participation* participation);
    System* parser(const char* doc);

    void printBlok(ofstream& outputFile, Meeting* m);
    void print(string filename);



    bool properlyInitialized();
};


#endif //SOFTWAREENG_SYSTEM_H