#include <iostream>
#include <unordered_set>
#include <string>
#include <cctype>

using namespace std;

// Функция для ввода элементов множества
void inputSet(unordered_set<int>& set, const string& setName) {
    string input;
    cout << "Введите элементы множества " << setName << " (введите пустую строку, чтобы завершить ввод):\n";
    while (true) {
        cout << "> ";
        getline(cin, input);
        if (input.empty()) {
            break;
        }
        bool validInput = true;
        for (char c : input) {
            if (!isdigit(c)) {
                validInput = false;
                break;
            }
        }
        if (validInput) {
            int num = stoi(input);
            set.insert(num);
        }
        else {
            cout << "Ошибка: введено некорректное значение. Пожалуйста, введите число.\n";
        }
    }
}

// Функция для вычисления разности двух множеств
unordered_set<int> difference(const unordered_set<int>& set1, const unordered_set<int>& set2) {
    unordered_set<int> diffSet;
    for (const auto& element : set1) {
        if (set2.find(element) == set2.end()) {
            // Если элемент не найден во втором множестве, добавляем его в разность
            diffSet.insert(element);
        }
    }
    return diffSet;
}

// Функция для вывода элементов множества
void printSet(const unordered_set<int>& set, const string& setName) {
    cout << "Элементы множества " << setName << ":\n";
    for (const auto& element : set) {
        // Выводим каждый элемент множества
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    unordered_set<int> set1, set2;

    // Ввод элементов первого множества
    inputSet(set1, "A");

    // Ввод элементов второго множества
    inputSet(set2, "B");

    // Вычисление разности двух множеств
    unordered_set<int> diffSet = difference(set1, set2);

    // Вывод результатов
    printSet(diffSet, "A - B");

    return 0;
}