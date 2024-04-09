#include "suffix_array.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	suffix_array sf = suffix_array(str);
	sf.view();
	cout << sf.get_lcp() << endl;

	cout << endl;
	cout << sf.get_scs() << endl;

	return 0;
}