//
// Created by Gebruiker on 01.04.2026.
//
#include <string>
#ifndef SOFTWAREENG_BUILDING_H
#define SOFTWAREENG_BUILDING_H


class Building
{
private:
    std::string name;
    std::string id;
    std::string campus;

public:
    void setName(const std::string& name);
    void setId(const std::string& id);
    void setCampus(const std::string& campus);

};


#endif //SOFTWAREENG_BUILDING_H