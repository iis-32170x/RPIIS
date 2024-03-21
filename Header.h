#pragma once
#include <iostream>
using namespace std;

const int max_elementov = 100;

struct Deque {
    int head, tail;
    int x[max_elementov];
};

void push_front(Deque* d, int value) {
    d->head = (d->head + (max_elementov - 1)) % max_elementov;
    d->x[d->head] = value;
}

void push_back(Deque* d, int value) {

    d->x[d->tail] = value;
    d->tail = (d->tail + 1) % max_elementov;
}

int pop_front(Deque* d) {
    int value = d->x[d->head];
    d->head = (d->head + 1) % max_elementov;
    return value;
}

int pop_back(Deque* d) {
    d->tail = (d->tail + (max_elementov - 1)) % max_elementov;
    int value = d->x[d->tail];
    return value;
}

void printDeque(Deque* d) {
    int i = d->head;
    while (i != d->tail) {
        cout << d->x[i] << " ";
        i = (i + 1) % max_elementov;
    }
    cout << endl;
}