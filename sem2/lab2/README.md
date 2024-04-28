# Лабораторная работа №2 Вариант 13

- `Цель` - Реализовать программу, определяющую разность двух исходных множеств.

## Список ключевых понятий (определения) 
- ` Множество`  - это любая определенная совокупность объектов. Объекты, из которых составлено множество, называются его элементами. Элементы множества различны и отличны друг от друга.
- `Разность двух мноожеств` — теоретико-множественная операция, результатом которой является множество, в которое входят все элементы первого множества, не входящие во второе множество.
  
## Алгоритм
- **Создание списка и чтение элементов множества A из файла "input_A.txt":**-

- Открыть файл "input_A.txt" с помощью ifstream и проверить, удалось ли открыть файл.
- Инициализировать пустую строку stroka.
- Считывать элементы из файла, добавлять их в строку stroka.
- Закрыть файл "input_A.txt".

- **Создание списка и чтение элементов множества B из файла "input_B.txt"**:

- Открыть файл "input_B.txt" с помощью ifstream и проверить, удалось ли открыть файл.
- Инициализировать пустую строку stroka1.
- Считывать элементы из файла, добавлять их в строку stroka1.
- Закрыть файл "input_B.txt".

- **Вычисление разности множеств A и B:**

- Реализуется функция raznost(), которая принимает указатели на начало списков A и B.
- Внутри raznost():
- Пройти по элементам списка A.
- Для каждого элемента из списка A проверить, есть ли он в списке B.
- Если элемент отсутствует в списке B, добавить его в список C (разность множеств A и B).
- Вывести элементы списка C.

- **Вывод результатов:**

- Вывести содержимое множества A.
- Вывести содержимое множества B.
- Вывести разность множеств A и B (множество С).

- **Завершение программы.**

## Код программы библиотеки функций

```cpp
#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

namespace setl
{

    std::vector<std::string> parseString(std::string str, int start = 0, int finish = -1);

    std::string vectorToString(std::vector<std::string> set);

};

void checkForBrackets(const std::string& str) 
{
    int curlyB = 0;
    int tupleB = 0;
    for (char ch : str) 
    {
        if (ch == '{') curlyB++;
        else if (ch == '}') curlyB--;
        else if (ch == '<') tupleB++;
        else if (ch == '>') tupleB--;
    }

    if (curlyB > 0 || tupleB > 0)
    {
        throw std::runtime_error("Не удалось разобрать: есть незакрытые скобки");
    }

    if (curlyB < 0 || tupleB < 0)
    {
        throw std::runtime_error("Не удалось разобрать: есть нераскрытые скобки");
    }
}

std::vector<std::string> setl::parseString(std::string str, const int start, int finish) 
{
    if (finish == -1)
    {
        finish = str.size() - 1;
    }

    if (str[start] != '{')
    {
        throw std::runtime_error("Не удалось проанализировать: нет открывающейся скобки в " + std::to_string(start));
    }

    if (str[finish] != '}')
    {
        throw std::runtime_error("Не удалось проанализировать: нет закрывающей скобки в " + std::to_string(finish));
    }

    checkForBrackets(str);

    // Удаляем пробелы
    str.erase(
        std::remove_if(
            str.begin(), str.end(), [](char ch) { return ch == ' '; }
        ), str.end()
    );

    // Удаляем внешние скобки из строки
    str = str.substr(1, str.size() - 2);

    std::string content;
    std::vector<std::string> elements;
    int depth = 0;
    for (int i = 0; i <= str.size(); i++) 
    {
        if (str[i] == '<' || str[i] == '{') 
        {
            depth++;
            content += str[i];
        }
        else if (str[i] == '>' || str[i] == '}') 
        {
            depth--;
            content += str[i];
        }
        else if (depth != 0 || (str[i] != ',' && str[i] != '\0')) 
        {
            content += str[i];
        }
        else 
        {
            elements.emplace_back(content);
            content = "";
        }
    }

    return elements;
}

std::string setl::vectorToString(std::vector<std::string> set) 
{
    std::string str = "{";

    for (int i = 0; i < set.size(); i++) 
    {
        str += set[i];
        if (i != set.size() - 1) 
        {
            str += ", ";
        }
    }
    str += "}";
    return str;
}

std::string sortNestedSets(const std::string& nestedSet) 
{
    std::string sortedSet = nestedSet;
    sortedSet.erase(std::remove(sortedSet.begin(), sortedSet.end(), '{'), sortedSet.end());
    sortedSet.erase(std::remove(sortedSet.begin(), sortedSet.end(), '}'), sortedSet.end());

    std::vector<std::string> elements;
    std::stringstream ss(sortedSet);
    std::string item;
    while (std::getline(ss, item, ',')) 
    {
        elements.push_back(item);
    }

    // Рекурсивная сортировка элементов вложенных множеств
    for (auto& element : elements) 
    {
        if (element.substr(0, 1) == "{" && element.substr(element.length() - 1, 1) == "}") 
        {
            element = sortNestedSets(element);
        }
    }

    // Удаляем пустые множества из элементов
    elements.erase(std::remove_if(elements.begin(), elements.end(),
        [](const std::string& element) 
        {
            return element.empty();
        }),
        elements.end());

    std::sort(elements.begin(), elements.end());

    sortedSet = "{";
    for (const auto& element : elements) 
    {
        sortedSet += element + ",";
    }
    sortedSet.pop_back();
    sortedSet += "}";

    return sortedSet;
}

std::vector<std::string> setDifference(const std::vector<std::string>& set1, const std::vector<std::string>& set2) 
{
    std::unordered_map<std::string, int> countMap;

    for (const auto& elem : set2) 
    {
        countMap[elem]++;
    }

    std::vector<std::string> difference;

    for (const auto& elem : set1) 
    {
        if (elem.substr(0, 1) == "{" && elem.substr(elem.length() - 1, 1) == "}") 
        {
            bool isSubset = false;
            std::string sortedElem = sortNestedSets(elem);

            for (const auto& subsetElem : set2) 
            {
                if (subsetElem.substr(0, 1) == "{" && subsetElem.substr(subsetElem.length() - 1, 1) == "}") 
                {
                    std::string sortedSubsetElem = sortNestedSets(subsetElem);

                    if (sortedElem == sortedSubsetElem && countMap[subsetElem] > 0) 
                    {
                        countMap[subsetElem]--;
                        isSubset = true;
                        break;
                    }
                }
            }

            if (!isSubset) 
            {
                difference.push_back(elem);
            }
        }
        else 
        {
            if (countMap[elem] > 0) 
            {
                countMap[elem]--;
            }
            else 
            {
                difference.push_back(elem);
            }
        }
    }

    return difference;
}
```


## Код программы main()
```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"


int main() {
    std::ifstream file1("input_A.txt");
    std::ifstream file2("input_B.txt");

    if (!file1.is_open() || !file2.is_open()) 
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 0;
    }

    std::string setString1, setString2;
    std::getline(file1, setString1);
    std::getline(file2, setString2);

    file1.close();
    file2.close();

    std::vector<std::string> set1, set2;
    set1 = setl::parseString(setString1);
    set2 = setl::parseString(setString2);

    std::cout << "Множество А: " << setl::vectorToString(set1) << std::endl << std::endl;
    std::cout << "Множество B: " << setl::vectorToString(set2) << std::endl << std::endl;

    std::vector<std::string> difference = setDifference(set1, set2);

    std::cout << "Множество С (разность А и В): " << setl::vectorToString(difference) << std::endl;

    return 0;
}
```

*****
## <p align="center">Тесты:</p>
![результат тестов](https://github.com/iis-32170x/RPIIS/tree/%D0%93%D0%BE%D1%80%D1%8F%D1%87%D0%B5%D0%B2_%D0%98/sem2/lab2/tests)
******
## <p align="center">Вывод:</p>
В ходе выполнения работы познакомился с понятием "Множество" и операцией над множествами "Разность. Создал библиотеку, реализующую структуру данных множество и выполняющую операцию разности.
