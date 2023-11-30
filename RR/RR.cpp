#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int connectedComponents(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }

            ++count;
        }
    }
    
    return count;
}

int main() {
    ifstream inputFile("graph3.txt");
    ofstream outputFile("countcomp.txt");

    int n, m; // Количество вершин и ребер
    inputFile >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v; // Смежные вершины u и v
        inputFile >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    inputFile.close();

    int components = connectedComponents(adj);

    outputFile << "Count of components is: " << components << endl;

    outputFile.close();

   

    return 0;
}