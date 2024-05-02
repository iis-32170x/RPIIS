#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<Windows.h>
using namespace std;

int CountStr(const string& file_name) 
{
	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Ошибка при открытии файла" << endl;
	}
	else 
	{
		int SetNum = 0;
		string str;
		while (getline(file, str))
		{
			SetNum++;
		}
		file.close();
		return SetNum;
	}
}


void MakeSet(const string & file_name,vector<vector<string>> & Set)
{
	ifstream file(file_name);
	if (!file.is_open()) 
	{
		cout << "Ошибка при открытии файла" << endl;
	}
	else 
	{
		int SetNum = CountStr(file_name);
		Set.resize(SetNum);
		for (int i = 0; i < SetNum; i++) 
		{
			string str;
			getline(file, str);
			string element;
			bool inner_elements = false;
			for (char StrSymbol : str)
			{
				if (StrSymbol == '{')
				{
					inner_elements = true;
					element += StrSymbol;
				}
				else if (StrSymbol == '}')
				{
					inner_elements = false;
					element += StrSymbol;

					if (element.size() == 2)
					{
						Set[i].push_back(element);
					}
					else
					{
						string in_brackets = element.substr(1, element.size() - 2);
						vector<string>InnerElements;
						string InnerElement;
						for (char InnerSymbol : in_brackets) 
						{
							if (InnerSymbol == ' ') 
							{
								if (!InnerElement.empty())
								{
									InnerElements.push_back(InnerElement);
									InnerElement.clear();
								}
							}
							else
							{
								InnerElement += InnerSymbol;
							}
						}
						if (!InnerElement.empty())
						{
							InnerElements.push_back(InnerElement);
						}
						sort(InnerElements.begin(), InnerElements.end());
						element = "{";
						for (const string& SortedElement : InnerElements) 
						{
							element += SortedElement + " ";
						}
						element.pop_back();
						element += "}";
						Set[i].push_back(element);
					}
					element.clear();
				}
				else if (StrSymbol == ' ' && !inner_elements)
				{
					if (!element.empty()) 
					{
						Set[i].push_back(element);
						element.clear();
					}
				}
				else 
				{
					element += StrSymbol;
				}
			}
			if (!element.empty()) 
			{
				Set[i].push_back(element);
			}
		}
		file.close();
	}
}

vector<vector<pair<string, int>>> MultiplCount(const vector<vector<string>>& Set) 
{
	vector<vector<pair<string, int>>> multipl_count(Set.size());
	for (int i = 0; i < Set.size(); i++) 
	{
		vector<string>elements;
		vector<int>multipl;
		for (const string& item : Set[i]) 
		{
			bool found = false;
			for (int j = 0; j < elements.size(); j++) 
			{
				if (elements[j] == item) 
				{
					multipl[j]++;
					found = true;
					break;
				}
			}
			if (!found) 
			{
				elements.push_back(item);
				multipl.push_back(1);
			}
		}
		for (int j = 0; j < elements.size(); j++) 
		{
			multipl_count[i].push_back(make_pair(elements[j], multipl[j]));
		}
	}
	return multipl_count;
}

vector<pair<string, int>> Union(const vector<vector<pair<string, int>>>& multipl_count) 
{
	vector<pair<string, int>> Union;
	for (const auto& Set : multipl_count)
	{
		for (const auto& pair : Set) 
		{
			bool found = false;
			for (auto& max_multipl : Union) 
			{
				if (max_multipl.first == pair.first) 
				{
					max_multipl.second = max(max_multipl.second, pair.second);
					found = true;
					break;
				}
			}
			if (!found)
			{
				Union.push_back(pair);
			}
		}
	}
	return Union;
}

void Result(const vector<pair<string, int>>& Union) 
{
	cout << "Union:" << endl;
	for (const auto& pair : Union)
	{
		for (int i = 0; i < pair.second; i++) 
		{
			cout << pair.first << " ";
		}
	}
	cout << endl;
}


int main() 
{
	int choice=0;
	string FileName;
	do 
	{
		cout << "Выберите номер теста(1-3)" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			FileName = "test1.txt";
			break;
		case 2:
			FileName = "test2.txt";
			break;
		case 3:
			FileName = "test3.txt";
			break;
		default:
			cout << "Некорректное значение, введите цифру от 1 до 3" << endl;
			choice = 0;
			break;
		}
	} while (choice == 0);
	vector<vector<string>> Set;
	MakeSet(FileName, Set);
	vector<vector<pair<string, int>>>count = MultiplCount(Set);
	vector < pair < string, int>> Res = Union(count);
	Result(Res);
}