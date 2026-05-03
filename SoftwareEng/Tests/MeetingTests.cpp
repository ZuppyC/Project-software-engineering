//
// Created by Admin on 02/05/2026.
//
#include "../Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
#include "../xmlparser/tinyxml.h"
#include "../Main_Directory/Output.h"
#include "compare_file.h"

class MEETINGTESTS: public ::testing::Test {
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
TEST_F(MEETINGTESTS, OccupancyKleinerDan1) {
    Meeting m;
    EXPECT_DEATH(m.setOccupancy(1), "Er moeten 2 or meer mensen in de ROOM kunnen");
}
TEST_F(MEETINGTESTS, setOccupancyFout) {
    Meeting m;
    EXPECT_NO_THROW(m.setOccupancy(2));
    EXPECT_EQ(m.getOccupancy(), 2);
}
TEST_F(MEETINGTESTS, co2StandaardFalse) {
    Meeting m;
    EXPECT_FALSE(m.getCo2Tracked());
}

TEST_F(MEETINGTESTS, co2OpTrueZetten) {
    Meeting m;
    m.setCo2Tracked(true);
    EXPECT_TRUE(m.getCo2Tracked());
}
TEST_F(MEETINGTESTS, idZettenEnOphalen) {
    Meeting m;
    m.setId("een ID");
    EXPECT_EQ(m.getId(), "een ID");
}

TEST_F(MEETINGTESTS, legeIdFOUT) {
    Meeting m;
    EXPECT_DEATH(m.setId(""), "Er is geen MEETING");
}
TEST_F(MEETINGTESTS, labelZetten) {
    Meeting m;
    m.setLabel("Test");
    EXPECT_EQ(m.getLabel(), "Test");
}

TEST_F(MEETINGTESTS, leegLabelFOUT) {
    Meeting m;
    EXPECT_DEATH(m.setLabel(""), "Er is geen LABEL");
}
TEST_F(MEETINGTESTS, roomZetten) {
    Meeting m;
    m.setRoom("een Room");
    EXPECT_EQ(m.getRoom(), "een Room");
}

TEST_F(MEETINGTESTS, legeRoomFOUT) {
    Meeting m;
    EXPECT_DEATH(m.setRoom(""), "Er is geen ROOM");
}
TEST_F(MEETINGTESTS, geldigeDatum) {
    Meeting m;
    EXPECT_NO_THROW(m.setDate("2028-05-22"));
}

TEST_F(MEETINGTESTS, fouteDatum) {
    Meeting m;
    EXPECT_DEATH(m.setDate("20280522"), "DATE moet formaat YYYY-MM-DD zijn");
}
TEST_F(MEETINGTESTS, DatumJuistOmzetten) {
    Meeting m;
    tm* t = m.strToTm("2028-05-22");

    EXPECT_EQ(t->tm_year, 128);
    EXPECT_EQ(t->tm_mon, 4);
    EXPECT_EQ(t->tm_mday, 22);
}
TEST_F(MEETINGTESTS, setPartJuist) {
    Meeting m;
    Participation* p = new Participation();

    m.setPart(p);

    EXPECT_EQ(m.getPart().size(), 1);
    delete p;
}

TEST_F(MEETINGTESTS, ParticipantNullptr) {
    Meeting m;
    EXPECT_DEATH(m.setPart(nullptr),"Er is geen PARTICIPATION");
}
TEST_F(MEETINGTESTS, meetingInVerleden) {
    Meeting m;
    m.setDate("2000-01-01");
    EXPECT_TRUE(m.isPast());
}

TEST_F(MEETINGTESTS, meetingInToekomst) {
    Meeting m;
    m.setDate("2100-01-01");
    EXPECT_FALSE(m.isPast());
}
TEST_F(MEETINGTESTS, meetingsConflict) {
    Meeting m1;
    Meeting m2;

    m1.setDate("2028-05-22");
    m2.setDate("2028-05-22");

    m1.setRoom("R1");
    m2.setRoom("R1");

    m1.setHour(10);
    m2.setHour(10);

    EXPECT_TRUE(m1.conflictsWith(&m2));
}

TEST_F(MEETINGTESTS, meetingsGeenConflict) {
    Meeting m1;
    Meeting m2;

    m1.setDate("2028-05-22");
    m2.setDate("2028-05-22");

    m1.setRoom("R1");
    m2.setRoom("R2");

    m1.setHour(10);
    m2.setHour(10);

    EXPECT_FALSE(m1.conflictsWith(&m2));
}
TEST_F(MEETINGTESTS, setBezigJuist) {
    Meeting m;
    m.setBezig(true);
    EXPECT_TRUE(m.getBezig());
}

TEST_F(MEETINGTESTS, setCancelJuist) {
    Meeting m;
    m.setCanceled(true);
    EXPECT_TRUE(m.getCanceled());
}
TEST_F(MEETINGTESTS, setOnlineJuist) {
    Meeting m;
    m.setOnline(true);
    EXPECT_TRUE(m.getOnline());
}
TEST_F(MEETINGTESTS, cateringTrue) {
    Meeting m;
    m.setCatering("true");
    EXPECT_TRUE(m.getCatering());
}

TEST_F(MEETINGTESTS, fouteCatering) {
    Meeting m;
    EXPECT_DEATH(m.setCatering("balright"), "De CATERING variabele mag alleen 'true' of 'false' zijn.");
}
TEST_F(MEETINGTESTS, externalsTrue) {
    Meeting m;
    m.setExternals("true");
    EXPECT_TRUE(m.getExternals());
}
TEST_F(MEETINGTESTS, UurJuist) {
    Meeting m;
    m.setHour(12);
    EXPECT_EQ(m.getHour(), 12);
}

TEST_F(MEETINGTESTS, foutUur) {
    Meeting m;
    EXPECT_DEATH(m.setHour(25), "");
}