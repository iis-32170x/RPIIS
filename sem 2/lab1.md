# Лабораторная работа №1

## Задача:
N-арное дерево. Вставка узла в дерево. Удаление узла из дерева.Отчёт по вот этой штуке c++

Описание:
В данном отчете представлена реализация операций вставки и удаления узлов в N-арном дереве на языке программирования C++. Для этого был создан класс Node, представляющий узел дерева, а также функции insertNode и removeNode, выполняющие соответствующие операции.

Реализация:
### Класс Node:
В начале кода определен класс Node, который представляет узел дерева. Узел содержит значение (value) и вектор указателей на его дочерние узлы (children).

```c++
#include <iostream>
#include <vector>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int val) : value(val) {}
};
```

### Функция вставки узла :
Функция insertNode выполняет операцию вставки нового узла в N-арное дерево. Она принимает указатель на корневой узел дерева, значение родительского узла (parentValue) и значение нового узла (newValue).
```c++
void insertNode(Node* root, int parentValue, int newValue) {
    if (root == nullptr) {
        return;
    }

    if (root->value == parentValue) {
        Node* newNode = new Node(newValue);
        root->children.push_back(newNode);
        return;
    }

    for (Node* child : root->children) {
        insertNode(child, parentValue, newValue);
    }
}
```

### Функция удаления узла:
Функция removeNode выполняет операцию удаления узла из N-арного дерева. Она принимает указатель на корневой узел дерева и значение узла, который нужно удалить (value).
```c++
void removeNode(Node* root, int value) {
    if (root == nullptr) {
        return;
    }

    for (auto it = root->children.begin(); it != root->children.end(); ++it) {
        if ((*it)->value == value) {
            root->children.erase(it);
            return;
        }
        removeNode(*it, value);
    }
}
```

### Пример использования:
Приведенный пример кода демонстрирует использование функций insertNode и removeNode для вставки и удаления узлов в N-арном дереве.
Сначала создается корневой узел с значением 1.
Затем вызывается функция insertNode для вставки новых узлов со значениями 2 и 3 как дочерних узлов корневого узла.
После этого вызывается функция insertNode для вставки новых узлов со значениями 4 и 5 как дочерних узлов узла со значением 2.
Затем вызывается функция removeNode для удаления узла со значением 4.
В конце освобождается память, выделенная для всего дерева, с помощью функции deleteTree.
```c++
int main() {
    Node* root = new Node(1);
    
    insertNode(root, 1, 2);
    insertNode(root, 1, 3);
    insertNode(root, 2, 4);
    insertNode(root, 2, 5);

    removeNode(root, 4);

    // Clean up memory by deleting the entire tree
    deleteTree(root);

    return 0;
}
```
Это результат примера:
[![Screenshot-2024-05-28-144750.png](https://i.postimg.cc/858gDkQr/Screenshot-2024-05-28-144750.png)](https://postimg.cc/kVypvm5n)


# Заключение
Реализованные функции позволяют эффективно вставлять и удалять узлы в N-арном дереве. Для более сложных операций или оптимизаций можно расширить функциональность класса Node и добавить дополнительные методы.
