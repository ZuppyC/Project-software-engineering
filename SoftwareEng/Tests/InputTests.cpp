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

TEST_F(InputTests,Lege_gebouw)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input2.txt");
    result = i.parseAll("../InputTestsxml/input2.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input2.txt","../InputTestsxml/expected_input2.txt"));

}
TEST_F(InputTests,geenCampusID_en_leeggebouw)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input3.txt");
    result = i.parseAll("../InputTestsxml/input3.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input3.txt","../InputTestsxml/expected_input3.txt"));

}

TEST_F(InputTests,over_capacity)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input4.txt");
    result = i.parseAll("../InputTestsxml/input4.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input4.txt","../InputTestsxml/expected_input4.txt"));

}

TEST_F(InputTests,geen_nonExternalUsers)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input5.txt");
    result = i.parseAll("../InputTestsxml/input5.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input5.txt","../InputTestsxml/expected_input5.txt"));

}

TEST_F(InputTests,meerdere_cateringservices)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input6.txt");
    result = i.parseAll("../InputTestsxml/input6.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input6.txt","../InputTestsxml/expected_input6.txt"));

}

TEST_F(InputTests,Dubbele_ids)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input7.txt");
    result = i.parseAll("../InputTestsxml/input7.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input7.txt","../InputTestsxml/expected_input7.txt"));

}

TEST_F(InputTests,geen_valid_ID)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input8.txt");
    result = i.parseAll("../InputTestsxml/input8.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == Success);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input8.txt","../InputTestsxml/expected_input8.txt"));

}

TEST_F(InputTests,syntax_error)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input9.txt");
    result = i.parseAll("../InputTestsxml/input9.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == ImportAborted);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input9.txt","../InputTestsxml/expected_input9.txt"));

}

TEST_F(InputTests,lege_attributen)
{
    Input i;
    System* s = new System;
    ofstream myfile;
    SuccessEnum result;

    myfile.open("../InputTestsxml/actual_input10.txt");
    result = i.parseAll("../InputTestsxml/input10.xml",myfile,s);
    i.consistencyCheck(myfile,s);
    myfile.close();

    EXPECT_TRUE(result == PartialImport);
    EXPECT_TRUE(FileCompare("../InputTestsxml/actual_input10.txt","../InputTestsxml/expected_input10.txt"));

}
