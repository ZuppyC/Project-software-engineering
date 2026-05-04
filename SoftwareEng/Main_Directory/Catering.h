//
// Created by Gebruiker on 01.04.2026.
//
#include <string>

#include "gtest/internal/gtest-port.h"
#ifndef SOFTWAREENG_CATERING_H
#define SOFTWAREENG_CATERING_H

using namespace std;
class Catering
{
private:
    Catering* _initCheck;
    std::string campus;
    double co2;

public:
    Catering();
    bool properlyInitialized();
    void setCampus(const std::string& campus);
    string getCampus();
    void setCo2(double co2);
    double getCo2() ;
    ~Catering();
};


#endif //SOFTWAREENG_CATERING_H