//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_SYSTEM_H
#define SOFTWAREENG_SYSTEM_H
#include <vector>

#include "Meeting.h"
#include "Participation.h"
using namespace std;

#include "Room.h"


class System
{
private:
    vector<Room*> rooms;
    vector<Meeting*> meetings;
    vector<Participation*> participation;
public:
};


#endif //SOFTWAREENG_SYSTEM_H