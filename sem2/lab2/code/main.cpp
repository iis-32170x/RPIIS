#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "mnozh.h"

using namespace std;

int main() {
    setlocale(0, "");
    string fileName;
    cout << "Введите имя файла: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file) {
        cout << "Не удалось открыть файл.\n";
        return 1;
    }

    int numSets;
    file >> numSets;
    string line;
    getline(file, line);

    vector<vector<string>> sets;
    for (int i = 0; i < numSets; i++) {
        getline(file, line);

        string setName;
        istringstream iss(line);
        iss >> setName;

        vector<string> set;
        string element;
        while (iss >> element) {
            if (element.back() == '}') {
                element.pop_back();
            }
            element.erase(remove(element.begin(), element.end(), ','), element.end());
            if (!element.empty()) {
                set.push_back(element);
            }
        }

        sets.push_back(set);
    }

    file.close();

    vector<vector<string>> cartesian = cartesianProduct(sets);

    cout << "Декартово произведение множеств:\n";
    cout << "{";
    for (const auto& set : cartesian) {
        printSet(set);       
    }
    cout << "}";

    return 0;
}
