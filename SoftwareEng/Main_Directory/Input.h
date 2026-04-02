//
// Created by amens on 3/28/2026.
//

#ifndef SOFTWAREENG_INPUT_H
#define SOFTWAREENG_INPUT_H

class System;
class Input {
    public:
        void eerste_parserCB(const char* xmldoc, System* sys);

        void parser_catering(const char* xmldoc, System* sys);

        void parserMRP(const char* xmldoc, System* sys);

        void parser_renovatie(const char* xmldoc, System* sys);


};


#endif //SOFTWAREENG_INPUT_H