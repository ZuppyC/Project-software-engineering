//
// Created by Dell on 26/02/2026.
//

#include "Participation.h"


void Participation::setmeeting(string meeting) {
    this->meeting = meeting;
}

void Participation::setUser(string user_) {
    user = user_;
}
string Participation::getUser() {
    return user;
}
string Participation::getmeeting() {
    return meeting;
}


