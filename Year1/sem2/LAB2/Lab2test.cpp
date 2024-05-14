/**************************************************
Название: SymmetricDifference
Разработчик: Германенко Владислав
Дата: 06.05.2024
Описание:
Программа получает количество множеств,
читает пронумерованно записанные множества,
производит рассчет симметрической разности.
**************************************************/
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <unordered_map>
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
			InnerItems = new Arr * [stoi(numberOfItems)]();
		}
		else if (type == "element")
		{
			Type = type;
			NumberOfItems = numberOfItems;
			InnerItems = NULL;
		}
	}
	~Arr() {
		if (InnerItems != nullptr) {
			delete[] InnerItems;
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
bool IsEqual(Arr* item1, Arr* item2) // равенство двух элементов множеств
{
	if (item1 == nullptr || item2 == nullptr)
		return false;

	return item1->Type == item2->Type && item1->NumberOfItems == item2->NumberOfItems;
}
string SymmetricDifferenceHelper1(Arr* set1, Arr* set2)// разность A/B
{
	std::vector<std::string> arr;
	//arr.push_back("{");
	int count = 0;
	Arr* result = new Arr("array", "0");

	for (int i = 0; i < stoi(set1->NumberOfItems); i++)
	{
		bool found = false;
		Arr* item1 = set1->InnerItems[i];

		for (int j = 0; j < stoi(set2->NumberOfItems); j++)
		{
			Arr* item2 = set2->InnerItems[j];

			if (item1 != nullptr && item2 != nullptr)
			{
				if (IsEqual(item1, item2)) {
					found = true;
					break;
				}
			}
		}

		if (!found)
		{
			arr.push_back(item1->NumberOfItems);
			arr.push_back(",");
			count++;
		}
	}
	if (!arr.empty()) arr.pop_back();
	
	std::string mergedString;
	for (const std::string& str : arr) {
		mergedString += str;
	}
	return mergedString;
	/*result = CreateArrFromString(mergedString);
	return result;*/
}
string SymmetricDifferenceHelper2(Arr* set1, Arr* set2) //Разность B/A
{
	std::vector<std::string> arr;
	//arr.push_back("{");
	int count = 0;
	Arr* result = new Arr("array", "0");

	for (int i = 0; i < stoi(set2->NumberOfItems); i++)
	{
		bool found = false;
		Arr* item1 = set2->InnerItems[i];

		for (int j = 0; j < stoi(set1->NumberOfItems); j++)
		{
			Arr* item2 = set1->InnerItems[j];

			if (item1 != nullptr && item2 != nullptr)
			{
				if (IsEqual(item1, item2)) {
					found = true;
					break;
				}
			}
		}

		if (!found)
		{
			arr.push_back(item1->NumberOfItems);
			arr.push_back(",");
			count++;
		}
	}
	if (!arr.empty()) arr.pop_back();

	std::string mergedString;
	for (const std::string& str : arr) {
		mergedString += str;
	}
	return mergedString;
	/*result = CreateArrFromString(mergedString);
	return result;*/
}
Arr* SymmetricDifferenceHelper3(Arr* set1, Arr* set2) { // создание результата симметрической разности
	string str;
	if (SymmetricDifferenceHelper2(set1, set2).empty()) {
		str = "{" + SymmetricDifferenceHelper1(set1, set2) + SymmetricDifferenceHelper2(set1, set2) + "}";
	}
	else {
		str = "{" + SymmetricDifferenceHelper1(set1, set2) + "," + SymmetricDifferenceHelper2(set1, set2) + "}";
	}
	Arr* result = CreateArrFromString(str);
	return result;
}
Arr* SymmetricDifference(Arr** sets, int numSets)
{
	if (numSets <= 0)
		return nullptr;

	Arr* result = sets[0];

	for (int i = 1; i < numSets; i++)
	{
		Arr* currentSet = sets[i];
		Arr* temp = SymmetricDifferenceHelper3(result, currentSet);
		delete currentSet;
		delete result;
		result = temp;
	}

	return result;
}
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
int main()
{
	setlocale(LC_ALL, "RU");
	int numSets;
	cout << "Enter the number of sets: ";
	cin >> numSets;
	getc(stdin);
	Arr** sets = new Arr * [numSets];

	for (int i = 0; i < numSets; i++)
	{
		string str;
		cout << "Enter set #" << (i + 1) << ": ";
		
		getline(std::cin, str);
		if (checkString(str))
		{
			sets[i] = CreateArrFromString(str);
		}
		else
		{
			cout << "Invalid string. Please try again." << endl;
			i--;
		}
	}
	bool result = isUniqueSet(sets, numSets);
	std::cout << std::boolalpha << result << std::endl;
	if (!result) {
		exit(0);
	}

	for (int i = 0; i < numSets; i++)
	{
		cout << "Set #" << (i + 1) << ":" << endl;
		ShowArrayElements(sets[i]);
		cout << endl;
	}
	/*Arr* simmetricdifference = SymmetricDifference(sets, numSets);

	cout << "Симметрическая разность множеств:" << endl;
	ShowArrayElements(simmetricdifference);*/
	
	Arr* simmetricdifference2 = ExcludeNonUniqueElements(sets, numSets);

	cout << "Симметрическая разность множеств:" << endl;
	ShowArrayElements(simmetricdifference2);
	

	// Очистка выделенной памяти
	/*for (int i = 0; i < numSets; i++)
	{
		RemoveArr(sets[i]);
	}
	
	delete[] sets;
	*/
	return 0;

}
// { 1, 2, 3, 4} { 1, 2} { 1, 2, 6}