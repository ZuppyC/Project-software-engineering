#include "..\Main_Directory/System.h"
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


TEST_F(SYSTEMTESTS, test1)
{
    EXPECT_TRUE(sss_.properlyInitialized());
    EXPECT_EQ(nullptr, sss_.parser("xmlfile.xml"));


}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}