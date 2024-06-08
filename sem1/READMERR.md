# Отчет по расчетной работе по дисциплине ПиОИвИС

### Цель:
Ознакомиться с  основами теории графов, способами представления графов, базовыми алгоритмами для работы с разными видами графов.
### Условие задания
Найти граф инциденций неориентированного графа.
Вывод работы программы выводиться в консоль в виде матрицы инцидентности и матрицы смежности.
### Базовые понятия 
- **Граф** - совокупность двух множеств множества самих объектов, называемого множеством вершин, и множества их парных связей, называемого множеством рёбер.
- **Неориентированный** граф-граф, в котором все ребра являются звеньями, то есть порядок двух концов ребра графа не существенен.
- **Матрица смежности** - это способ представления графа в виде матрицы. В этой матрице каждая строка и столбец соответствуют одной вершине графа. Элемент матрицы на пересечении строки i и столбца j равен 1, если вершины i и j соединены ребром, и 0, если они не соединены.
- **Матрица инцидентности** — одна из форм представления графа, в которой указываются связи между инцидентными элементами графа (ребро(дуга) и вершина). Столбцы матрицы соответствуют ребрам, строки — вершинам. Ненулевое значение в ячейке матрицы указывает связь между вершиной и ребром (их инцидентность).
### Код:
```cpp
#include <iostream>
#include <vector>

using namespace std;

// Функция для создания графа инциденций
vector<vector<int>> create_incidence_matrix(vector<vector<int>>& edges, int num_vertices) {
    vector<vector<int>> incidence_graph(num_vertices, vector<int>(edges.size(), 0));

    for (int i = 0; i < edges.size(); ++i) {
        int vertex1 = edges[i][0];
        int vertex2 = edges[i][1];

        incidence_graph[vertex1][i] = 1;
        incidence_graph[vertex2][i] = 1;
    }

    return incidence_graph;
}

// Функция для вывода графа инциденций
void print_incidence_matrix(const vector<vector<int>>& incidence_graph) {
    cout << "Graf incidencij:" << endl << endl;
    int nomer_vershini = 1;
    for (const auto& row : incidence_graph) {
        cout << nomer_vershini << "\t";
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
        nomer_vershini++;
    }
}

// Функция для создания матрицы смежности
vector<vector<int>> create_adjacency_matrix(const vector<vector<int>>& incidence_graph) {
    int num_vertices = incidence_graph.size();
    vector<vector<int>> adjacency_matrix(num_vertices, vector<int>(num_vertices, 0));

    for (int i = 0; i < incidence_graph[0].size(); ++i) {
        int vertex1 = -1, vertex2 = -1;
        for (int j = 0; j < incidence_graph.size(); ++j) {
            if (incidence_graph[j][i] == 1) {
                if (vertex1 == -1) {
                    vertex1 = j;
                }
                else {
                    vertex2 = j;
                }
            }
        }
        if (vertex1 != -1 && vertex2 != -1) {
            adjacency_matrix[vertex1][vertex2] = 1;
            adjacency_matrix[vertex2][vertex1] = 1;
        }
    }

    return adjacency_matrix;
}

// Функция для вывода матрицы смежности
void print_adjacency_matrix(const vector<vector<int>>& adjacency_matrix) {
    cout << "Matrica smezhnosti:" << endl << endl;
    for (const auto& row : adjacency_matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int num_vertices, num_edges;
    int e1, e2;
    int nomer_rebra = 1;
    cout << "Vvedite kolichestvo vershin: ";
    cin >> num_vertices;

    cout << "Vvedite kolichestvo reber: ";
    cin >> num_edges;

    vector<vector<int>> edges(num_edges, vector<int>(2));

    cout << "Vvedite pari vershin dla kazhdogo rebra:" << endl;
    for (int i = 0; i < num_edges; ++i) {
        cout << nomer_rebra << " : ";
        cin >> e1 >> e2;

        edges[i][0] = e1 - 1;
        edges[i][1] = e2 - 1;

        nomer_rebra++;
    }

    vector<vector<int>> incidence_graph = create_incidence_matrix(edges, num_vertices);
    print_incidence_matrix(incidence_graph);

    vector<vector<int>> adjacency_matrix = create_adjacency_matrix(incidence_graph);
    print_adjacency_matrix(adjacency_matrix);

    return 0;
}
```

## Пример работы:
Дан граф:
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-12-06%20031541.png)
Результат работы программы:
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-12-06%20031954.png)
## Вывод

В результате выполнения данной работы были получены следующие практические навыки:
- изучены основы теории графов
- изучены виды представления неориентированных графов
- изучены базовые алгоритмы для работы с графами
