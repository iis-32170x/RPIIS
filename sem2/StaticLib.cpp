#include <iomanip>
#include <iostream>
#include "pch.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    // Реализация деструктора для освобождения памяти, занимаемой узлами дерева
}

bool AVLTree::search(int value) {
    Node* current = root;

    while (current != nullptr) {
        if (value == current->key) {
            return true; // Значение найдено
        }
        else if (value < current->key) {
            current = current->left; // Идем влево
        }
        else {
            current = current->right; // Идем вправо
        }
    }

    return false;
}

int AVLTree::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::updateHeight(Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

AVLTree::Node* AVLTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

AVLTree::Node* AVLTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

AVLTree::Node* AVLTree::balance(Node* node) {
    updateHeight(node);

    if (getBalanceFactor(node) == 2) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    if (getBalanceFactor(node) == -2) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

AVLTree::Node* AVLTree::insertNode(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }
    else {
        return node;
    }

    return balance(node);
}

void AVLTree::insert(int key) {
    root = insertNode(root, key);
}

AVLTree::Node* AVLTree::findMinNode(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

AVLTree::Node* AVLTree::findMaxNode(Node* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

AVLTree::Node* AVLTree::removeNode(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = removeNode(node->right, key);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        }
        else if (node->right == nullptr) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }
        else {
            Node* minNode = findMinNode(node->right);
            node->key = minNode->key;
            node->right = removeNode(node->right, minNode->key);
        }
    }

    return balance(node);
}

bool AVLTree::remove(int key) {
    if (!search(key)) {
        return false; // Элемент не найден, удаление не выполняется
    }

    root = removeNode(root, key);
    return true; // Успешное удаление элемента
}

void AVLTree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

int AVLTree::findMin() {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    Node* minNode = findMinNode(root);
    return minNode->key;
}

int AVLTree::findMax() {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    Node* maxNode = findMaxNode(root);
    return maxNode->key;
}

AVLTree::Node* AVLTree::findClosestGreaterNode(Node* node, int key) {
    Node* result = nullptr;

    while (node != nullptr) {
        if (node->key > key) {
            result = node;
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    return result;
}

int AVLTree::findClosestGreater(int key) {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    Node* closestNode = findClosestGreaterNode(root, key);
    if (closestNode == nullptr) {
        throw std::runtime_error("No greater element found");
    }

    return closestNode->key;
}

AVLTree::Node* AVLTree::findClosestSmallerNode(Node* node, int key) {
    Node* result = nullptr;

    while (node != nullptr) {
        if (node->key < key) {
            result = node;
            node = node->right;
        }
        else {
            node = node->left;
        }
    }

    return result;
}

int AVLTree::findClosestSmaller(int key) {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    Node* closestNode = findClosestSmallerNode(root, key);
    if (closestNode == nullptr) {
        throw std::runtime_error("No smaller element found");
    }

    return closestNode->key;
}
void AVLTree::print_n(const Node* p, int n, int level, int prob) {
    if (p) {
        if (level == n) {
            for (int i = 0; i <= prob; i++)
                std::cout << " ";
            std::cout << p->key;
        }
        else {
            print_n(p->left, n, level + 1, prob);
            print_n(p->right, n, level + 1, prob);
        }
    }
}

void AVLTree::print() {
    int h = getHeight(root);
    int prob = 3;
    if (root) {
        for (int i = 0; i <= h; i++) {
            print_n(root, i, 0, prob * (h - i));
            std::cout << std::endl;
        }
    }
}