#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

void Show(vector<string> strCounter)
{
	cout << "Все множества: " << endl;
	for (int i = 0; i < strCounter.size(); ++i)
	{
		cout << "{" << strCounter[i] << "}" << endl;
	}

}

void AddStr(vector<string>& strCounter)
{
	cout << "Введите элементы множества\n "<< "Элементы разделяются только запятыми" << endl;
	string str;
	string temp;
	cin >> ws;
	getline(cin, str);
	for (int i = 0;i < str.size();i++)
	{
		if (str[i] != ' ')
		{
			temp += str[i];
		}
	}
	strCounter.push_back(temp);
	cout << "Множество добавлено " << endl;


}

void ReadFromFile(vector<string>& strCounter, ifstream& in)
{
	string str;
	strCounter.clear();
	while (getline(in, str))
	{
		//in.ignore();
		//getline(in, str);
		strCounter.push_back(str);
	}
	cout << "Файл успешно открыт" << endl;
	in.close();
}

void WriteIntoFile(ofstream& out, vector <string>& strCounter)
{
	for (int i = 0;i < strCounter.size(); i++)
	{
		out << strCounter[i] << endl;
	}
	cout << "Файл сохранён" << endl;
}


void Unite(vector<string> strCounter, string& UniteResults)
{
	if (strCounter.size() > 1)
	{
		Show(strCounter);
		string buffer{ };
		UniteResults = { };
		for (int i = 0;i < strCounter[0].size();i++)
		{
			UniteResults += strCounter[0][i];

		}
		int len = UniteResults.length();
		for (int k = 1;k < strCounter.size();k++)
		{
			int i = 0;
			while (i < strCounter[k].size())
			{
				for (;(strCounter[k][i] != ',') && (i < strCounter[k].size());i++)
				{
					buffer += strCounter[k][i];
				}
				if (UniteResults.find(buffer) > len)
				{
					UniteResults += ",";
					UniteResults += buffer;
					len = UniteResults.length();

				}
				i++;

				buffer = {};
			}

		}
		cout << "Объединение множеств: " << endl;
		cout << "{" << UniteResults << "}" << endl;;
	}
	else
	{
		cout << "Введено всего " << strCounter.size() << " множеств(а)" << endl;
	}
}

void Menu()
{
	cout << "Введите 1 чтобы открыть/создать файл " << endl;
	cout << "Введите 2 чтобы сохранить множества в файл" << endl;
	cout << "Введите 3 чтобы добавить множество " << endl;
	cout << "Введите 4 чтобы вывести множества" << endl;
	cout << "Введите 5 чтобы объединить множества" << endl;
	cout << "Введите 6 чтобы закрыть программу\n" << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");
	string UniRes;
	string name;
	vector <string> strCounter;
	while (true)
	{
		Menu();
		switch (_getch())
		{
		case '1':
		{
			cout << "1-открыть\n2-создать" << endl;
			switch (_getch())
			{
			case '1':
			{
				cout << "Введите название файла" << endl;
				cin >> name;
				name += ".txt";
				ifstream in(name);
				if (in.is_open())
				{
					ReadFromFile(strCounter, in);
				}
				else
				{
					cout << "Ошибка открытия файла " << endl;
				}
				break;
			}
			case '2':
				cout << "Введите название файла" << endl;
				cin >> name;
				name += ".txt";
				ofstream out(name);
				break;
			}
			break;
		}
		case '2':
		{
			if (!name.empty())
			{
				ofstream out(name);
				WriteIntoFile(out, strCounter);
				out.close();
			}
			else
			{
				cout << "Файл не задан" << endl;
			}
			break;
		}
		case '3':
			AddStr(strCounter);
			break;
		case '4':
			Show(strCounter);
			break;
		case '5':
			Unite(strCounter, UniRes);
			break;
		case '6':
			exit(0);
			break;
		}

		system("pause");
		system("cls");

	}
	return 0;
}