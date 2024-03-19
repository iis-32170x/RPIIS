#ifndef PCH_H
#define PCH_H
#include <iomanip>
#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int key);
int getHeight(Node* node);
int getBalanceFactor(Node* node);
void updateHeight(Node* node);
Node* rotateRight(Node* node);
Node* rotateLeft(Node* node);
Node* balance(Node* node);
Node* insertNode(Node* node, int key);
Node* removeNode(Node* node, int key);
Node* findMinNode(Node* node);
Node* findMaxNode(Node* node);
Node* findClosestGreaterNode(Node* node, int key);
Node* findClosestSmallerNode(Node* node, int key);
void clear(Node* node);
void insert(Node** root, int key);
bool remove(Node** root, int key);
bool search(Node* root, int key);
int findMin(Node* root);
int findMax(Node* root);
int findClosestGreater(Node* root, int key);
int findClosestSmaller(Node* root, int key);
void print_n(const Node* p, int n, int level, int prob);
void print(Node* root);

#endif 
