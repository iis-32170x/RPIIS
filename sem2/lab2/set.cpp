#include "set.h"

string trim(const string& str) {
    string result = str;

 
    size_t start = result.find_first_not_of(" \t\n\r");
    size_t end = result.find_last_not_of(" \t\n\r");
    if (start == string::npos || end == string::npos) {
        return "";
    }
    result = result.substr(start, end - start + 1);


    size_t pos = result.find(" ");
    while (pos != string::npos) {
        result.erase(pos, 1);
        pos = result.find(" ", pos);
    }

    return result;
}

set<string> intersection(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл.";
        exit(-1);
    }

    string line;
    set<string> result;
    bool firstSet = true;
    size_t firstSetMemorySize = 0;

    while (getline(file, line)) {
        line = trim(line);
        line = line.substr(3, line.length() - 4);

        stringstream ss(line);
        set<string> currentSet;
        string element;

        while (getline(ss, element, ',')) {
            element = trim(element);

            if (element.find('{') != string::npos or element.find('<') != string::npos) {
                string tuple;
                while (element.find('}') == string::npos and element.find('>') == string::npos) {
                    tuple += element + ",";
                    getline(ss, element, ',');
                    element = trim(element);
                }
                tuple += element;
                currentSet.insert(tuple);
            }
            else {
                if (!element.empty()) {
                    currentSet.insert(element);
                }
            }
        }

        if (firstSet) {
            result = currentSet;
            firstSetMemorySize = currentSet.size();
            firstSet = false;
        }
        else {
            if (currentSet.size() == firstSetMemorySize) {
                set<string> intersectionSet;
                for (const string& elem : currentSet) {
                    if (result.find(elem) != result.end()) {
                        intersectionSet.insert(elem);
                    }
                }
                result = intersectionSet;
            }
        }
    }

    file.close();
    return result;
}