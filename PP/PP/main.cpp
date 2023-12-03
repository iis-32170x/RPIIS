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
                vector<int> usedEdges(edges, 0);
                dfs(startVertex, visited, usedEdges, 1, maxLength);
            }

            return maxLength;
        }

    private:
        void dfs(int currentVertex, vector<int>& visited, vector<int>& usedEdges, int length, int& maxLength) {
            visited[currentVertex] = true;

            for (int edge = 0; edge < edges; ++edge) {
                if (incidenceMatrix[currentVertex][edge] == 1 && !usedEdges[edge]) {
                    for (int neighborVertex = 0; neighborVertex < vertices; ++neighborVertex) {
                        if (incidenceMatrix[neighborVertex][edge] == -1 && !visited[neighborVertex]) {
                            usedEdges[edge] = 1;
                            dfs(neighborVertex, visited, usedEdges, length + 1, maxLength);
                            usedEdges[edge] = 0;  // Backtrack: mark the edge as not used
                        }
                    }
                }
            }

            visited[currentVertex] = false;
            maxLength = max(maxLength, length);
        }


};

void tests()
{
    cout << "Граф А" << endl;
    int vertices, edges;
    vertices = 1;
    edges = 0;
    
    Graph graph(vertices, edges);
    if (vertices == 0)
        cout << "этого графа не существует, соответсвенно и индекс компонент равен 0";
    else
    {
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
    }
    int maxChainLength = graph.findMaxChainLength();
    if (maxChainLength == 1)
        cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 1 "<< endl;
    else if (maxChainLength == 2)
        cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 2  " << endl;
    else
        cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется от 2 до " << maxChainLength << endl;
    
    cout << "\n Граф A - B" << endl;
    vertices = 2;
    edges = 1;
    Graph graph1(vertices, edges);
    if (vertices == 0)
        cout << "этого графа не существует, соответсвенно и индекс компонент равен 0";
    else
    {
        if (edges >= 1)
        {
            graph1.addEdge(0, 1, 2);
        }
        
        maxChainLength = graph1.findMaxChainLength();
        if (maxChainLength == 1)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 1 "<< endl;
        else if (maxChainLength == 2)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 2  " << endl;
        else
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется от 2 до " << maxChainLength << endl;
    }
    cout << "\n Граф A - B - C - D - E" << endl;
    vertices = 5;
    edges = 4;
    Graph graph2(vertices, edges);
    if (vertices == 0)
        cout << "этого графа не существует, соответсвенно и индекс компонент равен 0";
    else
    {
        if (edges >= 1)
        {
            graph2.addEdge(0, 1, 2);
            graph2.addEdge(1, 2, 3);
            graph2.addEdge(2, 3, 4);
            graph2.addEdge(3, 4, 5);
        }
        
        maxChainLength = graph2.findMaxChainLength();
        if (maxChainLength == 1)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 1 "<< endl;
        else if (maxChainLength == 2)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 2  " << endl;
        else
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется от 2 до " << maxChainLength << endl;
    }
    cout << "\n Граф A - B - C - D" << endl;
    cout << "               \\  /" << endl;
    cout << "                E" << endl;
    vertices = 5;
    edges = 4;
    Graph graph3(vertices, edges);
    
    if (vertices == 0)
        cout << "этого графа не существует, соответсвенно и индекс компонент равен 0";
    else
    {
        if (edges >= 1)
        {
            graph3.addEdge(0, 1, 2);
            graph3.addEdge(1, 2, 3);
            graph3.addEdge(2, 3, 4);
            graph3.addEdge(3, 3, 5);
            graph3.addEdge(4, 4, 5);
        }
        
        maxChainLength = graph3.findMaxChainLength();
        if (maxChainLength == 1)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 1 "<< endl;
        else if (maxChainLength == 2)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 2  " << endl;
        else
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется от 2 до " << maxChainLength << endl;
    }
    cout << "\n В случае если графа нет (не имеет вершин)" << endl;
    vertices = 0;
    edges = 0;
    Graph graph4(vertices, edges);
    
    if (vertices == 0)
        cout << "этого графа не существует, соответсвенно и индекс компонент равен 0" << endl;
    else
    {
        if (edges >= 1)
        {
            graph4.addEdge(0, 1, 2);
            graph4.addEdge(1, 2, 3);
            graph4.addEdge(2, 3, 4);
            graph4.addEdge(3, 4, 1);
            
        }
        
        maxChainLength = graph4.findMaxChainLength();
        if (maxChainLength == 1)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 1 "<< endl;
        else if (maxChainLength == 2)
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется 2  " << endl;
        else
            cout << "Индекс компонент относительно простой цепи в неориентированном графе равняется от 2 до " << maxChainLength << endl;
    }
}

int main() {
    tests();
    return 0;
}
