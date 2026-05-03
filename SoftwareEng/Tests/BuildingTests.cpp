//
// Created by Admin on 03/05/2026.
//
#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"
class BUILDINGTESTS: public ::testing::Test {
protected:
    friend class System;
    Building b;
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
TEST_F(BUILDINGTESTS, campusZettenEnOphalen) {
    b.setCampus("CampusA");
    EXPECT_EQ(b.getCampus(), "CampusA");
}

TEST_F(BUILDINGTESTS, legeCampusFaalt) {
    EXPECT_DEATH(b.setCampus(""), "Campus mag niet leeg zijn");
}
TEST_F(BUILDINGTESTS, idZettenEnOphalen) {
    b.setId("B1");
    EXPECT_EQ(b.getId(), "B1");
}

TEST_F(BUILDINGTESTS, legeIdFaalt) {
    EXPECT_DEATH(b.setId(""), "Id mag niet leeg zijn");
}
TEST_F(BUILDINGTESTS, naamZettenEnOphalen) {
    b.setName("Gebouw A");
    EXPECT_EQ(b.getName(), "Gebouw A");
}

TEST_F(BUILDINGTESTS, legeNaamFaalt) {
    EXPECT_DEATH(b.setName(""), "Naam mag niet leeg zijn");
}
TEST_F(BUILDINGTESTS, volledigBuildingCorrect) {
    b.setId("B1");
    b.setName("Gebouw A");
    b.setCampus("CampusA");

    EXPECT_EQ(b.getId(), "B1");
    EXPECT_EQ(b.getName(), "Gebouw A");
    EXPECT_EQ(b.getCampus(), "CampusA");
}
TEST_F(BUILDINGTESTS, gettersGevenGeenLegeWaarden) {
    b.setCampus("C1");
    b.setId("ID1");
    b.setName("Naam1");

    EXPECT_FALSE(b.getCampus().empty());
    EXPECT_FALSE(b.getId().empty());
    EXPECT_FALSE(b.getName().empty());
}
TEST_F(BUILDINGTESTS, LegeStringsBijSetters) {
    EXPECT_DEATH(b.setId(""), "Id mag niet leeg zijn");
    EXPECT_DEATH(b.setName(""), "Naam mag niet leeg zijn");
    EXPECT_DEATH(b.setCampus(""), "Campus mag niet leeg zijn");
}