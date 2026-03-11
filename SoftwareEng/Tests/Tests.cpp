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




int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}