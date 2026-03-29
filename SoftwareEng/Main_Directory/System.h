//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_SYSTEM_H
#define SOFTWAREENG_SYSTEM_H
#include <vector>
#include <fstream>

#include "input.h"
#include "Meeting.h"
#include "Participation.h"

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
public:
    System(const char* xmldoc);
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