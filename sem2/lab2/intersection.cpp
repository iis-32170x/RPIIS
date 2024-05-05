#include "intersection.h"
string fromFile(string filename) {
	string text;
	ifstream file(filename);
	while (file) {
		getline(file, text);
	}

	return text;
}

void spacetest(string first_set, string second_set) {
	for (int i = 0; i < first_set.length(); i++) {
		if (first_set[i] == ' ') {
			cout << "Incorrect input" << endl;
			cout << "Extra space in set 1";
			exit(0);
		}
	}
	for (int i = 0; i < second_set.length(); i++) {
		if (second_set[i] == ' ') {
			cout << "Incorrect input" << endl;
			cout << "Extra space in set 2";
			exit(0);
		}
	}
}
void setСhecking(string first_set, string second_set) {
	if (first_set[0] != '{' || first_set[first_set.length()-1] != '}') {
		cout << "Set 1 is not one";
		exit(0);
	}
	if (second_set[0] != '{' || second_set[second_set.length()-1] != '}') {
		cout << "Set 2 is not one";
		exit(0);
	}
}
string intersection(string first_set, string second_set) {
	string result = "{";
	int temp = 0;
	string element = "";
	vector<string> first_set_element;
	vector<string> second_set_element;
	for (int i = 1; i < first_set.length() - 1; i++) {
		if (first_set[i] == '{' || first_set[i] == '<') {
			temp++;
		}
		if (temp > 0) {
			element += first_set[i];
		}
		if (first_set[i] == '}' || first_set[i] == '>') {
			temp--;
			if (temp == 0) {
				first_set_element.push_back(element);
				element = "";
			}
		}
		// можжно добавить if(temp1==0 && first_set[i] == '<') { temp2++; и то же самое что с первым}
		if (temp == 0 && first_set[i] != ',' && first_set[i] != '}' && first_set[i] != '>') {
			element += first_set[i];
		}
		if (temp == 0 && (first_set[i] == ',' || first_set[i] == '}' || first_set[i] == '>')) {
			if (!element.empty()) {
				first_set_element.push_back(element);
				element = "";
			}
		}
		if (temp < 0) {
			cout << "First set is incorrect, extra closing parenthesis" << endl;
			cout << "Crossing is impossible" << endl;
			exit(0);
		}
		if (i == first_set.length() - 1 && temp > 0) {
			cout << "First set is incorrect, extra opening parenthesis" << endl;
			cout << "Crossing is impossible";
			exit;
		}
	}

	element = "";
	for (int i = 1; i < second_set.length() - 1; i++) {
		if (second_set[i] == '{' || second_set[i] == '<') {
			temp++;
		}
		if (temp > 0) {
			element += second_set[i];
		}
		if (second_set[i] == '}' || second_set[i] == '>') {
			temp--;
			if (temp == 0) {
				second_set_element.push_back(element);
				element = "";
			}
		}
		if (temp == 0 && second_set[i] != ',' && second_set[i] != '}' && second_set[i] != '>') {
			element += second_set[i];
		}
		if (temp == 0 && (second_set[i] == ',' || second_set[i] == '}' || second_set[i] == '>')) {
			if (!element.empty()) {
				second_set_element.push_back(element);
				element = "";
			}
		}
		if (temp < 0) {
			cout << "Second set is incorrect, extra closing parenthesis" << endl;
			cout << "Crossing is impossible" << endl;
			exit(0);
		}
		if (i == second_set.length() - 1 && temp > 0) {
			cout << "Second set is incorrect, extra opening parenthesis" << endl;
			cout << "Crossing is impossible";
		}
	}
	for (int i = 0; i < first_set_element.size(); i++) {
		for (int j = 0; j < second_set_element.size(); j++) {
			if (first_set_element[i] == second_set_element[j]) {
				result = result + first_set_element[i] + ',';
			}
		}
	}
	result.pop_back();
	result += '}';
	return result;
}