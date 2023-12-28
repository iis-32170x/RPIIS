#include <iostream>
#include <vector>

using namespace std;

// Функция для создания матрицы инцидентности из списка ребер
vector<vector<int>> createIncidenceMatrix(const vector<vector<int>>& edges, int numVertices) {
    vector<vector<int>> incidenceMatrix(numVertices, vector<int>(edges.size(), 0));
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        incidenceMatrix[u][i] = 1;
        incidenceMatrix[v][i] = 1;
    }
    return incidenceMatrix;
}

int main() {
    vector<vector<int>> graph1 = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1}
    };
    vector<vector<int>> graph2 = {
           {1, 0, 1},
           {1, 0, 0},
           {0, 1, 0},
           {0, 1, 1}
    };

    int numVertices = 4; // Общее количество вершин в объединенном графе
    vector<vector<int>> combinedEdges = graph1; // Добавляем ребра из первого графа
    combinedEdges.insert(combinedEdges.end(), graph2.begin(), graph2.end()); // Добавляем ребра из второго графа

    vector<vector<int>> combinedIncidenceMatrix = createIncidenceMatrix(combinedEdges, numVertices);

    // Вывод матрицы инцидентности
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < combinedEdges.size(); j++) {
            cout << combinedIncidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}