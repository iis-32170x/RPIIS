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
    bool flag = true;// флаг отвечает за проверку на равенство всех элементов подматрицы 

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



void QuadTree::TakeFromTree(QuadTree* root, vector<vector<int>>& matrix, int row, int col, int size) {
    if (root) {
        if (size == 1) {
            if (row >= matrix.size() || col >= matrix[0].size()) {
                std::cerr << "Invalid row or col position" << std::endl;
                exit(1);
            }

            matrix[row][col] = root->data;
            return;
        }

        int newSize = size / 2;

        TakeFromTree(root->first, matrix, row, col, newSize);
        TakeFromTree(root->second, matrix, row, col + newSize, newSize);
        TakeFromTree(root->third, matrix, row + newSize, col, newSize);
        TakeFromTree(root->fourth, matrix, row + newSize, col + newSize, newSize);
    }
}

vector<vector<int>> QuadTree::TakeFromTree1(const vector<vector<int>>& matrix) {
    int size = matrix.size();  
    vector<vector<int>> result(size, vector<int>(size, 0));  

    TakeFromTree(this, result, 0, 0, size);  

    return result;
}



