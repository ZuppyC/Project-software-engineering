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
        meeting->printMeeting();
    }

}