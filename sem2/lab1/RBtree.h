#pragma once
#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* parent;
	Node* left;
	Node* right;
	bool Red;
};

void InsertNode(Node*& root, int value);
void InsertFix(Node* node, Node*& root);
void DeleteNode(Node*& root, int value);
void Delete(Node*& root, Node* node);
void ClearNode(Node* node);
void Print(Node* root);
void LeftRotate(Node*& root, int value);
void RightRotate(Node*& root, int value);
Node* Find(Node* root, int value);
int FindMax(Node* root);
int FindMin(Node* root);
int FindNearestMin(Node* node, int value);
int FindNearestMax(Node* node, int value);