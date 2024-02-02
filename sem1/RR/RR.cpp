#include <iostream>
#include <vector>

using namespace std;

bool isTreeGraph(vector<vector<int>>& adjacency, int node, vector<bool>& visited, int parent) {
    visited[node] = true;

    for (int j = 0; j < adjacency[node].size(); j++) {
        int neighbor = adjacency[node][j];

        if (visited[neighbor] && neighbor != parent) {
            return false;
        }

        if (!visited[neighbor] && !isTreeGraph(adjacency, neighbor, visited, node)) {
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "RUS");
    vector<vector<int>> adjacency{
        {1, 2},  // Вершина 0 связана с вершинами 1 и 2
        {0, 3},  // Вершина 1 связана с вершинами 0 и 3
        {0, 4},  // Вершина 2 связана с вершинами 0 и 4
        {1, 4},   // Вершина 3 связана только с вершиной 1
        {2, 3}    // Вершина 4 связана только с вершиной 2
    };

    int n = adjacency.size();  //  вершины
    int m = 0;  //  ребера

    for (const auto& edges : adjacency) {
        m += edges.size();
    }

    m /= 2;  // Поскольку каждое ребро учтено дважды

    vector<bool> visited(n);
    bool isTree = isTreeGraph(adjacency, 0, visited, -1);

    if (isTree) {
        cout << "Граф является деревом." << endl;
        cout << "Хорды отсутсвуют. " << endl;
    }
    else {
        cout << "Граф не является деревом." << endl;
        int numChords = m - n + 1;
        cout << "Число хорд в графе: " <<numChords <<  endl;
    }

   
}
