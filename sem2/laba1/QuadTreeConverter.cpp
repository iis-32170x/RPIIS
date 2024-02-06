#include <iostream>
#include <vector>
#include "QuadTreeConverter.hpp"
using namespace std;

bool isHomogeneous(int x, int y, int size, vector<vector<int>>& matrix) {
    int firstValue = matrix[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (matrix[i][j] != firstValue) {
                return false;
            }
        }
    }
    return true;
}

QuadTreeNode* convertToQuadTree(int x, int y, int size, vector<vector<int>>& matrix) {
    if (isHomogeneous(x, y, size, matrix)) {
        return new QuadTreeNode{true, matrix[x][y], nullptr, nullptr, nullptr, nullptr};
    }
    else {
        int newSize = size / 2;
        QuadTreeNode* node = new QuadTreeNode();
        node->isLeaf = false;
        node->value = -1;
        node->topLeft = convertToQuadTree(x, y, newSize, matrix);
        node->topRight = convertToQuadTree(x, y + newSize, newSize, matrix);
        node->bottomLeft = convertToQuadTree(x + newSize, y, newSize, matrix);
        node->bottomRight = convertToQuadTree(x + newSize, y + newSize, newSize, matrix);
        return node;
    }
}

void convertToMatrix(QuadTreeNode* node, int x, int y, int size, vector<vector<int>>& matrix) {
    if (node->isLeaf) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                matrix[i][j] = node->value;
            }
        }
    } else {
        int newSize = size / 2;
        if (node->topLeft) convertToMatrix(node->topLeft, x, y, newSize, matrix);
        if (node->topRight) convertToMatrix(node->topRight, x, y + newSize, newSize, matrix);
        if (node->bottomLeft) convertToMatrix(node->bottomLeft, x + newSize, y, newSize, matrix);
        if (node->bottomRight) convertToMatrix(node->bottomRight, x + newSize, y + newSize, newSize, matrix);
    }
}