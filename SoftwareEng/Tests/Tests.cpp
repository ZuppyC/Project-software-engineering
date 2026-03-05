#include "..\Main_Directory/System.h"
#include "gtest/gtest.h"
#include "iostream"
System s;
TEST(SystemTest, stest) {
    EXPECT_EQ(nullptr, s.parser("..\\Main_Directory\\xmlfile.xml"));


}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}