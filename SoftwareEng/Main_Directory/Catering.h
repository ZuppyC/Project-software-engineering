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
    /*
     * constructor voor Catering
     *
     */

    bool properlyInitialized();
    /*
     * controleert of het object correct geïnitialiseerd is
     *
     */

    void setCampus(const std::string& campus);
    std::string getCampus();
    /*
     * getters en setters voor de campus van de catering
     *
     */

    void setCo2(double co2);
    double getCo2();
    /*
     * getters en setters voor de CO2 uitstoot van de catering
     *
     */

    ~Catering();
    /*
     * destructor van Catering
     *
     */
};


#endif //SOFTWAREENG_CATERING_H