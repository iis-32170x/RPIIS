
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");
	Array* a1 = NULL, * a2 = NULL;
	cout << "Выберите метод ввода данных\n 1 - из файла\n 2 - из консоли\n 0 - выход\n";
	int choice;
	cin >> choice;
	string str, str2;
	ifstream fin;
	bool check = false, check2 = true;
		switch (choice) {

		case 1:

			fin.open("test.txt");
			fin >> str;
			cout << "A = " << str << endl;
			if (IsCorrect(str)) {
				a1 = ArrayCreation(str);
			}
			else {
				cout << "Строку невозможно корректно преобразовать: не может быть несколько элементов вне множества\n";
				return 1;
			}
			fin >> str2;
			cout << "B = " << str2 << endl;
			if (IsCorrect(str2)) {
				a2 = ArrayCreation(str2);
			}
			else {
				cout << "Строку невозможно корректно преобразовать: не может быть несколько элементов вне множества\n";
				return 1;
			}
			if (a1 != NULL && a2 != NULL) {
				GetResult(a1, a2);
			}
			Remove(a1);
			Remove(a2);
			fin.close();
			break;
		case 2:

			cout << "Введите первую строку:\n";
					
			while (check2) {
				cin >> str;
				if (IsCorrect(str)) {
					a1 = ArrayCreation(str);
					
				}
				if (a1 == NULL) {
					cout << "Строку невозможно корректно преобразовать\n";
				}
				else {
					break;
				}
			}
			
			cout << "Введите вторую строку:\n";
			while (check2) {
				cin >> str2;

				if (IsCorrect(str2)) {
					a2 = ArrayCreation(str2);
					
				}
				if (a2 == NULL) {
					cout << "Строку невозможно корректно преобразовать\n";
				}
				else {
					break;
				}
			}
			cout << "A = " << str << endl;
			cout << "B = " << str2 << endl;
			if (a1 != NULL && a2 != NULL) {
				GetResult(a1, a2);
			}
			Remove(a1);
			Remove(a2);
			break;
		case 0:
			return 0;
		default:
			cout << "Неверный выбор\n";
			break;
		}
	
	

	return 0;
}