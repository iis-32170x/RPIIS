#ifndef QUAD_TREE_CONVERTER_HPP
#define QUAD_TREE_CONVERTER_HPP

#include <iostream>
#include <vector>
using namespace std;

struct QuadTreeNode {
    bool isLeaf;
    int value;
    QuadTreeNode* topLeft;
    QuadTreeNode* topRight;
    QuadTreeNode* bottomLeft;
    QuadTreeNode* bottomRight;
};

bool isHomogeneous(int x, int y, int size, vector<vector<int>>& matrix);

QuadTreeNode* convertToQuadTree(int x, int y, int size, vector<vector<int>>& matrix);

void convertToMatrix(QuadTreeNode* node, int x, int y, int size, vector<vector<int>>& matrix);

#endif // QUAD_TREE_CONVERTER_HPP