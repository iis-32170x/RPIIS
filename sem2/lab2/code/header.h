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

bool isEqual(std::string e1, std::string e2)
{
    if (e1[0] == '{' ^ e2[0] == '{')
    {
        return false;
    }

    if (e1[0] == '{') 
    {
        auto pe1 = setl::parseString(e1);
        auto pe2 = setl::parseString(e2);
        sort(pe1.begin(), pe1.end());
        sort(pe2.begin(), pe2.end());
        return pe1 == pe2;
    }
    return e1 == e2;
}

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
