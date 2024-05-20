# Лабораторная работа №2
Вариант 2. Реализовать программу, формирующую множество равное пересечению произвольного
количества исходных множеств (без учёта кратных вхождений элементов).

## Цели лабораторной работы:
Изучить свойства множеств с кратными и не кратными элементами. Разработать программу для работы с множествами.

## Список используемых понятий и алгоритмов:
1. **Множество:**
  Простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
2. **Кортеж (ориентированное множество):**
  Упорядоченная последовательность конечного числа элементов; упорядоченное множество натуральных чисел.
3. **Пересечение неориентированных множеств**
  Пересечением неориентированных множеств A и B с учётом кратных вхождений элементов
будем называть неориентированное множество S тогда и только тогда, когда для любого x
истинно S|x| = min{A|x|, B|x|}.

## Алгоритм
### Заголовочный файл intersect.h

#### Библиотеки для работы с консолью, строками, векторами, файлами и текстом:
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
```

#### Загрузка данных из текстового файла
```cpp
vector<string> get_f_file(vector<string> empt, string path)
{
	ifstream in_file;
	string oneline;
	in_file.open(path);

	if (!in_file.is_open())
	{
		cout << "Error occured, while opening file." << endl;
		exit(-1);
	}
	else
	{
		cout << "File is opened." << endl;

		while (getline(in_file, oneline))
		{
			empt.push_back(oneline);
		}
	}

	in_file.close();

	return empt;
}
```
Открываем файл по переданному пути -> проверяем, можно ли открыть файл -> построчно выгружаем данные из файла в вектор.

#### Функция очистки кратных элементов:
```cpp
string clean_kratn(string init)
{
	int k = 0;

	bool chk = false, is_cort = false;

	vector<string> temp_vec;

	string temp_str, str, res_str;

	for (int i = 0; i < init.length(); i++)
	{

		if (k >= 2 || (k == 1 && (init[i] == '{' || init[i] == '<')))
		{
			temp_str += init[i];
		}

		if (((init[i] == '{' || init[i] == '<') && k == 0) || (k == 1 && init[i] != '{' && init[i] != '<'))
		{
			str.push_back(init[i]);
		}

		if (k == 2 && (init[i] == '}' || init[i] == '>'))
		{
			temp_str = clean_kratn(temp_str);
			str += temp_str;
			temp_str.clear();
		}
		if (init[i] == '{' || init[i] == '<')
		{
			k++;
		}
		if (init[i] == '}' || init[i] == '>')
		{
			k--;
		}
	}

	k = 0;
	temp_str.clear();

	if (str[0] == '{')
	{
		res_str.push_back('{');
	}
	else
	{
		res_str.push_back('<');
		is_cort = true;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (k > 0)
		{
			if (k == 1 && str[i] != ',' && str[i] != ' ' && str[i] != '}' && str[i] != '>')
			{
				temp_str += str[i];
			}
			if (k >= 2)
			{
				temp_str += str[i];
			}
			if ((str[i] == ',' && k == 1 && temp_str != "") || ((str[i] == '}' || str[i] == '>') && k == 1 && temp_str != ""))
			{
				if (!is_cort)
				{
					for (int j = 0; j < temp_vec.size(); j++)
					{
						if (are_equal(temp_vec[j], temp_str))
						{
							chk = true;
						}
					}
				}
				if (!chk)
				{
					temp_vec.push_back(temp_str);
				}
				temp_str.clear();
				chk = false;
			}
		}
		if (str[i] == '{' || str[i] == '<')
		{
			k++;
		}
		if (str[i] == '}' || str[i] == '>')
		{
			k--;
		}
	}

	string mmm;

	if(!is_cort)
	{
		for (int i = 0; i < temp_vec.size() - 1; i++)
		{
			for (int j = 1; j < temp_vec.size(); j++)
			{
				if (temp_vec[i] > temp_vec[j])
				{
					mmm = temp_vec[i];
					temp_vec[i] = temp_vec[j];
					temp_vec[j] = mmm;
				}
			}
		}
	}

	for (int i = 0; i < temp_vec.size(); i++)
	{
		res_str += temp_vec[i];
		if (i < temp_vec.size() - 1)
		{
			res_str.push_back(',');
		}
	}
	if (str[0] == '{')
	{
		res_str.push_back('}');
	}
	else
	{
		res_str.push_back('>');
	}
	return res_str;
}
```

Идея следующая: на вход подается вектор, каждый элемент которого - строка-множество. Начинаем проходить строку, при обнаружении открывающей скобки подмножества набираем в временную строку и рекурсивно отправляем ее, пока не в переданном подмножестве не будет подмножеств. В этом минимальном подмножестве, учитывая кортеж ли это, убираем все повторяющиеся элементы и сортируем их. Рекурсивно поднимаемся на подмножество выше, повторяем операцию, считая подмножества обычными элементами.

#### Функция разбиения множества на элементы
```cpp
vector<vector<string>> divide_on_elements(vector<string> init)
{
	vector<vector<string>> reworked;
	vector<string> temp_vec;

	string temp_str;


	int k = 0;

	for (int i = 0; i < init.size(); i++)
	{
		for (int j = 0; j < init[i].length(); j++)
		{
			if (k > 0)
			{
				if (k == 1 && init[i][j] != ',' && init[i][j] != ' ' && init[i][j] != '}')
				{
					temp_str += init[i][j];
				}
				if (k >= 2)
				{
					temp_str += init[i][j];
				}
				if ((init[i][j] == ',' && k == 1 && temp_str != "") || (init[i][j] == '}' && k == 1 && temp_str != ""))
				{
					temp_vec.push_back(temp_str);
					temp_str.clear();
				}
			}
			if (init[i][j] == '{' || init[i][j] == '<')
			{
				k++;
			}
			if (init[i][j] == '}' || init[i][j] == '>')
			{
				k--;
			}
		}
		reworked.push_back(temp_vec);
		temp_vec.clear();
		temp_str.clear();
		k = 0;
	}

	return reworked;
}
```
Разделяем переданную, очищенную от кратных элементов, строку на элементы и загружаем элементы в вектор векторов.


#### Функция пересечения
```cpp
vector<string> intersect(vector<vector<string>> init)
{
	vector<string> t_vector = init[0];
	vector<string> res;

	int temp = 0, chk = 0;

	for (int k = 0; k < t_vector.size(); k++)
	{

		for (int i = 1; i < init.size(); i++)
		{
			for (int j = 0; j < init[i].size(); j++)
			{
				if (are_equal(t_vector[k], init[i][j]) && temp < i)
				{
					temp++;
				}
			}
		}

		if (temp == init.size() - 1)
		{
			for (int y = 0; y < res.size(); y++)
			{
				if (t_vector[k] == res[y])
				{
					chk++;
				}
			}

			if (!chk)
			{
				res.push_back(t_vector[k]);
			}
			else
			{
				chk = 0;
			}
		}

		temp = 0;
	}
	return res;
}

```
Выполняем поэлементное пересечение множеств.

### Исходный файл peresech.cpp

#### Реализация работы всех вышеописанных функций (меню)
```cpp
#include "intersect.h"

using namespace std;

int main()
{
	vector<string> sets, final_res;
	vector<vector<string>> sets_n_elem;

	string pathway;

	int k = 0;

	cout << "Input path to .txt file (for e.g. D:\\Work\\list.txt): " << endl;
	cin >> pathway;
	pathway = "NEW2.txt";

	sets = get_f_file(sets, pathway);

	cout << endl;


	for (int i = 0; i < sets.size(); i++)
	{
		for (int j = 0; j < sets[i].length(); j++)
		{
			if (sets[i][j] == '{' || sets[i][j] == '<')
			{
				++k;
			}
			if (sets[i][j] == '}' || sets[i][j] == '>')
			{
				--k;
			}
		}

		if (k)
		{
			cout << "ERROR. SET No." << i + 1 << " IS INCORRECT. (Check for amount of \"{\"\"}\")" << endl;
			exit(-1);
		}
		sets[i] = clean_kratn(sets[i]);
	}

	sets_n_elem = divide_on_elements(sets);

	for (int i = 0; i < sets_n_elem.size(); i++)
	{
		cout << "Set " << i + 1 << ": {";

		for (int j = 0; j < sets_n_elem[i].size(); j++)
		{
			cout << sets_n_elem[i][j];

			if (j < sets_n_elem[i].size() - 1)
			{
				cout << ",";
			}
		}

		cout << "}" << endl << endl;
	}

	final_res = intersect(sets_n_elem);

	cout << "Final set: {";
	for (int i = 0; i < final_res.size(); i++)
	{
		cout << final_res[i];
		if(i < final_res.size() - 1)
		{
			cout << ",";
		}
	}
	cout << "}";
}
}
```


## Тесты
![Näyttökuva 2024-05-20 113237](https://github.com/iis-32170x/RPIIS/assets/144227421/78fe3770-2981-40d5-ade8-e688968fced9)

![Näyttökuva 2024-05-20 113454](https://github.com/iis-32170x/RPIIS/assets/144227421/858a10a6-2c6b-4936-80df-9d72f2c842ff)

![Screenshot 2024-05-20 114539](https://github.com/iis-32170x/RPIIS/assets/144227421/b3214883-65a0-41e3-b434-351881c4d095)

![Screenshot 2024-05-20 114614](https://github.com/iis-32170x/RPIIS/assets/144227421/5358550c-f93c-4833-a281-17e8f3f19ffa)

## Вывод
В рамках данной лабораторной работы были изучена и разработана программа для реализации пересечения множеств.


## Источники
1. https://drive.google.com/drive/folders/1SLcF9njDTaNUacXMA9Nrqm7FUS7MnNsI

