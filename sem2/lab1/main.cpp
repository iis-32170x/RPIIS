#include "exlibr.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	suffix_array sf = suffix_array(str);
	sf.view();

	cout << "The largest common prefix of two substrings:" << endl;
	cout << endl;
	cout << sf.get_lcp() << endl;
	cout << "the smallest cyclic shift:" << endl;
	cout << endl;
	cout << sf.get_scs() << endl;

	return 0;
}