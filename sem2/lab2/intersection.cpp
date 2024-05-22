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
			first_set.erase(i, 1);
		}
	}
	for (int i = 0; i < second_set.length(); i++) {
		if (second_set[i] == ' ') {
			second_set.erase(i, 1);
		}
	}
}

void setСhecking(string first_set, string second_set) {
	if (first_set[0] != '{' || first_set[first_set.length()-1] != '}') {
		cout << "Set 1 is not a set";
		exit(0);
	}
	if (second_set[0] != '{' || second_set[second_set.length()-1] != '}') {
		cout << "Set 2 is not a set";
		exit(0);
	}
}

vector<string> elementpush(string set) {
	vector<string>vecSet;
	int temp = 0;
	string element = "";
	for (int i = 1; i < set.length() - 1; i++) {
		if (set[i] == '{' || set[i] == '<') {
			temp++;
		}
		if (temp > 0) {
			element += set[i];
		}
		if (set[i] == '}' || set[i] == '>') {
			temp--;
			if (temp == 0) {
				vecSet.push_back(element);
				element = "";
			}
		}
		if (temp == 0 && set[i] != ',' && set[i] != '}' && set[i] != '>') {
			element += set[i];
		}
		if (temp == 0 && (set[i] == ',' || set[i] == '}' || set[i] == '>')||(temp == 0 && i == set.length()-2)) {
			if (!element.empty()) {																		
				vecSet.push_back(element);                                              
				element = "";
			}
		}
		if (temp < 0) {
			cout << "First set is incorrect, extra closing parenthesis" << endl;
			cout << "Intersection is impossible" << endl;
			exit(0);
		}
		if (i == set.length() - 1 && temp > 0) {
			cout << "First set is incorrect, extra opening parenthesis" << endl;
			cout << "Intersection is impossible";
			exit(0);
		}
		if ((set[i] == ',' && set[i + 1] == ',') || (set[i] == ',' && set[i + 1] == '}')) {
			cout << "Incorrect set, extra ','";
			exit(0);
		}
	}
	
	return vecSet;
}

vector<string> multiple_occurrences(vector<string> set) {
	string el;
	string text_temp = "";
	vector<string> current;
	for (int i = 0; i < set.size(); i++) {
		el = set[i];
		if (el[0] == '{' && el[el.length()-1] == '}') { 
			current = elementpush(el);
			sort(current.begin(), current.end());
			current.erase(unique(current.begin(), current.end()), current.end());
			text_temp = "{";
			for (int k = 0; k < current.size(); k++) {
				text_temp += current[k];
				if (k != current.size() - 1) {
					text_temp += ",";
				}
			}
			text_temp += "}";
			set[i] = text_temp;
		}
	}
	cout << "R: ";
	for (int i = 0; i < set.size(); i++) {
		cout << set[i] << endl;
	}
	return set;
}

string intersection(string first_set, string second_set) {
	string result = "{";
	vector<string> first_set_element;
	vector<string> second_set_element;
	vector<string> first_set_el_rework;
	vector<string> second_set_el_rework;
	first_set_element = elementpush(first_set);
	first_set_element.erase(unique(first_set_element.begin(), first_set_element.end()), first_set_element.end());
	second_set_element = elementpush(second_set);
	second_set_element.erase(unique(second_set_element.begin(), second_set_element.end()), second_set_element.end());
	first_set_el_rework = multiple_occurrences(first_set_element);
	second_set_el_rework = multiple_occurrences(second_set_element);
	cout << endl;
	for (int i = 0; i < first_set_el_rework.size(); i++) {
		for (int j = 0; j < second_set_el_rework.size(); j++) {
				if (first_set_el_rework[i] == second_set_el_rework[j]) {
					result = result + first_set_el_rework[i] + ',';
				}
			}   
		} 
		result.pop_back();
		if (!result.empty()) {
			result += '}';
		}
		return result;
	}
