#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"

class SYSTEMTESTS: public ::testing::Test {
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




class HAPPYDAY_SCENARIO: public ::testing::Test {
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



//  BRON SERGE DEMEYER  functie FileCompare.
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer - University of Antwerp
bool FileCompare(const std::string leftFileName, const std::string rightFileName) {
    ifstream leftFile, rightFile;
    char leftRead, rightRead;
    bool result;

    // Open the two files.
    leftFile.open(leftFileName.c_str());
    if (!leftFile.is_open()) {
        return false;
    };
    rightFile.open(rightFileName.c_str());
    if (!rightFile.is_open()) {
        leftFile.close();
        return false;
    };

    result = true; // files exist and are open; assume equality unless a counterexamples shows up.
    while (result && leftFile.good() && rightFile.good()) {
        leftFile.get(leftRead);
        rightFile.get(rightRead);
        result = (leftRead == rightRead);
    };
    if (result) {
        // last read was still equal; are we at the end of both files ?
        result = (!leftFile.good()) && (!rightFile.good());
    };

    leftFile.close();
    rightFile.close();
    return result;
}


TEST_F(SYSTEMTESTS, SyntaxFoutXML_VAL)
{
    // maak een file om de cerr op te vangen
    std::ofstream Test_file("Syntax_fout.txt");

    // stuur de komende cerr in de file
    std::streambuf* oldCerr = std::cerr.rdbuf(Test_file.rdbuf());

    System s("../xmlfilesTests/Syntax_fout.txt.xml");

    //herstel cerr zodat er niets meer erin kan
    std::cerr.rdbuf(oldCerr);


    EXPECT_TRUE(FileCompare("../Expected_output_tests/expected_Syntax_fout_val.txt","Syntax_fout.txt"));

}




// TEST_F(SYSTEMTESTS, NoMeeting_VAL)
// {
//     // maak een file om de cerr op te vangen
//     std::ofstream Test_file("Nomeeting_val.txt");
//
//     // stuur de komende cerr in de file
//     std::streambuf* oldCerr = std::cerr.rdbuf(Test_file.rdbuf());
//
//     System s("../xmlfilesTests/NoMeeting.xml");
//
//     //herstel cerr zodat er niets meer erin kan
//     std::cerr.rdbuf(oldCerr);
//
//
//     EXPECT_TRUE(FileCompare("../Expected_output_tests/expected_Nomeeting_val.txt","Nomeeting_val.txt"));
//
// }






//
// TEST_F(HAPPYDAY_SCENARIO,xmlIsJuist)
// {
//     TiXmlDocument doc("../Main_Directory/xmlfile.xml");
//
//     ASSERT_TRUE(doc.LoadFile());
//     TiXmlElement* root = doc.RootElement();
//     EXPECT_STREQ("SYSTEM",root->Value());
//
//     for (TiXmlElement* childs = root->FirstChildElement(); childs!= NULL;childs = childs->NextSiblingElement())
//     {
//         string type = childs->Value();
//         if (type == "ROOM")
//         {
//             EXPECT_NE(nullptr,childs->FirstChildElement("NAME"));
//             EXPECT_NE(nullptr,childs->FirstChildElement("CAPACITY"));
//             EXPECT_NE(nullptr,childs->FirstChildElement("IDENTIFIER"));
//
//             EXPECT_GT(stoi(childs->FirstChildElement("CAPACITY")->GetText()),0);
//         }
//         else if (type == "MEETING")
//         {
//             EXPECT_NE(nullptr,childs->FirstChildElement("LABEL"));
//             EXPECT_NE(nullptr,childs->FirstChildElement("ROOM"));
//             EXPECT_NE(nullptr,childs->FirstChildElement("IDENTIFIER"));
//             EXPECT_NE(nullptr,childs->FirstChildElement("DATE"));
//         }
//         else if (type == "PARTICIPATION") {
//             EXPECT_NE(nullptr,childs->FirstChildElement("MEETING"));
//             EXPECT_NE(nullptr,childs->FirstChildElement("USER"));
//         }
//
//     }
// }

//
// TEST_F(SYSTEMTESTS, NoRoomViolation)
// {
//     EXPECT_EQ(FileCompare())
// }
//
// TEST_F(SYSTEMTESTS, NoRoomViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/NoRoom.xml"), "De XML bestand moet ROOM element hebben.");
//
// }
// TEST_F(SYSTEMTESTS, NoParticipationViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/NoParticipation.xml"), "De XML bestand moet PARTICIPATION element hebben.");
//
// }
// TEST_F(SYSTEMTESTS, NoMeetingViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/NoMeeting.xml"), "De XML bestand moet MEETINGS element hebben.");
//
// }
//
// TEST_F(SYSTEMTESTS, NonExistingRoomViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/Meeting_NoExistingRoom.xml"), "MEETING wijst naar ROOM die niet bestaat");
// }
//
// TEST_F(SYSTEMTESTS, NoExistingMeetingViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/Participation_NoExistingMeeting.xml"), "PARTICIPATION wijst naar een MEETING die niet bestaat");
// }
//
// TEST_F(SYSTEMTESTS, DubbleRoomViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/DubbelRoom.xml"), "Dubbele ROOM IDENTIFIER");
// }
//
// TEST_F(SYSTEMTESTS, DubbleMeetingViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/DubbelMeeting.xml"), "Dubbele MEETING IDENTIFIER");
// }
//
// TEST_F(SYSTEMTESTS, CapacityNotIntViolation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/CapacityNoInt.xml"), "CAPACITY moet een int zijn");
// }
//
// TEST_F(SYSTEMTESTS, CapacityNotGreaterThen0Violation)
// {
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/CapacityNotGreaterThen0.xml"), "CAPACITY moet groter zijn dan 0");
// }
// TEST_F(SYSTEMTESTS, AboveMaxRoomCapViolation) {
//
//     EXPECT_DEATH(sss_.parser("../xmlfilesTests/AboveMaxRoomCap.xml"), "Aantal PARTITCIPATIONs is groter dan ROOM CAPACITY");
// }

// TEST(SYSTEM_MEETINGTEST, MeetingTakesPlace) {
//     System s;
//
//     Room* r = new Room();
//     r->setIdentifier("R1");
//     r->setName("Test Room");
//     r->setCapacity(10);
//     s.addRoom(r);
//
//     Meeting* m = new Meeting();
//     m->setId("M1");
//     m->setLabel("Test Meeting");
//     m->setRoom("R1");
//     s.addMeeting(m);
//
//     s.takesPlace(m);
//
//     EXPECT_TRUE(m->getBezig());
// }
//
// TEST(SYSTEM_MEETINGTEST, MeetingCancelled) {
//     System s;
//
//     Room* r1 = new Room();
//     r1->setIdentifier("R1");
//     r1->setName("Test Room");
//     r1->setCapacity(10);
//     s.addRoom(r1);
//
//     Meeting* m1 = new Meeting();
//     m1->setId("M1");
//     m1->setLabel("Test Meeting");
//     m1->setRoom("R1");
//     m1->setDate("2027/10/20");
//     s.addMeeting(m1);
//
//
//     Meeting* m2 = new Meeting();
//     m2->setId("M2");
//     m2->setLabel("Test Meeting");
//     m2->setRoom("R1");
//     m2->setDate("2027/10/20");
//     s.addMeeting(m2);
//
//
//     s.takesPlace(m1);
//     s.takesPlace(m2);
//
//     EXPECT_TRUE(m2->getCanceled());
// }
//
//
//
//
//
//
//
//
//
// TEST(SYSTEM_PRINTTEST, OutputfileIsJuist) {
//     System s;
//     s.parser("../xmlfilesTests/JuisteOutputFile.xml");
//
//     string filename= "OutputIsJuist";
//     s.print(filename);
//
//
//     ifstream f(filename);
//     EXPECT_TRUE(f.is_open());
//     EXPECT_NE(f.peek(), ifstream::traits_type::eof());
//
//     f.close();
// }

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}