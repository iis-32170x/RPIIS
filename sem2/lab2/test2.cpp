//
// Created by Катюша Рублевская on 28.02.24.
//
#include <gtest/gtest.h>
#include "Header.h"


TEST(SetDifferenceTest, BasicAssertions) {

    std::vector<std::string> set1 = {"a", "b", "c"};
    std::vector<std::string> set2 = {"b", "c"};
    const auto result = setDifference(set1, set2);


    std::vector<std::string> expected_result;
    expected_result.push_back("a");


    EXPECT_TRUE(result == expected_result);
}






/*TEST(SetDifferenceTest, BasicAssertions) {

    vector<string> set1 = {"a", "b", "c", "d"};
    vector<string> set2 = {"c", "d"};


    vector<string> expected_result = {"a", "b"};


    vector<string> result = setDifference(set1, set2);


    EXPECT_EQ(result, expected_result);
}*/