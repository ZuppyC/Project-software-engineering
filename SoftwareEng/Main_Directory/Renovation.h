#ifndef SOFTWAREENG_RENOVATION_H
#define SOFTWAREENG_RENOVATION_H

#include <string>
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
     */

    bool properlyInitialized();
    /*
     * controleert of het object correct geïnitialiseerd is
     */

    void setRoom(const std::string& room);
    /*
     * getters en setters voor de room van de renovatie
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     \n REQUIRE(!room.empty(), "ROOM mag niet leeg zijn");
     \n ENSURE(this->room == room, "ROOM is niet correct ingesteld");
     */
    std::string getRoom();
    /*
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     */

    tm* strToTm(const std::string& datum);
    /*
     * zet een string om naar een tm datum
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     \n REQUIRE(datum.size() == 10 && datum[4] == '-' && datum[7] == '-', "Datum moet formaat YYYY-MM-DD zijn");
     \n REQUIRE(maand >= 1 && maand <= 12, "Maand moet tussen 1 en 12 zijn");
     \n REQUIRE(dag >= 1 && dag <= 31, "Dag moet tussen 1 en 31 zijn");
     \n ENSURE(time != nullptr, "tm pointer is niet aangemaakt");
     */

    void setBeginDatum(const std::string& string);
    /*
     * getters en setters voor de begindatum van de renovatie
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     \n REQUIRE(string.size() == 10 && string[4] == '-' && string[7] == '-', "Datum moet formaat YYYY-MM-DD zijn");
     \n ENSURE(begindatum != nullptr, "Begin datum is niet correct ingesteld");
     */
    tm* getBeginDatum();
    /*
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     */

    void setEindDatum(const std::string& string);
    /*
     * getters en setters voor de einddatum van de renovatie
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     \n REQUIRE(string.size() == 10 && string[4] == '-' && string[7] == '-', "Datum moet formaat YYYY-MM-DD zijn");
     \n ENSURE(einddatum != nullptr, "Eind datum is niet correct ingesteld");
     */
    tm* getEindDatum();
    /*
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     */

    bool isTussen(tm* datum);
    /*
     * controleert of een datum tussen begin- en einddatum ligt
     \n REQUIRE(properlyInitialized(), "RENOVATION is niet geinitialiseerd");
     \n REQUIRE(datum != nullptr, "DATUM mag niet nullptr zijn");
     \n REQUIRE(begindatum != nullptr && einddatum != nullptr, "Begin of einddatum is niet ingesteld");
     \n ENSURE(result == true || result == false, "RESULT is geen boolean");
     */

    ~Renovation();
    /*
     * destructor van Renovation
     */
};

#endif //SOFTWAREENG_RENOVATION_H