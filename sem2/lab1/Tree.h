#pragma once
#include <vector>
#include <iostream>

using namespace std;
 

struct QuadTree {
	int data;
	QuadTree* root;
	QuadTree* first = nullptr;
	QuadTree* second = nullptr;
	QuadTree* third = nullptr;
	QuadTree* fourth = nullptr;
	void ViewTreeHelper(int level);
	void ViewTree();
    QuadTree* TakeFromMatrix(const vector<vector<int>>& matrix, int row, int col, int size);
	QuadTree* TakeFromMatrix(const vector<vector<int>>& matrix);
	void TakeFromTree(QuadTree* root, vector<vector<int>>& matrix, int row, int col, int size);
	vector<vector<int>> TakeFromTree1(const vector<vector<int>>& matrix);
};