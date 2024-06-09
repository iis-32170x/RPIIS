#include "exlibr.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

string suffix_array::get_lcp() { 
    string biggest;
    string lcp;
    for (int i = 1; i < suffixes.size(); i++) {
        lcp.clear();
      
        for (int j = 0; j < (suffixes[i].size() > suffixes[i - 1].size() ? suffixes[i - 1].size() : suffixes[i].size()); j++) {
            if (suffixes[i - 1][j] == suffixes[i][j]) {
                lcp += suffixes[i][j];
            }
            if (i == 1) biggest = lcp;
        }
        if (i > 1 && biggest.size() < lcp.size()) biggest = lcp;
    }
    return biggest;
}

void suffix_array::view() {
    for (auto&& str : this->suffixes) { 
        cout << str << endl;
    }
}

suffix_array::suffix_array(string str) { 
    for (int i = 0; i < str.size(); i++) {
        this->suffixes.push_back(string(str.begin() + i, str.end())); 
        this->shifts.push_back(string(str.begin() + i, str.end()).append(str.begin(), str.begin() + i));
        
    }
    sort(suffixes.begin(), suffixes.end()); 
    sort(shifts.begin(), shifts.end());
}

string suffix_array::get_scs() { 
    return shifts.back();
}