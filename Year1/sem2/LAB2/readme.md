
# Лабораторная работа № 2

## Вариант 3

## Цель

Цель работы - разработать программу для работы с множествами, обеспечиваю

### Задание

Реализовать код на языке `С++`, который создает и обрабатывает бинарное дерево поиска.
### Ключевые понятия
`Множество` - это иерархическая структура данных, в которой каждый узел имеет не более двух потомков.
`Узел бинарного дерева` - это основная структурная единица бинарного дерева.

> [!NOTE]
> Реализация структуры, конструкторов и создания множества из строки была позаимствована у Самовича Вячеслава за что ему выражается огромная благодарность.

### Структура множества
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

### Функции программы
`Создание множества из строки`
```c++
Arr* CreateArrFromString(string str) // Создаём множество из строки
{
	Arr* result;
	int startPos = 0;
	int endPos = 0;
	int count = 0;
	string type;
	int openArr = 0;
	int openCourt = 0;
	if (str == "{}") // Проверка на пустое множество
	{
		result = new Arr("array", "0");
		return result;
	}
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
	//cout << "number of items: " << count << endl;
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
`Проверка строки`
```c++
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
```
`Удаление множества`
```c++
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
```
`Отображение элементов`
```c++
void ShowArrayElements(Arr* arr, int level = 0)// отображение элементов множества
{
	if (arr->Type == "element")
	{
		// Отступ 
		for (int i = 0; i < level; i++)
		{
			cout << "  ";
		}

		cout << arr->NumberOfItems << endl;
	}
	else if (arr->Type == "cortege" || arr->Type == "array")
	{
		// Отступ 
		for (int i = 0; i < level; i++)
		{
			cout << "  ";
		}

		cout << arr->Type << ":" << endl;

		for (int i = 0; i < stoi(arr->NumberOfItems); i++)
		{
			ShowArrayElements(arr->InnerItems[i], level + 1);
		}
	}
}
```
`Функция равенства двух элементов`
```c++
bool IsEqual(Arr* item1, Arr* item2) // равенство двух элементов множеств
{
	if (item1 == nullptr || item2 == nullptr)
		return false;

	return item1->Type == item2->Type && item1->NumberOfItems == item2->NumberOfItems;
}
```
`Функция, которая проверяет все множества на уникальность элементов`
```c++
bool isUniqueSet(Arr** sets, int numSets) {
	for (int i = 0; i < numSets; i++) {
		Arr* set = sets[i];
		for (int j = 0; j < std::stoi(set->NumberOfItems); j++) {
			Arr* item1 = set->InnerItems[j];
			bool found = false;
			for (int k = j + 1; k < std::stoi(set->NumberOfItems); k++) {
				Arr* item2 = set->InnerItems[k];
				if (item1 != nullptr && item2 != nullptr) {
					if (IsEqual(item1, item2)) {
						found = true;
						break;
					}
				}
			}
			if (found) {
				return false;
			}
		}
	}
	return true;
}
```
`Функция Симметрической разности для произвольного кол-ва множеств`
```c++
Arr* ExcludeNonUniqueElements(Arr** sets, int numSets) { //исправленная симметрическая разность
	std::vector<std::string> strArr;
	std::unordered_map<std::string, int> elementCountMap;

	// Подсчет вхождений каждого элемента
	for (int i = 0; i < numSets; i++) {
		Arr* set = sets[i];
		for (int j = 0; j < std::stoi(set->NumberOfItems); j++) {
			Arr* innerItem = set->InnerItems[j];
			if (innerItem->Type == "element") {
				std::string element = innerItem->NumberOfItems;
				elementCountMap[element]++;
			}
		}
	}

	// Удаление неуникальных элементов
	for (int i = 0; i < numSets; i++) {
		Arr* set = sets[i];
		for (int j = 0; j < std::stoi(set->NumberOfItems); j++) {
			Arr* innerItem = set->InnerItems[j];
			if (innerItem->Type == "element") {
				std::string element = innerItem->NumberOfItems;
				if (elementCountMap[element] == 1) {
					strArr.push_back(element);
				}
			}
		}
	}


	std::string mergedString;
	mergedString = "{";
	for (const std::string& str : strArr) {
		mergedString += str + ",";
	}

	if (!strArr.empty()) {
		mergedString.pop_back(); 
	}
	mergedString += "}";
	return CreateArrFromString(mergedString);
}
```
## Результаты тестирования
Проверим нашу программу на примере теста:
 `Результат выполнения программы`
![image](https://github.com/iis-32170x/RPIIS/assets/146393417/287f85b6-3fac-4add-8a0f-0956ebd33ae4)


## Вывод
В результате выполнения данной работы были получены следующие практические навыки:
- изучение базовых алгоритмов для работы с множествами
