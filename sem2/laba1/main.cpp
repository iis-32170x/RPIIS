#include <iostream>
#include <vector>
#include "QuadTreeConverter.hpp"
using namespace std;

void printQuadTree(QuadTreeNode *node, int depth = 0)
{
    if (node == nullptr)
        return;

    if (node->isLeaf)
    {
        for (int i = 0; i < depth; i++)
        {
            cout << '-';
        }
        cout << ' ' << node->value << endl;
    }
    printQuadTree(node->topLeft, depth + 1);
    printQuadTree(node->topRight, depth + 1);
    printQuadTree(node->bottomLeft, depth + 1);
    printQuadTree(node->bottomRight, depth + 1);
}

int main()
{
    int choice = 0;
    cout << "Выберите необходимое действие:\n1. Перевод матрицы в дерево\n2. Перевод дерева в матрицу\nВаш выбор: ";
    cin >> choice;
    switch (choice)
    {
    case 1: // Матрица в дерево
    {
        vector<vector<int>> matrix = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 1, 1},
            {0, 0, 0, 0, 1, 1, 1, 1},
            {0, 0, 0, 1, 1, 1, 1, 1},
            {0, 0, 1, 1, 1, 1, 1, 1},
            {0, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 0}
        };

        QuadTreeNode *root = convertToQuadTree(matrix);
        vector<vector<int>> testMatrix(matrix.size(), vector<int>(matrix.size(), 0));
        testMatrix = convertToMatrix(root);
        bool result;
        for (int i = 0; i < testMatrix.size(); i++)
        {
            for (int j = 0; j < testMatrix[i].size(); j++)
            {
                if (testMatrix[i][j] != matrix[i][j])
                {
                    result = false;
                }
            }
        }
        if (result)
        {
            cout << "Тест пройден успешно!" << endl;
        }
        else
        {
            cout << "Тест не пройден!" << endl;
        }
        break;
    }
    case 2: // Дерево в матрицу
    {
        QuadTreeNode *root = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};

        root->topLeft = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};

        root->topRight = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};
        root->topRight->topLeft = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};
        root->topRight->topRight = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};
        root->topRight->bottomLeft = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->topRight->bottomRight = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};

        root->bottomLeft = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->topLeft = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->topRight = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->topRight->topLeft = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->topRight->topRight = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->topRight->bottomLeft = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->topRight->topRight = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->bottomLeft = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};
        root->bottomLeft->bottomRight = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};

        root->bottomRight = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->topLeft = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->topRight = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->bottomLeft = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->bottomLeft->topLeft = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->bottomLeft->topRight = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->bottomLeft->bottomLeft = new QuadTreeNode{true, 1, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->bottomLeft->bottomRight = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};
        root->bottomRight->bottomRight = new QuadTreeNode{true, 0, nullptr, nullptr, nullptr, nullptr};

        printQuadTree(root, 0);
        vector<vector<int>> matrix = convertToMatrix(root);
        int depth = getMaxDepth(root) - 1;
        cout << "Depth: " << depth << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        break;
    }
    default:
    {
        cout << "Неизвестный выбор, попробуйте еще раз.";
    }
        return 0;
    }
}