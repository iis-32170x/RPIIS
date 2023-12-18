<h1 align="center">Отчет по расчетной работе по дисциплине ПиОИвИС.</a> 

## Цель:

Ознакомиться с основами теории графов, способами представления графов, базовыми алгоритмами для работы с разными видами графов.

## Условие задания:

>*Вариант 4.7* 

Реализовать на С++ программу для нахождения большого модулного произведения двух неориентированных графов. Способ задания графов - cписок ребер(перечень ребер), ми*.

## Базовые понятия:

- ***Граф*** - совокупность двух множеств множества самих объектов, называемого множеством вершин, и множества их парных связей, называемого множеством рёбер.

- ***Неориентированный граф*** - граф, в котором все ребра являются звеньями, то есть порядок двух концов ребра графа не существенен.
  
<h4 align="center"> Примеры неориентированного графа:</a>
	
![Снимок экрана 2023-12-18 224934](https://github.com/iis-32170x/RPIIS/assets/145003765/b0bbae84-718c-46fa-acc0-6de7ffe2a77c)

- ***Список ребер*** - способ представления графов, при котором для каждого ребра графа хранится пара номеров вершин, которые оно соединяет.

  <h4 align="center"> Примеры списка(перечня) ребер:</a>

  ![пр](https://github.com/iis-32170x/RPIIS/assets/145003765/994f5ea1-4047-4a6b-8c86-d9c796fa64c1)


- ***Матрица инцидентности*** — одна из форм представления графа, в которой указываются связи между инцидентными элементами графа (ребро(дуга) и вершина).

  <h4 align="center"> Примеры матрицы инцидентности:</a>

  ![ми](https://github.com/iis-32170x/RPIIS/assets/145003765/9cfad8dc-79c7-4929-b0ee-f03fb52b3ec8)


- ***Большое модульное произведение*** - операция на графах, которая комбинирует их с заданной модульной операцией. Она определена на множестве всех возможных пар вершин из двух графов.

 > Большое модульное произведение $G_{1} \Diamond G_{2}$ двух неориентированных графов содержит рёбра $((x^{1},x^{2}), (y^{1},y^{2})) \in E(G_{1} \Diamond G_{2})$ тогда и только тогда, когда $x^{1} \neq y^{1}, x^{2} \neq y^{2}$ и либо $(x^{1},y^{1}) \in E_{1}$ и $(x^{2},y^{2}) \in E_{2}$, либо $(x^{1},y^{1}) \not \in  E_{1}$, где 
$x^{1}$ и $y^{1} \in E_1$, $x^{2}$ и $y^{2} \in E_2$, $E_1$ – множество ребер первого графа, $E_2$ – множество ребер второго графа.

## Описание алгоритма
- Получаем два графа из выбранных пользователем файлов (пользователь вводит путь к файлу).
- Создаём массив со всеми возможными точками конечного графа.
- Задаём циклы, в которых проверяем условия необходимые для получения ребер результата большого модульного произведения графов, для каждой пары точек массива со всеми возможными точками конечного графа:
   *  Проверяем условие $x^{1} \neq y^{1}, x^{2} \neq y^{2}$, если оно не выполняется берём другую пару точек.
   *  Проверяем условие $(x^{1},y^{1}) \in E_{1}$, если условие не выполняется переходим к пункту **(*)**
   *  Проверяем условие $(x^{2},y^{2}) \in E_{2}$, если условие не выполняется берем другую пару точек.
   *  Запиываем в файл ребро в виде $(x^{1},x^{2}), (y^{1},y^{2})$ **(*)**
- Сообщаем пользователью имя файла, в который записан конечный граф.

## Код

```

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

vector<int*> InputGraph(char* filename) {
	FILE* file = fopen(filename, "r");
	int edge, vertex_1, vertex_2;
	vector<int*> graph;
	while (fscanf(file, "%d:%d %d", &edge, &vertex_1, &vertex_2) != -1) {		//получаем значения из файла
		int* _edge = new int[2];				//создаем массив из двух элементов (динамический, потому что идет запись в вектор указателей)
		_edge[0] = vertex_1;					//записываем первую точку из строки как нулевой элемент массива
		_edge[1] = vertex_2;					//записываем вторую точку из строки как второй элемент массива
		if (graph.size() < edge)				//увеличение размера графа на 1, для записи в него еще одного элемента
			graph.resize(edge);
		graph[edge - 1] = _edge;				//записываем массив как последний элемент массива
	}
	fclose(file);
	return graph;
}
void LargeModularProduct(vector<int*> graph_1, vector<int*> graph_2) {			//функция для выполнения операции большого модульного произведения(на вход поступает 2 графа)
	int max_1 = 0, max_2 = 0;			//задаем две переменные для нахождения максимального номера точки в каждом из двух графов
	for (int i = 0; i < graph_1.size(); i++) {			//Находим максимальный номер точки в первом графе
		if (graph_1[i][0] > max_1) max_1 = graph_1[i][0];
		if (graph_1[i][1] > max_1) max_1 = graph_1[i][1];
	}
	for (int i = 0; i < graph_2.size(); i++) {			//Находим максимальный номер точки во втором графе
		if (graph_2[i][0] > max_2) max_2 = graph_2[i][0];
		if (graph_2[i][1] > max_2) max_2 = graph_2[i][1];
	}

	ofstream vertices_file("graph.txt");		//создаем файл, в который записываем все возможные точки конечного графа
	for (int i = 1; i <= max_1; i++) {
		for (int j = 1; j <= max_2; j++) {
			vertices_file << i << " " << j << endl;
		}
	}
	vertices_file.close();
	FILE* vertices_filei = fopen("graph.txt", "r");								//окрываем файл graph.txt для записи
	vector<int*> vertices;				//вектор для записи всех возможных точек конечного графа 
	int vertex_1, vertex_2, edge = 1;
	while (fscanf(vertices_filei, "%d %d", &vertex_1, &vertex_2) != -1) {	//цикл для записи всех возможных точек конечного графа в вектор vertices	
		int* _edge = new int[2];
		_edge[0] = vertex_1;
		_edge[1] = vertex_2;
		if (vertices.size() < edge)
			vertices.resize(edge);
		vertices[edge - 1] = _edge;
		edge++;																//
	}
	fclose(vertices_filei);

	edge = 1;
	ofstream final_graph("graph.txt");			//пересоздаем пустым файл graph.txt и открываем его для записи
	for (int i = 0; i < max_1 * max_2; i++) {
		if (vertices[i][0] != vertices[i][1]) {						//проверяем выполнение условия x1 != y1
			for (int j = 0; j < max_1 * max_2; j++) {
				if (vertices[j][0] != vertices[j][1]) {				//проверяем выполнение услловия x2 != y2
					for (int edge_is_element_of_graph_1 = 0; edge_is_element_of_graph_1 < graph_1.size(); edge_is_element_of_graph_1++) {
						if (((vertices[i][0] == graph_1[edge_is_element_of_graph_1][0]) && (vertices[i][1] == graph_1[edge_is_element_of_graph_1][1])) ||
							((vertices[i][1] == graph_1[edge_is_element_of_graph_1][0]) && (vertices[i][0] == graph_1[edge_is_element_of_graph_1][1]))) {			//проверяем, что две взятые точки образуют ребро, которое принадлежит первому графу
							for (int edge_is_element_of_graph_2 = 0; edge_is_element_of_graph_2 < graph_2.size(); edge_is_element_of_graph_2++) {
								if (((vertices[j][0] == graph_2[edge_is_element_of_graph_2][0]) && (vertices[j][1] == graph_2[edge_is_element_of_graph_2][1])) ||
									((vertices[j][1] == graph_2[edge_is_element_of_graph_2][0]) && (vertices[j][0] == graph_2[edge_is_element_of_graph_2][1]))) {	//проверяем, что две взятые точки образуют ребро, которое принадлежит второму графу
									final_graph << "(" << vertices[i][0] << ", " << vertices[j][0] << ")-(" << vertices[i][1] << ", " << vertices[j][1] << ")\n";	//записываем ребро в файл graph.txt
								}
							}
						}
						else {		//если две взятые точки не образуют ребро, которое принадлежит первому графу
							final_graph << "(" << vertices[i][0] << ", " << vertices[j][0] << ")-(" << vertices[i][1] << ", " << vertices[j][1] << ")\n";			//записываем ребро в файл graph.txt
						}
					}
				}
			}
		}
	}
	final_graph.close();
	cout << "Результат записан в файл \"graph.txt\"";
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[30];
	cout << "Введите путь к 1 файлу(графу): ";
	cin >> filename;
	vector<int*> graph_1 = InputGraph(filename);
	cout << "Введите путь ко 2 файлу(графу): ";
	cin >> filename;
	vector<int*> graph_2 = InputGraph(filename);
	LargeModularProduct(graph_1, graph_2);
}
```
## Пример работы программы

<h3 align="center"> Пример №1 </a>
	
<h4 align="center"> От пользователя поступает 2 графа (graph_1, graph_3): </a>
	
![13](https://github.com/iis-32170x/RPIIS/assets/145003765/3783525b-544e-4c21-8cbb-6958e8cb88a2)

![ср13](https://github.com/iis-32170x/RPIIS/assets/145003765/481882b9-9171-4283-a12b-2a803204e641)


![1-3](https://github.com/iis-32170x/RPIIS/assets/145003765/e049bc09-1976-423b-9800-140108f471fb)

<h3 align="center"> Пример №2 </a>
	
<h4 align="center"> От пользователя поступает 2 графа (graph_2, graph_5): </a>

![25](https://github.com/iis-32170x/RPIIS/assets/145003765/66d95b13-b3a8-4fdb-a3be-c1ca79d70468)

![ср25](https://github.com/iis-32170x/RPIIS/assets/145003765/52ade89c-8784-4f3c-81df-1b6cc160f216)

![2-5](https://github.com/iis-32170x/RPIIS/assets/145003765/d40d1588-e34c-4460-8894-a2a616da8ed9)

<h3 align="center"> Пример №3 </a>

<h4 align="center"> От пользователя поступает 2 графа (graph_4, graph_2): </a>


![42](https://github.com/iis-32170x/RPIIS/assets/145003765/2fd9fa2b-2ff1-430d-9eae-fe48aed02afc)

![ср42](https://github.com/iis-32170x/RPIIS/assets/145003765/1fe5bfc8-f0f5-4741-acad-7fafa3cb8864)

 ![4-2](https://github.com/iis-32170x/RPIIS/assets/145003765/9184ae35-3232-465e-85a9-31cf96206b2c)

## Вывод:
В результате выполнения данной работы были получены следующие практические навыки:

- изучены основы теории графов
- изучены способы представления графов
- изучены базовые алгоритмы для работы с графами

## Список использованных источников:
- https://ru.wikipedia.org/wiki
- https://graphonline.ru/
- https://habr.com/ru/company/otus/blog/568026/
- https://habr.com/ru/company/otus/blog/675730/
- http://pco.iis.nsk.su/grapp/index.php/%D0%9F%D1%80%D0%BE%D0%B8%D0%B7%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5_%D0%B3%D1%80%D0%B0%D1%84%D0%BE%D0%B2
- Гладков Л.А., Курейчик В.В., Курейчик В.М. Дискретная математика / Под ред. В.М. Курейчика. — М.: ФИЗМАТЛИТ, 2014. — 496 с. —
ISBN 978-5-9221-1575-9.
