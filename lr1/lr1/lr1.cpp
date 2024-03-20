#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");


	int i, in, n, kod;
	while (true)
	{
		cout << "\nСоздать стэк - 1.\nДобавить элементы в стек - 2.\nПросмотреть стэк - 3.\nДостать элемент стэка - 4.\nВыход - 0. \n";
		cin >> kod;
		switch (kod)
		{
		case 1: case 2:
			if (kod == 1 && Vertex != NULL)
			{
				cout << "Очистите память сначала" << endl;
				break;
			}
			cout << "Введите количество элементов: ";
			cin >> n;
			cout << endl;

			for (i = 1; i <= n; i++)
			{
				cin >> in;
				InStack(&Vertex, in);
			}

			break;

		case 3:
			if (!Vertex)
			{
				cout << "Стэк пуст!" << endl;
				break;
			}
			cout << "--- Stack ---" << endl;
			View(Vertex);
			break;
		case 4:
			if (Vertex != NULL)
			{
				int a = OutStack(&Vertex);
				cout << "Из стэка был взят элемент: " << a << endl;
			}
			else
			{
				cout << "Стэк пуст!" << endl;
			}
			break;
		case 0:
			return 0;
		}
	}
}