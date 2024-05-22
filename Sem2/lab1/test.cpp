#include "pch.h"
#include <gtest/gtest.h>
#include "C:\Users\Filip\Desktop\2 ñåìåñòð\ÏÈÎÈÂÈÑ\lab1\lab1\Header.h"
using namespace std;

TEST(DequeTest, PushBack) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);

    EXPECT_EQ(d.x[0], 10);
    EXPECT_EQ(d.x[1], 20);
    EXPECT_EQ(d.tail, 2);
}

TEST(DequeTest, PushFront) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_front(&d, 10);
    push_front(&d, 20);

    EXPECT_EQ(d.x[max_elementov - 1], 10);
    EXPECT_EQ(d.x[max_elementov - 2], 20);
    EXPECT_EQ(d.head, max_elementov - 2);
}

TEST(DequeTest, PopFront) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);
    push_back(&d, 30);

    int value = pop_front(&d);

    EXPECT_EQ(value, 10);
    EXPECT_EQ(d.head, 1);
}

TEST(DequeTest, PopBack) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);
    push_back(&d, 30);

    int value = pop_back(&d);

    EXPECT_EQ(value, 30);
    EXPECT_EQ(d.tail, 2);
}

TEST(DequeTest, PrintDeque) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);
    push_back(&d, 30);

    testing::internal::CaptureStdout();
    printDeque(&d);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 20 30 \n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}