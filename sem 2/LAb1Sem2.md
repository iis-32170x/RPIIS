# Работа с очередью в C++

При выполнении задания по работе с очередью вы будете использовать концепции и алгоритмы, связанные с основными операциями с очередью.

## Цель задания:
Цель задания заключается в освоении работы с очередью, включая вставку элемента в очередь и извлечение элемента из очереди.

## Концепции:
- **Очередь (Queue):**
  - Очередь представляет собой структуру данных, работающую по принципу FIFO (First In, First Out).
- **Вставка элемента (Enqueue) и извлечение элемента (Dequeue):**
  - Вставка элемента в очередь (enqueue) происходит путем добавления нового элемента в конец очереди.
  - Извлечение элемента из очереди (dequeue) осуществляется путем удаления элемента из начала очереди.

## Алгоритмы:
- **Алгоритм вставки в очередь:**
  - При использовании массива для реализации очереди, вставка элемента включает добавление элемента в конец массива.
  - При использовании связанного списка, вставка элемента подразумевает добавление нового узла в конец списка.
- **Алгоритм извлечения из очереди:**
  - Для извлечения элемента из очереди нужно удалить элемент из начала очереди и обновить указатель на начало очереди.
  - При использовании массива, извлечение может включать смещение всех элементов на одну позицию влево.
  - При использовании связанного списка, извлечение может включать удаление первого узла и обновление указателя на начало списка.

Эти концепции и алгоритмы помогут вам эффективно выполнять операции с очередью и понимать их применение в различных алгоритмах и приложениях.
## Пример работы с очередью на C++
# ([cpp](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%B0%D0%B4%D1%87%D0%B5%D0%BD%D0%BA%D0%BE_%D0%9D/sem%202/%D0%9F%D0%98%D0%9E%D0%98%D0%92%D0%98%D0%A1%20%D0%BB%D0%B0%D0%B11.cpp).файл)
# ([header](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%B0%D0%B4%D1%87%D0%B5%D0%BD%D0%BA%D0%BE_%D0%9D/sem%202/%D0%9F%D0%98%D0%9E%D0%98%D0%92%D0%98%D0%A1%20%D0%BB%D0%B0%D0%B11.h).файл)
```cpp
#include<iostream>
#include <conio.h>
#include<cctype>
#include<string>
#include "ПИОИВИС лаб1.h"
#include <vector>
using namespace std;



MyQueue::MyQueue() {
    last = begin = NULL;
}

MyQueue::~MyQueue() {
    while (begin != nullptr) {
        QueueElement* tmp = begin;
        begin = begin->prev;
        delete tmp;
    }
}

bool MyQueue::Check() {
    return(begin == NULL);
}

void MyQueue::Push(int value) {
    QueueElement* tmp = new QueueElement;
    tmp->el = value;
    tmp->prev = nullptr;

    if (begin == nullptr) {
        begin = last = tmp;
    }
    else {
        last->prev = tmp;
        last = tmp;
    }
}

void MyQueue::View() {
    QueueElement* tmp = begin;
    system("cls");
    cout << "Очередь : ";
    while (tmp != nullptr) {
        cout << tmp->el << " ";
        tmp = tmp->prev;
    }
}

int MyQueue::Pop() {
    if (Check()) {
        return 1234567;
    }
    else {
        int popel = begin->el;
        QueueElement* tmp = begin;
        begin = begin->prev;
        delete tmp;
        return popel;
    }
}

void MyQueue::HeadElemenetToTail() {
    setlocale(LC_ALL, "ru");
    int mass[] = { 1,2,3,4,5 };
    for (int c : mass) {
        Push(c);
    }
    cout << "Очередь : ";
    View();
    Push(Pop());
    cout << "Переделанная очередь : ";
    View();
}

int main() {
    setlocale(LC_ALL, "ru");
    MyQueue queue;
    int choice = 0, choice2 = 0, choice3 = 0, choice4 = 0, popel = 0, el = 0;
    bool digit = true;
    bool size = false;
    string elm;

    do {
        cout << "Выбирете действие\n"
            <<"1.Перейти к обычному меню\n"
            <<"2.Перейти к методу перемещающему элемент из головы очереди в хвост\n";
        cin >> elm;
        digit = true;
        size = false;
        for (char c : elm) {
            if (!isdigit(c)) {
                digit = false;
            }
        }
        if (digit && elm.size() < 2) {
            if (stoi(elm) == 2 || stoi(elm) == 1) {
                choice4 = stoi(elm);
                size = true;
            }
        }
        elm.clear();
        system("cls");
    } while (!digit || !size);
    if (choice4 == 1) {
        do {
            do {
                cout << "выбирете действие\n"
                    << " 1.Добавление\n"
                    << " 2.Взятие элемента\n"
                    << " 3.Просмотр очереди\n"
                    << " 4.Выйти"
                    << endl;
                cin >> elm;
                digit = true;
                size = false;
                for (char c : elm) {
                    if (!isdigit(c)) {
                        digit = false;
                    }
                }
                if (digit && elm.size() < 2) {
                    choice = stoi(elm);
                    size = true;
                }
                elm.clear();
                system("cls");
            } while (!digit || !size);
            switch (choice) {
            case 1:
                do {
                    do {
                        system("cls");
                        cout << "Введите элемент : ";
                        cin >> elm;
                        digit = true;
                        size = false;
                        for (char c : elm) {
                            if (!isdigit(c)) {
                                digit = false;
                            }
                        }
                        if (digit && elm.size() < 6) {
                            el = stoi(elm);
                            size = true;
                        }
                        elm.clear();
                    } while (!digit || !size);
                    system("cls");
                    queue.Push(el);
                    do {
                        cout << "Выбирете действие\n"
                            << " 1.Добавить еще\n"
                            << " 2.Больше не добавлять\n"
                            << endl;
                        cin >> elm;
                        digit = true;
                        size = false;
                        for (char c : elm) {
                            if (!isdigit(c)) {
                                digit = false;
                            }
                        }
                        if (digit && elm.size() < 2) {
                            if (stoi(elm) == 1 || stoi(elm) == 2) {
                                choice2 = stoi(elm);
                                size = true;
                            }
                        }
                        elm.clear();
                        system("cls");
                    } while (!digit || !size);
                } while (choice2 != 2);
                break;
            case 2:
                popel = queue.Pop();
                if (popel != 1234567) {
                    do{
                    cout << "Выбирете действие \n"
                        << "1.Добавть взятый элемент в конец очереди \n"
                        << "2.Удалить взятый элемент\n"
                        << endl;
                    cin >> elm;
                    digit = true;
                    size = false;
                    for (char c : elm) {
                        if (!isdigit(c)) {
                            digit = false;
                        }
                    }
                    if (digit && elm.size() < 2) {
                        if (stoi(elm) == 1 || stoi(elm) == 2) {
                            choice3 = stoi(elm);
                            size = true;
                        }
                    }
                    elm.clear();
                    system("cls");
                } while (!digit || !size);                   
                system("cls");
                    switch (choice3) {
                    case 1:
                        queue.Push(popel);
                        cout << "Элемент добавлен в конец очереди ";
                        cout << "\nнажмите любую клавишу что бы продолжить : ";
                        while (!_kbhit()) {
                        }
                        _getch();
                        system("cls");
                        break;
                    case 2:
                        cout << "элемент был удален";
                        cout << "\nнажмите любую клавишу что бы продолжить : ";
                        while (!_kbhit()) {
                        }
                        _getch();
                        system("cls");
                        break;
                    default: cout << "Неправильный выбор \n";
                    }
                }
                else {
                    cout << "очередь пустая";
                    cout << "\nнажмите любую клавишу что бы продолжить : ";
                    while (!_kbhit()) {
                    }
                    _getch();
                    system("cls");
                }
                break;
            case 3:
                queue.View();
                cout << "\nнажмите любую клавишу что бы выйти из просмотра : ";
                while (!_kbhit()) {
                }
                _getch();
                system("cls");
                break;
            case 4:
            {
                break;
            }
            default:cout << "Неправильный выбор\n";
            }
        } while (choice != 4);
    }
    else {
        queue.HeadElemenetToTail();
    }
    return 0;
}
```
## Алгоритм работы программы

### Определение класса MyQueue:
- В классе `MyQueue` определены приватные элементы `last` и `begin`, представляющие последний и первый элементы очереди соответственно.
- В классе определена структура `QueueElement`, которая представляет собой элемент очереди.

### Конструктор и деструктор класса `MyQueue`:
- Конструктор класса `MyQueue` инициализирует указатели `last` и `begin` как `nullptr`.
- Деструктор освобождает память, выделенную для элементов очереди.

### Методы `Push`, `Pop`, `View`:
- Метод `Push` добавляет элемент в конец очереди.
- Метод `Pop` извлекает элемент из начала очереди.
- Метод `View` выводит содержимое очереди на экран.

### Функция `main()`:
- В функции `main()` создается объект класса `MyQueue`.
- В цикле `do-while` пользователю предлагается выбрать действие (добавление, извлечение, просмотр очереди или выход).
- В зависимости от выбора пользователя выполняются соответствующие операции с очередью.
- Для добавления элемента в конец очереди используется цикл `do-while`.
- После каждого действия пользователю предлагается выбрать следующее действие.
- Пользователь может выйти из программы, выбрав соответствующий пункт меню.
  # Работа с очередью,вывод

Очередь - это структура данных, в которой элементы упорядочены по принципу "первым пришел, первым вышел" (FIFO - First-In-First-Out). Это означает, что элементы добавляются в конец очереди и удаляются из ее начала.

## Операции с очередью

### Вставка элемента в очередь

Для вставки элемента в очередь вы используете операцию, которая называется "enqueue" или "встать в очередь". Элемент добавляется в конец очереди. Если очередь заполнена, то возможно ожидание, пока место в очереди не освободится.

### Взятие элемента из очереди

Для взятия элемента из очереди вы используете операцию, которая называется "dequeue" или "выйти из очереди". Элемент извлекается из начала очереди. Если очередь пуста, то операция извлечения может привести к ошибке или вернуть специальное значение, указывающее на пустую очередь.



