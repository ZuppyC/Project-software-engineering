//
// Created by Dell on 26/02/2026.
//

#include "System.h"
#include <iostream>
#include "../src/DesignByContract.h"
#include <fstream>

#include "input.h"

System::System(const char* xmldoc)
{
    input_bestand.eerste_parserCB(xmldoc, this);

    input_bestand.parser_catering(xmldoc, this);

    input_bestand.parserMRP(xmldoc, this);

    input_bestand.parser_renovatie(xmldoc,this);

    _initcheck = this;

}

System::System()
{

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

void System::addBuilding(Building* building) {
    buildings.push_back(building);
}

void System::addCampus(Campus* campus) {
    campuses.push_back(campus);
}

void System::addCatering(Catering* catering) {
    caterings.push_back(catering);
}

void System::addRenovation(Renovation* renovation) {
    renovations.push_back(renovation);
}

double System::getTotalCo2() {

    return totalCo2;
}


void System::takesPlace(Meeting* meeting) {

    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");




    if (!meeting->getExternals()) {
        for (Participation* p: meeting->getPart()) {
            if (p->getExternal()) {
                cout<<"User: "<<p->getUser()<<", can't participate in this meeting"<<meeting->getId()<<endl;
            }
        }
        cout<<"External users are not allowed in: "<< meeting->getId()<<endl;
    }

    if (meetings.size()==1 ) {
        cout<<"Meeting takes place"<<endl;
        meeting->setBezig(true);
        trackCo2(meeting);
        if (!meeting->getOnline()) {
            trackOccupancy(meeting);
            handleCatering(meeting);
        }

    }
    else if (meeting->getOnline()==true) {
        cout<<"Meeting takes place online: "<<meeting->getId()<<endl;
        meeting->setBezig(true);
        trackCo2(meeting);
    }

    else{
        for (Renovation* r: renovations) {
            if (r->isTussen(meeting->getDate())) {
                cerr<<"The room is being renovated, meeting canceled: "<< meeting->getId() <<endl;
                meeting->setCanceled(true);
                return;
            }
        }
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
        trackCo2(meeting);
        trackOccupancy(meeting);
        handleCatering(meeting);


    }

    ENSURE(meeting->getBezig() || meeting->getCanceled(), "Meeting hasnt taken place, or hasnt been canceled.");
}

void System::handleCatering(Meeting* meeting) {
    REQUIRE(meeting!=nullptr,"Er is geen meeting");
    if (!meeting->getCatering()) {
        return;
    }

    if (meeting->getOnline()) {
        cerr << "Online meetings cannot have catering: " << meeting->getId() << endl;
        return;
    }

    double totalCost= 0.0;
    vector<Participation*> parts = meeting->getPart();

    for (Participation* p : parts) {
        if (p->getExternal()) {
            totalCost += 20.79;
        } else {
            totalCost += 10.59;
        }
    }
    ofstream cateringFile("catering.txt");
    if (!cateringFile.is_open()) {
        cerr << "Kan cateringbestand niet openen" << endl;
        return;
    }

    tm* d = meeting->getDate();

    cateringFile << "Meeting ID : " << meeting->getId() << endl;
    cateringFile << "Location : " << meeting->getRoom() << endl;
    cateringFile << "Date: " << d->tm_mday << "/" << d->tm_mon + 1 << "/" << d->tm_year + 1900 << endl;
    cateringFile << "Time: " << meeting->getHour() << "h" << endl;
    cateringFile << "Catering cost : EUR " << totalCost << endl;

}

void System::trackCo2(Meeting* meeting) {
    REQUIRE(meeting != nullptr, "Er is geen MEETING");

    if (meeting->getCo2Tracked()) {
        return;
    }

    double meetingCo2 =0.0;
    vector<Participation*> parts = meeting->getPart();

    for (Participation* p : parts) {
        if (meeting->getOnline()) {
            meetingCo2 +=30;
        }
        else if (p->getExternal()) {
            meetingCo2 += 1200;
        }
        else {
            meetingCo2 +=120;
        }
    }

    if (meeting->getCatering() && !meeting->getOnline()) {
        string campus = getCampusFromRoom(meeting->getRoom());

        for (Catering* c : caterings) {
            if (c->getCampus()==campus) {
                meetingCo2 +=c->getCo2()*parts.size();
                break;
            }
        }



        }
    totalCo2 += meetingCo2;
    meeting->setCo2Tracked(true);
    }




string System::getCampusFromRoom(const string& roomId) {
    for (Room* r : rooms) {
        if (r->getIdentifier() == roomId) {
            return r->getCampus();
        }
    }
    return "";
}


void System::trackOccupancy(Meeting* meeting) {
    REQUIRE(meeting != nullptr, "Er is geen Meeting");

    int participantsCount = meeting->getPart().size();

    for (Room* r :rooms) {
        if (r->getIdentifier() == meeting->getRoom()) {
            meeting->setOccupancy(participantsCount);
            return;
        }
    }
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

vector<Catering*> System::getCatering() {
    return caterings;
}

bool System::properlyInitialized()
{
    return _initcheck ==this;
}




