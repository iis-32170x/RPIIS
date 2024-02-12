#include "symmetric_difference.hpp"
using namespace std;

set<int> symmetric_difference(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Ошибка при открытии файла.";
        exit(-1);
    }
    vector<set<int>> sets;
    sets.emplace_back();
    string number;
    char ch;
    while (file.get(ch)) {
        if (isdigit(ch)) {
            number += ch;
        } else if (ch == ' ' || ch == ',' || ch == '\n') {
            if (!number.empty()) {
                sets.back().insert(stoi(number));
                number.clear();
            }
            if (ch == '\n') {
                sets.emplace_back();
            }
        } else {
            cout << "Ошибка при чтении файла: недопустимый символ." << endl;
            exit(-1); 
        }
    }

    if (!number.empty()) {
        sets.back().insert(stoi(number));
    }

    set<int> result = sets[0];
    for (int i = 1; i < sets.size(); i++) {
        set<int> temp;
        set_symmetric_difference(result.begin(), result.end(),
                                sets[i].begin(), sets[i].end(),
                                inserter(temp, temp.begin()));
        result = temp;
    }
    file.close();
    return result;
}