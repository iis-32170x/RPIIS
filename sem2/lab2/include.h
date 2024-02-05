#include <iostream>
#include <algorithm>

using namespace std;

class PermutationGenerator {
public:
    int numElements;
    int* inputSet;

    PermutationGenerator(int elements) : numElements(elements) {
        inputSet = new int[numElements];
    }

    void readInputSet() {
        cout << "¬ведите элементы множества: ";
        for (int i = 0; i < numElements; i++) {
            cin >> inputSet[i];
        }
    }

    void generatePermutations() {
        do {
            for (int i = 0; i < numElements; i++) {
                cout << inputSet[i] << " ";
            }
            cout << endl;
        } while (next_permutation(inputSet, inputSet + numElements));
    }

    ~PermutationGenerator() {
        delete[] inputSet;
    }
};