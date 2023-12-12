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

# Алгоритм

### Структура данных для ребер:

Определена структура `Edge`, представляющая ребро графа с полями `u`, `v` (вершины) и `weight` (вес).

### Чтение данных из файла:

Реализована функция `ReadFile`, которая считывает ребра из файла в вектор `Edges`.

### Определение числа вершин:

Реализована функция `NumVertices`, которая по вектору ребер определяет количество вершин в графе.

### Класс `Graph`:

Класс `Graph` содержит приватные члены `V` (количество вершин) и `edges` (список ребер).
- Конструктор класса инициализирует количество вершин.
- Метод `addEdge` добавляет ребра в граф.
- Метод `collect` используется для объединения вершин при нахождении минимального разреза.
- Метод `MinCutAlgorithm` содержит алгоритм поиска минимального разреза.

### Главная функция:

В главной функции создается объект класса `Graph`.
1. Вызывается функция чтения файла и создания графа.
2. Запускается алгоритм поиска минимального разреза.
3. Выводится результат.

### Алгоритм поиска минимального разреза:

Основан на методе "Стохастического минимального разреза" (Stoer-Wagner algorithm), который использует случайные выборки для поиска приближенного минимального разреза во взвешенном графе.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include<numeric>
#include <fstream>
#include <set>
using namespace std;
struct Edge {
    int u, v, weight;
};
vector<Edge> ReadFile(string& filename) {
    vector<Edge> edge;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        Edge edges;
        while (inputFile >> edges.u >>edges.v>> edges.weight) {
            edge.push_back(edges);
        }
        inputFile.close();
    }
    else {
        cerr << "Unable to open the file." << endl;
    }

    return edge;
}
// функция для нахождения количесива вершин
int NumVertices(vector<Edge> Edges) {
    vector<char> vertices;
    for (int i = 0; i < Edges.size(); i++) {
        vertices.push_back(Edges[i].u);
        vertices.push_back(Edges[i].v);
    }
    set<char> NumVertices(vertices.begin(), vertices.end());
    int V = NumVertices.size();
    return V;
}
class Graph {
private:
    int V; // Количество вершин
    vector<Edge> edges; // Список рёбер

public:
    Graph(int vertices) { V = vertices; }

    // создание графа
    void addEdge(vector<Edge> Edges) {
        edges = Edges;
   }
    //функция для обьединение=я вершин
    void  collect(int subset1, int subset2, int weight, vector<int>& MinCut) {
        MinCut.push_back(weight);
        setlocale(LC_ALL, "RU");
        cout << "Образовалось \n";
        for (int i = 0; i < edges.size(); i++)
        {
            if (subset2 == edges[i].u && subset1 != edges[i].v) {
                edges[i].u = subset1;
                cout << "ребро " << edges[i].u << "-" << edges[i].v << "\n";
            }
            else
                if (subset2 == edges[i].v && subset1 != edges[i].u) {
                    edges[i].v = edges[i].u;
                    edges[i].u = subset1;
                    cout << "ребро " << edges[i].u << "-" << edges[i].v << "\n";
                }
                else
                    if (subset1 == edges[i].v && subset2 == edges[i].u) {
                        MinCut.push_back(edges[i].weight);
                        cout << "ребро " << edges[i].u << "-" << edges[i].v << "\n";
                        edges.erase(edges.begin() + i);
                    }
                    else
                        if (subset1 == edges[i].u && subset2 == edges[i].v) {
                            MinCut.push_back(edges[i].weight);
                            cout << "ребро " << edges[i].u << "-" << edges[i].v << "\n";
                            edges.erase(edges.begin() + i);
                        }
        }

    }
    //функция для нахождения минимального разреза
    int MinCutAlgorithm() {
        vector<int> Cut;
        int MinCut = 0;
        setlocale(LC_ALL, "RU");
        while (V > 2) {
            cout << "выбираем случайные вершины\n";
            int randomEdge = rand() % edges.size();
            int subset1 = edges[randomEdge].u;
            int subset2 = edges[randomEdge].v;
            int weight = edges[randomEdge].weight;
            cout << "случайным образом выбрались вершины " << subset1 << " и " << subset2 << "\n";
            cout << "объединяем вершину " << subset1 << " с вершиной " << subset2 << "\n";
            edges.erase(edges.begin() + randomEdge);
            collect(subset1, subset2, weight, Cut);
            if (V > 3) {
                cout << "продолжаем пока не останется две вершины \n";
            }
            else {
                cout << "так как осталось два ребра можем считать минимальный разрез \n";
            }
            V--;

        }
        MinCut = accumulate(Cut.begin(), Cut.end(), 0);

        return MinCut;
    }
};

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");
    string filename = "RR.txt";
    vector<Edge> Edges = ReadFile(filename);
    int vertices = NumVertices(Edges);
    Graph graph(vertices);
    graph.addEdge(Edges);
    int MinCut = graph.MinCutAlgorithm();
    cout << "минимальный разрез графа равен " << MinCut;
}
```
# Результат
![image](https://github.com/iis-32170x/RPIIS/assets/148863144/5964dead-3100-4723-8ddd-bb11c0840bf4)
