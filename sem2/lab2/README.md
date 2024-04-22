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
#include <cstring>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node
{
    string data;
    Node* next;
    Node* prev;
};

Node* createNode(const string value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

string trim(const string& str)
{
    size_t start = str.find_first_not_of(" \t\n");
    size_t end = str.find_last_not_of(" \t\n");
    if (start == string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

void add(Node*& begin, Node*& end, const string value)
{
    stringstream ss(value);
    string item;
    bool isCurlyBrace = false;
    bool isAngleBracket = false;

        while (getline(ss, item, ','))
        {
            item = trim(item);
            isCurlyBrace = false;
            isAngleBracket = false;

            if (item.substr(0, 1) == "{")
            {
                string fullItem = item;

                while (item.substr(item.length() - 1, 1) != "}")
                {
                    if (!getline(ss, item, ','))
                    {
                        // Если достигнут конец строки без закрывающей скобки,
                        // считаем текущий элемент полным элементом
                        break;
                    }
                    fullItem += ", " + trim(item);
                }

                item = fullItem;
                isCurlyBrace = true;
            }

            if (item.substr(0, 1) == "<")
            {
                string fullItem1 = item;

                while (item.substr(item.length() - 1, 1) != ">")
                {
                    if (!getline(ss, item, ','))
                    {
                        // Если достигнут конец строки без закрывающей скобки,
                        // считаем текущий элемент полным элементом
                        break;
                    }
                    fullItem1 += ", " + trim(item);
                }

                item = fullItem1;
                isAngleBracket = true;
            }

            if (!item.empty())
            {
                if (item.front() == '{' && item.back() == '}' && !isCurlyBrace)
                {
                    // Если значение начинается и заканчивается фигурными скобками,
                    // записываем его без изменений
                    Node* newNode = createNode(item);
                    if (end == nullptr)
                    {
                        begin = newNode;
                        end = newNode;
                    }
                    else
                    {
                        end->next = newNode;
                        newNode->prev = end;
                        end = newNode;
                    }
                }

                if (item.front() == '<' && item.back() == '>' && !isAngleBracket)
                {
                    // Если значение начинается и заканчивается скобками,
                    // записываем его без изменений
                    Node* newNode = createNode(item);
                    if (end == nullptr)
                    {
                        begin = newNode;
                        end = newNode;
                    }
                    else
                    {
                        end->next = newNode;
                        newNode->prev = end;
                        end = newNode;
                    }
                }
                else
                {
                    // Если значение не содержит фигурные скобки, то разделяем
                    // элементы запятыми и записываем со скобками
                    stringstream subSS(item);
                    string subItem;
                    string fullItem;
                    bool firstItem = true;

                    while (getline(subSS, subItem, ','))
                    {
                        subItem = trim(subItem);
                        if (!firstItem)
                        {
                            fullItem += ", ";
                        }
                        fullItem += subItem;
                        firstItem = false;
                    }

                    Node* newNode = createNode(fullItem);
                    if (end == nullptr)
                    {
                        begin = newNode;
                        end = newNode;
                    }
                    else
                    {
                        end->next = newNode;
                        newNode->prev = end;
                        end = newNode;
                    }
                }
            }
        }
}

void view(Node* begin, Node* end)
{
    Node* t = begin;
    while (t != end)
    {
        cout << t->data << ", ";
        t = t->next;
    }

    if (end)
    {
        cout << t->data;
    }
}

bool areSetsEqual(const string& set1, const string& set2)
{
    vector<char> sortedSet1;
    vector<char> sortedSet2;

    for (char c : set1)
    {
        if (c != '{' && c != '}' && c != ',')
        {
            sortedSet1.push_back(c);
        }
    }
    sort(sortedSet1.begin(), sortedSet1.end());

    for (char c : set2)
    {
        if (c != '{' && c != '}' && c != ',')
        {
            sortedSet2.push_back(c);
        }
    }
    sort(sortedSet2.begin(), sortedSet2.end());

    return sortedSet1 == sortedSet2;
}

string sortString(std::string str)
{
    sort(str.begin() + 1, str.end() - 1);
    return str;
}

void raznost(Node* begin, Node* begin1)
{
    Node* q = begin;
    Node* q1 = begin1;
    unordered_map<string, int> countMap;

    while (q1 != nullptr)
    {
        countMap[q1->data]++;
        q1 = q1->next;
    }

    int regularCount = 0;

    while (q != nullptr)
    {
        bool isSubset = false;
        bool isNumber = false;

        if (q->data.substr(0, 1) == "{" && q->data.substr(q->data.length() - 1, 1) == "}")
        {
            string sortedQ = sortString(q->data);

            for (Node* subsetNode = begin1; subsetNode != nullptr; subsetNode = subsetNode->next)
            {
                if (subsetNode->data.substr(0, 1) == "{" && subsetNode->data.substr(subsetNode->data.length() - 1, 1) == "}")
                {
                    string sortedSubset = sortString(subsetNode->data);

                    if (sortedQ == sortedSubset && countMap[subsetNode->data] != 0)
                    {
                        isSubset = true;
                        countMap[subsetNode->data]--;
                        break;
                    }
                }
            }
        }
        else {
            isNumber = true;
            regularCount++;

            if (countMap[q->data] != 0)
            {
                countMap[q->data]--;
                isSubset = true;
            }
        }

        if (!isSubset)
        {
            cout << q->data << ", ";
        }

        q = q->next;
    }

    for (const auto& pair : countMap)
    {
        if (pair.second == 0 && !pair.first.empty() && pair.first[0] != '{' && pair.first[pair.first.length() - 1] != '}')
        {
            for (int i = 0; i < pair.second; i++)
            {
                cout << pair.first << ", ";
            }
        }
    }
}
```


## Код программы main()
```cpp
#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	string element, stroka, stroka1;
	Node* begin = nullptr;
	Node* end = nullptr;
	Node* begin1 = nullptr;
	Node* end1 = nullptr;

    ifstream inputFile("input_A.txt");
	if (!inputFile)
	{
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}

	while (inputFile >> element)
	{
		stroka += element;
	}

	add(begin, end, stroka);

	inputFile.close();

	Node* p = begin;
	Node* v = end;

	cout << "Множество A: ";
	cout << "{";
	view(p, v);
	cout << "}" << endl;

	ifstream inputFile1("input_B.txt");
	if (!inputFile1)
	{
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}

	while (inputFile1 >> element)
	{
		stroka1 += element;
	}

	add(begin1, end1, stroka1);

	inputFile1.close();

	Node* p1 = begin1;
	Node* v1 = end1;

	cout << endl;
	cout << "Множество B: ";
	cout << "{";
	view(p1, v1);
	cout << "}" << endl;

	cout << endl;
	cout << "Множество C (разность множеств A и B): ";
	cout << "{";
	raznost(begin, begin1);
	cout << "}" << endl;

	return 0;
}
```
