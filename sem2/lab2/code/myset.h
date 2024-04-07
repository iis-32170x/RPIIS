#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template <typename T>
struct Node {
    T data;

    int count;

    Node* left;

    Node* right;
};

// обход
template<typename T>
void inorder(Node<T>* r)
{
    if (r == NULL) {
        return;
    }
    inorder(r->left);
    for (int i = 0; i < r->count; ++i) {
        cout << r->data << ", ";
    }
    inorder(r->right);
}

//содержится ли
template<typename T>
int containsNode(Node<T>* r, T d)
{
    if (r == NULL) {
        return 0;
    }
    int x = r->data == d ? r->count : 0;
    return x + containsNode(r->left, d) + containsNode(r->right, d);
}

// вставка
template<typename T>
Node<T>* insert(Node<T>* r, T d)
{
    if (r == NULL) {
        Node<T>* tmp = new Node<T>;
        tmp->data = d;
        tmp->count = 1;
        tmp->left = tmp->right = NULL;
        return tmp;
    }

    if (d < r->data) {
        r->left = insert(r->left, d);
    }
    else if (d > r->data) {
        r->right = insert(r->right, d);
    }
    else {
        r->count++;
    }
    return r;
}

// чтение из файла
void sortSubset(string& subset) {
    // Remove curly braces
    subset = subset.substr(1, subset.size() - 2);

    stringstream ss(subset);
    string element;
    vector<string> elements;

    bool inBrackets = false;
    string currentElement;
    int openBracketsCount = 0;

    while (getline(ss, element, ',')) {
        // Count the number of opening and closing brackets
        openBracketsCount += count(element.begin(), element.end(), '{');
        openBracketsCount -= count(element.begin(), element.end(), '}');

        if (!inBrackets && openBracketsCount > 0) {
            currentElement = element;
            inBrackets = true;
        }
        else if (inBrackets) {
            currentElement += ',' + element;
            if (openBracketsCount == 0) {
                inBrackets = false;
                elements.push_back(currentElement);
                currentElement.clear();
            }
        }
        else {
            elements.push_back(element);
        }
    }

    // сортировка
    for (string& elem : elements) {
        if (elem.front() == '{' && elem.back() == '}') {
            sortSubset(elem); // рекурсивно запускаем если зашли в подмножество
        }
    }
    sort(elements.begin(), elements.end());

    // собираем заново
    subset = "{";
    for (size_t i = 0; i < elements.size(); ++i) {
        subset += elements[i];
        if (i != elements.size() - 1) {
            subset += ",";
        }
    }
    subset += "}";
}





template<typename T>
void addFromFile(Node<T>*& root, const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    T element;
    while (file >> element) {
       
       

        if (element[element.size() - 1] == ',')
            element = element.substr(0, element.size() - 1);

        if (element.front() == '{' && element.back() == '}') {
            sortSubset(element);
        }

        root = insert(root, element);
    }

    file.close();
}
// размер
template<typename T>
int getSize(Node<T>* root)
{
    if (root == nullptr)
        return 0;
    return getSize(root->left) + getSize(root->right) + root->count;
}


template<typename T>
Node<T>* symmetricDifference(Node<T>* root1, Node<T>* root2)
{
    stack<Node<T>*> nodeStack1;
    nodeStack1.push(root1);
    stack<Node<T>*> nodeStack2;
    nodeStack2.push(root2);

    Node<T>* diff = nullptr;

    while (!nodeStack1.empty()) {
        Node<T>* node1 = nodeStack1.top();
        nodeStack1.pop();

        int diffCount = node1->count - containsNode(root2, node1->data);
        for (int i = 0; i < diffCount; ++i) {
            diff = insert(diff, node1->data);
        }

        if (node1->right)
            nodeStack1.push(node1->right);
        if (node1->left)
            nodeStack1.push(node1->left);
    }

    while (!nodeStack2.empty()) {
        Node<T>* node2 = nodeStack2.top();
        nodeStack2.pop();

        int diffCount = node2->count - containsNode(root1, node2->data);
        for (int i = 0; i < diffCount; ++i) {
            diff = insert(diff, node2->data);
        }

        if (node2->right)
            nodeStack2.push(node2->right);
        if (node2->left)
            nodeStack2.push(node2->left);
    }

    return diff;
}

// вывод
template<typename T>
void displaySet(Node<T>* root)
{
    cout << "{ ";
    inorder(root);
    cout << "}" << endl;
}
