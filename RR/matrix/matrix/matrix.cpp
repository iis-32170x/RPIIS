#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Структура для представления ребра
struct Edge {
    int numVertices, numEdges;
};

// Функция для объединения графов
/*vector<vector<int>> unionGraphs(const vector<vector<int>>& graph1, const vector<vector<int>>& graph2) {
    int n1 = graph1.size();
    int n2 = graph2.size(); 
    int n = n1 + n2; 

    // Создаем матрицу инцидентности для объединенного графа
    vector<vector<int>> incidenceMatrix(n, vector<int>(n1 + n2, 0));

    // Заполня0ем матрицу инцидентности для первого графа
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

    return incidenceMatrix;*/
vector<set<int>> uniteGraphs(const vector<set<int>>& graph1, const vector<set<int>>& graph2) {
    int numVertices = max(graph1.size(), graph2.size());
    vector<set<int>> unitedGraph(numVertices);

    for (int i = 0; i < graph1.size(); i++) {
        for (int vertex : graph1[i]) {
            unitedGraph[i].insert(vertex);
        }
    }

    for (int i = 0; i < graph2.size(); i++) {
        for (int vertex : graph2[i]) {
            unitedGraph[i].insert(vertex);
        }
    }

    return unitedGraph;
}

int main() {
    // Примеры графов
    //vector<vector<int>> graph1 = { {1, 2}, {0, 2}, {0, 1} };
   // vector<vector<int>> graph2 = { {1, 2}, {0, 1}, {0, 3}, {3,2} };
    vector<set<int>> graph1 = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1}
    };
    vector<set<int>> graph2 = {
        {1, 0, 1},
        {1, 0, 0},
        {0, 1, 0},
        {0, 1, 1}
    };


    // Объединяем графы
    vector<set<int>> unitedGraph = uniteGraphs(graph1, graph2);
    // Выводим матрицу инцидентности объединенного графа
    for (int i = 0; i < unitedGraph.size(); i++) {
        for (int j = 0; j < unitedGraph.size(); j++) {
            cout << unitedGraph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
