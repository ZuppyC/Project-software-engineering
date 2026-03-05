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
    System* system = new System();
    TiXmlDocument doc(xmldoc);

    if (!doc.LoadFile()) {
        std::cerr << "XML kon niet geladen worden: "
                  << doc.ErrorDesc() << std::endl;
        delete system;
        return nullptr;
    }

    std::cout << "XML bestand succesvol geladen." << std::endl;
    return system;
}


