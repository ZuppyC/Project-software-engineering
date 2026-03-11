//
// Created by Dell on 26/02/2026.
//

#include "Meeting.h"
#include <iostream>
#include <ctime>
#include <bits/locale_classes.h>

void Meeting::setId(string id) {
    this->identifier = id;
}
string Meeting::getId() {
    return identifier;
}

void Meeting::setLabel(string label) {
    this->label = label;
}
string Meeting::getLabel() {
    return label;
}

void Meeting::setRoom(string roomnr) {
    this->Room = roomnr;
}
string Meeting::getRoom() {
    return Room;
}

void Meeting::setDate(const string& a) {
    date = strToTm(a);
}
tm* Meeting::getDate() const {
    return date;
}

tm* Meeting::strToTm(const string& datum) {

    int jaar = stoi(datum.substr(0, 4));

    int maand= stoi(datum.substr(5, 2));

    int dag = stoi(datum.substr(8, 2));

    tm* time= new tm();
    time->tm_mday= dag;
    time->tm_mon= maand;
    time->tm_year= jaar;

    return time;
}

void Meeting::setPart(Participation *part) {
    participants = part;
}

Participation* Meeting::getPart() const {
    return participants;
}


bool Meeting::isPast() {
    time_t t = time(nullptr);
    tm* today = localtime(&t);

    tm* mdate = date;
    bool a = today->tm_year+1900 > mdate->tm_year;
    bool b= today->tm_year+1900 == mdate->tm_year && today->tm_mon+1 > mdate->tm_mon;
    bool c= today->tm_year+1900 == mdate->tm_year && today->tm_mon+1 == mdate->tm_mon && today->tm_mday > mdate->tm_mday;
    return a||b||c;
}