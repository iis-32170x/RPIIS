#include "hash_table.h"

using namespace std;

void run_testcase(const string& path, int& arrSize, int arr[]) {
    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        cout << "File is not open\n";
    }
    else {
        file >> arrSize;
        for (int i = 0; i < arrSize; i++) {
            file >> arr[i];
        }
        file.close();
    }
}

Node** create(int tableSize) {
    Node** pTable = new Node * [tableSize];
    for (int i = 0; i < tableSize; i++) {
        pTable[i] = NULL;
    }
    return pTable;
}

void add(int inf, int tableSize, Node** pTable) {
    Node* newElement = new Node;
    newElement->inf = inf;
    newElement->deleted = false;
    int i = inf % tableSize;
    if (pTable[i] == NULL) {//добавляем элемент в ячейку
        pTable[i] = newElement;
        newElement->pNext = NULL;
    }
    else {//добавляем элемент в начало списка
        newElement->pNext = pTable[i];
        pTable[i] = newElement;
    }
}

int search(int inf, int tableSize, Node** pTable) {
    int i = abs(inf % tableSize);
    Node* currentNode = pTable[i];
    while (currentNode != NULL) {
        if (!currentNode->deleted && currentNode->inf == inf)
            return i;
        currentNode = currentNode->pNext;//переход к следующему узлу
    }
    return -1;
}

void remove(int inf, int tableSize, Node** pTable) {
    int i = abs(inf % tableSize);
    Node* currentNode = pTable[i];
    while (currentNode != NULL) {
        if (currentNode->inf == inf) {
            currentNode->deleted = true;
        }
        currentNode = currentNode->pNext;
    }
}
