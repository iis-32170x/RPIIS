#pragma once
#include <stdexcept>
#include <vector>

class PriorityQueue {
public:
    void insert(int value);
    int extract();
    bool isEmpty() const;

private:
    std::vector<int> vect;
    void up(int i);
    void down(int i);
};