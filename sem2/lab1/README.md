# <p align="center">Лабораторная работа №1</p>

Вариант 5 Дерево отрезков. Поиск количества вхождений какого-то числа на
отрезке массива. Изменение всех чисел на отрезке массива на какое-то
значение.
## <p align="center">Цели лабораторной работы:</p>
1. Разработать библиотеку для работы с очередью  на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.

## <p align="center">Задачи лабораторной работы:</p>
1. Изучить спецификацию задачи по работе с очередью.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для работы с очередью, включая операции вставки и извлечения элементов.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## <p align="center">Список используемых понятий:</p>
1. **Библиотека программного обеспечения (Библиотека кода):**
В программировании библиотека представляет собой совокупность программного кода, предназначенного для решения определенных задач. Этот код может содержать функции, классы, процедуры или другие компоненты, которые разработчики могут повторно использовать в своих программных проектах. Библиотеки упрощают разработку, так как они предоставляют готовые решения для типовых задач.
## <p align="center">Описание используемых алгоритмов:</p>
1. **Структура SegmentTreeNode:.**
Предоставляет информацию о начале и конце отрезка, а также о количестве вхождений в этом отрезке.
```cpp
struct SegmentTreeNode {
int start;
int end;
int count;
};
```
2. **Функция buildSegmentTree:**
- Используется для построения дерева отрезков на основе заданного массива arr.
```cpp
void buildSegmentTree(vector<SegmentTreeNode>& tree, int arr[], int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = { start, end, (arr[start] == arr[start]) ? 1 : 0 };
    }
    else {
        int mid = (start + end) / 2;
        buildSegmentTree(tree, arr, start, mid, 2 * treeNode);
        buildSegmentTree(tree, arr, mid + 1, end, 2 * treeNode + 1);
        tree[treeNode].count = tree[2 * treeNode].count + tree[2 * treeNode + 1].count;
    }
```
3. **Функция countOccurrences:**
- Используется для подсчета количества вхождений заданного значения value на заданном отрезке [start, end] в дереве отрезков.
```cpp
int countOccurrences(vector<SegmentTreeNode>& tree, int treeNode, int start, int end, int value) {
    if (start > end || start > tree[treeNode].end || end < tree[treeNode].start) {
        return 0;
    if (start <= tree[treeNode].start && end >= tree[treeNode].end) {
        return tree[treeNode].count;
```
4. **Функция updateValues:**
- Используется для обновления значений в дереве отрезков.
```cpp
void updateValues(vector<SegmentTreeNode>& tree, int treeNode, int start, int end, int value) {
    if (start > end || start > tree[treeNode].end || end < tree[treeNode].start) {
        return;
    }
    if (tree[treeNode].start == tree[treeNode].end) {
        tree[treeNode].count = (value == tree[start].count) ? 1 : 0;
    }
    else {
        int mid = (tree[treeNode].start + tree[treeNode].end) / 2;
        updateValues(tree, 2 * treeNode, start, end, value);
        updateValues(tree, 2 * treeNode + 1, start, end, value);
        tree[treeNode].count = tree[2 * treeNode].count + tree[2 * treeNode + 1].count;
```
## <p align="center">Результат работы кода.</p>
```cpp
#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int start;
    int end;
    int count;
};

void buildSegmentTree(vector<SegmentTreeNode>& tree, int arr[], int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = { start, end, (arr[start] == arr[start]) ? 1 : 0 };
    }
    else {
        int mid = (start + end) / 2;
        buildSegmentTree(tree, arr, start, mid, 2 * treeNode);
        buildSegmentTree(tree, arr, mid + 1, end, 2 * treeNode + 1);
        tree[treeNode].count = tree[2 * treeNode].count + tree[2 * treeNode + 1].count;
    }
}

int countOccurrences(vector<SegmentTreeNode>& tree, int treeNode, int start, int end, int value) {
    if (start > end || start > tree[treeNode].end || end < tree[treeNode].start) {
        return 0;
    }
    if (start <= tree[treeNode].start && end >= tree[treeNode].end) {
        return tree[treeNode].count;    
    }
    int mid = (tree[treeNode].start + tree[treeNode].end) / 2;
    int leftCount = countOccurrences(tree, 2 * treeNode, start, end, value);
    int rightCount = countOccurrences(tree, 2 * treeNode + 1, start, end, value);
    return leftCount + rightCount;
}

void updateValues(vector<SegmentTreeNode>& tree, int treeNode, int start, int end, int value) {
    if (start > end || start > tree[treeNode].end || end < tree[treeNode].start) {
        return;
    }
    if (tree[treeNode].start == tree[treeNode].end) {
        tree[treeNode].count = (value == tree[start].count) ? 1 : 0;
    }
    else {
        int mid = (tree[treeNode].start + tree[treeNode].end) / 2;
        updateValues(tree, 2 * treeNode, start, end, value);
        updateValues(tree, 2 * treeNode + 1, start, end, value);
        tree[treeNode].count = tree[2 * treeNode].count + tree[2 * treeNode + 1].count;
    }
}

int main() {

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 6;
    int start = 3;
    int end = 7;
    setlocale(LC_ALL, "Russian");
    vector<SegmentTreeNode> tree(4 * size);
    buildSegmentTree(tree, arr, 0, size - 1, 1);

    int occurrences = countOccurrences(tree, 1, start, end, value);
    cout << "Количество вхождений " << value << " на отрезке [" << start << ", " << end << "]: " << occurrences << endl;

    updateValues(tree, 1, start, end, 10);

    cout << "Массив после изменения: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
```
![image](https://github.com/iis-32170x/RPIIS/assets/144334182/b6a17cfe-9fb6-43ca-a98b-ae65ab9c1e44)
## <p align="center">Вывод:</p>
В ходе выполнения работы познакомился созданием дерева отрезков, поиском узлов дерева и взаимодействием с ними.
