#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main() {
    setlocale(0, "");
    Node* front = nullptr;
    Node* rear = nullptr;

    int choice;
    string element;

    while (true) {
        cout << "Меню:" << endl;
        cout << "1) Добавить элемент" << endl;
        cout << "2) Посмотреть очередь" << endl;
        cout << "3) Взять элемент" << endl;
        cout << "4) Очистка очереди" << endl;
        cout << "5) Закрыть программу" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент для добавления (q для возврата в меню): ";
            cin.ignore();
            getline(cin, element);
            while (element != "q") {
                enqueue(front, rear, element);
                cout << "Введите следующий элемент (q для возврата в меню): ";
                getline(cin, element);
            }
            break;
        case 2:
            printQueue(front);
            break;
        case 3:
            if (!isEmpty(front)) {
                string value = dequeue(front, rear);
                if (value != "") {
                    cout << "Взятый элемент: " << value << endl;
                }                
            }
            else {
                cout << "Очередь пуста." << endl;
            }
            break;
        case 4:
            clearQueue(front, rear);
            break;
        case 5:
            cout << "Программа закрыта." << endl;
            return 0;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите существующий пункт меню." << endl;
            break;
        }
    }

    return 0;
}
