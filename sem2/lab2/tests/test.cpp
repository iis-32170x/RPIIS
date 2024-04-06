#include "../pioivislab2/mnozh.h"
#include "pch.h"

TEST(CartesianProductTest, TestCartesianProduct) {
    std::vector<std::vector<std::string>> sets = { {"A", "B"}, {"1", "2", "3"}, {"X", "Y"} };
    std::vector<std::vector<std::string>> expected = {
        {"A", "1", "X"}, {"A", "1", "Y"},
        {"A", "2", "X"}, {"A", "2", "Y"},
        {"A", "3", "X"}, {"A", "3", "Y"},
        {"B", "1", "X"}, {"B", "1", "Y"},
        {"B", "2", "X"}, {"B", "2", "Y"},
        {"B", "3", "X"}, {"B", "3", "Y"}
    };

    std::vector<std::vector<std::string>> result = cartesianProduct(sets);

    ASSERT_EQ(result, expected);
}

TEST(CartesianProductTest, TestPrintSet) {
    std::vector<std::string> set = { "A", "B", "C" };
    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    printSet(set);

    std::cout.rdbuf(coutBuffer);
    ASSERT_EQ(output.str(), "<A, B, C> ");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
