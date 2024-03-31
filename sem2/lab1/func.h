#pragma once

#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class node
{
public:
	int key;
	vector<node*> children;
};

node* create();

void add(node*& parent, int n);

void deleteNode(node* parent, node* nodeToDelete);

void find4del(node* parent);

void deleteTree(node*& parent);

void print(node* root, int depth);

void text(int n);

void work();
