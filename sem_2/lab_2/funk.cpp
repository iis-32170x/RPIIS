#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

int input(const string& message) {
    int num;
    cout << message;
    while (!(cin >> num)) {
        cout << "\033[1;31mОшибка ввода! Введите число: \033[0m";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

void ADD(vector<int>& V, int size) {
    int num;
    for (int i = 0; i < size; i++) {
        num = input("Введите элемент №" + to_string(i + 1) + ": ");
        V.push_back(num);
    }
}

void read(vector<int>& V, ifstream& file) {
    int size;
    if (!(file >> size)) {
        cout << "\033[1;31mОшибка чтения файла: неверный формат данных\033[0m" << endl;
        exit(EXIT_FAILURE);
    }

    int num;
    for (int i = 0; i < size; ++i) {
        if (!(file >> num)) {
            cout << "\033[1;31mОшибка чтения файла: неверный формат данных\033[0m" << endl;
            exit(EXIT_FAILURE);
        }
        V.push_back(num);
    }
}

bool check(const vector<int>& one, const vector<int>& two) {
    for (int i = 0; i < one.size(); i++) {
        bool m = false;
        for (int s = 0; s < two.size(); s++) {
            if (one[i] == two[s]) {
                m = true;
                break;
            }
        }
        if (!m) {
            return false;
        }
    }
    return true;
}

void print(const vector<int>& V) {
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << endl;
}

