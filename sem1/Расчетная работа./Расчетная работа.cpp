#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки, можно ли добавить вершину n в текущий путь
bool isSafe(int n, const vector<vector<int>>& graph, vector<int>& path, int p) {

    if (graph[path[p - 1]][n] == 0)
        return false;
    //Если не смежна, нельзя соединять
    for (int i = 0; i < p; i++) {
        if (path[i] == n)
            return false;
    }
    //Если посещалась, нельзя соединять

    return true;
}

// Рекурсивная функция для нахождения гамильтонова пути в графе
bool hamiltonianPathUtil(const vector<vector<int>>& graph, vector<int>& path, int p) {
    // Базовый случай: если все вершины добавлены в путь
    if (p == graph.size()) {
        // Проверяем, существует ли ребро между последней и первой вершиной в пути
        if (graph[path[p - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Пытаемся добавить каждую вершину в путь
    for (int n = 1; n < graph.size(); n++) {
        if (isSafe(n, graph, path, p)) {
            path[p] = n;

            // Рекурсивно проверяем, существует ли гамильтонов путь, начинающийся с вершины n
            if (hamiltonianPathUtil(graph, path, p + 1))
                return true;

            // Если добавление вершины n не приводит к решению, удаляем ее из пути
            path[p] = -1;
        }
    }

    return false;
}

// Функция для проверки наличия гамильтонова пути в графе
bool hasHamiltonianPath(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<int> path(numVertices, -1); // Инициализируем путь

    // Вершина 0 всегда является начальной вершиной в гамильтоновом пути
    path[0] = 0;

    // Проверяем, существует ли гамильтонов путь, начинающийся с вершины 0
    if (hamiltonianPathUtil(graph, path, 1))
        return true;

    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numVertices;
    cout << "Введите количество вершин графа: ";
    cin >> numVertices;

    cout << "Введите матрицу смежности графа:\n";
    vector<vector<int>> graph(numVertices, vector<int>(numVertices));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
        cout << endl;
    }

    if (hasHamiltonianPath(graph))
        cout << "Граф имеет гамильтонов путь.\n";
    else
        cout << "Граф не имеет гамильтонова пути.\n";

    return 0;
}