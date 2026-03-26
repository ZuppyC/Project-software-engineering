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
void System::addRoom(Room *room) {
    rooms.push_back(room);
}

void System::addMeeting(Meeting* meeting) {
    meetings.push_back(meeting);
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


            if (cap<0) {
                cerr<<"CAPACITY moet groter zijn dan 0"<<endl;
            }
            ruimte->setCapacity(cap);
            ruimte->setIdentifier(childs->FirstChildElement("IDENTIFIER")->GetText());
            TiXmlElement* name1 = childs->FirstChildElement("NAME");


            if (name1 == nullptr) {
                cerr<<"Er is geen NAME element"<<endl;
            }

            ruimte->setName(name1->GetText());
            rooms.push_back(ruimte);

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

            meetings.push_back(meetNgreet);



        }
        else if (type == "PARTICIPATION")
        {
            Participation* participatie = new Participation;
            participatie->setmeeting(childs->FirstChildElement("MEETING")->GetText());

            for (TiXmlElement* user = childs->FirstChildElement("USER"); user != NULL; user = user->NextSiblingElement("USER")) {
                participatie->setUser(user->GetText());

            }


            //postconditions
            if (participatie->getUser().empty()) {
                cerr<<"Er is geen USER gelezen"<<endl;
            }
            if (participatie->getmeeting().empty()) {
                cerr<<"Er is geen MEETING gelezen"<<endl;
            }

            participations.push_back(participatie);
        }
    }


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
            if (r->getName()==i->getRoom()) {
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
    if (users.size()>1)
    {
        for (int i = 0; i < users.size()-1; i++) {
            outputFile<<users[i]->getUser()<<", ";
        }
        outputFile<<users[users.size()-1]->getUser()<<"\n";
    }else if (users.size()==1)
    {
        outputFile<<"  "<<users[users.size()-1]->getUser()<<"\n";
    }


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
               outputFile<<"  Reason: conflict with meeting "<< meetings[i]->getId().substr(8)<<endl;
           }
        }
    }

    outputFile<<"\n"<<"Rooms: "<<endl;

    for (Room* r: rooms) {
        outputFile << "- "<<r->getName()<<endl;
        outputFile <<"  Capacity: "<<r->getCapacity()<<" people"<<endl;
    }

    ENSURE(outputFile.is_open() && !outputFile.fail(), "Output bestand is niet correct gemaakt");

    meetingPlanner = move(outputFile);

    outputFile.close();

}


void System::takesPlace(Meeting* meeting) {

    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");


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

                cerr<<"The room is occupied, meeting canceled: "<< meeting->getId() <<endl;
                meeting->setCanceled(true);
                return;
            }
        }

        cout<<"Meeting takes place: "<< meeting->getId() <<endl;
        meeting->setBezig(true);


    }
    ENSURE(meeting->getBezig() || meeting->getCanceled(), "Meeting hasnt taken place, or hasnt been canceled.");
}


void System::takePlaceEveryMeeting() {

    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
    REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");

    for (int i =0; i< meetings.size();i++) {
        this->takesPlace(this->getMeeting()[i]);

    }

    for (Meeting* m: meetings) {
        ENSURE(m->getBezig() || m->getCanceled(), "Meeting hasnt taken place, or hasnt been canceled.");
    }

}


vector<Meeting *>System::getMeeting() {
    return meetings;
}


bool System::properlyInitialized()
{
    return _initcheck ==this;
}



