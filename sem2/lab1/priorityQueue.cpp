#include "priorityQueue.h"
#include <algorithm>


void PriorityQueue::insert(int value) {
    vect.push_back(value);
    up(vect.size() - 1);
}

int PriorityQueue::extract() {
    if (isEmpty()) {
        throw std::out_of_range("Priority queue is empty");
    }

    int value = vect[0];
    vect[0] = vect[vect.size() - 1];
    vect.pop_back();
    down(0);
    return value;
}

void PriorityQueue::up(int i) {
    while (vect[i] > vect[(i - 1) / 2] && i != 0) {
        std::swap(vect[(i - 1) / 2], vect[i]);
        i = (i - 1) / 2;
    }
}

void PriorityQueue::down(int i) {
    while (2 * i + 1 < vect.size()) {
        int maxChild = 2 * i + 1;
        if (maxChild + 1 < vect.size() && vect[maxChild] < vect[maxChild + 1]) {
            maxChild++;
        }
        if (vect[i] >= vect[maxChild]) {
            break;
        }
        std::swap(vect[maxChild], vect[i]);
        i = maxChild;
    }
}

bool PriorityQueue::isEmpty() const {
    return vect.empty();
}