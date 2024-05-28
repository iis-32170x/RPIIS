#pragma once

#include <vector>
#include <string>

using namespace std;

void sozdmn(const string& path, int& num_sets, vector<vector<string>>& sets);
void dekpr(const vector<vector<string>>& sets, int cur, int& num_sets, vector<vector<string>>& cortprod, vector<string>& el);