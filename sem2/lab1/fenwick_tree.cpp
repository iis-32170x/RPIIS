#include <iostream>
#include <vector>
#include "fenwick_tree.hpp"

struct FenwickTree {

    vector<int> tree;
    vector<int> arr;

    FenwickTree(int size)                   //размер дерева фенвика
    {
        tree.resize(size + 1);
        arr.resize(size + 1);
    }

    void update(int idx, int value)         //обновление значения
    {
        while (idx < tree.size())
        {
            tree[idx] += value;
            idx += idx & -idx;
        }
    }


    void updateArr(int idx, int newValue) {
        int diff = newValue - (arr[idx - 1]); // Вычисляем разницу между новым и старым значением
        arr[idx - 1] = newValue; // Обновляем значение в массиве

        update(idx, diff); // Обновляем соответствующий элемент в дереве Фенвика
    }



    int sum(int x) {                        //сумма от 0
        int result = 0;

        while (x > 0) {
            result += tree[x];
            x -= x & -x;
        }

        return result;
    }

    int sum(int l, int r) {                 //сумма на отрезке
        if (l > 0) {
            return sum(r) - sum(l - 1);
        }
        else {
            return sum(r);
        }
    }

};