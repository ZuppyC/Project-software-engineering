//
// Created by Dell on 26/02/2026.
//

#include "System.h"
#include <iostream>

System::System()
{

}

System* System::parser(const char* xmldoc)
{

}
void System::addMeeting(Meeting* meeting)
{
    meetings.push_back(meeting);
}

void System::addRoom(Room* room)
{
    rooms.push_back(room);
}

void System::addParticipation(Participation* participation)
{
    participations.push_back(participation);
}

