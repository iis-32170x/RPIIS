#include "include.h"

int main() {
    setlocale(LC_ALL, "RU");
    int numElements;
    cout << "Введите количество элементов в множестве: ";
    cin >> numElements;

    PermutationGenerator generator(numElements);
    generator.readInputSet();
    generator.generatePermutations();

    return 0;
}
