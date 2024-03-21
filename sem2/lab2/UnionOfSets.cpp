#include "UnionOfSets.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void run_testcase(const string& path, int& num_sets, vector<vector<string>>& sets) {
    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        cout << "File is not open\n";
    }
    else {
        file >> num_sets;
        file.ignore();
        sets.resize(num_sets);
        for (int i = 0; i < num_sets; ++i) {
            string line;
            getline(file, line);
            string element;
            for (char c : line) {
                if (c == ' ') {
                    if (!element.empty()) {
                        sets[i].push_back(element);
                        element.clear();
                    }
                }
                else {
                    element += c;
                }
            }
            if (!element.empty()) {
                sets[i].push_back(element);
            }
        }
        file.close();
    }
}

vector<vector<pair<string, int>>> CountMultiplicities(const vector<vector<string>>& sets) {
    vector<vector<pair<string, int>>> counts(sets.size());

    for (int i = 0; i < sets.size(); ++i) {
        vector<string> unique_elements;
        vector<int> element_counts;

        
        for (const string& element : sets[i]) {
            bool found = false;
            
            for (size_t j = 0; j < unique_elements.size(); ++j) {
                if (unique_elements[j] == element) {
                    
                    element_counts[j]++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                unique_elements.push_back(element);
                element_counts.push_back(1);
            }
        }

        
        for (int j = 0; j < unique_elements.size(); ++j) {
            counts[i].push_back(make_pair(unique_elements[j], element_counts[j]));
        }
    }

    return counts;
}


vector<pair<string, int>> FindMaxMultiplicities(const vector<vector<pair<string, int>>>& counts) {
    vector<pair<string, int>> max_counts;

    for (const auto& set : counts) {
        for (const auto& pair : set) {
            bool found = false;
            for (auto& max_pair : max_counts) {
                if (max_pair.first == pair.first) {
                    max_pair.second = max(max_pair.second, pair.second);
                    found = true;
                    break;
                }
            }
            if (!found) {
                max_counts.push_back(pair);
            }
        }
    }

    return max_counts;
}

void OutputResult(const vector<pair<string, int>>& max_counts) {
    cout << "The union of the sets: " << endl;
    for (const auto& pair : max_counts) {
        for (int i = 0; i < pair.second; ++i) {
            cout << pair.first << " ";
        }
    }
    cout << endl;
}
