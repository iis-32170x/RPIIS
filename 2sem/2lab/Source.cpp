#include "Header.h"
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

void getcort (const vector<vector<string>>& sets, int cur, int& num_sets,  vector<vector<string>>& cortprod, vector<string>& el)
{

        for (int i = 0; i < sets[cur].size(); i++)
        {
            
            el.push_back(sets[cur][i]);
           
            if (cur == num_sets-1) 
            {
                cortprod.push_back(el);
        
            }
            else  
            getcort(sets, cur + 1, num_sets,  cortprod, el);
            el.pop_back();
        }
    
}

