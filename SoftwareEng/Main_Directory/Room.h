#ifndef SOFTWAREENG_ROOM_H
#define SOFTWAREENG_ROOM_H

#include <string>

#include "Building.h"
#include "Campus.h"
using namespace std;

class Room
{
private:
    Room* _initCheck;
    string name;
    string identifier;
    int capacity = 0;
    bool isOccupied = false;
    string campus;
    Campus campus_pointer;
    string building;
    Building building_pointer;

public:
    Room();
    /*
     * constructor voor Room
     */

    bool properlyInitialized();

    void setName(string name);
    /*
     * getters en setters voor room Name
     \n REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
     \n REQUIRE(!name.empty(), "Er is geen NAME");
     \n ENSURE(name == name, "NAME is niet gelezen");
     */
    string getName();
    /*
     \n REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
     */

    void setIdentifier(string id);
    /*
     * getters en setters voor room Identifier
     \n REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
     \n REQUIRE(!id.empty(), "Er is geen IDENTIFIER");
     \n ENSURE(identifier == id, "IDENTIFIER is niet gelezen");
     */
    string getIdentifier();
    /*
     \n REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
     */

    void setCapacity(int getal);
    /*
     * getters en setters voor room Capacity
     \n REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
     \n REQUIRE(getal > 0, "CAPACITY moet groter zijn dan 0");
     \n ENSURE(capacity == getal, "CAPACITY is niet gelezen");
     */
    int getCapacity();
    /*
     \n REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
     */

    bool getOccupied();
    void setOccupied(bool occupied);
    /*
     * getters en setters voor room occupation
     */

    void printRoom(ofstream& outputFile);
    /*
     \n REQUIRE(properlyInitialized(), "ROOM is niet geinitialiseerd");
     */

    void setBuilding(string _building);
    /*
     * getters en setters voor room Building
     \n REQUIRE(properlyInitialized(), "Room is niet geinitialiseerd");
     \n REQUIRE(!_building.empty(), "Building mag niet leeg zijn");
     \n ENSURE(building == _building, "Building niet correct gezet");
     */
    string getBuilding();
    /*
     \n REQUIRE(properlyInitialized(), "Room is niet geinitialiseerd");
     \n ENSURE(!building.empty(), "Building mag niet leeg zijn");
     */

    void setCampus(string _campus);
    /*
     * getters en setters voor room Campus
     \n REQUIRE(properlyInitialized(), "Room is niet geinitialiseerd");
     \n ENSURE(!campus.empty(), "Campus mag niet leeg zijn");
     */
    string getCampus();
    /*
     \n REQUIRE(properlyInitialized(), "Room is niet geinitialiseerd");
     */

    ~Room();
    /*
     * Room object destructor
     */
};

#endif //SOFTWAREENG_ROOM_H