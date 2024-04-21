#ifndef HEADER_H
#define HEADER_H

#include<vector>
#include<string>

using namespace std;

void cartesianProductRecursive(const vector<vector<string>>& sets, vector<vector<string>>& result, vector<string>& currentSet, int index);
vector<vector<string>> cartesianProduct(const vector<vector<string>>& sets);
void printSet(const vector<string>& set);
vector<vector<int>> createSets(int num);
void parseSet(const string& line, vector<string>& set);
#endif
