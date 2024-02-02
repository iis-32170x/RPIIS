#include "pch.h"
#include <gtest/gtest.h>
#include "../priorityQueue/priorityQueue.h"
using namespace std;

//базовый тест на вставку и извлечение
TEST(PriorityQueueTest, InsertAndExtract1) {
    priorityQueue pq;

    EXPECT_TRUE(pq.isEmpty());

    pq.insert(10);
    pq.insert(5);
    pq.insert(20);

    EXPECT_FALSE(pq.isEmpty());

    EXPECT_EQ(pq.extract(), 20);
    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), 5);

    EXPECT_TRUE(pq.isEmpty());
}

//базовый тест на вставку и извлечение
TEST(PriorityQueueTest, InsertAndExtract2) {
    priorityQueue pq;

    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(15);
    pq.insert(25);

    EXPECT_EQ(pq.extract(), 25);
    EXPECT_EQ(pq.extract(), 20);
    EXPECT_EQ(pq.extract(), 15);
    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), 5);

    EXPECT_TRUE(pq.isEmpty());
}

//тест на вставку и извлечение с одинаковыми элементами
TEST(PriorityQueueTest, InsertAndExtractWithDuplicates) {
    priorityQueue pq;
    pq.insert(10);
    pq.insert(5);
    pq.insert(10);
    pq.insert(8);

    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), 8);
    EXPECT_EQ(pq.extract(), 5);
    EXPECT_TRUE(pq.isEmpty());
}

//тест на извлечение из пустой очереди
TEST(PriorityQueueTest, ExtractFromEmptyQueue) {
    priorityQueue pq;

    EXPECT_THROW(pq.extract(), std::out_of_range);
}

//тест на вставку и извлечение с отрицательными элементами
TEST(PriorityQueueTest, InsertWithNegativeNumbers) {
    priorityQueue pq;

    pq.insert(10);
    pq.insert(-5);
    pq.insert(25);
    pq.insert(-10);
    pq.insert(-2);

    EXPECT_EQ(pq.extract(), 25);
    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), -2);
    EXPECT_EQ(pq.extract(), -5);
    EXPECT_EQ(pq.extract(), -10);
    EXPECT_TRUE(pq.isEmpty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}