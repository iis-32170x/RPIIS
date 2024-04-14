#include <iostream>
#include "BinarySearchTree.h"

int main() {
   /* BinarySearchTree bst;

    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    std::cout << "Inorder traversal of the BST: ";
    bst.inorderTraversal();

    std::cout << "Deleting 3...\n";
    bst.deleteKey(3);
    std::cout << "Inorder traversal after deleting 3: ";
    bst.inorderTraversal();

    int key = 7;
    if (bst.search(key)) {
        std::cout << "Key " << key << " found in the BST.\n";
    }
    else {
        std::cout << "Key " << key << " not found in the BST.\n";
    }

    std::cout << "insert 23: ";
    bst.insert(23);
    bst.inorderTraversal();
    */

        BinarySearchTree bst;

        int keys[] = { 40, 20, 60, 10, 30, 50, 70, 5, 15, 25, 35, 45, 55, 65, 75 };
        for (int key : keys) {
            bst.insert(key);
        }

        std::cout << "Inorder traversal of the BST: ";
        bst.inorderTraversal();

        std::cout << "Searching for nodes 25 and 65:" << std::endl;
        std::cout << "Node 25: " << (bst.search(25) ? "found" : "not found") << std::endl;
        std::cout << "Node 65: " << (bst.search(65) ? "found" : "not found") << std::endl;

        std::cout << "insert 20 und 60: ";
        bst.insert(20);
        bst.insert(60);
        bst.inorderTraversal();

        std::cout << "Inorder traversal after deletions: ";
        bst.inorderTraversal();

        std::cout << "Deleting nodes 20 and 60:" << std::endl;
        bst.deleteKey(20);
        bst.deleteKey(60);

        std::cout << "Inorder traversal after deletions: ";
        bst.inorderTraversal();

        std::cout << "Final structure of the BST: ";
        bst.inorderTraversal();

    return 0;
}