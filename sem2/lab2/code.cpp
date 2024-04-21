#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

struct Arr // структура, описывающая множество
{
	string Type; // "element" "cortege" "array"
	string NumberOfItems;
	Arr** InnerItems;

	Arr() // пустой конструктор для множества
	{

	}

	Arr(string type, string numberOfItems) // конструктор с параметрами
	{
		if (type == "array" || type == "cortege")
		{
			Type = type;
			NumberOfItems = numberOfItems;
			InnerItems = new Arr * [stoi(numberOfItems)];
		}
		else if (type == "element")
		{
			Type = type;
			NumberOfItems = numberOfItems;
			InnerItems = NULL;
		}
	}
};

Arr* CreateArrFromString(string str) // Создаём множество из строки
{
	Arr* result;
	int startPos = 0;
	int endPos = 0;
	int count = 0;
	string type;
	int openArr = 0;
	int openCourt = 0;
	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i] == '{') openArr++;
		if (str[i] == '<') openCourt++;
		if (str[i] == '}') openArr--;
		if (str[i] == '>') openCourt--;
		if (str[i] == ',' && openArr == 0 && openCourt == 0) count++;
	}
	if (str[0] == '{') type = "array";
	else if (str[0] == '<') type = "cortege";
	else
	{
		Arr* arr = new Arr("element", str);
		return arr;
	}
	count++;
	result = new Arr(type, to_string(count));
	int i = 0;

	while (i < count)
	{
		if (startPos == 0 || str[startPos] == ',')
		{
			startPos++;
		}
		if (endPos == str.length() - 1 || str[endPos] == ',')
		{
			endPos--;
			openArr = 0;
			openCourt = 0;

			for (int j = 1; j <= endPos; j++)
			{
				if (str[j] == '{') openArr++;
				else if (str[j] == '<') openCourt++;
				else if (str[j] == '}') openArr--;
				else if (str[j] == '>') openCourt--;
			}
			if (openArr == 0 && openCourt == 0)
			{
				result->InnerItems[i] = CreateArrFromString(str.substr(startPos, endPos - startPos + 1));
				startPos = endPos + 1;
				endPos = startPos;
				i++;
			}
			else
			{
				endPos++;
			}
		}

		endPos++;
	}
	return result;
}

bool isSubset(Arr* arr1, Arr* arr2) // определяем является ли arr1 подмножеством arr2 
{
	bool isInSecond = false;
	if (arr1->Type != "element" && arr2->Type != "element")
	{
		for (int i = 0; i < stoi(arr1->NumberOfItems); i++)
		{
			for (int j = 0; j < stoi(arr2->NumberOfItems); j++)
			{
				if (arr1->InnerItems[i]->NumberOfItems == arr2->InnerItems[j]->NumberOfItems && arr1->InnerItems[i]->Type == arr2->InnerItems[j]->Type)
				{
					if (isInSecond == true) break;
					if (arr1->Type == "cortege" && j > i) return false; 
					isInSecond = isSubset(arr1->InnerItems[i], arr2->InnerItems[j]);
				}
			}
			if (!isInSecond) return false;
			isInSecond = false;
		}
	}
	else if (arr1->Type == "element" && arr2->Type == "element" && arr1->NumberOfItems == arr2->NumberOfItems)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkString(string str) // проверка на правильность введённой строки
{
	if (str.find("><") != -1) return false;
	if (str.find("}{") != -1) return false;
	int openArr = 0;
	int openCourt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '{') openArr++;
		if (str[i] == '<') openCourt++;
		if (str[i] == '}') openArr--;
		if (str[i] == '>') openCourt--;
	}
	if (openArr != 0 || openCourt != 0) return false;
	return true;
}

void RemoveArr(Arr* arr) // Очистка множества
{
	if (arr->Type == "element")
	{
		delete arr;
		return;
	}
	for (int i = 0; i < stoi(arr->NumberOfItems); i++)
	{
		RemoveArr(arr->InnerItems[i]);
	}
	delete arr;
	return;
}

void GetResult(Arr* arr1, Arr* arr2) // Получение результата
{
	if (isSubset(arr1, arr2) && isSubset(arr2, arr1)) cout << "множества A и B равны" << endl;
	else
	{
		cout << "множества A и B НЕ равны" << endl;
		if (isSubset(arr1, arr2)) cout << "A это подмножество множества В " << endl;
		else if (isSubset(arr2, arr1)) cout << "В это подмножество множества А" << endl;
		else
		{
			for (int i = 0; i < stoi(arr1->NumberOfItems); i++)
			{
				if (isSubset(arr1->InnerItems[i], arr2) && isSubset(arr2, arr1->InnerItems[i]))
				{
					cout << "В это элемент множества А" << endl;
					break;
				}
			}
			for (int i = 0; i < stoi(arr2->NumberOfItems); i++)
			{
				if (isSubset(arr2->InnerItems[i], arr1) && isSubset(arr1, arr2->InnerItems[i]))
				{
					cout << "А это элемент множества В" << endl;
					break;
				}
			}
		}

	}
}

int main()
{
	string str;
	ifstream fin;
	fin.open("tests.txt");
	Arr* a1 = NULL, * a2 = NULL;
	for (int i = 0; i < 6; i++)
	{
		fin >> str;
		cout << "A = " << str << endl;
		if (checkString(str)) a1 = CreateArrFromString(str);
		fin >> str;
		cout << "B = " << str << endl;
		if (checkString(str)) a2 = CreateArrFromString(str);
		if (a1 != NULL && a2 != NULL)GetResult(a1, a2);
		RemoveArr(a1);
		RemoveArr(a2);
		cout << endl;
		a1 = NULL;
		a2 = NULL;
	}

	while (true)
	{
		cout << "A = ";
		cin >> str;
		a1 = CreateArrFromString(str);
		cout << "B = ";
		cin >> str;
	    a2 = CreateArrFromString(str);
		GetResult(a1, a2);
		cout << endl;
	}



	return 0;
}
