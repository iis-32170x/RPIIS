# Лабораторная работа №2



# Задача:

Реализовать программу, формирующую множество равное булеану исходного множества.

# Цель:

Ознакомиться с основами графов , способами работы с контейнерами, базовыми алгоритмами для работы с разными видами контейнеров.

## Программная реализация и пример работы

```c++
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <gtest/gtest.h>


using namespace std;

void generateSubsets(const vector<char>& nums, vector<char>& current, int index, vector<vector<char>>& subsets) {
    subsets.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        generateSubsets(nums, current, i + 1, subsets);
        current.pop_back();
    }
}

    vector<vector<char>> subsets(const vector<char>& nums) {
    vector<vector<char>> subsets;
    vector<char> current;
    generateSubsets(nums, current, 0, subsets);

    return subsets;
}

void addCharToArray(vector<char>& arr) {
    char element;
    cout << "Введите символ: ";
    cin >> element;
    arr.push_back(element);
}



int main() {
    setlocale(LC_ALL, "ru");
    vector<char> array;
    int n;
    cout << "Введи колво элементов множества" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введи " << (i + 1) << " элемент" << endl;
        addCharToArray(array);
    }
    vector<char> nums = array;

    vector<vector<char>> allSubsets = subsets(nums);

    cout << "All subsets of { ";
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << ", ";
    cout << "\b\b }:\n";
    cout << "{ ";
    for (const auto& subset : allSubsets) {
        cout << "{";
        for (const auto& num : subset) {
            cout << num << ", ";
        }
        if(subset.size()) cout << "\b\b";
        cout << "}, ";
    }
    cout << "\b\b}";

    return 0;
}
```
# Вывод:

Булеан множества - это множество всех подмножеств данного множества. Он используется для анализа и генерации всех возможных комбинаций элементов, которые могут или не могут присутствовать в исходном множестве. Изучение булеана множества помогает развить навыки работы с множествами и аналитическое мышление.


