#include "branch.h"
#include <iostream>

using namespace std;

void Add(Branch*& current, int value) {
    if (!current) {
        current = new Branch(value);
        return;
    }
    else if (value < current->data) {
        Add(current->left, value);
    }
    else if (value > current->data) {
        Add(current->right, value);
    }
}

Branch* findMinNode(Branch* node) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (node->left == nullptr) {
        return node;
    }
    else {
        return findMinNode(node->left);
    }
}

void removeNode(Branch*& current, int value) {
    if (current == nullptr) {
        return;
    }
    if (value < current->data) {
        removeNode(current->left, value);
    }
    else if (value > current->data) {
        removeNode(current->right, value);
    }
    else {
        if (current->left == nullptr) {
            Branch* temp = current;
            current = current->right;
            delete temp;
        }
        else if (current->right == nullptr) {
            Branch* temp = current;
            current = current->left;
            delete temp;
        }
        else {
            Branch* minRight = findMinNode(current->right);
            current->data = minRight->data;
            removeNode(current->right, minRight->data);
        }
    }
}

Branch* FindElem(Branch* node, int value) {
    if (!node) {
        cout << "Элемент не найден. ";
        return nullptr;
    }
    if (node->data == value) {
        cout << "Элемент найден. ";
        return node;
    }
    if (node->data < value) {
        return FindElem(node->right, value);
    }
    else {
        return FindElem(node->left, value);
    }
}

void print(Branch* node) {
    if (!node) {
        return;
    }
    print(node->left);
    std::cout << node->data << " ";
    print(node->right);
}

void UnionAdd(Branch*& current, Branch*& mnozhC) {
    if (!current) {
        return;
    }
    Add(mnozhC, current->data);
    UnionAdd(current->right, mnozhC);
    UnionAdd(current->left, mnozhC);
}

void Union(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
    if (mnozhA) {
        UnionAdd(mnozhA, mnozhC);
    }
    if (mnozhB) {
        UnionAdd(mnozhB, mnozhC);
    }
}

void proverka(int value, Branch* node, Branch*& mnozhC) {
    if (!node) {
        return;
    }
    if (node->data == value) {
        Add(mnozhC, value);
        return;
    }
    proverka(value, node->left, mnozhC);
    proverka(value, node->right, mnozhC);
}

void Intersection(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
    if (!mnozhA) {
        return;
    }
    proverka(mnozhA->data, mnozhB, mnozhC);
    Intersection(mnozhA->left, mnozhB, mnozhC);
    Intersection(mnozhA->right, mnozhB, mnozhC);
}
