#include "../pioivislab/queue.h"
#include "pch.h"

// Тестирование функции enqueue
TEST(EnqueueTest, EnqueueElement) {
    Node* front = nullptr;
    Node* rear = nullptr;
    enqueue(front, rear, "Element 1");

    ASSERT_EQ(front->data, "Element 1");
    ASSERT_EQ(rear->data, "Element 1");
}

// Тестирование функции dequeue
TEST(DequeueTest, DequeueElement) {
    Node* front = nullptr;
    Node* rear = nullptr;
    enqueue(front, rear, "Element 1");
    enqueue(front, rear, "Element 2");

    string value = dequeue(front, rear);

    ASSERT_EQ(value, "Element 1");
    ASSERT_EQ(front->data, "Element 2");
}

// Тестирование функции isEmpty
TEST(IsEmptyTest, CheckEmptyQueue) {
    Node* front = nullptr;
    Node* rear = nullptr;

    ASSERT_TRUE(isEmpty(front));

    enqueue(front, rear, "Element 1");

    ASSERT_FALSE(isEmpty(front));
}

// Тестирование функции clearQueue
TEST(ClearQueueTest, ClearQueue) {
    Node* front = nullptr;
    Node* rear = nullptr;
    enqueue(front, rear, "Element 1");
    enqueue(front, rear, "Element 2");

    clearQueue(front, rear);

    ASSERT_TRUE(isEmpty(front));
    ASSERT_TRUE(isEmpty(rear));
}

int main(int argc, char** argv) {
    setlocale(0, "");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
