#ifndef FENWICK_TREE_HPP
#define FENWICK_TREE_HPP

#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	vector<int> arr;
	FenwickTree(int size);
	void update(int idx, int value);
	void updateArr(int idx, int newValue);
	int sum(int x);
	int sum(int l, int r);


}

int main() {
	vector<int> arr;
}

#endif

