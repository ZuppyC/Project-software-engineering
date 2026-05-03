//
// Created by Gebruiker on 01.04.2026.
//

#include "Renovation.h"
#include "../src/DesignByContract.h"
#include <iostream>

Renovation::Renovation() {
    _initCheck = this;
}

bool Renovation::properlyInitialized() {
    return _initCheck == this;
}
//
// Created by Dell on 03/05/2026.
//

#include "Renovation.h"
#include "../src/DesignByContract.h"
#include <stdexcept>

tm* Renovation::strToTm(const std::string &datum)
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    REQUIRE(datum.size() == 10 && datum[4] == '-' && datum[7] == '-', "Datum moet formaat YYYY-MM-DD zijn");

    int jaar = stoi(datum.substr(0, 4));
    int maand = stoi(datum.substr(5, 2));
    int dag = stoi(datum.substr(8, 2));

    REQUIRE(maand >= 1 && maand <= 12, "Maand moet tussen 1 en 12 zijn");
    REQUIRE(dag >= 1 && dag <= 31, "Dag moet tussen 1 en 31 zijn");

    tm* time = new tm();
    time->tm_mday = dag;
    time->tm_mon = maand - 1;
    time->tm_year = jaar - 1900;

    ENSURE(time != nullptr, "tm pointer is niet aangemaakt");

    return time;
}

void Renovation::setBeginDatum(const std::string &string)
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    REQUIRE(string.size() == 10 && string[4] == '-' && string[7] == '-', "Datum moet formaat YYYY-MM-DD zijn");

    begindatum = strToTm(string);

    ENSURE(begindatum != nullptr, "Begin datum is niet correct ingesteld");
}

void Renovation::setEindDatum(const std::string &string)
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    REQUIRE(string.size() == 10 && string[4] == '-' && string[7] == '-', "Datum moet formaat YYYY-MM-DD zijn");

    einddatum = strToTm(string);

    ENSURE(einddatum != nullptr, "Eind datum is niet correct ingesteld");
}

void Renovation::setRoom(const std::string &room)
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    REQUIRE(!room.empty(), "ROOM mag niet leeg zijn");

    this->room = room;

    ENSURE(this->room == room, "ROOM is niet correct ingesteld");
}

std::string Renovation::getRoom()
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    return room;
}

bool Renovation::isTussen(tm *datum)
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    REQUIRE(datum != nullptr, "DATUM mag niet nullptr zijn");
    REQUIRE(begindatum != nullptr && einddatum != nullptr, "Begin of einddatum is niet ingesteld");

    bool afterBegin =
        (datum->tm_year > begindatum->tm_year) ||
        (datum->tm_year == begindatum->tm_year && datum->tm_mon > begindatum->tm_mon) ||
        (datum->tm_year == begindatum->tm_year && datum->tm_mon == begindatum->tm_mon && datum->tm_mday >= begindatum->tm_mday);

    bool beforeEnd =
        (datum->tm_year < einddatum->tm_year) ||
        (datum->tm_year == einddatum->tm_year && datum->tm_mon < einddatum->tm_mon) ||
        (datum->tm_year == einddatum->tm_year && datum->tm_mon == einddatum->tm_mon && datum->tm_mday <= einddatum->tm_mday);

    bool result = afterBegin && beforeEnd;

    ENSURE(result == true || result == false, "RESULT is geen boolean");

    return result;
}

tm* Renovation::getBeginDatum()
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    return begindatum;
}

tm* Renovation::getEindDatum()
{
    REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
    return einddatum;
}

Renovation::~Renovation()
{

}
