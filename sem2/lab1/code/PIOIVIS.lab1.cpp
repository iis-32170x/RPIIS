#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	vetka* koren = nullptr;
	vetka* koren2 = nullptr;
	vetka* koren3 = nullptr;
	vetka* koren4 = nullptr;
	cout << "введите мощность 1-го множества" << endl;
	cin >> a;
	cout << "введите элементы 1-го множества" << endl;
	for (int i = 0; i < a; i++) {
		cin >> b;
		Add(koren, b);
	}

	cout << endl;
	cout << "введите мощность 2-го множества" << endl;
	cin >> a;
	cout << "введите элементы 2-го множества" << endl;
	for (int i = 0; i < a; i++) {
		cin >> b;
		Add(koren2, b);
	}
	cout << endl << endl << "Дерево 1: " << endl;

	print(koren);

	cout << endl << "Дерево 2: " << endl;
	print(koren2);

	Peresechenie(koren, koren2, koren3);
	cout << endl << endl << "Пересечение" << endl;
	print(koren3);

	Objedinenie(koren, koren2, koren4);
	cout << endl << endl << "Объединение" << endl;
	print(koren4);
	cout << endl;

	cout << endl << "выбирете элемент для поиска" << endl;
	cin >> c;
	FindElem(koren4, c);

	cout << endl << "выбирете элемент для удаления" << endl;
	cin >> c;
	cout << endl << endl << "Удаление" << endl;
	removeNode(koren4, c);
	print(koren4);


	return 0;
}