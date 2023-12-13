#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int componenti(vector<vector<int>>& spisok) {
    int n = spisok.size();
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

                for (int sosed : spisok[curr]) {
                    if (!visited[sosed]) {
                        q.push(sosed);
                        visited[sosed] = true;
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

    int n, m; // вершины и ребра
    inputFile >> n >> m;

    vector<vector<int>> spisok(n);

    for (int i = 0; i < m; ++i) {
        int u, v; // смежные вершины u и v
        inputFile >> u >> v;
        spisok[u - 1].push_back(v - 1);
        spisok[v - 1].push_back(u - 1);
    }

    inputFile.close();

    int components = componenti(spisok);

    outputFile << "Count of components is: " << components << endl;

    outputFile.close();

   

    return 0;
}
