#include "test.h"

int main() {
    setlocale(LC_ALL, "RU");
    int elementsCount;
    cout << "Введите количество элементов множества: ";
    cin >> elementsCount;

    CombinationGenerator generator(elementsCount);
    generator.readElements();
    generator.generateCombinations();

    return 0;
}
