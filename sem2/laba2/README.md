# Лабораторная работа по дисциплине ПиОИвИС №2, второй семестр

## Цель работы

Исследовать свойства структуры данных “множество” и разработать библиотеку для выполнения операции над множеством

## Индивидуальное задание №15
Реализовать программу, формирующую множество равное симметрической разности произвольного количества исходных множеств (без учёта кратных вхождений элементов).
## Ключевые понятия

***Множество*** — любая определенная совокупность объектов.

***Симметрическая разность*** — Множество C называется симметрической разностью множеств A и B, если C состоит из тех элементов и только тех элементов универсального множества U, которые принадлежат множеству A и не принадлежат множеству B или принадлежат множеству B и не принадлежат множеству A.

---

## Выполнение задания

Данная работа описывает взаимодействие с множествами в большинстве своём в виду работы со строками, поэтому порядок действий следующий: считываем файл с множествами в вектор строк (функция `readSets`), проверяем баланс скобок (просто лишняя проверка на входные данные, функция `bracketsBalance`), разбираем каждую строку на элементы вектора, которые в свою очередь являются элементами множества (функция `parseString`), убираем кратные вхождения (в том числе и в подмножествах, функции `removeMultiOccurence` и `removeDuplicatesRecursive`), выполняем симметрическую разность посредством объединением двух разностей обоих множеств (`set_difference` и `set_union`).

---
file_size(string path):
Эта функция принимает путь к файлу в качестве входных данных и возвращает количество строк в файле.
Она открывает файл с помощью ifstream, читает каждую строку с помощью getline() и увеличивает счетчик для отслеживания количества строк.
Если не удается открыть файл, она выводит сообщение об ошибке и не возвращает никакого значения.
```cpp
int file_size(string path) {
	int numLines = 0;
	ifstream fin(path);
	string unused;
	if (fin.is_open()) {
		while (getline(fin, unused)) {
			++numLines;
		}
		return numLines;
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
}

```

---

Функция `stringsAreEqual` предназначена для проверки эквивалентности множеств в виде `{1,2}` и `{2,1}` (запись разная, но множества одинаковые). Сначала происходит считывание строк в вектор элементов, а дальше преобразование в `set` строк (поскольку контейнер `set` заведомо не учитывает кратные вхождения элементов).

```cpp
bool stringsAreEqual(const string &str1, const string &str2) {
    if (str1.front() == '{' && str2.front() == '{') {
        vector<string> vec1 = parseString(str1);
        vector<string> vec2 = parseString(str2);
        set<string> set1(vec1.begin(), vec1.end());
        set<string> set2(vec2.begin(), vec2.end());
        return set1 == set2;
    }
    return str1 == str2;
}
```

---

get_line(int count, string path):
Эта функция принимает количество строк и путь к файлу в качестве входных данных и возвращает указанную строку из файла.
Она открывает файл с помощью ifstream, читает строки до указанного количества с помощью цикла, а затем читает и возвращает строку на этом счетчике.
Она также проверяет, равно ли количество открывающих и закрывающих фигурных/угловых скобок, и возвращает сообщение об ошибке, если это не так.
Если не удается открыть файл, она выводит сообщение об ошибке и не возвращает никакого значения.
```cpp
string get_line(int count, string path) {
	string line;
	int count_left = 0;
	int count_right = 0;
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		for (int i = 0; i < count; i++)
		{
			fin >> line;
		}
		for (int i = 0; i < line.size(); i++)
		{
			if ((line[i] == '{') or (line[i] == '<')) {
				count_left++;
			}
			if ((line[i] == '}') or (line[i] == '>')) {
				count_right++;
			}
		}
		if (count_left != count_right) {
			return "Ошибка в записи множества";
		}
		return line;
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
}
```
get_line(int count, string path):
Эта функция принимает количество строк и путь к файлу в качестве входных данных и возвращает указанную строку из файла.
Она открывает файл с помощью ifstream, читает строки до указанного количества с помощью цикла, а затем читает и возвращает строку на этом счетчике.
Она также проверяет, равно ли количество открывающих и закрывающих фигурных/угловых скобок, и возвращает сообщение об ошибке, если это не так.
Если не удается открыть файл, она выводит сообщение об ошибке и не возвращает никакого значения.
```cpp
string get_line(int count, string path) {
	string line;
	int count_left = 0;
	int count_right = 0;
	ifstream fin;
	fin.open(path);
	if (fin.is_open()) {
		for (int i = 0; i < count; i++)
		{
			fin >> line;
		}
		for (int i = 0; i < line.size(); i++)
		{
			if ((line[i] == '{') or (line[i] == '<')) {
				count_left++;
			}
			if ((line[i] == '}') or (line[i] == '>')) {
				count_right++;
			}
		}
		if (count_left != count_right) {
			return "Ошибка в записи множества";
		}
		return line;
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
}
```
---
massive_size(string mass[100]):
Эта функция принимает массив строк в качестве входных данных и возвращает количество непустых элементов в массиве.
Она проходит по массиву и считает количество элементов, пока не достигнет пустой строки.
```cpp
int massive_size(string mass[100]) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (mass[i] == "") {
			return count;
		}
		count++;
	}
}
```

---
check(string mass[100], string key):
Эта функция принимает массив строк и ключевую строку в качестве входных данных и возвращает 1, если ключ найден в массиве, или 0, если он не найден.
Она проходит по массиву и сравнивает каждый элемент с ключом.
```cpp
int check(string mass[100], string key) {
	for (int i = 0; i < 100; i++)
	{
		if (key == mass[i]) {
			return 1;
		}
	}
	return 0;
}

```

---

Symmetric_difference(string path):
Эта функция принимает путь к файлу в качестве входных данных и возвращает массив строк, содержащих симметричную разность между двумя множествами, представленными в файле.
Она читает файл построчно, извлекает элементы двух множеств и сохраняет их в отдельных массивах (plenty_1 и plenty_2).
Затем она сравнивает элементы в двух множествах и добавляет элементы, которые не являются общими для обоих множеств, в массив plenty_result.
Наконец, она возвращает массив plenty_1, который содержит симметричную разность.
```cpp
string* Symmetric_difference(string path) {
	int pov = 0;
	int ch = 0;
	int count = 1;
	int number_mass = 0;
	string* plenty_1 = new string[100];
	string* plenty_2 = new string[100];
	string* plenty_result = new string[100];
	char temp_p;
	bool flag_struct = false;
	string line = "";
	string temp = "";
	for (int i = 0; i < file_size(path); i++) {
		line = get_line(count, path);
		flag_struct = false;
		ch = 0;
		for (int j = 1; j < (line.size() - 1); j++)
		{
			if (((line[j] == '{') or (line[j] == '<')) and (flag_struct == true)) {
				ch++;
			}
			if ((line[j] == '{') or (line[j] == '<')) {
				flag_struct = true;
			}
			if (((line[j] == '>') or (line[j] == '}')) and (ch == 0)) {
				flag_struct = false;
			}
			if (((line[j] == '>') or (line[j] == '}')) and (ch > 0)) {
				ch--;
			}
			if ((line[j] == ',') && (count == 1) && (flag_struct == false)) {
				plenty_1[number_mass] = temp;
				temp = "";
				number_mass++;
				continue;
			}
			if ((line[j] == ',') && (count > 1) && (flag_struct == false)) {
				plenty_2[number_mass] = temp;
				temp = "";
				number_mass++;
				continue;
			}
			temp_p = line[j];
			temp += temp_p;
			if ((j == (line.size() - 2)) and (count == 1)) {
				plenty_1[number_mass] = temp;
				temp = "";
				number_mass++;
				break;
			}
			if ((j == (line.size() - 2)) and (count > 1)) {
				plenty_2[number_mass] = temp;
				temp = "";
				number_mass++;
				break;

			}
		}



		number_mass = 0;
		if (count == 1) {
			count++;
			continue;
		}
		else {
			for (int j = 0; j < massive_size(plenty_1);j++) {
				for (int k = 0; k < massive_size(plenty_2); k++) {
					if (plenty_1[j] == plenty_2[k]) {
						pov = 1;
						continue;
					}
				}
				if (pov == 0) {
					plenty_result[number_mass] = plenty_1[j];
					number_mass++;
				}
				pov = 0;
			}
			pov = 0;
			for (int j = 0; j < massive_size(plenty_2);j++) {
				for (int k = 0; k < massive_size(plenty_1); k++) {
					if (plenty_1[k] == plenty_2[j]) {
						pov = 1;
						continue;
					}
				}
				if (pov == 0) {
					plenty_result[number_mass] = plenty_2[j];
					number_mass++;
				}
				pov = 0;
			}
		}
		if (massive_size(plenty_1) > massive_size(plenty_result)) {
			for (int j = 0; j < massive_size(plenty_1); j++) {
				plenty_1[j] = plenty_result[j];
			}
		}
		if (massive_size(plenty_1) <= massive_size(plenty_result)) {
			for (int j = 0; j < massive_size(plenty_result); j++) {
				plenty_1[j] = plenty_result[j];
			}
		}
		for (int j = 0; j < massive_size(plenty_result); j++)
		{
			plenty_result[j] = " ";
		}
		for (int j = 0; j < massive_size(plenty_2); j++)
		{
			plenty_2[j] = " ";
		}
		number_mass = 0;
		temp = "";
		count++;
	}
	return plenty_1;
}

```

---

## Тестирование
Симметрическая разность основана на объединении разностей двух множеств

Входные данные:
```
{o,{},A}
{o,<1,2>,A2,c3,B,b3_A,{},{o,{},A}}
{o,A2,b3,A,<1,2>,{}}
```

Выходные данные:
```
Результат симметрической разности всех множеств: {c3, B, b3_A, {o,{},A}, o, b3, {}}
```
---
Входные данные:
```
{1,{{{1},2},3},{{2,<{1},{1}>,2},3}}
{{{{1},2},3}}
{1,{{{1},2},3},{{2,<{1},{1}>,2},3}}
```
Выходные данные:
```
Результат симметрической разности всех множеств: {{{{1},2},3}}
```
---

## Вывод
Была реализована библиотека для нахождения симметрической разности множеств.

---

## Источники
1. https://www.youtube.com/watch?v=dQw4w9WgXcQ

)
