#ifndef TREAP_H
#define TREAP_H

#include <vector>
#include <utility>
#include <random>
#include <iostream>
#include <queue>
#include <iomanip>

class Node {
public:
    int key;
    int priority;
    Node* left;
    Node* right;
    bool rev;
    Node(int _key)
    {
        key = _key;
        srand((_key * 4 + 234) % 20 + 23);
        priority = rand() % 21;
        if (priority < 0) priority *= -1;
    }
    Node(int _key, int _priority)
    {
        key = _key;
        priority = _priority;
    }
};

class Treap {
private:
    void swap(Node*& a, Node*& b);
    void split(Node* p, int x, Node*& f, Node*& s);
    Node* merge(Node* l, Node* r);
    bool InTree(Node* node, int key);
public:
    Node* root = nullptr;
    void insert(int x);
    void insert(int x,int y);
    void erase(Node*& t, int k);
    void buildTree(std::vector<int> keys);
    void buildTree(std::vector<int> keys, std::vector<int> prioritys);
    void outTree(Node* node,int);
    Node* search(Node*, int);
    Node* unite(Node* l, Node* r);
    Node* intersect(Node* root1, Node* root2);
};
#endif
