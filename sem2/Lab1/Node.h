#pragma once
#include <iostream>
#include <vector>
class Node
{
public:
	std::vector<Node*> front_ptrs = { nullptr };
	Node* back_ptr;
	char c;
	int num = 0;
	bool is_root = false;
	bool end = false;
	Node();
	Node(char c);
	Node(Node* p);
};