#include "queue.h"

void Queue::enqueue(int value) {
    queue.push_back(value);
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    int value = queue[frontIndex];
    frontIndex++;
    return value;
}

bool Queue::isEmpty() const {
    return frontIndex >= queue.size();
}

int Queue::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    return queue[frontIndex];
}

int Queue::size() const {
    return queue.size() - frontIndex;
}

void Queue::clear() {
    frontIndex = 0;
    queue.clear();
}