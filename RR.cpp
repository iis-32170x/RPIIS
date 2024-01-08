#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100000];
bool used[100000];

void dfs(int v, int p = -1) {
    used[v] = true;

    for (int u : graph[v]) {
        if (!used[u]) {
            dfs(u, v);
        }
        else if (u != p) {
            cout << "Граф содержит циклы." << endl;
            exit(0);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    vector<vector<bool>> graphMatrix;
    vector<bool> visited;
    int size;
    cout << "Введите мощность множества вершин графа: ";
    cin >> size;
    graphMatrix.resize(size);
    for (int i = 0; i < size; i++) {
        graphMatrix[i].resize(size);
    }
    visited.resize(size);

    for (int i = 0; i < graphMatrix.size(); i++) {
        for (int j = 0; j < graphMatrix[i].size(); j++) {
            cout << "Между вершинами " << i << " и " << j << " есть связь? (1 - да, 0 - нет): ";
            bool input;
            cin >> input;
            graphMatrix[i][j] = input;
            if (input) {
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    cout << "Граф не содержит циклов." << endl;

    return 0;
}
