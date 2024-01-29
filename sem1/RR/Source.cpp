#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> incidenceMatrix;
    vector<bool> visited;

public:
    Graph(const vector<vector<int>>& matrix) : incidenceMatrix(matrix) {
        numVertices = matrix.size();
        visited.resize(numVertices, false);
    }

    void DFS(int v) {
        visited[v] = true;

        for (int u = 0; u < numVertices; ++u) {
            if (incidenceMatrix[v][u] == 1 && !visited[u]) {
                DFS(u);
            }
        }
    }

    int countConnectedComponents() {
        int count = 0;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v]) {
                DFS(v);
                count++;
            }
        }

        return count;
    }

    vector<vector<int>> findConnectedComponents() {
        vector<vector<int>> connectedComponents;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v]) {
                vector<int> component;
                DFS(v);
                connectedComponents.push_back(component);
            }
        }

        return connectedComponents;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    vector<vector<int>> incidenceMatrix = {
        {1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0}
    };

    Graph graph(incidenceMatrix);

    
    int numComponents = graph.countConnectedComponents();

    
    cout << "Кол-во компонент связности: " << numComponents << endl;
  

    return 0;
}
