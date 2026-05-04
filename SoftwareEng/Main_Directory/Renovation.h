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
    /*
     * constructor voor Renovation
     *
     */

    bool properlyInitialized();
    /*
     * controleert of het object correct geïnitialiseerd is
     *
     */

    void setRoom(const std::string& room);
    std::string getRoom();
    /*
     * getters en setters voor de room van de renovatie
     *
     */

    tm* strToTm(const std::string& datum);
    /*
     * zet een string om naar een tm datum
     *
     */

    void setBeginDatum(const std::string& string);
    tm* getBeginDatum();
    /*
     * getters en setters voor de begindatum van de renovatie
     *
     */

    void setEindDatum(const std::string& string);
    tm* getEindDatum();
    /*
     * getters en setters voor de einddatum van de renovatie
     *
     */

    bool isTussen(tm* datum);
    /*
     * controleert of een datum tussen begin- en einddatum ligt
     *
     */

    ~Renovation();
    /*
     * destructor van Renovation
     *
     */
};


#endif //SOFTWAREENG_RENOVATION_H