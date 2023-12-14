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

using namespace std;
struct Smezh {
	int v, weight;
	Smezh(int v, int w) : v(v), weight(w) {}
};
struct Edge {
	int u;
	vector<Smezh> smezh;
	Edge(int u, const vector<Smezh>& pairs) : u(u),smezh(pairs){}
};
class Graph {
private:
	int V; // Количество вершин
	vector<Edge> ListSmezh;
public:
	Graph(int vertices) { V = vertices; }
	void addEdge(vector<Edge> Edges) {
		ListSmezh = Edges;
	}
	void UnionVertices(int randomVert, int randomEdge, int randomEdgeIndex, int randomIndex,int Mincut) { 
		setlocale(LC_ALL, "RU");
		ListSmezh[randomIndex].smezh.erase(ListSmezh[randomIndex].smezh.begin() + randomEdgeIndex);
		if (!ListSmezh[randomIndex].smezh.empty()) {
			for (int i = 0; i < ListSmezh[randomIndex].smezh.size(); i++) {
				if (randomEdge == ListSmezh[randomIndex].smezh[i].v) {
					ListSmezh[randomIndex].smezh.erase(ListSmezh[randomIndex].smezh.begin() + i);
				}
			}
		}
		for (int i = 0; i < ListSmezh.size(); i++) {
			for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
				if (randomEdge == ListSmezh[i].smezh[j].v) {
					ListSmezh[i].smezh[j].v = ListSmezh[i].u;
					ListSmezh[randomIndex].smezh.push_back(ListSmezh[i].smezh[j]);
					ListSmezh[i].smezh.erase(ListSmezh[i].smezh.begin() + j);
				}
			}
			if (randomEdge == ListSmezh[i].u) {
				ListSmezh[randomIndex].smezh.insert(ListSmezh[randomIndex].smezh.end(), ListSmezh[i].smezh.begin(), ListSmezh[i].smezh.end());
				ListSmezh.erase(ListSmezh.begin() + i);
			}
		}
		cout << "\nграф после удаления ребра\n";
		for (int i = 0; i < ListSmezh.size(); i++) {
			cout << ListSmezh[i].u;
			for (int j = 0; j < ListSmezh[i].smezh.size(); j++) {
				cout  <<"(" << ListSmezh[i].smezh[j].v<<"," <<ListSmezh[i].smezh[j].weight<<")";
			}
			cout << endl;
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
					}
					cout << "вершину " << randomVert << " и вершину " << randomEdge << endl;
					UnionVertices(randomVert, randomEdge, randomEdgeIndex, randomIndex,Mincut);
				}
			}
			V--;
		}
		return Mincut;
	}
};

int main() {
	srand(time(NULL));
	vector<Edge> ListSmezh;
	ListSmezh.push_back(Edge(0, { Smezh(1, 10), Smezh(2, 20) ,Smezh(3,30)}));
	ListSmezh.push_back(Edge(1, {Smezh(3,40) }));
	ListSmezh.push_back(Edge(2, { Smezh(3,50) }));
	Graph graph(4);
	graph.addEdge(ListSmezh);
	int Mincut=graph.MinCut();
	cout <<"минимальный разрез графа: "<< Mincut;
}
```
# Результат
![image](https://github.com/iis-32170x/RPIIS/assets/148863144/150e757d-1a30-45d1-987e-8598893c4281)

