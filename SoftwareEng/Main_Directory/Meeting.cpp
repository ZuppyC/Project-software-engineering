    //
// Created by Dell on 26/02/2026.
//

#include "Meeting.h"
#include <iostream>
#include <ctime>
#include <bits/locale_classes.h>
#include "../src/DesignByContract.h"

Meeting::Meeting() {
    _initCheck = this;
}

bool Meeting::properlyInitialized() {
    return _initCheck == this;
}



void Meeting::setId(string id) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    REQUIRE(!id.empty(), "Er is geen MEETING");
    this->identifier = id;
    ENSURE(this->identifier==id, "MEETING is niet gelezen");
}
string Meeting::getId() {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    return identifier;
}

void Meeting::setLabel(string label) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    REQUIRE(!label.empty(), "Er is geen LABEL");

    this->label = label;
    ENSURE(this->label==label, "LABEL is niet gelezen");
}
string Meeting::getLabel() {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    return label;
}

void Meeting::setRoom(string roomnr) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    REQUIRE(!roomnr.empty(), "Er is geen ROOM");
    this->room = roomnr;
    ENSURE(this->room==roomnr, "ROOM is niet gelezen");
}
string Meeting::getRoom() {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    return room;
}

void Meeting::setDate(const string& a) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    REQUIRE(a.size() == 10, "DATE moet formaat YYYY-MM-DD zijn");
    date = strToTm(a);
    ENSURE(date != nullptr, "DATE is niet gelezen");
}
tm* Meeting::getDate() const {

    return date;
}

tm* Meeting::strToTm(const string& datum) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");

    int jaar = stoi(datum.substr(0, 4));

    int maand= stoi(datum.substr(5, 2));

    int dag = stoi(datum.substr(8, 2));

    tm* time= new tm();
    time->tm_mday= dag;
    time->tm_mon= maand;
    time->tm_year= jaar;

    return time;
}

void Meeting::setPart(Participation* part) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    REQUIRE(part != nullptr, "Er is geen PARTICIPATION");
    participants.push_back(part);
    bool part_in_p= false;
    for (Participation* part_ :participants) {
        if (part==part_) {
            part_in_p= true;
        }
    }
    ENSURE(part_in_p, "PARTICIPATION is niet gelezen");
}

vector<Participation*> Meeting::getPart() const {

    return participants;
}


bool Meeting::isPast() {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    time_t t = time(nullptr);
    tm* today = localtime(&t);

    tm* mdate = date;
    bool a = today->tm_year+1900 > mdate->tm_year;
    bool b= today->tm_year+1900 == mdate->tm_year && today->tm_mon+1 > mdate->tm_mon;
    bool c= today->tm_year+1900 == mdate->tm_year && today->tm_mon+1 == mdate->tm_mon && today->tm_mday > mdate->tm_mday;
    return a||b||c;
}

bool Meeting::conflictsWith(Meeting* m) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    REQUIRE(m != nullptr, "Er is geen MEETING");
    tm* d1 = this->date;
    tm* d2 = m->getDate();

    if (d1->tm_mday == d2->tm_mday && d1->tm_mon == d2->tm_mon && d1->tm_year == d2->tm_year
        && room== m->getRoom() && hour== m->getHour());{
        return true;

    }
    return false;
}

bool Meeting::getBezig() {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    return isBezig;
}

void Meeting::setBezig(bool bezig) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    isBezig= bezig;
}

void Meeting::setCanceled(bool canceled) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    isCanceled= canceled;
}

bool Meeting::getCanceled() {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    return isCanceled;
}

bool Meeting::getOnline() {
    return isOnline;
}

void Meeting::setOnline(bool online) {
    isOnline= online;
}

bool Meeting::getCatering() {
    return hasCatering;
}
void Meeting::setCatering(string catering) {
    if (catering=="true") {
        hasCatering= true;
    }
    else {
        hasCatering= false;
    }
}

bool Meeting::getExternals() {
    return hasExternals;
}

void Meeting::setExternals(string externals) {
    if (externals=="true") {
        hasExternals= true;
    }
    else {
        hasExternals= false;
    }
}

int Meeting::getHour() {
    return hour;
}

void Meeting::setHour(int h) {
    REQUIRE(properlyInitialized(), "MEETING is niet geinitialiseerd");
    REQUIRE(h >= 0 && h <= 23, "Hour moet tusssen 0 en 23 zijn ");
    hour = h;
    ENSURE(hour == h, "Hour is niet correct gezet");
}

void Meeting::setOccupancy(int occupancy) {
    this->occupancy = occupancy;
}

int Meeting::getOccupancy() {
    return occupancy;
}

void Meeting::printMeeting() {
    cout<<"["<<identifier<<"]"<<endl;
    tm* d1 = date;
    cout<<" -  Time:  "<<d1->tm_mday<<"/"<<d1->tm_mon<<"/"<<d1->tm_year<<", "<<hour<<"h00"<<endl;
    cout<<" -  Location:  "<<room<<endl;
    if (hasExternals) {
        cout<<" -  Externals allowed"<<endl;
    }
    else {
        cout<<" -  Externals not allowed"<<endl;
    }
    if (hasCatering) {
        cout<<" -  Catering"<<endl;
    }
    else {
        cout<<" -  No Catering"<<endl;
    }

    cout<<" -  CO2 emitted:  "<<"HIER MOET NOG CO2 BEREKEND WORDEN"<<"\n"<<endl;
}