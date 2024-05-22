#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> Read(string path) {
    ifstream f;
    f.open(path);
    if (!f.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(0);
    }
    vector<string> sets;
    string buff;
    while (getline(f, buff)) {
        size_t found = buff.find('=');
        if (found != string::npos) {
            string dataAfterEqualSign = buff.substr(found + 1);
            sets.push_back(dataAfterEqualSign);
            cout << "Множество: " << dataAfterEqualSign << endl;

            int open = 0, close = 0;
            for (char ch : dataAfterEqualSign) {
                if (ch == '{' || ch == '<') open++;
                if (ch == '}' || ch == '>') close++;
            }
            if (open != close) {
                cout << "Проверьте правильность ввода!" << endl;
                cout << "Количество '{' не равно количеству '}'" << endl;
                exit(0);
            }
        }
    }
    f.close();
    return sets;
}

vector<string> Write(vector<string> sets, int& number) {
    vector<string> FULLset(sets.size());
    for (int i = 0; i < sets.size(); i++) {
        FULLset[i] = sets[i];
        number++;
    }
    return FULLset;
}

vector<string> Analys(const string& input) {
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
        else {
            buffer += c;
        }
    }
    return elements;
}

vector<vector<string>> subsets(vector<string> sets) {
    vector<vector<string>> subsets;
    for (int i = 0; i < sets.size(); i++) {
        subsets.push_back(Analys(sets[i]));
        for (const auto& element : subsets[i]) {
            cout << element << " ";
        }
        cout << " - Элементы " << i + 1 << " множества." << endl;
    }
    return subsets;
}

string intersection(vector<string>& set1, vector<string>& set2) {
    string result;
    bool isFirstElement = true;

    for (auto it1 = set1.begin(); it1 != set1.end();) {
        bool found = false;
        for (auto it2 = set2.begin(); it2 != set2.end();) {
            if (*it1 == *it2) {
                if (!isFirstElement) {
                    result += ",";
                }
                result += *it1;
                isFirstElement = false;

                it2 = set2.erase(it2);
                found = true;
                break;
            }
            else {
                ++it2;
            }
        }
        if (found) {
            it1 = set1.erase(it1);
        }
        else {
            ++it1;
        }
    }

    if (result.empty()) {
        return "{}";
    }

    return "{" + result + "}";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int sets_q = 0;
    string path = "set.txt";
    auto Sets = Write(Read(path), sets_q);
    auto Subsets = subsets(Sets);

    if (Subsets.size() < 2) {
        cout << "Недостаточно множеств для нахождения пересечения!" << endl;
        return 0;
    }

    string result = intersection(Subsets[0], Subsets[1]);

    for (int i = 2; i < sets_q; i++) {
        auto help_intersec = Analys(result);
        result = intersection(help_intersec, Subsets[i]);
    }

    cout << result << " - РЕЗУЛЬТАТ" << endl;
    return 0;
}