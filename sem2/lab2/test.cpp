#include "pch.h"
#include "C:/Всячина/Лаба2(Множества)/Project26/Header.h"

int factorial(int i)
{
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}
Set set0;
TEST(SetTest1, ReadSet) {
    string input = "{1,2,3}";
    set0.readSet(input);

    ASSERT_EQ(set0.inSet.size(), 3);
    EXPECT_EQ(set0.inSet[0], 1);
    EXPECT_EQ(set0.inSet[1], 2);
    EXPECT_EQ(set0.inSet[2], 3);
}
Set set1;
TEST(SetTest2, ReadSet) {
    testing::internal::CaptureStdout();
    string input = "{1,2,3,}";
    set1.readSet(input);
    string error = testing::internal::GetCapturedStdout();
    EXPECT_EQ(error, "Error");
    EXPECT_EQ(set1.inSet.size(), 0);
    input = "{,1,2,3}";
    cout.clear();
    EXPECT_EQ(set1.inSet.size(), 0);
    input = "{1,,2,3}";
    cout.clear();
    EXPECT_EQ(set1.inSet.size(), 0);
}
TEST(SetTest2_5, ReadSet) {
    testing::internal::CaptureStdout();
    string input = "{1,2,3";
    set1.readSet(input);
    string error = testing::internal::GetCapturedStdout();
    EXPECT_EQ(error, "Error");
    EXPECT_EQ(set1.inSet.size(), 0);
    input = "1,2,3}";
    cout.clear();
    EXPECT_EQ(set1.inSet.size(), 0);
}
Set set2;
TEST(SetTest3, GenSet) {
    string input = "<1,2,3>";
    set2.readSet(input);
    testing::internal::CaptureStdout();
    set2.genSet();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n1 3 2 \n2 1 3 \n2 3 1 \n3 1 2 \n3 2 1 \n");
}
Set set3;
TEST(SetTest4, GenSet) {
    string input = "<5,17,2>";
    set3.readSet(input);
    testing::internal::CaptureStdout();
    set3.genSet();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2 5 17 \n2 17 5 \n5 2 17 \n5 17 2 \n17 2 5 \n17 5 2 \n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
