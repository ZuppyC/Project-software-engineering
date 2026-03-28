//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_SYSTEM_H
#define SOFTWAREENG_SYSTEM_H
#include <vector>
#include <fstream>
#include "Meeting.h"
#include "Participation.h"

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
    void addParticipation(Participation* participation);

    vector<Meeting*> getMeeting();
    vector<Room*> getRooms();
    vector<Participation*> getParticipations();




    void printBlok(ofstream& outputFile, Meeting* m);

    void print(string filename);


    bool properlyInitialized();


    void takesPlace(Meeting* meeting);

    void takePlaceEveryMeeting();

};


#endif //SOFTWAREENG_SYSTEM_H