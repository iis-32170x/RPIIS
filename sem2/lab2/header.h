#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<string> parseString(string str, int start = 0, int finish = -1);
string vectorToString(vector<string> set);

void checkForBrackets(const string& str)
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
        throw runtime_error("Не удалось разобрать: есть незакрытые скобки");
    }

    if (curlyB < 0 || tupleB < 0)
    {
        throw runtime_error("Не удалось разобрать: есть нераскрытые скобки");
    }
}

vector<string> parseString(string str, const int start, int finish)
{
    if (finish == -1)
    {
        finish = str.size() - 1;
    }

    if (str[start] != '{')
    {
        throw runtime_error("Не удалось проанализировать: нет открывающейся скобки в " + to_string(start));
    }

    if (str[finish] != '}')
    {
        throw runtime_error("Не удалось проанализировать: нет закрывающей скобки в " + to_string(finish));
    }

    checkForBrackets(str);

    // Удаляем пробелы
    str.erase(
        remove_if(
            str.begin(), str.end(), [](char ch) { return ch == ' '; }
        ), str.end()
    );

    // Удаляем внешние скобки из строки
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

string vectorToString(vector<string> set)
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

string sortNestedSets(const string& nestedSet)
{
    string sortedSet = nestedSet;
    sortedSet.erase(remove(sortedSet.begin(), sortedSet.end(), '{'), sortedSet.end());
    sortedSet.erase(remove(sortedSet.begin(), sortedSet.end(), '}'), sortedSet.end());

    vector<string> elements;
    stringstream ss(sortedSet);
    string item;
    while (getline(ss, item, ','))
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
    elements.erase(remove_if(elements.begin(), elements.end(),
        [](const string& element)
        {
            return element.empty();
        }),
        elements.end());

    sort(elements.begin(), elements.end());

    sortedSet = "{";
    for (const auto& element : elements)
    {
        sortedSet += element + ",";
    }
    sortedSet.pop_back();
    sortedSet += "}";

    return sortedSet;
}

vector<string> setDifference(const vector<string>& set1, const vector<string>& set2)
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
            string sortedElem = sortNestedSets(elem);

            for (const auto& subsetElem : set2)
            {
                if (subsetElem.substr(0, 1) == "{" && subsetElem.substr(subsetElem.length() - 1, 1) == "}")
                {
                    string sortedSubsetElem = sortNestedSets(subsetElem);

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