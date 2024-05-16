#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "avl_node.h"
#include <string>
using namespace std;

class AVLTree {
public:
    AVLTree(); // Конструктор
    ~AVLTree(); // Деструктор

    // Основные операции с AVL-деревом
    void insert(int key); // Вставка ключа
    void remove(int key); // Удаление ключа
    Node* find(int key) const; // Поиск узла по ключу
    bool isEmpty() const; // Проверка дерева на пустоту
    void printTree(); // Вывод структуры дерева в консоль
    int height(); // Получение высоты дерева
    Node* findMin() const; // Находит минимальный элемент
    Node* findMax() const; // Находит максимальный элемент
    Node* findSuccessor(int key) const; // Находит ближайший больший элемент для заданного ключа
    Node* findPredecessor(int key) const; // Находит ближайший меньший элемент для заданного ключа

private:
    Node* root; // Корневой узел дерева

    // Вспомогательные функции для рекурсивной реализации основных операций
    Node* insert(Node* node, int key); // Вставка ключа в поддерево
    Node* remove(Node* node, int key); // Удаление ключа из поддерева
    Node* find(Node* node, int key) const; // Поиск узла по ключу в поддереве
    void destroyTree(Node* node); // Рекурсивное удаление всех узлов дерева

    // Вспомогательные функции для поддержания баланса дерева
    Node* balance(Node* node); // Балансировка узла
    Node* rotateLeft(Node* node); // Левое вращение
    Node* rotateRight(Node* node); // Правое вращение
    int getBalanceFactor(Node* node); // Получение фактора баланса узла
    void fixHeight(Node* node); // Обновление высоты узла

    // Вспомогательные функции для работы с узлами
    Node* findMin(Node* node); // Поиск узла с минимальным ключом
    Node* removeMin(Node* node); // Удаление узла с минимальным ключом
    void printTreeHelper(const Node* node, std::string indent, bool last) const; // Вспомогательная функция для печати дерева
    int height(Node* node) const; // Вычисление высоты поддерева
};

#endif // AVL_TREE_H
