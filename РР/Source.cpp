#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> Listsmez;

    Graph(int V) : V(V), Listsmez(V) {}

    void addV(int u, int v, int weight) {
        Listsmez[u].push_back(make_pair(v, weight));
        Listsmez[v].push_back(make_pair(u, weight));
    }
};

void Tree(Graph& graph) {
    vector<bool> inTree(graph.V, false);
    vector<int> key(graph.V, INT_MAX);
    vector<int> parent(graph.V, -1);

    key[0] = 0;

    for (int count = 0; count < graph.V; count++) {
        int minKey = INT_MAX;
        int u = -1;
        for (int v = 0; v < graph.V; ++v) {
            if (!inTree[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        inTree[u] = true;
        for (auto& neighbor : graph.Listsmez[u]) {
            if (!inTree[neighbor.first] && neighbor.second < key[neighbor.first]) {
                parent[neighbor.first] = u;
                key[neighbor.first] = neighbor.second;
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
    cout << "Введите список инцидентности(числа от 0 до n-1, где n - количество вершин): \n";
    for (int i = 0; i < m; i++) {
        int v, u, 
        const weight = 1;
        while (1) {
            cin >> v >> u;
            if (!cin.fail()) {
                if (v >= n || u >= n) {
                    cout << "Ошибка ввода\n";
                }
                else {
                    break;
                }
            }
            cin.clear();
            cout << "Некорректный ввод\n";
            cout << "Введите 2 вершины: \n";
            cin.ignore(INT_MAX, '\n');
        }
        graph.addV(v, u, weight);
    }

    Tree(graph);

    return 0;
}
