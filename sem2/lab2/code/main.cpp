#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "mnozh.h"

using namespace std;

int main() {
    string filename;
    cout << "Введите название файла: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return 1;
    }

    string line;
    vector<vector<string>> sets;
    while (getline(inputFile, line)) {

        size_t firstOpeningBracket = line.find_first_of('{');
        size_t lastClosingBracket = line.find_last_of('}');

        if (firstOpeningBracket != string::npos && lastClosingBracket != string::npos) {
            line.erase(firstOpeningBracket, 1);
            line.erase(lastClosingBracket - 1, 1);
        }

        if (isalpha(line[0])) {
            line = line.substr(1);

            if (line[0] == '=') {
                line.erase(0, 1);
            }
        }

        vector<string> set;
        parseSet(line, set);
        sets.push_back(set);
    }

    inputFile.close();

    vector<vector<string>> cartesian = cartesianProduct(sets);

    cout << "Декартово произведение множеств:\n";
    cout << "{ ";
    for (const auto& set : cartesian) {
        printSet(set);
    }
    cout << "}";

    return 0;
}
