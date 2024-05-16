#include "avl_tree.h"
#include <string>
#include <iostream>

// Конструктор
AVLTree::AVLTree() : root(nullptr) {}

// Деструктор
AVLTree::~AVLTree() {
    // Деструктор будет рекурсивно освобождать память всех узлов,
    // начиная с корня.
    destroyTree(root);
}

// Вспомогательная функция для деструктора для рекурсивного удаления узлов
void AVLTree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void AVLTree::printTree()
{
    printTreeHelper(root, "", true);
}

int AVLTree::height()
{
    return height(root);
}

int AVLTree::height(Node* node) const {
    if (node == nullptr) {
        // Высота пустого дерева или поддерева равна 0
        return 0;
    }
    // Высота узла равна максимальной высоте его поддеревьев плюс один
    return 1 + max(height(node->left), height(node->right));
}


// Проверка, пусто ли дерево
bool AVLTree::isEmpty() const {
    return root == nullptr;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

Node* AVLTree::insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        // Ключ уже существует, вставка не производится
        return node;
    }

    // Обновляем высоту узла
    fixHeight(node);

    // Выполняем балансировку
    return balance(node);
}

// Обновление высоты узла
void AVLTree::fixHeight(Node* node) {
    unsigned char heightLeft = node->left ? node->left->height : 0;
    unsigned char heightRight = node->right ? node->right->height : 0;
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

void AVLTree::printTreeHelper(const Node* node, string indent, bool last) const {
    // Проверяем, существует ли узел
    if (node != nullptr) {
        cout << indent;
        cout << (last ? "└── " : "├── ");

        // Вывод информации об узле
        cout << "key: " << node->key;

        cout << 
endl;

        // Рекурсивный вызов для левого и правого поддерева, обновляем indent для поддеревьев
        indent += last ? "    " : "│   ";
        printTreeHelper(node->left, indent, false);
        printTreeHelper(node->right, indent, true);
    }
}

// Вычисление фактора баланса узла
int AVLTree::getBalanceFactor(Node* node) {
    int heightLeft = node->left ? node->left->height : 0;
    int heightRight = node->right ? node->right->height : 0;
    return heightRight - heightLeft;
}

// Левое вращение вокруг узла
Node* AVLTree::rotateLeft(Node* node) {
    Node* leftNode = node->left;
    node->left = leftNode->right;
    leftNode->right = node;
    fixHeight(node);
    fixHeight(leftNode);
    return leftNode;
}

// Правое вращение вокруг узла
Node* AVLTree::rotateRight(Node* node) {
    Node* rightNode = node->right;
    node->right = rightNode->left;
    rightNode->left = node;
    fixHeight(node);
    fixHeight(rightNode);
    return rightNode;
}

// Метод для балансировки узла
Node* AVLTree::balance(Node* node) {
    fixHeight(node);

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor == 2) {
        if (getBalanceFactor(node->right) < 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    if (balanceFactor == -2) {
        if (getBalanceFactor(node->left) > 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    return node; // Балансировка не требуется
}

// Публичный метод
Node* AVLTree::find(int key) const {
    return find(root, key);
}


// Вспомогательный приватный метод
Node* AVLTree::find(Node* node, int key) const {
    if (node == nullptr) {
        return nullptr; // Ключ не найден
    }
    if (key < node->key) {
        return find(node->left, key);
    }
    else if (key > node->key) {
        return find(node->right, key);
    }
    else {
        return node; // Ключ найден
    }
}

void AVLTree::remove(int key) {
    root = remove(root, key);
}

Node* AVLTree::remove(Node* node, int key) {
    if (node == nullptr) return nullptr;

    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else { // Удаление узла, когда ключ найден
        Node* left = node->left;
        Node* right = node->right;

        delete node; // Удаление текущего узла

        if (right == nullptr) return left;

        Node* min = findMin(right);
        min->right = removeMin(right);
        min->left = left;

        return balance(min);
    }

    return balance(node);
}

Node* AVLTree::findMin(Node* node) {
    return node->left ? findMin(node->left) : node;
}

Node* AVLTree::removeMin(Node* node) {
    if (node->left == nullptr) return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

// Находит минимальный элемент в дереве
Node* AVLTree::findMin() const {
    Node* current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Находит максимальный элемент в дереве
Node* AVLTree::findMax() const {
    Node* current = root;
    while (current && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

Node* AVLTree::findSuccessor(int key) const {
    Node* current = find(root, key); // Сначала находим узел с данным ключом
    if (current == nullptr) return nullptr; // Если такого узла нет, возвращаем nullptr

    // Если у узла есть правое поддерево, то ищем минимальный элемент в этом поддереве
    if (current->right != nullptr) {
        Node* temp = current->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }

    // Если правого поддерева нет, поднимаемся вверх к корню,
    // пока не найдем переход от левого к правому поддереву
    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != current) {
        if (current->key < ancestor->key) {
            successor = ancestor; // Нашли потенциального successor
            ancestor = ancestor->left;
        }
        else {
            ancestor = ancestor->right;
        }
    }

    return successor;
}

Node* AVLTree::findPredecessor(int key) const {
    Node* current = find(root, key); // Сначала находим узел с данным ключом
    if (current == nullptr) return nullptr; // Если такого узла нет, возвращаем nullptr

    // Если у узла есть левое поддерево, то ищем максимальный элемент в этом поддереве
    if (current->left != nullptr) {
        Node* temp = current->left;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }

    // Если левого поддерева нет, поднимаемся вверх к корню,
    // пока не найдем переход от правого к левому поддереву
    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != current) {
        if (current->key > ancestor->key) {
            predecessor = ancestor; // Нашли потенциального predecessor
            ancestor = ancestor->right;
        }
        else {
            ancestor = ancestor->left;
        }
    }

    return predecessor;
}
