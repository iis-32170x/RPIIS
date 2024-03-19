#include <iomanip>
#include <iostream>
#include "pch.h"
using namespace std;

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

Node* rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

Node* balance(Node* node) {
    updateHeight(node);

    if (getBalanceFactor(node) == 2) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    if (getBalanceFactor(node) == -2) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

Node* insertNode(Node* node, int key) {
    if (node == nullptr) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }
    else {
        return node;
    }

    return balance(node);
}

void insert(Node** root, int key) {
    *root = insertNode(*root, key);
}

bool search(Node* root, int key) {
    Node* current = root;

    while (current != nullptr) {
        if (key == current->key) {
            return true;
        }
        else if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return false;
}

Node* removeNode(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = removeNode(node->right, key);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
                delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* minRight = findMinNode(node->right);
            node->key = minRight->key;
            node->right = removeNode(node->right, minRight->key);
        }
    }

    return balance(node);
}

bool remove(Node** root, int key) {
    if (*root == nullptr) {
        return false;
    }

    bool keyExists = search(*root, key);

    if (keyExists) {
        *root = removeNode(*root, key);
    }

    return keyExists;
}

Node* findMinNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

int findMin(Node* root) {
    if (root == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    Node* minNode = findMinNode(root);
    return minNode->key;
}

Node* findMaxNode(Node* node) {
    Node* current = node;

    while (current->right != nullptr) {
        current = current->right;
    }

    return current;
}

int findMax(Node* root) {
    if (root == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    Node* maxNode = findMaxNode(root);
    return maxNode->key;
}

Node* findClosestGreaterNode(Node* node, int key) {
    Node* closestGreater = nullptr;
    Node* current = node;

    while (current != nullptr) {
        if (current->key > key) {
            closestGreater = current;
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return closestGreater;
}

int findClosestGreater(Node* root, int key) {
    Node* closestGreaterNode = findClosestGreaterNode(root, key);

    if (closestGreaterNode == nullptr) {
        throw std::runtime_error("No greater key found");
    }

    return closestGreaterNode->key;
}

Node* findClosestSmallerNode(Node* node, int key) {
    Node* closestSmaller = nullptr;
    Node* current = node;

    while (current != nullptr) {
        if (current->key < key) {
            closestSmaller = current;
            current = current->right;
        }
        else {
            current = current->left;
        }
    }

    return closestSmaller;
}

int findClosestSmaller(Node* root, int key) {
    Node* closestSmallerNode = findClosestSmallerNode(root, key);

    if (closestSmallerNode == nullptr) {
        throw std::runtime_error("No smaller key found");
    }

    return closestSmallerNode->key;
}

void clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
}

void print_n(const Node* p, int n, int level, int prob) {
    if (p) {
        if (level == n){
            for (int i = 0; i <= prob; i++)
                cout << " ";
            cout << p->key;
            }
        else
        {
            print_n(p->left, n, level + 1, prob);
            print_n(p->right, n, level + 1, prob);
        }
    }
}

void print(Node* p) {
    int h = getHeight(p);
    int prob = 3;
    if (p)
    {
        for (int i = 0; i <= h; i++) 
        {
            print_n(p, i, 0, prob * (h - i)); 
            cout << endl;
        }
    }
}
