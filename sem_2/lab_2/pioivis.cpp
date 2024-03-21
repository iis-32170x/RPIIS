#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int a, b, c;
    vector<int> A;
    vector<int> B;

    do {
        c = input("Выберите способ ввода(1 - вручную)(2 - из файла): ");
        if (!(c == 1 || c == 2)) {
            cout << "\033[1;31mПовторите ввод: \033[0m";
        }
    } while (!(c == 1 || c == 2));

    if (c == 1) {
        a = input("Введите количество элементов множества A: ");
        ADD(A, a);
        b = input("Введите количество элементов множества B: ");
        ADD(B, b);
    }
    else if (c == 2) {
        string filename;
        ifstream file;
        bool fileOpened = false;
        do {
            cout << "Введите путь к файлу: ";
            cin >> filename;
            file.open(filename);
            if (!file.is_open()) {
                cout << "\033[1;31mОшибка открытия файла\033[0m" << endl;
            }
            else {
                fileOpened = true;
            }
        } while (!fileOpened);
        read(A, file);
        read(B, file);
        file.close();
    }


    cout << "Множество A: ";
    print(A);
    cout << "Множество B: ";
    print(B);

    cout << endl;

    if (check(A, B) && check(B, A)) {
        cout << "Множества A и B равны" << endl;
    }
    else if (check(B, A)) {
        cout << "Все элементы множества B присутствуют в множестве A" << endl;
    }
    else if (check(A, B)) {
        cout << "Все элементы множества A присутствуют в множестве B" << endl;
    }
    else {
        cout << "Множества A и B не связаны" << endl;
    }
    return 0;
}