#include "Tree.h"

int main() {
	
	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	QuadTree* root = NULL;
	int size = matrix.size();
	root = root-> TakeFromArray(matrix, 0, 0, size);
	cout << "QuadTree: " << endl;
	root->ViewTree(root, 0);
	cout << endl;
	vector<vector<int>> matrix1(4, vector<int>(4, 0));
	cout << "Martix from QuadTree: " << endl;
	root->TakeFromTree(root, matrix1, 0, 0, 4);

	for (int i = 0; i < matrix1.size(); i++) {
		for (int j = 0; j < matrix1[i].size(); j++) {
			cout << matrix1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if (matrix[i][j] == matrix1[i][j]) {
				cout << "correct convertation" << endl;
			}
			else {
				cout << "fail" << endl;
			}
		}
	}
}