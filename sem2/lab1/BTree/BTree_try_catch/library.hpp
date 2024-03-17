#include <sstream>
#include <queue>
#include <iostream>

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

using namespace std;

class BTreeNode
{
	int* keys; 
	int t;	
	BTreeNode** C;
	int n;	
	bool leaf; 

public:

	BTreeNode(int _t, bool _leaf); 

	BTreeNode* search_key(int k);

	int findKey(int k);

	void insertNonFull(int k);

	void splitChild(int i, BTreeNode* y);

	void delete_key(int k);

	void delete_from_leaf(int idx);

	void delete_from_nonleaf(int idx);

	int getPred(int idx);

	int getSucc(int idx);

	void fill(int idx);

	void borrowFromPrev(int idx);

	void borrowFromNext(int idx);

	void merge(int idx);

	~BTreeNode();

	friend class BTree;
	friend class PrettyPrint;
};

class BTree
{
	BTreeNode* root; 
	int t; 
public:

	BTree(int _t)
	{
		root = NULL;
		t = _t;
	}

	BTreeNode* search_key(int k)
	{
		return (root == NULL) ? NULL : root->search_key(k);
	}

	void insert_key(int k);

	void delete_key(int k);

	~BTree();

	friend class PrettyPrint;
};

class PrettyPrint
{
	struct NodeInfo
	{
		string text; 
		unsigned text_pos, text_end;
	};

	typedef vector<NodeInfo> LevelInfo;

	vector<LevelInfo> levels;

	string node_text(int const keys[], unsigned key_count);

	void before_traversal()
	{
		levels.resize(0);
		levels.reserve(10);
	}

	void visit(BTreeNode const* node, unsigned level = 0, unsigned child_index = 0);

	void after_traversal();

public:

	void print(BTree const& tree)
	{
		before_traversal();
		visit(tree.root);
		after_traversal();
	}
};

void BTree_try_catch();

#endif