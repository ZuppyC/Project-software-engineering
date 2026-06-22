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

    // input_bestand.eerste_parserCB(xmldoc,cerr, this);
    //
    // input_bestand.parser_catering(xmldoc,cerr, this);
    //
    // input_bestand.parserMRP(xmldoc,cerr, this);
    //
    // input_bestand.parser_renovatie(xmldoc,cerr,this);
    _initcheck = this;

    REQUIRE(xmldoc != nullptr, "Er is geen XML bestand opgegeven");

    input_bestand.parseAll(xmldoc,cerr, this);

    input_bestand.consistencyCheck(cerr,this);

    input_bestand.returnConsistency(this);


    ENSURE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
}

System::System()
{
    _initcheck = this;
}


void System::addParticipation(Participation* participation) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(participation != nullptr, "Er is geen participation");
    participations.push_back(participation);
    ENSURE(!participations.empty() && participations.back() ==participation, "Participation is niet toegevoegd");
}

vector<Room*> System::getRooms() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return rooms;
}

vector<Participation*> System::getParticipations() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return participations;
}
void System::addRoom(Room *room) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(room != nullptr, "Er is geen ROOM");
    rooms.push_back(room);
    ENSURE(!rooms.empty() && rooms.back() == room, "ROOM is niet toegevoegd");
}

void System::addMeeting(Meeting* meeting) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(meeting != nullptr, "Er is geen Meeting");
    meetings.push_back(meeting);
    ENSURE(!meetings.empty() && meetings.back() == meeting, "Meeting is niet toegevoegd");
}

void System::addBuilding(Building* building) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(building != nullptr, "Er is geen Building");
    buildings.push_back(building);
    ENSURE(!buildings.empty() && buildings.back() == building, "Building is niet toegevoegd");
}

void System::addCampus(Campus* campus) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(campus != nullptr, "Er is geen Campus");
    campuses.push_back(campus);
    ENSURE(!campuses.empty() && campuses.back() == campus, "Campus is niet toegevoegd");

}

void System::addCatering(Catering* catering) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(catering != nullptr, "Er is geen Catering");
    caterings.push_back(catering);
    ENSURE(!caterings.empty() && caterings.back() == catering, "Catering is niet toegevoegd");
}

void System::addRenovation(Renovation* renovation) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(renovation != nullptr, "Er is geen Renovation");
    renovations.push_back(renovation);
    ENSURE(!renovations.empty() && renovations.back() == renovation, "Renovation is niet toegevoegd");
}

double System::getTotalCo2() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return totalCo2;
}


void System::takesPlace(Meeting* meeting) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(meeting != nullptr, "Er is geen MEETING");
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

    ENSURE(meeting->getBezig() || meeting->getCanceled(), "Meeting hasnt taken place or hasnt been canceled.");
}

void System::handleCatering(Meeting* meeting) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
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
        REQUIRE(p != nullptr, "PARTICIPATION is een nullptr");
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
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(meeting != nullptr, "Er is geen MEETING");

    double oldTotalCo2 = totalCo2;
    double meetingCo2 =0.0;

    if (meeting->getCo2Tracked()) {
        return;
    }

    vector<Participation*> parts = meeting->getPart();

    for (Participation* p : parts) {
        REQUIRE(p != nullptr, "Participation is een nullptr");
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
            REQUIRE(c != nullptr, "Catering is een nullptr");
            if (c->getCampus()==campus) {
                meetingCo2 +=c->getCo2()*parts.size();
                break;
            }
        }

        }
    totalCo2 += meetingCo2;
    meeting->setCo2Tracked(true);
    ENSURE(meeting->getCo2Tracked(), "CO2 moet als getracked gemarkeerd zijn");
    ENSURE(totalCo2 == oldTotalCo2 + meetingCo2, "totalCo2 is niet correct updated");
    }




string System::getCampusFromRoom(const string& roomId) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(!roomId.empty(), "Er is geen room id");
    for (Room* r : rooms) {
        if (r->getIdentifier() == roomId) {
            return r->getCampus();
        }
    }
    return "";
}


void System::trackOccupancy(Meeting* meeting) {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(meeting != nullptr, "Er is geen Meeting");

    int participantsCount = meeting->getPart().size();
    bool roomFound = false;

    for (Room* r :rooms) {
        if (r->getIdentifier() == meeting->getRoom()) {
            meeting->setOccupancy(participantsCount);
            roomFound=true;
            break;
        }
    }
    ENSURE(!roomFound || meeting->getOccupancy() == participantsCount,"Occupancy is niet correct");
}

void System::statisticsReport(const string& filename) {

    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    REQUIRE(!filename.empty(), "Er is geen bestandsnaam opgegeven");
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Kan statistics report niet openen" << endl;
        return;
    }
    int onlineMeetings = 0;
    int canceledMeetings = 0;
    int cateringMeetings = 0;
    int totalParticipants = 0;
    for (Meeting* m : meetings) {
        if (m->getOnline()) {
            onlineMeetings++;
        }
        if (m->getCanceled()) {
            canceledMeetings++;
        }
        if (m->getCatering()) {
            cateringMeetings++;
        }
        totalParticipants += m->getPart().size();
    }

    auto print = [&](ostream& out) {
        out << "STATISTICS REPORT: " << endl;
        out << "Total meetings: " << meetings.size() << endl;
        out << "Online meetings: " << onlineMeetings << endl;
        out << "Canceled meetings: " << canceledMeetings << endl;
        out << "Meetings with catering: " << cateringMeetings << endl;
        out << "Total participants: " << totalParticipants << endl;
        out << "Total CO2: " << totalCo2 << endl;
    };

    print(cout);
    print(file);

    file.close();
}



void System::takePlaceEveryMeeting() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
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
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return meetings;
}

vector<Catering*> System::getCatering() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return caterings;
}

bool System::properlyInitialized()
{
    return _initcheck ==this;
}

vector<Building *> System::getBuilding() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return buildings;
}

vector<Campus *> System::getCampus() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return campuses;
}


vector<Renovation*> System::getRenovations()
{
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return renovations;
}




// vector<Building*> getBuilding();
// vector<Renovation*> getRenovations();
System::~System()
{
    for (Meeting* m : meetings)
    {
        delete m;
    }
    for (Participation* p : participations)
    {
        delete p;
    }
    for (Catering* c : caterings)
    {
        delete c;
    }
    for (Campus* c : campuses)
    {
        delete c;
    }
    for (Building* b : buildings)
    {
        delete b;
    }
    for (Room* r : rooms)
    {
        delete r;
    }
    for (Renovation* r : renovations)
    {
        delete r;
    }

}

Input System::getInput() {
    REQUIRE(properlyInitialized(), "SYSTEM is niet geinitialiseerd");
    return input_bestand;
}
