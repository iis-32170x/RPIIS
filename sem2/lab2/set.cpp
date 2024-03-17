#include "set.h"


string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == string::npos || end == string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

set<string> intersection(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "������ ��� �������� �����.";
        exit(-1);
    }

    string line;
    set<string> result;
    bool firstSet = true;

    while (getline(file, line)) {
       
        line = trim(line);
        line = line.substr(1, line.length() - 2); 

        stringstream ss(line);
        set<string> currentSet;
        string element;

        while (getline(ss, element, ',')) {
            
            element = trim(element);

           
            if (element.find('<') != string::npos) {
                string tuple;
                while (element.find('>') == string::npos) {
                   
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
            firstSet = false;
        }
        else {
            set<string> intersectionSet;
            for (const string& elem : currentSet) {
                if (result.find(elem) != result.end()) {
                    intersectionSet.insert(elem);
                }
            }
            result = intersectionSet;
        }
    }

    file.close();
    return result;
}