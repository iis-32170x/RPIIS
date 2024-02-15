#include <iostream>
#include <vector>
#include "QuadTreeConverter.hpp"
using namespace std;

bool isHomogeneous(vector<vector<int>> &matrix, int size, int x, int y)
{
    int firstValue = matrix[x][y];
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (matrix[i][j] != firstValue)
            {
                return false;
            }
        }
    }
    return true;
}

QuadTreeNode *convertToQuadTree(vector<vector<int>> &matrix, int size, int x, int y)
{
    if (size == 0)
    {
        size = matrix.size();
    }

    if (isHomogeneous(matrix, size, x, y))
    {
        return new QuadTreeNode{true, matrix[x][y], nullptr, nullptr, nullptr, nullptr};
    }
    else
    {
        int newSize = size / 2;
        QuadTreeNode *node = new QuadTreeNode();
        node->isLeaf = false;
        node->value = -1;
        node->topLeft = convertToQuadTree(matrix, newSize, x, y);
        node->topRight = convertToQuadTree(matrix, newSize, x, y + newSize);
        node->bottomLeft = convertToQuadTree(matrix, newSize, x + newSize, y);
        node->bottomRight = convertToQuadTree(matrix, newSize, x + newSize, y + newSize);
        return node;
    }
}

void fillMatrix(QuadTreeNode *node, vector<vector<int>> &matrix, int x, int y, int size)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->isLeaf)
    {
        for (int i = x; i < x + size; i++)
        {
            for (int j = y; j < y + size; j++)
            {
                matrix[i][j] = node->value;
            }
        }
    }
    else
    {
        int newSize = size / 2;
        fillMatrix(node->topLeft, matrix, x, y, newSize);
        fillMatrix(node->topRight, matrix, x, y + newSize, newSize);
        fillMatrix(node->bottomLeft, matrix, x + newSize, y, newSize);
        fillMatrix(node->bottomRight, matrix, x + newSize, y + newSize, newSize);
    }
}

int getMaxDepth(QuadTreeNode *node)
{
    if (node == nullptr)
        return 0;
    if (node->isLeaf)
        return 1;

    int depthTopLeft = getMaxDepth(node->topLeft);
    int depthTopRight = getMaxDepth(node->topRight);
    int depthBottomLeft = getMaxDepth(node->bottomLeft);
    int depthBottomRight = getMaxDepth(node->bottomRight);

    int maxDepth = 1 + max({depthTopLeft, depthTopRight, depthBottomLeft, depthBottomRight});

    return maxDepth;
}

vector<vector<int>> convertToMatrix(QuadTreeNode *node)
{
    if (node == nullptr)
    {
        return vector<vector<int>>();
    }

    int size = pow(2, getMaxDepth(node) - 1);
    vector<vector<int>> matrix(size, vector<int>(size, 0));

    fillMatrix(node, matrix, 0, 0, size);
    return matrix;
}