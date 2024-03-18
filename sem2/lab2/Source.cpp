#include "Header.h"
int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите количество элементов в множестве: ";
    cin >> n;
    Set generator;
    generator.readSet(n);
    generator.genSet();
    return 0;
}