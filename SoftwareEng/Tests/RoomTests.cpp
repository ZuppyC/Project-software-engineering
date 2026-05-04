//
// Created by Admin on 04/05/2026.
//
#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"
#include "compare_file.h"
class ROOMTESTS : public ::testing::Test {
protected:
    friend class System;
    Room r;
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
TEST_F(ROOMTESTS, setCapacityJuist) {
    r.setCapacity(10);
    EXPECT_EQ(r.getCapacity(), 10);
}

TEST_F(ROOMTESTS, setCapacityFout) {
    EXPECT_DEATH(r.setCapacity(0), "CAPACITY moet groter zijn dan 0");
}
TEST_F(ROOMTESTS, setIdentifierJuist) {
    r.setIdentifier("R1");
    EXPECT_EQ(r.getIdentifier(), "R1");
}

TEST_F(ROOMTESTS, setIdentifierFout) {
    EXPECT_DEATH(r.setIdentifier(""), "Er is geen IDENTIFIER");
}
TEST_F(ROOMTESTS, setNameJuist) {
    r.setName("Room A");
    EXPECT_EQ(r.getName(), "Room A");
}

TEST_F(ROOMTESTS, setNameFout) {
    EXPECT_DEATH(r.setName(""), "Er is geen NAME");
}
TEST_F(ROOMTESTS, setBuildingJuist) {
    r.setBuilding("B1");
    EXPECT_EQ(r.getBuilding(), "B1");
}

TEST_F(ROOMTESTS, setBuildingFout) {
    EXPECT_DEATH(r.setBuilding(""), "Building mag niet leeg zijn");
}
TEST_F(ROOMTESTS, setCammpusJuist) {
    r.setCampus("Campus1");
    EXPECT_EQ(r.getCampus(), "Campus1");
}

TEST_F(ROOMTESTS, setCampusFout) {
    EXPECT_DEATH(r.setCampus(""), "Campus mag niet leeg zijn");
}