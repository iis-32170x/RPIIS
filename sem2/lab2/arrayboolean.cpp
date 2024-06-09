#include "arrayboolean.h"
#include <iostream>;
#include <string>;
#include <vector>;
#include <windows.h>;
#include <fstream>;
using namespace std;

int n, ind = 0, length;
string arrstring;
string arrstringn;
vector<char> arrayA(0);
vector<char> arrayBoolean(0);

void filecheck() {
	ifstream in("arrayA.txt");
	if (in.is_open()) {
		getline(in, arrstring);
	}
	length = arrstring.length();
	for (int i = 0; i < length; i++) {
		if (arrstring[i] == ' ');
		else arrstringn += arrstring[i];
	}
	length = arrstringn.length();
}

void arraytask() {
	for (int i = 0; i < length; i++) {
		arrayA.push_back(arrstringn[i]);
	}
	for (int i = 0; i < arrayA.size(); i++) {
		if (arrayBoolean.size() == 0) {
			arrayBoolean.push_back(arrayA[i]);
		}
		else {
			for (int k = 0; k < arrayBoolean.size(); k++) {
				if (arrayA[i] == arrayBoolean[k]);
				else ind++;
			}
			if (ind == arrayBoolean.size()) {
				arrayBoolean.push_back(arrayA[i]);
			}
			ind = 0;
		}
	}
}

void output() {
	for (int i = 0; i < arrayBoolean.size(); i++) {
		cout << arrayBoolean[i] << ' ';
	}
}