#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include "library.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	string Result, name;
	vector <string> strCount;
	cout << "Открыть файл - 1" << endl;
	cout << "Вывести множества - 2" << endl;
	cout << "Объединить множества - 3" << endl;
	while (1) {
		switch (_getch()) {
		case '1': {
			cout << "Введите название файла" << endl;
			cin >> name;
			ifstream fin(name);
			if (fin.is_open()) {
				cout << "Файл открыт успешно!!!" << endl;
				cout << "----------------------" << endl;
				cout << "Вывести множества - 2" << endl;
				cout << "Объединить множества - 3" << endl;
				File(strCount, fin);
			}
			else {
				cout << "Ошибка открытия файла " << endl;
			}
			break;
		}
		case '2':
			Show(strCount);
			break;
		case '3':
			Union(strCount, Result);
			exit(0);
			break;
		}
	}
	return 0;
}
