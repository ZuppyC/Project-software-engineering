//
// Created by Dell on 26/02/2026.
//

#include "System.h"
#include <iostream>
#include "../src/DesignByContract.h"
#include <fstream>

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
            meetNgreet->setDate(childs->FirstChildElement("DATE")->GetText());

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

    for (Meeting* i: meetings) {
        for (Participation* j: participations) {
            if (j->getmeeting()==i->getId()) {
                i->setPart(j);
            }
        }

    }

    ENSURE(!rooms.empty(),"geen room");
    ENSURE(!meetings.empty(),"geen meeting");
    ENSURE(!participations.empty(),"geen participatie");


    return system;
}

void System::printBlok(ofstream& outputFile, Meeting* m) {


    vector<string> dagen= {"Sunday", "Monday","Tuesday", "Wednesday","Thursday", "Friday", "Saturday"};

    tm* mDate= m->getDate();
    string dag= to_string(mDate->tm_mday);
    if (dag.size()==1) {
        dag= "0"+dag;
    }
    string maand= to_string(mDate->tm_mon);
    if (maand.size()==1) {
        maand= "0"+maand;
    }
    int jaar= mDate->tm_year;
    outputFile<< "- "<<m->getRoom()<<", "<<dagen[mDate->tm_wday]<<" "<<dag<<"/"<<maand<<"/"<<jaar<<"\n";
    outputFile<<"  "<<m->getLabel()<<"\n";

    vector<string> users = m->getPart()->getUsers();
    for (int i = 0; i < users.size()-1; i++) {
            outputFile<<users[i]<<", ";
    }
    outputFile<<"  "<<users[users.size()-1]<<"\n";

    string id= m->getId().substr(8);
    outputFile<<"  "<<"Meeting ID: "<<id<<endl;



}





void System::print() {
    ofstream outputFile("SystemOutput.txt");

    outputFile<< "Past meetings:\n";
    int teller=0;
    for (Meeting* m: meetings) {
        if (m->isPast()) {
            teller+=1;
            printBlok(outputFile, m);
        }
    }

    outputFile<<"\n"<<"\n"<<"Future Meetings:\n";
    teller=0;
    for (Meeting* m: meetings) {
        if (m->isPast()==false) {
            teller+=1;
            printBlok(outputFile, m);
        }
    }

    outputFile<<"\n"<<"\n"<<"Conflicts:\n";
    teller= 0;
    for (int i =0; i< meetings.size();i++) {
        for (int j= i+1; j<meetings.size();j++) {
            tm* d1 = meetings[i]->getDate();
            tm* d2 = meetings[j]->getDate();
            if (d1->tm_mday == d2->tm_mday && d1->tm_mon == d2->tm_mon && d1->tm_year == d2->tm_year) {
                teller+=1;
                printBlok(outputFile, meetings[j]);
                outputFile<<"  Reason: conflict with meeting "<< meetings[j]->getId().substr(8)<<endl;
            }
        }
    }

    outputFile<<"\n"<<"Rooms: "<<endl;

    for (Room* r: rooms) {
        outputFile << "- "<<r->getName()<<endl;
        outputFile <<"  Capacity: "<<r->getCapacity()<<" people"<<endl;
    }

    outputFile.close();



}

bool System::properlyInitialized()
{
    return _initcheck ==this;
}


