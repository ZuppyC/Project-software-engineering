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

            ENSURE(ruimte->getCapacity() != 0, "Er is get CAPACITY gelzen");
            ENSURE(!ruimte->getIdentifier().empty(), "Er is geen IDENTIFIER gelezen");
            ENSURE(!ruimte->getName().empty() , "Er is geen NAME gelezen");
        }
        else if (type == "MEETING")
        {
            Meeting* meetNgreet = new Meeting;
            meetNgreet->setId(childs->FirstChildElement("IDENTIFIER")->GetText());
            meetNgreet->setLabel(childs->FirstChildElement("LABEL")->GetText());
            meetNgreet->setRoom(childs->FirstChildElement("ROOM")->GetText());
            meetNgreet->setDate(childs->FirstChildElement("DATE")->GetText());

            ENSURE(!meetNgreet->getId().empty(), "Er is geen IDENTIFIER gelezen");
            ENSURE(!meetNgreet->getLabel().empty(), "Er is geen LABEL gelezen");
            ENSURE(!meetNgreet->getRoom().empty(), "Er is geen ROOM gelezen");
            ENSURE(meetNgreet->getDate() != nullptr, "Er is geen DATE gelezen");

            meetings.push_back(meetNgreet);


        }
        else if (type == "PARTICIPATION")
        {
            Participation* participatie = new Participation;
            participatie->setmeeting(childs->FirstChildElement("MEETING")->GetText());

            for (TiXmlElement* user = childs->FirstChildElement("USER"); user != NULL; user = user->NextSiblingElement("USER")) {
                participatie->setUser(user->GetText());

            }

            ENSURE(!participatie->getUser().empty(), "Er is geen USER gelezen");
            ENSURE(!participatie->getmeeting().empty(), "Er is geen MEETING gelezen");

            participations.push_back(participatie);
        }
    }

    for (Participation* j: participations) {
        for (Meeting* i: meetings) {
            if (j->getmeeting()== i->getId()) {
                i->setPart(j);



                ENSURE(!i->getPart().empty(), "Er is geen PARTICIPATION gelezen");
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

    vector<Participation*> users = m->getPart();
    for (int i = 0; i < users.size()-1; i++) {
            outputFile<<users[i]->getUser()<<", ";
    }
    outputFile<<"  "<<users[users.size()-1]->getUser()<<"\n";

    string id= m->getId().substr(8);
    outputFile<<"  "<<"Meeting ID: "<<id<<endl;



}





void System::print(string filename) {

    ofstream outputFile(filename);

    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
    REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");

    outputFile<< "Past meetings:\n";

    for (Meeting* m: meetings) {
        if (m->isPast()) {

            printBlok(outputFile, m);
        }
    }

    outputFile<<"\n"<<"\n"<<"Future Meetings:\n";
    vector<Meeting*> futureMeetings;
    for (Meeting* m: meetings) {
        if (m->isPast()==false) {
            for (Meeting* m2: futureMeetings) {
                if (!m->conflictsWith(m2) || futureMeetings.empty()) {
                    printBlok(outputFile, m);
                    futureMeetings.push_back(m);
                }
            }
            if (futureMeetings.empty()) {
                printBlok(outputFile, m);
                futureMeetings.push_back(m);
            }
        }
    }

    outputFile<<"\n"<<"\n"<<"Conflicts:\n";

    for (int i =0; i< meetings.size();i++) {
        for (int j= i+1; j < meetings.size();j++) {
           if (meetings[i]->conflictsWith(meetings[j])) {
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


void System::takesPlace(Meeting* meeting) {
    if (meetings.size()==1) {
        cout<<"Meeting takes place"<<endl;
        meeting->setBezig(true);

    }
    else{
        for (Meeting* m: meetings) {
            if (m==meeting) {
                continue;
            }
            else if (meeting->conflictsWith(m) && m->getBezig()) {

                cerr<<"The room is occupied, meeting canceled."<<endl;

                return;
            }
            else {

            }

        }

        cout<<"Meeting takes place"<<endl;
        meeting->setBezig(true);
    }



}

vector<Meeting *>System::getMeeting() {
    return meetings;
}


bool System::properlyInitialized()
{
    return _initcheck ==this;
}



