# Лабораторная работа № 1

## Вариант 22

## Цель

Цель работы - разработать библиотеку для работы с очередью, обеспечивающую эффективные операции добавления элемента в конец очереди и извлечение элемента из начала очереди. 

### Задание

Реализовать код на языке `С++`, который создает и обрабатывает структуру очередь.

### Ключевые понятия

`Очередь` - структура данных, в которой элементы кладутся в конец, а извлекаются из начала (FIFO). Таким образом, первым из очереди будет извлечен тот элемент, который будет добавлен раньше других.
 
## Оптсание функций

`Реализация структуры очередь` 

```c++
struct stack
{
    int data;
    stack* next;
    stack* prev;
};
```
Где `next`, `prev` - переменные, которые хранят номера следующего и предыдущего элементов очереди, представленной целого числа.
`data` - переменная ,хранящая значение элемета.


`Реализация функци вставки элемента` 

```c++
void add(stack*& begin, stack*& end, int value)
{
    stack* t = new stack;
    t->data = value;
    t->next = NULL;
    t->prev = end;
    end->next = t;
    end = t;
}
```

Необходимо передавать в функцию указатель, т.е. их вызов
должен выглядеть как: `void add(stack*& begin, stack*& end, int value)`;  где `stack*& begin` – начало очереди,  `stack*& end` – конец очереди, `int value` - значение элемента. 


 `Реализация функци изъятия элемента` 

```c++
void del(stack*& begin)
{
    stack* t = begin;
    t = t->next;
    delete del;

}
```
Удаляет первый элемент очереди,где `stack*& begin`-указатель на начало очереди.

`Функция создания очериди`

```c++
void create(stack*& begin, stack*& end, int value)
{
    stack* t = new stack;
    t->data = value;
    t->next = end;
    t->prev = begin;
    begin = end = t;
}
```

Представляет собой функцию создания очереди включающую в себя 1 элемент. `stack*& begin` – начало очереди,  `stack*& end` – конец очереди, `int value` - значение элемента. 


`Функция вывода элементов очереди`

```c++
void view(stack* begin)
{
    stack* t = begin;
    while (t != NULL)
    {
        cout << t->data << endl;
        t = t->next;
    }
    cout << endl;
}
```
Выводит элемениы очереди до тех пор пока существует ненулевой указатель на следующий элемент.`stack* begin`-указатель на начало очереди.

```c++
void delStack(stack** begin)
{
    stack* t;
    while (*begin != NULL)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}
```

Удаляет все элементы очереди и указатели на них начиная с первого до последнего.`stack** begin`-указатель на начало очереди,которое будет меняться в цикле.

`Функция выбора`

```c++
void ftext()
{
    cout << "1-to create queue\n";
    cout << "2-to add elements\n";
    cout << "3-to delete first element\n";
    cout << "4-to see queue\n";
    cout << "5-to clean queue\n";
    cout << "6-to close programm\n";
}
```

Получает число и исходя из него запускает ту или иную функцию.

## Header.h

```c++
#pragma once
struct stack;
void create(stack*& begin, stack*& end, int value);
void add(stack*& b, stack*& e, int value);
void view(stack* p);
void del(stack*& p);
void delStack(stack** p);
void ftext();
```

## functions.cpp*

```c++
#include <iostream>
#include <conio.h>

using namespace std;

struct stack
{
    int data;
    stack* next;
    stack* prev;
};

void create(stack*& begin, stack*& end, int value)
{
    stack* t = new stack;
    t->data = value;
    t->next = end;
    t->prev = begin;
    begin = end = t;
}

void add(stack*& begin, stack*& end, int value)
{
    stack* t = new stack;
    t->data = value;
    t->next = NULL;
    t->prev = end;
    end->next = t;
    end = t;
}

void view(stack* begin)
{
    stack* t = begin;
    while (t != NULL)
    {
        cout << t->data << endl;
        t = t->next;
    }
    cout << endl;
}

void del(stack*& begin)
{
    stack* t = begin;
    t = t->next;
    delete del;

}

void delStack(stack** begin)
{
    stack* t;
    while (*begin != NULL)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}

void ftext()
{
    cout << "1-to create queue\n";
    cout << "2-to add elements\n";
    cout << "3-to delete first element\n";
    cout << "4-to see queue\n";
    cout << "5-to clean queue\n";
    cout << "6-to close programm\n";
}
```

##main.cpp

```c++
#include <iostream>
#include <conio.h>
#include "Header.h"
using namespace std;

int main()
{
    int value;
    stack* begin = NULL;
    stack* end = NULL;

    while (true)
    {
        ftext();
        switch (_getch())
        {
        case '1':
            cout << "first element value\n";
            cin >> value;
            create(begin, end, value);
            break;

        case '2':
            cout << "Num elements?" << endl;
            int k;
            cin >> k;
            cout << "\nElement?\n";
            for (int i = 0; i < k; i++)
            {
                cin >> value;
                add(begin, end, value);
            }
            break;
        case '3':
            del(begin);
            break;
        case '4':
            if (!begin == NULL)
            {
                view(begin);
                cout << endl;

            }
            else
            {
                cout << "\nClean\n";
            }
            break;
        case '5':
            delStack(&begin);
            break;
        case '6':
            exit(0);
            break;
        }
        system("pause");
        system("cls");

    }
    return 0;
}
```

## Вывод
 
В результате выполнения данной работы были получены следующие практические навыки:
- изучение структуры очередь
- умение работать с header-файлами
- изучение базовых алгоритмов для работы со структурами типа очередь   
