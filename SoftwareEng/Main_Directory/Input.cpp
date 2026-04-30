//
// Created by amens on 3/28/2026.
//

#include "Input.h"
#include "../xmlparser/tinyxml.h"
#include <iostream>
#include <map>
#include <set>
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

            TiXmlElement* id = childs->FirstChildElement("IDENTIFIER");
            TiXmlElement* name = childs->FirstChildElement("NAME");

            bool flag = false;
            if (id == nullptr)
            {
                cerr << "geen ATTRIBUTE IDENTIFIER gevonden." << endl;
                flag = true;

            }else if (id->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE IDENTIFIER is leeg." << endl;
                flag = true;

            }
            if (name == nullptr)
            {
                cerr << "geen ATTRIBUTE NAME gevonden." << endl;
                flag = true;
            }else if (name->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE IDENTIFIER is leeg." << endl;
                flag = true;
            }

            if (!flag)
            {
                Campus* c = new Campus();

                c->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
                c->setName(childs->FirstChildElement("NAME")->GetText());

                sys->addCampus(c);
            }

        }else if (type == "BUILDING")
        {
            TiXmlElement* id = childs->FirstChildElement("IDENTIFIER");
            TiXmlElement* name = childs->FirstChildElement("NAME");
            TiXmlElement* campus = childs->FirstChildElement("CAMPUS");

            bool flag = false;
            if (id == nullptr)
            {
                cerr << "geen ATTRIBUTE IDENTIFIER gevonden." << endl;
                flag = true;

            }else if (id->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE IDENTIFIER is leeg." << endl;
                flag = true;

            }

            if (name == nullptr)
            {
                cerr << "geen ATTRIBUTE NAME gevonden." << endl;
                flag = true;

            }else if (name->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE NAME is leeg." << endl;
                flag = true;

            }

            if (campus == nullptr)
            {
                cerr << "geen ATTRIBUTE CAMPUS gevonden." << endl;
                flag = true;

            }else if (campus->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE CAMPUS is leeg." << endl;
                flag = true;

            }
            if (!flag) {
                Building* b = new Building;

                b->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
                b->setName(childs->FirstChildElement("NAME")->GetText());
                b->setCampus(childs->FirstChildElement("CAMPUS")->GetText());

                sys->addBuilding(b);
            }


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
            TiXmlElement* campus = childs->FirstChildElement("CAMPUS");
            TiXmlElement* co2 = childs->FirstChildElement("CO2");

            bool flag = false;
            if (campus == nullptr)
            {
                cerr << "geen ATTRIBUTE CAMPUS gevonden." << endl;
                flag = true;

            }else if (campus->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE CAMPUS is leeg." << endl;
                flag = true;

            }else
            if (co2 == nullptr)
            {
                cerr << "geen ATTRIBUTE CO2 gevonden." << endl;
                flag = true;

            }else if (co2->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE CO2 is leeg." << endl;
                flag = true;

            } else {
                try {
                    double cap= stod(co2->GetText());
                    if (cap <= 0)
                    {
                        cerr << "de CAPACITY moet groter zijn dan 0" << endl;
                        flag = true;
                    }
                }
                catch (...) {

                    cerr<<"CAPACITY moet een float zijn"<<endl;
                    flag = true;
                }
            }

            // checks
            if (!flag) {
                Catering* c = new Catering;

                c->setCampus(childs->FirstChildElement("CAMPUS")->GetText());

                c->setCo2(stof(childs->FirstChildElement("CO2")->GetText()));


                sys->addCatering(c);
            }

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

            TiXmlElement* room = childs->FirstChildElement("ROOM");
            TiXmlElement* start = childs->FirstChildElement("START");
            TiXmlElement* end = childs->FirstChildElement("END");
            bool flag = false;
            if (room == nullptr)
            {
                cerr << "geen ATTRIBUTE ROOM gevonden." << endl;
                flag = true;

            }else if (room->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE ROOM is leeg." << endl;
                flag = true;

            }

            if (start == nullptr)
            {
                cerr << "geen ATTRIBUTE START gevonden." << endl;
                flag = true;

            }else if (start->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE START is leeg." << endl;
                flag = true;

            }

            if (end == nullptr)
            {
                cerr << "geen ATTRIBUTE END gevonden." << endl;
                flag = true;

            }else if (end->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE END is leeg." << endl;
                flag = true;

            }


            if (!flag)
            {
                Renovation* r = new Renovation;

                r->setRoom(childs->FirstChildElement("ROOM")->GetText());

                r->setBeginDatum(childs->FirstChildElement("START")->GetText());

                r->setEindDatum(childs->FirstChildElement("END")->GetText());

                tm begindatum = *r->getBeginDatum();
                tm einddatum = *r->getEindDatum();

                // als einddatum voor start datum is error
                if (mktime(&einddatum) <= mktime(&begindatum))
                {
                    cerr << "ATTRIBUTE END moet een datum zijn NA START" << endl;
                    delete r;

                }else
                {
                    sys->addRenovation(r);
                }
            }
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



    TiXmlElement* begin = s->FirstChildElement();
    for (TiXmlElement* childs = begin; childs!= NULL;childs = childs->NextSiblingElement())
    {
        string type = childs->Value();
        if (type == "ROOM")
        {
            TiXmlElement* cap = childs->FirstChildElement("CAPACITY");
            TiXmlElement* id = childs->FirstChildElement("IDENTIFIER");
            TiXmlElement* building = childs->FirstChildElement("BUILDING");
            TiXmlElement* campus = childs->FirstChildElement("CAMPUS");
            TiXmlElement* name = childs->FirstChildElement("NAME");

            bool flag = false;
            if (cap == nullptr)
            {
                cerr << "geen ATTRIBUTE CAPACITY gevonden." << endl;
                flag = true;

            }else if (cap->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE CAPACITY is leeg." << endl;
                flag = true;

            }else
            {
                try
                {
                    int cap= stoi(childs->FirstChildElement("CAPACITY")->GetText());
                    if (cap <= 0)
                    {
                        cerr << "de CAPACITY moet groter zijn dan 0" << endl;
                        flag = true;
                    }


                }catch (...)
                {
                    cerr << "de CAPACITY moet een int zijn" << endl;
                    flag = true;

                }

            }
            if (id == nullptr)
            {
                cerr << "geen ATTRIBUTE IDENTIFIER gevonden." << endl;
                flag = true;

            }else if (id->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE IDENTIFIER is leeg." << endl;
                flag = true;

            }

            if (building == nullptr)
            {
                cerr << "geen ATTRIBUTE BUILDING gevonden." << endl;
                flag = true;

            }else if (building->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE BUILDING is leeg." << endl;
                flag = true;

            }

            if (campus == nullptr)
            {
                cerr << "geen ATTRIBUTE CAMPUS gevonden." << endl;
                flag = true;

            }else if (campus->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE CAMPUS is leeg." << endl;
                flag = true;

            }

            if (name == nullptr)
            {
                cerr << "geen ATTRIBUTE NAME gevonden." << endl;
                flag = true;

            }else if (name->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE NAME is leeg." << endl;
                flag = true;

            }




            if (!flag) {
                Room* ruimte = new Room;

                ruimte->setCapacity(stoi(childs->FirstChildElement("CAPACITY")->GetText()));
                ruimte->setIdentifier(childs->FirstChildElement("IDENTIFIER")->GetText());
                ruimte->setBuilding(childs->FirstChildElement("BUILDING")->GetText());
                ruimte->setCampus(childs->FirstChildElement("CAMPUS")->GetText());
                ruimte->setName(childs->FirstChildElement("NAME")->GetText());
                sys->addRoom(ruimte);
            }

        }
        else if (type == "MEETING")
        {
            TiXmlElement* id = childs->FirstChildElement("IDENTIFIER");
            TiXmlElement* label = childs->FirstChildElement("LABEL");
            TiXmlElement* room = childs->FirstChildElement("ROOM");
            TiXmlElement* datum = childs->FirstChildElement("DATE");
            TiXmlElement* uur = childs->FirstChildElement("HOUR");
            TiXmlElement* online = childs->FirstChildElement("ONLINE");
            TiXmlElement* external = childs->FirstChildElement("EXTERNALS");
            TiXmlElement* catering = childs->FirstChildElement("CATERING");

            bool flag = false;
            if (id == nullptr)
            {
                cerr << "geen ATTRIBUTE IDENTIFIER gevonden." << endl;
                flag = true;

            }else if (id->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE IDENTIFIER is leeg." << endl;
                flag = true;

            }

            if (label == nullptr)
            {
                cerr << "geen ATTRIBUTE LABEL gevonden." << endl;
                flag = true;

            }else if (label->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE LABEL is leeg." << endl;
                flag = true;

            }

            if (room == nullptr)
            {
                cerr << "geen ATTRIBUTE ROOM gevonden." << endl;
                flag = true;

            }else if (room->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE ROOM is leeg." << endl;
                flag = true;

            }

            if (datum == nullptr)
            {
                cerr << "geen ATTRIBUTE DATE gevonden." << endl;
                flag = true;

            }else if (datum->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE DATE is leeg." << endl;
                flag = true;

            }

            if (uur == nullptr)
            {
                cerr << "geen ATTRIBUTE HOUR gevonden." << endl;
                flag = true;

            }else if (uur->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE HOUR is leeg." << endl;
                flag = true;

            }else
            {
                try
                {
                    int cap = stoi(uur->GetText());
                    if (0 > cap || cap > 23)
                    {
                        cerr << "ATTRIBUTE HOUR is moet tussen 0 en 23 zijn." << endl;
                        flag = true;

                    }

                }catch (...)
                {
                    cerr << "ATTRIBUTE HOUR moet een int getal zijn." << endl;
                    flag = true;

                }


            }

            if (online == nullptr)
            {
                cerr << "geen ATTRIBUTE ONLINE gevonden." << endl;
                flag = true;

            }else if (online->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE ONLINE is leeg." << endl;
                flag = true;

            }else
            {
                string boolean = online->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    cerr << "de ATTRIBUTE ONLINE moet een booleanse waarde zijn" << endl;
                    flag = true;

                }

            }

            if (external == nullptr)
            {
                cerr << "geen ATTRIBUTE EXTERNALS gevonden." << endl;
                flag = true;

            }else if (external->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE EXTERNALS is leeg." << endl;
                flag = true;

            }else
            {
                string boolean = external->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    cerr << "de ATTRIBUTE EXTERNALS moet een booleanse waarde zijn" << endl;
                    flag = true;

                }

            }

            if (catering == nullptr)
            {
                cerr << "geen ATTRIBUTE CATERING gevonden." << endl;
                flag = true;

            }else if (catering->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE CATERING is leeg." << endl;
                flag = true;

            }else
            {
                string boolean = catering->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    cerr << "de ATTRIBUTE CATERING moet een booleanse waarde zijn" << endl;
                    flag = true;

                }

            }



            if (!flag) {
                Meeting* meetNgreet = new Meeting;
                meetNgreet->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
                meetNgreet->setLabel(childs->FirstChildElement("LABEL")->GetText());
                meetNgreet->setRoom(childs->FirstChildElement("ROOM")->GetText());
                meetNgreet->setDate(childs->FirstChildElement("DATE")->GetText());


                meetNgreet->setHour(stoi(childs->FirstChildElement("HOUR")->GetText()));
                meetNgreet->setOnline(string (childs->FirstChildElement("ONLINE")->GetText())== "true");
                meetNgreet->setExternals(childs->FirstChildElement("EXTERNALS")->GetText());
                meetNgreet->setCatering(childs->FirstChildElement("CATERING")->GetText());

                if (meetNgreet->getOnline() && meetNgreet->getCatering())
                {
                    cerr << "een online meeting kan geen catering hebben" << endl;
                    delete meetNgreet;

                }else
                {
                    sys->addMeeting(meetNgreet);

                }
            }



        }
        else if (type == "PARTICIPATION")
        {
            TiXmlElement* meeting = childs->FirstChildElement("MEETING");
            TiXmlElement* user = childs->FirstChildElement("USER");
            TiXmlElement* external = childs->FirstChildElement("EXTERNAL");
            bool flag = false;
            if (meeting == nullptr)
            {
                cerr << "geen ATTRIBUTE MEETING gevonden." << endl;
                flag = true;

            }else if (meeting->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE MEETING is leeg." << endl;
                flag = true;

            }

            if (user == nullptr)
            {
                cerr << "geen ATTRIBUTE USER gevonden." << endl;
                flag = true;

            }else if (user->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE USER is leeg." << endl;
                flag = true;

            }

            if (external == nullptr)
            {
                cerr << "geen ATTRIBUTE EXTERNAL gevonden." << endl;
                flag = true;

            }else if (external->GetText() == nullptr)
            {
                cerr << "ATTRIBUTE EXTERNAL is leeg." << endl;
                flag = true;

            }else
            {
                string boolean = external->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    cerr << "de ATTRIBUTE EXTERNALS moet een booleanse waarde zijn" << endl;
                    flag = true;

                }

            }




            if (!flag) {
                Participation* participatie = new Participation;

                participatie->setmeeting(childs->FirstChildElement("MEETING")->GetText());
                participatie->setUser(childs->FirstChildElement("USER")->GetText());
                participatie->setExternal(childs->FirstChildElement("EXTERNAL")->GetText());

                sys->addParticipation(participatie);
            }

        }
    }

    for (Participation* p : sys->getParticipations())
    {
        for (Meeting* m : sys->getMeeting())
        {
            if (p->getmeeting() == m->getId())
            {
                m->setPart(p);
                break;
            }
        }
    }

}

void Input::consistencyCheck(System *sys)
{
    vector<Campus*> campusen = sys->getCampus();
    vector<Building*> buildings = sys->getBuilding();
    bool nietConsistensy = false;

    for (Campus* c : campusen)
    {
        bool campusleeg = true;
        for (Building* b : buildings)
        {
            if (c->getId() == b->getCampus())
            {
                campusleeg = false;
            }
        }
        if (campusleeg)
        {
            cerr << "de volgende campus is leeg: " << c->getName() <<endl;
            nietConsistensy = true;
        }
    }

    for (Building* b : buildings)
    {
        bool buildingleeg = true;
        for (Room* r : sys->getRooms())
        {
            if (r->getBuilding() == b->getId())
            {
                buildingleeg = false;
            }
        }
        if (buildingleeg)
        {
            cerr << "de volgende gebouw is leeg" << b->getName() << endl;
            nietConsistensy = true;
        }

    }

    for (Meeting* m : sys->getMeeting())
    {
        bool oneNonExternal = true;

        for (Participation* p : m->getPart())
        {
            if (!p->getExternal())
            {
                oneNonExternal = false;
            }
        }

        if (oneNonExternal)
        {
            cerr << "er is geen Non-external user in deze meeting: "<< m->getId() << endl;
            nietConsistensy = true;
        }


    }

    set<string> campusID;
    set<string> buildingID;
    set<string> roomID;
    set<string> meetingID;

    for (Campus* c : sys->getCampus())
    {
        string id = c->getId();
        if (campusID.count(id))
        {
            cerr << "dubbele id voor Campus met id: " << id << endl;
            nietConsistensy = true;
        }else
        {
            campusID.insert(id);
        }
    }
    for (Building* b : sys->getBuilding())
    {
        string id = b->getId();
        if (buildingID.count(id))
        {
            cerr << "dubbele id voor Building met id: " << id << endl;
            nietConsistensy = true;
        }else
        {
            buildingID.insert(id);
        }

    }
    for (Room* r : sys->getRooms())
    {
        string id = r->getId();
        if (roomID.count(id))
        {
            cerr << "dubbele id voor Room met id: " << id << endl;
            nietConsistensy = true;
        }else
        {
            roomID.insert(id);
        }

    }
    for (Meeting* m : sys->getMeeting())
    {
        string id = m->getId();
        if (meetingID.count(id))
        {
            cerr << "dubbele id voor Meeting met id: " << id << endl;
            nietConsistensy = true;
        }else
        {
            meetingID.insert(id);
        }

    }

    for (Building* b : sys->getBuilding())
    {
        if (!campusID.count(b->getCampus()))
        {
            cerr << "Het campusID bestaat niet van het building " << b->getName() <<endl;
            nietConsistensy = true;
            // cerr << "De volgende campusID bestaat niet: " << b->getCampus() << endl;
        }
    }

    for (Room* r : sys->getRooms())
    {
        if (!campusID.count(r->getCampus()))
        {
            cerr << "Het campusID bestaat niet van het room " << r->getName() <<endl;
            nietConsistensy = true;
        }

        if (!buildingID.count(r->getBuilding()))
        {
            cerr << "Het buildingID bestaat niet van het room " << r->getName() << endl;
            nietConsistensy = true;
        }
    }

    for (Meeting* m : sys->getMeeting())
    {
        if (!roomID.count(m->getRoom()))
        {
            cerr << "Het roomID bestaat niet voor het meeting met id: " << m->getId() << endl;
        }
    }

    map<string,int> capacityCheck;

    for (Participation* p : sys->getParticipations())
    {
        if (!meetingID.count(p->getmeeting()))
        {
            cerr << "het MeetingID bestaat niet voor de participant "<<p->getUser() << endl;
            nietConsistensy = true;

        }else
        {
            capacityCheck[p->getmeeting()]++;
        }
    }

    for (Renovation* r : sys->getRenovations())
    {
        if (!roomID.count(r->getRoom()))
        {
            cerr << "Het roomID: " << r->getRoom() << " bestaat niet voor de renovatie" << endl;
            nietConsistensy = true;
        }
    }

    for (Meeting* m : sys->getMeeting())
    {
        int capacity = 0;
        for (Room* r:sys->getRooms())
        {
            if (m->getRoom() == r->getId())
            {
                capacity = r->getCapacity();
                break;
            }
        }
        if (capacityCheck[m->getId()] > capacity)
        {
            cerr << "er is niet genoeg plaatst voor de meeting "<< m->getId() << endl;
            nietConsistensy = true;
        }
    }
    set<string> catering_campus;
    for (Catering* cater : sys->getCatering())
    {
        string c_campus = cater->getCampus();
        if (!campusID.count(c_campus))
        {
            cerr << "het catering service verwijst naar een campusID dat niet bestaat" << endl;
            nietConsistensy = true;
        }

        if (catering_campus.count(c_campus))
        {
            cerr << "de volgende campus " << c_campus <<" heeft meerdere catering services wat niet kan" << endl;
            nietConsistensy = true;
        }else
        {
            catering_campus.insert(c_campus);
        }


    }


    if (nietConsistensy)
    {
        cerr << "Het systeem is niet consistent en wordt niet geaccepteerd." << endl;
        delete sys;
        exit(-1);

    }
}
