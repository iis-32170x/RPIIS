# *Расчётная работа*
## Введение
### Цель
Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами.
### Задание
5.6 Найти вершины с указанной степенью.

Реализовать на C++ код, который находит вершины графа с указанной степенью.

Граф(ориентированный) представляется в виде списка смежности(списка инцидентности).
### Ключевые понятия
`Граф` - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

`Неориентированный граф` — граф, рёбрам которого не присвоено направление.

`Список смежности` - один из способов представления графа в виде коллекции списков вершин. Каждой вершине графа соответствует список, состоящий из «соседей» этой вершины.

`Декартово произведение графов` - Декартовым произведением G₁ и G₂ графов называется граф G(V,E) со множеством вершин V = X x Y, в котором дуга (ребро) из вершины (xᵢ, yⱼ)в вершину (xₖ, yₗ) существует тогда и только тогда, когда существуют дуги (рёбра) (xᵢ, xₖ) ∈ E₁ и (yⱼ, yₗ) ∈ E₂ одновременно.

## Алгоритм решения
Получаем из 1-ого файла 1-ый граф в виде списка смежности. Получаем из 2-ого файла 2-ой граф в виде списка смежности. Затем выполняем декартово произведение этих 2-ух графов следующим образом: ![Визуализация](https://github.com/iis-32170x/RPIIS/assets/144227421/e71e3764-f865-43b4-a373-26368af95329) Затем выводим получившийся граф в файл.
## Реализация на С++
Код, выполняющий приведённый алгоритм:
```C++
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string graphpath1, graphpath2, onestr, strbuf;
	char swit;
	ifstream filewgr1, filewgr2;
	int numbuf = 0;

	vector <vector<int>> graph1;
	vector <vector<int>> graph2;
        vector<int> vecbuf;

	string fingrpath = "D:\\rr\\result.txt";

	cout << "1st GRAPH FILENAME PATH (including file; e.g. D:\\rr\\graph1.txt): "; cin >> graphpath1; cout << endl;
	cout << "2nd GRAPH FILENAME PATH (including file; e.g. D:\\rr\\graph2.txt): "; cin >> graphpath2; cout << endl;
	cout << "CHANGE FINAL GRAPH FILENAME PATH (including file; by default: D:\\rr\\result.txt)? y - yes, n - no" << endl;
	cin >> swit;
	if (swit == 'y')
	{
		cout << "CHANGE FINAL GRAPH FILENAME PATH (including file;  e.g. D:\\rr\\result.txt):" << endl;
		cin >> fingrpath;
	}


	filewgr1.open(graphpath1);

	if (!filewgr1.is_open())
	{
		cout << "ERROR" << endl;
		return -1;
	}
	else
	{
		cout << "FILE IS OPENED";

		while (getline(filewgr1, onestr))
		{
			for (int i = 1; i <= onestr.length(); i++)
			{
				if (onestr[i] != ',' && onestr[i] != ' ')
				{
					strbuf = strbuf + onestr[i];
				}
				else {
					try
					{
						numbuf = stoi(strbuf);
						vecbuf.push_back(numbuf);
					}
					catch(invalid_argument)
					{
					}
					strbuf.clear();
				}
			}
			numbuf = stoi(strbuf);
			vecbuf.push_back(numbuf);

			graph1.push_back(vecbuf);
			vecbuf.clear();
			strbuf.clear();
		}

		cout << endl;
		cout << "First graph:" << endl;

		for (int i = 0; i < graph1.size(); i++)
		{
			cout << i << " ";
			for (int j = 0; j < graph1[i].size(); j++)
			{
				cout << graph1[i][j] << " ";
			}
			cout << endl;
		}
	}
	filewgr1.close();

	cout << endl;

	filewgr2.open(graphpath2);

	if (!filewgr2.is_open())
	{
		cout << "ERROR" << endl;
		return -1;
	}
	else
	{
		cout << "FILE IS OPENED";

		while (getline(filewgr2, onestr))
		{
			for (int i = 1; i <= onestr.length(); i++)
			{
				if (onestr[i] != ',' && onestr[i] != ' ')
				{
					strbuf = strbuf + onestr[i];
				}
				else {
					try
					{
						numbuf = stoi(strbuf);
						vecbuf.push_back(numbuf);
					}
					catch (invalid_argument)
					{
					}
					strbuf.clear();
				}
			}
			numbuf = stoi(strbuf);
			vecbuf.push_back(numbuf);

			graph2.push_back(vecbuf);
			vecbuf.clear();
			strbuf.clear();
		}

		cout << endl;
		cout << "Second graph:" << endl;

		for (int i = 0; i < graph2.size(); i++)
		{
			cout << i << " ";
			for (int j = 0; j < graph2[i].size(); j++)
			{
				cout << graph2[i][j] << " ";
			}
			cout << endl;
		}
	}
	filewgr2.close();

	cout << endl;

    ofstream fingraph;
	fingraph.open(fingrpath);


	for (int i = 0; i < graph1.size(); i++)
	{
		for (int j = 0; j < graph2.size(); j++)
		{
			fingraph << i << j << " ";
			for (int k = 0; k < graph2[j].size(); k++)
			{
				fingraph << i << graph2[j][k] << " ";
			}

			for (int l = 0; l < graph1[i].size(); l++)
			{
				fingraph << graph1[i][l] << j << " ";
			}
			fingraph << endl;
		}

		fingraph << endl;
	} 

	fingraph.close();
}
```
## Разбор кода
1. `#include <vector>, #include <fstream>, #include <string>` : подключение библиотек, отвечающих за работу с векторами и сторонними файлами.
2. `string graphpath1, graphpath2, onestr, strbuf; char swit; ifstream filewgr1, filewgr2; int numbuf = 0; vector <vector<int>> graph1; vector <vector<int>> graph2; vector<int> vecbuf; string fingrpath = "D:\\rr\\result.txt";` : инициализация переменных.
     - *string graphpath1, graphpath2* : строки, содержащие путь до текстовых файлов, в которых находятся графы 1 и 2.
     - *string onestr* : в эту переменную записывается поочерёдно строки из текстового файла для дальнейшей обработки.
     - *string strbuf* : буферная переменная для перевода чисел из вида string в int.
     - *char swit* : переключатель для смены пути вывода для файла с результатом.
     - *ifstream filewgr1, filewgr2* : переменные для чтения информации из .txt файла.
     - *int numbuf = 0* : буферная переменная для записи чисел, полученных из strbuf.
     - *vector <vector<int>> graph1; vector <vector<int>> graph2* : двумерные вектора - репрезентация графов.
     - *vector<int> vecbuf* : буферный вектор для создания двумерных векторов.

## Тестирование
Все тесты и наглядные изображения графов, участвующих в них, можно посмотреть [здесь]
## Вывод
