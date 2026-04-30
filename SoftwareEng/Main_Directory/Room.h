//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_ROOM_H
#define SOFTWAREENG_ROOM_H
#include <string>
using namespace std;

class Room
{
private:
    Room* _initCheck;
    string name;
    string identifier;
    int capacity=0;
    bool isOccupied= false;
    string campus;
    string building;

public:
    Room();
    bool properlyInitialized();

    void setName(string name);
    string getName();
    /*
     *  getters en setters voor room Name
     */

    void setIdentifier(string id);
    string getIdentifier();
    /*
     *  getters en setters voor room Identifier
     */

    void setCapacity(int getal);
    int getCapacity();
    /*
     *  getters en setters voor room Capacity
     */

    bool getOccupied();
    void setOccupied(bool occupied);
    /*
     *  getters en setters voor room occupation, om te zien of de room word gebruikt of niet
     */

    void printRoom(ofstream& outputFile);

    void setBuilding(string _building);
    string getBuilding();

    void setCampus(string _campus);
    string getCampus();
    string getId();

    ~Room();
    /*
     *  Room object destructor
     */
};


#endif //SOFTWAREENG_ROOM_H