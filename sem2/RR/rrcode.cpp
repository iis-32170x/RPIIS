#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<vector<int>>& matrix, int node, vector<int>& component, vector<bool>& visited) {
    visited[node] = true;
    component.push_back(node);
    for (int j = 0; j < matrix[node].size(); j++) {
        if (matrix[node][j] == 1 && !visited[j]) {
            DFS(matrix, j, component, visited);
        }
    }
}
vector<vector<int>> findComponents(vector<vector<int>>& matrix) {
    vector<vector<int>> components;
    vector<bool> visited(matrix.size(), false);
    for (int i = 0; i < matrix.size(); i++) {
        if (!visited[i]) {
            vector<int> component;
            DFS(matrix, i, component, visited);
            components.push_back(component);
        }
    }
    return components;
}
vector<int> reversed(vector<int> v) {
    vector<int> r;
    r.resize(v.size());
    for (int i = 0; i < r.size(); i++) {
        r[i] = v[v.size() - 1 - i];
    }
    return r;
}
int main() {
    setlocale(LC_ALL, "ru");
    vector<vector<int>>matrix;
    cout << "Введите количество узлов вашего неориетированного графа" << endl;
    int size; cin >> size;
    matrix.resize(size);
    for (int i = 0; i < size; i++) {
        matrix[i].resize(size);
    }
    vector<vector<bool>>written;
    written.resize(matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
        written[i].resize(matrix.size());
    }
    for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        if (written[i][j] != true && written[j][i] != true) {
            if (i == j) { matrix[i][j] = 0; matrix[j][i] = 0; }
            else {
                cout << "Связан ли узел " << i << " с узлом " << j << endl;
                bool input; cin >> input;
                matrix[i][j] = input;
                matrix[j][i] = input;
            }
            written[i][j] = true;
            written[j][i] = true;
        }
        }
    }
    vector<vector<int>>setOFcomponets;
    setOFcomponets = findComponents(matrix);
    vector<vector<int>>setOFbridges;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] == 1) {
                vector<vector<int>>fake;
                fake = matrix;
                fake[i][j] = 0;
                fake[j][i] = 0;
                vector<vector<int>>setOFfake;
                setOFfake = findComponents(fake);
                if (setOFfake.size() > setOFcomponets.size()) {
                    vector<int>bridge;
                    bridge.push_back(i); bridge.push_back(j);
                    setOFbridges.push_back(bridge);
                }
            }
        }
    }
    vector<int>repeat_indexes;
    for (int i = 0; i < setOFbridges.size(); i++) {
        for (int j = i + 1; j < setOFbridges.size(); j++) {
            if (setOFbridges[i] == reversed(setOFbridges[j])) {
                repeat_indexes.push_back(i);
            }
        }
    }
    for(int i=0;i< setOFbridges.size();i++){
        bool ban = false;
        for (int j = 0; j < repeat_indexes.size(); j++) {
            if (repeat_indexes[j] == i) { ban = true; }
        }
        if (ban == false) {
            cout << setOFbridges[i][0] << " - " << setOFbridges[i][1] << endl;
        }
    }
    
}
