//
// Created by Admin on 26/02/2026.
//
#include <iostream>

#include "System.h"
#include "../xmlparser/tinyxml.h"
using namespace std;



int main()
{
    System s;
    s.parser("..//Main_Directory//xmlfile.xml");
    s.print("SystemOutput");
    s.takePlaceEveryMeeting();
    return 0;
}