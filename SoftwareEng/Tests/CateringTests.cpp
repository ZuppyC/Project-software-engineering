//
// Created by Admin on 04/05/2026.
//
#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"
class CATERINGTESTS : public ::testing::Test {
protected:
    friend class System;
    Catering c;
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
TEST_F(CATERINGTESTS, setCampusJuist) {
    c.setCampus("CampusA");
    EXPECT_EQ(c.getCampus(), "CampusA");
}

TEST_F(CATERINGTESTS, setCampusFout) {
    EXPECT_DEATH(c.setCampus(""), "Campus mag niet leeg zijn");
}
TEST_F(CATERINGTESTS, setCo2Juist) {
    c.setCo2(100);
    EXPECT_DOUBLE_EQ(c.getCo2(), 100);
}

TEST_F(CATERINGTESTS, setCo2Fout) {
    EXPECT_DEATH(c.setCo2(-1), "CO2 mag niet negatief zijn");
}
TEST_F(CATERINGTESTS, gettersJuist) {
    c.setCampus("C1");
    c.setCo2(50);

    EXPECT_EQ(c.getCampus(), "C1");
    EXPECT_EQ(c.getCo2(), 50);
}

