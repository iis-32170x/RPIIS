#include <iostream>
#include <vector>

using namespace std;

// Структура для представления ребра
struct Edge {
    int u, v;
};

// Функция для объединения графов
vector<vector<int>> unionGraphs(const vector<vector<int>>& graph1, const vector<vector<int>>& graph2) {
    int n1 = graph1.size(); // Количество вершин в первом графе
    int n2 = graph2.size(); // Количество вершин во втором графе
    int n = n1 + n2; // Общее количество вершин

    // Создаем матрицу инцидентности для объединенного графа
    vector<vector<int>> incidenceMatrix(n, vector<int>(n1 + n2, 0));

    // Заполняем матрицу инцидентности для первого графа
    for (int i = 0; i < n1; i++) {
        for (int j : graph1[i]) {
            incidenceMatrix[i][i] = 1;
            incidenceMatrix[j][i] = 1;
        }
    }

    // Заполняем матрицу инцидентности для второго графа
    for (int i = 0; i < n2; i++) {
        for (int j : graph2[i]) {
            incidenceMatrix[i + n1][i] = 1;
            incidenceMatrix[j + n1][i] = 1;
        }
    }

    return incidenceMatrix;
}

int main() {
    // Примеры графов 
    vector<vector<int>> graph1 = { {1, 2}, {0, 2}, {0, 1} };
    vector<vector<int>> graph2 = { {1, 2}, {0, 1}, {0, 3}, {3,2} };

    // Объединяем графы
    vector<vector<int>> unionMatrix = unionGraphs(graph1, graph2);
   // Выводим матрицу инцидентности объединенного графа
    for (const auto& row : unionMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

