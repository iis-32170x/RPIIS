#include <iostream>
#include "Header.h"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Russian");
    vector <string> sets;
    sets = getSets(inputpath);
    Start(sets);
    fin.close();
    cout << '\n';
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

TEST(Test, Basic) {

    const string test_set = "input.txt";
    const auto result = getSets(test_set);

    vector<string> expected_result;
    expected_result.push_back("A={1,3,2,2,2,5}");
    expected_result.push_back("B={1,{2,5},2,2,3}");

    EXPECT_EQ(result, expected_result);

}

TEST(DifferenceTest, Basic) {

    vector<string> set1 = { "a", "b", "c" };
    vector<string> set2 = { "a", "c" };
    const auto result = setDifference(set1, set2);

    vector<string> expected_result;
    expected_result.push_back("b");

    EXPECT_TRUE(result == expected_result);

}

TEST(SplitTest, Basic) {

    vector<string> sets = {
        "C={A,B,{C,D,E},{F,G},H}"
    };

    vector<vector<string>> expected = {
        {"A","B","{C,D,E}","{F,G}","H"}
    };

    vector<vector<string>> result = splitSets(sets, ',');

    ASSERT_EQ(result, expected);
}
