//
// Created by Admin on 03/05/2026.
//
#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"
class CAMPUSTESTS: public ::testing::Test {
protected:
    friend class System;
    Campus c;
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
TEST_F(CAMPUSTESTS, idZettenEnOphalen) {
    c.setId("C1");
    EXPECT_EQ(c.getId(), "C1");
}

TEST_F(CAMPUSTESTS, legeIdFaalt) {
    EXPECT_DEATH(c.setId(""), "Id mag niet leeg zijn");
}
TEST_F(CAMPUSTESTS, naamZettenEnOphalen) {
    c.setName("Campus Antwerpen");
    EXPECT_EQ(c.getName(), "Campus Antwerpen");
}

TEST_F(CAMPUSTESTS, legeNaamFaalt) {
    EXPECT_DEATH(c.setName(""), "Naam mag niet leeg zijn");
}
TEST_F(CAMPUSTESTS, volledigCampusCorrect) {
    c.setId("C1");
    c.setName("Campus Antwerpen");

    EXPECT_EQ(c.getId(), "C1");
    EXPECT_EQ(c.getName(), "Campus Antwerpen");
}
TEST_F(CAMPUSTESTS, gettersNietLeegNaZetten) {
    c.setId("C1");
    c.setName("Campus A");

    EXPECT_FALSE(c.getId().empty());
    EXPECT_FALSE(c.getName().empty());
}
TEST_F(CAMPUSTESTS, verkeerdeInputWordtNietGeaccepteerd) {
    EXPECT_DEATH(c.setId(""), "Id mag niet leeg zijn");
    EXPECT_DEATH(c.setName(""), "Naam mag niet leeg zijn");
}
