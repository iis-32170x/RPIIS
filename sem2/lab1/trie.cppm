#include <iostream>
#include <vector>
using namespace std;

export module trie;



struct node {
	char key;
	vector<node*>children;

	node() { key = NULL; children = {}; }

};// íå äîñòóïíàÿ ïîëüçîâàòåëþ ñòðóêòóðà




export class trie {
private:
	//
	node* root;
	node* current;
	//

	bool go_to_search(string str, int counter, bool is_here) {
		if (counter == str.size()) { return true; }
		is_here = false;
		for (auto n : current->children) {
			if (n->key == str[counter]) { is_here = true; current = n; }
		}
		if (is_here == false) { return false; }
		else {
			counter++;
			return go_to_search(str, counter, is_here);
		}

	}

	void go_to_insert(const string str, int counter, bool is_here) {
		if (counter == str.size()) { return; }
		is_here = false;
		for (auto n : current->children) {
			if (n->key == str[counter]) { is_here = true; current = n; }
		}
		if (is_here == false) {
			node* n = new node; n->key = str[counter];
			current->children.push_back(n);
			current = n;
		}
		counter++;
		go_to_insert(str, counter, is_here);
	}

	void go_to_remove_by_prefix(node* start) {

		for (auto n : start->children) {
			go_to_remove_by_prefix(n);
		}
		delete start;

	}
public:
	//êîíñòðóêòîð ïî óìîë÷àíèþ
	trie() { root = new node; current = root; }


	void insert(const string str) {//for user
		current = root;
		int counter = 0;
		bool is_here = false;
		go_to_insert(str, counter, is_here);

	}


	bool search(const string str) {//for user
		current = root;
		int counter = 0;
		bool is_here = false;
		bool answer = go_to_search(str, counter, is_here);
		return answer;
	}

	void remove_by_prefix(const string str) {//for user
		if (search(str) == false) {
			cout << "Òàêîãî íå ïðåôèêñà íåò" << endl; return;
		}

		current = root;
		vector<node*>collection_for_remove = {};

		node* start = nullptr;
		for (auto n : current->children) {
			if (n->key = str[0]) { start = n; }
		}
		if (start != nullptr) {
			go_to_remove_by_prefix(start);
		}
	}

};
