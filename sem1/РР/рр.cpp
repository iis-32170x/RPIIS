#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestCycle(vector<vector<int>>& adjList, int n) {
    int minCycle = n + 1; 

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false); 
        queue<pair<int, int>> q; 
        q.push({ i, 0 }); 

        while (!q.empty()) {
            int cur = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (int neighbor : adjList[cur]) {
                if (neighbor == i) { 
                    minCycle = min(minCycle, dist + 1); 
                }
                else if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({ neighbor, dist + 1 });
                }
            }
        }
    }

    if (minCycle == n + 1) {
        return -1; 
    }
    else {
        return minCycle; 
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, m;
    cout << "Введите количество вершин: ";
    cin >> n;
    cout << "Введите количество рёбер: ";
    cin >> m;

    vector<vector<int>> adjList(n);
    cout << "Введите список смежности: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adjList[u].push_back(v);
    }

    int cycleLength = shortestCycle(adjList, n);
    if (cycleLength == -1) {
        cout << "Обхват графа: бесконечность" << endl;
    }
    else {
        cout << "Обхват графа: " << cycleLength << endl;
    }

    return 0;
}
