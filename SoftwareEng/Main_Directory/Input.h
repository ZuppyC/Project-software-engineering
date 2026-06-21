//
// Created by amens on 3/28/2026.
//

#ifndef SOFTWAREENG_INPUT_H
#define SOFTWAREENG_INPUT_H
#include <iostream>

class System;

enum SuccessEnum {ImportAborted, PartialImport, Success};

class Input {

private:
    enum SuccessEnum resultaat = Success;

    bool nietconsistent = false;


    public:
        Input(const char* xmldoc,std::ostream& errStream, System* sys);
        Input();


        SuccessEnum eerste_parserCB(const char* xmldoc,std::ostream& errStream, System* sys);

        SuccessEnum parser_catering(const char* xmldoc,std::ostream& errStream, System* sys);

        SuccessEnum parserMRP(const char* xmldoc,std::ostream& errStream, System* sys);

        SuccessEnum parser_renovatie(const char* xmldoc,std::ostream& errStream, System* sys);

        SuccessEnum parseAll(const char* xmldoc, std::ostream& errStream, System* sys);

        void consistencyCheck(std::ostream& errStream, System* sys);

        void returnConsistency(System* sys);

    enum SuccessEnum getResultaat();



};


#endif //SOFTWAREENG_INPUT_H