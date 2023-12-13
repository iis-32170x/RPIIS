# *Расчётная работа*
## Введение
### Цель
Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами.
### Задание
5.6 Найти вершины с указанной степенью.

Реализовать на C++ код, который находит вершины графа с указанной степенью.

Граф(неориентированный) представляется в виде списка смежности(списка инцидентности).
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
3. `cout << "1st GRAPH FILENAME PATH (including file; e.g. D:\\rr\\graph1.txt): "; cin >> graphpath1; cout << endl;` : ввод пути, где лежит файл с графом.
4. ```
   cout << "CHANGE FINAL GRAPH FILENAME PATH (including file; by default: D:\\rr\\result.txt)? y - yes, n - no" << endl;
	cin >> swit;
	if (swit == 'y')
	{
		cout << "CHANGE FINAL GRAPH FILENAME PATH (including file;  e.g. D:\\rr\\result.txt):" << endl;
		cin >> fingrpath;
	}
   ```
   : конструкция для смены пути вывода файла с финальным графом.
5. `filewgr1.open(graphpath1);` : открываем файл с графом.
6. ```
   if (!filewgr1.is_open())
       {
	  cout << "ERROR" << endl;
	  return -1;
       }
   ```
    : проверяем, успешно ли открылся файл.
7. `while (getline(filewgr1, onestr))` : берём 1-ну строку из файла.
8. `for (int i = 1; i <= onestr.length(); i++)` : для каждого символа строки, начиная со 2-го, выполняем следующие действия:
9. ```
        if (onestr[i] != ',' && onestr[i] != ' ')
        {
	      strbuf = strbuf + onestr[i];
        }
   ```
   : если символ не равен запятой или пробелу, то мы записываем этот символ в буферную строку
10. ```
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
    ```
    : в противном случае, если символ равен запятой или пробелу, то к этому моменту буферная строка уже может быть заполнена некоторым числом; тогда мы проверяем можно ли перевести из string в integer: если да, то переведённое число записываем в буферный вектор, если нет то "ловим" ошибку, что аргумент неверен. Очищаем буферную строку.
11. `numbuf = stoi(strbuf);` : (после последней цифры не стоит запятой или пробела, поэтому обрабатываем последнее число отдельно) Переводим последнее число из string в integer.
12. `vecbuf.push_back(numbuf);` : переведённое число записываем в буферный вектор.
13. `graph1.push_back(vecbuf);` : полученный буферный вектор, который содержит все числа 1-ой строки (кроме первого), т.е. вершины, которые связаны с 1-ой вершиной, записываем в 1-ый двумерный вектор - репрезентацию 1-ого графа.
14. `vecbuf.clear(); strbuf.clear();` : очищаем буферную строку, очищаем буферный вектор. Переходим ко 2-ой строке и выполняем те же действия, начиная с 8-ого пункта. Так перебираем все строки в файле.
15. ```
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
    ```
    : вывод 1-ого графа на экран.
16. `filewgr1.close();` : закрываем файл с 1-ым графом.
17. Выполняем пункт 5 - 16 для 2-ого графа.
18. `ofstream fingraph; fingraph.open(fingrpath);` : создаём переменную для записи файла с результатом.
19. ```
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
     ```
     : Операция декартова произведения:
    - Берем i = 1, где i = 1,n1 (n1 - кол-во вершин 1ого графа)
    - Для каждого i перебираем j, где j = 1, j = 1,n2 (n2 - кол-во вершин 1ого графа)
    - Получаем номер 1-ой вершины нового графа: ij
    - Вычисляем вершины, которые связанные с данной:
    - Берем каждую вершину k, которая связана с j вершиной и создаем новую вершину которая связана с ij: ik
    - Берем каждую вершину l, которая связана с i вершиной и создаем новую вершину которая связана с ij: lj

20.`fingraph.close();` : закрываем файл для записи.
## Тестирование
Все графы и их произведения можно посмотреть [здесь](https://github.com/iis-32170x/RPIIS/tree/%D0%9A%D0%B0%D1%80%D0%BF_%D0%93/RR/graphs).
## Вывод
