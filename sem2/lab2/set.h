#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <Windows.h>
using namespace std;

set<string> intersection(const string& file_path);
string trim(const string& str);