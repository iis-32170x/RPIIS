# <p align="center">Лабораторная работа №1</p>

Вариант 6. B-Дерево. Поиск. Вставка. Удаление.

## <p align="center">Цели лабораторной работы:</p>
1.Изучить структуру данных B-дерево и его принципы работы.
2.Понять, как B-дерево обеспечивает эффективный поиск, вставку и удаление данных.

## <p align="center">Задачи лабораторной работы:</p>
1.Ознакомиться с основными понятиями B-дерева: порядок, степень, высота.
2.Изучить правила вставки, поиска и удаления в B-дереве.
3.Написать код для создания B-дерева.
4.Реализовать операции поиска, вставки и удаления элементов в B-дереве.

## <p align="center">Список используемых понятий и алгоритмов:</p>
1. Бинарное дерево (или двоичное дерево) — это иерархическая структура данных, в которой каждый узел имеет не более двух потомков (детей). В общем случае, первый узел называется родительским, а его дети — левым и правым наследниками. Двоичное дерево может быть пустым (null) или состоять из данных и двух поддеревьев (каждое из которых также может быть пустым). Если узел имеет оба пустых поддерева, он называется листовым узлом или конечным узлом

## <p align="center">Описание используемых алгоритмов:</p>
1. **Бинарное дерево**

  b_tree представляет собой структуру данных, которая может использоваться для создания бинарных деревьев. В этой структуре z — это значение узла, left и right — указатели на его детей (левого и правого наследника), а height — высота узла в дереве

```cpp
typedef struct b_tree {
    int z;
    struct b_tree* left;
    struct b_tree* right;
}b_tree;
```
2. **Создание бинарного узла**

   функция el создает новый узел с заданным значением i

```cpp
     b_tree* el(int i) {
    b_tree* elem = new b_tree;
    elem->z = i;
    elem->left = NULL;
    elem->right = NULL;
    return elem;
}
```

3. **Функция для вставки элемента в B-дерево**

```cpp
void vst(b_tree* root, b_tree* elem) {
    if (elem->z < root->z) {
        //право
        if (root->left == NULL) {
            root->left = elem;
        }
        else {
            vst(root->left, elem);
        }
    }
    else {
        if (elem->z > root->z) {
            //лево
            if (root->right == NULL) {
                root->right = elem;
            }
            else {
                vst(root->right, elem);
            }
        }
    }
}
```

4. **Функция для поиска элемента в В-дереве**

```cpp
void find(int a, b_tree* root) {
    if (a == root->z)
        cout << "число ", a, " найдено";
        if (a < root->z) {
            //лево
            if (root->left != NULL) {
                find(a, root->left);
            }
            else cout << "число "<< a<<" не найдено";
        }
        else {
            if (a > root->z) {
                //право
                if (root->right != NULL) {
                    find(a, root->right);
                }
                else cout << "число "<< a<< " не найдено";
            }
        }

}
```

5. **Функция для удаления элемента из В-дерева**

```cpp
void udalit(int a, b_tree*& root) {
    if (root!=NULL) {
        if (a == root->z) {
            b_tree* t = root;
            if (root->left == NULL) {
                root = root->right;
            }
            else if (root->right == NULL) {
                root = root->left;
            }
            else {
                b_tree* g = root->right; //поиск замены
                while (g->left != NULL) {
                    g = g->left;
                }
                g->left = root->left;
                root = root->right;
            }
            delete t;
        }
        else if (a < root->z) {
            udalit(a, root->left);
        }
        else {
            udalit(a, root->right);
        }
    }
}
```

6. **Функция для вывода В-дерева**

```cpp
void print(b_tree* root) {
    if (root != NULL) {
        print(root->left);
        cout << root->z << " ";
        print(root->right);
    }
}
```
## <p align="center">Вывод:</p>
В рамках данной лабораторной работы были изучены понятие бинарные деревья и базовые операции над ними. 

