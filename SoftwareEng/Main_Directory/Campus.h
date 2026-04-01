//
// Created by Gebruiker on 01.04.2026.
//
#include <string>
#ifndef SOFTWAREENG_CAMPUS_H
#define SOFTWAREENG_CAMPUS_H


class Campus {
private:
    std::string name;
    std::string identifier;
public:
    void setName(const std::string& name);
    void setId(const std::string& id);
};


#endif //SOFTWAREENG_CAMPUS_H