//
// Created by Dell on 26/02/2026.
//

#include "Room.h"


Room::Room()
{

}

void Room::setCapacity(int getal)
{
    this->capacity = getal;
}

int Room::getCapacity() {
    return capacity;
}

void Room::setIdentifier(string id)
{
    this->identifier = id;
}
string Room::getIdentifier() {
    return identifier;
}

void Room::setName(string name)
{
    this->name = name;
}

string Room::getName() {
    return name;
}


Room::~Room()
{

}

