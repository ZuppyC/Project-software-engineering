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
void System::addParticipation(Participation* participation) {
    participations.push_back(participation);
}

vector<Room*> System::getRooms() {
    return rooms;
}

vector<Participation*> System::getParticipations() {
    return participations;
}
void System::addRoom(Room *room) {
    rooms.push_back(room);
}

void System::addMeeting(Meeting* meeting) {
    meetings.push_back(meeting);
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



