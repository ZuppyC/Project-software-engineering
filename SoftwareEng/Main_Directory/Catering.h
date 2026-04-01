//
// Created by Gebruiker on 01.04.2026.
//
#include <string>
#ifndef SOFTWAREENG_CATERING_H
#define SOFTWAREENG_CATERING_H


class Catering
{
private:
    std::string campus;
    float co2;
public:
    void setCampus(const std::string& campus);
    void setCo2(float co2);
};


#endif //SOFTWAREENG_CATERING_H