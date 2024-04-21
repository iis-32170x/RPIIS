
#ifndef PCH_H
#define PCH_H
#include <vector>
#include <string>
using namespace std;

void setData(const string& filepath, int& num_sets, vector<vector<string>>& sets);
void cartesianProducts(const vector<vector<string>>& sets, int cur, int& num_sets, vector<vector<string>>& combinations, vector<string>& elements);
int print(const std::string& filepath);

#endif 

