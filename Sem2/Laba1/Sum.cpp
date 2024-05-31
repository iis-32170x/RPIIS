#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include "..\StaticLib\Header.h"

using namespace std;

string Laba1::Suf(int n, int m, string Mas)
{
	string Suffix;
	Suffix.resize(100);
	int i = 0;
	while (n < m)
	{
		Suffix[i] = Mas[n];
		i++;
		n++;
	}
	return Suffix;
}

int Laba1::Sravn(string a, string b, int m)
{
	int i = 0;
	while (i < m)
	{
		if ((a[i] < b[i])) return 0;
		else if (a[i] > b[i]) return 1;
		else if (a[i] == b[i]) i++;
	}
}

string Laba1::SdvigMas(string Mas, int n, int m)
{
	string Sdvig;
	Sdvig.resize(m);
	string Bufer;
	Bufer.resize(m);
	for (int i = 0; i < m - n; i++)
	{
		Bufer[i] = Mas[i + n];
	}
	for (int i = 0; i < m - n; i++)
	{
		Sdvig[i] = Bufer[i];
	}
	for (int i = 0; i < n; i++)
	{
		Sdvig[i + (m - n)] = Mas[i];
	}
	return Sdvig;
}

vector<string> Laba1::generateSubstrings(const string& str) {
	vector<string> substrings;
	for (int i = 0; i < str.size(); i++) {
		for (int len = 1; len <= str.size() - i; len++) {
			substrings.push_back(str.substr(i, len));
		}
	}
	return substrings;
}

string Laba1::longestCommonPrefix(const string& str1, const string& str2) {
	int length = min(str1.size(), str2.size());
	for (int i = 0; i < length; i++) {
		if (str1[i] != str2[i]) {
			return str1.substr(0, i);
		}
	}
	return str1.substr(0, length);
}
