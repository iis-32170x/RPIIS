#include "pch.h"
#include <gtest/gtest.h>


TEST(OMassiveTest, DsortTest1) {
    OMassive myStruct;
    myStruct.arr = { 1, 5, 3, 8, 2 };
    myStruct.dsort(myStruct.arr);
     vector<int> expected = { 1, 2, 3, 5, 8 };
    ASSERT_EQ(myStruct.arr, expected);
}

TEST(OMassiveTest, DsortTest2) {
    OMassive myStruct;
    myStruct.arr = { 10, 6, 4, 7, 9 };
    myStruct.dsort(myStruct.arr);
     vector<int> expected = { 4, 6, 7, 9, 10 };
    ASSERT_EQ(myStruct.arr, expected);
}

TEST(OMassiveTest, DsortTest3) {
    OMassive myStruct;
    myStruct.arr = { 100, 50, 30, 80, 20 };
    myStruct.dsort(myStruct.arr);
     vector<int> expected = { 20, 30, 50, 80, 100 };
    ASSERT_EQ(myStruct.arr, expected);
}

TEST(OMassiveTest, AddTest1) {
    OMassive myStruct;
    myStruct.arr = { 1, 5, 3 };
    myStruct.add(8);
     vector<int> expected = { 1, 3, 5, 8 };
    ASSERT_EQ(myStruct.arr, expected);
}

TEST(OMassiveTest, AddTest2) {
    OMassive myStruct;
    myStruct.arr = { 10, 6, 4 };
    myStruct.add(7);
     vector<int> expected = { 4, 6, 7, 10 };
    ASSERT_EQ(myStruct.arr, expected);
}

TEST(OMassiveTest, AddTest3) {
    OMassive myStruct;
    myStruct.arr = { 100, 50, 30 };
    myStruct.add(80);
     vector<int> expected = { 30, 50, 80, 100 };
    ASSERT_EQ(myStruct.arr, expected);
}

TEST(OMassiveTest, ObjedinenieTest1) {
    OMassive myStruct;
    myStruct.arr = { 1, 5, 3 };
     vector<int> arr2 = { 8, 2, 6 };
     vector<int> result = myStruct.objedinenie(arr2);
     vector<int> expected = { 1, 2, 3, 5, 6, 8 };
    myStruct.dsort(expected); 
    ASSERT_EQ(result, expected);
}

TEST(OMassiveTest, ObjedinenieTest2) {
    OMassive myStruct;
    myStruct.arr = { 10, 6, 4 };
     vector<int> arr2 = { 7, 9, 11 };
     vector<int> result = myStruct.objedinenie(arr2);
     vector<int> expected = { 4, 6, 7, 9, 10, 11 };
    myStruct.dsort(expected); 
    ASSERT_EQ(result, expected);
}

TEST(OMassiveTest, ObjedinenieTest3) {
    OMassive myStruct;
    myStruct.arr = { 100, 50, 30 };
     vector<int> arr2 = { 80, 120, 70 };
     vector<int> result = myStruct.objedinenie(arr2);
     vector<int> expected = { 30, 50, 70, 80, 100, 120 };
    myStruct.dsort(expected); 
    ASSERT_EQ(result, expected);
}

TEST(OMassiveTest, Perese4enieTest1) {
    OMassive myStruct;
    myStruct.arr = { 1, 5, 3, 8, 2 };
     vector<int> arr2 = { 2, 4, 6 };
     vector<int> result = myStruct.perese4enie(arr2);
     vector<int> expected = { 2 };
    ASSERT_EQ(result, expected);
}

TEST(OMassiveTest, Perese4enieTest2) {
    OMassive myStruct;
    myStruct.arr = { 10, 6, 4, 7, 9 };
     vector<int> arr2 = { 5, 7, 9, 11 };
     vector<int> result = myStruct.perese4enie(arr2);
     vector<int> expected = { 7, 9 };
    ASSERT_EQ(result, expected);
}

TEST(OMassiveTest, Perese4enieTest3) {
    OMassive myStruct;
    myStruct.arr = { 100, 50, 30, 80, 20 };
     vector<int> arr2 = { 10, 20, 30, 40, 50 };
     vector<int> result = myStruct.perese4enie(arr2);
     vector<int> expected = { 20, 30, 50 };
    ASSERT_EQ(result, expected);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}