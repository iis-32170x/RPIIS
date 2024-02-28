#include "undirectedGraph.h"

bool Ngraph::VertexExists(int vertex) {
    return graph.find(vertex) != graph.end();
}

bool Ngraph::EdgeExists(int a, int b) {
    if (graph.find(a) == graph.end() || graph.find(b) == graph.end()) {
        return false;
    }
    return graph.at(a).find(b) != graph.at(a).end();
}

void Ngraph::AddVertex(int a) {
    if ((graph.find(a) == graph.end()) && a > 0) {
        graph[a] = std::set<int>();
    }

}

void Ngraph::AddEdge(int a, int b) {
    if (!VertexExists(a) || !VertexExists(b)) {
        throw std::invalid_argument("This vertex(es) is not exist");
    }
    graph[a].insert(b);
    graph[b].insert(a);
}

void Ngraph::DeleteVertex(int a)
{
    graph.erase(a);

    for (auto& kv : graph) {
        kv.second.erase(a);
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
