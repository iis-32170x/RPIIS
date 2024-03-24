#pragma once
#include <iostream>

namespace N
{
	struct Node {
		int data;
		Node* left;
		Node* right;
		Node* par;

		Node(int val);
	};
	class bst {
	private:
		Node* root;
		Node* search(Node*, int val);
		Node* Insert(Node* node, int val);
		void bypass(Node*);
		Node* Remove(Node* node, int val);
		Node* min(Node* node);
	public:
		bool search(int val);
		void Insert(int val);
		void bypass();
		void Remove(int val);
		Node* CreateBSTarr(int arr[], int start, int end);

	};

}