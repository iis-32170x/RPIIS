~~~C++
#include <iostream> 
#include <vector> 
#include <queue> 
#include <climits> 
#include <fstream> 
using namespace std;

struct Edge {
    int to;        // информация о конечной вершине *to* и весе *weight* ребра
    int weight;
};

/////////////вычисление эксцентриситета заданной вершины//////////
int findEccentricity(vector<vector<Edge>>& adjList, int start, int n) { //список смежности *adjList*, n-общее количество вершин
    vector<int> dist(n, INT_MAX);//вектор *dist* для хранения расстояний от заданной вершины до всех остальных вершин (изначально расстояние от вершины *start* до любой другой вершины ∞)
    dist[start] = 0; //расстояние вершины *start* до самой себя

    queue<int> q; //создаем очередь для хранения вершин, которые мы будем рассматривать
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const Edge& edge : adjList[cur]) { // для каждого ребра *edge*, инцидентного текущей вершине cur (adjList[cur]-ребра, инцидентные вершине) выполняем:
            int neighbor = edge.to; // *neighbor*- номер соседней вершины для вершины *cur*
            int weight = edge.weight; //*weight* -вес ребра

            if (dist[neighbor] > dist[cur] + weight) { //Если найден новый более короткий путь к вершине *neighbor*, то его расстояние обновляется, и вершина добавляется в очередь для дальнейшего рассмотрения. Этот процесс продолжается до тех пор, пока не будут рассмотрены все возможные пути и найдены кратчайшие расстояния от стартовой вершины до всех других вершин в графе.
                dist[neighbor] = dist[cur] + weight;
                q.push(neighbor);
            }
        }
    }

    int maxDist = 0;
    for (int i = 0; i < n; ++i) { //находим эксцентриситет вершины (максимальное удаление(расстояние) от данной вершины)
        maxDist = max(maxDist, dist[i]); //в каждой итерации цикла используется функция max, которая возвращает большее из двух значений
    }

    return maxDist;
}
///////////////////////////////////////////////////////////////////////



/////////нахождение диаметра графа/////////////////////////////////////
int findGraphDiametr(vector<vector<Edge>>& adjList, int n) {
    int maxEccentricity = INT_MIN;

    for (int i = 0; i < n; ++i) { //проходим по всем вершинам графа и вычисляем эксцентриситет каждой вершины с помощью ф-ии *findEccentricity*
        int eccentricity = findEccentricity(adjList, i, n);
        maxEccentricity = max(maxEccentricity, eccentricity); //находим максимальный эксцентриситет, который и будет диаметром
    }

    if (maxEccentricity == INT_MIN) { //если граф пустой или несвязный
        return -1;
    }
    else {
        return maxEccentricity;
    }
}
/////////////////////////////////////////////////////////////////////



///////ввод значений и их обработка//////////////////////////////////
void run_testcase() {
    

    int n, m;
    cout << "Введите количество вершин, потом ребер (максимальный размер - 7х7): ";
    cin >> n >> m; //кол-во вершин n и кол-во ребер m

    vector<vector<Edge>> adjList(n);
    int matr[7][7];
    cout << "Введите матрицу инцидентности взвешенного ненаправленного графа:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }
    cout << "Список смежности: " << endl;
    int u, v, w; //вершины u и v, вес w 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { 
            if (matr[j][i] > 0) {
                for (int p = j + 1; p < n; p++) {
                    if (matr[p][i] == matr[j][i]) {
                        v = p; u = j; w = matr[j][i]; break;
                    }
                    else continue;
                }
            } 
            if (matr[j][i] == 0) continue;
        }

        Edge edge_to_v = { v, w }; //ребро, направленное к вершине v с весом w
        Edge edge_to_u = { u, w }; //ребро, направленное к вершине u с весом w

        adjList[u].push_back(edge_to_v); //добавляем созданное ребро *edge_to_v* в список смежности для вершины u
        adjList[v].push_back(edge_to_u); ////добавляем созданное ребро *edge_to_u* в список смежности для вершины v
        cout << u + 1 << "<->" << v + 1 << " " << w << endl; //выводим список смежности
        cout << endl;
        
    }

    int graphDiametr = findGraphDiametr(adjList, n);
    if (graphDiametr == -1) {
        cout << "Граф несвязанный или пустой " << endl;
    }
    else {
        cout << "Диаметр графа: " << graphDiametr << endl;
    }
    cout << "--------------------------------------------------\n";
}
//////////////////////////////////////////////////////////////////////////////



////////запуск тестовых случаев/////////////////////////////////////////////
int main() {
    setlocale(LC_ALL, "ru");

    // Run the test case
    run_testcase();

    return 0;
}
~~~
