//
// Created by Gebruiker on 01.04.2026.
//

#include "Building.h"

void Building::setCampus(const std::string &campus) {
    this->campus = campus;
}

void Building::setId(const std::string &id) {
    this->id = id;
}

void Building::setName(const std::string &name) {
    this->name = name;
}

std::string Building::getCampus() {
    return campus;
}

std::string Building::getId() {
    return id;
}

std::string Building::getName() {
    return name;
}

Building::~Building()
{

}
