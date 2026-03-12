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
    s.takesPlace(s.getMeeting()[0]);
    s.takesPlace(s.getMeeting()[1]);
    return 0;
}