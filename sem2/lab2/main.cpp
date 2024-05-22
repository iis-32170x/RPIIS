
#include "pch.h"




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string file_path = "input.txt";
    const auto result = union_sets(file_path);
    cout << "Объединение множеств: ";
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
