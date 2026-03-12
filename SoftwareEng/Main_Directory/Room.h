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

    void setIdentifier(string id);
    string getIdentifier();

    void setCapacity(int getal);
    int getCapacity();

    bool getOccupied();
    void setOccupied(bool occupied);

    ~Room();
};


#endif //SOFTWAREENG_ROOM_H