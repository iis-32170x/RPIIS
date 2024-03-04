#include<iostream>
#include <conio.h>
#include<string>
#include "ПИОИВИС лаб1.h"
#include <vector>
using namespace std;

MyQueue::MyQueue() {
    last = begin = nullptr;
}

MyQueue::~MyQueue() {
    while (begin != nullptr) {
        QueueElement* tmp = begin;
        begin = begin->prev;
        delete tmp;
    }
}

bool MyQueue::Check() {
    return (begin == nullptr);
}

void MyQueue::Push(std::string information) {
    QueueElement* tmp = new QueueElement;
    tmp->inf = information;
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
    while (tmp != nullptr) {
        std::cout << "(" << tmp->inf << ") ";
        tmp = tmp->prev;
    }
    if (begin != nullptr) {
        std::cout << "<- хвост очереди";
    }
    std::cout << "\nнажмите любую клавишу, чтобы выйти из просмотра : ";
    while (!_kbhit()) {
    }
    _getch();
    system("cls");
}

std::string MyQueue::Pop() {
    if (Check()) {
        std::string popinf;
        return popinf;
    }
    else {
        std::string popinf = begin->inf;
        QueueElement* tmp = begin;
        begin = begin->prev;
        delete tmp;
        return popinf;
    }
}

void MyQueue::HeadElemenetToTail() {
    std::vector <std::string> infomation = { "молоко","хлеб","мука","сырок","вода","батон" };
    for (auto& c : infomation) {
        Push(c);
    }
    std::cout << "Очередь : ";
    View();
    Push(Pop());
    std::cout << "Переделанная очередь : ";
    View();
}

int main() {
    setlocale(LC_ALL, "ru");
    MyQueue queue;
    int choice = 0, choice2 = 0, choice3 = 0, choice4 = 0;
    string elm;
    string popinf;
    do {
        cout << "Выберите действие\n"
            << "1.Перейти к обычному меню\n"
            << "2.Перейти к методу перемещающему элемент из головы очереди в хвост\n";
        getline(cin, elm);
        if (elm.size() == 1) {
            if (elm[0] == '1') {
                choice4 = 1;
            }
            else if (elm[0] == '2') {
                choice4 = 2;
            }
        }
        system("cls");
        elm.clear();
    } while (choice4 == 0);
    if (choice4 == 1) {
        // Обычное меню
        do {
            do {
                choice = 0;
                cout << "Выберите действие\n"
                    << " 1.Добавление\n"
                    << " 2.Взятие элемента\n"
                    << " 3.Просмотр очереди\n"
                    << " 4.Выйти"
                    << endl;
                getline(cin, elm);
                if (elm.size() == 1) {
                    if (isdigit(elm[0])) {
                        choice = stoi(elm);
                    }
                }
                system("cls");
                elm.clear();
            } while (choice == 0);
            switch (choice) {
            case 1:
                // Добавление элементов в очередь
                do {
                    system("cls");
                    do {
                        cout << "Введите информацию : ";
                        getline(cin, elm);
                        system("cls");
                    } while (elm.empty());
                    queue.Push(elm);
                    elm.clear();
                    do {
                        choice2 = 0;
                        cout << "Выберите действие\n"
                            << " 1.Добавить еще\n"
                            << " 2.Больше не добавлять\n"
                            << endl;
                        getline(cin, elm);
                        if (elm.size() == 1) {
                            if (elm[0] == '1') {
                                choice2 = 1;
                            }
                            else if (elm[0] == '2') {
                                choice2 = 2;
                            }
                        }
                        system("cls");
                        elm.clear();
                    } while (choice2 == 0);
                } while (choice2 != 2);
                break;
            case 2:
                // Извлечение элемента из очереди
                popinf = queue.Pop();
                if (!popinf.empty()) {
                    do {
                        choice3 = 0;
                        cout << "Выберите действие \n"
                            << "1.Добавить взятый элемент в конец очереди \n"
                            << "2.Удалить взятый элемент\n"
                            << endl;
                        getline(cin, elm);
                        if (elm.size() == 1) {
                            if (elm[0] == '1') {
                                choice3 = 1;
                            }
                            else if (elm[0] == '2') {
                                choice3 = 2;
                            }
                        }
                        system("cls");
                        elm.clear();
                    } while (choice3 == 0);
                    system("cls");
                    switch (choice3) {
                    case 1:
                        // Добавление извлеченного элемента в конец очереди
                        queue.Push(popinf);
                        cout << "Элемент добавлен в конец очереди ";
                        cout << "\nнажмите любую клавишу, чтобы продолжить : ";
                        while (!_kbhit()) {
                        }
                        _getch();
                        system("cls");
                        break;
                    case 2:
                        // Удаление извлеченного элемента
                        cout << "элемент был удален";
                        cout << "\nнажмите любую клавишу, чтобы продолжить : ";
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
                    cout << "\nнажмите любую клавишу, чтобы продолжить : ";
                    while (!_kbhit()) {
                    }
                    _getch();
                    system("cls");
                }
                break;
            case 3:
                // Просмотр очереди
                cout << "Очередь : ";
                queue.View();
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
        // Вызов метода перемещения элемента из головы в хвост
        queue.HeadElemenetToTail();
    }
    return 0;
}
