// 516losik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

using namespace std;

class Graph {
    vector<vector<int>> g, gr;
    vector<int> visited, order;

    void dfs1(int v) {
        visited[v] = 1;
        for (int to : gr[v]) {
            if (!visited[to]) {
                dfs1(to);
            }
        }
        order.push_back(v);
    }

    void dfs2(int v, int component) {
        visited[v] = component;
        for (int to : g[v]) {
            if (!visited[to]) {
                dfs2(to, component);
            }
        }
    }
public:
    Graph(int vertexCount) {
        g.resize(vertexCount);
        gr.resize(vertexCount);
    }

    ~Graph() {
        order.clear();
        visited.clear();
        g.clear();
        gr.clear();
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<int> findScc() {
        visited.assign(g.size(), 0);
        for (int v = 0; v < g.size(); v++) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        reverse(order.begin(), order.end());

        visited.assign(g.size(), 0);
        int SccCount = 0;
        for (int v : order) {
            if (!visited[v]) {
                dfs2(v, ++SccCount);
            }
        }

        return visited;
    }
};



int main()
{
    int vertexCount, edgeCount, max_comp;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> edgeCount >> vertexCount;
    
   int** gr_ = new int* [edgeCount];
    for (int i = 0; i < edgeCount; ++i) {
        gr_[i] = new int[edgeCount];
    }

    for (int i = 0; i < edgeCount; ++i) {
        for (int k = 0; k < edgeCount; ++k) {
            gr_[i][k] = 0;
        }
    }

    for (int i = 0; i < edgeCount; ++i) {
        int a, b;
        cin >> a >> b;
        gr_[a - 1][b - 1] = 1;
    }

    for (int i = 0; i < edgeCount; ++i) {
        for (int k = 0; k < edgeCount; ++k) {
            cout << gr_[i][k] << " ";
        }
        cout << endl;
    }

    cout << endl;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; ++i) {
        for (int k = 0; k < edgeCount; ++k) {
            if (gr_[i][k] == 1) {
                graph.addEdge(i, k);
            }
        }
    }

    vector<int> scc = graph.findScc();
    max_comp = scc[0];
   
    for (int j = 0; j < edgeCount; ++j) {
       int** graph_ = new int* [edgeCount - 1];
       for (int i = 0; i < edgeCount - 1; ++i) {
           graph_[i] = new int[edgeCount - 1];
       }
       
       int row = 0;
       for (int i = 0; i < edgeCount && row < edgeCount-1; ++i) {
           int col = 0;
           for (int k = 0; k < edgeCount && col <edgeCount-1; ++k) {
               if (i != j && k != j) {
                   graph_[row][col] = gr_[i][k];
                   ++col;
               }
           }
           ++row;
       }

       cout << endl;

       Graph gr(vertexCount-1);

       for (int i = 0; i < edgeCount - 1; ++i) {
           for (int k = 0; k < edgeCount - 1; ++k) {
               if (graph_[i][k] == 1) {
                   gr.addEdge(i, k);
               }
           }
       }

       vector<int> scc_ = gr.findScc();

       if (scc_[0] > scc[0]) {
           cout << j;
       }

       for (int i = 0; i < edgeCount - 1; ++i) {
           delete[] graph_[i];
       }
       delete[] graph_;
    }

   for (int i = 0; i < edgeCount; ++i) {
        delete[] gr_[i];
    }
    delete[] gr_;
    return 0;
}