#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>
#include <sstream>
#include <iostream>
#include <stack>

struct SubSet {
	std::vector<std::string> element;
	size_t oriented = 0;
};

struct Set {
	bool oriented = 0;
	std::string name;
	std::vector<std::string> subsets;
};

bool bracketsBalance(const std::string& line);
void print(const std::vector<Set>& sets);
void processSubsets(const std::string& line, size_t& i, Set& SET);
std::vector<Set> read(const std::string& filename);

void intersectionCalc(std::vector<std::string>& result, Set set1, Set set2);
std::vector<std::string> intersection(const std::string& filename);
