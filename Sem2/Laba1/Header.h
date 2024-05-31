#pragma once

#ifndef LABA1_HPP
#define Laba1_HPP
#include <iostream>
#include <vector>
using namespace std;

struct Laba1 {
	string Suf(int n, int m, string Mas);
	int Sravn(string a, string b, int m);
	string SdvigMas(string Mas, int n, int m);
	vector<string> generateSubstrings(const string& str);
	string longestCommonPrefix(const string& str1, const string& str2);
};

#endif