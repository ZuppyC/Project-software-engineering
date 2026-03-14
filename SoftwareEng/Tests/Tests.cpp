#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
System s;

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
    System sss_;

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
    System happydaysss_;

};

TEST_F(HAPPYDAY_SCENARIO,xmlIsJuist)
{
    TiXmlDocument doc("../Main_Directory/xmlfile.xml");
    ASSERT_TRUE(doc.LoadFile());
    TiXmlElement* root = doc.RootElement();
    EXPECT_STREQ("SYSTEM",root->Value());

    for (TiXmlElement* childs = root->FirstChildElement(); childs!= NULL;childs = childs->NextSiblingElement())
    {
        string type = childs->Value();
        if (type == "ROOM")
        {
            EXPECT_NE(nullptr,childs->FirstChildElement("NAME"));
            EXPECT_NE(nullptr,childs->FirstChildElement("CAPACITY"));
            EXPECT_NE(nullptr,childs->FirstChildElement("IDENTIFIER"));

            EXPECT_GT(stoi(childs->FirstChildElement("CAPACITY")->GetText()),0);
        }
        else if (type == "MEETING")
        {
            EXPECT_NE(nullptr,childs->FirstChildElement("LABEL"));
            EXPECT_NE(nullptr,childs->FirstChildElement("ROOM"));
            EXPECT_NE(nullptr,childs->FirstChildElement("IDENTIFIER"));
            EXPECT_NE(nullptr,childs->FirstChildElement("DATE"));
        }
        else if (type == "PARTICIPATION") {
            EXPECT_NE(nullptr,childs->FirstChildElement("MEETING"));
            EXPECT_NE(nullptr,childs->FirstChildElement("USER"));
        }

    }
}








TEST_F(SYSTEMTESTS, NoRoomViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/NoRoom.xml"), "De XML bestand moet ROOM element hebben.");

}
TEST_F(SYSTEMTESTS, NoParticipationViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/NoParticipation.xml"), "De XML bestand moet PARTICIPATION element hebben.");

}
TEST_F(SYSTEMTESTS, NoMeetingViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/NoMeeting.xml"), "De XML bestand moet MEETINGS element hebben.");

}

TEST_F(SYSTEMTESTS, NonExistingRoomViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/Meeting_NoExistingRoom.xml"), "MEETING wijst naar ROOM die niet bestaat");
}

TEST_F(SYSTEMTESTS, NoExistingMeetingViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/Participation_NoExistingMeeting.xml"), "PARTICIPATION wijst naar een MEETING die niet bestaat");
}

TEST_F(SYSTEMTESTS, DubbleRoomViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/DubbelRoom.xml"), "Dubbele ROOM IDENTIFIER");
}

TEST_F(SYSTEMTESTS, DubbleMeetingViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/DubbelMeeting.xml"), "Dubbele MEETING IDENTIFIER");
}

TEST_F(SYSTEMTESTS, CapacityNotIntViolation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/CapacityNoInt.xml"), "CAPACITY moet een int zijn");
}

TEST_F(SYSTEMTESTS, CapacityNotGreaterThen0Violation)
{
    EXPECT_DEATH(sss_.parser("../xmlfilesTests/CapacityNotGreaterThen0.xml"), "CAPACITY moet groter zijn dan 0");
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}