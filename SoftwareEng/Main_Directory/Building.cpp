//
// Created by Gebruiker on 01.04.2026.
//

#include "Building.h"
#include <bits/locale_classes.h>
#include "../src/DesignByContract.h"


Building::Building() {
    _initCheck = this;
}
bool Building::properlyInitialized() {
    return _initCheck == this;
}
void Building::setCampus(const std::string &campus) {
    REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
    REQUIRE(!campus.empty(), "Campus mag niet leeg zijn");

    this->campus = campus;

    ENSURE(this->campus == campus, "Campus is niet correct gezet");
}

void Building::setId(const std::string &id) {
    REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
    REQUIRE(!id.empty(), "Id mag niet leeg zijn");

    this->id = id;

    ENSURE(this->id == id, "Id is niet correct gezet");
}

void Building::setName(const std::string &name) {
    REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
    REQUIRE(!name.empty(), "Naam mag niet leeg zijn");

    this->name = name;

    ENSURE(this->name == name, "Naam is niet correct gezet");
}

std::string Building::getCampus() {
    REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");

    ENSURE(!campus.empty(), "Campus mag niet leeg zijn");
    return campus;
}

std::string Building::getId() {
    REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");

    ENSURE(!id.empty(), "Id mag niet leeg zijn");
    return id;
}

std::string Building::getName() {
    REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");

    ENSURE(!name.empty(), "Naam mag niet leeg zijn");
    return name;
}
Building::~Building()
{

}
