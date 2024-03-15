# Лабораторная работа №1
**Вариант №2**    
Множество. Добавление элемента во множество. Удаление элемента из
множества. Поиск элемента во множестве. Объединение двух
множеств. Пересечение двух множеств.
## Цели лабораторной работы:
1. Разработать библиотеку для работы с очередью  на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.
   
## Задачи лабораторной работы
1. Изучить спецификацию задачи по работе с множествами.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для работы с множествами, включая операции вставки и удаления элементов.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## Список используемых понятий:
1. **Множество** - набор, совокупность каких-либо объектов
2. **Объединением множеств А и В** называется множество, содержащее все элементы, принадлежащие либо множеству А, либо В, либо им обоим
3. **Пересечением множеств А и В** называется множество, состоящее из всех элементов, принадлежащих одновременно каждому из множеств
А и В.

## Описание используемых алгоритмов:

1. **Добавление элемента в множество**
   
   Функция Add добавляет новый элемент в множество. Если элемент уже присутствует, он не будет добавлен повторно, так как множество содержит только уникальные элементы.
```cpp
void Add(Branch*& current, int value) {
    if (!current) {
        current = new Branch(value);
        return;
    }
    else if (value < current->data) {
        Add(current->left, value);
    }
    else if (value > current->data) {
        Add(current->right, value);
    }
}
```
2. **Удаление элемента из множества**
   
   Функция findMinNode осуществляет поиск наименьшего элемента, который используется в removeNode для замены значения удаляемого элемента, а затем удаления этого наименьшего элемента из дерева.
```cpp
Branch* findMinNode(Branch* node) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (node->left == nullptr) {
        return node;
    }
    else {
        return findMinNode(node->left);
    }
}

void removeNode(Branch*& current, int value) {
    if (current == nullptr) {
        return;
    }
    if (value < current->data) {
        removeNode(current->left, value);
    }
    else if (value > current->data) {
        removeNode(current->right, value);
    }
    else {
        if (current->left == nullptr) {
            Branch* temp = current;
            current = current->right;
            delete temp;
        }
        else if (current->right == nullptr) {
            Branch* temp = current;
            current = current->left;
            delete temp;
        }
        else {
            Branch* minRight = findMinNode(current->right);
            current->data = minRight->data;
            removeNode(current->right, minRight->data);
        }
    }
}
```
3. **Поиск элемента в множестве**

   Функция FindElem выполняет поиск указанного элемента в множестве. Если элемент найден, функция возвращает указатель на соответствующий элемент. Если элемент не найден, возвращается значение nullptr.
```cpp
Branch* FindElem(Branch* node, int value) {
    if (!node) {
        cout << "Элемент не найден. ";
        return nullptr;
    }
    if (node->data == value) {
        cout << "Элемент найден. ";
        return node;
    }
    if (node->data < value) {
        return FindElem(node->right, value);
    }
    else {
        return FindElem(node->left, value);
    }
}
```
4. **Вывод множества на экран**
   
   Функция print выполняет обход в порядке "левый-корень-правый" и выводит элементы в порядке возрастания.
```cpp
void print(Branch* node) {
    if (!node) {
        return;
    }
    print(node->left);
    std::cout << node->data << " ";
    print(node->right);
}
```
5. **Объединение двух множеств**
   
   Функция Union выполняет объединение двух множеств. Она создает новое множество и добавляет в него все элементы из обоих исходных множеств. Функция UnionAdd является вспомогательной функцией, которая используется в функции Union для добавления всех элементов из одного множества в другое.
```cpp
void UnionAdd(Branch*& current, Branch*& mnozhC) {
    if (!current) {
        return;
    }
    Add(mnozhC, current->data);
    UnionAdd(current->right, mnozhC);
    UnionAdd(current->left, mnozhC);
}

void Union(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
    if (mnozhA) {
        UnionAdd(mnozhA, mnozhC);
    }
    if (mnozhB) {
        UnionAdd(mnozhB, mnozhC);
    }
}
```
6. **Пересечение двух множеств**
   
   Функция Intersection использует функцию proverka для выполнения операции пересечения между двумя бинарными деревьями mnozhA и mnozhB. Функция proverka выполняет поиск значения value в дереве mnozhB и добавляет его в дерево mnozhC, если оно присутствует.
```cpp
void proverka(int value, Branch* node, Branch*& mnozhC) {
    if (!node) {
        return;
    }
    if (node->data == value) {
        Add(mnozhC, value);
        return;
    }
    proverka(value, node->left, mnozhC);
    proverka(value, node->right, mnozhC);
}

void Intersection(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
    if (!mnozhA) {
        return;
    }
    proverka(mnozhA->data, mnozhB, mnozhC);
    Intersection(mnozhA->left, mnozhB, mnozhC);
    Intersection(mnozhA->right, mnozhB, mnozhC);
}
```
## Тесты:

## Вывод:
В ходе выполнения работы познакомился созданием библиотек в С++, реализоавал библиотеку работы с массивами,а также создал систему тестов,которая проверяет корректность созданной библиотеки, отточил свои навыки в создании структур и функций.

## Используемые источники:
1. [Литература](https://drive.google.com/drive/folders/1rJjlVms04Betx1EkAgaek2xNpHV6c_1j)
2. [Создание библиотеки](https://www.youtube.com/watch?v=pAxEfF2yVlM&t=1s)
