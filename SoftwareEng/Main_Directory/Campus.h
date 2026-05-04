//
// Created by Gebruiker on 01.04.2026.
//
#include <string>
#ifndef SOFTWAREENG_CAMPUS_H
#define SOFTWAREENG_CAMPUS_H


class Campus {
private:
    Campus* _initCheck;
    std::string name;
    std::string identifier;
public:
    Campus();
    /*
     * constructor voor Campus
     *
     */

    bool properlyInitialized();
    /*
     * controleert of het object correct geïnitialiseerd is
     *
     */

    void setName(const std::string& name);
    std::string getName();
    /*
     * getters en setters voor de naam van de campus
     *
     */

    void setId(const std::string& id);
    std::string getId();
    /*
     * getters en setters voor de id van de campus
     *
     */

    ~Campus();
    /*
     * destructor van Campus
     *
     */

};


#endif //SOFTWAREENG_CAMPUS_H