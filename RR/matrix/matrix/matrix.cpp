
#include <iostream>
#include <vector>

using namespace std;

// Функция для объединения графов
vector<vector<int>> unionGraphs(vector<vector<int>>& graph1, vector<vector<int>>& graph2) {
    int n1 = graph1.size(); // Количество вершин в первом графе
    int n2 = graph2.size(); // Количество вершин во втором графе
    int m1 = graph1[0].size(); // Количество рёбер в первом графе
    int m2 = graph2[0].size(); // Количество рёбер во втором графе

    // Создаем новую матрицу инцидентности для объединенного графа
    vector<vector<int>> unionGraph(n1 + n2, vector<int>(m1 + m2, 0));

    // Копируем матрицу инцидентности первого графа в объединенный граф
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            unionGraph[i][j] = graph1[i][j];
        }
    }

    // Копируем матрицу инцидентности второго графа в объединенный граф
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            unionGraph[n1 + i][m1 + j] = graph2[i][j];
        }
    }

    return unionGraph;
}

int main() {
    // Примеры матриц инцидентности для двух графов
    vector<vector<int>> graph1 = { {1, 1, 0}, {1, 0, 1}, {0, 1, 1} };
    vector<vector<int>> graph2 = { {1, 0}, {1, 1}, {0, 1} };

    // Объединяем графы и выводим результат
    vector<vector<int>> unionGraph = unionGraphs(graph1, graph2);
    for (int i = 0; i < unionGraph.size(); i++) {
        for (int j = 0; j < unionGraph[0].size(); j++) {
            cout << unionGraph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


