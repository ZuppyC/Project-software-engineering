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
    string name;
    string identifier;
    int capacity=0;
    bool isOccupied= false;

public:
    Room();
    void setName(string name);
    string getName();
    /*
     *getters en setters voor de naam van het room
     *
     */

    void setIdentifier(string id);
    string getIdentifier();
    /*
     *getters en setters voor de ID van het ROOM
     *
     */

    void setCapacity(int getal);
    int getCapacity();
    /*
     *getters en setters voor de room capacity
     *
     */



    ~Room();
};


#endif //SOFTWAREENG_ROOM_H