<h1 align = "center"> <B> Расчетная работа ПиОИвИС </B></h1>
<h2> <B> Введение </B></h2>
<h3> <B> Цель: </B></h3>
Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами.
<h3> <B> Задание: </B></h3>
4.8(ми)
<br> Найти объединение множества неориентированных графов.(Реализовать на C++)
<h3> <B> Основные понятия: </B></h3>
<B><I>Граф</I></B> — математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.
<br>(совокупность точек, соединенных линиями. Точки называются вершинами, или узлами, а линии – ребрами, или дугами.)

<br> <B><I>Неориентированный граф</I></B> — Граф, ни одному ребру которого не присвоено направлениею.

<br><B><I>Матрица инцедентности графа </I></B> — это матрица, количество строк в которой соответствует числу вершин, а количество столбцов – числу рёбер. В ней указываются связи между инцидентными элементами графа (ребро(дуга) и вершина). (В неориентированном графе если вершина инцидентна ребру то соответствующий элемент равен 1, в противном случае элемент равен 0)

<br><B><I> Матрица смежности графа</I></B> — это квадратная матрица, в которой каждый элемент принимает одно из двух значений: 0 или 1.
Число строк матрицы смежности равно числу столбцов и соответствует количеству вершин графа. (1 - есть ребро, 0 - отсутствует ребро)

<br><B> <I> Объединение графов </I> </B> — операция над графами, в результате которой получается граф, множества вершин и рёбер которого являются объединениями множеств вершин и рёбер исходных графов. Иными словами, в результирующий граф входят все рёбра и вершины, которые присутствуют в исходных графах.
<h2><B>Алгоритм решения: </B></h2>
<h3>Примеры объединения: </h3>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/graph1.png?raw=true"> </image>

<B>∪</B>

<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/graph2.png?raw=true"></image>

 <B>=</B>

<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/uniongraph1and2.png?raw=true"></image>
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/graph11.png?raw=true"> </image>

<B>∪</B>

<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/graph22.png?raw=true"></image>

 <B>=</B>

<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/uniongraph11and22.png?raw=true"></image>
<h2><B>Реализация на С++ </B></h2>

```C++
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	int EdgeCount1, VertexCount1, EdgeCount2, VertexCount2;
	cout << "Amount of Graph Vertex 1" << endl;  //4  //5
	cin >> VertexCount1;   
	cout << "Amount of Graph Edges 1" << endl;  //4 //6
	cin >> EdgeCount1;
	cout << "Amount of Graph Vertex 2" << endl; //5 //6
	cin >> VertexCount2;
	cout << "Amount of Graph Edges 2" << endl; //5   //5
	cin >> EdgeCount2;
	string fname, sname;
	cout << "Enter first file name with graph: ";
	cin >> fname;
	cout << "Enter second file name with graph: ";
	cin >> sname;
	ifstream matrix1(fname);
	ifstream matrix2(sname);
	vector < vector <int> > injectivityMatrix1(VertexCount1, vector <int>(EdgeCount1));            //Задаем матрицы инцедентности
	vector < vector <int> > injectivityMatrix2(VertexCount2, vector <int>(EdgeCount2));
	//Заполним матрицы инцедентности из файла
	for (int i = 0; i < VertexCount1; i++)
	{
		for (int j = 0; j < EdgeCount1; j++) {
                      
			matrix1 >> injectivityMatrix1[i][j];
		}

	}
	for (int i = 0; i < VertexCount2; i++)
	{
		for (int j = 0; j < EdgeCount2; j++) {

			matrix2 >> injectivityMatrix2[i][j];
		}

	}
		//Создадим пустые матрицы смежности на основе данных векторов
	vector < vector <int> > adjacencyMatrix1 (VertexCount1, vector <int>(VertexCount1));
	vector < vector <int> > adjacencyMatrix2 (VertexCount2, vector <int>(VertexCount2));
	for (int i = 0; i < VertexCount1; i++)
		for (int j = 0; j < VertexCount1; j++)
		{
			adjacencyMatrix1[i][j] = 0;
		}
	for (int i = 0; i < VertexCount2; i++)
		for (int j = 0; j < VertexCount2; j++)
		{
			adjacencyMatrix2[i][j] = 0;
		}
	int temp;
	
	// Перезаполним первый граф
	for (int i = 0; i < EdgeCount1; i++) {

		for (int j = 0; j < VertexCount1; j++) {
			if (injectivityMatrix1[j][i] == 1) {
				temp = j;      //Ищем первую вершину соединенную ребром
				break;
			}
		}
		for (int k = VertexCount1-1; k >0; k--) {
			if (injectivityMatrix1[k][i] == 1) {             //Ищем вторую и заполняем матрицу смежности
				adjacencyMatrix1[k][temp] = 1;
				adjacencyMatrix1[temp][k] = 1;
				break;
			}
	}

	}
	temp = 0;
	// Перезаполняем второй граф
	for (int i = 0; i < EdgeCount2; i++) {

		for (int j = 0; j < VertexCount2; j++) {
			if (injectivityMatrix2[j][i] == 1) {
				temp = j;                                //Ищем первую вершину соединенную ребром
				break;
			}
		}
		for (int k = VertexCount2-1; k >0; k--) {
			if (injectivityMatrix2[k][i] == 1) {                     //Ищем вторую и заполняем матрицу смежности
				adjacencyMatrix2[k][temp] = 1;
				adjacencyMatrix2[temp][k] = 1;
				break;
			}
	}

	}
	cout << "First adjacency matrix(" << VertexCount1 <<"x" << VertexCount1 << "):" << endl;
	for (int i = 0; i < VertexCount1; i++)
	{
		for (int j = 0; j < VertexCount1; j++) {
			cout << adjacencyMatrix1[i][j] << " "; 
		}
		cout << endl;
	}
	cout << "Second adjacency matrix(" << VertexCount2 << "x" << VertexCount2 << "):" << endl;
	for (int i = 0; i < VertexCount2; i++)
	{
		for (int j = 0; j < VertexCount2; j++) {
			cout << adjacencyMatrix2[i][j] << " ";
		}
		cout << endl;
	}
	int UnionVertex;            
	if (VertexCount1 > VertexCount2) {
		UnionVertex = VertexCount1;
	}
	else { UnionVertex = VertexCount2; }
	vector < vector <int> > UnionGraph(UnionVertex, vector <int>(UnionVertex));
	for (int i = 0; i < UnionVertex; i++) {
		for (int j = 0; j < UnionVertex; j++) {
			UnionGraph[i][j] = 0;
		}

	}
	for (int i = 0; i < VertexCount1; i++) {
		for (int j = 0; j < VertexCount1; j++) {
			UnionGraph[i][j] = adjacencyMatrix1[i][j];
		}
	}
	for (int i = 0; i < VertexCount2; i++) {
		for (int j = 0; j < VertexCount2; j++) {
			if (UnionGraph[i][j] != 1) {
				UnionGraph[i][j] = adjacencyMatrix2[i][j];
			}
		}
	}
	cout << "Adjacency matrix graph union(" << UnionVertex << "x" << UnionVertex <<"):" << endl;
	for (int i = 0; i < UnionVertex; i++)
	{
		for (int j = 0; j < UnionVertex; j++) {
			cout << UnionGraph[i][j] << " ";
		}
		cout << endl;
	}
	int UnionEdge = 0;
	for (int i = 0; i < UnionVertex; i++) {
		for (int j = i + 1; j < UnionVertex; j++) {
			if (UnionGraph[i][j] == 1) {
				UnionEdge++;
			}
		}
	}
	cout << "Injectivity matrix graph union(" << UnionVertex << "x" << UnionEdge << "):" << endl;;
	vector < vector <int> > UnionGraphI(UnionVertex, vector <int>(UnionEdge));
	for (int i = 0; i < UnionVertex; i++) {
		for (int j = 0; j < UnionEdge; j++) {
			UnionGraphI[i][j] = 0;                                  //Создаем пустую матрицу индедентности
		}
	}
	//Перезаписываем матрицу инцедентности
	int count = 0;
	for (int i = 0; i < UnionVertex; i++) {
		for (int j = i + 1; j < UnionVertex; j++) {
			if (UnionGraph[i][j]==1) {
				UnionGraphI[i][count] = 1;
				UnionGraphI[j][count] = 1;
				count++;
			}
		}
	}
	for (int i = 0; i < UnionVertex; i++) {
		for (int j = 0; j < UnionEdge; j++) {      // Вывод объединенной матрицы инцедентнсти
			cout << UnionGraphI[i][j] << " ";
		}
		cout << endl;
	}

}
```
<h2><B>Разбор кода: </B></h2> 

```C++ 
   #include <iostream>
    #include <vector> 
    #include <fstream> 
    #include <string> 
    using namespace std;
```
             1)Подключаем библиотеки для работу с веторами, строками и файлами, а также пространство имен std.
    
```C++
    int EdgeCount1, VertexCount1, EdgeCount2, VertexCount2;
cout << "Amount of Graph Vertex 1" << endl;  //4  //5
cin >> VertexCount1;   
cout << "Amount of Graph Edges 1" << endl;  //4 //6
cin >> EdgeCount1;
cout << "Amount of Graph Vertex 2" << endl; //5 //6
cin >> VertexCount2;
cout << "Amount of Graph Edges 2" << endl; //5   //5
cin >> EdgeCount2;
string fname, sname;
cout << "Enter first file name with graph: ";
cin >> fname;
cout << "Enter second file name with graph: ";
cin >> sname;
ifstream matrix1(fname);
ifstream matrix2(sname);
```
    2)Создаем переменный и просим пользователя задать количество вершин и ребер двух графов. Также создаем 2 строки в котрые запоминаем название файлов и берем данные из этих файлов.

  ```C++
    vector < vector <int> > injectivityMatrix1(VertexCount1, vector <int>(EdgeCount1));            \
vector < vector <int> > injectivityMatrix2(VertexCount2, vector <int>(EdgeCount2));
for (int i = 0; i < VertexCount1; i++)
{
	for (int j = 0; j < EdgeCount1; j++) {

		matrix1 >> injectivityMatrix1[i][j];
	}

}
for (int i = 0; i < VertexCount2; i++)
{
	for (int j = 0; j < EdgeCount2; j++) {

		matrix2 >> injectivityMatrix2[i][j];
	}

}
```
      3)Создаем матрицы инцедентности нужного размера и заполняем их из файла ранне введенного пользователем.

```C++  
	vector < vector <int> > adjacencyMatrix1 (VertexCount1, vector <int>(VertexCount1));
	vector < vector <int> > adjacencyMatrix2 (VertexCount2, vector <int>(VertexCount2));
	for (int i = 0; i < VertexCount1; i++)
		for (int j = 0; j < VertexCount1; j++)
		{
			adjacencyMatrix1[i][j] = 0;
		}
	for (int i = 0; i < VertexCount2; i++)
		for (int j = 0; j < VertexCount2; j++)
		{
			adjacencyMatrix2[i][j] = 0;
		}
```
     4)Создаем пустые матрицы смежности на основе количества вершин матриц инцедентности
```C++
	int temp;
	
	// Перезаполним первый граф
	for (int i = 0; i < EdgeCount1; i++) {

		for (int j = 0; j < VertexCount1; j++) {
			if (injectivityMatrix1[j][i] == 1) {
				temp = j;      //Ищем первую вершину соединенную ребром
				break;
			}
		}
		for (int k = VertexCount1-1; k >0; k--) {
			if (injectivityMatrix1[k][i] == 1) {             //Ищем вторую и заполняем матрицу смежности
				adjacencyMatrix1[k][temp] = 1;
				adjacencyMatrix1[temp][k] = 1;
				break;
			}
	}

	}
	temp = 0;
	// Перезаполняем второй граф
	for (int i = 0; i < EdgeCount2; i++) {

		for (int j = 0; j < VertexCount2; j++) {
			if (injectivityMatrix2[j][i] == 1) {
				temp = j;                                //Ищем первую вершину соединенную ребром
				break;
			}
		}
		for (int k = VertexCount2-1; k >0; k--) {
			if (injectivityMatrix2[k][i] == 1) {                     //Ищем вторую и заполняем матрицу смежности
				adjacencyMatrix2[k][temp] = 1;
				adjacencyMatrix2[temp][k] = 1;
				break;
			}
	}

	}
```
    5)Перезаписываем матрицы инцедентности в матрицы смежности ища две вершины соедененных одним ребром и так как граф неориентированный записываем 1 семетрично относительно главной диогонали на против этих вершин
```C++
	int UnionVertex;            
	if (VertexCount1 > VertexCount2) {
		UnionVertex = VertexCount1;
	}
	else { UnionVertex = VertexCount2; }
	vector < vector <int> > UnionGraph(UnionVertex, vector <int>(UnionVertex));
	for (int i = 0; i < UnionVertex; i++) {
		for (int j = 0; j < UnionVertex; j++) {
			UnionGraph[i][j] = 0;
		}

	}
	for (int i = 0; i < VertexCount1; i++) {
		for (int j = 0; j < VertexCount1; j++) {
			UnionGraph[i][j] = adjacencyMatrix1[i][j];
		}
	}
	for (int i = 0; i < VertexCount2; i++) {
		for (int j = 0; j < VertexCount2; j++) {
			if (UnionGraph[i][j] != 1) {
				UnionGraph[i][j] = adjacencyMatrix2[i][j];
			}
		}
	}
```
    6)Находим количество вершин объединенного графа равное максимальному числу вершин одного из двух графов.
    На основе этого создаем пустую матрицу смежности.
    После чего записываем в эту матрицу смежности объединения матрицу смежности 1 и если на пересечение не 1 записываем числа из матрицы смежности 2.
```C++
	int UnionEdge = 0;
	for (int i = 0; i < UnionVertex; i++) {
		for (int j = i + 1; j < UnionVertex; j++) {
			if (UnionGraph[i][j] == 1) {
				UnionEdge++;
			}
		}
	}
```
    7)Ищем количество ребер объедененной матрицы инцедентности равное количеству 1 выше главной диагонали(так как у нас граф без петель и без кратных ребер)
```C++
vector < vector <int> > UnionGraphI(UnionVertex, vector <int>(UnionEdge));
for (int i = 0; i < UnionVertex; i++) {
	for (int j = 0; j < UnionEdge; j++) {
		UnionGraphI[i][j] = 0;                                  //Создаем пустую матрицу индедентности
	}
}
//Перезаписываем матрицу инцедентности
int count = 0;
for (int i = 0; i < UnionVertex; i++) {
	for (int j = i + 1; j < UnionVertex; j++) {
		if (UnionGraph[i][j]==1) {
			UnionGraphI[i][count] = 1;
			UnionGraphI[j][count] = 1;
			count++;
		}
	}
}
```
      8)Создаем пустую матрицу инцедентности на основе количество вершин объедененной матрицы и кол ребер объедененной матрицы которое мы ранее нашли.
      После же перезаписываем матрицу смежности в матрицу инцедентности исчесляя ребра начиная от вершины 1 с поступательными движениями

<h2><B>Тесты: </B></h2>
<h3>Тест 1:</h3>
Входные данные(Кол вершин и ребер, и имя файлов с МИ)
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/enter1.png?raw=true"> </image>
Матрица 1:

```
1 0 0 1
1 1 0 0
0 1 1 0
0 0 1 1
```
Матрица 2:

```
1 0 0 0 1
1 0 1 0 0
0 1 0 1 0
0 1 0 0 0
0 0 1 1 1
```
<br>Объединенная матрица инцедентности:
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/output1.png?raw=true"></image>
<h3>Тест 2:</h3>
Входные данные(Кол вершин и ребер, и имя файлов с МИ)
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/enter2.png?raw=true"> </image>
Матрица 11:

```
1 0 0 0 0 1
1 0 0 0 0 
0 1 1 0 1 0
0 0 1 1 0 0
0 0 0 1 1 1 
```
Матрица 22:
```
1 0 0 0 0
0 1 0 0 0
1 1 1 0 0
0 0 1 1 0
0 0 0 1 1
0 0 0 0 1
```
<br>Объединенная матрица инцедентности:
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/PP/Tests/output2.png?raw=true"></image>
<h2><B>Вывод:</B></h2>
В результате выполнения расчётной работы приобрёл следующие навыки:
<ul>
 <li>Изучил основы теории графов</li>
 <li>Изучил способы представления графов</li>
 <li>Изучил базовые алгоритмы для работы с графами</li>
 <li>Изучил базовые алгоритмы работы с векторами, файлами в C++</li>
</ul>
