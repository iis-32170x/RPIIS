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
	void ViewTree(QuadTree* root, int level);
	QuadTree* Add_data(QuadTree* root, int data);
	QuadTree* TakeFromArray(const vector<vector<int>>& arr, int row, int col, int size);
	void TakeFromTree(QuadTree* root, vector<vector<int>>& matrix, int row, int col, int size);

};

