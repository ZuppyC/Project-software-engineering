//
// Created by Dell on 26/02/2026.
//

#include "Room.h"
#include "../src/DesignByContract.h"
using namespace std;

Room::Room() {
    _initCheck = this;
}
bool Room::properlyInitialized() {
    return _initCheck == this;
}

void Room::setCapacity(int getal)
{
    REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
    REQUIRE(getal > 0, "CAPACITY moet groter zijn dan 0");
    this->capacity = getal;
    ENSURE(capacity == getal, "CAPACITY is niet gelezen");
}

int Room::getCapacity() {
    REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
    return capacity;
}

void Room::setIdentifier(string id)
{
    REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
    REQUIRE(!id.empty(), "Er is geen IDENTIFIER");
    this->identifier = id;
    ENSURE(identifier == id, "IDENTIFIER is niet gelezen");
}
string Room::getIdentifier() {
    REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
    return identifier;
}

void Room::setName(string name_)
{
    REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
    REQUIRE(!name_.empty(), "Er is geen NAME");
    this->name = name_;
    ENSURE(name == name_, "NAME is niet gelezen");
}

string Room::getName() {
    REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
    return name;
}





Room::~Room()
{

}

