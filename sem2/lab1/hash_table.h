#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

struct Node {
    int inf;            // Значение, хранимое в узле
    bool deleted;       // Флаг, указывающий, был ли узел помечен как удаленный
    Node* pNext;        // Указатель на следующий узел в списке
};

void run_testcase(const std::string& path, int& arrSize, int arr[]);
Node** create(int tableSize);
void add(int inf, int tableSize, Node** pTable);
int search(int inf, int tableSize, Node** pTable);
void remove(int inf, int tableSize, Node** pTable);

