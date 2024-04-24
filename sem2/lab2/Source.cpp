#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct element 
{
	int multipl;
	string name;
};

int Max(int a, int b) 
{
	if (a > b)
	{
		return a;
	}
	else return b;
}

void ShowSet(vector<element>& Set)
{
	if (Set.size() != 0) 
	{
		cout << "{";
		for (int i = 0; i < Set.size(); i++)
		{
			if (i != Set.size() - 1) 
			{
				cout << Set[i].multipl << Set[i].name << ",";
			}
			else 
			{
				cout << Set[i].multipl << Set[i].name << "}";
			}
		}
	}
}

int CountElem(string str)
{
	int count = 0;
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] == ',' || str[i] == '{' || str[i] == '<')
		{
			int j = ++i;
			int openS = 0;
			count++;
			while (str[j] != ',' && str[j] != '}' && str[j] != '>') 
			{
				if (s) 
				{

				}
			}
		}
	}
}
int main() 
{
	vector<element>Set(2);
	Set[0].multipl = 5;
	Set[0].name = "a";
	Set[1].multipl = 3;
	Set[1].name = "b";
	ShowSet(Set);
	

}