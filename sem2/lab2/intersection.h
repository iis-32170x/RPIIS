#pragma once
#include <iostream>
#include <fstream>;
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string fromFile(string filename);
void spacetest(string first_set, string second_set);
string intersection(string first_set, string second_set);
void setСhecking(string first_set, string second_set);
void elementpush(string set, vector<string> vecSet);
vector<string> multiple_occurrences(vector<string> set);
