
//
// Created by Dell on 26/02/2026.
//

#include "Participation.h"
#include "../src/DesignByContract.h"


Participation::Participation() {
    _initCheck = this;
}

bool Participation::properlyInitialized() {
    return _initCheck == this;
}



void Participation::setmeeting(string meeting) {
    REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");

    REQUIRE(!meeting.empty(), "Er is geen MEETING");
    this->meeting = meeting;
    ENSURE(this->meeting == meeting, "MEETING is niet gelezen");
}

void Participation::setUser(string user_) {
    REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");

    REQUIRE(!user_.empty(), "Er is geen USER");
    user = user_;
    ENSURE(user==user_, "USER is niet gelezen");
}
string Participation::getUser() {
    REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");

    return user;
}
string Participation::getmeeting() {
    REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");

    return meeting;
}

void Participation::setExternal(string external) {
    REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
    REQUIRE(external=="true"||external=="false", "De EXTERNAL variabele mag alleen 'true' of 'false' zijn.");
    if (external=="true") {
        isExternal = true;
    }
    else {
        isExternal = false;
    }
    ENSURE(isExternal==true && external=="true"||isExternal==false && external=="false", "De EXTERNAL variabele is niet juist gelezen.");
}

bool Participation::getExternal() {
    REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
    return isExternal;
}



Participation::~Participation()
{
}
