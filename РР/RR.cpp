#include <iostream>
#include <vector>

using namespace std;

void findPath(vector<vector<int>>& graph, int path, int start, int length,vector<int>&pytb, int startV) {
    if (path == length) {
        cout << startV<<' ';
        for (auto x : pytb)
            cout << pytb[x] << ' ';
        exit(1);
    }

    else if (path < length) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[start][i] != 0  && (path + graph[start][i])<=length){
                pytb.push_back(i);
                path += graph[start][i];
                findPath(graph, path,i , length, pytb,startV);
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int numVertices;
    cout << "Введите количество вершин: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Введите матрицу смежности (0 - отсутствие ребра, вес - вес ребра):" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    int startVertex, endVertex, desiredLength;
    cout << "Введите начальную вершину: ";
    cin >> startVertex;
    cout << "Введите длину пути: ";
    cin >> desiredLength;

    int path = 0;
    vector <int> pytb;
    findPath(graph, path, startVertex, desiredLength,pytb,startVertex);

    return 0;
}