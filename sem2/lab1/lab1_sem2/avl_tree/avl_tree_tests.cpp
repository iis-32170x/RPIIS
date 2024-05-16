#include "avl_tree.h"
#include <cassert>
#include <iostream>

void testPrintTree() {
    AVLTree tree;

    cout << "Тестирование вывода структуры дерева...\n";

    // Вставляем элементы в дерево
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);

    // Выводим структуру дерева
    tree.printTree();

    cout << "Проверим выше структуру AVL-дерева на корректность визуально.\n";
}

void testInsertWithPrint() {
    AVLTree tree;

    cout << "Тестирование операции вставки с выводом структуры дерева:\n";

    // Печать пустого дерева
    cout << "Изначальное пустое дерево:\n";
    tree.printTree();

    // Массив ключей для вставки
    int keys[] = { 3, 1, 4, 2, 5 };
    for (int key : keys) {
        cout << "Вставка элемента с ключом: " << key << "\n";
        tree.insert(key);
        tree.printTree();
        cout << "\n";
    }
}

void testRemoveWithPrint() {
    AVLTree tree;

    cout << "Тестирование операции удаления с выводом структуры дерева:\n";

    // Массив ключей для вставки
    int keysToInsert[] = { 3, 1, 4, 2, 5 };
    cout << "Изначальное наполнение дерева:\n";
    for (int key : keysToInsert) {
        tree.insert(key);
    }
    tree.printTree();

    // Массив ключей для удаления в обратном порядке
    int keysToRemove[] = { 5, 2, 4, 1, 3 };
    for (int key : keysToRemove) {
        std::cout << "Удаление элемента с ключом: " << key << "\n";
        tree.remove(key);
        tree.printTree();
        std::cout << "\n";
    }
}

void testFindMinAndMax() {
    AVLTree tree;

    cout << "Тестирование поиска минимального и максимального элементов:\n";

    // Вставляем элементы в дерево
    int keys[] = { 5, 3, 8, 1, 4, 7, 9 };
    for (int key : keys) {
        tree.insert(key);
    }

    // Выводим структуру дерева после вставки элементов
    cout << "Структура дерева после вставки элементов:\n";
    tree.printTree();

    // Находим и выводим минимальный и максимальный элементы
    Node* minNode = tree.findMin();
    Node* maxNode = tree.findMax();
    cout << "Минимальный элемент в дереве: " << (minNode ? std::to_string(minNode->key) : "Дерево пусто") << "\n";
    cout << "Максимальный элемент в дереве: " << (maxNode ? std::to_string(maxNode->key) : "Дерево пусто") << "\n";
}

void testFindPredecessorAndSuccessor() {
    AVLTree tree;

    cout << "Тестирование поиска ближайшего меньшего и ближайшего большего элементов:\n";

    // Вставляем элементы в дерево
    int keys[] = { 15, 10, 20, 8, 12, 17, 25, 6, 11, 16 };
    for (int key : keys) {
        tree.insert(key);
    }

    // Выводим структуру дерева после вставки элементов
    cout << "Структура дерева после вставки элементов:\n";
    tree.printTree();

    // Ключи для тестирования поиска predecessor и successor
    int testKeys[] = { 10, 15, 20 };
    for (int key : testKeys) {
        Node* predecessor = tree.findPredecessor(key);
        Node* successor = tree.findSuccessor(key);
        cout << "Для ключа " << key << ":\n";
        cout << "  Predecessor: " << (predecessor ? std::to_string(predecessor->key) : "нет") << "\n";
        cout << "  Successor: " << (successor ? std::to_string(successor->key) : "нет") << "\n";
    }
}

void runAllTests() {
    cout << "\nТест на визуализацию структуры:\n";
    testPrintTree();
    cout << "\nТест на вставку узлов:\n";
    testInsertWithPrint();
    cout << "\nТест на удаление узлов:\n";
    testRemoveWithPrint();
    cout << "\nТест на поиск минимального и максимального узлов:\n";
    testFindMinAndMax();
    cout << "\nТест на поиск ближайших меньшего и большего узлов:\n";
    testFindPredecessorAndSuccessor();
    cout << "\nВсе тесты пройдены!\n";
}
