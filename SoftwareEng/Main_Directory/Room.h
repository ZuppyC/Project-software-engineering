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

    ~Room();
    /*
     *  Room object destructor
     */
};


#endif //SOFTWAREENG_ROOM_H