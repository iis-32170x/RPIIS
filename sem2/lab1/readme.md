# *Лабораторная работа №1*
## *Вариант 9*
***
### Задача:
Разработать библиотеку для работы с AVL-дерево. Вставка. Удаление. Поиск. Поиск минимума, максимума, ближайшего большего и ближайшего меньшего.
### Цель:
Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных.
### Ключевые понятия: 
___АВЛ-дерево___ — сбалансированное по высоте двоичное дерево поиска: для каждой его вершины высота её двух поддеревьев различается не более чем на 1.
Относительно АВЛ-дерева балансировкой вершины называется операция, которая в случае разницы высот левого и правого поддеревьев = 2, изменяет связи предок-потомок в поддереве данной вершины так, что разница становится <= 1, иначе ничего не меняет. Указанный результат получается вращениями поддерева данной вершины. 
АВЛ — аббревиатура, образованная первыми буквами создателей (советских учёных) Адельсон-Вельского Георгия Максимовича и Ландиса Евгения Михайловича.

Относительно АВЛ-дерева ___балансировкой___ вершины называется операция, которая в случае разницы высот левого и правого поддеревьев = 2, изменяет связи предок-потомок в поддереве данной вершины так, что разница становится <= 1, иначе ничего не меняет. Указанный результат получается вращениями поддерева данной вершины.

___Фактор баланса___ — разница в высоте между правым и левым под-деревом.

### Функции и алгоритмы программы
Создание нового узела дерева с заданным ключом и инициализация его поля:
```c++
Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}
```
Возвращает высоту узла node. Если узел node равен nullptr, то высота считается равной 0.
```c++
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}
```
Вычисляет баланс фактор узла node, который определяется как разность высоты его левого поддерева и высоты его правого поддерева.
```c++
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
```
Обновляет высоту узла node в соответствии с высотами его левого и правого поддеревьев.
```c++
void updateHeight(Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
```
Выполняет правый поворот вокруг узла node. Этот поворот сохраняет свойство AVL-дерева и поддерживает его баланс.
```c++
Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}
```
Проверяет баланс узла node и, при необходимости, выполняет повороты, чтобы восстановить баланс в соответствии с правилами AVL-дерева.
```c++
Node* balance(Node* node) {
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
Вставляет узел с ключом key в дерево, начиная с узла node. При необходимости выполняется балансировка дерева. Вставляет узел с ключом key в дерево, указанное указателем root. Если дерево пустое, устанавливает новый узел в качестве корня.
```c++
Node* insertNode(Node* node, int key) {
    if (node == nullptr) {
        return createNode(key);
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
}

void insert(Node** root, int key) {
    *root = insertNode(*root, key);
}
```
Ищет узел с ключом key в дереве, начиная с корня root. Возвращает true, если узел найден, и false в противном случае.
```c++
bool search(Node* root, int key) {
    Node* current = root;

    while (current != nullptr) {
        if (key == current->key) {
            return true;
        }
        else if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return false;
}
```
Удаляет узел с ключом key из дерева, начиная с узла node. При необходимости выполняется балансировка дерева. Удаляет узел с ключом key из дерева, указанного указателем root. Если узел найден и удален, выполняется балансировка дерева.
```c++
Node* removeNode(Node* node, int key) {
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
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* minRight = findMinNode(node->right);
            node->key = minRight->key;
            node->right = removeNode(node->right, minRight->key);
        }
    }

    return balance(node);
}

bool remove(Node** root, int key) {
    if (*root == nullptr) {
        return false;
    }

    bool keyExists = search(*root, key);

    if (keyExists) {
        *root = removeNode(*root, key);
    }

    return keyExists;
}
```
Находит узел с минимальным ключом в дереве, начиная с узла node. Возвращает минимальный ключ в дереве, указанном корнем root.
```c++
Node* findMinNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

int findMin(Node* root) {
    if (root == nullptr) {
        throw std::runtime_error("The tree is empty");
    }

    Node* minNode = findMinNode(root);
    return minNode->key;
}
```
Находит узел с наименьшим ключом, который больше заданного ключа key в дереве, начиная с узла node. Возвращает наименьший ключ, который больше заданного ключа key в дереве, указанном корнем root.
```c++
Node* findClosestGreaterNode(Node* node, int key) {
    Node* closestGreater = nullptr;
    Node* current = node;

    while (current != nullptr) {
        if (current->key > key) {
            closestGreater = current;
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return closestGreater;
}

int findClosestGreater(Node* root, int key) {
    Node* closestGreaterNode = findClosestGreaterNode(root, key);

    if (closestGreaterNode == nullptr) {
        throw std::runtime_error("No greater key found");
    }

    return closestGreaterNode->key;
}
```
Функция clear рекурсивно очищает память, занятую узлами дерева, начиная с заданного узла node.
```c++
void clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
}
```

### Тест программы 
![тест](https://github.com/iis-32170x/RPIIS/assets/146451109/a68b8fa9-f3a2-4ce6-a645-e0a0dcc7b4d3)
### Вывод:
Цель достигнута. Поставленная задача решена.
***
### Источники: 
[АВЛ-дерво Википедия](https://ru.wikipedia.org/wiki/%D0%90%D0%92%D0%9B-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE#%D0%91%D0%B0%D0%BB%D0%B0%D0%BD%D1%81%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0)

[Создание библиотеки Visual Studio C++](https://www.youtube.com/watch?v=5mD-rhaYF4U )
