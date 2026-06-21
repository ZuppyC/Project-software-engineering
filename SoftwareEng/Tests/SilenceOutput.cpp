//
// Created by Admin on 21/06/2026.
//

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

class SilenceCoutEnvironment : public ::testing::Environment {
public:
    void SetUp() override {
#ifndef NDEBUG
        static std::ostringstream nullStream;
        std::cout.rdbuf(nullStream.rdbuf());
#endif
    }
};

// Dit zorgt ervoor dat de SetUp() automatisch wordt aangeroepen
// voordat ELKE test draait, zonder dat je iets anders moet aanpassen.
::testing::Environment* const silence_env =
    ::testing::AddGlobalTestEnvironment(new SilenceCoutEnvironment);