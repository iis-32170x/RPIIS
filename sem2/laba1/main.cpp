#include <iostream>
#include <vector>
#include "QuadTreeConverter.hpp"
using namespace std;

void printQuadTree(QuadTreeNode* node, int depth = 0) {
    if (node == nullptr) return;

    if (node->isLeaf) {
        for (int i = 0; i < depth; i++) {
            cout << '-';
        }
        cout << ' ' << node->value << endl;
    }
    printQuadTree(node->topLeft, depth + 1);
    printQuadTree(node->topRight, depth + 1);
    printQuadTree(node->bottomLeft, depth + 1);
    printQuadTree(node->bottomRight, depth + 1);
}

int main() {
    int choice = 0;
    cout << "Выберите необходимое действие:\n1. Перевод матрицы в дерево\n2. Перевод дерева в матрицу\nВаш выбор: ";
    cin >> choice;
    switch (choice) {
        case 1: // Матрица в дерево
        {
            int matrixSize = 8;
            vector<vector<int>> matrix = {
                {12, 12, 136, 136},
                {12, 12, 136, 136},
                {12, 12, 12, 12},
                {100, 100, 12, 12}
            };
            QuadTreeNode* root = convertToQuadTree(0, 0, matrixSize, matrix);
            printQuadTree(root, 0);
            break;
        }
        case 2: // Дерево в матрицу
        {
            int matrixSize = 4;
            QuadTreeNode* root = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};
            root->topLeft = new QuadTreeNode{true, 12, nullptr, nullptr, nullptr, nullptr};
            root->topRight = new QuadTreeNode{true, 136, nullptr, nullptr, nullptr, nullptr};
            root->bottomLeft = new QuadTreeNode{false, -1, nullptr, nullptr, nullptr, nullptr};
            root->bottomLeft->topLeft = new QuadTreeNode{true, 12, nullptr, nullptr, nullptr, nullptr};
            root->bottomLeft->topRight = new QuadTreeNode{true, 12, nullptr, nullptr, nullptr, nullptr};
            root->bottomLeft->bottomLeft = new QuadTreeNode{true, 100, nullptr, nullptr, nullptr, nullptr};
            root->bottomLeft->bottomRight = new QuadTreeNode{true, 100, nullptr, nullptr, nullptr, nullptr}; 
            root->bottomRight = new QuadTreeNode{true, 12, nullptr, nullptr, nullptr, nullptr};
            vector<vector<int>> matrix(matrixSize, vector<int>(matrixSize, 0));
            printQuadTree(root, 0);
            convertToMatrix(root, 0, 0, matrixSize, matrix);
            break;
        }
        return 0;
    }
}