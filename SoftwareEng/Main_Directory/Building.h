//
// Created by Gebruiker on 01.04.2026.
//
#include <string>
#ifndef SOFTWAREENG_BUILDING_H
#define SOFTWAREENG_BUILDING_H


class Building
{
private:
    Building* _initCheck;
    std::string name;
    std::string id;
    std::string campus;

public:
    Building();
    /*
     * constructor voor Building
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
     * getters en setters voor de naam van het gebouw
     *
     */

    void setId(const std::string& id);
    std::string getId();
    /*
     * getters en setters voor de id van het gebouw
     *
     */

    void setCampus(const std::string& campus);
    std::string getCampus();
    /*
     * getters en setters voor de campus van het gebouw
     *
     */

    ~Building();
    /*
     * destructor van Building
     *
     */

};


#endif //SOFTWAREENG_BUILDING_H