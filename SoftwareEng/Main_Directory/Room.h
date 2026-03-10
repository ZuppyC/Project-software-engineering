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
    int capacity;
public:
    Room();
    void setName(string name);
    void setIdentifier(string id);
    void setCapacity(int getal);
    ~Room();
};


#endif //SOFTWAREENG_ROOM_H