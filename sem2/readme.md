# Лабораторная работа №1
## Вариант 9
### Задача:
Разработать библиотеку для работы с AVL-дерево. Вставка. Удаление. Поиск. Поиск минимума, максимума, ближайшего большего и ближайшего меньшего.
### Цель:
Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных.
### Ключевые понятия: 
АВЛ-дерево — сбалансированное по высоте двоичное дерево поиска: для каждой его вершины высота её двух поддеревьев различается не более чем на 1.
Относительно АВЛ-дерева балансировкой вершины называется операция, которая в случае разницы высот левого и правого поддеревьев = 2, изменяет связи предок-потомок в поддереве данной вершины так, что разница становится <= 1, иначе ничего не меняет. Указанный результат получается вращениями поддерева данной вершины.
### Функции и методы класса: 
 Поиск значения value в дереве. Возвращает true, если значение найдено, и false, если значение отсутствует.
``` c++
bool AVLTree::search(int value) {
    Node* current = root;

    while (current != nullptr) {
        if (value == current->key) {
            return true; // Значение найдено
        }
        else if (value < current->key) {
            current = current->left; // Идем влево
        }
        else {
            current = current->right; // Идем вправо
        }
    }

    return false;
}
```

 Балансировка дерева относительно узла node.
```c++
AVLTree::Node* AVLTree::balance(Node* node) {
    updateHeight(node);

    if (getBalanceFactor(node) == 2) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    if (getBalanceFactor(node) == -2) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}
```
Вставка нового узла с ключом key в дерево, начиная с узла node. Вставка нового узла с ключом key в дерево.
```c++
AVLTree::Node* AVLTree::insertNode(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }
    else {
        return node;
    }

    return balance(node);

void AVLTree::insert(int key) {
    root = insertNode(root, key);
}
}
```
Удаление узла с ключом key из дерева. Возвращает true, если узел успешно удален, и false, если узел не найден.
```c++
AVLTree::Node* AVLTree::removeNode(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = removeNode(node->right, key);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        }
        else if (node->right == nullptr) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        }
        else {
            Node* minNode = findMinNode(node->right);
            node->key = minNode->key;
            node->right = removeNode(node->right, minNode->key);
        }
    }

    return balance(node);
}

bool AVLTree::remove(int key) {
    if (!search(key)) {
        return false;
    }

    root = removeNode(root, key);
    return true; 
}
```
Поиск минимального ключа в дереве.
```c++
AVLTree::Node* AVLTree::findMinNode(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
int AVLTree::findMin() {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    Node* minNode = findMinNode(root);
    return minNode->key;
}
```
Поиск наименьшего ключа, который больше key в дереве.
```c++
AVLTree::Node* AVLTree::findClosestGreaterNode(Node* node, int key) {
    Node* result = nullptr;

    while (node != nullptr) {
        if (node->key > key) {
            result = node;
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    return result;
}

int AVLTree::findClosestGreater(int key) {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    Node* closestNode = findClosestGreaterNode(root, key);
    if (closestNode == nullptr) {
        throw std::runtime_error("No greater element found");
    }

    return closestNode->key;
}
```
### Тест программы 
![Снимок экрана (9)](https://github.com/iis-32170x/RPIIS/assets/146451109/f424677c-9c2b-4b6c-b090-e92c873b84d3)
### Вывод:
Цель достигнута. Поставленная задача решена.
### Источники: 
https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE#%D0%91%D0%B0%D0%BB%D0%B0%D0%BD%D1%81%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0

https://www.youtube.com/watch?v=5mD-rhaYF4U 
