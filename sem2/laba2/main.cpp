#include <iostream>
#include <vector>
#include <fstream>
#include <string>
// current_value - переменная отвечающая за запись строкового значения базового элемента множества 

constexpr auto BASIC = "basic";
constexpr auto TUPLE = "tuple";
constexpr auto SET = "set";

using namespace std;

struct node {
	node* dad;
	string type;// тип узла базовый, кортэж или неор. множество

	vector<node*>children;//пустой для базового элемента 
	
	string value;//не пустой только для базового элемента

	node() {
		dad = nullptr;
		type = BASIC;
		children = {};
		value = "";// Empty element;
	}

	void add_child(string t) {
			node* n = new node;
			n->type = t;
			children.push_back(n); // Function of adding child
		
	} 
	//параметром передается тип создаваемого узла, current указатель надо переводить самостоятельно
};



class tree {
public:
	node* root;
	node* current;

	tree() { root = new node; current = root; }

	//Строку передавать затримленую от пробелов и начиная с первогой скобки
	void parse_from_str(string str) {
		cout << "starting parsing" << endl;
		
		
		if (str[0] == '{') { root->type = SET; }
		else { root->type = TUPLE; }//определяет тип корневого множества
		current = root;

		string current_value;

		for (int i = 1; i < str.size(); i++) {
			
			if (str[i - 1] == '{' || str[i - 1] == '<' || str[i - 1] == ',') {

				if (str[i] == '{') {
					current->add_child(SET);
				}
				else if (str[i] == '<') {
					current->add_child(TUPLE);
				}
				else {
					current->add_child(BASIC);
				}
				current->children.back()->dad = current;
				current = current->children.back(); //перемещение карент указателя
			}

			if (str[i] == ',') {
				if (current->type == BASIC) {
					current->value = current_value;
					current_value = "";
				}
				current = current->dad;
			}
			else if (str[i] == '}' || str[i] == '>') {
				if (current->type == BASIC) {
					current->value = current_value;
					current_value = "";
				}
				current = current->dad; 
			}
			else if (str[i] != '{' && str[i] != '<' && str[i] != ',' && str[i] != '}' && str[i] != '>') {
				current_value.push_back(str[i]);
			}
		}


	}

};

bool check_equality_for_sets(node* a, node* b);
void check_equality(node* a, node* b, bool& status);

bool check_equality_for_sets(node* a, node* b) {
	int counter_of_eq = 0;
	if (a->children.size() != b->children.size()) { return false; }
	for (auto i : a->children) {
		for (auto j : b->children) {
			bool st = true;
			check_equality(i, j, st);
			if (st == true) { counter_of_eq++; }
		}
	}
	if (counter_of_eq == a->children.size()) { return true; }
	return false;

}

void check_equality(node* a, node* b , bool &status) {

	if (a->type != b->type) { status = false; }
	//если типы все таки совпадают
	else {

		if (a->type == BASIC) { if (a->value != b->value) { status = false; } }// для базовых элементов 

		if (a->type == TUPLE) {
			if (a->children.size() != b->children.size()) { status = false; }
			else {
				for (int i = 0; i < a->children.size(); i++) { check_equality(a->children[i], b->children[i], status); }
			}
		}//для кортэжей
		if (a->type == SET) {
			status = check_equality_for_sets(a, b);
		}


	}

}

void read_from_file(const string& filename, string& firstLine, string& secondLine) {
	ifstream file(filename); 

	if (file.is_open()) {
		if (!getline(file, firstLine)) { 
			cout << "Не удалось считать первую строку." << endl; return;
		}
		if (!getline(file, secondLine)) {
			cout << "Не удалось считать вторую строку." << endl; return;
		}
		file.close();
	}
	else {
		cout << "Не удалось открыть файл." << endl; return;
	}
}

void print_tree(node* a, string& result) {
	if (a->type == BASIC) {
		result = result + a->value;
	}
	else if (a->type == SET) {
		result += "{";
		for (int i = 0; i < a->children.size(); i++) {
			print_tree(a->children[i], result);
			if (i != a->children.size() - 1) {
				result += ",";
			}
		}
		result += "}";
	}
	else if (a->type == TUPLE) {
		result += "<";
		for (int i = 0; i < a->children.size(); i++) {
			print_tree(a->children[i], result);
			if (i != a->children.size() - 1) {
				result += ",";
			}
		}
		result += ">";
	}
}

string print_tree(node* a) {
	string result;
	print_tree(a, result);
	return result;
}
int main() {
	//разность - все что пренадлежат А, но не пренадлежат Б

	string A; string B; read_from_file("example.txt", A, B);
	A.erase(remove(A.begin(), A.end(), ' '), A.end());
	B.erase(remove(B.begin(), B.end(), ' '), B.end());//удаляет пробелы
	A = A.substr(2);
	B = B.substr(2);
	cout << A << endl;
	cout << B << endl;

	tree a;
	tree b;
	a.parse_from_str(A);
	b.parse_from_str(B);

	tree c;

	for (auto i : a.root->children) {
		bool status;
		for (auto j : b.root->children) {
			status = true;
			check_equality(i, j, status);
			if (status == true) break; // если элемент найден, выходим из внутреннего цикла
		}
		if (!status) { // если элемент не найден, добавляем его в c
			c.root->children.push_back(i);
		}
	}
	c.root->type = SET;

	cout << "size " << c.root->type << endl;
	cout<<print_tree(c.root);

}