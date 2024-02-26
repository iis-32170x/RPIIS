#include "NG.h"

void Ngraph::AddVertex(int a) {
    if ((graph.find(a) == graph.end())&&a>0) {
        graph[a] = std::set<int>();
    }
    
}

void Ngraph::AddEdge(int a, int b) {
    if (graph.find(a) == graph.end() || graph.find(b) == graph.end()) {
        return;
    } 
    graph[a].insert(b);
    graph[b].insert(a);
}

void Ngraph::DeleteVertex(int a)
{
    graph.erase(a);
    
    for (auto& kv : graph) {
        kv.second.erase(a); // Удаляем ребро, ведущее к удаляемой вершине
    }
}

void Ngraph::DeleteEdge(int a, int b)
{
    if (graph.find(a) == graph.end() || graph.find(b) == graph.end() || graph[a].find(b) == graph[a].end()) {
        return;

    }
        graph[a].erase(b);
        graph[b].erase(a);
}


void Ngraph::DFS(int a, std::map<int, bool>& visited)
{
    visited[a] = true; 
    std::cout << a << " ";
    for (int neighbor : graph[a]) {
        if (!visited[neighbor]) {
           DFS(neighbor, visited); 
        }
    }
    for (const auto& kv : graph) {
        if (!visited[kv.first]) {
            DFS(kv.first, visited);
        }
    }
}

void Ngraph::DFSTree(int first)
{
    std::map<int, bool> visited;
    DFS(first, visited);
    std::cout << std::endl;
}
