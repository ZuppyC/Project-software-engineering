//
// Created by Gebruiker on 30.04.2026.
//

#include "gtest/gtest.h"
#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "compare_file.h"

class InputTests: public ::testing::Test {
protected:
    friend class System;
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.

};





TEST_F(InputTests,Lege_campus)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input1.txt");
    result = i.parseAll("../InputTestsxml/input1.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input1.txt","../InputTestsxml/expected_input1.txt"));

}