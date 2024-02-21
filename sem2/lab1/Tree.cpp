#include "Tree.h"

void QuadTree::ViewTreeHelper(int level) {
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << data << endl;
    if (first) {
        first->ViewTreeHelper(level + 1);
    }
    if (second) {
        second->ViewTreeHelper(level + 1);
    }
    if (third) {
        third->ViewTreeHelper(level + 1);
    }
    if (fourth) {
        fourth->ViewTreeHelper(level + 1);
    }
}

void QuadTree::ViewTree() {
    ViewTreeHelper(0);
}





QuadTree* QuadTree::TakeFromMatrix(const vector<vector<int>>& matrix, int row, int col, int size) {
    if (matrix.size() != 4) {
        cout << "Invalid matrix size" << endl;
        exit(1);
    }
    if (size == 1) {
        QuadTree* node = new QuadTree;
        node->data = matrix[row][col];
        return node;
    }

    int newSize = size / 2;

    int firstData = matrix[row][col];
    bool flag = true; 

    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (matrix[i][j] != firstData) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        QuadTree* node = new QuadTree;
        node->data = firstData;
        return node;
    }

    QuadTree* root = new QuadTree;
    root->data = 0;

    root->first = TakeFromMatrix(matrix, row, col, newSize);
    root->second = TakeFromMatrix(matrix, row, col + newSize, newSize);
    root->third = TakeFromMatrix(matrix, row + newSize, col, newSize);
    root->fourth = TakeFromMatrix(matrix, row + newSize, col + newSize, newSize);

    return root;
}

QuadTree* QuadTree::TakeFromMatrix(const vector<vector<int>>& matrix) {
    return TakeFromMatrix(matrix, 0, 0, matrix.size());
}



void QuadTree::TakeFromTree1(QuadTree* root, vector<vector<int>>& matrix, int row, int col, int size) {
    if (root) {
        if (root->first == nullptr) { // Проверка, что узел является листовым
            if (row >= matrix.size() || col >= matrix[0].size()) {
                cerr << "Invalid row or col position" << endl;
                exit(1);
            }

            for (int i = row; i < row + size; i++) {
                for (int j = col; j < col + size; j++) {
                    matrix[i][j] = root->data; 
                }
            }

            return;
        }

        int newSize = size / 2;

        TakeFromTree1(root->first, matrix, row, col, newSize);
        TakeFromTree1(root->second, matrix, row, col + newSize, newSize);
        TakeFromTree1(root->third, matrix, row + newSize, col, newSize);
        TakeFromTree1(root->fourth, matrix, row + newSize, col + newSize, newSize);
    }
}

vector<vector<int>> QuadTree::TakeFromTree(const vector<vector<int>>& matrix) {
    int size = matrix.size();
    vector<vector<int>> result(size, vector<int>(size, 0));

    TakeFromTree1(this, result, 0, 0, size);

    return result;
}


