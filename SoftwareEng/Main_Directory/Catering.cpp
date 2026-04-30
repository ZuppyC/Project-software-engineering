//
// Created by Gebruiker on 01.04.2026.
//

#include "Catering.h"

void Catering::setCampus(const std::string &campus)
{
    this->campus = campus;
}

void Catering::setCo2(double co2)
{
    this->co2 = co2;
}

double Catering::getCo2() const
{
    return co2;
}
string Catering::getCampus() {
    return campus;
}

Catering::~Catering()
{

}
