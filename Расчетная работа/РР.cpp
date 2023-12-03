#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;
//функция поиска в глубину для ориентированного графа
void DFS(const vector<vector<int>>& matrix, int vertex, vector<bool>& visited) {
	visited[vertex] = true;
	//цикл поиска ребра выходящего из выбранной вершины(vertex)
	for (int edge = 0; edge < matrix[0].size(); edge++) {
		if (matrix[vertex][edge]== 1) {
			//цикл поиска вершины, которая не была посещена и в которую входит ребро из выбранной вершины(vertex)
			for(int i=0;i<matrix.size();i++)
				if (matrix[i][edge] == -1 && !visited[i]) {
					DFS(matrix, i, visited);
				}

		}
	}
}
//функция проверки на сильно связный граф 
bool isstronglyconnected(const vector<vector<int>>& matrix) {
	//получение количества вершин графа 
	int vertices = matrix.size();
	//цикл прохода по всем вершинам графа 
	for (int vertex = 0; vertex < vertices; vertex++) {
	//задание вектора в который записывается посещены ли вершины или нет
		vector<bool>visited(vertices, false);
	//поиск вглубину из текущей вершины
		DFS(matrix, vertex, visited);
	//цикл, определяющий все ли вершины были посещены  
		int i = 0;
		while (i < vertices && visited[i]) {
			i++;
		}
		if (i < vertices) {
			return false;
		}
	}

		return true;
	

}

int main() {
	setlocale(0, " ");
	cout << "Введите количество вершин графа:" << endl;
	int vertices; cin >> vertices;
	cout << "Введите количество ребер графа:" << endl;
	int edges; cin >> edges;
	//задание матрицы инцидентности 
	vector<vector<int>>matrix(vertices,vector<int>(edges,0));
    cout<<"Введите матрицу инцидентности(строки-вершины,столбцы-ребра)"<<endl;
	for (int i = 0; i < vertices; i++) 
		for (int j = 0; j < edges; j++) {
			cin >> matrix[i][j];
		}
	if (isstronglyconnected(matrix)) {
		cout << "Граф является сильно связным" << endl;
	}
	else {
		cout << "Граф не является сильно связным" << endl;
	}



	
}