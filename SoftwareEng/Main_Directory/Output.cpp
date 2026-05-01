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

void Output::print(const std::string& filename, System& system) {
    vector<Room*> rooms = system.getRooms();
    vector<Meeting*> meetings = system.getMeeting();
    vector<Participation*> participations = system.getParticipations();

    ofstream outputFile(filename);

    REQUIRE(!rooms.empty(),"Er zijn geen ROOMs");
    REQUIRE(!meetings.empty(),"Er zijn geen MEETINGs");
    REQUIRE(!participations.empty(),"Er zijn geen PARTICIPATIONs");

    outputFile<< "## ==== [SYSTEM STATUS] ==== ##"<<"\n"<<endl;


    outputFile<<"--== Meetings ==--\n"<<endl;
    for (Meeting* meeting : meetings) {
        meeting->printMeeting(outputFile);
        Room* r;
        double cateringCO2=0.0;
        for (Room* room : system.getRooms()) {
            if (meeting->getRoom()==room->getIdentifier()) {
                r= room;
            }
        }
        for (Catering* c: system.getCatering()) {
            if (c->getCampus()==r->getCampus()) {
                cateringCO2+=c->getCo2();
            }
        }
        cateringCO2=cateringCO2* meeting->getPart().size();
        outputFile<<" -  CO2 emitted:  "<<meeting->co2ZonderCatering()+cateringCO2<<"\n"<<endl;
    }

    outputFile<<"--== Rooms ==--\n"<<endl;
    for (Room* room : rooms) {
        room->printRoom(outputFile);
    }

    outputFile<<"--== CO2 Summary ==--\n"<<endl;
    outputFile<<"-  Total CO2:  "<<system.getTotalCo2()<<"\n";



}