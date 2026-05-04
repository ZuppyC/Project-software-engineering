//
// Created by Admin on 04/05/2026.
//
#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"

class RENOVATIONTESTS: public ::testing::Test {
protected:
    friend class System;
    Renovation r;
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
TEST_F(RENOVATIONTESTS, datumCorrectOmgezet) {
    tm* t = r.strToTm("2028-05-22");

    EXPECT_EQ(t->tm_year, 2028 - 1900);
    EXPECT_EQ(t->tm_mon, 4);
    EXPECT_EQ(t->tm_mday, 22);
}
TEST_F(RENOVATIONTESTS, fouteDatumFormaat) {
    EXPECT_DEATH(r.strToTm("20280522"), "Datum moet formaat YYYY-MM-DD zijn");
}

TEST_F(RENOVATIONTESTS, maandBuitenRange) {
    EXPECT_DEATH(r.strToTm("2028-13-10"), "Maand moet tussen 1 en 12 zijn");
}

TEST_F(RENOVATIONTESTS, dagBuitenRange) {
    EXPECT_DEATH(r.strToTm("2028-05-32"), "Dag moet tussen 1 en 31 zijn");
}
TEST_F(RENOVATIONTESTS, setbeginDatum) {
    r.setBeginDatum("2028-01-01");

    EXPECT_NE(r.getBeginDatum(), nullptr);
}

TEST_F(RENOVATIONTESTS, beginDatumFout) {
    EXPECT_DEATH(r.setBeginDatum("20280101"), "Datum moet formaat YYYY-MM-DD zijn");
}
TEST_F(RENOVATIONTESTS, setDate) {
    r.setEindDatum("2028-12-31");

    EXPECT_NE(r.getEindDatum(), nullptr);
}

TEST_F(RENOVATIONTESTS, eindDatumFout) {
    EXPECT_DEATH(r.setEindDatum("20281231"), "Datum moet formaat YYYY-MM-DD zijn");
}
TEST_F(RENOVATIONTESTS, setRoomJuist) {
    r.setRoom("R1");
    EXPECT_EQ(r.getRoom(), "R1");
}

TEST_F(RENOVATIONTESTS, legeRoomFout) {
    EXPECT_DEATH(r.setRoom(""), "ROOM mag niet leeg zijn");
}
TEST_F(RENOVATIONTESTS, datumLigtTussen) {
    r.setBeginDatum("2028-01-01");
    r.setEindDatum("2028-12-31");

    tm* d = r.strToTm("2028-06-01");

    EXPECT_TRUE(r.isTussen(d));
}
TEST_F(RENOVATIONTESTS, datumVoorBegin) {
    r.setBeginDatum("2028-01-01");
    r.setEindDatum("2028-12-31");

    tm* d = r.strToTm("2027-12-31");

    EXPECT_FALSE(r.isTussen(d));
}

TEST_F(RENOVATIONTESTS, datumNaEinde) {
    r.setBeginDatum("2028-01-01");
    r.setEindDatum("2028-12-31");

    tm* d = r.strToTm("2029-01-01");

    EXPECT_FALSE(r.isTussen(d));
}

