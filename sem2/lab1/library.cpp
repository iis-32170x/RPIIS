#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "library.h"
using namespace std;

int tabs=0;

// Функция создания узла дерева
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->key = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Функция для построения дерева из массива
Node* buildTree(int arr[], int start, int end)
{
    // Проверка наличия элементов в массиве
    if (start > end)
        return NULL;

    // Вычисление индекса корневого элемента
    int mid = (start + end) / 2;

    // Создание узла дерева из среднего элемента массива
    Node* root = createNode(arr[mid]);

    // Рекурсивное построение левого и правого поддеревьев
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);

    return root;
}

//Функция отображения дерева
void printTree(Node* root)
{
    if (root == nullptr) 
    {
        return;
    }

    tabs += 5;

    printTree(root->right);

    for (int i = 0; i < tabs; i++) 
    {
        cout << " ";
    }

    cout << root->key << endl;

    printTree(root->left);

    tabs -= 5;
    return;
}

//Функция для вставки нового узла
Node* insertNode(Node* root, int value)
{
    // Если дерево пустое, создаем новый узел и делаем его корнем
    if (root == nullptr)
    {
        root = createNode(value);
        return root;
    }

    // Рекурсивно вставляем элемент в правильное поддерево
    if (value < root->key)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->key)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Функция для поиска узла в бинарном дереве поиска
bool search(Node* root, int key)
{
    // Если дерево пустое или ключ корня равен искомому ключу
    if (root == nullptr || root->key == key)
    {
        if (root != nullptr)
        {
            cout << "Элемент найден." << endl;
        }
        else
        {
            cout << "Элемент не найден." << endl;
        }
        return true;
    }

    // Если искомый ключ меньше ключа корня, рекурсивно ищем в левом поддереве
    if (key < root->key)
    {
        return search(root->left, key);
    }

    // Если искомый ключ больше ключа корня, рекурсивно ищем в правом поддереве
    return search(root->right, key);
}

// Функция для поиска наименьшего элемента в бинарном дереве
Node* findMinNode(Node* root) 
{
    if (root == nullptr) 
    {
        return nullptr;
    }
    while (root->left != nullptr) 
    {
        root = root->left;
    }
    return root;
}

// Функция для удаления элемента из бинарного дерева поиска
Node* deleteNode(Node* root, int key)
{
    if (root == nullptr)
        return root;

    // Если ключ меньше значения корневого узла, рекурсивно ищем и удаляем в левом поддереве
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    // Если ключ больше значения корневого узла, рекурсивно ищем и удаляем в правом поддереве
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    // Если ключ совпадает со значением корневого узла, удаляем корневой узел
    else
    {
        // Узлы с одним или без детей удаляются просто путем освобождения памяти
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Узлы с двумя детьми заменяются на узел с наименьшим ключом из правого поддерева
        Node* temp = findMinNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Функция обхода дерева в прямом порядке (pre-order)
void preOrderTraversal(Node* node)
{
    if (node == nullptr)
        return;

    cout << node->key << " "; // Посещаем текущий узел
    preOrderTraversal(node->left); // Рекурсивно обходим левое поддерево
    preOrderTraversal(node->right); // Рекурсивно обходим правое поддерево
}

// Функция обхода дерева в симметричном порядке (in-order)
void inOrderTraversal(Node* node)
{
    if (node == nullptr)
        return;

    inOrderTraversal(node->left); // Рекурсивно обходим левое поддерево
    cout << node->key << " "; // Посещаем текущий узел
    inOrderTraversal(node->right); // Рекурсивно обходим правое поддерево
}

// Функция обхода дерева в обратном порядке (post-order)
void postOrderTraversal(Node* node)
{
    if (node == nullptr)
        return;

    postOrderTraversal(node->left); // Рекурсивно обходим левое поддерево
    postOrderTraversal(node->right); // Рекурсивно обходим правое поддерево
    cout << node->key << " "; // Посещаем текущий узел
}

//Функция очистки памяти
void clearTree(Node* root)
{
    if (root == nullptr) 
{
        return;
    }

    clearTree(root->left);
    clearTree(root->right);

    delete root;
}

#endif


