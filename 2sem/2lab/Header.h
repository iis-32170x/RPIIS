#pragma once

#include <vector>
#include <string>

using namespace std;

void run_testcase(const string& path, int& num_sets, vector<vector<string>>& sets);
void getcort(const vector<vector<string>>& sets, int cur, int &num_sets,  vector<vector<string>>& cortprod, vector<string>& el);