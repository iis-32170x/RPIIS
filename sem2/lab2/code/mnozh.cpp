#include <iostream>
#include <vector>
#include <string>
#include "mnozh.h"

using namespace std;

vector<vector<string>> cartesianProduct(const vector<vector<string>>& sets) {
    vector<vector<string>> result;
    vector<string> currentSet;

    cartesianProductRecursive(sets, result, currentSet, 0);

    return result;
}

void cartesianProductRecursive(const vector<vector<string>>& sets, vector<vector<string>>& result, vector<string>& currentSet, int index) {
    if (index == sets.size()) {
        result.push_back(currentSet);
        return;
    }

    for (const auto& element : sets[index]) {
        currentSet.push_back(element);
        cartesianProductRecursive(sets, result, currentSet, index + 1);
        currentSet.pop_back();
    }
}

void parseSet(const string& line, vector<string>& set) {
    string element;
    int nestedLevel = 0;

    for (char c : line) {
        if (c == '{') {
            nestedLevel++;
        }
        else if (c == '}') {
            nestedLevel--;
        }

        if (c == ',' && nestedLevel == 0) {
            set.push_back(element);
            element.clear();
        }
        else {
            element += c;
        }
    }

    if (!element.empty()) {
        set.push_back(element);
    }
}

void printSet(const vector<string>& set) {
    cout << "<";
    for (size_t i = 0; i < set.size(); i++) {
        cout << set[i];
        if (i != set.size() - 1) {
            cout << ",";
        }
    }
    cout << "> ";
}
