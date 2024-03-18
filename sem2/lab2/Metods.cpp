#include "Header.h"
void Set::readSet(int n) {
    cout << "¬ведите элементы множества: ";
    for (int i = 0; i < n; i++) {
        int buff;
        cin >> buff;
        inSet.push_back(buff);
    }
}
void Set::genSet() {
    sort(inSet.begin(), inSet.end());
    do {
        for (int i = 0; i < size(inSet); i++) {
            cout << inSet[i] << " ";
        }
        cout << endl;
    } while (next_permutation(inSet.begin(), inSet.end()));
}