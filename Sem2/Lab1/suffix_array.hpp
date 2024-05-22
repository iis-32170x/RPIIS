#pragma once
#include <vector>
#include <string>
using namespace std;
class suffix_array {
public:
	suffix_array(string str); //Принимает строку в качестве аргумента при создании объекта класса
	void view();
	string get_lcp(); //Longest common prefix
	string get_scs(); //Наименьший циклический сдвиг
private:
vector<string> suffixes;
vector<string> shifts;
};