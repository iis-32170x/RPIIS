#pragma once
#include <stdexcept>
#include <vector>

class Queue {
public:
    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    int front() const;
    int size() const;
    void clear() ;

private:
    std::vector<int> queue;
    size_t frontIndex = 0;
};
