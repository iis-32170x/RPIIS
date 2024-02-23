```#include "pch.h"
#include "D:\БГУИР\Пиво\sem2\PriorityQueue\PriorityQueue.h"

TEST(PriorityQueueTest, PushAndPopTest) {
    PriorityQueue<int> q;
    q.push(1, 10); // Добавляем элемент с приоритетом
    EXPECT_EQ(q.pop(), 1); // Проверяем, что верхний элемент - это добавленный элемент
}

TEST(PriorityQueueTest, EmptyTest) {
    PriorityQueue<int> q;
    EXPECT_TRUE(q.empty()); // Проверяем, что очередь пуста
    q.push(1, 10); // Добавляем элемент
    EXPECT_FALSE(q.empty()); // Проверяем, что очередь не пуста
}

TEST(PriorityQueueTest, PopFromEmptyQueueTest) {
    PriorityQueue<int> q;
    EXPECT_THROW(q.pop(), std::runtime_error); // Проверяем, что выбрасывается исключение при попытке извлечь элемент из пустой очереди
}

TEST(PriorityQueueTest, ReadFromNotExistingFileTest) {
    PriorityQueue<int> q;
    EXPECT_THROW(q.readFromFile("notexisting.txt"), std::runtime_error); 
}

TEST(PriorityQueueTest, ReadFromEmptyFileTest) {
    PriorityQueue<int> q;
    q.readFromFile("empty.txt"); 
    EXPECT_TRUE(q.empty());
}

TEST(PriorityQueueTest, ReadFromFileTest) {
    PriorityQueue<int> q;
    q.readFromFile("1.txt"); 
    EXPECT_EQ(q.pop(), 15);
    EXPECT_EQ(q.pop(), 789);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_THROW(q.pop(), std::runtime_error);
}

TEST(PriorityQueueTest, ReadCharFromFileTest) {
    PriorityQueue<char> q;
    q.readFromFile("2.txt"); 
    EXPECT_EQ(q.pop(), 'a');
    EXPECT_EQ(q.pop(), 'b');
    EXPECT_EQ(q.pop(), 'c');
    EXPECT_EQ(q.pop(), 'd');
    EXPECT_THROW(q.pop(), std::runtime_error);
}

TEST(PriorityQueueTest, ReadIliaFromFileTest) {
    PriorityQueue<int> q;
    q.readFromFile("3.txt"); 
    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.pop(), 5);
    EXPECT_EQ(q.pop(), 9);
    EXPECT_THROW(q.pop(), std::runtime_error);
}

TEST(PriorityQueueTest, ReadCharIliaFromFileTest) {
    PriorityQueue<char> q;
    q.readFromFile("4.txt"); 
    EXPECT_EQ(q.pop(), '&');
    EXPECT_EQ(q.pop(), '!');
    EXPECT_EQ(q.pop(), '/');
    EXPECT_EQ(q.pop(), '*');
    EXPECT_EQ(q.pop(), '|');
    EXPECT_THROW(q.pop(), std::runtime_error);
}

TEST(PriorityQueueTest, ReadCharYubileyFromFileTest) {
    PriorityQueue<char> q;
    q.readFromFile("5.txt");
    EXPECT_EQ(q.pop(), 'b');
    EXPECT_EQ(q.pop(), 'y');
    EXPECT_EQ(q.pop(), 'b');
    EXPECT_THROW(q.pop(), std::runtime_error);
}

TEST(PriorityQueueTest, StringPushAndPopTest) {
    PriorityQueue<std::string> q;
    q.push("apple", 10); 
    EXPECT_EQ(q.pop(), "apple");
}

TEST(PriorityQueueTest, ReadStringFromFileTest) {
    PriorityQueue<std::string> q;
    q.readFromFile("12.txt"); 
    EXPECT_EQ(q.pop(), "asg");
    EXPECT_EQ(q.pop(), "wer");
    EXPECT_EQ(q.pop(), "ervg");
    EXPECT_THROW(q.pop(), std::runtime_error);
}

```