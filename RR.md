# Расчетная работа вариант 5.11
условие : найти минимальный простой разрез графа (вог , сс)
# определения
**Термин "граф" в различных контекстах**

**Математика**

**Граф (теория графов):** В математике теория графов изучает отношения между объектами с использованием схемы, называемой графом. Граф состоит из вершин (узлов) и рёбер (связей между узлами).

**Информатика**

**Граф (структура данных):** В компьютерной науке граф может использоваться как структура данных для представления связей между различными элементами.

**Минимальный простой разрез (минимальный разрез) графа:** Это множество рёбер, удаление которых из графа разбивает его на две непересекающиеся компоненты.

**Взвешенный ориентированный граф:** Граф, у которого каждому ребру присвоено числовое значение, называемое весом или стоимостью. Вес ребра может представлять различные характеристики, такие как расстояние, затраты, время и т.д., в зависимости от конкретной задачи.

**Ориентированный граф:** Состоит из вершин и направленных рёбер, где каждое ребро имеет начальную и конечную вершину.

**Список смежности:** Способ представления графа в виде структуры данных. Каждая вершина графа связана с другими вершинами, с которыми она имеет рёбра. Для каждой вершины создается список смежности, содержащий вершины, с которыми она соединена.

# Алгоритм Каргера для нахождения минимального разреза в графе

Данный код реализует алгоритм Каргера для нахождения минимального разреза в графе. Минимальный разрез представляет собой множество рёбер, разделяющих граф на две непересекающиеся компоненты связности, с минимальной суммой весов рёбер.

## Основные шаги алгоритма:

1. Создание графа с использованием структур `Smezh` (ребро) и `Edge` (вершина и связанные с ней рёбра).

2. В методе `MinCut` происходит итеративное слияние вершин до тех пор, пока в графе не останется 2 вершины. На каждой итерации случайным образом выбираются две вершины, и все исходящие из них рёбра объединяются. Веса рёбер суммируются для определения текущей величины минимального разреза.

3. В конце работы алгоритма выводится минимальный разрез.
  
### Алгоритм поиска минимального разреза:

Основан на методе "Стохастического минимального разреза" (Stoer-Wagner algorithm), который использует случайные выборки для поиска приближенного минимального разреза во взвешенном графе.
## КОД

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include<numeric>
#include <fstream>


using namespace std;
struct Edge {
	int u;
	int v;
	int weight;
};
struct Smezh {
	int v, weight;
};
struct Vertex {
	int u;
	vector<Smezh> smezh;
};
void FileRead(vector<Edge>& Edges, string FileName) {
	ifstream inputFile(FileName);

	// Проверка, удалось ли открыть файл
	if (!inputFile.is_open()) {
		cout << "Unable to open the file.\n";
	}
	// Считывание данных из файла и запись в вектор
	Edge edge;
	while (inputFile >> edge.u >> edge.v >> edge.weight) {
		Edges.push_back(edge);
	}

	// Закрытие файла
	inputFile.close();
}
void Adding(vector<Vertex>& ListSmezh,int vertex, int smezhn,int weight) {
	bool Find = false;
	for (int i = 0; i < ListSmezh.size(); i++) {
		if (smezhn == ListSmezh[i].u) {
			bool find = false;
			for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
				if (vertex == ListSmezh[i].smezh[j].v && weight == ListSmezh[i].smezh[j].weight) {
					find = true;
				}
			}
			if (!find) {
				ListSmezh[i].smezh.push_back({ vertex,weight });
			}
			Find = true;
        }
	}	 	
	if (!Find) {
			Vertex vert;
			Smezh sm;
			sm.v = vertex;
			sm.weight = weight;
			vert.u = smezhn;
			vert.smezh.push_back(sm);
			ListSmezh.push_back(vert);
			vert.smezh.clear();
		
	}
}
void AddSmezh(vector<Vertex>& ListSmezh, vector<Edge>& Edges) {
	setlocale(LC_ALL, "RU");
	Edge sort;
	for (int i = 0; i < Edges.size() - 1; i++) {
		for (int j = i + 1; j < Edges.size(); j++) {
			if (Edges[i].u > Edges[i + 1].u) {
				sort = Edges[i];
				Edges[i] = Edges[j];
				Edges[j] = sort;
			}
		}
	}
	int counting = 0;
	Vertex vertex; // Предполагается, что у вас есть структура Vertex
	Smezh smezhn ;  // Предполагается, что у вас есть структура Smezh
	for (int i = 0; i < Edges.size(); i += counting) {
		counting = 0;
		vertex.u = Edges[i].u;
		for (int j = i; j < Edges.size(); j++) {
			if (Edges[i].u == Edges[j].u) {
				smezhn.v = Edges[j].v;
				smezhn.weight = Edges[j].weight;
				vertex.smezh.push_back(smezhn);
				counting++;
			}
		}
		ListSmezh.push_back(vertex); 
		vertex.smezh.clear();
	}
	for (int i = 0; i < ListSmezh.size(); i++) {
		for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
			Adding(ListSmezh, ListSmezh[i].u, ListSmezh[i].smezh[j].v, ListSmezh[i].smezh[j].weight);
		}
	}
}
class Graph {
private:
	int V; // Количество вершин
	vector<Vertex> ListSmezh;
public:
	Graph(int vertices) { V = vertices; }
	void addEdge(vector<Vertex> Edges) {
		ListSmezh = Edges;
	}
	void UnionVertices(int randomVert, int randomEdge, int randomEdgeIndex, int randomIndex, int Mincut) {
		ListSmezh[randomIndex].smezh.erase(ListSmezh[randomIndex].smezh.begin() + randomEdgeIndex);//удаление ребера
		if (!ListSmezh[randomIndex].smezh.empty()) {
			for (int i = 0; i < ListSmezh[randomIndex].smezh.size(); i++) {
				if (randomEdge == ListSmezh[randomIndex].smezh[i].v) {
					ListSmezh[randomIndex].smezh.erase(ListSmezh[randomIndex].smezh.begin() + i);
				}
			}
		}//удаление ребер
		for (int i = 0; i < ListSmezh.size(); i++) {
			if (randomEdge == ListSmezh[i].u) {
				for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
					if (randomVert == ListSmezh[i].smezh[j].v) {
						ListSmezh[i].smezh.erase(ListSmezh[i].smezh.begin() + j);
					}
				}
			}
		}//удаление ребра
		for (int i = 0; i < ListSmezh.size(); i++) {
			if (randomEdge == ListSmezh[i].u) {
				ListSmezh[randomIndex].smezh.insert(ListSmezh[randomIndex].smezh.end(), ListSmezh[i].smezh.begin(), ListSmezh[i].smezh.end());
				ListSmezh.erase(ListSmezh.begin() + i);
			}
		}
		for (int i = 0; i < ListSmezh.size(); i++) {
			for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
				if (randomEdge == ListSmezh[i].smezh[j].v) {
					ListSmezh[i].smezh[j].v = randomVert;
				}
			}
		}
	}


	int MinCut() {
		setlocale(LC_ALL, "RU");
		int Mincut = 0;
		cout << "начальный граф\n";
		for (int i = 0; i < ListSmezh.size(); i++) {
			cout << ListSmezh[i].u;
			for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
				cout << "(" << ListSmezh[i].smezh[j].v << "," << ListSmezh[i].smezh[j].weight << ")";
			}
			cout << endl;
		}
		while (V > 2) {
			int randomIndex = 0;
			int randomVert = 0;
			cout << "выбираем случайным образом две вершины например: ";
			do {
				randomIndex = rand() % ListSmezh.size();
				randomVert = ListSmezh[randomIndex].u;
			} while (ListSmezh[randomIndex].smezh.empty());
			for (int i = 0; i < ListSmezh.size(); i++) {
				if (randomVert == ListSmezh[i].u) {
					int randomEdgeIndex = rand() % ListSmezh[randomIndex].smezh.size();
					int randomEdge = ListSmezh[randomIndex].smezh[randomEdgeIndex].v;
					int randomWeight = ListSmezh[randomIndex].smezh[randomEdgeIndex].weight;
					for (int i = 0; i < ListSmezh[randomIndex].smezh.size(); i++) {
						if (randomEdge == ListSmezh[randomIndex].smezh[i].v) {
							Mincut += ListSmezh[randomIndex].smezh[i].weight;
						}
					}//подсчет разреза

					cout << "вершину " << randomVert << " и вершину " << randomEdge << endl;
					UnionVertices(randomVert, randomEdge, randomEdgeIndex, randomIndex, Mincut);
					for (int i = 0; i < ListSmezh.size(); i++) {
						if (ListSmezh[i].smezh.empty()) {
							ListSmezh.erase(ListSmezh.begin() + i);
						}
					}
					cout << "\nграф после удаления ребра\n";
					for (int i = 0; i < ListSmezh.size(); i++) {
						cout << ListSmezh[i].u;
						for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
							cout << "(" << ListSmezh[i].smezh[j].v << "," << ListSmezh[i].smezh[j].weight << ")";
						}
						cout << endl;
					}
				}
			}
			V--;
		}
		return Mincut;
	}
};

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	string FileName;
	cout << "введите имя файла из которого требуется считать данные: ";
	cin >> FileName;
	vector<Edge> Edges;
	FileRead(Edges, FileName);
	vector<Vertex> ListSmezh;
	AddSmezh(ListSmezh, Edges);
	Graph graph(ListSmezh.size());
	graph.addEdge(ListSmezh);
	int Mincut = graph.MinCut();
	cout << "минимальный разрез графа: " << Mincut;
}
```
# Результат
![image](https://github.com/iis-32170x/RPIIS/assets/148863144/8f46ad23-8818-4a5a-bb17-f07913e4ef3a)



