#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int radius(vector<vector<int>>& adjMatrix, int V) {
    int rad = INF;

    for (int i = 0; i < V; i++) {
        vector<int> dist(V, INF);
        dist[i] = 0;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != INF && dist[v] == INF) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    q.push(v);
                }
            }
        }

        int maxDist = 0;
        for (int j = 0; j < V; j++) {
            maxDist = max(maxDist, dist[j]);
        }

        rad = min(rad, maxDist);
    }

    return rad;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int V;
    cout << "Ââåäèòå ÷èñëî âåðøèí: ";
    cin >> V;

    vector<vector<int>> adjMatrix(V, vector<int>(V));
    cout << "Ââåäèòå ìàòðèöó ñìåæíîñòè (åñëè íåò ðåáðà, ââåäèòå INF):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int rad = radius(adjMatrix, V);
    cout << "Ðàäèóñ âçâåøåííîãî îðèåíòèðîâàííîãî ãðàôà: " << rad << endl;

    return 0;
}
