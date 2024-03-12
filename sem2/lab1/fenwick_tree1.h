#pragma once

#ifndef FENWICK_TREE1_HPP
#define FENWICK_TREE1_HPP
#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
	vector<int> arr;
	vector<int> tree;
	FenwickTree(int size);
	void update(int idx, int value);
	void updateArr(int idx, int newValue);
	int sum(int x);
	int sum(int l, int r);


};

#endif
