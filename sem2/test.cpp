#include <iostream>
#include "..\StaticLib\pch.h"
using namespace std;

int main() {
    Node* tree = nullptr;
    setlocale(LC_ALL, "RU");

    // Заполнение дерева(проверка вставки)
    insert(&tree, 10);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);
    insert(&tree, 7);
    insert(&tree, 17);
    insert(&tree, 12);

    try {

        print(tree);

        // Поиск
        int searchKey = 7;
        bool searchResult = search(tree, searchKey);
        cout << "Результат поиска " << searchKey << ": " << (searchResult ? "Найдено" : "Не найдено") << endl;

        // Поиск минимального 
        int minKey = findMin(tree);
        cout << "Минимальный элемент: " << minKey << endl;

        // Поиск максимального элемента
        int maxKey = findMax(tree);
        cout << "Максимальный элемент: " << maxKey << endl;

        // Поиск ближайшего наименьшего
        int closestMinKey = findClosestSmaller(tree, searchKey);
        cout << "Ближайший элемент, меньший " << searchKey << ": " << closestMinKey << endl;

        // Поиск ближайшего наибольшего 
        int closestMaxKey = findClosestGreater(tree, searchKey);
        cout << "Ближайший элемент, больший " << searchKey << ": " << closestMaxKey << endl;

        // Удаление
        int keyToRemove = 17;
        bool removeResult = remove(&tree, keyToRemove);
        cout << "Результат удаления элемента " << keyToRemove << ": " << (removeResult ? "Удалено" : "Не найдено") << endl;

        // Вывод полученного дерева 
        print(tree);
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    // Очистка памяти
    clear(tree);

    return 0;
}
