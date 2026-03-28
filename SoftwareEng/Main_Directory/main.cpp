//
// Created by Admin on 26/02/2026.
//
#include <iostream>
#include"input.h"
#include "System.h"
#include "../xmlparser/tinyxml.h"
using namespace std;



int main()
{
    Input in;
    System* s = in.parser("..//Main_Directory//xmlfile.xml");

    if (s == nullptr) {
        return 1;
    }

    s->print("SystemOutput");
    s->takePlaceEveryMeeting();

    delete s;
    return 0;
}