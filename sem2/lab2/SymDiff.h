#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void runTestcase(string filename, int& num_sets, vector<vector<string>>& sets);
void symDiff(vector<vector<string>>& sets, int cur, int& num_sets, vector<string>& symdiff);