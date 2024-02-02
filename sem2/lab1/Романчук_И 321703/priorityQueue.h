#pragma once
#include <stdexcept>
#include <vector>

class priorityQueue {
public:
    void insert(int value);
    int extract();
    bool isEmpty() const;

private:
    std::vector<int> a;
    void up(int i);
    void down(int i);
};
