#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
	char field;
	int freq;
	Node* left;
	Node* right;
};
Node* getNode(char field, int freq, Node* left, Node* right);
struct compare
{
	bool operator()(Node* l, Node* r)
	{
		return l->freq > r->freq;
	}
};
Node* BuildTree(string text, unordered_map<char, string>& BTable);
string EncodeText(string text, unordered_map<char, string>& BTable);
string DecodeText(string encodedText, Node* root);
