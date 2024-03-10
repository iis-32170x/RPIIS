#include "pch.h"
#include <gtest/gtest.h>
#include "../priorityQueue/priorityQueue.h"
using namespace std;


TEST(PriorityQueueTest, InsertAndExtract1) {
    PriorityQueue queue;

    EXPECT_TRUE(queue.isEmpty());

    queue.insert(10);
    queue.insert(5);
    queue.insert(15);
    queue.insert(2);

    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.extract(), 15);
    EXPECT_EQ(queue.extract(), 10);
    EXPECT_EQ(queue.extract(), 5);
    EXPECT_EQ(queue.extract(), 2);
    EXPECT_TRUE(queue.isEmpty());
}


TEST(PriorityQueueTest, InsertAndExtract2) {
    PriorityQueue queue;

    queue.insert(10);
    queue.insert(5);
    queue.insert(20);
    queue.insert(15);
    queue.insert(25);
    queue.insert(35);
    queue.insert(17);

    EXPECT_EQ(queue.extract(), 35);
    EXPECT_EQ(queue.extract(), 25);
    EXPECT_EQ(queue.extract(), 20);
    EXPECT_EQ(queue.extract(), 17);
    EXPECT_EQ(queue.extract(), 15);
    EXPECT_EQ(queue.extract(), 10);
    EXPECT_EQ(queue.extract(), 5);

    EXPECT_TRUE(queue.isEmpty());
}


TEST(PriorityQueueTest, InsertAndExtractWithDuplicates) {
    PriorityQueue queue;
    queue.insert(10);
    queue.insert(6);
    queue.insert(5);
    queue.insert(10);
    queue.insert(6);

    EXPECT_EQ(queue.extract(), 10);
    EXPECT_EQ(queue.extract(), 10);
    EXPECT_EQ(queue.extract(), 6);
    EXPECT_EQ(queue.extract(), 6);
    EXPECT_EQ(queue.extract(), 5);
    EXPECT_TRUE(queue.isEmpty());
}

TEST(PriorityQueueTest, ExtractFromEmptyQueue) {
    PriorityQueue queue;

    EXPECT_THROW(queue.extract(), std::out_of_range);
}


TEST(PriorityQueueTest, InsertWithNegativeNumbers) {
    PriorityQueue queue;

    queue.insert(-34);
    queue.insert(10);
    queue.insert(-5);
    queue.insert(25);
    queue.insert(-7);
    queue.insert(-2);

    EXPECT_EQ(queue.extract(), 25);
    EXPECT_EQ(queue.extract(), 10);
    EXPECT_EQ(queue.extract(), -2);
    EXPECT_EQ(queue.extract(), -5);
    EXPECT_EQ(queue.extract(), -7);
    EXPECT_EQ(queue.extract(), -34);
    EXPECT_TRUE(queue.isEmpty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}