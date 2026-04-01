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
