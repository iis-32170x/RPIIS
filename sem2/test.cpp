#include <iostream>
#include "..\StaticLib\pch.h"
using namespace std;
int main() {
    AVLTree tree;
    setlocale(LC_ALL, "RU");
   
    // Вставка элементов в дерево
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    try {
        // Поиск элемента
        int searchKey =7;
        bool searchResult = tree.search(searchKey);
        cout << "Результат поиска " << searchKey << ": " << (searchResult ? "Найдено" : "Не найдено") << endl;

        // Поиск минимального элемента
        int minKey = tree.findMin();
        cout << "Минимальный элемент: " << minKey << endl;

        // Поиск максимального элемента
        int maxKey = tree.findMax();
        cout << "Максимальный элемент: " << maxKey << endl;

        // Поиск ближайшего элемента, меньшего заданного
        int closestMinKey = tree.findClosestSmaller(searchKey);
        cout << "Ближайший элемент, меньший " << searchKey << ": " << closestMinKey << endl;

        // Поиск ближайшего элемента, большего заданного
        int closestMaxKey = tree.findClosestGreater(searchKey);
        cout << "Ближайший элемент, больший " << searchKey << ": " << closestMaxKey << endl;

        // Удаление элемента
        int keyToRemove = 12;
        bool removeResult = tree.remove(keyToRemove);
        cout << "Результат удаления элемента " << keyToRemove << ": " << (removeResult ? "Удалено" : "Не найдено") << endl;

        tree.print();
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}