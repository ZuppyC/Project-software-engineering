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


SuccessEnum Input::eerste_parserCB(const char* xmldoc,std::ostream& errStream, System* sys)
{
    SuccessEnum result = Success;

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        errStream << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return ImportAborted;
    }

    TiXmlElement* s = doc.FirstChildElement("SYSTEM");


    TiXmlElement* begin = s->FirstChildElement();


    for (TiXmlElement* childs = begin; childs!= NULL;childs = childs->NextSiblingElement())
    {

        string type = childs->Value();

        if (type == "CAMPUS")
        {
            // check of id al bestaat Geen dubbele id's

            TiXmlElement* id = childs->FirstChildElement("IDENTIFIER");
            TiXmlElement* name = childs->FirstChildElement("NAME");

            bool flag = false;
            if (id == nullptr)
            {
                errStream << "Geen ATTRIBUTE IDENTIFIER gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (id->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE IDENTIFIER is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }
            if (name == nullptr)
            {
                errStream << "Geen ATTRIBUTE NAME gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;
            }else if (name->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE NAME is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

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
                errStream << "Geen ATTRIBUTE IDENTIFIER gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (id->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE IDENTIFIER is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (name == nullptr)
            {
                errStream << "Geen ATTRIBUTE NAME gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (name->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE NAME is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (campus == nullptr)
            {
                errStream << "Geen ATTRIBUTE CAMPUS gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (campus->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE CAMPUS is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

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

    return result;



}


SuccessEnum Input::parser_catering(const char* xmldoc,std::ostream& errStream, System* sys)
{
    SuccessEnum result = Success;

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        errStream << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return ImportAborted;
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
                errStream << "Geen ATTRIBUTE CAMPUS gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (campus->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE CAMPUS is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (co2 == nullptr)
            {
                errStream << "Geen ATTRIBUTE CO2 gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (co2->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE CO2 is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            } else {
                try {
                    double cap= stod(co2->GetText());
                    if (cap <= 0)
                    {
                        errStream << "de CO2 moet groter zijn dan 0" << endl;
                        flag = true;
                        result = PartialImport;
                    }
                }
                catch (...) {

                    errStream<<"CO2 moet een float zijn"<<endl;
                    flag = true;
                    result = PartialImport;
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

return result;
}




SuccessEnum Input::parser_renovatie(const char* xmldoc,std::ostream& errStream, System* sys)
{
    SuccessEnum result = Success;

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        errStream << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return ImportAborted;
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
                errStream << "Geen ATTRIBUTE ROOM gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (room->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE ROOM is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (start == nullptr)
            {
                errStream << "Geen ATTRIBUTE START gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (start->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE START is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (end == nullptr)
            {
                errStream << "Geen ATTRIBUTE END gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (end->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE END is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

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
                    errStream << "ATTRIBUTE END moet een datum zijn NA START" << endl;
                    result = PartialImport;
                    delete r;

                }else
                {
                    sys->addRenovation(r);
                }
            }
        }
    }


    return result;
}












SuccessEnum Input::parserMRP(const char* xmldoc,std::ostream& errStream, System* sys)
{
    SuccessEnum result = Success;

    TiXmlDocument doc(xmldoc);
    if (!doc.LoadFile()) {
        errStream << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        return ImportAborted;
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
                errStream << "Geen ATTRIBUTE CAPACITY gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (cap->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE CAPACITY is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else
            {
                try
                {
                    int cap= stoi(childs->FirstChildElement("CAPACITY")->GetText());
                    if (cap <= 0)
                    {
                        errStream << "De CAPACITY moet groter zijn dan 0" << endl;
                        flag = true;
                        result = PartialImport;
                    }


                }catch (...)
                {
                    errStream << "De CAPACITY moet een int zijn voor het type "<< type << endl;
                    flag = true;
                    result = PartialImport;


                }

            }
            if (id == nullptr)
            {
                errStream << "Geen ATTRIBUTE IDENTIFIER gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (id->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE IDENTIFIER is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (building == nullptr)
            {
                errStream << "Geen ATTRIBUTE BUILDING gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (building->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE BUILDING is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (campus == nullptr)
            {
                errStream << "Geen ATTRIBUTE CAMPUS gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (campus->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE CAMPUS is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (name == nullptr)
            {
                errStream << "Geen ATTRIBUTE NAME gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (name->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE NAME is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

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
                errStream << "Geen ATTRIBUTE IDENTIFIER gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (id->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE IDENTIFIER is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (label == nullptr)
            {
                errStream << "Geen ATTRIBUTE LABEL gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (label->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE LABEL is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (room == nullptr)
            {
                errStream << "Geen ATTRIBUTE ROOM gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (room->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE ROOM is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (datum == nullptr)
            {
                errStream << "Geen ATTRIBUTE DATE gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (datum->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE DATE is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (uur == nullptr)
            {
                errStream << "Geen ATTRIBUTE HOUR gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (uur->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE HOUR is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else
            {
                try
                {
                    int cap = stoi(uur->GetText());
                    if (0 > cap || cap > 23)
                    {
                        errStream << "ATTRIBUTE HOUR moet tussen 0 en 23 zijn voor het type "<< type << endl;
                        flag = true;
                        result = PartialImport;

                    }

                }catch (...)
                {
                    errStream << "ATTRIBUTE HOUR moet een int getal zijn voor het type "<< type << endl;
                    flag = true;
                    result = PartialImport;

                }


            }

            if (online == nullptr)
            {
                errStream << "Geen ATTRIBUTE ONLINE gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (online->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE ONLINE is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else
            {
                string boolean = online->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    errStream << "Het ATTRIBUTE ONLINE moet een booleanse waarde zijn voor het type "<< type << endl;
                    flag = true;
                    result = PartialImport;

                }

            }

            if (external == nullptr)
            {
                errStream << "Geen ATTRIBUTE EXTERNALS gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (external->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE EXTERNALS is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else
            {
                string boolean = external->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    errStream << "Het ATTRIBUTE EXTERNAL moet een booleanse waarde zijn voor het type "<< type << endl;
                    flag = true;
                    result = PartialImport;

                }

            }

            if (catering == nullptr)
            {
                errStream << "Geen ATTRIBUTE CATERING gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (catering->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE CATERING is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else
            {
                string boolean = catering->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    errStream << "Het ATTRIBUTE CATERING moet een booleanse waarde zijn voor het type "<< type << endl;
                    flag = true;
                    result = PartialImport;

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
                    errStream << "een online meeting kan geen catering hebben" << endl;
                    delete meetNgreet;
                    result = PartialImport;

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
                errStream << "Geen ATTRIBUTE MEETING gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (meeting->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE MEETING is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (user == nullptr)
            {
                errStream << "Geen ATTRIBUTE USER gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (user->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE USER is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }

            if (external == nullptr)
            {
                errStream << "Geen ATTRIBUTE EXTERNAL gevonden voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else if (external->GetText() == nullptr)
            {
                errStream << "ATTRIBUTE EXTERNAL is leeg voor het type "<< type << endl;
                flag = true;
                result = PartialImport;

            }else
            {
                string boolean = external->GetText();
                if (boolean != "true" && boolean != "false")
                {
                    errStream << "Het ATTRIBUTE EXTERNAL moet een booleanse waarde zijn voor het type "<< type << endl;
                    flag = true;
                    result = PartialImport;

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

    return result;

}

bool Input::consistencyCheck(std::ostream& errStream,System *sys)
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
            errStream << "de volgende campus is leeg: " << c->getName() <<endl;
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
            errStream << "de volgende gebouw is leeg" << b->getName() << endl;
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


        if (m->getPart().size() != 0) {
            if (oneNonExternal)
            {
                errStream << "er is geen Non-external user in deze meeting: "<< m->getId() << endl;
                nietConsistensy = true;
            }
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
            errStream << "dubbele id voor Campus met id: " << id << endl;
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
            errStream << "dubbele id voor Building met id: " << id << endl;
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
            errStream << "dubbele id voor Room met id: " << id << endl;
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
            errStream << "dubbele id voor Meeting met id: " << id << endl;
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
            errStream << "Het campusID bestaat niet van het building " << b->getName() <<endl;
            nietConsistensy = true;
            // errStream << "De volgende campusID bestaat niet: " << b->getCampus() << endl;
        }
    }

    for (Room* r : sys->getRooms())
    {
        if (!campusID.count(r->getCampus()))
        {
            errStream << "Het campusID bestaat niet van het room " << r->getName() <<endl;
            nietConsistensy = true;
        }

        if (!buildingID.count(r->getBuilding()))
        {
            errStream << "Het buildingID bestaat niet van het room " << r->getName() << endl;
            nietConsistensy = true;
        }
    }

    for (Meeting* m : sys->getMeeting())
    {
        if (!roomID.count(m->getRoom()))
        {
            errStream << "Het roomID bestaat niet voor het meeting met id: " << m->getId() << endl;
        }
    }

    map<string,int> capacityCheck;

    for (Participation* p : sys->getParticipations())
    {
        if (!meetingID.count(p->getmeeting()))
        {
            errStream << "het MeetingID bestaat niet voor de participant "<<p->getUser() << endl;
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
            errStream << "Het roomID: " << r->getRoom() << " bestaat niet voor de renovatie" << endl;
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
            errStream << "er is niet genoeg plaatst voor de meeting "<< m->getId() << endl;
            nietConsistensy = true;
        }
    }
    set<string> catering_campus;
    for (Catering* cater : sys->getCatering())
    {
        string c_campus = cater->getCampus();
        if (!campusID.count(c_campus))
        {
            errStream << "het catering service verwijst naar een campusID dat niet bestaat" << endl;
            nietConsistensy = true;
        }

        if (catering_campus.count(c_campus))
        {
            errStream << "de volgende campus " << c_campus <<" heeft meerdere catering services wat niet kan" << endl;
            nietConsistensy = true;
        }else
        {
            catering_campus.insert(c_campus);
        }


    }

    return nietConsistensy;



}


void Input::returnConsistency(System *sys) {

    if (nietconsistent)
    {
        delete sys;
        exit(1);

    }

}


SuccessEnum Input::parseAll(const char* xmldoc, std::ostream& errStream, System* sys)
{
    SuccessEnum result = Success;
    result = eerste_parserCB(xmldoc, errStream, sys);

    if (result == PartialImport) {
        result = PartialImport;
    }

    if (parser_catering(xmldoc, errStream, sys) == PartialImport) {
        result = PartialImport;
    }
    if (parserMRP(xmldoc, errStream, sys) == PartialImport) {
        result = PartialImport;
    }
    if (parser_renovatie(xmldoc, errStream, sys) == PartialImport) {
        result = PartialImport;
    }

    return result;
}