//
// Created by Gebruiker on 01.04.2026.
//

#include "Campus.h"
#include "../src/DesignByContract.h"

Campus::Campus() {
    _initCheck = this;
}

bool Campus::properlyInitialized() {
    return _initCheck == this;
}

void Campus::setId(const std::string &id) {
    REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");
    REQUIRE(!id.empty(), "Id mag niet leeg zijn");

    this->identifier = id;

    ENSURE(this->identifier == id, "Id is niet correct gezet");
}

void Campus::setName(const std::string &name) {
    REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");
    REQUIRE(!name.empty(), "Naam mag niet leeg zijn");

    this->name = name;

    ENSURE(this->name == name, "Naam is niet correct gezet");
}

std::string Campus::getId() {
    REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");

    ENSURE(!identifier.empty(), "Id mag niet leeg zijn");
    return identifier;
}

std::string Campus::getName() {
    REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");

    ENSURE(!name.empty(), "Naam mag niet leeg zijn");
    return name;
}

Campus::~Campus() {
}

