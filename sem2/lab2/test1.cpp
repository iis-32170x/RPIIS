//
// Created by Катюша Рублевская on 22.02.24.

#include <gtest/gtest.h>
#include "Header.h"

TEST(HelloTest, BasicAssertions) {
    const string test_set = "../tests/test1.txt";
    const auto result = getSets(test_set);
    std::vector<string> expected_result;
    expected_result.push_back("C={A,B}");
    expected_result.push_back("D={A,B,C}");
    EXPECT_EQ( result, expected_result);

}
