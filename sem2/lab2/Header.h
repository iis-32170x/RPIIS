#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

vector<vector<string>> ReadFileToVector(const string& fileName);
vector<vector<string>> CartesianProduct(const vector<vector<string>>& sets);
void PrintCartesianProduct(const vector<vector<string>>& product);
