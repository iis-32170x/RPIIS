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
