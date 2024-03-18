
#ifndef PCH_H
#define PCH_H
#include <iomanip>
#include <iostream>

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;
   
        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    Node* insertNode(Node* node, int key);
    Node* removeNode(Node* node, int key);
    Node* findMinNode(Node* node);
    Node* findMaxNode(Node* node);
    Node* findClosestGreaterNode(Node* node, int key);
    Node* findClosestSmallerNode(Node* node, int key);
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);
    void updateHeight(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* balance(Node* node);
    
public:
    AVLTree();
    ~AVLTree();
    void clear(Node* node);
    void insert(int key);
    bool remove(int key);
    bool search(int key);
    int findMin();
    int findMax();
    int findClosestGreater(int key);
    int findClosestSmaller(int key);
    void print(); // Добавленная функция print
    void print_n(const Node* p, int n, int level, int prob);
};

#endif // PCH_H