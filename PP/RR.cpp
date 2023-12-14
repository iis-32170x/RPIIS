
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
