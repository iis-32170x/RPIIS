# Лабораторная работа № 1

## Вариант 4

## Цель

Цель работы - разработать библиотеку для работы с бинарным деревом поиска, обеспечивающую эффективные операции поиска узла в дереве, вставки узла в дерево, удаление узла из дерева, обходы дерева, построение дерева из массива.

### Задание

Реализовать код на языке `С++`, который создает и обрабатывает бинарное дерево поиска.
### Ключевые понятия
`Бинарное дерево` - это иерархическая структура данных, в которой каждый узел имеет не более двух потомков.
`Узел бинарного дерева` - это основная структурная единица бинарного дерева.
## Алгоритм и его реализация
`Реализция структуры узла`
```c++
struct Node {
	int data;
	Node* left;
	Node* right;
	Node* par;

	Node(int val);
};
``` 
Где `data` - число, которое хранит узел, `left` - указатель на левого потомка, `right` - указатель на правого потомка, `par` - родительский узел, `Node(int val)` - метод для создания нового узла

`Реализация бинарного дерева поиска через класс`
```c++
class bst {
private:
	Node* search(Node*, int val);
	Node* Insert(Node* node, int val);
	void bypass(Node*);
	Node* Remove(Node* node, int val);
	Node* min(Node* node);
public:
	Node* root = NULL;
	bool search(int val);
	void Insert(int val);
	void bypass();
	void Remove(int val);
	Node* CreateBSTarr_NotSort(int arr[], int start, int end);
	Node* CreateBSTarr(int arr[], int size);
};
```

`Функция создания нового узла бинарного дерева поиска`
```c++
Node::Node(int val) {
	left = nullptr;
	right = nullptr;
	data = val;
    par = nullptr;
}
```
`Функция поиска узла`
```c++
Node* bst::search(Node* node, int val)
{
    // not found 
    if (node == NULL)
        return NULL;
    // is found
    else if (node->data == val)
        return node;
    // greater
    else if (node->data < val)
        return search(node->right, val);
    // smaller
    else
        return search(node->left, val);
}
```
Функция рекурсивно проходит дерево и при нахождении нужного узла возвращает его. Если функция не находит узел она возвращает NULL.

`Функция добавление узла в дерево`
```c++
Node* bst::Insert(Node* node, int val)
{
    // new
    if(node == NULL)
    {
        node = new Node(val);
        node->left = NULL;
        node->right = NULL;
        node->par = NULL;
    }
    // greater
    else if (val > node->data)
    {
        node->right = Insert(node->right, val);
        node->right->par = node;
    }
    // smaller
    else if (val < node->data)
    {
        node->left = Insert(node->left, val);
        node->left->par = node;
    }
    return node;

}
```
Функция рекурсивно проходит дерево и, дойдя до конца, добавляет элемент функцией Node, после возвращает узел.

`Функция обхода дерева`
```c++
void bst::bypass(Node* node) {
    //stop
    if (node == NULL)
        return;
    //smallest
    bypass(node->left);

    // Print 
    std::cout << node->data << " ";

    bypass(node->right);
}
```
Функция рекурсивно до самого левого узла и после, выводя каждый последующий узел в консоль, проходит до самого правого.

`Функция удаления узла`
```c++
Node* bst::Remove(Node* node, int val) {
    if (node == NULL) {
        return NULL;
    }

    if (val < node->data) {
        node->left = Remove(node->left, val);
    }
    else if (val > node->data) {
        node->right = Remove(node->right, val);
    }
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = min(node->right);
        node->data = temp->data;
        node->right = Remove(node->right, temp->data);
    }

    return node;
}
```
Функция рекурсивно доходит до нужного узла. Если у этого узла есть потомок справа, то функция заменяет текущий узел правым потомком, тоже самое с левым. При наличии двух потомков у данного узла текущий узел заменяется минимальным элементом из правого поддерева. Если функция не находит элемент для удаления возвращается NULL.

 `Функция создания дерева из массива`
 ```c++
Node* bst::CreateBSTarr(int arr[], int size) {
    if (size == 0)
        return NULL;

    root = new Node(arr[0]);

    for (int i = 1; i < size; i++) {
        Insert(root, arr[i]);
    }

    return root;
}
```
Функция за первый элемент дерева берет первый элемент массива. Далее в цикле for проходится по всему массиву, добавляя каждый элемент из него в дерево с помощью функции Insert.


## Результаты тестирования
Проверим нашу программу на примере теста:
`Исходные данные`
Массив с элементами 23, 12, 31, 3, 15, 7, 29, 88, 53.
 `Результат выполнения программы`
![image](https://github.com/iis-32170x/RPIIS/assets/146393417/699de0b5-5781-4495-b298-c82c44aba368)

## Вывод
 
В результате выполнения данной работы были получены следующие практические навыки:
- изучение бинарного дерева поиска
- умение работать с header-файлами
- изучение базовых алгоритмов для работы с бинарными деревьями  
