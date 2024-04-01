#include "queue.h"
#include<iostream>
#include<string>

using namespace std;

void enqueue(Node*& front, Node*& rear, const string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Элемент '" << value << "' добавлен в очередь." << endl;
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        cout << "Очередь пуста." << endl;
        return "";
    }

    string value = front->data;

    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;

    return value;
}

bool isEmpty(Node* front) {
    return front == nullptr;
}

void clearQueue(Node*& front, Node*& rear) {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    rear = nullptr;

    cout << "Очередь очищена." << endl;
}

void printQueue(Node* front) {
    if (isEmpty(front)) {
        cout << "Очередь пуста." << endl;
        return;
    }

    cout << "Содержимое очереди: ";

    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
