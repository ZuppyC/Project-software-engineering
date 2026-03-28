//
// Created by amens on 3/28/2026.
//

#include "Output.h"
#include "Output.h"
#include "System.h"
#include "Meeting.h"
#include "Participation.h"
#include "Room.h"
#include "../src/DesignByContract.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;


void Output::printBlok(ofstream& outputFile, Meeting* m) {


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

void Output::print(const std::string& filename, System& system) {
    vector<Room*> rooms = system.getRooms();
    vector<Meeting*> meetings = system.getMeeting();
    vector<Participation*> participations = system.getParticipations();

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


    outputFile.close();

}