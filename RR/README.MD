# Расчетная работа 

## Введение

### Цель
Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами, 
### Задание
6.1 
### Ключевые понятия
`Граф` - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

`Неориентированным графом`  G называется пара G=(V,E), где V— множество вершин, а E⊂{{v,u}:v,u∈V} — множество рёбер.

`Дерево` — это связный ациклический граф.[1] Связность означает наличие маршрута между любой парой вершин, ацикличность — отсутствие циклов. Отсюда, в частности, следует, что число рёбер в дереве на единицу меньше числа вершин, а между любыми парами вершин имеется один и только один путь.

`Обход в глубину` (поиск в глубину, англ. Depth-First Search, DFS) — один из основных методов обхода графа, часто используемый для проверки связности, поиска цикла и компонент сильной связности и для топологической сортировки.
## Алгоритм решение
Этот код реализует алгоритм для определения минимального количества вершин, которые нужно удалить из графа, чтобы он стал деревом. Для этого он использует несколько шагов:

1. Чтение графа из файла:

Сначала он читает данные о графе из файла. Первая строка файла содержит количество вершин, а вторая строка - количество рёбер. Последующие строки представляют собой пары чисел (u, v), обозначающих рёбра между вершинами u и v.
2. Построение графа:

Создаётся граф, используя информацию из файла, и строятся рёбра между вершинами.
3. Проверка связности графа:

Проверяется, связанный ли граф. Если есть хотя бы одна непосещённая вершина после обхода в ширину (BFS), то граф несвязный.
4. Проверка наличия циклов:

Также проверяется наличие циклов в графе с помощью обхода в глубину (DFS).
5. Определение минимального количества вершин для удаления:

Если граф несвязный или содержит циклы, начинается поиск минимального количества вершин для удаления.
Перебираются все вершины графа. Для каждой вершины удаляются все её рёбра, и затем проверяется связность и отсутствие циклов в графе.
Если граф становится связным и не содержит циклов после удаления рёбер данной вершины, возвращается количество удалённых вершин.
Если ни одна из вершин не может быть удалена, чтобы граф стал деревом, возвращается 0.
Этот алгоритм стремится минимизировать количество удаленных вершин, чтобы превратить граф в дерево (связный ациклический граф).

## Реализация на C++

```c++
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclicUtil(int v, vector<bool>& visited, int parent) {
        visited[v] = true;

        for (int i = 0; i < adj[v].size(); ++i) {
            int u = adj[v][i];

            if (!visited[u]) {
                if (isCyclicUtil(u, visited, v))
                    return true;
            }
            else if (u != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);

        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                if (isCyclicUtil(u, visited, -1))
                    return true;
            }
        }
        return false;
    }

    bool isConnected() {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        for (bool v : visited) {
            if (!v) return false; // Если есть непосещенные вершины, граф несвязный
        }

        return true;
    }

    int countVerticesToRemove() {
        if (!isConnected() || isCyclic()) {
            int removedVertices = 1; // Начинаем с удаления одной вершины

            for (int u = 0; u < V; u++) {
                vector<vector<int>> temp = adj;

                for (int v : adj[u]) {
                    removeEdge(u, v);

                    if (isConnected() && !isCyclic()) {
                        return removedVertices;
                    }
                    else {
                        adj = temp;
                    }
                }
            }
        }

        return 0;
    }

    void removeEdge(int u, int v) {
        adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
    }
    void readGraphFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cout << "Не удалось открыть файл." << endl;
            return;
        }

        inputFile >> V; // Считываем количество вершин из файла
        adj.resize(V);

        int E;
        inputFile >> E; // Считываем количество рёбер из файла
        for (int i = 0; i < E; ++i) {
            int u, v;
            inputFile >> u >> v;
            addEdge(u, v);
        }

        inputFile.close();
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Graph graph(0); // Создаем граф с изначальным количеством вершин 0

    string filePath = "C:\\Users\\bebra\\Desktop\\test1.txt"; // Полный путь к файлу
    graph.readGraphFromFile(filePath);

    int verticesToRemove = graph.countVerticesToRemove();
    cout << "Минимальное количество вершин для удаления: " << verticesToRemove << endl;

    return 0;
}










