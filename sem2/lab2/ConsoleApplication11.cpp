#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;

vector<string> readSets(const string& path) {
    ifstream f(path);
    if (!f.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> sets;
    string buff;

    while (getline(f, buff)) {
        size_t found = buff.find('=');
        if (found != string::npos) {
            string dataAfterEqualSign = buff.substr(found + 1);
            int open = 0, close = 0;

            for (char c : dataAfterEqualSign) {
                if (c == '{' || c == '<') open++;
                if (c == '}' || c == '>') close++;
            }

            if (open != close) {
                cout << "Code is wrong" << endl;
                cout << "Count of '{' not = '}'" << endl;
                exit(EXIT_FAILURE);
            }

            sets.push_back(dataAfterEqualSign);
        }
    }

    return sets;
}

vector<string> writeSets(const vector<string>& sets, int& number) {
    number = sets.size();
    return sets;
}

vector<string> parseSet(const string& input) {
    vector<string> elements;
    size_t pos = 1;
    string buffer;
    int openBraces = 1;

    for (; pos < input.length(); pos++) {
        char c = input[pos];
        if (c == '{' || c == '<') {
            openBraces++;
            if (openBraces == 2 && !buffer.empty()) {
                elements.push_back(buffer);
                buffer.clear();
            }
            buffer += c;
        }
        else if (c == '}' || c == '>') {
            openBraces--;
            if (openBraces > 0) {
                buffer += c;
            }
            if (openBraces == 0) {
                elements.push_back(buffer);
                buffer.clear();
            }
        }
        else if (openBraces == 1) {
            if (c == ',') {
                elements.push_back(buffer);
                buffer.clear();
            }
            else {
                buffer += c;
            }
        }
        else if (openBraces > 0) {
            buffer += c;
        }
    }

    return elements;
}

vector<vector<string>> subsets(const vector<string>& sets) {
    vector<vector<string>> subsets;
    for (const auto& set : sets) {
        subsets.push_back(parseSet(set));
    }
    return subsets;
}

string unionSets(vector<string>& set1, vector<string>& set2) {
    unordered_set<string> unionSet;

    for (const auto& element : set1) {
        unionSet.insert(element);
    }

    for (const auto& element : set2) {
        unionSet.insert(element);
    }

    string result = "{";
    bool isFirstElement = true;

    for (const auto& element : unionSet) {
        if (!isFirstElement) {
            result += ",";
        }
        result += element;
        isFirstElement = false;
    }

    result += "}";
    return result;
}

int main() {
    int sets_q = 0;
    string path = "input.txt";
    auto sets = writeSets(readSets(path), sets_q);
    auto subsetsList = subsets(sets);

    if (sets_q < 2) {
        cout << "Not enough sets for union." << endl;
        return 0;
    }

    string result = unionSets(subsetsList[0], subsetsList[1]);

    for (int i = 2; i < sets_q; i++) {
        auto help_union = parseSet(result);
        result = unionSets(help_union, subsetsList[i]);
    }

    cout << result << " - RESULT" << endl;

    return 0;
}