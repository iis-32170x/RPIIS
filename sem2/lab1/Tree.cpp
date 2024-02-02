#include "Tree.h"

void QuadTree::ViewTree(QuadTree* root,int level) {
    if (root) {
       
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << root-> data << endl;
        ViewTree(root->first, level + 1);
        ViewTree(root->second, level + 1);
        ViewTree(root->third, level + 1);
        ViewTree(root->fourth, level + 1);
    }
}

QuadTree* QuadTree::Add_data(QuadTree* root, int data) {
    if (!root) {
        QuadTree* root = new QuadTree;
        root->data = data;
        root->first = nullptr;
        root->second = nullptr;
        root->third = nullptr;
        root->fourth = nullptr;
        return root;
    }
    if (!root->first->first) {
        root->first->first = new QuadTree;
        root->first->second = new QuadTree;
        root->first->third = new QuadTree;
        root->first->fourth = new QuadTree;
    }
    root->first = Add_data(root->first, data);
    root->second = Add_data(root->second, data);
    root->third = Add_data(root->third, data);
    root->fourth = Add_data(root->fourth, data);
    return root;
}

QuadTree* QuadTree::TakeFromArray(const vector<vector<int>>& arr, int row, int col, int size) {
    if (size == 1) {
        QuadTree* Tree = new QuadTree;
        Tree->data = arr[row][col];
        return Tree;
    }

    int newSize = size / 2;

    QuadTree* root = new QuadTree;
    root->data = 0;
    
    

    root->first = TakeFromArray(arr, row, col, newSize);
    root->second = TakeFromArray(arr, row, col + newSize, newSize);
    root->third = TakeFromArray(arr, row + newSize, col, newSize);
    root->fourth = TakeFromArray(arr, row + newSize, col + newSize, newSize);

    return root;
}

void QuadTree::TakeFromTree(QuadTree* root, vector<vector<int>>& matrix, int row, int col, int size) {
    if (root) {
        if (size == 1) {
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