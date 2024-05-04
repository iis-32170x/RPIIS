#include "Header.h"
#include <iostream>
using namespace Y;
using namespace std;
int main() {
	int choice;
	setlocale(LC_ALL, "ru");
	Deck* exmpl= new Deck;
	exmpl -> crtdeck();
	exmpl->output();
	again:
	cout <<endl<< "1.Удалить с конца" << endl << "2.Удалить с начала" << endl << "3.Добавить в конец" << endl << "4.Добавить в начало" << endl << "5.Просмотреть" << endl << "6.Закончить";
	cin >> choice;
	while (cin.fail()||choice<1||choice>6) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите значение:";
		cin >> choice;
	}
	switch (choice) {
	case 1:
		exmpl->delback();
		if (exmpl->check() == true) {
			break;
		}
		goto again;
	case 2:
		exmpl->delfront();
		if (exmpl->check()==true) {
			break;
		}
		goto again;
	case 3:
		exmpl->addback();
		goto again;
	case 4:
		exmpl->addfront();
		goto again;
	case 5:
		exmpl->output();
		goto again;
	case 6:
		break;
	}
	while (exmpl->check() == false) {
		exmpl->delfront();
		exmpl->output();
	}
	delete exmpl;
	return 0;
}