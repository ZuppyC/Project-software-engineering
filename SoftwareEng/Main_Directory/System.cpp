//
// Created by Dell on 26/02/2026.
//

#include "System.h"
#include <iostream>
#include "../src/DesignByContract.h"
#include <fstream>

System::System()
{
    _initcheck = this;


}
void System::addParticipation(Participation* participation) {
    participations.push_back(participation);
}

vector<Room*> System::getRooms() {
    return rooms;
}

vector<Participation*> System::getParticipations() {
    return participations;
}
void System::addRoom(Room *room) {
    rooms.push_back(room);
}

void System::addMeeting(Meeting* meeting) {
    meetings.push_back(meeting);
}




void System::takesPlace(Meeting* meeting) {

    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");


    if (meetings.size()==1) {
        cout<<"Meeting takes place"<<endl;
        meeting->setBezig(true);

    }
    else{
        for (Meeting* m: meetings) {
            if (m==meeting) {
                continue;
            }
            else if (meeting->conflictsWith(m) && m->getBezig()) {

                cerr<<"The room is occupied, meeting canceled: "<< meeting->getId() <<endl;
                meeting->setCanceled(true);
                return;
            }
        }

        cout<<"Meeting takes place: "<< meeting->getId() <<endl;
        meeting->setBezig(true);


    }
    ENSURE(meeting->getBezig() || meeting->getCanceled(), "Meeting hasnt taken place, or hasnt been canceled.");
}


void System::takePlaceEveryMeeting() {

    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
    REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");

    for (int i =0; i< meetings.size();i++) {
        this->takesPlace(this->getMeeting()[i]);

    }

    for (Meeting* m: meetings) {
        ENSURE(m->getBezig() || m->getCanceled(), "Meeting hasnt taken place, or hasnt been canceled.");
    }

}


vector<Meeting *>System::getMeeting() {
    return meetings;
}


bool System::properlyInitialized()
{
    return _initcheck ==this;
}



