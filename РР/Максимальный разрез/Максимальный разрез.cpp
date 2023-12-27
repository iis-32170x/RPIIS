#include<set>
#include<tuple>
#include<vector>
#include<fstream>
#include<conio.h>
#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");                 //Кириллица в консоли
	int number;
	fstream fin;
	cout << "Введите номер графа (от 1 до 5): " << endl;
	cin >> number;
	string file_paths[] = {                    //Массив строк с путями к файлам
	"C:\\Users\\Acer\\Desktop\\1 КУРС\\РР\\tests\\in1.txt",
	"C:\\Users\\Acer\\Desktop\\1 КУРС\\РР\\tests\\in2.txt",
	"C:\\Users\\Acer\\Desktop\\1 КУРС\\РР\\tests\\in3.txt",
	"C:\\Users\\Acer\\Desktop\\1 КУРС\\РР\\tests\\in4.txt",
	"C:\\Users\\Acer\\Desktop\\1 КУРС\\РР\\tests\\in5.txt"
	};

	if (number >= 1 && number <= 5) {
		fin.open(file_paths[number - 1], ios::in); //Ввод из файла с именем in в формате: первая строка - кол-во ребёр, последующие - структуры "Начальная_Вершина_n Конечная_Вершина_n Вес_Ребра_Связи"
	}
	else {
		cout << "Некорректный номер графа" << endl;
		return 1;                                 //Выход из программы в случае неверного ввода
	}
	ofstream fout("C:\\Users\\Acer\\Desktop\\1 КУРС\\РР\\tests\\result.txt");			//Вывод в файл с именем result в формате: первая строка - общий вес разреза, последующие строки - рёбра разреза

	vector<pair<pair<int, int>, int>> graph;	//Матрица инцидентности
	vector<int> value_versh;					//Вектор, отвечающий за вес каждой вершины
	set<int> versh_raz;							//Подмножество вершин, полученное в результате разреза
	int sum_value = 0;							//Суммарный вес разреза
	int N;										//Кол-во рёбер в графе
	fin >> N;									//Заполнение списка инцидентности
	int size = N;
	while (size) {
		int first_v;							//Первая вершина в ребре
		int second_v;							//Вторая вершина в ребре
		int value;								//Вес ребра
		fin >> first_v;
		fin >> second_v;
		fin >> value;
		graph.push_back(pair<pair<int, int>, int>(pair<int, int>(first_v, second_v), value));	//Добавление ребра в матрицу инцидентности
		size--;
	}
	value_versh.push_back(0);														//Добавление нулевой вершины, чтобы отсчёт вершин шёл с единицы
	for (int i = 1, value = 0; ; i++, value = 0) {									//Заполнение веса вершин, номер вершины = её индекс в векторе
		for (int j = 0; j < graph.size(); j++) {
			if (graph[j].first.first == i || graph[j].first.second == i)			//Если вершина принадлежит ребру
				value += graph[j].second;											//То добавить вес ребра к весу вершины
		}
		if (value == 0)	break;														//Если вес равен нулю, значит прошлая вершина была последняя	
		value_versh.push_back(value);												//Добавляем вес вершины в вектор 
	}
	do {
		int max = 0;
		for (int i = 1; i < value_versh.size(); i++) {
			if (value_versh[i] > value_versh[max]) max = i;							//Ищем вершину с максимальным весом		
		}
		if (value_versh[max] > 0) {													//Вес вершины должен быть больше нуля
			sum_value += value_versh[max];											//Прибавляем вес вершины в итоговый вес разреза
			value_versh[max] = 0;													//Обнуляем вес вершины, чтобы не взять её снова 
			versh_raz.insert(max);													//Добавляем эту вершину в множество
			for (int i = 0; i < graph.size(); i++) {								//Ищём рёбра инцидентные вершине с максимальным весом
				if (graph[i].first.first == max) {									//Вычитаем 2 раза вес инцидентного ребра из веса смежной вершины							
					value_versh[graph[i].first.second] -= graph[i].second * 2;		//Один раз вычитаем, потому что данное ребро пойдет в разрез
				}																	//Второй раз, чтобы проверить, выгодно ли добавлять смежную вершину в множество
				if (graph[i].first.second == max) {
					value_versh[graph[i].first.first] -= graph[i].second * 2;
				}																	//Вершина может стоять как на первом месте ребра, так и на втором
			}

		}
		else break;
	} while (1);
	fout << sum_value << endl;														//Выводим суммарный вес разреза
	for (const int& a : versh_raz)
	{
		for (int i(0); i < graph.size(); i++)										//Выводим все рёбра, входящие в разрез
		{
			if (graph[i].first.first == a && versh_raz.find(graph[i].first.second) == versh_raz.end())				//Если вершина стоит на первом месте ребра и вершина на втором месте 
				fout << graph[i].first.first << ' ' << graph[i].first.second << ' ' << graph[i].second << endl;		//не относится к тому же множеству
			if (graph[i].first.second == a && versh_raz.find(graph[i].first.first) == versh_raz.end())				//Если вершина стоит на втором месте ребра и вершина на первом месте 
				fout << graph[i].first.first << ' ' << graph[i].first.second << ' ' << graph[i].second << endl;		//не относится к тому же множеству
		}
	}
	cout << " Результат разреза записан в файл result.txt";
	_getch();
	return 0;
}