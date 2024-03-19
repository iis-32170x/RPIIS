#include <iostream>
#include <string>
#include "Node.h"; 
#include "bor.h";
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int n = 0;
	string s;
	Node* root = new Node();
	root->back_ptr = new Node(root);
	do
	{
 		cout << "Выберите операцию: 1 - добавить строку в бор, 2 - удалить cтроку из бора, 3 - поиск строки в боре, 4 - вывести все строки в боре, 0 - завершить программу " << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "Введите строку: ";
			cin >> s;
			AddString(s, root);
			break;
		case 2:
			cout << "Введите строку: ";
			cin >> s;
			DelString(s, root);
			break;
		case 3:
			cout << "Введите строку: ";
			cin >> s;
			SearchString(s, root);
			break;
		case 4:
			cout << "Строки в боре: " << endl;
			ShowBor(root);
			break;
		case 0:
			delete root->back_ptr;
			DelBor(root);
			return 0;
		default:
			cout << "Введено необозначенное число";
		}
	} while (true);
}
