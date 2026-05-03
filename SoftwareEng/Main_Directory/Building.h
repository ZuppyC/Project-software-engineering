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
    bool properlyInitialized();
    void setName(const std::string& name);
    void setId(const std::string& id);
    void setCampus(const std::string& campus);
    std::string getCampus();
    std::string getId();
    std::string getName();

    ~Building();

};


#endif //SOFTWAREENG_BUILDING_H