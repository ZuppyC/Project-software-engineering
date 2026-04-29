//
// Created by Gebruiker on 01.04.2026.
//

#include "Campus.h"


void Campus::setId(const std::string &id) {
    this->identifier = id;
}

void Campus::setName(const std::string &name) {
    this->name = name;
}


std::string Campus::getId() {
    return identifier;
}


std::string Campus::getName() {
    return name;
}
