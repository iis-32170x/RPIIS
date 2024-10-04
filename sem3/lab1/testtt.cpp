#include <UnitTest++/UnitTest++.h>
#include "full_lab/decimal_realisation.cpp"

TEST(SUM) {
    decimal drob1{2, 3};
    decimal drob2{3, 4};
    decimal drob3{1, 6};

    CHECK_EQUAL(17, (drob1 + drob2).get_numerator());
    CHECK_EQUAL(12, (drob1 + drob2).get_denominator());

    CHECK_EQUAL(19, (drob1 + drob2 + drob3).get_numerator());
    CHECK_EQUAL(12, (drob1 + drob2 + drob3).get_denominator());
}

TEST(SUBTRACTION) {
    decimal drob1{5, 6};
    decimal drob2{1, 3};
    decimal drob3{1, 6};

    CHECK_EQUAL(1, (drob1 - drob2).get_numerator());
    CHECK_EQUAL(2, (drob1 - drob2).get_denominator());

    CHECK_EQUAL(1, (drob1 - drob2 - drob3).get_numerator());
    CHECK_EQUAL(3, (drob1 - drob2 - drob3).get_denominator());
}

TEST(MULTIPLICATION) {
    decimal drob1{2, 3};
    decimal drob2{3, 5};
    decimal drob3{4, 7};

    CHECK_EQUAL(2, (drob1 * drob2).get_numerator());
    CHECK_EQUAL(5, (drob1 * drob2).get_denominator());

    CHECK_EQUAL(8, (drob1 * drob2 * drob3).get_numerator());
    CHECK_EQUAL(35, (drob1 * drob2 * drob3).get_denominator());
}

TEST(DIVISION) {
    decimal drob1{4, 5};
    decimal drob2{2, 3};
    decimal drob3{1, 2};

    CHECK_EQUAL(6, (drob1 / drob2).get_numerator());
    CHECK_EQUAL(5, (drob1 / drob2).get_denominator());

    CHECK_EQUAL(12, (drob1 / drob2 / drob3).get_numerator());
    CHECK_EQUAL(5, (drob1 / drob2 / drob3).get_denominator());
}

TEST(SUM_WITH_INTEGER) {
    decimal drob1{2, 3};
    int operand2 = 2;

    CHECK_EQUAL(8, (drob1 + operand2).get_numerator());
    CHECK_EQUAL(3, (drob1 + operand2).get_denominator());

    decimal drob2{3, 4};
    int operand3 = 1;

    CHECK_EQUAL(7, (drob2 + operand3).get_numerator());
    CHECK_EQUAL(4, (drob2 + operand3).get_denominator());
}

TEST(SUBTRACTION_WITH_INTEGER) {
    decimal drob1{5, 6};
    int operand2 = 1;

    CHECK_EQUAL(-1, (drob1 - operand2).get_numerator());
    CHECK_EQUAL(6, (drob1 - operand2).get_denominator());

    decimal drob2{7, 5};
    int operand3 = 3;

    CHECK_EQUAL(-8, (drob2 - operand3).get_numerator());
    CHECK_EQUAL(5, (drob2 - operand3).get_denominator());
}

TEST(MULTIPLICATION_WITH_INTEGER) {
    decimal drob1{2, 3};
    int operand2 = 4;

    CHECK_EQUAL(8, (drob1 * operand2).get_numerator());
    CHECK_EQUAL(3, (drob1 * operand2).get_denominator());

    decimal drob2{3, 7};
    int operand3 = 5;

    CHECK_EQUAL(15, (drob2 * operand3).get_numerator());
    CHECK_EQUAL(7, (drob2 * operand3).get_denominator());
}

TEST(DIVISION_WITH_INTEGER) {
    decimal drob1{4, 5};
    int operand2 = 2;

    CHECK_EQUAL(2, (drob1 / operand2).get_numerator());
    CHECK_EQUAL(5, (drob1 / operand2).get_denominator());

    decimal drob2{9, 4};
    int operand3 = 3;

    CHECK_EQUAL(3, (drob2 / operand3).get_numerator());
    CHECK_EQUAL(4, (drob2 / operand3).get_denominator());
}

TEST(GREATER_THAN_FRACTION) {
    decimal drob1{3, 8};
    decimal drob2{1, 4};

    CHECK_EQUAL(true, drob1 > drob2);
    CHECK_EQUAL(false, drob2 > drob1);
}

TEST(GREATER_THAN_INTEGER) {
    decimal drob1{5, 2};

    CHECK_EQUAL(true, drob1 > 1);
    CHECK_EQUAL(false, drob1 > 3);
}

TEST(LESS_THAN_FRACTION) {
    decimal drob1{1, 3};
    decimal drob2{2, 3};

    CHECK_EQUAL(true, drob1 < drob2);
    CHECK_EQUAL(false, drob2 < drob1);
}

TEST(LESS_THAN_INTEGER) {
    decimal drob1{3, 4};

    CHECK_EQUAL(true, drob1 < 2);
    CHECK_EQUAL(true, drob1 < 1);
}

TEST(GREATER_THAN_OR_EQUAL_FRACTION) {
    decimal drob1{3, 5};
    decimal drob2{3, 5};

    CHECK_EQUAL(true, drob1 >= drob2);

}

TEST(GREATER_THAN_OR_EQUAL_INTEGER) {
    decimal drob1{8, 3};

    CHECK_EQUAL(true, drob1 >= 2);
    CHECK_EQUAL(false, drob1 >= 3);
}

TEST(LESS_THAN_OR_EQUAL_FRACTION) {
    decimal drob1{1, 2};
    decimal drob2{1, 2};
    decimal drob3{2, 5};
    CHECK_EQUAL(true, drob1 <= drob2);
    CHECK_EQUAL(false, drob1 <= drob3);

}

TEST(LESS_THAN_OR_EQUAL_INTEGER) {
    decimal drob1{4, 5};

    CHECK_EQUAL(true, drob1 <= 1);
    CHECK_EQUAL(false, drob1 <= 0);
}

int main(int, char**) {


    return UnitTest::RunAllTests();

}
