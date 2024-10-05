#include <iostream>
#include <vector>
#include <string>
#include "Turing_Machine.h"
using namespace std;

/**
 * @brief ������� main ���������.
 *
 * ����� ���������� ���� ��������, �����, ��������� � ������. ����� ���������� �������� ���� ���������� �������
 *
 * @return 0 ���� ��������� ����������� �������.
 */
int main() {
	setlocale(LC_ALL, "ru");
	Turing_Machine tm;
	int cond, n, num;
	char c;
	string alphabet, line, rule;

	cout << "������� �������: ";
	cin >> alphabet;
	tm.Set_Alphabet(alphabet);
	alphabet = alphabet + '~';

	do {
		cout << "������� ����� �� �����: ";
		cin >> line;
	} while (!tm.Set_Line(line));

	cout << "������� ���������� ���������: ";
	cin >> cond;
	tm.Set_Cond(cond);
	cin.ignore();

	do {
		for (int i = 0; i < cond; i++) {
			for (char j : alphabet) {
				do {
					cout << "������� ������� ��� ��������� " << i << " � ������� " << j << ": ";
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
		cout << "�������� ��������� ��������:\n0 - ����������� ����� � �������\n1 - �������� �������� �� �����\n2 - �������� �������\n3 - ��������� ������\n";
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
				cout << "������� ����� �������, ������� ������ ��������: " << endl;
				cin >> num;
				if ((num < 1) || (num > line.length()))
					cout << "������������ ����" << endl;
				else
					break;
			}
			do
			{
				cout << "������� ����� ������" << endl;
				cin >> c;
			} while (!tm.Change_Line(num, c));
			cout << endl;
			break;
		case 2:
			do
			{
				cout << "������� ���������: ";
				cin >> num;
				cout << "������� ������: ";
				cin >> c;
				cout << "������� �������: ";
				cin.ignore();
				getline(cin, rule);
			} while (!tm.Change_Rule(num, c, rule));
			break;
		case 3:
			while (true)
			{
				cout << "�������� �� ����� ���������� ����� ������� ����? (Y/N): ";
				cin >> c;
				if ((c != 'Y') && (c != 'N'))
				{
					cout << "������������ ����" << endl;
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
			cout << "������������ ����" << endl;
		}
	}
}