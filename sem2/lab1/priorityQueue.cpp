#include "priorityQueue.h"
#include <algorithm>


void priorityQueue::insert(int value) {
    a.push_back(value);
    up(a.size() - 1);
}

int priorityQueue::extract() {
    if (isEmpty()) {
        throw std::out_of_range("Priority queue is empty");
    }

    int value = a[0];
    a[0] = a[a.size() - 1];
    a.pop_back();
    down(0);
    return value;
}

void priorityQueue::up(int i) {
    while (a[i] > a[(i - 1) / 2] && i != 0) {
        std::swap(a[(i - 1) / 2], a[i]);
        i = (i - 1) / 2;
    }
}

void priorityQueue::down(int i) {
    while (2 * i + 1 < a.size()) {
        int maxChild = 2 * i + 1;
        if (maxChild + 1 < a.size() && a[maxChild] < a[maxChild + 1]) {
            maxChild++;
        }
        if (a[i] >= a[maxChild]) {
            break;
        }
        std::swap(a[maxChild], a[i]);
        i = maxChild;
    }
}

bool priorityQueue::isEmpty() const {
    return a.empty();
}
