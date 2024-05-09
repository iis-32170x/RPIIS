#include "../StaticLib/bor.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

TEST(BorTest, InsertAndFind) {
    bor b;
    b.insert("apple", 1);
    b.insert("application", 2);
    b.insert("banana", 3);

    EXPECT_EQ(b.find("apple"), 1);
    EXPECT_EQ(b.find("application"), 2);
    EXPECT_EQ(b.find("banana"), 3);
    EXPECT_EQ(b.find("orange"), -1);
    cout << "Good";
}

TEST(BorTest, Delete) {
    bor b;
    b.insert("apple", 1);
    b.insert("application", 2);
    b.insert("banana", 3);

    EXPECT_TRUE(b.del("apple"));
    EXPECT_EQ(b.find("apple"), -1);
    EXPECT_EQ(b.find("application"), 2);
    EXPECT_EQ(b.find("banana"), 3);
}

TEST(BorTest, DeleteNonexistentWord) {
    bor b;
    b.insert("apple", 1);
    b.insert("application", 2);
    b.insert("banana", 3);

    EXPECT_FALSE(b.del("orange"));
    EXPECT_EQ(b.find("apple"), 1);
    EXPECT_EQ(b.find("application"), 2);
    EXPECT_EQ(b.find("banana"), 3);
}

TEST(BorTest, FindNonexistentWord) {
    bor b;
    b.insert("apple", 1);
    b.insert("application", 2);
    b.insert("banana", 3);

    EXPECT_EQ(b.find("orange"), -1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}