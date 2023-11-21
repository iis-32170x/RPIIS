# Расчетная работа 

## Введение

### Цель
Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами, 
### Задание
3.6(Найти граф, являющийся объединением множества всех гамильтоновых циклов
графа)

Реализовать на C++ код, который может найти граф, являющийся объединением множества всех гамильтоновых циклов
графа.

Граф(ориентированный) представляется в виде списка смежности(списка инцидентности).

### Ключевые понятия
`Граф` - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

`Ориентированный граф (кратко орграф)` —  граф, рёбрам которого присвоено направление.

`Список смежности` - один из способов представления графа в виде коллекции списков вершин. Каждой вершине графа соответствует список, состоящий из «соседей» этой вершины.

`Путь в графе` – это последовательность рёбер, в которой конец каждого ребра (кроме последнего) совпадает с началом следующего.
Замкнутый путь называется `циклом`.

`Гамильтонов цикл` — цикл, проходящий через все вершины.

## Алгоритм решения
`Основная идея заключается в построении всех возможных путей от любой выбранной вершины(пусть это будет 0-ая вершина), определению среди них гамильтоновых циклов, и записи их в новый список смежности.`

Полчуем граф ввиде списка смежности. Начинаем новый путь из любой вершины. Берем первое возможное продолжение данного пути и сравниваем его по очереди со всеми членами данного пути, затем берем второе возможное продолжение данного пути и т.д. ...если в данном пути еще не было возможного продолжения, то возможное продолжение становится продолжением, создаем (n-1)(где n-число продолжений) копий нашего пути и записываем туда продолжения.Повторяем это со всеми путями, а после переходим к следующему шагу пути и повторяем все это и так пока не дойдем до путей которые соединяют все вершины(если путь оказался тупиковым(на любом шаге), помечаем его черной меткой).Пути которые замыкаются на 0-ую вершину записываем в новый список смежности.



## Реализация на C++

Код, выполняющий наш алгоритм:

```c++
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

void cicle(vector<vector<int>>& graph, int v, vector<vector<int>>& novigraph) {
	
	vector<vector<int>> pyts(1);
	int pyti{ 1 };
	pyts[0].push_back(0);

	for (int i{ 0 }; i < v; i++) {
		int obchiecopy{ 0 };

		for (int k{ 0 }; k < pyti; k++) {
			int copy{ -1 };
			bool vozvrat{ false };

			if (pyts[k][i] != -1) {
				for (int j : graph[pyts[k][i]]) {
					bool mojno_li_idti{ true };

					if (j == 0) {
						vozvrat = true;
					}

					for (int x : pyts[k]) {
						if (j == x) {
							mojno_li_idti = false;
						}
					}

					if (mojno_li_idti == true) {
						copy++;
						if (copy == 0) {
							pyts[k].push_back(j);
						}
						else {
							pyts.push_back(pyts[k]);
							pyts[pyti - 1 + copy + obchiecopy].erase(pyts[pyti - 1 + copy + obchiecopy].end() - 1);
							pyts[pyti - 1 + copy + obchiecopy].push_back(j);
						}
					}
					if (i == (v - 1) && vozvrat == true && copy == -1) {
						copy++;
						pyts[k].push_back(0);
					}
				}
			}
			else {
				pyts[k].push_back(-1);
			}

			if (copy == -1 && i != (v - 1)) {
				pyts[k].push_back(-1);
			}

			if (i == (v - 1) && vozvrat == true) {
				
				for (int z{ 1 }; z <= v; z++) {
					bool mojno_li_idti2{ true };
					for (int c : novigraph[pyts[k][z - 1]]) {
						if (c == pyts[k][z]) {
							mojno_li_idti2 = false;
						}
					}
					if (mojno_li_idti2 == true) {
						novigraph[pyts[k][z-1]].push_back(pyts[k][z]);
					}
				}
			}
			if (copy > 0) {
				obchiecopy += copy;
			}
		}
		pyti += obchiecopy;
	}
}


int main() {

	setlocale(LC_ALL, "RU");
	string stroka;

	cout << "Введите файл: ";
	cin >> stroka;

	ifstream inputFile(stroka);
	ofstream outputFile("novigraph.txt");

	int versh, svaz;
	inputFile >> versh >> svaz;

	vector<vector<int>> graph(versh);
	vector<vector<int>> novigraph(versh);

	for (int i{ 0 }; i < svaz; i++) {
		int a, b;
		inputFile >> a >> b;
		graph[a].push_back(b);
	}
	inputFile.close();

	cout << endl;
	cicle(graph, versh, novigraph);

	int g{ 0 };
	for (int i{ 0 }; i < versh; i++) {
		for (int k : novigraph[i]) {
			outputFile << i << " " << k << endl;
			g++;
		}
	}
	if (g == 0) {
		outputFile << "PYSTOE MNOJESTVO";
	}
	outputFile.close();
}
```

## Разбор кода:

- `#include <vector>`, `#include <fstream>` : библиотеки , которые предоставляют возможность использовать векторы и файлы.
- `void cicle(vector<vector<int>>& graph, int v, vector<vector<int>>& novigraph)`: Объявление функции cicle, которая принимает ссылку на вектор векторов graph(список смежности данного графа), целочисленное значение v, обозначающее количество вершин в графе, и ссылку на вектор векторов novigraph(список смежности нового графа). Функция ничего не возвращает.
- `vector<vector<int>> pyts(1)` : создаем вектор векторов в котором будут храниться пути.
- `int pyti{ 1 }` : счетчик путей.
- `pyts[0].push_back(0)` : добовляем начало пути вершину 0.
- `for (int i{ 0 }; i < v; i++)` : цикл в котором происходит шагание по пути.
- `int obchiecopy{ 0 }` : счетчик общих копий.
- `for (int k{ 0 }; k < pyti; k++)` : цикл в котором происходит перебор всех путей.
- `int copy{ -1 }` : количество копий.
- `bool vozvrat{ false }` : нужно для проверки на замыкание пути.
- `if (pyts[k][i] != -1)` : проверка на черную метку.
- `for (int j : graph[pyts[k][i]])` : цикл с перебором возможных продолжений пути.
- `bool mojno_li_idti{ true }` : нужно для проверки возможного продолжения на становление продолжением.
- `if (j == 0)` : проверка на замыкание.
- `for (int x : pyts[k]) { if (j == x)...` : проверка на становление продолжением.
- `if (mojno_li_idti == true){...}` : запись продолжений в пути.
- `if (i == (v - 1) && vozvrat == true && copy == -1)` : запись последней вершины 0.
- `pyts[k].push_back(-1)` : черная метка.
- if (i == (v - 1) && vozvrat == true){...}` : запись гамильтоновых циклов в новый граф.

После реализации алгоритма остаётся, лишь запросить у пользователя файл с ориентированным графом (в виде списка смежности) и вывести новый граф в новый файл.
```c++
int main() {

	setlocale(LC_ALL, "RU");
	string stroka;

	cout << "Введите файл: ";
	cin >> stroka;

	ifstream inputFile(stroka);
	ofstream outputFile("novigraph.txt");

	int versh, svaz;
	inputFile >> versh >> svaz;

	vector<vector<int>> graph(versh);
	vector<vector<int>> novigraph(versh);

	for (int i{ 0 }; i < svaz; i++) {
		int a, b;
		inputFile >> a >> b;
		graph[a].push_back(b);
	}
	inputFile.close();

	cout << endl;
	cicle(graph, versh, novigraph);

	int g{ 0 };
	for (int i{ 0 }; i < versh; i++) {
		for (int k : novigraph[i]) {
			outputFile << i << " " << k << endl;
			g++;
		}
	}
	if (g == 0) {
		outputFile << "PYSTOE MNOJESTVO";
	}
	outputFile.close();
}
```

## Тестирование
Все тесты и наглядное изображение графов можетете посмотреть  [тут]()

## Вывод
 
В результате выполнения расчётной работы приобрёл следующие навыки:
- изучил основы теории графов
- изучил способы представления графов
- изучил базовые алгоритмы для работы с графами
- изучил базовые алгоритмы работы с векторами, файлами в C++
