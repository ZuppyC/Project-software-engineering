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
    vector<string> users;
    string meeting;
public:
    void setUser(string user);
    void setmeeting(string meeting);
};


#endif //SOFTWAREENG_PARTICIPATION_H