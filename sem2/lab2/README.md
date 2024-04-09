# Лабораторная работа №2
## `Вариант 8`
## Задача:
Реализовать программу, формирующую без повторений всевозможные
неориентированные множества из элементов исходного неориентированного множества,
количество элементов в сформированных множествах должно быть равно исходному
натуральному n.
## Цель: 
- Изучить основы теории множеств и операций над ними.
- Разроботать программу выполняюую задание
- Написать тест, проверяющий корректность работы программы
- Составит отчет по работе
## Ключевые понятия
- ***Множество*** – простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
- ***Неориентированное множество*** – это термин, который обозначает множество элементов, где порядок следования данных элементов не имеет значения. 
- ***Google C++ Testing Framework*** — библиотека для модульного тестирования на языке C++

## Код:

```c++ Header.h
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Set {
public:
    vector <int> inSet;
    void readSet(int n);
    void genSet();
};
```
```c++ Metods.cpp
#include "Header.h"
void Set::readSet(string set) {
    inSet.clear();
    int n = size(set), open = 1, close = 1;
    if ((set[0] != '<' && set[0] != '{') || (set[n - 1] != '>' && set[n - 1] != '}'))
    {
        cout << "Error";
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if ((set[i - 1] == ',' || set[i - 1] == '<' || set[i - 1] == '{') && set[i] == ',')
        {
            cout << "Error";
            return;
        }
        if ((set[i + 1] == '>' || set[i + 1] == '}') && set[i] == ',')
        {
            cout << "Error";
            return;
        }
        if (close > open)
        {
            cout << "Error";
            return;
        }
    }
    if (close != open)
    {
        cout << "Error";
        return;
    }
    vector<int> buff_vec;
    int buff;
    buff = 0;
    for (int i = 1; i < n; ++i)
    {
        if (set[i] == '<' || set[i] == '{')
        {
            buff_vec.push_back(INT_MIN);
            i++;
            int skob = 1;
            while (skob!=0 )
            {
                if (isdigit(set[i]))
                {
                    int buff = 0;
                    while (isdigit(set[i]))
                    {
                        buff = buff * 10 + (set[i] - '0');
                        ++i;
                    }
                    buff_vec.push_back(buff);
                }
                
                    if (set[i] == '{' || set[i] == '<')
                    {
                        skob++;
                        buff_vec.push_back(INT_MIN);
                    }
                    if (set[i] == '>' || set[i] == '}')
                    {
                        skob--;
                        buff_vec.push_back(INT_MAX);
                    }
           
                i++;
            }
            inSet.push_back(buff_vec);
            buff_vec.clear();
        }
        else if (isdigit(set[i]))
        {
            int buff = 0;
            while (isdigit(set[i]))
            {
                buff = buff * 10 + (set[i] - '0');
                ++i;
            }
            buff_vec.push_back(buff);
            inSet.push_back(buff_vec);
            buff_vec.clear();
        }
    }
}

void Set::genSet() {
    sort(inSet.begin(), inSet.end());
    do {
        for (int i = 0; i < size(inSet); i++) {
            if (inSet[i].size() == 1) {
                cout << inSet[i][0] << " ";
            }
            else {
                //cout << " ";
                for (int j = 0; j < inSet[i].size(); ++j)
                {
                    if (inSet[i][j] == INT_MAX)
                    {
                        cout << ">";
                    }
                    else if (inSet[i][j] == INT_MIN)
                    {
                        cout << "<";
                    }
                    else {
                        cout << inSet[i][j];
                        if (j != inSet[i].size() - 1&& inSet[i][j+1] != INT_MAX) {
                            cout << ",";
                        }
                    }
                }
                cout << " ";
            }
        }
        cout << endl;
    } while (next_permutation(inSet.begin(), inSet.end()));
}
```

## Алгоритм выполнения программы:
1. Чтение множества(ReadSet)
   - Пронимает на вход строку с множеством
   - Проверяет множество на правильно расположенные скобки, запятые и т. д.
   - Заносит элементы множества в вектор
2. Генератор новых множест(genSet)
   - сортирует множество от наименьшего до наибольшего значения
   - выводит множество и увеличивает лексиграфический порядок до тех пор, пока он не станет максимально возможным
## Пример тестирования:
Система тестов состоит из 5 тестов:
1. **SetTest1** - тестирования правильного чтения множества.
   - Проверяет правильно ли считались значения.
2. **SetTest2** - тестирование правильного расставления запятых
   - Проверяет выполняется ли программа если отсутствуют ли запятые перед ковычками, после ковычек, и внутри множества
3. **SetTest2_5** - тестирование правильного расставления скобок
   - Проверяет выполняется программа если отсутствуют скобки по краям
4. **SetTest3** - проверяет вывод функции genSet при вводе: <1,2,3>
   - Перехватывает значения, которые выводит функция genSet
   - Сравнивает эти значения с теми, которые должны быть на выходе
5. **SetTest4** - проверяет вывод функции genSet при вводе : <5,17,2>
   - Перехватывает значения, которые выводит функция genSet
   - Сравнивает эти значения с теми, которые должны быть на выходе
6. **SetTest5** - - проверяет вывод функции genSet при вводе : {1,2,{4,5}}
   - Перехватывает значения, которые выводит функция genSet
   - Сравнивает эти значения с теми, которые должны быть на выходе 

[Код тестирования](https://github.com/iis-32170x/RPIIS/blob/%D0%94%D1%80%D0%B0%D0%BD%D1%8C%D0%BA%D0%BE_%D0%98/sem2/lab2/test.cpp)


![Консоль отладки Microsoft Visual Studio 08 04 2024 21_10_55](https://github.com/iis-32170x/RPIIS/assets/144374775/2e9a5112-ea32-4375-84f9-10f182ad7d62)


## Вывод
Реализовал программу, формирующую без повторений всевозможные неориентированные множества из элементов исходного неориентированного множества.

## Источники
[drive.google](https://drive.google.com/drive/folders/1SLcF9njDTaNUacXMA9Nrqm7FUS7MnNsI)

[Habr](https://habr.com/ru/articles/667880/)
