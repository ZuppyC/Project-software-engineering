#ifndef SOFTWAREENG_CATERING_H
#define SOFTWAREENG_CATERING_H

#include <string>

using namespace std;

class Catering
{
private:
    Catering* _initCheck;
    std::string campus;
    double co2;

public:
    Catering();
    /*
     * constructor voor Catering
     */

    bool properlyInitialized();
    /*
     * controleert of het object correct geïnitialiseerd is
     */

    void setCampus(const std::string& campus);
    /*
     * getters en setters voor de campus van de catering
     \n REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");
     \n REQUIRE(!campus.empty(), "Campus mag niet leeg zijn");
     \n ENSURE(this->campus == campus, "Campus is niet correct ingesteld");
     */
    std::string getCampus();
    /*
     * getters en setters voor de campus van de catering
     \n REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");
     \n ENSURE(!campus.empty(), "Campus mag niet leeg zijn");
     */

    void setCo2(double co2);
    /*
     * getters en setters voor de CO2 uitstoot van de catering
     \n REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");
     \n REQUIRE(co2 >= 0, "CO2 mag niet negatief zijn");
     \n ENSURE(this->co2 == co2, "CO2 is niet correct ingesteld");
     */
    double getCo2();
    /*
     * getters en setters voor de CO2 uitstoot van de catering
     \n REQUIRE(properlyInitialized(), "Catering is niet geinitialiseerd");
     \n ENSURE(co2 >= 0, "CO2 moet geldig zijn");
     */

    ~Catering();
    /*
     * destructor van Catering
     */
};

#endif //SOFTWAREENG_CATERING_H