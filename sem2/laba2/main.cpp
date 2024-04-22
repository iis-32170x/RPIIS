#include "symmetric_difference.hpp"
using namespace std;

vector<string> symmetricDifference(const vector<string> &set1, const vector<string> &set2) {
    vector<string> diff1 = set_difference(set1, set2);
    // cout << "Результат первой разности: ";
    // for (const string &elem : diff1) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    vector<string> diff2 = set_difference(set2, set1);
    // cout << "Результат второй разности: ";
    // for (const string &elem : diff2) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    return set_union(diff1, diff2);
}

int main() {
    cout << "Введите путь к файлу: ";
    string filepath;
    cin >> filepath;

    vector<string> sets = readSets(filepath);
    if (sets.size() < 2) {
        cout << "В файле должно быть минимум два множества." << endl;
        return 1;
    }
    for (const string &set : sets) {
        if (!bracketsBalance(set)) {
            cout << "Ошибка: неверное расположение скобок в множестве: " << set << endl;
            return 1;
        }
    }
    for (string &set : sets) {
        vector<string> parsedSet = parseString(set);
        removeDuplicatesRecursive(parsedSet);
        string formattedSet = "{";
        for (size_t i = 0; i < parsedSet.size(); ++i) {
            formattedSet += parsedSet[i];
            if (i != parsedSet.size() - 1) formattedSet += ",";
        }
        formattedSet += "}";
        set = formattedSet;
    }
    
    // for (size_t i = 0; i < sets.size(); ++i) {
    //     cout << "Множество " << i + 1 << ": " << sets[i] << endl;
    // }

    vector<string> result = parseString(sets[0]);
    for (size_t i = 1; i < sets.size(); ++i) {
        vector<string> nextSet = parseString(sets[i]);
        result = symmetricDifference(result, nextSet);
    }

    cout << "Результат симметрической разности всех множеств: {";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
    return 0;
}