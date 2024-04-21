#include <iostream>
#include "..\StaticLib\pch.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string filepath;

    cout << "Введите название файла: ";
    getline(cin, filepath);

    int result = print(filepath);  // Замените print на имя вашей функции вывода

    return 0;
}