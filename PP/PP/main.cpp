//
//  main.cpp
//  PP
//
//  Created by Артём Астахов on 2.12.23.
//
#include <iostream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int vertices;
    int edges;
    vector<vector<int>> incidenceMatrix;

public:
    Graph(int v, int e) : vertices(v), edges(e), incidenceMatrix(v, vector<int>(e, 0)) {}

    void addEdge(int edge, int vertex1, int vertex2) {
        incidenceMatrix[vertex1 - 1][edge] = 1;
        incidenceMatrix[vertex2 - 1][edge] = -1;
    }

    int findMaxChainLength() {
        int maxLength = 0;

        for (int startVertex = 0; startVertex < vertices; ++startVertex) {
            vector<int> visited(vertices, false);
            queue<int> q;
            q.push(startVertex);
            visited[startVertex] = true;
            int length = 1;

            while (!q.empty()) {
                int currentVertex = q.front();
                q.pop();

                for (int edge = 0; edge < edges; ++edge) {
                    if (incidenceMatrix[currentVertex][edge] == 1) {
                        for (int neighborVertex = 0; neighborVertex < vertices; ++neighborVertex) {
                            if (incidenceMatrix[neighborVertex][edge] == -1 && !visited[neighborVertex]) {
                                q.push(neighborVertex);
                                visited[neighborVertex] = true;
                                length++;
                            }
                        }
                    }
                }
            }

            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};

int main() {
    int vertices, edges;
    cout << "Введите количество вершин и рёбер графа: ";
    cin >> vertices >> edges;

    Graph graph(vertices, edges);
    if (edges >= 1)
    {
        cout << "Введите ребра графа (по одному ребру в строке):" << endl;
        for (int i = 0; i < edges; ++i) {
            int vertex1, vertex2;
            cout << "Ребро " << (i + 1) << ": ";
            cin >> vertex1 >> vertex2;
            graph.addEdge(i, vertex1, vertex2);
        }
    }

    int maxChainLength = graph.findMaxChainLength();
    if (maxChainLength == 1)
        cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 1 "<< endl;
    else if (maxChainLength == 2)
        cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 2  " << endl;
    else
        cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется от 2 до " << maxChainLength << endl;

    return 0;
}
