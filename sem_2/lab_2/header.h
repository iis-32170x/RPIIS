#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>

#ifndef PIOIVIS_HEADER_H
#define PIOIVIS_HEADER_H

using namespace std;

int input(const string& message);
void ADD(vector<int>& vec, int size);
void read(vector<int>& V, ifstream& file);
bool check(const vector<int>& one, const vector<int>& two);
void print(const vector<int>& V);


#endif //PIOIVIS_HEADER_H

