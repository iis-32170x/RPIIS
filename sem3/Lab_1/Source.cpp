#include <iostream>
#include <vector>
#include <string>
#include "Turing_Machine.h"
using namespace std;

/**
 * @brief Функция main программы.
 *
 * Здесь происходит ввод алфавита, ленты, состояний и правил. Также реализован основной цикл управления машиной
 *
 * @return 0 Если программа завершилась успешно.
 */
int main() {
	setlocale(LC_ALL, "ru");
	Turing_Machine tm;
	int cond, n, num;
	char c;
	string alphabet, line, rule;

	cout << "Введите алфавит: ";
	cin >> alphabet;
	tm.Set_Alphabet(alphabet);
	alphabet = alphabet + '~';

	do {
		cout << "Введите слово на ленте: ";
		cin >> line;
	} while (!tm.Set_Line(line));

	cout << "Введите количество состояний: ";
	cin >> cond;
	tm.Set_Cond(cond);
	cin.ignore();

	do {
		for (int i = 0; i < cond; i++) {
			for (char j : alphabet) {
				do {
					cout << "Введите правило для состояния " << i << " и символа " << j << ": ";
					getline(cin, rule);
				} while (!tm.Set_Rule(rule));
			}
			tm.Push_Back();
		}
	} while (!tm.Check_End());
	cout << endl;
	
	tm.Show_Line();
	tm.Show_Table();

	while (true) {
		cout << "Выберите следующее действие:\n0 - просмотреть ленту и таблицу\n1 - изменить значение на ленте\n2 - изменить правило\n3 - запустить машину\n";
		cin >> n;
		cout << endl;

		switch (n) {
		case 0:
			tm.Show_Line();
			tm.Show_Table();
			break;
		case 1:
			while (true)
			{
				cout << "Введите номер символа, который хотите изменить: " << endl;
				cin >> num;
				if ((num < 1) || (num > line.length()))
					cout << "Неправильный ввод" << endl;
				else
					break;
			}
			do
			{
				cout << "Введите новый символ" << endl;
				cin >> c;
			} while (!tm.Change_Line(num, c));
			cout << endl;
			break;
		case 2:
			do
			{
				cout << "Введите состояние: ";
				cin >> num;
				cout << "Введите символ: ";
				cin >> c;
				cout << "Введите правило: ";
				cin.ignore();
				getline(cin, rule);
			} while (!tm.Change_Rule(num, c, rule));
			break;
		case 3:
			while (true)
			{
				cout << "Выводить на экран информацию после каждого шага? (Y/N): ";
				cin >> c;
				if ((c != 'Y') && (c != 'N'))
				{
					cout << "Неправильный ввод" << endl;
					continue;
				}
				cout << endl;
				tm.Run_Machine(c);
				if (c == 'N')
				{
					tm.Show_Line();
					tm.Show_Table();
				}
				return 0;
			}
			return 0;
		default:
			cout << "Неправильный ввод" << endl;
		}
	}
}