#ifndef SOFTWAREENG_BUILDING_H
#define SOFTWAREENG_BUILDING_H

#include <string>
#include "Campus.h"

class Building
{
private:
    Building* _initCheck;
    std::string name;
    std::string id;
    std::string campus;
    Campus* campus_pointer;

public:
    Building();
    /*
     * constructor voor Building
     */

    bool properlyInitialized();
    /*
     * controleert of het object correct geïnitialiseerd is
     */

    void setName(const std::string& name);
    /*
     * getters en setters voor de naam van het gebouw
     \n REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
     \n REQUIRE(!name.empty(), "Naam mag niet leeg zijn");
     \n ENSURE(this->name == name, "Naam is niet correct gezet");
     */
    std::string getName();
    /*
     * getters en setters voor de naam van het gebouw
     \n REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
     \n ENSURE(!name.empty(), "Naam mag niet leeg zijn");
     */

    void setId(const std::string& id);
    /*
     * getters en setters voor de id van het gebouw
     \n REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
     \n REQUIRE(!id.empty(), "Id mag niet leeg zijn");
     \n ENSURE(this->id == id, "Id is niet correct gezet");
     */
    std::string getId();
    /*
     * getters en setters voor de id van het gebouw
     \n REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
     \n ENSURE(!id.empty(), "Id mag niet leeg zijn");
     */

    void setCampus(const std::string& campus);
    /*
     * getters en setters voor de campus van het gebouw
     \n REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
     \n REQUIRE(!campus.empty(), "Campus mag niet leeg zijn");
     \n ENSURE(this->campus == campus, "Campus is niet correct gezet");
     */
    std::string getCampus();
    /*
     * getters en setters voor de campus van het gebouw
     \n REQUIRE(properlyInitialized(), "Building is niet geinitialiseerd");
     \n ENSURE(!campus.empty(), "Campus mag niet leeg zijn");
     */

    ~Building();
    /*
     * destructor van Building
     */

};

#endif //SOFTWAREENG_BUILDING_H