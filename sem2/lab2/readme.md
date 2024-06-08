# Лабораторная работа №2 - Разность 2-ух множеств с учётом кратных вхождений
___
## Постановка задачи:
- ***Реализовать алгоритм разности 2-ух множеств с учётом кратных вхождений***
___
## Определение понятий: 
- ***Множество***  - это любая определенная совокупность элементов. Элементы множества различны и отличны друг от друга.
- ***Разность двух множеств*** — теоретико-множественная операция, результатом которой является множество, в которое входят все элементы первого множества, не входящие во второе множество.
___
## Алгоритм

*Из добавленных файлов считывается информация и добавляется в строки line1 & line2. Затем они рзбиваются на эл-ты с помощью parsestring и сохраняются в set1 & set2. Вычисляется разность с помощью ф-ции difference и выводится на экран. При выполнение условия ф-ции check разность 2-ух множеств выводится без исправления, иначе с исправлением.*

***Реализованы следующие функции:***
- ***check()*** - проверяет выполнение условия одинакового кол-ва скобок. Возвращает значение *true* или *false*.

- ***checkforbrakets()*** - работает аналогично ф-ции ***check()***, однако выводит на экран сообщение о незакрытых/нераскрытых скобках.
  
- ***parsestring()*** - считывает входную строку и преобразует ее в вектор строк, где каждый элемент вектора представляет отдельный элемент множества.

- ***vectortoline()*** - принимает вектор строк и преобразует его в строковое представление множества.

- ***sortnestedsets()*** - сортирует элементы вложенного множества в лексикографическом порядке.

- ***difference()*** - вычисляет разность между множествами A и B. 
___
## Скриншоты выполения задания:
![image](https://github.com/iis-32170x/RPIIS/assets/144333910/ab04028b-2f31-4fce-a4c6-d5e1925fb55a)

![image](https://github.com/iis-32170x/RPIIS/assets/144333910/ea9ed391-1465-47e9-968f-831ea6396002)
___
## Код:
### header-file
#pragma once 
#include <iostream> 
#include <algorithm> 
#include <string> 
#include <unordered_map> 
#include <vector> 
#include <unordered_set> 
#include <sstream> 

using namespace std;

vector<string> parsestring(string str, int start = 0, int end = -1);
string vectortoline(vector<string> set);

bool check(const string& str)
{
    int fig = 0;
    int cor = 0;
    for (char ch : str)
    {
        if (ch == '{')
            fig++;
        else if (ch == '}')
            fig--;
        else if (ch == '<')
            cor++;
        else if (ch == '>')
            cor--;
    }
    return (fig == 0 && cor == 0);
}

void checkbrackets(const string& str)
{
    int fig = 0;
    int cor = 0;
    for (char ch : str)
    {
        if (ch == '{')
            fig++;
        else if (ch == '}')
            fig--;
        else if (ch == '<')
            cor++;
        else if (ch == '>')
            cor--;
    }

    if (fig > 0 || cor > 0)
    {
        cout << "Не удалось разобрать: есть незакрытые скобки" << endl << endl;
    }

    if (fig < 0 || cor < 0)
    {
        cout << "Не удалось разобрать: есть нераскрытые скобки" << endl << endl;
    }
}

vector<string> parsestring(string str, const int start, int end)
{
    checkbrackets(str);
    str.erase(remove_if(str.begin(), str.end(), [](char ch) { return ch == ' '; }), str.end());
    str = str.substr(1, str.size() - 2);

    string content;
    vector<string> elements;
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

string vectortoline(vector<string> set)
{
    string str = "{";

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

string sortnestedsets(const string& nestedset)
{
    string sortedset = nestedset;
    sortedset.erase(remove(sortedset.begin(), sortedset.end(), '{'), sortedset.end());
    sortedset.erase(remove(sortedset.begin(), sortedset.end(), '}'), sortedset.end());

    vector<string> elements;
    stringstream ss(sortedset);
    string item;
    while (getline(ss, item, ','))
    {
        elements.emplace_back(item);
    }
    for (auto& element : elements)
    {
        if (element.substr(0, 1) == "{" && element.substr(element.length() - 1, 1) == "}")
        {
            element = sortnestedsets(element);
        }
    }
    elements.erase(remove_if(elements.begin(), elements.end(),
        [](const string& element)
        {
            return element.empty();
        }),
        elements.end());

    sort(elements.begin(), elements.end());

    sortedset = "{";
    for (const auto& element : elements)
    {
        sortedset += element + ",";
    }
    sortedset.pop_back();
    sortedset += "}";

    return sortedset;
}

vector<string>  difference(const vector<string>& set1, const vector<string>& set2)
{
        unordered_map<string, int> countMap;

        for (const auto& elem : set2)
        {
            countMap[elem]++;
        }

        vector<string> difference;

        for (const auto& elem : set1)
        {
            if (elem.substr(0, 1) == "{" && elem.substr(elem.length() - 1, 1) == "}")
            {
                bool isSubset = false;
                string sortedElem = sortnestedsets(elem);

                for (const auto& subsetElem : set2)
                {
                    if (subsetElem.substr(0, 1) == "{" && subsetElem.substr(subsetElem.length() - 1, 1) == "}")
                    {
                        string sortedSubsetElem = sortnestedsets(subsetElem);

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
                    difference.emplace_back(elem);
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
                    difference.emplace_back(elem);
                }
            }
        }

        return difference;
}
___
### main-file 
#pragma once
#include <iostream> 
#include <algorithm> 
#include <string> 
#include <unordered_map> 
#include <vector> 
#include <fstream> 
#include "header.h" 

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1.is_open() || !file2.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 0;
    }

    string line1, line2;
    getline(file1, line1);
    getline(file2, line2);

    file1.close();
    file2.close();

    vector<string> set1, set2;
    set1 = parsestring(line1);
    set2 = parsestring(line2);

    cout << "Множество А: " << vectortoline(set1) << endl << endl;
    cout << "Множество B: " << vectortoline(set2) << endl << endl;
    vector<string> diff = difference(set1, set2);
    if (check(line1) || check(line2))
    {
        cout << "Разность 2-ух множеств: " << vectortoline(diff) << endl;
    }
    else if (!check(line1) || !check(line2))
    {
        cout << "Разность 2-ух множеств c учётом исправления: " << vectortoline(diff) << endl;
    }
    return 0;
}
___
## Вывод
 Реализовал выполнение операции ***разность 2-ух множеств*** .

