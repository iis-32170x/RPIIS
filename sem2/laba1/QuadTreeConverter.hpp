#ifndef QUAD_TREE_CONVERTER_HPP
#define QUAD_TREE_CONVERTER_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct QuadTreeNode {
    bool isLeaf;
    int value;
    QuadTreeNode* topLeft;
    QuadTreeNode* topRight;
    QuadTreeNode* bottomLeft;
    QuadTreeNode* bottomRight;
};

bool isHomogeneous(vector<vector<int>>& matrix, int size, int x = 0, int y = 0);

QuadTreeNode *convertToQuadTree(vector<vector<int>> &matrix, int size = 0, int x = 0, int y = 0);

vector<vector<int>> convertToMatrix(QuadTreeNode *node);

int getMaxDepth(QuadTreeNode* node);

void fillMatrix(QuadTreeNode* node, vector<vector<int>>& matrix, int x, int y, int size);

#endif