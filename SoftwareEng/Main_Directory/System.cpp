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
            Room* ruimte = new Room;
            ruimte->setCapacity(stoi(childs->FirstChildElement("CAPACITY")->GetText()));
            ruimte->setIdentifier(childs->FirstChildElement("IDENTIFIER")->GetText());
            ruimte->setName(childs->FirstChildElement("NAME")->GetText());
            rooms.push_back(ruimte);
        }
        else if (type == "MEETING")
        {
            Meeting* meetNgreet = new Meeting;
            meetNgreet->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
            meetNgreet->setLabel(childs->FirstChildElement("LABEL")->GetText());
            meetNgreet->setRoom(childs->FirstChildElement("ROOM")->GetText());

            meetings.push_back(meetNgreet);


        }
        else if (type == "PARTICIPATION")
        {
            Participation* participatie = new Participation;
            participatie->setmeeting(childs->FirstChildElement("MEETING")->GetText());

            for (TiXmlElement* user = childs->FirstChildElement("USER"); user != NULL; user = user->NextSiblingElement("USER")) {
                participatie->setUser(user->GetText());
            }

            participations.push_back(participatie);
        }
    }
    ENSURE(!rooms.empty(),"geen room");
    ENSURE(!meetings.empty(),"geen meeting");
    ENSURE(!participations.empty(),"geen participatie");


    return system;
}
bool System::properlyInitialized()
{
    return _initcheck ==this;
}


