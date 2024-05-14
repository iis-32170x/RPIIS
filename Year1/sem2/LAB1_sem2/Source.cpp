#include "Header.h"
#include <iostream>
using namespace N;
int main() {
    bst* tree = new bst;
    bst* tree1 = new bst;
    int keys[] = { 23, 12, 31, 3, 15, 7, 29, 88, 53 };

    // способ создания дерева из массива с помощью функции insert
    /*for (const int& key : keys)
        tree->Insert(key);

    std:: cout << "Tree keys: ";
    tree->bypass();
    */

    // способ задания дерева из массива с помощью отдельной функции(для отсортированного массива)
    /*tree1->CreateBSTarr_NotSort(keys, 0, 8);
    std::cout << "Tree keys: ";
    tree1->bypass();
    */

    // создание дерева из неотсортированного массива
    tree->CreateBSTarr(keys, 9);
    std::cout << "Tree keys: ";
    tree->bypass();

    // поиск элемента
    std::cout << "search 7" << std::endl;
    bool b = tree->search(7);
    if (b) {
        std::cout << "found" << std::endl;
    }
    else std::cout << "not found" << std::endl;

    // удаление элемента
    std::cout << "remove 7" << std::endl;
    tree->Remove(7);

    std::cout << "Tree keys after remove: ";
    tree->bypass();
    

    // поиск элемента
    std::cout << "search 7" << std::endl;
    b = tree->search(7);
    if (b) {
        std::cout << "found" << std::endl;
    }
    else std::cout << "not found" << std::endl;
    
    // Добавление элемента
    std::cout << "insert 7" << std::endl;
    tree->Insert(7);
    
    // поиск элемента
    std::cout << "search 7" << std::endl;
    b = tree->search(7);
    if (b) {
        std::cout << "found" << std::endl;
    }
    else std::cout << "not found" << std::endl;
}