//
// Created by Admin on 04/05/2026.
//

#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"
#include "compare_file.h"
class OUTPUTTESTS : public ::testing::Test {
protected:
    friend class System;
    Output o;
    System s;
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
TEST_F(OUTPUTTESTS, SystemOutputError) {
    System s("../xmlfilesTests/SysteemOutputFout.xml");
    Output o;
    s.takePlaceEveryMeeting();
    o.print("SystemOutputTest.txt", s);

    EXPECT_TRUE(FileCompare("../Expected_output_tests/SysteemOutputIsJuist.txt","SystemOutputTest.txt"));

}
TEST_F(OUTPUTTESTS, geenRoomsFout) {

    EXPECT_DEATH(o.print("test.txt", s), "Er zijn geen ROOMs");
}
TEST_F(OUTPUTTESTS, geenMeetingsFout) {
    Room* r = new Room();
    r->setIdentifier("R1");
    s.addRoom(r);
    delete r;
    EXPECT_DEATH(o.print("test.txt", s), "Er zijn geen MEETINGs");
}
TEST_F(OUTPUTTESTS, geenParticipationsFout) {
    Room* r = new Room();
    r->setIdentifier("R1");
    s.addRoom(r);
    delete r;

    Meeting* m = new Meeting();
    m->setRoom("R1");
    s.addMeeting(m);
    delete m;

    EXPECT_DEATH(o.print("test.txt", s), "Er zijn geen PARTICIPATIONs");
}
TEST_F(OUTPUTTESTS, printJuist) {
    Room* r = new Room();
    r->setIdentifier("R1");
    r->setCampus("C1");
    s.addRoom(r);

    Meeting* m = new Meeting();
    m->setRoom("R1");
    m->setCatering("false");
    s.addMeeting(m);

    Participation* p = new Participation();
    s.addParticipation(p);
    m->setPart(p);

    Catering* c = new Catering();
    c->setCampus("C1");
    c->setCo2(10);
    s.addCatering(c);

    o.print("test.txt", s);

    ifstream file("test.txt");
    EXPECT_TRUE(file.good());
}