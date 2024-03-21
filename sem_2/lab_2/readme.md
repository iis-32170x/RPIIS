# Лабораторная работа №2 (Вариант 9)

- `Цель` - Реализовать программу, определяющую является ли одно, либо оба из двух исходных
множеств подмножеством или элементом другого.

## Список ключевых понятий (определения) ❓
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

### [header.h](https://github.com/iis-32170x/RPIIS/blob/53d567ba180f1db4b2b2db0e7ffe0d809fbe8346/sem_2/lab_2/funk.cpp).файл)

``` C++
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>

#ifndef PIOIVIS_HEADER_H
#define PIOIVIS_HEADER_H

using namespace std;

int input(const string& message);
void ADD(vector<int>& vec, int size);
void read(vector<int>& V, ifstream& file);
bool check(const vector<int>& one, const vector<int>& two);
void print(const vector<int>& V);

#endif //PIOIVIS_HEADER_H
```

### [pioivis.cpp](https://github.com/iis-32170x/RPIIS/blob/53d567ba180f1db4b2b2db0e7ffe0d809fbe8346/sem_2/lab_2/pioivis.cpp).файл)

``` c++
#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int a, b, c;
    vector<int> A;
    vector<int> B;

    do {
        c = input("Выберите способ ввода(1 - вручную)(2 - из файла): ");
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

    if (check(A, B) && check(B, A)) {
        cout << "Множества A и B равны" << endl;
    }
    else if (check(B, A)) {
        cout << "Все элементы множества B присутствуют в множестве A" << endl;
    }
    else if (check(A, B)) {
        cout << "Все элементы множества A присутствуют в множестве B" << endl;
    }
    else {
        cout << "Множества A и B не связаны" << endl;
    }
    return 0;
}
```

### [funk.cpp](https://github.com/iis-32170x/RPIIS/blob/53d567ba180f1db4b2b2db0e7ffe0d809fbe8346/sem_2/lab_2/funk.cpp).файл)


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
        num = input("Введите элемент №" + to_string(i + 1) + ": ");
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

// Функция для проверки, является ли один вектор подмножеством другого
bool check(const vector<int>& one, const vector<int>& two) {
    for (int i = 0; i < one.size(); i++) {
        bool m = false;
        for (int s = 0; s < two.size(); s++) {
            // Если элемент из первого вектора есть во втором, устанавливаем флаг
            if (one[i] == two[s]) {
                m = true;
                break;
            }
        }
        // Если хотя бы один элемент первого вектора отсутствует во втором, возвращаем false
        if (!m) {
            return false;
        }
    }
    // Если все элементы первого вектора присутствуют во втором, возвращаем true
    return true;
}

// Функция для вывода элементов вектора на экран
void print(const vector<int>& V) {
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}
```
## [tt.txt](https://github.com/iis-32170x/RPIIS/blob/7065d3a347d2e8a2b721c0c560aa9c14d88f6f6c/sem_2/lab_2/tt.txt).Пример файла txt из которого происходит чтение множеств
``` txt
7 6 3 8 1 33 4 5
3 6 4 1
```

## Пример запуска
Вручную:
<img width="1728" alt="Снимок экрана 2024-03-21 в 13 36 32" src="https://github.com/iis-32170x/RPIIS/assets/105926921/4061150e-3129-4250-b7b0-5f44aaec1d69">
Из файла:
<img width="999" alt="Снимок экрана 2024-03-21 в 13 37 24" src="https://github.com/iis-32170x/RPIIS/assets/105926921/c2073af5-5e90-491d-bfa5-83b06312b941">

## Тесты

## Вывод
Разработанная программа успешно выполняет задачу определения того, являются ли исходные множества подмножествами друг друга или содержат их элементы. Это делает программу полезным инструментом для работы с множествами в различных сценариях.
