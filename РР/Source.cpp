#include <iostream>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adjList;

    Graph(int V) : V(V), adjList(V) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }
};

void primMST(Graph& graph) {
    vector<bool> inMST(graph.V, false);
    vector<int> key(graph.V, INT_MAX);
    vector<int> parent(graph.V, -1);

    key[0] = 0;

    for (int count = 0; count < graph.V - 1; ++count) {
        int minKey = INT_MAX;
        int u = -1;

        for (int v = 0; v < graph.V; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (const auto& neighbor : graph.adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    for (int i = 1; i < graph.V; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}
int main() {
    int n, m;
    system("chcp 1251 > nul");
    cout << "Введите количество вершин: \n";
    while (1) {
        cin >> n;
        if (!cin.fail()) {
            break;
        }
        cin.clear();
        cout << "Это не число \n";
        cout << "Введите количество вершин \n";
        cin.ignore(INT_MAX, '\n');
    }

    cout << "Введите количество рёбер: \n";
    while (1) {
        cin >> m;
        if (!cin.fail()) {
            break;
        }
        cin.clear();
        cout << "Это не число \n";
        cout << "Введите количество рёбер \n";
        cin.ignore(INT_MAX, '\n');
    }
    Graph graph(n);
    cout << "Введите список инцидентности(числа от 0 до n-1, где n - количество вершин) и вес рёбер: \n";
    for (int i = 0; i < m; i++) {
        int v, u, weight;
        while (1) {
            cin >> v >> u >> weight;
            if (!cin.fail()) {
                if (v >= n || u >= n || weight < 0) {
                    cout << "Ошибка ввода\n";
                }
                else {
                    break;
                }
            }
            cin.clear();
            cout << "Некорректный ввод\n";
            cout << "Введите 2 вершины и вес: \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        graph.addEdge(v, u, weight);
    }

    primMST(graph);

    return 0;
}
