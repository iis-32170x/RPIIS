#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

struct Element
{
	string info;
	int depth;
	string type;
	bool check;
	Element(string Type = "Skobka", string Info = "", int Depth = 0, bool checked = false)//type(Skobra,Element)
	{
		depth = Depth;
		info = Info;
		check = checked;
		type = Type;
	}
};

int CountStr(string file_name);
bool IsCorrect(string& str);
void MakeUnion(string file_name);
void MakeElement(vector<vector<Element>>& arr);
void Swap(char& a, char& b);
void Union(vector<vector<Element>>& arr);
string Sort(string str);
bool IsEqual(vector<vector<Element>>& arr, int pos1, int pos2);
int SymbolNumber(vector<vector<Element>>& arr, int i);
int ElemNumber(vector<vector<Element>>& arr, int j);

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