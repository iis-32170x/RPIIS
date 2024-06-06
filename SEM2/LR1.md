# Лабораторная работа №1
> ## Постановка задачи
1. Разработать библиотеку для работы со структурой данных, указанной в
индивидуальном задании, на любом императивном языке
программирования (Pascal, C\C++, Java, C#, Python и др.)
2. Разработать тестовую программу, которая демонстрирует
работоспособность реализованной библиотеки работы со структурой
данных.
3. Разработать систему тестов, которые продемонстрировали бы
работоспособность реализованной библиотеки. Система тестов должна
отвечать требованиям полноты, адекватности и непротиворечивости.
Система тестов должна учитывать не только корректную работу на
правильных данных, но и предусматривать корректное завершение
программы в случае некорректных данных.
4. По результатам выполнения задания составить отчет.
> ## Условие первой лабораторной работы (Вариант 6)
Бинарное дерево. Поиск, вставка, удаление
> ## Определения и понятия
+ Дерево представляет собой набор объектов, называемых узлами. Узлы соединены ребрами. Каждый узел содержит значение или данные, и он может иметь или не иметь дочерний узел.Первый узел дерева называется корнем. Если этот корневой узел соединен с другим узлом, тогда корень является родительским узлом, а связанный с ним узел — дочерним. Лист — узел, не имеющий дочерних узлов на дереве.
+ Бинарным (двоичным) деревом называется иерархическая структура данных, в которой каждый узел имеет не более двух дочерних.
+ Бинарное дерево поиска — это бинарное дерево, обладающее дополнительными свойствами: значение левого потомка меньше значения родителя, а значение правого потомка больше значения родителя для каждого узла дерева
___
##  *Разбор алгоритмов основных функций*
Для реализации дерева максимумов будем пользоваться бинарным деревом.

___
> + класс "node", необходимый для хранения данных, ссылок на потомков.
``` c++
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};
```
Где 
+ key - целочисленная переменная для хранения значения узла
+ *left и *right - указатели на левого и правого потомка узла
---
>+ класс дерева, необходим для организации узлов, выполнения операций.
``` c++
class BinarySearchTree { 
private:
    Node* root;
    Node* insert(Node* node, int key); // Функция для вставки ключа, начиная с узла node.
    Node* search(Node* node, int key); // Функция для поиска ключа, начиная с узла node.
    Node* deleteNode(Node* node, int key); // Функция для удаления ключа, начиная с узла node.
    Node* findMin(Node* node); // Функция для нахождения узла с минимальным ключом.
    void destroyTree(Node* node); // Функция для уничтожения дерева, начиная с узла node.
    void inorderTraversal(Node* node); // Функция для обхода дерева в порядке "in-order", начиная с узла node.

```
Функция вставки элемента:
___
``` c++
Node* BinarySearchTree::insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}
```
___
>+ Функция поиска
```c++
Node* BinarySearchTree::search(Node* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}
```
___
>+ Функция удаления:
```c++
Node* BinarySearchTree::deleteNode(Node* node, int key) {
    if (node == nullptr) return node;

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

          Node* temp = findMin(node->right);
          node->key = temp->key;
          node->right = deleteNode(node->right, temp->key);
      }
      return node;
  }
```

___
>+ Функция поиска
```c++
Node* BinarySearchTree::search(Node* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}
```
>+ Header.h:
```c++
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int key);
    Node* search(Node* node, int key);
    Node* deleteNode(Node* node, int key);
    Node* findMin(Node* node);
    void destroyTree(Node* node);
    void inorderTraversal(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int key);
    bool search(int key);
    void deleteKey(int key);
    void destroyTree();
    void inorderTraversal();
};

```
>+Header.cpp:
```c++
#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroyTree();
}

Node* BinarySearchTree::insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

Node* BinarySearchTree::search(Node* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

Node* BinarySearchTree::deleteNode(Node* node, int key) {
    if (node == nullptr) return node;

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

          Node* temp = findMin(node->right);
          node->key = temp->key;
          node->right = deleteNode(node->right, temp->key);
      }
      return node;
  }

  Node* BinarySearchTree::findMin(Node* node) {
      Node* current = node;
      while (current && current->left != nullptr) {
          current = current->left;
      }
      return current;
  } 

  void BinarySearchTree::insert(int key) {
      root = insert(root, key);
  }

  bool BinarySearchTree::search(int key) {
      return search(root, key) != nullptr;
  }
  
  void BinarySearchTree::deleteKey(int key) {
      root = deleteNode(root, key);
  }
  
  void BinarySearchTree::destroyTree(Node* node) {
      if (node) {
          destroyTree(node->left);
          destroyTree(node->right);
          delete node;
      }
  }

  void BinarySearchTree::destroyTree() {
      destroyTree(root);
  }
  
  void BinarySearchTree::inorderTraversal(Node * node) {
      if (node != nullptr) {
          inorderTraversal(node->left);
          std::cout << node->key << " ";
          inorderTraversal(node->right);
      }
  }

  void BinarySearchTree::inorderTraversal() {
      inorderTraversal(root);
      std::cout << std::endl;
  }
  
```
main.cpp:
```c++
#include <iostream>
#include "BinarySearchTree.h"

int main() {

        BinarySearchTree bst;

        int keys[] = { 40, 20, 60, 10, 30, 50, 70, 5, 15, 25, 35, 45, 55, 65, 75 };
        for (int key : keys) {
            bst.insert(key);
        }

        std::cout << "Inorder traversal of the BST: ";
        bst.inorderTraversal();

        std::cout << "Searching for nodes 25 and 65:" << std::endl;
        std::cout << "Node 25: " << (bst.search(25) ? "found" : "not found") << std::endl;
        std::cout << "Node 65: " << (bst.search(65) ? "found" : "not found") << std::endl;

        std::cout << "insert 20 und 60: ";
        bst.insert(20);
        bst.insert(60);
        bst.inorderTraversal();

        std::cout << "Inorder traversal after deletions: ";
        bst.inorderTraversal();

        std::cout << "Deleting nodes 20 and 60:" << std::endl;
        bst.deleteKey(20);
        bst.deleteKey(60);

        std::cout << "Inorder traversal after deletions: ";
        bst.inorderTraversal();

        std::cout << "Final structure of the BST: ";
        bst.inorderTraversal();

    return 0;
}
```

___

##  *Пример выполнения*
//![Img1](https://github.com/iis-32170x/RPIIS/blob/Ходосов_Т/piv.png)
___ 
#Вывод бинарного дерева происходит от середины строки
В результате выполнения данной работы были получены следующие практические навыки:

+ изучение структуры бинарного дерева
+ умение работать с header-файлами
+ изучение базовых алгоритмов для работы со структурами типа дерево максимумов
[Для вопросов, претензий, а также уточнения источников и использованных материалов](https://www.youtube.com/watch?v=dQw4w9WgXcQ&pp=ygUXbmV2ZXIgZ29ubmEgZ2l2ZSB5b3UgdXA%3D)
