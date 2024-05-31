#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SetMassiv {
public:
    vector<string> inSet;
    void readSet(string);
    vector<string> MassivOutput();
    void unionSets(vector<string>, vector<string>);
    void printSet();
};