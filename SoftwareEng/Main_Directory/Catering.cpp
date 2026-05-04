//
// Created by Gebruiker on 01.04.2026.
//

#include "Catering.h"
#include <bits/locale_classes.h>
#include "../src/DesignByContract.h"


Catering::Catering() {
    _initCheck = this;
}

bool Catering::properlyInitialized() {
    return _initCheck == this;
}

void Catering::setCampus(const std::string &campus)
{
    REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");
    REQUIRE(!campus.empty(), "Campus mag niet leeg zijn");

    this->campus = campus;

    ENSURE(this->campus == campus, "Campus is niet correct ingesteld");
}

void Catering::setCo2(double co2)
{
    REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");
    REQUIRE(co2 >= 0, "CO2 mag niet negatief zijn");

    this->co2 = co2;

    ENSURE(this->co2 == co2, "CO2 is niet correct ingesteld");
}

double Catering::getCo2()
{
    REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");

    ENSURE(co2 >= 0, "CO2 moet geldig zijn");
    return co2;
}

string Catering::getCampus()
{
    REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");

    ENSURE(!campus.empty(), "Campus mag niet leeg zijn");
    return campus;
}
Catering::~Catering()
{

}
