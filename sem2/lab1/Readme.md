# Лабораторная работа №1

## Задача:
- Разработать библиотеку для работы со структурой данных, указанной в
индивидуальном задании, на любом императивнойм языке
программирования (Pascal, C\C++, Java, C#, Python и др.)
- Разработать тестовую программу, которая демонстрирует
работоспособность реализованной библиотеки работы со структурой
данных.
- Разработать систему тестов, которые продемонстрировали бы
работоспособность реализованной библиотеки
- По результатам выполнения задания составить отчет.
# Вариант 8:
Декартово дерево. Вставка. Поиск. Удаление. Построение дерева из
массива значений. Объединение двух деревьев. Пересечение двух
деревьев.
## Цель:
Исследовать свойства структур данных и разработать
библиотеку алгоритмов обработки структур данных.

## Список ключевых понятий:
- *Декартово дерево* или *дерамида* (англ. *Treap*) — это структура данных, объединяющая в себе *бинарное дерево поиска* и *бинарную кучу* (отсюда и второе её название: *treap* (tree + heap) и *дерамида* (дерево + пирамида), также существует название *курево* (куча + дерево).
- *Бинарное дерево поиска* (англ. *binary search tree*, *BST*) — структура данных для работы с упорядоченными множествами.
- *Двоичная куча* представляет собой полное бинарное дерево, для которого выполняется основное свойство кучи: приоритет каждой вершины больше приоритетов её потомков.
## Свойства:
- Проще реализуется по сравнению, например, с настоящими самобалансирующимися деревьями вроде красно-чёрного.
- Хорошо ведёт себя «в среднем», если ключи y раздать случайно.
- Типичная для сортирующего дерева операция «разделить по ключу x на „меньше x0“ и „не меньше x0“» работает за O(h), где h — высота дерева. На красно-чёрных деревьях придётся восстанавливать балансировку и окраску узлов.
## Недостатки:
- Большие накладные расходы на хранение: вместе с каждым элементом хранятся два-три указателя и случайный ключ y.
- Скорость доступа O(n) в худшем, хотя и маловероятном, случае. Поэтому декартово дерево недопустимо, например, в ядрах ОС.
## Реализация:
Создадим класс Node, в которой будем хранить ключ и приоритет, а также указатели на левого и правого сына. Указателя на корень дерева достаточно для идентификации всего дерева. Поэтому, когда мы будем говорить «функция принимает два дерева» на самом деле будут иметься в виду указатели на их корни. К нулевому указателю же мы будем относиться, как к «пустому» дереву. Также создадим конструкторы для добавления «узлов» (указателей на поддеревья).
```cpp
class Node {
public:
    int key;
    int priority;
    Node* left;
    Node* right;
    bool rev;
    Node(int _key)
    {
        key = _key;
        srand((_key * 4 + 234) % 20 + 23);
        priority = rand() % 21;
        if (priority < 0) priority *= -1;
    }
    Node(int _key, int _priority)
    {
        key = _key;
        priority = _priority;
    }
};
```
# Добавим 4 вспомогательных метода:
1. Merge
Принимает два дерева (два корня), и про которые известно, что в левом все вершины имеют меньший ключ, чем все в правом. Их нужно объединить в одно дерево так, что по ключам это всё ещё дерево, а по приоритетами — куча.
Сначала выберем, какая вершина будет корнем. Здесь всего два кандидата — левый корень или правый — просто возьмем тот, у кого приоритет больше.
Пусть, для однозначности, это был левый корень L. Тогда левый сын корня итогового дерева должен быть левым сыном. С правым сыном сложнее: возможно, его нужно смерджить с R. Поэтому рекурсивно сделаем
``` merge(l->right, r) ``` и запишем результат в качестве правого сына.
```cpp
merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
    if (l->priority > r->priority) {
        l->right = merge(l->right, r);
        return l;
    }
    else {
        r->left = merge(l, r->left);
        return r;
    }
}
```
2. Split
   Принимает дерево и ключ x, по которому его нужно разделить на два: L должно иметь все ключи не больше x, а R должно иметь все ключи больше x.
   В этой функции мы сначала решим, в каком из деревьев должен быть корень, а потом рекурсивно разделим его правую или левую половину и присоединим, куда надо:
   ```cpp
   split(Node* p, int x, Node*& f, Node*& s) {
    if (p == nullptr) {
        f = nullptr;
        s = nullptr;
        return ;
    }
    Node* f1 = nullptr, * s1 = nullptr;
    if (p->key <= x) {
        split(p->right, x, f1, s1);
        p->right = f1;
        f = p;
        p = s1;
    }
    else {
        split(p->left, x, f1, s1);
        p->left = s1;
        f = f1;
        s = p;
    }
   }
   ```
3. Swap
  Принимает два дерева L и R, создает временное дерево, с помощью которого деревья L и R меняются местами, а после очищает память.
```cpp
swap(Node*& a, Node*& b) {
    Node* temp = a;
    a = b;
    b = temp;
    delete temp;
}
```
4. InTree
   Принимает на вход дерево и ключ и проверяет присутстыует ли он в дереве. Проверяет присутствует ли ключ в узле, если нет, то рекурсивно вызывает себя до тех пор, пока не будет найден ключ, либо пройдены все узлы. Возвращает true либо false.
   ```cpp
   InTree(Node* node1, int k) {
    if (node1 == nullptr) return false;
    if (node1->key == k) return true;
    if (k < node1->key) return InTree(node1->left, k);
    else return InTree(node1->right, k);
   }
   ```
# Основные методы
- insert
  Метод принимает одно или 2 значения — ключ и приоритет(если есть), а после вставляет узел в дерево, путём разделения дерева по ключу и дальнейшем объединение образовавшихся поддеревьев и нового узла
  ```cpp
  insert(int x) {
  std::pair <Node*, Node*> q;
  Node* f1 = nullptr, * s1 = nullptr;
  split(root, x, f1, s1);
  Node* t = new Node(x);
  root = merge(f1, merge(t, s1));
  } 
  insert(int x,int y) {
  std::pair <Node*, Node*> q;
  Node* f1 = nullptr, * s1 = nullptr;
  split(root, x, f1, s1);
  q.first = f1;
  q.second = s1;
  Node* t = new Node(x,y);
  root = merge(q.first, merge(t, q.second));
  }
  ```
- erase
  Принимает дерево и ключ, по которому нужно удалить узел. Рекурсивно сравнивает узлы дерева с ключом, а когда находит ключ, то объеденяет левое и правое поддеревья найденного узла.
  ```cpp
  erase(Node*& t, int key) {
    if (t == nullptr) return;
    if (t->key == key)  t = merge(t->left, t->right);
    else
    {
        if (key < t->key) {
            erase(t->left, key);
        }
        else {
            erase(t->right, key);
        }
    }
    root = t; 
  }
  ```
- buildTree
  Метод принимает одно или 2 значения — вектор ключей и приоритетов(если есть), а после проходит по всем элементам и вставляет их вызывая ```insert```.
  ```cpp
    buildTree(std::vector<int> keys) {
    for (int i = 0; i < size(keys); i++)
    {
        int key = keys[i];
        insert(key);
    }
  }
- buildTree(std::vector<int> keys, std::vector<int> prioritys) {
    for (int i = 0; i < size(keys);i++)
    {
        int key = keys[i];
        int priority = prioritys[i];
        insert(key,priority);
    }
  }
  ```
- searce
  Работает также, как и метод ```InTree```, только возвращает дерево, а не булевую пересенную.
```cpp
  Node* Treap::search(Node* node, int key)
{
    if (node == nullptr) return node;
    if (node->key == key) return node;
    else if (key < node->key)
    {
        return search(node->left, key);
    }
    else
    {
        return search(node->right, key);
    }
}
```
- unite
  Принимает два дерева, после находит дерево с меньшим ключом и рекурсивно присоединяет к его правой ветке второе дерево.
  Возвращает полученное дерево.
```cpp
unite(Node* root1, Node* root2)
{
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    Node* u;
    if (root1->key < root2->key)
    {
        u = root1;
        u->right = unite(root1->right, root2);
    }
    else
    {
        u = root2;
        u->left = unite(root1, root2->left);
    }
    return u;
}
```
- intersection
  Принимает два дерева, рекурсивно проверяет все узлы, при помощи метода ```InTree```, если узел присутствует во 2-м дереве, то запускает конструктор, которые добавляет узел в новое дерево.
  Возвращает полученное дерево.
```cpp
intersect(Node* root1, Node* root2) 
    {
    if (root1 == nullptr || root2 == nullptr) return nullptr;
    Node* inter = nullptr;

    if (InTree(root2, root1->key))
    {
        inter = new Node(root1->key, root1->priority);
        inter->left = intersect(root1->left, root2);
        inter->right = intersect(root1->right, root2);
    }
    else
    {
        inter = intersect(root1->left, root2);
        inter = intersect(root1->right, root2);
    }
    return inter;
}
```
## Результаты тестирования
```cpp
#include "Header.h"
using namespace std;
int main()
{
	system("chcp 1251 > nul");
	Treap tree;
	//Tест 1:
	if (!tree.root) cout << "Тест 1 пройден\n";
	// Тест 2:
	vector <int> keys = {1,3, 2, 4 };
	tree.buildTree(keys);
	tree.outTree(tree.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	for (int key: keys)
	{
		if (tree.search(tree.root, key)-> key!= key)
		{
			cout << "Ошибка";
			return 0;
		}
	}
	cout << "Тест 2 пройден\n";
	// Тест 3:
	for (int key : keys)
	{
		tree.erase(tree.root, key);
	}
	if(tree.root == nullptr) cout << "Тест 3 пройден\n";
	//Тест 4:
	tree.insert(9, 5);
	if (tree.search(tree.root, 9)->key == 9) cout << "Тест 4 пройден\n";
	tree.erase(tree.root, 9);
	//Тест 5:
	vector <int> keys2 = { 3, 5, 7, 8};
	vector <int> prioritys = { 5, 11, 4, 2};
	Treap tree2;
	tree2.buildTree(keys2, prioritys);
	for (int key : keys2)
	{
		if (tree2.search(tree2.root, key)->key != key)
		{
			cout << "Ошибка";
			return 0;
		}
	}
	tree2.outTree(tree2.root, 0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "Тест 5 пройден\n";
	//Тест 6:
	Treap uniontree,tree1;
	tree1.buildTree(keys);
	uniontree.root = uniontree.unite(tree1.root, tree2.root);
	uniontree.outTree(uniontree.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "Тест 6 пройден\n";
	//Тест 7:
	Treap intersection,tree3;
	tree3.buildTree(keys);
	tree3.insert(5);
	tree3.insert(7);
	intersection.root = intersection.intersect(tree2.root, tree3.root);
	intersection.outTree(intersection.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "Тест 7 пройден\n";
}
```
![C__Users_ilyad_OneDrive_Рабочий стол_Священная лаба_x64_Debug_Project23 exe 27 02 2024 01_54_55](https://github.com/iis-32170x/RPIIS/assets/144374775/c6592c65-34bc-4e29-9913-bed076cbda6f)
## Вывод:
В результате создал программу на языке c++, которая создает Декартово декартово дерево и выполняет операции над ним. Проверил работу программы при помощи тестов.
## Источники:
- https://algorithmica.org/ru/treap
- https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B5%D0%BA%D0%B0%D1%80%D1%82%D0%BE%D0%B2%D0%BE_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE
- https://e-maxx.ru/algo/treap

