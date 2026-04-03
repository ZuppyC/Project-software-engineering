//
// Created by Gebruiker on 01.04.2026.
//

#include "Renovation.h"


tm *Renovation::strToTm(const std::string &datum)
{
    int jaar = stoi(datum.substr(0, 4));

    int maand= stoi(datum.substr(5, 2));

    int dag = stoi(datum.substr(8, 2));

    tm* time= new tm();
    time->tm_mday= dag;
    time->tm_mon= maand;
    time->tm_year= jaar;

    return time;

}




void Renovation::setBeginDatum(const std::string &string)
{
    begindatum = strToTm(string);

}

void Renovation::setEindDatum(const std::string &string)
{
    einddatum = strToTm(string);

}

void Renovation::setRoom(const std::string &room) {
    this->room = room;
}

string Renovation::getRoom() {
    return room;
}

bool Renovation::isTussen(tm *datum) {
    if (begindatum->tm_year > datum->tm_year || einddatum->tm_year < datum->tm_year) {
        return false;
    }
    else if (begindatum->tm_year == datum->tm_year && begindatum->tm_mon > datum->tm_mon) {
        return false;
    }
    else if (einddatum->tm_year == datum->tm_year && einddatum->tm_mon < datum->tm_mon) {
        return false;
    }
    else if (begindatum->tm_mon== datum->tm_mon && begindatum->tm_mday > datum->tm_mday) {
        return false;
    }
    else if (einddatum->tm_mon==datum->tm_mon && einddatum->tm_mday < datum->tm_mday) {
        return false;
    }
    else {
        return true;
    }
}
