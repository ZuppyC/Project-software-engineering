//
// Created by Dell on 26/02/2026.
//

#include "System.h"
#include <iostream>

System::System()
{

}

System* System::parser(const char* xmldoc)
{
    System* systeem = new System();
    TiXmlDocument doc;
    doc.Print();
    if (doc.LoadFile(xmldoc) != true)
    {
        std::cerr << "amanasikim" << endl;
    }
    return systeem;

}