# Лабораторная работа №2



- `Цель` - Реализовать программу, выполняюшую операцию симметрической разности неограниченного кол-ва множеств.
- `Задача` - реализовать алгоритм симметрической разностит разности
- `Вариант` - 3

## Список ключевых понятий (определения) ❓
- ` Множество`  - это любая определенная совокупность объектов. Объекты, из которых составлено множество, называются его элементами. Элементы множества различны и отличны друг от друга.
- `Симметрическая разность множеств A и B ` - это множество, которое состоит из тех элементов, которые одновременно  принадлежат множеству A и не принадлежат множеству B и тех , принадлежат множеству B и не принадлежат множеству А.
## Алгоритм
Для того, чтобы посчитать симметрическую разность n-ого количества множеств, нужно чтобы в нашу функцию симметрической разности передавалосись значения элементов всех множеств.
Далее эти множества разбиваются на отдельные элементы и сохраняются в отдельный массив(происходит проверки на подмножества и картежи).
Далее необходимо отсортировать получившийся массив элементов множеств .
В результате получаем отсортированный массив всех элементов, из которого все элементы встречающиеся ровно 1 раз добавляются в результат симметрической разности.
## Реализация алгоритма

### Функция, выполняюшая операцию.

``` C++
void operaciya(const vector<string>& strCounter, string& Results)
{
	if (strCounter.size() > 1)
	{
		Show(strCounter);
		string uni{ };
		for (int j = 0; j < strCounter.size(); j++)
		{
			uni += strCounter[j];
			if (j != strCounter.size() - 1)
			{
				uni += ',';
			}
		}

		vector<string> elementby1;
		stringstream ss(uni);
		string element;
		string buffer;
		int skobochki = 0;
		int kartezh = 0;
		while (getline(ss, element, ','))
		{
			buffer += element;
			for (char c : element)
			{
				if (c == '<') kartezh++;
				else if (c == '>') kartezh--;
				if (c == '{') skobochki++;
				else if (c == '}') skobochki--;
			}
			if (skobochki == 0)
			{
				if (kartezh == 0)
				{
					elementby1.push_back(buffer);
					buffer.clear();
				}
				if (kartezh != 0) buffer += ',';
			}
			if (skobochki != 0)
			{
				buffer += ",";
			}
		}

		for (int i = 0; i < elementby1.size() -2; i++)
		{
			for (int j = 0; j < elementby1.size() - i - 1; j++)
			{
				if (elementby1[j] > elementby1[j + 1])
				{
					swap(elementby1[j], elementby1[j + 1]);
				}
			}
		}
		if (elementby1[0] != elementby1[1])
		{
			Results += elementby1[0];
			Results += ',';
		}
		for (int i = 1; i < elementby1.size()-1 ; i++)
		{
			if (elementby1[i] != elementby1[i - 1] && elementby1[i] != elementby1[i + 1])
			{
				Results += elementby1[i];
				Results += ',';
			}
		}
		size_t k = elementby1.size() - 1;
		if (elementby1[k] != elementby1[k - 1])
		{
			Results += elementby1[k];
		}

		cout << "{" << Results << "}" << endl;
	}
	else
	{
		cout << "Vvedeno vsego" << strCounter.size() << "Mnozhesvo" << endl;
	}
}
```
## Функции

```C++
#include "Library.h"

void Show(vector<string> strCounter)\\функция вывода всех множеств    
{
	cout << "Vse mnozhestva: " << endl; 
	for (int i = 0; i < strCounter.size(); ++i)  
	{
		cout << "{" << strCounter[i] << "}" << endl;  
	}
} 

void AddStr(vector<string>& strCounter) \\функция добавления нового множества
{
	cout << "Vvedite elementi mnozhestva\n " << "Elementi razdelyautsia zapiatimi" << endl;  
	string str;
	string temp;
	cin >> ws;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			temp += str[i];
		}
	}
	strCounter.push_back(temp);
	cout << "Mnozhestvo dobavleno " << endl;
}

void ReadFromFile(vector<string>& strCounter, ifstream& in)\\функция чтения множеств из файла(3|qwe|qwewr|1,2|{12},2,3|1|1,2,3,4,5,6,7,8,9 <1,2>,<2,2>|<1,2>|{<2,2>,<1,2>,3,4},<3,3>|{1,2,3,4,5,6,{1,2,3,4,5}},<1,2>)

{
	string str;
	strCounter.clear();
	while (getline(in, str))
	{
		strCounter.push_back(str);
	}
	cout << "Fail otcrit" << endl;
	in.close();
}

void WriteIntoFile(ofstream& out, vector <string>& strCounter)\\функция записи множеств в файл
{
	for (int i = 0; i < strCounter.size(); i++)
	{
		out << strCounter[i] << endl;
	}
	cout << "Fail sohranen" << endl;
}


void operaciya(const vector<string>& strCounter, string& Results)\\алгоритм симметрической разности
{
	if (strCounter.size() > 1)
	{
		Show(strCounter);
		string uni{ };
		for (int j = 0; j < strCounter.size(); j++)
		{
			uni += strCounter[j];
			if (j != strCounter.size() - 1)
			{
				uni += ',';
			}
		}

		vector<string> elementby1;
		stringstream ss(uni);
		string element;
		string buffer;
		int skobochki = 0;
		int kartezh = 0;
		while (getline(ss, element, ','))
		{
			buffer += element;
			for (char c : element)
			{
				if (c == '<') kartezh++;
				else if (c == '>') kartezh--;
				if (c == '{') skobochki++;
				else if (c == '}') skobochki--;
			}
			if (skobochki == 0)
			{
				if (kartezh == 0)
				{
					elementby1.push_back(buffer);
					buffer.clear();
				}
				if (kartezh != 0) buffer += ',';
			}
			if (skobochki != 0)
			{
				buffer += ",";
			}
		}

		for (int i = 0; i < elementby1.size() -2; i++)
		{
			for (int j = 0; j < elementby1.size() - i - 1; j++)
			{
				if (elementby1[j] > elementby1[j + 1])
				{
					swap(elementby1[j], elementby1[j + 1]);
				}
			}
		}
		if (elementby1[0] != elementby1[1])
		{
			Results += elementby1[0];
			Results += ',';
		}
		for (int i = 1; i < elementby1.size()-1 ; i++)
		{
			if (elementby1[i] != elementby1[i - 1] && elementby1[i] != elementby1[i + 1])
			{
				Results += elementby1[i];
				Results += ',';
			}
		}
		size_t k = elementby1.size() - 1;
		if (elementby1[k] != elementby1[k - 1])
		{
			Results += elementby1[k];
		}

		cout << "{" << Results << "}" << endl;
	}
	else
	{
		cout << "Vvedeno vsego" << strCounter.size() << "Mnozhesvo" << endl;
	}
}



void Menu()\\меню
{
	cout << "Vvedite 1 chtobi otcrit/sozdat fail " << endl;
	cout << "Vvedite 2 chtobi sohranit mnozhestva v fail" << endl;
	cout << "Vvedite 3 chtobi dobavit mnozhestvo " << endl;
	cout << "Vvedite 4 chtobi vivesti mnozhestva " << endl;
	cout << "Vvedite 5 chtobi vipolnit operaciy " << endl;
	cout << "Vvedite 6 chtobi zakrit programmy \n" << endl;
}

```
## Main

Функции вызываются в соответствии с `Menu()`.

```C++

#include "Library.h"

int main()
{
	string UniRes;  
	string name; 
	vector <string> strCounter; 
	while (true) 
	{
		Menu(); 
		switch (_getch())
		{
		case '1':
		{
			cout << "1-open\n2-create" << endl;
			switch (_getch())
			{
			case '1':
			{
				cout << "Vvedite nazvanie faila" << endl;
				cin >> name;
				name += ".txt";
				ifstream in(name);
				if (in.is_open())
				{
					ReadFromFile(strCounter, in);
				}
				else
				{
					cout << "Oshibka otkritiya faila" << endl;
				}
				break;
			}
			case '2':
				cout << "Vvedite nazvanie faila" << endl;
				cin >> name;
				name += ".txt";
				ofstream out(name);
				break;
			}
			break;
		}
		case '2':
		{
			if (!name.empty())
			{
				ofstream out(name);
				WriteIntoFile(out, strCounter);
				out.close();
			}
			else
			{
				cout << "Fail ne zadan" << endl;
			}
			break;
		}
		case '3':
			AddStr(strCounter); 
			break;
		case '4':
			Show(strCounter);
			break;
		case '5':
		{
			UniRes.clear();
			operaciya(strCounter, UniRes);
			break;
		}
		break;
		case '6':
			exit(0);
			break;
		}

		system("pause");
		system("cls");

	}
	return 0;
}
```

##Library.h

```C++
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_set>

using namespace std; 

void Show(vector<string> strCounter); 
void AddStr(vector<string>& strCounter); 
void ReadFromFile(vector<string>& strCounter, ifstream& in); 
void WriteIntoFile(ofstream& out, vector <string>& strCounter); 
void operaciya(const vector<string>& strCounter, string& Results); 
void Menu(); 
```



## Вывод
Реализовал алгоритм `симметрической разности`
## Источники
В ходе лабораторной работы никакие источники не были использованы
