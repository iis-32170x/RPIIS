# Лабораторная работа №1

## Вариант 12

Условие:
> Таблица Юнга. Вставка элемента в таблицу. Удаление элемента из таблицы.

**Тема** - таблицы Юнга.

**Цель лабораторной работы** - разработка библиотеки для работы с таблицами Юнга.

**Задача лабораторной работы** - научиться работать со структурами и классами (в данном случае - при помощи C++).

## Определения, используемые при выполнении лабораторной работы

**Таблица Юнга** (далее в тексте "таблица") - структура данных, представляющая собой конечный набор ячеек или клеток, выровненных по левой границе, каждая из которых заполнена натуральными числами. В т.н. стандартной таблице Юнга длина каждой строки не больше предыдущей, числа возрастают в каждой строке и каждом столбце и при этом каждое число встречается в таблице ровно один раз.

## Полный код

Библиотека *YoungTableau.h*:
```cpp



#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

class YoungTableau {
public:
    void initialize(int row_number);
    size_t width();
    void add(int line_number, int element);
    void remove(int element, int line_number);
    void removeAll(int element);
    void print();
    void printToFile(std::string filename);
    void add1(int element, int line_number);

private:
    std::vector<std::vector<int>> table;
    int row_number; // Добавлено поле для хранения количества элементов в строке
};




```

Библиотека *YoungTableau.cpp*:
```cpp
#include "YoungTableau.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

void YoungTableau::initialize(int row_number)
{
	if (!table.empty())
	{
		for (auto& row : table)
			row.clear();
		table.clear();
	}
	this->row_number = row_number; // Инициализация поля row_number
	for (int i = 0; i < row_number; i++)
	{
		table.push_back({});
	}
}
size_t YoungTableau::width()
{
	return table.size();
}

void YoungTableau::add(int line_number, int element)
{
	if (line_number <= table.size())
	{
		auto& row = table[line_number - 1];
		if (row.size() <= row_number - line_number + 1) // Проверяем, что количество элементов в строке не превышает ограничение
		{
			row.push_back(element);
			std::sort(row.begin(), row.end());
		}
		else
		{
			std::cout << "Ошибка: Превышено ограничение на количество элементов в строке.\n";
		}
	}
	else
	{
		std::cout << "Ошибка: Недопустимый номер строки.\n";
	}
}

void YoungTableau::removeAll(int element)
{
	bool in_table = false;
	for (auto& row : table)
	{
		while (true)
		{
			auto it = std::find(row.begin(), row.end(), element);

			if (it != row.end())
			{
				row.erase(it);
				in_table = true;
			}
			else
				break;
		}
	}
	if (!in_table)
		std::cout << "Данного элемента нет в таблице.\n";
	else
		std::cout << "Из таблицы были удалены все элементы " << element << ".\n";
}

void YoungTableau::print()
{
	if (table.size() == 0)
		std::cout << "\nТаблица пуста.\n";
	bool nonempty_row = false;
	for (auto& row : table)
	{
		if (!row.empty())
		{
			nonempty_row = true;
			break;
		}
	}
	if (!nonempty_row)
	{
		std::cout << "\nТаблица пуста.\n";
		return;
	}
	std::cout << "\nТаблица Юнга:\n";
	for (auto& row : table)
	{
		for (int element : row)
		{
			std::cout << element << " ";
		}
		std::cout << "\n";
	}
}

void YoungTableau::printToFile(std::string filename)
{
	std::ofstream fout(filename);
	if (table.size() == 0)
		fout << "Таблица пуста.";
	fout << "Таблица Юнга:";
	for (auto& row : table)
	{
		fout << "\n";
		for (int element : row)
		{
			fout << element << " ";
		}
	}
	std::cout << "Таблица была выведена в " << filename << "\n";
}

void YoungTableau::add1(int element, int line_number)
{
	// Проверка допустимости номера строки
	if (line_number <= table.size())
	{
		auto& row = table[line_number - 1];

		// Проверка наличия элемента в строке
		if (std::find(row.begin(), row.end(), element) != row.end())
		{
			std::cout << "Ошибка: Элемент уже присутствует в таблице.\n";
			return;
		}

		// Поиск позиции для вставки элемента
		auto insert_pos = std::upper_bound(row.begin(), row.end(), element);

		// Если элемент больше всех элементов строки, вставляем его в конец
		if (insert_pos == row.end())
		{
			row.push_back(element);
			std::cout << "Элемент " << element << " добавлен в конец строки.\n";
		}
		else
		{
			// Замена элемента в строке
			int replaced_element = *insert_pos;
			*insert_pos = element;
			std::cout << "Элемент " << element << " заменяет элемент " << replaced_element << " в строке.\n";

			// Вставка вытесненного элемента в следующую строку
			if (line_number < table.size())
			{
				add1(replaced_element, line_number + 1);
			}
			else
			{
				std::vector<int> new_row = { replaced_element };
				table.push_back(new_row);
				std::cout << "Элемент " << replaced_element << " добавлен в новую строку.\n";
			}
		}
	}
	else
	{
		std::cout << "Ошибка: Недопустимый номер строки.\n";
	}
}

void YoungTableau::remove(int element, int line_number)
{
	// Проверка допустимости номера строки
	if (line_number > table.size() || line_number <= 0)
	{
		std::cout << "Ошибка: Недопустимый номер строки.\n";
		return;
	}

	// Поиск элемента в указанной строке
	auto& row = table[line_number - 1];
	auto it = std::find(row.begin(), row.end(), element);

	// Проверка наличия элемента в строке
	if (it == row.end())
	{
		std::cout << "Ошибка: Элемент не найден в таблице.\n";
		return;
	}

	// Удаление элемента из строки
	row.erase(it);
	std::cout << "Элемент " << element << " удален из строки " << line_number << ".\n";

	// Поиск предыдущей строки
	if (line_number > 1)
	{
		auto& previous_row = table[line_number - 2];

		// Проверка, является ли элемент наибольшим в предыдущей строке
		if (previous_row.empty() || element > previous_row.back())
		{
			previous_row.push_back(element);
			std::cout << "Элемент " << element << " добавлен в конец предыдущей строки.\n";
		}
		else
		{
			// Поиск первого элемента, меньшего заданного элемента, в предыдущей строке
			auto insert_pos = std::find_if(previous_row.begin(), previous_row.end(), [&](int num) {
				return num < element;
				});

			// Замена элемента в предыдущей строке
			int replaced_element = *insert_pos;
			*insert_pos = element;
			std::cout << "Элемент " << element << " заменяет элемент " << replaced_element << " в предыдущей строке.\n";

			// Вставка вытесненного элемента в предыдущую предыдущую строку (если есть)
			if (line_number > 2)
			{
				auto& prev_previous_row = table[line_number - 3];

				// Поиск первого элемента, меньшего вытесненного элемента, в предыдущей предыдущей строке
				auto insert_prev_pos = std::find_if(prev_previous_row.begin(), prev_previous_row.end(), [&](int num) {
					return num < replaced_element;
					});

				// Замена элемента в предыдущей предыдущей строке
				int replaced_prev_element = *insert_prev_pos;
				*insert_prev_pos = replaced_element;
				std::cout << "Элемент " << replaced_element << " заменяет элемент " << replaced_prev_element << " в предыдущей предыдущей строке.\n";
			}
			else
			{
				std::cout << "Элемент " << replaced_element << " удален из таблицы.\n";
			}
		}
	}
	else
	{
		std::cout << "Удаление завершено.\n";
	}
}
```
```
maim.cpp:


#include "YoungTableau.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{   
    setlocale(LC_ALL, "Ru");
    YoungTableau t;
    

    while (true)
    {
        std::cout << "\n1) Прочесть таблицу из файла";
        std::cout << "\n2) Просмотреть таблицу";
        std::cout << "\n3) Добавить элемент в таблицу";
        std::cout << "\n4) Удалить элемент из таблицы";
        std::cout << "\n5) Записать таблицу в файл";
        std::cout << "\n6) Выйти из программы";
        std::cout << "\nВыберите операцию: ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::string filename;
            std::cout << "Введите имя файла: ";
            std::cin >> filename;

            std::ifstream fin(filename);
            if (!fin)
            {
                std::cout << "Не удалось открыть файл.\n";
                continue;
            }

            std::string line;
            std::getline(fin, line);
            std::istringstream iss(line);
            int row_number;
            if (!(iss >> row_number))
            {
                std::cout << "Некорректный формат файла.\n";
                continue;
            }

            t.initialize(row_number);

            for (int i = 0; i < row_number; i++)
            {
                std::getline(fin, line);
                std::istringstream iss(line);
                int element;
                while (iss >> element)
                {
                    t.add(i + 1, element);
                }
            }

            std::cout << "Таблица успешно загружена из файла.\n";
        }
        else if (choice == 2)
        {
            t.print();
        }
        else if (choice == 3)
        {
            int line_number, element;

            std::cout << "Введите номер строки: ";
            std::cin >> line_number;

            std::cout << "Введите элемент: ";
            std::cin >> element;

            t.add1(element, line_number);
        }

        else if (choice == 4) {
            int element, line_number;

            std::cout << "Введите элемент: ";
            std::cin >> element;
            std::cout << "Введите номер строки: ";
            std::cin >> line_number;


           

            t.remove(element,line_number);
        }
        else if (choice == 5)
        {
            std::string filename;
            std::cout << "Введите имя файла: ";
            std::cin >> filename;

            t.printToFile(filename);
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            std::cout << "Некорректный выбор операции. Попробуйте ещё раз.\n";
        }
    }



    return 0;
}
```
## Описание кода пользовательской библиотеки *YoungTableau.h*
В этом коде определен класс YoungTableau, который имеет следующие члены:

Приватные члены:

std::vector<std::vector<int>> table: Вектор векторов, представляющий таблицу Юнга. Каждый внутренний вектор представляет строку таблицы, а элементы внутренних векторов представляют значения в соответствующих столбцах.
Публичные функции-члены:

void initialize(int row_number): Инициализирует таблицу Юнга с указанным количеством строк row_number.
size_t width(): Возвращает количество столбцов в таблице Юнга.
void add(int line_number, int element): Добавляет элемент element в указанную строку line_number таблицы Юнга.
void remove(int element): Удаляет первое вхождение элемента element из таблицы Юнга.
void removeAll(int element): Удаляет все вхождения элемента element из таблицы Юнга.
void print(): Выводит содержимое таблицы Юнга на стандартный вывод.
void printToFile(std::string filename): Выводит содержимое таблицы Юнга в указанный файл filename.



## Описание кода пользовательской библиотеки *YoungTableau.cpp*
Метод initialize(int row_number): Инициализирует таблицу Юнга с заданным числом строк. Если таблица уже существует, то она очищается и создается новая.

Метод width(): Возвращает количество строк в таблице.

Метод add(int line_number, int element): Добавляет элемент в указанную строку таблицы.

Метод remove(int element): Удаляет первое включение заданного элемента из таблицы. Если элемент не найден, выводится соответствующее сообщение.

Метод removeAll(int element): Удаляет все включения заданного элемента из таблицы. Если элемент не найден, выводится соответствующее сообщение.

Метод print(): Выводит таблицу Юнга на экран. Если таблица пуста, выводится сообщение об этом.

Метод printToFile(std::string filename): Выводит таблицу Юнга в указанный файл. Если таблица пуста, выводится соответствующее сообщение.

В коде используются стандартные библиотеки C++, такие как algorithm, iostream, fstream, и sstream. Эти библиотеки используются, например, для работы с файлами, поиска элементов в таблице, вывода сообщений и т.д.

Также в коде определен бесконечный цикл (не представлен в данном фрагменте кода), который представляет меню, где пользователю предлагаются различные действия над таблицами Юнга. При вводе определенных чисел (1-6) выбранный алгоритм применяется к таблице.

	
## Описание кода основной программы
Подключаются заголовочный файл "YoungTableau.h" и несколько стандартных библиотек C++, таких как iostream и fstream.
Создается объект класса YoungTableau с именем "t".
В бесконечном цикле выводится меню с доступными операциями пользователю.
Пользователь выбирает операцию, вводя соответствующую цифру.
В зависимости от выбора пользователя выполняется одна из операций:
Чтение таблицы из файла: Пользователь вводит имя файла, из которого нужно прочитать таблицу. Файл должен содержать первую строку с числом строк в таблице, а затем следующие строки должны содержать целые числа, разделенные пробелами. В результате таблица Юнга создается или обновляется.
Просмотр таблицы: Таблица Юнга выводится на экран.
Добавление элемента в таблицу: Пользователь вводит номер строки и элемент, который нужно добавить в таблицу.
Удаление элемента из таблицы: Пользователь вводит элемент, который нужно удалить из таблицы. Затем пользователь выбирает, нужно ли удалить только первое вхождение элемента или все вхождения.
Запись таблицы в файл: Пользователь вводит имя файла, в который нужно записать таблицу. Таблица записывается в указанный файл.
Выход из программы: Программа завершает свою работу.
После выполнения каждой операции, кроме выхода из программы, пользователь возвращается в меню и может выбрать следующую операцию.
В конце программы возвращается 0, указывая успешное завершение программы
		
## Тесты
Тестовые входные файлы и алгоритмы работы с ними заданы в репозитории.

Рассмотрим здесь тест №1 из репозитория.
Входной файл *file1.txt* имеет следующее содержание:
```
4
1 2 3
4 5 6
7 8
9
```
Что соответствует таблице Юнга:
![tableau1](https://github.com/iis-32170x/RPIIS/assets/146937124/335415ec-b6d1-4141-8218-7a49a7079b0c)



Далее были проведены следующие манипуляции:





<img width="392" alt="Снимок экрана 2024-03-19 094437" src="https://github.com/iis-32170x/RPIIS/assets/146937124/88df9d6a-757d-487d-bbb6-dbb2d8833d39">

...








<img width="544" alt="Снимок экрана 2024-03-19 094554" src="https://github.com/iis-32170x/RPIIS/assets/146937124/907301d2-f6c9-49f5-b5fe-726fc62def46">



...





<img width="235" alt="Снимок экрана 2024-03-19 094704" src="https://github.com/iis-32170x/RPIIS/assets/146937124/0b79ee67-5582-44bb-a057-b59938a680b4">




Результаты манипуляций соответствуют ожидаемым.

## Вывод

На C++ была создана библиотека, выполняющая основные действия с таблицами Юнга, а также программа с текстовым интерфейсом, приводящая данную библиотеку в действие.
