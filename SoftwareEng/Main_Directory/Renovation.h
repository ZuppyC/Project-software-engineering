//
// Created by Gebruiker on 01.04.2026.
//
#include <string>

#ifndef SOFTWAREENG_RENOVATION_H
#define SOFTWAREENG_RENOVATION_H
using namespace std;


class Renovation {
private:
    Renovation* _initCheck;
    std::string room;
    tm* begindatum = nullptr;
    tm* einddatum = nullptr;



public:
    Renovation();
    bool properlyInitialized();
    void setRoom(const std::string& room);
    string getRoom();

    tm* strToTm(const std::string& datum);
    void setBeginDatum(const std::string& string);
    void setEindDatum(const std::string& string);
    tm* getBeginDatum();
    tm* getEindDatum();

    bool isTussen(tm* datum);
    ~Renovation();
};


#endif //SOFTWAREENG_RENOVATION_H