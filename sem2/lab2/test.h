#include <iostream>
#include <algorithm>

using namespace std;

class CombinationGenerator {
public:
    int numElements;
    int* elements;

    CombinationGenerator(int elementsCount) : numElements(elementsCount) {
        elements = new int[numElements];
    }

    void readElements() {
        cout << "Введите элементы множества: ";
        for (int i = 0; i < numElements; i++) {
            cin >> elements[i];
        }
    }

    void generateCombinations() {
        int combinationsCount = 0; // Счетчик комбинаций
        do {
            for (int i = 0; i < numElements; i++) {
                cout << elements[i] << " ";
            }
            cout << endl;
            combinationsCount++; // Увеличиваем счетчик при генерации новой комбинации
        } while (next_permutation(elements, elements + numElements));
        cout << "Количество сгенерированных комбинаций: " << combinationsCount << endl; // Выводим количество комбинаций
    }

    ~CombinationGenerator() {
        delete[] elements;
    }
};
