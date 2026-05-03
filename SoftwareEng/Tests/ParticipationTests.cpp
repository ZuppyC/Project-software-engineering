//
// Created by Admin on 02/05/2026.
//

#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"
#include "compare_file.h"

class PARTICIPATIONTESTS: public ::testing::Test {
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

TEST_F(PARTICIPATIONTESTS, ExternalNoBoolean) {
    Participation* p= new Participation();

    EXPECT_DEATH(p->setExternal("geenBool"), "De EXTERNAL variabele mag alleen 'true' of 'false' zijn.");
}
TEST_F(PARTICIPATIONTESTS, SetExternalFoutTrue) {
    Participation* p= new Participation();
    EXPECT_NO_THROW(p->setExternal("true"));
    EXPECT_TRUE(p->getExternal());
}

TEST_F(PARTICIPATIONTESTS, SetExternalFoutFalse) {
    Participation* p= new Participation();

    EXPECT_NO_THROW(p->setExternal("false"));
    EXPECT_FALSE(p->getExternal());
}
TEST_F(PARTICIPATIONTESTS, UserLegeString) {
    Participation* p= new Participation();
    EXPECT_DEATH(p->setUser(""), "Er is geen USER");
}
TEST_F(PARTICIPATIONTESTS, setUserfout) {
    Participation* p= new Participation();
    EXPECT_NO_THROW(p->setUser("User"));
    EXPECT_EQ(p->getUser(), "User");
}

TEST_F(PARTICIPATIONTESTS, MeetingLegeString) {
    Participation* p= new Participation();
    EXPECT_DEATH(p->setmeeting(""), "Er is geen MEETING");
}
TEST_F(PARTICIPATIONTESTS, setMeetingfout) {
    Participation* p= new Participation();
    EXPECT_NO_THROW(p->setmeeting("Meeting"));
    EXPECT_EQ(p->getmeeting(), "Meeting");
}