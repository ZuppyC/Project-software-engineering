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
    if (!doc.LoadFile()) {
        std::cerr << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        delete system;
        return nullptr;
    }

    TiXmlElement* s = doc.FirstChildElement("SYSTEM");
    REQUIRE(
        s != nullptr &&
        s->FirstChildElement("ROOM") != nullptr,
        "De XML bestand moet ROOM element hebben."
    );
    REQUIRE(
        s != nullptr &&
        s->FirstChildElement("PARTICIPATION") != nullptr,
        "De XML bestand moet PARTICIPATION element hebben."
    );
    REQUIRE(
        s != nullptr &&
        s->FirstChildElement("MEETING") != nullptr,
        "De XML bestand moet MEETINGS element hebben."
    );

    std::cout << "XML bestand succesvol geladen." << std::endl;
    TiXmlElement* begin = s->FirstChildElement();
    for (TiXmlElement* childs = begin; childs!= NULL;childs = childs->NextSiblingElement())
    {
        string type = childs->Value();
        if (type == "ROOM")
        {
            cout << "dit is een room" <<endl;
        }
        else if (type == "MEETING")
        {
            cout << "dit is een meeting" << endl;
        }
        else if (type == "PARTICIPATION")
        {
            cout << "dit is een participatie" << endl;
        }
    }
    ENSURE(!rooms.empty(),"geen room");
    ENSURE(!meetings.empty(),"geen meeting");
    ENSURE(!participations.empty(),"geen participatie");


    return nullptr;
}
bool System::properlyInitialized()
{
    return _initcheck ==this;
}


