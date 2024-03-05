#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

// регулярное выражение для всего файла.
#define FORMA_1 "(\\w\\w*=((\\{\\w*(,\\w+)*\\})|(\\<\\w*(,\\w+)*\\>))\n)+"

// регулярное выражение для множеств внутри другого множества.
#define FORMA_2 "((\\{\\w*(,\\w+)*\\})|(\\<\\w*(,\\w+)*\\>))(?=,|\\}|\\>)"

#define C_ALL(X) cbegin(X), cend(X) 

using namespace std;

struct myset{
    string name;
    vector<string> elements;
    bool poradok;
};

bool format(string name, vector<myset> &mnojestva, string &all_file);

string add_set(string str, vector<myset> &mnojestva);
vector<string> razbil_na_names(string str);

void replace_na_names(string &text, string old_inf, string new_inf);
void replace_na_names(vector<myset> &mnojestva, string old_inf, string new_inf);

void make_sets(string &all_file, vector<myset> &mnojestva);

void union_sets(myset &result_set, vector<myset> &mnojestva);

bool poradoc(string str);

void write(myset &result_set, vector<myset> &mnojestva, string name);
void write_recursiv(myset &set, vector<myset> &mnojestva, ofstream &fout);

void do_all(string name);