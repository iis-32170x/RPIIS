#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	//ДЕКЛАРАЦИЯ И ИНИЦИАЛИЗАЦИЯ
	node* begin = new node;
	int amount; int numb;
	cout << "Введите количество элементов списка" << endl;
	cin >> amount;
	while (cin.fail() || amount < 1)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "ОШИБКА. Введите другое число" << endl;
		cin >> amount;
	}
	cout << "Введите значение элемента" << endl;
	cin >> numb;
	//Проверка
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "ОШИБКА. Введите другое число" << endl;
		cin >> numb;
	}
	begin->info = numb;
	begin->next = nullptr;
	for (int i = 1; i < amount; i++)
	{
		cout << "Введите значение элемента" << endl;
		cin >> numb;
		AddNode(begin, numb);
	}
again:
	cout << "Какую операции вы хотите сделать?" << endl;
	cout << endl;
	cout << "1. ВЫВОД" << endl;
	cout << "2. ВСТАВКА" << endl;
	cout << "3. УДАЛЕНИЕ" << endl;
	cout << "4. СОРТИРОВКА" << endl;
	cout << "5. ПОИСК" << endl;
	cout << "6. ОБЪЕДИНЕНИЕ" << endl;
	cout << "7. ПЕРЕСЕЧЕНИЕ" << endl;
	cout << "8. ВЫХОД" << endl;
	cout << endl;
	int user;
	cin >> user;
	while (cin.fail() || user < 1 || user>8)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "ОШИБКА. Введите другое число" << endl;
		cin >> user;
	}
	cout << endl;
	switch (user)
	{
		//ВЫВОД
	case 1:
	{
		//ВЫВОД
		cout << "СПИСОК:" << endl;
		node* y = begin;
		while (y)
		{
			cout << y->info << endl;
			y = y->next;
		}
		cout << endl;
	} goto again;
	//ВСТАВКА
	case 2:
	{
		//ВСТАВКА
		cout << "Введите число, которое нужно вставить:" << endl;
		int add;
		cin >> add;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> add;
		}
		cout << endl;
		AddNode(begin, add);
	} goto again;
	//УДАЛЕНИЕ
	case 3:
	{
		//УДАЛЕНИЕ
		cout << "Введите элемент, который нужно удалить:" << endl;
		int del;
		cin >> del;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> del;
		}
		cout << endl;
		while (cin.fail() || SearchNodeInfo(begin, del) == nullptr)
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> del;
		}
		DeleteNode(&begin, SearchNodeInfo(begin, del));
	} goto again;
	//СОРТИРОВКА
	case 4:
	{
		//СОРТИРОВКА
		NodeSorting(begin);
	} goto again;
	//ПОИСК
	case 5:
	{
		//ПОИСК
		cout << "Введите элемент, который необходимо найти" << endl;
		cout << endl;
		int search;
		cin >> search;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> search;
		}
		cout << endl;
		int i = 0;
		node* y = SearchNodeInfo(begin, search);
		if (y != nullptr)
		{
			node* t = begin;
			while (t != y)
			{
				i++;
				t = t->next;
			}
			i++;
			cout << "Номер элемента поиска: " << i << endl;
		}
		else cout << "Нет такого элемента" << endl;
		cout << endl;
	} goto again;
	//ОБЪЕДИНЕНИЕ
	case 6:
	{
		node* begin2 = new node;
		cout << "Введите количество элементов списка" << endl;
		cin >> amount;
		//Проверка
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> amount;
		}
		cout << "Введите значение элемента" << endl;
		cin >> numb;
		//Проверка
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> numb;
		}
		begin2->info = numb;
		begin2->next = nullptr;
		for (int i = 1; i < amount; i++)
		{
			cout << "Введите значение элемента" << endl;
			cin >> numb;
			AddNode(begin2, numb);
		}
		cout << endl;
		cout << "Объединение 1 и 2 списка:" << endl;
		node* c = Unification(begin, begin2);
		NodeSorting(c);
		while (c != nullptr)
		{
			cout << c->info << endl;;
			c = c->next;
		}
		cout << endl;
	} goto again;
	//ПЕРЕСЕЧЕНИЕ
	case 7:
	{
		node* begin2 = new node;
		cout << "Введите количество элементов списка" << endl;
		cin >> amount;
		//Проверка
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> amount;
		}
		cout << "Введите значение элемента" << endl;
		cin >> numb;
		//Проверка
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ОШИБКА. Введите другое число" << endl;
			cin >> numb;
		}
		begin2->info = numb;
		begin2->next = nullptr;
		for (int i = 1; i < amount; i++)
		{
			cout << "Введите значение элемента" << endl;
			cin >> numb;
			AddNode(begin2, numb);
		}
		cout << endl;
		cout << "Пересечение 1 и 2 списка:" << endl;
		node* c = getIntersectionByInfo(begin, begin2);
		if (c != nullptr) {
			NodeSorting(c);
			while (c != nullptr)
			{
				cout << c->info << endl;;
				c = c->next;
			}
		}
		else cout << endl << "Пересечение является пустым списком";
		cout << endl << endl;
	} goto again;
	case 8: break;
	}
}