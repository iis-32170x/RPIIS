#include "Tree.h"

int main() {	
	QuadTree* root = NULL;

	vector<vector<int>> matrix = {
		{1, 1, 98, 65},
		{1, 1, 15, 4},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	
	root = root->TakeFromMatrix(matrix);
	cout << "QuadTree: " << endl;
	root->ViewTree();
	cout << endl;
	cout << "Martix from QuadTree: " << endl;
	vector<vector<int>> matrix1 = root->TakeFromTree(matrix);
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