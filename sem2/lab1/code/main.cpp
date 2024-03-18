#include "branch.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(0, "");
    Branch* rootA = nullptr;
    Add(rootA, 5);
    Add(rootA, 3);
    Add(rootA, 8);
    Add(rootA, 2);
    Add(rootA, 4);

    Branch* rootB = nullptr;
    Add(rootB, 8);
    Add(rootB, 1);
    Add(rootB, 4);
    Add(rootB, 6);
    Add(rootB, 9);

    Branch* unionResult = nullptr;
    Union(rootA, rootB, unionResult);
    cout << "Объединение: ";
    print(unionResult);
    cout << endl;

    Branch* intersectionResult = nullptr;
    Intersection(rootA, rootB, intersectionResult);
    cout << "Пересечение: ";
    print(intersectionResult);
    cout << endl;

    removeNode(rootA, 3);
    cout << "После удаления элемента: ";
    print(rootA);
    cout << endl;

    Branch* foundElem = FindElem(rootA, 4);
    if (foundElem) {
        cout << "Найденный элемент: " << foundElem->data << endl;
    }

    return 0;
}
