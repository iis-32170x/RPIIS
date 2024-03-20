# Лабораторная работа №1

## Цель работы: 

Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных

## Условие лабораторной работы вариант 20:

Дерево сумм. Поиск суммы чисел на отрезке массива. Изменение всех
чисел на отрезке массива на какое-то значение.
## Используемые понятия:
`Массив`-структура данных, хранящая набор значений, идентифицируемых по индексу или набору индексов, принимающих целые значения из некоторого заданного непрерывного диапазона.
Дерево сумм (Sum tree) - это структура данных, которая представляет собой бинарное дерево, где каждая вершина содержит числовое значение. Значение каждой вершины в дереве сумм равно сумме значений всех его потомков.
Дерево сумм обычно используется для эффективного вычисления суммы значений в диапазоне элементов массива или списковых структур. 



## Используемый алгоритм(заголовочная часть):

``` c++
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class SumTree {
private:
    vector<int> tree; 
    int size; 
    int LastBit(int x) {
        return x & (-x);
    }

public:
    SumTree(int n) {
        size = n;
        tree.resize(size + 1, 0);
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += LastBit(index);
        }
    }

    int PrefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= LastBit(index);
        }
        return sum;
    }

    int Sum(int left, int right) {
        return PrefixSum(right) - PrefixSum(left - 1);
    }

    void updateRange(int left, int right, int value) {
        for (int i = left; i <= right; i++) {
            int oldValue = Sum(i, i);
            int diff = value - oldValue;
            update(i, diff);
        }
    }
};


SumTree- класс, который представляет суммационное дерево.
Поля класса:

tree: Вектор, представляющий суммационное дерево. Он используется для хранения сумм значений элементов.
size: Размер дерева, указывающий на количество элементов в дереве.
Методы класса:

SumTree(int n): Конструктор класса, принимающий целое число n и инициализирующий размер дерева и вектор tree с нулевыми значениями.
update(int index, int value): Метод для обновления значения элемента в дереве. Принимает индекс элемента index и значение value, которое нужно добавить к текущему значению элемента.
PrefixSum(int index): Метод для вычисления префиксной суммы от элемента с индексом index. Возвращает сумму всех элементов от начала дерева до заданного индекса index.
Sum(int left, int right): Метод для вычисления суммы элементов в заданном диапазоне индексов от left до right. Использует метод PrefixSum для вычисления суммы.
updateRange(int left, int right, int value): Метод для обновления значения элементов в заданном диапазоне индексов от left до right. Принимает значение value, на которое нужно обновить каждый элемент в диапазоне, и обновляет элементы с помощью метода update.


## Используемый алгоритм(часть main):
``` c++
#include <iostream>
#include <vector>
#include "Header.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int n; 
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n); 
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SumTree tree(n);

    for (int i = 1; i <= n; i++) {
        tree.update(i, arr[i - 1]);
    }

    int left, right; 
    int znachenie; 

    cout << "Введите левую границу интервала: ";
    cin >> left;
    cout << "Введите правую границу интервала: ";
    cin >> right;
    cout << "Введите значение для изменения интервала: ";
    cin >> znachenie;

    int SumDO = tree.Sum(left, right);
    cout << "Сумма на интервале до изменения: " << SumDO << endl;

    tree.updateRange(left, right, znachenie);

    int SumPosle = tree.Sum(left, right);
    cout << "Сумма на интервале после изменения: " << SumPosle << endl;

    return 0;
}

### Результат:
