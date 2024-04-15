# Лабораторная работа №2 Вариант 9

- `Цель` - Реализовать программу, определяющую является ли одно, либо оба из двух исходных
множеств подмножеством или элементом другого.

## Список ключевых понятий (определения) 
- ` Множество`  - это любая определенная совокупность объектов. Объекты, из которых составлено множество, называются его элементами. Элементы множества различны и отличны друг от друга.
- `Подмножеством` данного множества называется множество, все элементы которого принадлежат данному множеству.

ё## Алгоритм
- **Ввод множеств:**
  - Пользователь выбирает способ ввода элементов множеств: вручную или из файла.
  - Если выбран ввод из файла, запрашивается путь к файлу, из которого будут считываться данные.
- **Ввод элементов множеств:**
  - Для каждого выбранного способа ввода пользователь вводит количество элементов множества и сами элементы.
  - Элементы добавляются в соответствующие векторы.
  - - **Сравнение множеств:**
  - Проверяется, содержит ли множество A все элементы множества B и наоборот.
  - Если оба множества содержат все элементы друг друга, они считаются равными.
  - Если множество B содержит все элементы множества A, но не наоборот, выводится сообщение об этом.
  - Если множество A содержит все элементы множества B, но не наоборот, также выводится соответствующее сообщение.
  - Если ни одно из условий не выполняется, множества считаются не связанными.
- **Вывод результата.**

## Код

### header.h
``` C++
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>


using namespace std;

int input(const string& message);
void ADD(vector<int>& vec, int size);
void read(vector<int>& V, ifstream& file);
bool check(const vector<int>& one, const vector<int>& two);
void print(const vector<int>& V);


```

### main.cpp

``` c++
#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include <string>
using namespace std;

int main() {
    int a, b, c;
    vector<int> A;
    vector<int> B;

    do {
        c = input("Выберите способ ввода (1 - вручную, 2 - из файла): ");
        if (!(c == 1 || c == 2)) {
            cout << "\033[1;31mПовторите ввод: \033[0m";
        }
    } while (!(c == 1 || c == 2));

    if (c == 1) {
        a = input("Введите количество элементов множества A: ");
        ADD(A, a);
        b = input("Введите количество элементов множества B: ");
        ADD(B, b);
    }
    else if (c == 2) {
        string filename;
        ifstream file;
        bool fileOpened = false;
        do {
            cout << "Введите путь к файлу: ";
            cin >> filename;
            file.open(filename);
            if (!file.is_open()) {
                cout << "\033[1;31mОшибка открытия файла\033[0m" << endl;
            }
            else {
                fileOpened = true;
            }
        } while (!fileOpened);
        read(A, file);
        read(B, file);
        file.close();
    }

    cout << "Множество A: ";
    print(A);
    cout << "Множество B: ";
    print(B);

    cout << endl;

    check(A, B);
    return 0;
}
```

### functions.cpp


``` c++
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

// Функция для ввода целого числа с обработкой ошибок
int input(const string& message) {
    int num;
    cout << message;
    // Пока не удалось прочитать число
    while (!(cin >> num)) {
        // Выводим сообщение об ошибке и просим ввести число снова
        cout << "\033[1;31mОшибка ввода! Введите число: \033[0m";
        cin.clear(); // Сбрасываем флаги ошибок
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
    }
    return num;
}

// Функция для добавления элементов в вектор
void ADD(vector<int>& V, int size) {
    int num;
    for (int i = 0; i < size; i++) {
        // Вызываем функцию input для ввода числа с проверкой
        num = input("Введите элемент " + to_string(i + 1) + ": ");
        V.push_back(num);
    }
}

// Функция для чтения данных из файла
void read(vector<int>& V, ifstream& file) {
    int size;
    // Считываем размер вектора
    if (!(file >> size)) {
        cout << "\033[1;31mОшибка чтения файла: неверный формат данных\033[0m" << endl;
        exit(EXIT_FAILURE);
    }

    int num;
    // Считываем элементы вектора из файла
    for (int i = 0; i < size; ++i) {
        if (!(file >> num)) {
            cout << "\033[1;31mОшибка чтения файла: неверный формат данных\033[0m" << endl;
            exit(EXIT_FAILURE);
        }
        V.push_back(num);
    }
}

bool check(const vector<int>& one, const vector<int>& two) {
    bool isSubset = true;
    for (const auto& element : two) {
        if (count(one.begin(), one.end(), element) < count(two.begin(), two.end(), element)) {
            isSubset = false;
            break;
        }
    }

    bool isSuperset = true;
    for (const auto& element : one) {
        if (count(two.begin(), two.end(), element) < count(one.begin(), one.end(), element)) {
            isSuperset = false;
            break;
        }
    }

    if (isSubset && isSuperset) {
        cout << "Множество B является подмножеством множества A, и множество A является подмножеством множества B" << endl;
    }
    else if (isSubset) {
        cout << "Множество B является подмножеством множества A" << endl;
    }
    else if (isSuperset) {
        cout << "Множество A является подмножеством множества B" << endl;
    }
    else {
        cout << "Множества не связвны:ни множество A, ни множество B не являются подмножествами друг друга" << endl;
    }

    return isSubset && isSuperset;
}

// Функция для вывода элементов вектора на экран
void print(const vector<int>& V) {
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}
```
## Пример файла txt из которого происходит чтение множеств
``` txt
 9 3 5 2 6543 1 15
 5 15 9 1
```

## Пример запуска
Вручную:
<img width="694" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/146937124/0c3ee5bb-cc2e-4257-8868-a50317488b85">

Из файла:
<img width="384" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/146937124/e09ac480-fa9f-411d-a1bd-5b84c72f1900">


## Вывод
Разработанная программа успешно выполняет задачу определения того, являются ли исходные множества подмножествами друг друга или содержат их элементы. Это делает программу полезным инструментом для работы с множествами в различных сценариях.
