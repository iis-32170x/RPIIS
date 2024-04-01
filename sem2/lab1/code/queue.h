#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, const string& value);
string dequeue(Node*& front, Node*& rear);
bool isEmpty(Node* front);
void clearQueue(Node*& front, Node*& rear);
void printQueue(Node* front);

#endif
