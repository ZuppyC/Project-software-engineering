//
// Created by amens on 3/28/2026.
//
#include<string>
#include<fstream>

#ifndef SOFTWAREENG_OUTPUT_H
#define SOFTWAREENG_OUTPUT_H

class System;
class Meeting;

class Output {
    public:
    void print(const std::string& filename, System& system);
    void printBlok(std::ofstream& outputFile, Meeting* m);
};


#endif //SOFTWAREENG_OUTPUT_H