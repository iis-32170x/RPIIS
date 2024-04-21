#include "set.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string file_path = "input.txt";
    const auto result = intersection(file_path);
    cout << "Пересечение  множеств: ";
    cout << "{";
    bool first = true;
    for (const string& element : result) {
        if (!first) {
            cout << ", ";
        }
        cout << element;
        first = false;
    }
    cout << "}";
}