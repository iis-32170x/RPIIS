# Лабораторная работа №1
# Цель
Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки конкретной структуры данных.
# Задача
Организовать структуру данных Бор (Префиксное дерево), написать функции добавления, удаления и поиска строки в нём.
# Список используемых понятий
`Бор` — структура данных для хранения набора строк, представляющая из себя подвешенное дерево с символами на рёбрах. Строки получаются последовательной записью всех символов, хранящихся на рёбрах между корнем бора и терминальной вершиной.(источник:
https://neerc.ifmo.ru/wiki/index.php?title=%D0%91%D0%BE%D1%80)
# Описание алгоритмов
## Файл Node.h
```C++
#pragma once
#include <iostream>
#include <vector>
class Node
{
public:
	std::vector<Node*> front_ptrs = { nullptr };
	Node* back_ptr;
	char c;
	int num = 0;
	bool is_root = false;
	bool end = false;
	Node();
	Node(char c);
	Node(Node* p);
};
```
## Файл Node.cpp (описание класса узла)
```C++
class Node
{
public:
	std::vector<Node*> front_ptrs = { nullptr };//Вектор указателей на потомков данного узла
	Node* back_ptr;//Указатель на предка данного узла
	char c;//Символ, хранящийся в этом узле
	int num = 0;//Количество потомков
	bool is_root = false;//Обозначение, является ли узел корнем
	bool end = false;//Обозначение, является ли этот узел концом слова
	Node()//Конструктор для корневого узла
  {
	  is_root = true;
  }
	Node(char c)//Конструктор для обычного узла (с указанием символа, хранящегося в нём)
  {
	this->c = c;
  }
	Node(Node* p)//Конструктор для узла, предшествующего корневому
  {
	this->front_ptrs[0] = p;
  }
};
```
## Файл bor.h
```C++
#pragma once
#include "Node.h"
#include <string>
void AddString(std::string, Node*);
int DelString(std::string s, Node* root);
void rekurs(Node* current, std::string word);
void ShowBor(Node* root);
int SearchString(std::string s, Node* root);
void DelBor(Node*);
```
## Файл bor.cpp (описание каждой функции в нём)
### Функция добавления строки в дерево
```C++
void AddString(string s, Node* root)
{
	Node* current = root;//Текущая вершина при обходе дерева
	Node* ptr;//Вспомогательный указатель
	int i, j;//Счётчики
	bool fnd;//Вспомогательное обозначение
	for (i = 0; i < s.size(); i++)//Обход введённой строки
	{
		fnd = false;
		for (j = 0; j < current->front_ptrs.size(); j++)//Обход указателей текущего узла
		{
			ptr = current->front_ptrs[j];
			if (ptr != nullptr)
			{
				if (s[i] == ptr->c)//Если среди потомков найден узел, содержащий текущий символ строки, просто переходим на него 
				{
					current = current->front_ptrs[j];
					fnd = true;
					break;
				}
			}
		}
		if (fnd == false)//Если не найден, создаём новый узел
		{
			if (current->front_ptrs[0] == nullptr)
				current->front_ptrs[current->num] = new Node(s[i]);
			else
				current->front_ptrs.push_back(new Node(s[i]));
			current->num++;
			ptr = current->front_ptrs[current->num - 1];
			ptr->back_ptr = current;//Присваем указателю на предка его адрес
			current = current->front_ptrs[current->num - 1];
		}
		if (i == s.size() - 1)//Если дошли до конца строки, помечаем текущий узел, как конец слова
			current->end = true;
	}
	cout << "Строка добавлена" << endl << endl;
}
```
### Функция удаления строки
```C++
int DelString(string s, Node* root)
{
	Node* current = root;
	Node* ptr;
	int i, j;
	bool fnd = false;
	for (i = 0; i < s.size(); i++)//Идём по элементам строки к её последнему элементу
	{
		for (j = 0; j < current->front_ptrs.size(); j++)
		{

			ptr = current->front_ptrs[j];
			if (ptr == nullptr)//Если натыкаемся на nullptr, пишем, что строки в боре нет, завершаем функцию
			{
				cout << "Строка не найдена" << endl << endl;
				return 1;
			}
			if (s[i] == ptr->c)
			{
				current = current->front_ptrs[j];
				fnd = true;
				break;
			}
		}
		if (fnd == false)//Если не нашли потомка с следующим символом, пишем, что строки в боре нет, завершаем функцию
		{
			cout << "Строка не найдена" << endl << endl;
			return 1;
		}
	}
	if (current->end != true)//Если узел с последним символом строки не помечен как конец слова, пишем, что строки в боре нет, завершаем функцию
	{
		cout << "Строка не найдена" << endl << endl;
		return 1;
	}
	for (i = s.size() - 1; i >= 0; i--)//Начинаем удаление с последнего символа
	{
		if ((current->num < 1 && current->end == false) || (i == s.size() - 1 && current->num < 1))//Если текущий узел не содержит потомков кроме раннее удалённого,не является концом другого слова или если он последний символ строки и не имеет больше потомков, удаляем его
		{
			current = current->back_ptr;//Переходим на предка
			for (j = 0; j < current->front_ptrs.size(); j++)//Ищем среди потомков узел, интересующий нас, удаляем его и указатель, указывавший на него из вектора
			{
				ptr = current->front_ptrs[j];
				if (s[i] == ptr->c)
				{
					delete current->front_ptrs[j];
					current->front_ptrs.erase(current->front_ptrs.begin() + j);
					break;
				}
			}
			current->num--;
		}
		else//Иначе, если символ, не подходящий под условия выше, является последним в строке, убираем его статус последнего символа в строке и завершаем функцию, или просто завершаем функцию
		{
			if (i == s.size() - 1)
				current->end = false;
			break;
		}
	}
	cout << "Строка удалена" << endl << endl;
	return 0;
}
```
### Функция для вывода всего бора
```C++
void ShowBor(Node* root)
{
	Node* current = root->back_ptr;//Переходим сразу на узел перед корневым
	string word;
	rekurs(current, word);//Передаём этот узел в функцию для рекурсии
	cout << endl;
}
```
### Вспомогательная рекурсивная функция для функции ShowBor
```C++
void rekurs(Node* current, string word)
{
	int i;
	for (i = 0; i < current->front_ptrs.size(); i++)//Обходим всех потомков текущего узла
	{
		if (current->front_ptrs[i] != nullptr)//Если i-тый потомок не равен nullptr
		{
			current = current->front_ptrs[i];//Переходим на него и, если это не корень, записываем его символ в слово word, а если он помечен концом строки, выводим слово word
			if (current->is_root == false)
			{
				word.push_back(current->c);
				if (current->end == true)
				{
					cout << word << endl;
				}
			}
			rekurs(current, word);//Снова запускаем рекурсию для этого узла
		}
	}
}
```
### Функция поиска строки
```C++
int SearchString(string s, Node* root)//Алгоритм идентичен алгоритму проверки наличия строки из функции DelString
{
	Node* current = root;
	Node* ptr;
	int i, j;
	bool fnd = false;
	for (i = 0; i < s.size(); i++)
	{
		for (j = 0; j < current->front_ptrs.size(); j++)
		{
			ptr = current->front_ptrs[j];
			if (ptr == nullptr)
			{
				cout << "Строка не найдена" << endl << endl;
				return 1;
			}
			if (s[i] == ptr->c)
			{
				current = current->front_ptrs[j];
				fnd = true;
				break;
			}
		}
		if (fnd == false)
		{
			cout << "Строка не найдена" << endl << endl;
			return 1;
		}
	}
	if (current->end == true)
	{
		cout << "Строка найдена" << endl << endl;
		return 0;
	}
	else
	{
		cout << "Строка не найдена" << endl << endl;
		return 1;
	}
}
```
### Функция удаления бора при завершении программы
```C++
void DelBor(Node* root)
{
	int i;
	if (root != nullptr)
		for (i = 0; i < root->front_ptrs.size(); i++)//Перебираем всех потомков данного узла
		{
			if (root->front_ptrs[i])//Если потомок существует, рекурсивно снова запускаем для енго функцию
			{
				DelBor(root->front_ptrs[i]);
			}
		}
	delete root;//И начиная с последнего доступного элемента, производим удаление
}
```
### Файл Source.cpp
```C++
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
			Delbor(root);
			return 0;
		default:
			cout << "Введено необозначенное число";
		}
	} while (true);
}
```
## Тестирование
![image](https://github.com/iis-32170x/RPIIS/assets/147268285/f76264de-a002-489c-bde9-2105906e4a6e)

![image](https://github.com/iis-32170x/RPIIS/assets/147268285/c6be2b60-d3ae-4482-931e-a8898231b44a)

## Вывод
Мы организовали правильную работы бора как структуры данных со всеми необходимыми функциями.  

