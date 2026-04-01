//
// Created by Gebruiker on 01.04.2026.
//
#include <string>

#ifndef SOFTWAREENG_RENOVATION_H
#define SOFTWAREENG_RENOVATION_H


class Renovation {
private:
    std::string room;
    tm* begindatum = nullptr;
    tm* einddatum = nullptr;



public:

    tm* strToTm(const std::string& datum);
    void setBeginDatum(const std::string& string);
    void setEindDatum(const std::string& string);

};


#endif //SOFTWAREENG_RENOVATION_H