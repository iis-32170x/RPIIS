#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include "library.h"
using namespace std;
void Show(vector<string> reg) {
	for (int i = 0; i <= reg.size(); i++) {
		if (i < reg.size()) {
			cout << "Множество " << i + 1 << " :" << endl;
			cout << "{" << reg[i] << "}" << endl;
		}
		else {
			cout << "Все множества записаны" << endl;
			cout << "----------------------" << endl;
			cout << "Объединить множества - 3" << endl;
		}
	}
}

void File(vector<string>& count, ifstream& fin) {
    string str;
    while (!fin.eof()) {
        getline(fin, str);
        count.push_back(str);
    }
    fin.close();
}
void Union(vector<string>& count, string& obyedineniye) {
    if (count.size() != 0) {
        string result = obyedineniye;
        int length = result.length();
        string dop;
        for (int k = 0; k < count.size(); k++) {
            int i = 0;
            while (i < count[k].size()) {
                while (i < count[k].size() && count[k][i] != ',') {
                    dop += count[k][i];
                    i++;
                }
                if (result.find(dop) == string::npos && dop != "") {
                    result += dop + ',';
                    length = result.length();
                }
                dop = "";
                if (i < count[k].size())
                    i++;
            }
        }
        result = result.substr(0, length - 1);
        cout << "Результат объединения:" << std::endl;
        cout << "{" << result << "}" << std::endl;
    }
}
