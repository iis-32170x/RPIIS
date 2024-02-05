# Лабораторная работа №2
## `Вариант 8`
## Задача:
Реализовать программу, формирующую без повторений всевозможные
неориентированные множества из элементов исходного неориентированного множества,
количество элементов в сформированных множествах должно быть равно исходному
натуральному n.
## Цель: 
Изучить основы теории множеств и операций над ними.
## Ключевые понятия:
***`Множество`*** – простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
***`Неориентированное множество`*** – это термин, который обозначает множество элементов, где порядок следования данных элементов не имеет значения. 



```c++
#include <iostream>
#include <algorithm>

using namespace std;

class PermutationGenerator {
public:
    int numElements;
    int* inputSet;

    PermutationGenerator(int elements) : numElements(elements) {
        inputSet = new int[numElements];
    }

    void readInputSet() {
        cout << "Введите элементы множества: ";
        for (int i = 0; i < numElements; i++) {
            cin >> inputSet[i];
        }
    }

    void generatePermutations() {
        do {
            for (int i = 0; i < numElements; i++) {
                cout << inputSet[i] << " ";
            }
            cout << endl;
        } while (next_permutation(inputSet, inputSet + numElements));
    }

    ~PermutationGenerator() {
        delete[] inputSet;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    int numElements;
    cout << "Введите количество элементов в множестве: ";
    cin >> numElements;

    PermutationGenerator generator(numElements);
    generator.readInputSet();
    generator.generatePermutations();

    return 0;
}

```

## Пример выполнения программы:
![Image alt](https://github.com/iis-32170x/RPIIS/blob/Кадиков_П/sem2/lab2/images/results.png)	

Все работает как следует.

## Вывод
Реализовал программу, формирующую без повторений всевозможные неориентированные множества из элементов исходного неориентированного множества, количество элементов в сформированных множествах должно быть равно исходному натуральному n.

## Источники
[drive.google](https://drive.google.com/drive/folders/1SLcF9njDTaNUacXMA9Nrqm7FUS7MnNsI)
