# Расчетная работа

## Введение
---
### Цель
Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами.
### Задание
5.2 Найти эйлеров цикл в графе 

Реализовать на C++ код, который может найти эйлеров цикл в неориентированном графе.

Граф представляется в виде матрицы смежности.

### Ключевые понятия
`Граф` - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

`Неориентированный граф (кратко орграф)` — это тип графа, в котором рёбра (или связи) между вершинами не имеют направления.

`Матрица смежности` - это способ представления графа в виде квадратной матрицы, где строки и столбцы представляют вершины графа, а значения в ячейках показывают наличие или отсутствие ребра между соответствующими вершинами.

`Путь в графе` – это последовательность рёбер, в которой конец каждого ребра (кроме последнего) совпадает с началом следующего.
Замкнутый путь называется `циклом`. 

`Эйлеров цикл` — это путь в графе, который проходит через каждое ребро ровно один раз и возвращается в начальную вершину. Эйлеров цикл существует только в графах, где все вершины имеют четную степень (количество инцидентных рёбер).

`Эйлеров путь` — это путь в графе, который проходит через каждое ребро ровно один раз. Однако, в отличие от Эйлерова цикла, Эйлеров путь не обязательно начинается и заканчивается в одной и той же вершине.

`Поиск в глубину (Depth-First Search, DFS)` — это один из основных алгоритмов обхода или поиска в графе. Он работает путем последовательного исследования каждой вершины и всех её потомков, находящихся на одном уровне, перед переходом к следующему уровню.

Графический пример обхода в ширину:

![image](https://intuit.ru/EDI/28_11_18_2/1543357168-6234/tutorial/909/objects/44/files/44_05.png)

## Алгоритм решения

Получаем и преобразуем матрицу смежности неориентированного графа (2 способа задания: файлом, с клавиатуры)

Проверяем основыные требования к эйлеровому графу: связность и четные степени всех вершин. Если условия не выполняются, то и смысла продолжнать программу нет, а значит в таком случае можем ее досрочно завершить.

Запускаем поиск в глубину, который учитывает пройденные вершины, помечая их в отдельном списке, и наличие связей, сравнивая значения в матрице смежности. DFS проходит по всем вершинам, а если выхода из вершины нет, то он делает шаг назад и перемещает вершину, из которой выхода нет, в эйлеров цикл. В результате мы получаем список, в котором находится эйлеров цикл.

Если эйлеров цикл обнаружен, мы выводим его, а также его длину, на экран. В противном случае выводим сообщение "The graph does not contain an euler's cycle.".

_Приведем приме выполнения алгоритма:_

Исходный граф:

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/EulersGraph10.jpg?raw=true)

Исходная матрица смежности:

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B01.png?raw=true)

Для наглядности будем использовать 2 списка: visited и euler. Общий принцин работы: заходим в вершину и помечаем ее как посещенную, ищем ближайшую непосещенную вершину, которая связана с нашей, и переходим в нее. Если выхода из вершины нет, то переносим вершину в список euler и делаем шаг назад, при это не восстанавливая связь.

1. Начинаем с вершины 0:

visited = [0]

euler = []

Ближайшая непосещенная вершина - 5

2. Заходим в вершину 5:

visited = [0,5]

euler = []

Ближайшая непосещенная вершина - 3


3. Заходим в вершину 3:

visited = [0,5,3]

euler = []

Ближайшая непосещенная вершина - 7


4. Заходим в вершину 7:

visited = [0,5,3,7]

euler = []

Ближайшая непосещенная вершина - 1



5. Заходим в вершину 1:

visited = [0,5,3,7,1]

euler = []

Ближайшая непосещенная вершина - 4


6. Заходим в вершину 4:

visited = [0,5,3,7,1,4]

euler = []

Ближайшая непосещенная вершина - 5


7. Заходим в вершину 5:

visited = [0,5,3,7,1,4,5]

euler = []

Ближайшая непосещенная вершина - 6


8. Заходим в вершину 6:

visited = [0,5,3,7,1,4,5,6]

euler = []

Ближайшая непосещенная вершина - 0


9. Заходим в вершину 0:

visited = [0,5,3,7,1,4,5,6,0]

euler = []

Как видно из матрицы смежности, выхода из вершины нет, а значит переносим вершину и делаем шаг назад.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B02.png?raw=true)

10. Вернулись к 6:

visited = [0,5,3,7,1,4,5,6]

euler = [0]

Ближайшая непосещенная вершина - 4


11. Заходим в вершину 4:

visited = [0,5,3,7,1,4,5,6,4]

euler = [0]

Ближайшая непосещенная вершина - 8


12. Заходим в вершину 8:

visited = [0,5,3,7,1,4,5,6,4,8]

euler = [0]

Ближайшая непосещенная вершина - 2


13. Заходим в вершину 2:

visited = [0,5,3,7,1,4,5,6,4,8,2]

euler = [0]

Ближайшая непосещенная вершина - 7

14. Заходим в вершину 7:

visited = [0,5,3,7,1,4,5,6,4,8,2,7]

euler = [0]

Ближайшая непосещенная вершина - 6


15. Заходим в вершину 6:

visited = [0,5,3,7,1,4,5,6,4,8,2,7,6]

euler = [0]

Как видно, выходна снова нет, повторяем операции до тех пор, пока не найдем выход.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B03.png?raw=true)

16. Вернулись в вершину 8:

visited = [0,5,3,7,1,4,5,6,4,8]

euler = [0,6,7,2]

Ближайшая непосещенная вершина - 3


17. Заходим в вершину 3:

visited = [0,5,3,7,1,4,5,6,4,8,3]

euler = [0,6,7,2]

Ближайшая непосещенная вершина - 9


18. Заходим в вершину 9:

visited = [0,5,3,7,1,4,5,6,4,8,3,9]

euler = [0,6,7,2]

Ближайшая непосещенная вершина - 8


19. Заходим в вершину 8:

visited = [0,5,3,7,1,4,5,6,4,8,3,9,8]

euler = [0,6,7,2]

Как видно, выходов нет и все вершины мы прошли, поэтому просто переносим по порядку все вершины из visited в euler

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B04.png?raw=true)


20. Переносим вершины.

visited = []

euler = [0,6,7,2,8,9,3,8,4,6,5,4,1,7,3,5,0]

Эйлеров цикл получен.
 
## Реализация на C++

Код, выполняющий наш алгоритм:

```c++
#include <iostream>
#include <vector>
#include <fstream>
#include <string> 
using namespace std;

void createMatrix(int vertexCount, vector<vector<int>>& matrix) {
	cout << "Select input type:" << endl << "0) Adjacency matrix from file." << endl << "1) Keyboard input using vertex connections." << endl;

	bool choice;
	cin >> choice;
	cout << endl;

	//file

	if (choice == 0) {
		cout << "Enter the absolute path to the file: ";

		string path;

		int i = 0, j = 0;
		char sim;

		cin >> path;
		cout << endl;

		ifstream myfile(path);
		if (myfile.is_open()) {
			while (myfile.get(sim)) {
				switch (sim) {
					case '1': {
						matrix[i][j] = 1;
						j++;
						break;
					}
					case '0': {
						matrix[i][j] = 0;
						j++;
						break;
					}
					case '\n': {
						j = 0;
						i++;
						break;
					}
				}
			}
			myfile.close();
		}
		else {
			cout << "Unable to open file";
			exit(0);
		}
	}

	// keybord

	if (choice == 1) {
		cout << "Enter the elements of an undirected graph with a connection (element numbers start from 0)." << endl;
		cout << "* If you want to stop entering, enter -1." << endl;

		while (true) {
			int a, b;
			cin >> a;
			if (a == -1) {
				cout << endl << "Entry completed." << endl;
				break;
			}
			cin >> b;

			matrix[a][b] = 1;
			matrix[b][a] = 1;
		}
	}

	// output matrix

	cout << "  ";

	for (int i = 0; i < vertexCount; i++) {
		cout << i << " ";
	}

	cout << endl;

	for (int i = 0; i < vertexCount; i++) {
		cout << i << " ";
		for (int j = 0; j < vertexCount; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


// DFS

bool DFS(int v, vector<int>& visited, vector<int>& euler, vector<vector<int>>& matrix) {
	visited.push_back(v);
	for (int i = 0; i < matrix.size(); ++i) {
		if (matrix[v][i] == 1 && i != visited[visited.size()-1]) {
			matrix[v][i] = 0;
			matrix[i][v] = 0;
			DFS(i, visited, euler, matrix);
		}
	}
	if (visited.empty()) {
		return 1;
	}
	euler.push_back(v);
	visited.pop_back();
	if (visited.empty()) {
		return 1;
	}
	v = visited[visited.size() - 1];
	visited.pop_back();
	DFS(v, visited, euler, matrix);
}

bool isEuler(int vertexCount, int startVetrex, vector<int>& visited, vector<int>& euler, vector<vector<int>>& matrix) {

	// check if number of vertices have odd degree 

	for (int i = 0; i < vertexCount; i++) {
		int counter = 0;
		for (int j = 0; j < vertexCount; j++) {
			if (matrix[i][j] == 1) {
				counter++;
			}
		}
		if (counter % 2 != 0 || counter == 0) {
			return 0;
		}
	}

	// start DFS

	return DFS(startVetrex, visited, euler, matrix);
} 

int main() {
	int vertexCount;
	cout << "Enter number of vertex: ";
	cin >> vertexCount;
	cout << endl;

	vector<vector <int>> matrix(vertexCount, vector<int>(vertexCount));

	createMatrix(vertexCount, matrix);

	cout << endl << "Enter the number of the vertex with which you want to start checking the cycle: ";
	int startVertex;
	cin >> startVertex;
	cout << endl;

	vector<int> visited;
	vector<int> euler;

	if (isEuler(vertexCount, startVertex, visited, euler, matrix)) {
		cout << "The graph contains an Euler cycle: ";
		for (int i = 0; i < euler.size(); i++) {
			cout << euler[i] << " ";
		}
		cout << endl;
		cout << "Eulerian cycle length: " << euler.size()-1;
	}
	else {
		cout << "The graph does not contains an Euler cycle." << endl;
	}
}
```

## Тестирование

Результаты выполнения программы для 3 случаев: 2 эйлерова графа и 1 обычный граф. Способа задания 2. Также есть пример при неправильном вводе абсолютного пути к файлу.

1) Эйлеров граф на 10 вершин:

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/EulersGraph10.jpg?raw=true)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/res%201.png?raw=true)

Этот граф был задан текстовым файлом.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/10txt.png?raw=true)
   
2) Эйлеров граф на 7 вершин:

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/EulersGraph7.jpg?raw=true)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/res%202.png?raw=true)

Этот граф был задан вводом с клавиатуры.

3)Граф на 9 вершин:

![image](https://graphonline.ru/tmp/saved/qe/qeTjSdFKLQSxWznm.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/9txt.png?raw=true)

4) Ошибка при вводе:

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A0%D0%BE%D0%BC%D0%B0%D0%BD%D1%87%D1%83%D0%BA_%D0%98/%D0%A0%D0%B0%D1%81%D1%87%D0%B5%D1%82%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0/eror.png?raw=true)

Этот граф был задан текстовым файлом.

![image]

## Вывод
 
В результате выполнения расчётной работы приобрёл следующие навыки:
- изучил основы теории графов
- изучил способы представления графов
- изучил базовые алгоритмы для работы с графами
- изучил базовые алгоритмы работы с векторами, очерядими и файлами в C++

## Список литературы
[1] Оре О. Теория графов. – 2-е изд.. – М.: Наука, 1980. – С. 336.

[2] Кормен Т. Х. и др. Часть VI. Алгоритмы для работы с графами // Алгоритмы: построение
и анализ = Introduction to Algorithms. – 2-е изд.. – М.: Вильямс, 2006. – С. 1296.

[3] Харари, Ф. Теория графов / Ф. Харари / Пер. с англ. и предисл. В.П. Козырева. Под ред.
Г.П. Гаврилова. Изд. 2-е. – М.: Едиториал УРСС, 2003. – 269 с.

[4] Нечипуренко, М. И. Алгоритмы и программы решения задач на графах и сетях / М.И.
Нечипуренко, В.К. Попков, С.М. Майнагашев и др. – Новосибирск: Наука. Сиб. отд-ние,
1990. – 515 с.

[5] Емеличев В. А., Мельников О. И., Сарванов В. И., Тышкевич Р. И. Лекции по теории
графов. М.: Наука, 1990. 384с. (Изд.2, испр. М.: УРСС, 2009. 392 с.)

[6] Касьянов, В. Н. Графы в программировании: обработка, визуализация и применение / В.
Н. Касьянов, В. А. Евстигнеева. – СПб. : БХВ-Петербург, 2003.

[7] База знаний по теории графов OSTIS GT [Электронный ресурс] / проект OSTIS, 2012. –
Режим доступа: http://ostisgraphstheo.sourceforge.net. — Дата доступа : 11.09.2012.
