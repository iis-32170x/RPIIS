#pragma once

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};


Node* buildTree(int arr[], int start, int end);

Node* insertNode(Node* root, int key);

void printTree(Node* root);

Node* findMinNode(Node* root);

Node* deleteNode(Node* root, int key);

bool search(Node* root, int key);

void clearTree(Node* root);

void preOrderTraversal(Node* node);

void inOrderTraversal(Node* node);

void postOrderTraversal(Node* node);

