﻿// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"
#include <ctime>
using namespace std;


int main(){
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
    Deque d;
    d.head = 0;
    d.tail = 0;
	int vybor; bool stop = 1; bool flag = 0;
    
	while (stop)
	{
		cout << "Выберете операцию:\n 1 - Создать дек \n 2 - Добавить элемент вперед\n 3 - Добавить элемент назад \n 4 - Удалить элемент с начала\n 5 - Удалить элемент с конца\n 6 - просмотр \n 0 - закончить выполнение \n";
		cin >> vybor;
		switch (vybor)
		{
		case(1):
		{
			if (!flag)
			{
				flag = 1;
				cout << "Дек создан" << endl;
			}
			else cout << "Дек уже создан"<< endl;
			break;
		}
		case(2):
		{
			if (flag)
			{
				for (int i = 0; i < 3; i++)
					push_front(&d, rand() % 100);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(3):
		{
			if (flag)
			{
				for (int i = 0; i < 3; i++)
					push_front(&d, rand() % 100);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(4):
		{
			if (flag)
			{
				pop_front(&d);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(5):
		{
			if (flag)
			{
				pop_back(&d);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(6):
		{
			if (flag)
			{
				printDeque(&d);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(0):
			stop = false;
		}
	}
	cout << "Программа завершена";
	return 1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
