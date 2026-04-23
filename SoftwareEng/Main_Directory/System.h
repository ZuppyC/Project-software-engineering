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
    System();
    void addRoom(Room* room);
    void addMeeting(Meeting* meeting);
    void addParticipation(Participation* participation);
    void addBuilding(Building* building);
    void addCatering(Catering* catering);
    void addCampus(Campus* campus);
    void addRenovation(Renovation* renovation);

    vector<Meeting*> getMeeting();
    vector<Room*> getRooms();
    vector<Participation*> getParticipations();
    vector<Catering*> getCatering();



    bool properlyInitialized();


    void takesPlace(Meeting* meeting);

    void handleCatering(Meeting* meeting);

    void takePlaceEveryMeeting();

    void trackOccupancy(Meeting* meeting);

    void trackCo2(Meeting* meeting);

    double getTotalCo2();



};


#endif //SOFTWAREENG_SYSTEM_H