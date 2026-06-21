//
// Created by Admin on 26/02/2026.
//
#include <iostream>
#include"input.h"
#include "System.h"
#include"output.h"
#include "../xmlparser/tinyxml.h"
using namespace std;



int main()
{
    System* s = new System;
    Input i("xmlfile.xml",cerr,s);
    Output out;
    s->takePlaceEveryMeeting();
    out.print("SystemOutput", *s);
    return 0;
}