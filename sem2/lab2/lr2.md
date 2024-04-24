# Лабораторная работа 2
### группа 321701
### Самович Вячеслав
### Вариант 9
## Задание
Реализовать программу, определяющую является ли одно, либо оба из двух исходных
множеств подмножеством или элементом другого.
## 1. Структура, в которую записывается множество
```c++
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
			InnerItems = new Arr*[stoi(numberOfItems)];
		}
		else if (type == "element")
		{
			Type = type;
			NumberOfItems = numberOfItems;
			InnerItems = NULL;
		}
	}
};
```
String Type - поле для типа элемента множества. Может принимать значения 
"element" - для строки, символа или числа, "cortege" - для направленного множества.

String NumberOfItems - количество элементов множества или значение для последнего 
элемента.

Arr** InnerItems - элементы множества.

## 2. Различные функции в программе
### Создание множества из строки
```c++
Arr* CreateArrFromString(string str) // Создаём множество из строки
{
	//cout << "input:" << str << endl;
	Arr* result;
	int startPos = 0;
	int endPos = 0;
	int count = 0;
	string type;
	int openArr = 0;
	int openCourt = 0;
	for (int i = 1; i < str.length()-1; i++)
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
	result = new Arr(type,to_string(count));
	//cout << "number of items: " << count << endl;
	int i = 0; 

	while (i < count)
	{
		if (startPos == 0 || str[startPos] == ',')
		{
			startPos++;
		}
		if (endPos == str.length()-1 || str[endPos] == ',')
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
				//cout << str.substr(startPos, endPos - startPos + 1) << endl;
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
```
### 2.2 Определяем является ли arr1 подмножеством arr2 (равенство для кортежей)
```c++
bool isSubset(Arr* arr1, Arr* arr2)  
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
```
### 2.3 Проверка на правильность введённой строки
```c++
bool checkString(string str)
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
```
### 2.4 Удаление множества
```c++
void RemoveArr(Arr* arr) 
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
```

### 2.5 Получение результатов
```c++
void GetResult(Arr* arr1, Arr* arr2)
{
	if (isSubset(arr1, arr2) && isSubset(arr2, arr1)) cout << "equal" << endl;
	else
	{
		cout << "not equal" << endl;
		if (isSubset(arr1, arr2)) cout << "A is subset of B" << endl;
		else if (isSubset(arr2, arr1)) cout << "B is subset of A" << endl;
		else
		{
			for (int i = 0; i < stoi(arr1->NumberOfItems); i++)
			{
				if (isSubset(arr1->InnerItems[i], arr2) && isSubset(arr2, arr1->InnerItems[i]))
				{
					cout << "B is an element of A" << endl;
					break;
				}
			}
			for (int i = 0; i < stoi(arr2->NumberOfItems); i++)
			{
				if (isSubset(arr2->InnerItems[i], arr1) && isSubset(arr1, arr2->InnerItems[i]))
				{
					cout << "A is an element of B" << endl;
					break;
				}
			}
		}

	}
}
```

### 2.6 Ввод данных 
```c++
int main()
{
	string str;
	ifstream fin;
	fin.open("C:/Users/slavikovics/OneDrive/Desktop/Пиоивис 2 сем/lr2/tests.txt");
	Arr* a1 = NULL, *a2 = NULL;
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
    	return 0;
}
```

# Тестирование

Тестирование выполняется из файла:
```
{1,2,3,4}
{3,4}
{<1,2>,<2,3>}
<1,2>
{{1,2,3},<2,3>}
{1,2,3}
{a,b,c}
{a,b,c}
{<a,b>,<a,c>,<a,d>}
<a,c>
{{e,f,g}}
{{<a,b,c>},{<1,2>},{{e,f,g}}}
```

Пример выполнения программы:
```
A = {1,2,3,4}
B = {3,4}
not equal
B is subset of A

A = {<1,2>,<2,3>}
B = <1,2>
not equal
B is an element of A

A = {{1,2,3},<2,3>}
B = {1,2,3}
not equal
B is an element of A

A = {a,b,c}
B = {a,b,c}
equal

A = {<a,b>,<a,c>,<a,d>}
B = <a,c>
not equal
B is an element of A

A = {{e,f,g}}
B = {{<a,b,c>},{<1,2>},{{e,f,g}}}
not equal
A is an element of B
```