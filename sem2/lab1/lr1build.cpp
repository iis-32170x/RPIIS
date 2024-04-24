
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "list.h"

using namespace std;

void InputFromTestFile(int** arr, int* len)
{
	string resp = "", temp;
	ifstream fin;
	cout << "Enter path" << endl;
	cin >> resp;
	fin.open(resp);
	resp = "";
	for (int i = 0; i < 6; i++)
	{
		getline(fin, temp);
		resp += temp;
	}
	cout << resp << endl;
	fin.close();
	int ind1 = resp.find('{', 0);
	int ind2 = resp.find('}', ind1 + 1);
	ind1++;
	*len = stoi(resp.substr(ind1, ind2 - ind1));
	int* arr2 = new int[*len];
	*arr = arr2;
	ind1 = resp.find('{', ind2 + 1);
	ind1++;

	for (int i = 0; i < *len; i++)
	{
		ind2 = resp.find(',', ind1);
		arr2[i] = stoi(resp.substr(ind1, ind2 - ind1));
		ind1 = ind2 + 1;
	}
}

void InputFromConsole(int** arr, int* len)
{
	cout << "Enter list length" << endl;
	cin >> *len;
	int* arr2 = new int[*len];
	*arr = arr2;
	cout << "Enter  elements: " << endl;
	for (int i = 0; i < *len; i++)
	{
		cout << i + 1 << ": ";
		cin >> arr2[i];
	}
}

void CommandSwitcher(Quenue **Top1, Quenue **Top2)
{
	string command;
	while (true)
	{
		cout << "Choose action: join | intersect | removeAt | find | sort | insertAt | exit" << endl;
		cin >> command;
		if (command == "join")
		{
			Quenue* sum = Join(*Top1, *Top2);
			ConsoleOutput(sum);
			RemoveQuenue(&sum);
			continue;
		}
		if (command == "intersect")
		{
			Quenue* inter = Intersect(*Top1, *Top2);
			ConsoleOutput(inter);
			RemoveQuenue(&inter);
			continue;
		}
		if (command == "removeAt")
		{
			cout << "Choose quenue (1 | 2)" << endl;
			int q, ind;
			cin >> q;
			cout << "Enter index" << endl;
			cin >> ind;
			if (q == 1)
			{
				RemoveAt(Top1, ind);
				ConsoleOutput(*Top1);
			}
			else if (q == 2)
			{
				RemoveAt(Top2, ind);
				ConsoleOutput(*Top2);
			}
			continue;
		}
		if (command == "find")
		{
			cout << "Choose quenue (1 | 2)" << endl;
			int q, value, resp = -1;
			cin >> q;
			cout << "Enter value" << endl;
			cin >> value;
			if (q == 1)
			{
				resp = FindItem(*Top1, value);
			}
			else if (q == 2)
			{
				resp = FindItem(*Top2, value);
			}
			cout << "Index: " << resp << endl;
			continue;
		}
		if (command == "sort")
		{
			cout << "Choose quenue (1 | 2)" << endl;
			int q;
			cin >> q;
			if (q == 1)
			{
				SortQuenue(Top1);
				ConsoleOutput(*Top1);
			}
			else if (q == 2)
			{
				SortQuenue(Top2);
				ConsoleOutput(*Top2);
			}
			continue;
		}
		if (command == "insertAt")
		{
			cout << "Choose quenue (1 | 2)" << endl;
			int q, ind, data;
			cin >> q;
			cout << "Enter index and data" << endl;
			cin >> ind >> data;
			if (q == 1)
			{
				InsertAt(Top1, ind, data);
				ConsoleOutput(*Top1);
			}
			else if (q == 2)
			{
				InsertAt(Top2, ind, data);
				ConsoleOutput(*Top2);
			}
			continue;
		}
		if (command == "exit") return;
	}
}

int main()
{
	int len, * arr, i1, i2, i3, numb, resp;
	cout << "Select input option: 1 - testfile; 2 - console" << endl;
	cin >> resp;
	if (resp == 1) {
		InputFromTestFile(&arr, &len);
	}
	else
	{
		InputFromConsole(&arr, &len);
	}

	Quenue* Top = NULL;
	CreateQuenueFromPtr(arr,len,&Top);
	ConsoleOutput(Top);

	cout << "Select input option: 1 - testfile; 2 - console" << endl;
	cin >> resp;
	if (resp == 1) {
		InputFromTestFile(&arr, &len);
	}
	else
	{
		InputFromConsole(&arr, &len);
	}

	Quenue* Top2 = NULL;
	CreateQuenueFromPtr(arr, len, &Top2);
	ConsoleOutput(Top2);

	CommandSwitcher(&Top,&Top2);

	RemoveQuenue(&Top);
	RemoveQuenue(&Top2);
	return 0;
}


