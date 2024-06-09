#pragma once
#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Graph {
    int V;
    list<int>* adj;
};

Graph* createGraph(int V) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->adj = new list<int>[V];
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src].push_back(dest);
}

void removeEdge(Graph* graph, int src, int dest) {
    graph->adj[src].remove(dest);
}

void BFS(Graph* graph, int start) {
    bool* visited = new bool[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    list<int> queue;
    visited[start] = true;
    queue.push_back(start);

    while (!queue.empty()) {
        start = queue.front();
        cout << start << " ";
        queue.pop_front();

        for (auto i = graph->adj[start].begin(); i != graph->adj[start].end(); ++i) {
            if (!visited[*i]) {
                queue.push_back(*i);
                visited[*i] = true;
            }
        }
    }
}
