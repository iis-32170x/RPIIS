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

string sortString(string str)
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
        else 
        {
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
}
