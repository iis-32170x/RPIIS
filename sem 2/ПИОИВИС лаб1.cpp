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

