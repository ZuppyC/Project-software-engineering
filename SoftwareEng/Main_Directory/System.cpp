//
// Created by Dell on 26/02/2026.
//

#include "System.h"
#include <iostream>
#include "../src/DesignByContract.h"

System::System()
{
    _initcheck = this;


}

System* System::parser(const char* xmldoc)
{


    System* system = new System();
    TiXmlDocument doc(xmldoc);

    REQUIRE(
        doc.FirstChildElement("SYSTEM")->FirstChildElement("ROOM") != NULL &&
        doc.FirstChildElement("SYSTEM")->FirstChildElement("MEETING") != NULL &&
        doc.FirstChildElement("SYSTEM")->FirstChildElement("PARTICIPATION") != NULL,
        "De XML bestand moet ROOM, MEETING en PARTICIPATION elementen hebben."
    );

    if (!doc.LoadFile()) {
        std::cerr << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        delete system;
        return nullptr;
    }

    std::cout << "XML bestand succesvol geladen." << std::endl;

    ENSURE(!rooms.empty(), "ROOMS zijn niet gelezen");
    ENSURE(!meetings.empty(), "MMEETINGS zijn niet gelezen");
    ENSURE(!participations.empty(), "PARTICIPATIONS zijn niet gelezen");

    return nullptr;
}
bool System::properlyInitialized()
{
    return _initcheck ==this;
}


