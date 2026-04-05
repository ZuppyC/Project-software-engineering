//
// Created by amens on 3/28/2026.
//

#include "Input.h"
#include "../xmlparser/tinyxml.h"
#include <iostream>
#include <string>
#include "System.h"
#include <vector>

#include "Building.h"
#include "Campus.h"
#include "Catering.h"
#include "Renovation.h"


void Input::eerste_parserCB(const char* xmldoc, System* sys)
{

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        std::cerr << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return;
    }

    TiXmlElement* s = doc.FirstChildElement("SYSTEM");


    TiXmlElement* begin = s->FirstChildElement();


    for (TiXmlElement* childs = begin; childs!= NULL;childs = childs->NextSiblingElement())
    {

        string type = childs->Value();

        if (type == "CAMPUS")
        {
            // check of id al bestaat geen dubbele id's



            Campus* c = new Campus();

            c->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
            c->setName(childs->FirstChildElement("NAME")->GetText());

            sys->addCampus(c);





        }else if (type == "BUILDING")
        {

            Building* b = new Building;

            b->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
            b->setName(childs->FirstChildElement("NAME")->GetText());
            b->setCampus(childs->FirstChildElement("CAMPUS")->GetText());


            sys->addBuilding(b);


        }else
        {
            continue;
        }

    }





}


void Input::parser_catering(const char* xmldoc, System* sys)
{

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        std::cerr << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return;
    }

    TiXmlElement* s = doc.FirstChildElement("SYSTEM");


    TiXmlElement* begin = s->FirstChildElement();


    for (TiXmlElement* childs = begin; childs!= NULL;childs = childs->NextSiblingElement())
    {
        string type = childs->Value();

        if (type == "CATERING")
        {

            // checks
            Catering* c = new Catering;

            c->setCampus(childs->FirstChildElement("CAMPUS")->GetText());

            c->setCo2(stof(childs->FirstChildElement("CO2")->GetText()));


            sys->addCatering(c);

        }
    }


}














void Input::parser_renovatie(const char* xmldoc, System* sys)
{

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        std::cerr << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return;
    }

    TiXmlElement* s = doc.FirstChildElement("SYSTEM");


    TiXmlElement* begin = s->FirstChildElement();

    for (TiXmlElement* childs = begin; childs!= NULL;childs = childs->NextSiblingElement())
    {

        string type = childs->Value();
        if (type == "RENOVATION")
        {
            // nog checks of valid is



            Renovation* r = new Renovation;

            r->setRoom(childs->FirstChildElement("ROOM")->GetText());

            r->setBeginDatum(childs->FirstChildElement("START")->GetText());

            r->setEindDatum(childs->FirstChildElement("END")->GetText());

            sys->addRenovation(r);
        }
    }





}












void Input::parserMRP(const char* xmldoc, System* sys)
{

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        std::cerr << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return;
    }

    TiXmlElement* s = doc.FirstChildElement("SYSTEM");

    //Preconditions
    if (s == nullptr || s->FirstChildElement("ROOM") == nullptr) {
        cerr<< "De XML bestand moet ROOM element hebben"<<endl;
    }

    if (s == nullptr || s->FirstChildElement("PARTICIPATION") == nullptr) {
        cerr<< "De XML bestand moet PARTICIPATION element hebben"<<endl;
    }

    if (s == nullptr || s->FirstChildElement("MEETING") == nullptr) {
        cerr<< "De XML bestand moet MEETING element hebben"<<endl;
    }


    TiXmlElement* begin = s->FirstChildElement();
    for (TiXmlElement* childs = begin; childs!= NULL;childs = childs->NextSiblingElement())
    {
        string type = childs->Value();
        if (type == "ROOM")
        {
            Room* ruimte = new Room;


            try {
                int cap= stoi(childs->FirstChildElement("CAPACITY")->GetText());
                ruimte->setCapacity(cap);
            }
            catch (...) {

                cerr<<"CAPACITY moet een int zijn"<<endl;
            }

            int cap= stoi(childs->FirstChildElement("CAPACITY")->GetText());


            if (cap<=0) {
                cerr<<"CAPACITY moet groter zijn dan 0"<<endl;
            }
            ruimte->setCapacity(cap);
            ruimte->setIdentifier(childs->FirstChildElement("IDENTIFIER")->GetText());
            ruimte->setBuilding(childs->FirstChildElement("BUILDING")->GetText());
            ruimte->setCampus(childs->FirstChildElement("CAMPUS")->GetText());
            TiXmlElement* name1 = childs->FirstChildElement("NAME");


            if (name1 == nullptr) {
                cerr<<"Er is geen NAME element"<<endl;
            }

            ruimte->setName(name1->GetText());

            sys->addRoom(ruimte);

            //Postconditions

            if (ruimte->getCapacity() <= 0) {
                cerr<<"Er is geen CAPACITY gelezen"<<endl;
            }

            if (ruimte->getIdentifier().empty()) {
                cerr<<"Er is geen IDENTIFIER gelezen"<<endl;
            }

            if (ruimte->getName().empty()) {
                cerr<<"Er is geen NAME gelezen"<<endl;
            }
        }
        else if (type == "MEETING")
        {
            Meeting* meetNgreet = new Meeting;
            meetNgreet->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
            meetNgreet->setLabel(childs->FirstChildElement("LABEL")->GetText());
            meetNgreet->setRoom(childs->FirstChildElement("ROOM")->GetText());
            meetNgreet->setDate(childs->FirstChildElement("DATE")->GetText());


            meetNgreet->setHour(stoi(childs->FirstChildElement("HOUR")->GetText()));
            meetNgreet->setOnline(string (childs->FirstChildElement("ONLINE")->GetText())== "true");
            meetNgreet->setExternals(childs->FirstChildElement("EXTERNALS")->GetText());
            meetNgreet->setCatering(childs->FirstChildElement("CATERING")->GetText());




            //Postconditions
            if (meetNgreet->getId().empty()) {
                cerr<<"Er is geen IDENTIFIER gelezen"<<endl;
            }

            if (meetNgreet->getLabel().empty()) {
                cerr<<"Er is geen LABEL gelezen"<<endl;
            }

            if (meetNgreet->getRoom().empty()) {
                cerr<<"Er is geen ROOM gelezen"<<endl;
            }

            if (meetNgreet->getDate() == nullptr) {
                cerr<<"Er is geen DATE gelezen"<<endl;
            }

            sys->addMeeting(meetNgreet);



        }
        else if (type == "PARTICIPATION")
        {
            Participation* participatie = new Participation;
            participatie->setmeeting(childs->FirstChildElement("MEETING")->GetText());

            for (TiXmlElement* user = childs->FirstChildElement("USER"); user != NULL; user = user->NextSiblingElement("USER")) {
                participatie->setUser(user->GetText());

            }
            participatie->setExternal(childs->FirstChildElement("EXTERNAL")->GetText());



            //postconditions
            if (participatie->getUser().empty()) {
                cerr<<"Er is geen USER gelezen"<<endl;
            }
            if (participatie->getmeeting().empty()) {
                cerr<<"Er is geen MEETING gelezen"<<endl;
            }

            sys->addParticipation(participatie);
        }
    }




    vector<Meeting*> meetings = sys->getMeeting();
    vector<Room*> rooms = sys->getRooms();
    vector<Participation*> participations = sys->getParticipations();


    for (Meeting* m : meetings) {
        bool gevonden = false;

        for (Room* r : rooms) {
            if (m->getRoom() == r->getIdentifier()) {
                gevonden = true;
            }
        }

        if (!gevonden) {
            cerr<<"MEETING wijst naar ROOM die niet bestaat"<<endl;
            exit(-1);
        }
    }


    for (Participation* p : participations) {

        bool found = false;

        for (Meeting* m : meetings) {
            if (p->getmeeting() == m->getId()) {
                m->setPart(p);
                found = true;
            }
        }

        if (!found) {
            cerr<<"PARTICIPATION wijst naar een MEETING die niet bestaat"<<endl;
            exit(-1);
        }
    }


    for (Meeting* i: meetings) {
        int teller= 0;
        for (Participation* j: participations) {
            if (j->getmeeting()== i->getId()) {
                teller+=1;
            }
        }
        for (Room* r: rooms) {
            if (r->getIdentifier()==i->getRoom()) {
                 if (teller> r->getCapacity()) {
                    cerr<<"Aantal PARTITCIPATIONs is groter dan ROOM CAPACITY"<<endl;
                     exit(-1);
                }
            }
        }
    }



    for (size_t i = 0; i < meetings.size(); i++) {
        for (size_t j = i + 1; j < meetings.size(); j++) {

            if (meetings[i]->getId() == meetings[j]->getId()) {
                cerr<<"Dubbele MEETING IDENTIFIER"<<endl;
                exit(-1);
            }
        }
    }

    for (size_t i = 0; i < rooms.size(); i++) {
        for (size_t j = i + 1; j < rooms.size(); j++) {

            if (rooms[i]->getIdentifier() == rooms[j]->getIdentifier()) {
                cerr<<"Dubbele ROOM IDENTIFIER"<<endl;
                exit(-1);
            }
        }
    }



    if (rooms.empty()) {
        cerr<<"geen room"<<endl;
    }

    if (meetings.empty()) {
        cerr<<"geen meeting"<<endl;
    }

    if (participations.empty()) {
        cerr<<"geen participation"<<endl;
    }
}
