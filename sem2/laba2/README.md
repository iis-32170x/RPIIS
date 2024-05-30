# Лабораторная работа №2
**Вариант №10**    
объединение множеств с учетом кратных вхождений
________________________________________________
## Цели лабораторной работы:
1. Разработать библиотеку для считывания из файла и работы с несколькими мультимножествами на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.
________________________________________________
## Задачи лабораторной работы
1. Изучить спецификацию задачи по работе с множествами.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для считывания из файла и нахождения симметрической разности нескольких мультимножеств.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.
________________________________________________
## Используемые понятия:
1.**Множество** - набор, совокупность каких-либо объектов

2.**объединение множеств** —  множество, содержащее в себе все элементы исходных множеств.

3.**объединение множеств с учетом кратных вхождений** —  множество, содержащее в себе все элементы исходных множеств.
________________________________________________
## Используемые алгоритмы:

1.**CountStr(string file_name):** 
Этот алгоритм подсчитывает количество строк в файле, указанном в file_name. Он делает это, используя ifstream для открытия файла, затем считывает каждую строку с помощью getline() и увеличивает счетчик count на 1 для каждой строки. Наконец, он возвращает значение count, которое представляет общее количество строк в файле.

  ```cpp
int CountStr(string file_name)
{
	ifstream file(file_name);
	int count = 0;
	string str;
	while (getline(file, str))
	{
		count++;
	}
	return count;
}
```
2. **IsCorrect(string& str):
Этот алгоритм проверяет, является ли строка str корректным представлением множеств. 
```cpp
bool IsCorrect(string& str)
{
	if (str.find("}{") != -1)
	{
		return false;
	}
	if (str.find(", ,") != -1)
	{
		return false;
	}
	int depth = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '{')
			depth++;
		if (str[i] == '}')
			depth--;
	}
	if (depth != 0)
	{
		return false;
	}
	return true;
}

```
3. **MakeUnion(string file_name):**
Этот алгоритм реализует создание объединения множеств, содержащихся в файле с именем file_name.

```cpp
void MakeUnion(string file_name)
{
	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	string Sets;
	cout << "Исходные множества:" << endl;
	int l = 0;
	while (l < CountStr(file_name))
	{
		if (l < CountStr(file_name) - 1)
		{
			string Set;
			getline(file, Set);
			cout << Set << endl;
			Set = Set.substr(1, Set.length() - 2);
			Sets += Set + " ";
			l++;
		}
		else
		{
			string Set;
			getline(file, Set);
			cout << Set << endl;
			Set = Set.substr(1, Set.length() - 2);
			Sets += Set;
			l++;
		}
	}
	if (!IsCorrect(Sets))
	{
		cout << "Ошибка в записи множеств в файле" << endl;
		return;
	}
	vector<vector<Element>> arr;
	int depth = 0;
	int i = 0;
	for (int k = 0; k < Sets.length(); k++)
	{
		Element elem;
		if (Sets[k] == '{')
		{
			elem.info += Sets[k];
			depth++;
			if (arr.size() <= 0)
			{
				arr.push_back(vector<Element>());
			}
			arr[i].push_back(elem);
		}
		else if (Sets[k] == '}')
		{
			elem.info += Sets[k];
			depth--;
			arr[i].push_back(elem);
		}

		else if (depth == 0 && Sets[k] == ' ')
		{
			i++;
			arr.push_back(vector<Element>());
			elem.info += " ";
			elem.depth = 1;
			arr[i].push_back(elem);
			i++;
			arr.push_back(vector<Element>());

		}
		else if (depth == 0 && Sets[k] == ',')
		{
			i++;
			arr.push_back(vector<Element>());
		}
		else if (depth == 0 && Sets[k] != ',')
		{
			elem.info += Sets[k];
			elem.depth = depth;
			elem.type = "Element";
			arr[i].push_back(elem);
		}
		else if (depth != 0)
		{
			elem.info += Sets[k];
			elem.depth = depth;
			elem.type = "Element";
			arr[i].push_back(elem);
		}

	}
	MakeElement(arr);
	Union(arr);
}

```
4.**MakeElement(vector<vector<Element>>& arr):**
Этот алгоритм добавляет в каждый вложенный вектор arr элемент, представляющий само множество. Он проходит по каждому вложенному вектору и создает новый элемент Element, объединяя все элементы внутри вектора. Если вложенный вектор содержит только пробел (" "), то новый элемент получает глубину -1.

5.**Swap(char& a, char& b):**
Этот простой алгоритм меняет местами значения двух переменных a и b типа char.

6.**Sort(string str):**
Этот алгоритм сортирует символы строки str в порядке убывания. Он использует два вложенных цикла для последовательного сравнения и обмена соседних символов, пока все символы не будут отсортированы.

```cpp
void MakeElement(vector<vector<Element>>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		Element element;
		for (int j = 0; j < arr[i].size(); j++)
		{
			element.info += arr[i][j].info;
			if (element.info == " ")
			{
				element.depth = -1;
			}
		}
		arr[i].insert(arr[i].begin(), element);
	}
}

void Swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

string Sort(string str)
{
	for (int i = 1; i < str.length(); i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str[i] < str[j])
			{
				Swap(str[i], str[j]);
			}
		}
	}
	return str;
}

```

7.**Union(vector<vector<Element>>& arr):**
Этот алгоритм создает объединение всех множеств, представленных в векторе arr.

8.**IsEqual(vector<vector<Element>>& arr, int pos1, int pos2):**
Эта функция сравнивает "Element" объекты в двух заданных позициях (pos1 и pos2) двумерного вектора arr

9.**SymbolNumber(vector<vector<Element>>& arr, int i):**
Эта функция подсчитывает количество "Element" объектов (за исключением первого элемента, который, вероятно, является меткой или заголовком) в векторе в позиции i двумерного вектора arr.

10.**ElemNumber(vector<vector<Element>>& arr, int j):**
Эта функция находит максимальное количество наборов "Element" объектов, которые имеют такие же свойства info и depth, как "Element" объект в позиции j двумерного вектора arr.

11.**main():**
Эта функция предлагает пользователю выбрать тестовый случай (1, 2 или 3) и затем вызывает функцию MakeUnion() (которая не предоставлена в фрагменте кода) с соответствующим именем файла.

```cpp
void Union(vector<vector<Element>>& arr)
{
	cout << "Объединение:" << endl;
	cout << "{";
	vector<pair<int, Element>>Union;
	for (int i = 0; i < arr.size(); i++)
	{
		Element elem;
		int count = 0;
		if (arr[i][0].info == " " && arr[i][0].depth == -1)
		{
			continue;
		}
		else
		{
			if (!arr[i][0].check)
			{
				elem = arr[i][0];
				count = ElemNumber(arr, i);
				Union.push_back(make_pair(count, elem));
			}
		}
	}
	int i = 0;
	for (i; i < Union.size() - 1; i++)
	{
		for (int j = 0; j < Union[i].first; j++)
		{
			cout << Union[i].second.info << ",";
		}
	}
	for (int j = 0; j < Union[i].first; j++)
	{
		cout << Union[i].second.info;
	}
	cout << "}";
}

bool IsEqual(vector<vector<Element>>& arr, int pos1, int pos2)
{
	int count = SymbolNumber(arr, pos1);
	for (int k = 1; k < arr[pos1].size(); k++)
	{
		if (arr[pos1][k].type == "Element")
		{

			for (int l = 0; l < arr[pos2].size(); l++)
			{
				if (Sort(arr[pos1][k].info) == Sort(arr[pos2][l].info) && arr[pos1][k].depth == arr[pos2][l].depth)
				{
					count--;
					break;
				}
			}
		}
	}
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int SymbolNumber(vector<vector<Element>>& arr, int i)
{
	int count = 0;
	for (int j = 1; j < arr[i].size(); j++)
	{
		if (arr[i][j].type == "Element")
		{
			count++;
		}
	}
	return count;
}

int ElemNumber(vector<vector<Element>>& arr, int j)
{
	Element& elem = arr[j][0];
	int max_num = 0;
	int max_set_num = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i][0].info == " " && arr[i][0].depth == -1)
		{
			arr[i][0].check = true;
			max_num = 0;
			continue;
		}
		if (Sort(elem.info) == Sort(arr[i][0].info) && IsEqual(arr, i, j))
		{
			arr[i][0].check = true;
			max_num++;
			if (max_set_num <= max_num)
			{
				max_set_num = max_num;
			}
		}
	}
	return max_set_num;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	string file_name;
	do {
		cout << "Выберите номер теста(1-3)" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			file_name = "test1.txt";
			break;
		case 2:
			file_name = "test2.txt";
			break;
		case 3:
			file_name = "test3.txt";
			break;
		default:
			cout << "Неправильный номер теста" << endl;
			choice = 0;
			break;
		}
	} while (choice == 0);
	MakeUnion(file_name);
}
```

____________________________________________

## <p align="center">Вывод:</p>
В ходе выполнения работы познакомился созданием библиотек в С++, реализоавал библиотеку работы со считыванием из файла и симметрической разностью,а также создал систему тестов,которая проверяет корректность созданной библиотеки, отточил свои навыки в создании структур и функций.


