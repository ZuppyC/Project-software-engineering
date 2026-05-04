#ifndef SOFTWAREENG_CAMPUS_H
#define SOFTWAREENG_CAMPUS_H

#include <string>

class Campus {
private:
 Campus* _initCheck;
 std::string name;
 std::string identifier;

public:
 Campus();
 /*
  * constructor voor Campus
  */

 bool properlyInitialized();
 /*
  * controleert of het object correct geïnitialiseerd is
  */

 void setName(const std::string& name);
 /*
  * getters en setters voor de naam van de campus
  \n REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");
  \n REQUIRE(!name.empty(), "Naam mag niet leeg zijn");
  \n ENSURE(this->name == name, "Naam is niet correct gezet");
  */

 std::string getName();
 /*
  * getters en setters voor de naam van de campus
  \n REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");
  \n ENSURE(!name.empty(), "Naam mag niet leeg zijn");
  */

 void setId(const std::string& id);
 /*
  * getters en setters voor de id van de campus
  \n REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");
  \n REQUIRE(!id.empty(), "Id mag niet leeg zijn");
  \n ENSURE(this->identifier == id, "Id is niet correct gezet");
  */

 std::string getId();
 /*
  * getters en setters voor de id van de campus
  \n REQUIRE(properlyInitialized(), "Campus is niet geinitialiseerd");
  \n ENSURE(!identifier.empty(), "Id mag niet leeg zijn");
  */

 ~Campus();
 /*
  * destructor van Campus
  */
};

#endif //SOFTWAREENG_CAMPUS_H