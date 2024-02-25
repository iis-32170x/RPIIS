#pragma once
#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* parent;
	Node* left;
	Node* right;
	bool IsRed;
};

void insertNode(Node*& root, int key);
void insert_fix(Node* node, Node*& root);
void deleteNode(Node*& root, int key);
void del(Node*& root, Node* node);
void clearNode(Node* node);
void printInorder(Node* root);
void left_rotate(Node*& root, int key);
void right_rotate(Node*& root, int key);
Node* find(Node* root, int key);
int find_max(Node* root);
int find_min(Node* root);
int find_nearest_min(Node* node, int key);
int find_nearest_max(Node* node, int key);