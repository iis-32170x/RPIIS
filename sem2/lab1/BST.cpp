#include <iostream>
#include <cstdlib>

#include "header.h"

using namespace std;

BST::BST() 
{
	root = nullptr;
}

BST::Node* BST::CreateLeaf(int key) 
{
	Node* n = new Node;
	n->key = key;
	n->left = nullptr;
	n->right = nullptr;
	
	return n;
}

void BST::AddLeaf(int key) 
{
	AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, Node* Ptr)
{
	if (root == nullptr)
	{
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != nullptr)
		{
			AddLeafPrivate(key, Ptr->left);
		}
		else
		{
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != nullptr)
		{
			AddLeafPrivate(key, Ptr->right);
		}
		else
		{
			Ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		cout << "You was trying to create a node with a key \"" << key << "\". Oooops, the node with this key already exists.\n";
	}
}

void BST::PrintInOrder() 
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(Node* Ptr)
{
	if (root != nullptr)
	{
		if (Ptr->left != nullptr)
		{
			PrintInOrderPrivate(Ptr->left);
		}

		cout << Ptr->key << "\t";

		if (Ptr->right != nullptr)
		{
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty.\n";
	}
}

BST::Node* BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}

BST::Node* BST::ReturnNodePrivate(int key, Node* Ptr)
{
	if (Ptr != nullptr)
	{
		if (Ptr->key == key)
		{
			return Ptr;
		}
		else
		{
			if (key < Ptr->key)
			{
				return ReturnNodePrivate(key, Ptr->left);
			}
			if (key > Ptr->key)
			{
				return ReturnNodePrivate(key, Ptr->right);
			}
		}
	}
	else
	{
		return nullptr;
	}
}

void BST::PrintChildren(int key) 
{
	Node* Ptr = ReturnNode(key);

	if (Ptr != nullptr)
	{
		cout << "Parent Node = " << Ptr->key << endl;

		Ptr->left == nullptr ?
			cout << "Left Child = NULL\n" :
			cout << "Left Child = " << Ptr->left->key << "\n";

		Ptr->right == nullptr ?
			cout << "Right Child = NULL\n" :
			cout << "Right Child = " << Ptr->right->key << "\n";
	}
	else
	{
		cout << "Key " << key << " is not in the tree.\n";
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
};

int BST::FindSmallestPrivate(Node* Ptr) 
{
	if (Ptr == nullptr)
	{
		cout << "The tree is empty." << "\n";
		return -1000;
	}
	else
	{
		if (Ptr->left != nullptr)
		{
			return FindSmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}
};

void BST::Remove(Node* parent, Node* match, bool left)
{
	Node* delPtr;
	int matchKey = match->key;
	int smallestRightSubtree;

	//case 0
	if (match->left == nullptr && match->right == nullptr)
	{
		delPtr = match;
		left == true ? parent->left = nullptr : parent->right = nullptr;
		delete delPtr;
		cout << "The node with key \"" << matchKey << "\"  was removed.\n";
	}

	//case 1
	else if (match->left == nullptr && match->right != nullptr)
	{
		left == true ? parent->left = match->right : parent->right = match->right;
		match->right = nullptr;
		delPtr = match;
		delete delPtr;
		cout << "The node with key \"" << matchKey << "\"  was removed.\n";
	}

	//case 1
	else if (match->left != nullptr && match->right == nullptr)
	{
		left == true ? parent->left = match->left : parent->right = match->left;
		match->left = nullptr;
		delPtr = match;
		delete delPtr;
		cout << "The node with key \"" << matchKey << "\"  was removed.\n";
	}

	//case 2
	else
	{
		smallestRightSubtree = FindSmallestPrivate(match->right);
		RemoveNodePrivate(smallestRightSubtree, match);
		match->key = smallestRightSubtree;

	}

}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, Node* parent)
{
	if (root != nullptr)
	{
		if(root->key == key)
		{
			RemoveRoot();
		}
		else 
		{
			if (key < parent->key && parent->left != nullptr)
			{
				parent->left->key == key ?
					Remove(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != nullptr)
			{
				parent->right->key == key ?
					Remove(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else
			{
				cout << "The key " << key << " was not found in the tree.\n";
			}
		}

	}
	else
	{
		cout << "The tree is empty." << "\n";
	}
}

void BST::RemoveRoot()
{
	Node* delPtr = root;
	int rootKey = root->key;
	int smallestRightSubtree;

	//case 0
	if (root->left == nullptr && root->right == nullptr)
	{
		root = nullptr;
		delete delPtr;
	}
	//case 1
	else if (root->left == nullptr && root->right != nullptr)
	{
		root = root->right;
		delPtr->right = nullptr;
		delete delPtr;
		cout << "The root node with key " << rootKey << " was deleted." <<
			"The new root contais key: " << root->key << "\n";
	}
	//case 1
	else if (root->left != nullptr && root->right == nullptr)
	{
		root = root->left;
		delPtr->left = nullptr;
		delete delPtr;
		cout << "The root node with key " << rootKey << " was deleted." <<
			"The new root contais key: " << root->key << "\n";
	}
	//case 2
	else
	{
		smallestRightSubtree = FindSmallestPrivate(root->right);
		RemoveNodePrivate(smallestRightSubtree, root);
		root->key = smallestRightSubtree;
		cout << "The root key containg key: " << rootKey <<
			" was ovewritting with key: " << root->key << "\n";
	}
};

BST::~BST()
{
	RemoveSubTree(root);
}

void BST::RemoveSubTree(Node* Ptr)
{
	if (Ptr != nullptr)
	{
		if (Ptr->left != nullptr)
		{
			RemoveSubTree(Ptr->left);
		}

		if (Ptr->right != nullptr)
		{
			RemoveSubTree(Ptr->right);
		}

		cout << "Node " << Ptr->key << " was deleted." << endl;
		delete Ptr;
	}
}