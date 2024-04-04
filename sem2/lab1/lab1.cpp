
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
import function;
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    TreeNode* root = getNewNode(1);

    // Вставка элементов в дерево
    addChild(root, 2);
    addChild(root, 3);
    addChild(root, 4);
    TreeNode* node2 = root->children[0];
    addChild(node2, 5);
    addChild(node2, 6);

    TreeNode* node3 = root->children[1];
    addChild(node3, 7);

    TreeNode* node4 = root->children[2];
    addChild(node4, 8);
    addChild(node4, 9);
    addChild(node4, 10);
    TreeNode* node5 = root->children[0]->children[0];
    addChild(node5, 11);
    addChild(node5, 12);
    // Вывод дерева
    cout << "Дерево до удаления элемента:" << endl;
    printTree(root);

    // Удаление элемента из дерева
    int elementToDelete;
    cout << "Введите элемент, который хотите удалить: ";
    cin >> elementToDelete;
    root = deleteNode(root, elementToDelete);
    cout << "Дерево после удаления элемента " << elementToDelete << ":" << endl;
    printTree(root);

    // Освобождение памяти
    deleteTree(root);

    return 0;
}