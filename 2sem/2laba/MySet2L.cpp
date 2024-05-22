#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


set<string> symmetricDifference(const vector<set<string>>& sets) {
    set<string> result;
    set<string> temp;

    for (const auto& set : sets) {
        for (const auto& element : set) {
            if (result.count(element) == 0 && temp.count(element) == 0) {
                result.insert(element);
            }
            else {
                result.erase(element);
                temp.insert(element);
            }
        }
        temp.clear();
    }

    return result;
}

int main() {
    setlocale(0, "");
    ifstream inputFile("file.txt");
    vector<set<string>> sets;
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            set<string> currentSet;
            size_t start = line.find('{');
            size_t end = line.rfind('}');

            if (start != string::npos && end != string::npos) {
                string elements = line.substr(start + 1, end - start - 1);
                size_t commaPos = elements.find(',');

                while (commaPos != string::npos) {
                    string element = elements.substr(0, commaPos);
                    currentSet.insert(element);
                    elements = elements.substr(commaPos + 1);
                    commaPos = elements.find(',');
                }
                currentSet.insert(elements);
            }
            sets.push_back(currentSet);
        }
        inputFile.close();
    }
    else
        cout << "Не удалось открыть файл." << endl;

    set<string> symmetricDiff = symmetricDifference(sets);
 
    cout << "Симметрическая разность всех множеств: ";
    cout << "{";
    //bool firstElement = true;
    for (const auto& element : symmetricDiff) {       
        //if (!firstElement) {
          //  cout <<" ";
        //}
        //firstElement = false;  
        cout <<element<<" ";
    }
    cout << "}";
    cout << endl;

    return 0;
}
