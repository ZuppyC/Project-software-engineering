//
// Created by Dell on 26/02/2026.
//

#ifndef SOFTWAREENG_PARTICIPATION_H
#define SOFTWAREENG_PARTICIPATION_H
#include <string>

#include <vector>
using namespace std;
class Participation
{
private:
    string user;
    string meeting;
public:
    void setUser(string user_);
    string getUser();
    /*
     *  getters en setters voor participation User
     */

    void setmeeting(string meeting);
    string getmeeting();
    /*
     *  getters en setters voor participation Meeting
     */
};


#endif //SOFTWAREENG_PARTICIPATION_H