#ifndef SOFTWAREENG_PARTICIPATION_H
#define SOFTWAREENG_PARTICIPATION_H

#include <string>
#include <vector>

#include "Meeting.h"

using namespace std;

class Participation
{
private:
    Participation* _initCheck;
    string user;
    string meeting;
    Meeting meeting_pointer;
    bool isExternal = false;

public:
    Participation();
    /*
     * constructor voor Participation
     */

    bool properlyInitialized();
    /*
     * controleert of het object correct geïnitialiseerd is
     */

    void setUser(string user_);
    /*
     * getters en setters voor participation User
     \n REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
     \n REQUIRE(!user_.empty(), "Er is geen USER");
     \n ENSURE(user==user_, "USER is niet gelezen");
     */
    string getUser();
    /*
     \n REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
     */

    void setmeeting(string meeting);
    /*
     * getters en setters voor participation Meeting
     \n REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
     \n REQUIRE(!meeting.empty(), "Er is geen MEETING");
     \n ENSURE(this->meeting == meeting, "MEETING is niet gelezen");
     */
    string getmeeting();
    /*
     \n REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
     */

    void setExternal(string isExternal_);
    /*
     * getters en setters voor participation isExternal
     \n REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
     \n REQUIRE(isExternal_=="true"||isExternal_=="false", "De EXTERNAL variabele mag alleen 'true' of 'false' zijn.");
     \n ENSURE(isExternal==true && isExternal_=="true"||isExternal==false && isExternal_=="false", "De EXTERNAL variabele is niet juist gelezen.");
     */
    bool getExternal();
    /*
     \n REQUIRE(properlyInitialized(), "PARTICIPATION is niet geinitialiseerd");
     */

    ~Participation();
    /*
     * destructor van Participation
     */
};

#endif //SOFTWAREENG_PARTICIPATION_H