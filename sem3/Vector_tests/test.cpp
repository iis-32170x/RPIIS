#include "pch.h"
#include "D:\БГУИР\Курс 2\ППОИС\lab1\vector\vector.cpp"

TEST(VectorTest, DefaultConstructor) {
    Vector v;
    EXPECT_EQ(v.length(), 0);
}

TEST(VectorTest, ParameterizedConstructor) {
    Vector v(0, 0, 0, 1, 1, 1);
    EXPECT_DOUBLE_EQ(v.length(), std::sqrt(3));
}

// Тесты для оператора +
TEST(VectorTest, AdditionOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2(1, 1, 1, 2, 2, 2);
    Vector result = v1 + v2;
    EXPECT_DOUBLE_EQ(result.length(), std::sqrt(12));
}

// Тесты для оператора +=
TEST(VectorTest, AdditionAssignmentOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2(1, 1, 1, 2, 2, 2);
    v1 += v2;
    EXPECT_DOUBLE_EQ(v1.length(), std::sqrt(12));
}

// Тесты для оператора -
TEST(VectorTest, SubtractionOperator) {
    Vector v1(1, 1, 1, 3, 3, 3);
    Vector v2(0, 0, 0, 1, 1, 1);
    Vector result = v1 - v2;
    EXPECT_DOUBLE_EQ(result.length(), std::sqrt(3));
}

// Тесты для оператора -=
TEST(VectorTest, SubtractionAssignmentOperator) {
    Vector v1(1, 1, 1, 2, 2, 2);
    Vector v2(0, 0, 0, 1, 1, 1);
    v1 -= v2;
    EXPECT_DOUBLE_EQ(v1.length(), 0.0);
}

// Тесты для оператора *
TEST(VectorTest, MultiplicationOperator) {
    Vector v1(0, 0, 0, 1, 0, 1);
    Vector v2(1, 1, 1, 2, 2, 1);
    Vector result = v1 * v2;
    EXPECT_DOUBLE_EQ(result.length(), std::sqrt(3));
}

// Тесты для оператора *=
TEST(VectorTest, MultiplicationAssignmentOperator) {
    Vector v1(0, 0, 0, 4, 69, 37);
    Vector v2(1, 1, 1, -3.2, 86, -68);
    v1 *= v2;
    std::ostringstream output;
    output << v1;
    EXPECT_EQ(output.str(), "(0, 0, 0, -7906, 120.6, 629.8)");
}

// Тесты для оператора * (скаляр)
TEST(VectorTest, ScalarMultiplicationOperator) {
    Vector v(0, 0, 0, 1, 1, 1);
    Vector result = v * 2.0;
    EXPECT_DOUBLE_EQ(result.length(), std::sqrt(12));
}

// Тесты для оператора *= (скаляр)
TEST(VectorTest, ScalarMultiplicationAssignmentOperator) {
    Vector v(0, 0, 0, 1, 1, 1);
    v *= 2.0;
    EXPECT_DOUBLE_EQ(v.length(), std::sqrt(12));
}

// Тесты для оператора /
TEST(VectorTest, DivisionOperator) {
    Vector v1(0, 0, 0, 2, 0, 2);
    Vector v2(1, 1, 1, 3, 3, 3);
    Vector result = v1 / v2;
    EXPECT_DOUBLE_EQ(result.length(), std::sqrt(2));
}

// Тесты для оператора /= 
TEST(VectorTest, DivisionAssignmentOperator) {
    Vector v1(0, 0, 0, 2, 2, 3);
    Vector v2(1, 1, 1, 3, 3, 3);
    v1 /= v2;
    std::ostringstream output;
    output << v1;
    EXPECT_EQ(output.str(), "(0, 0, 0, -0.5, 0.5, 0)");
}

// Тесты для оператора ^
TEST(VectorTest, DotProductOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2(1, 1, 1, 2, 2, 2);
    EXPECT_DOUBLE_EQ(v1 ^ v2, 1.0);
}

// Тесты для оператора ==
TEST(VectorTest, EqualityOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2(0, 0, 0, 1, 1, 1);
    EXPECT_TRUE(v1 == v2);
}

// Тесты для оператора !=
TEST(VectorTest, InequalityOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2(1, 1, 1, 2, 2, 2);
    EXPECT_TRUE(v1 != v2);
}

// Тесты для оператора >
TEST(VectorTest, GreaterThanOperator) {
    Vector v1(0, 0, 0, 2, 2, 2);
    Vector v2(0, 0, 0, 1, 1, 1);
    EXPECT_TRUE(v1 > v2);
}

// Тесты для оператора <
TEST(VectorTest, LessThanOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2(0, 0, 0, 2, 2, 2);
    EXPECT_TRUE(v1 < v2);
}

// Тесты для оператора >=
TEST(VectorTest, GreaterThanOrEqualOperator) {
    Vector v1(0, 0, 0, 2, 2, 2);
    Vector v2(0, 0, 0, 1, 1, 1);
    Vector v3(0, 0, 0, 2, 2, 2);
    EXPECT_TRUE(v1 >= v2);
    EXPECT_TRUE(v1 >= v3);
}

// Тесты для оператора <=
TEST(VectorTest, LessThanOrEqualOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2(0, 0, 0, 2, 2, 2);
    Vector v3(0, 0, 0, 1, 1, 1);
    EXPECT_TRUE(v1 <= v2);
    EXPECT_TRUE(v1 <= v3);
}

// Тесты для оператора =
TEST(VectorTest, AssignmentOperator) {
    Vector v1(0, 0, 0, 1, 1, 1);
    Vector v2 = v1;
    EXPECT_TRUE(v1 == v2);
}

// Тесты для функции display
TEST(VectorTest, DisplayFunction) {
    Vector v(0, 0, 0, 1, 1, 1);
    testing::internal::CaptureStdout();
    v.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(0, 0, 0) -> (1, 1, 1)\n");
}

// Тесты для оператора ввода
TEST(VectorTest, InputOperator) {
    Vector v;
    std::istringstream input("0 0 0 1 1 1");
    input >> v;
    EXPECT_DOUBLE_EQ(v.length(), std::sqrt(3));
}

// Тесты для оператора вывода
TEST(VectorTest, OutputOperator) {
    Vector v(0, 0, 0, 1, 1, 1);
    std::ostringstream output;
    output << v;
    EXPECT_EQ(output.str(), "(0, 0, 0, 1, 1, 1)");
}
