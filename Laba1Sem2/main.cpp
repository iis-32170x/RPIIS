#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include "..\StaticLib\Header.h"

using namespace std;


int SufMassiv()
{
	Laba1 laba1;
	int m;
	int Bufer;
	string Mas;
	int SufMas[100];
	string Suffix1;
	string Suffix2;
	cout << "Введите строку\n";
	cin >> Mas;
	m = size(Mas);


	for (int j = 0; j < m; j++)
	{
		SufMas[j] = j;
	}

	for (int i = 0; i < m - 1; i++)
	{

		Suffix1 = laba1.Suf(SufMas[i], m, Mas);
		Suffix2 = laba1.Suf(SufMas[i + 1], m, Mas);
		
		if (laba1.Sravn(Suffix1, Suffix2, m) == 1)
		{
			Bufer = SufMas[i + 1];
			SufMas[i + 1] = SufMas[i];
			SufMas[i] = Bufer;
			i = -1;

		}
	
	}
	for (int i = 0; i < m; i++)
	{
		cout << SufMas[i] << " ";
	}
	return 1;
}


int Sdvig()
{
	Laba1 laba1;
	int m, n = 2;
	string Mas;
	string Sdvig;
	cin >> Mas;
	string Min = Mas;
	m = size(Mas);
	for (int i = 0; i < m; i++)
	{
		Sdvig = laba1.SdvigMas(Mas, i, m);
		if (laba1.Sravn(Sdvig, Min, m) == 0)
		{
			Min = Sdvig;
		}
	}
	cout << Min;
	return 0;
}

int Prefix()
{
	Laba1 laba1;
	string str;
	cout << "Введите строку: ";
	cin >> str;

	vector<string> substrings = laba1.generateSubstrings(str);

	string longestPrefix = "";
	for (int i = 0; i < substrings.size(); i++) {
		for (int j = i + 1; j < substrings.size(); j++) {
			string prefix = laba1.longestCommonPrefix(substrings[i], substrings[j]);
			if (prefix.size() > longestPrefix.size()) {
				longestPrefix = prefix;
			}
		}
	}

	cout << "Наибольший общий префикс: " << longestPrefix << endl;

	return 0;
}

int main()
{
	
	setlocale(LC_ALL, "ru");
	int k;
	cout << "Выберите действие\n";
	cin >> k;
	switch (k)
	{
	case 1: SufMassiv(); break;
	case 2: Sdvig(); break;
	case 3: Prefix(); break;
	default: cout << "Не выбрана функция ";
	}
}