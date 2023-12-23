# Отчет по Расчётной работе по дисциплине ПиОИвИС
- `Тема` расчётной работы - ${Графы}$.

- `Цель` расчётной работы - Поиск реберного графа для данного неориентированного графа

- `Задача` заключается в разработке алгоритма, который выполняет поставленную задачу, согласно варианту, который необходимо выполнить. 

- `Вариант` - ${4.12(ми)}$
## Список ключевых понятий и определений
-  ${Граф}$ - это **совокупность непустого множества вершин и множества пар вершин**

 ![|400](https://kpolyakov.spb.ru/school/test10/5_files/0_numway10.gif)
	
-  ${Неориентированный}$ ${граф}$ - это граф, **рёбра которого не имеют направления и могут быть проходимыми в обоих направлениях**.

  ![|400](https://eng.libretexts.org/@api/deki/files/42793/clipboard_e2c0029f031ce8d39860aa77e76b909cf.png?revision=1&size=bestfit&width=321&height=151)

- ${Рёберный}$ ${граф}$ - это такой граф L(G), заданного графа G, для которого истины следующие утверждения:
  - Любая вершина графа L(G) представляет ребро графа G
  - Две вершины графа L(G) смежны тогда и только тогда, когда их соответствующие рёбра смежны в графе G

![|400](https://github.com/iis-32170x/RPIIS/assets/135509020/60379413-97e1-4269-92fa-3988667c6a99)


-  ${Матрица}$ ${ инцидентности}$ — **одна из форм представления графа, в которой указываются связи между вершинами графа**. В качестве элементов строк выступают вершины графа, а в качестве элементов столбцов - рёбра, соединяющие вершины. Соответственно, в случае принадлежности ребра вершине, ставится значение 1, иначе - 0
  
  ![|400](https://kvodo.ru/wp-content/uploads/incidence_matrix.jpg)

  ## Алгоритм решения задачи с графами:
  Разработанный алгоритм предусматривает прохождение по каждой строчке данной матрицы инцидентности и нахождение пар смежных между собой ребер. Далее предусматривается создание новой матрицы инцидентности, количество строк которой будет соответствовать количеству ребер в исходном графе. Заполнение матрицы будет происходить на основе информации о смежных ребрах. 
  ## Код - реализация решения задачи с графами на ЯП С++:
  ```C++
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int edges;
int vertices;
map<int, pair<int, int>> connection;

void find_adjacent_edges(const vector<vector<int>>& matrix) {
    int rows = vertices;    // Number of vertices
    int columns = edges;  // Number of edges

    int num = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++) {
            if (matrix[i][j] == 1) {
                for (int k = j + 1; k < columns; k++) {
                    if (matrix[i][k] == 1) {
                        connection[num] = make_pair(j, k);
                        num++;
                    }
                }
            }
        }
    }

    // Print connections
    cout << "_______________________" << endl << endl;
    cout << "Смежные ребра:" << endl;
    vector<vector<int>> AdjacentEdges;
    for (const auto& pair : connection) {
        cout << pair.first << 'e' << " :  " << char(65 + pair.second.first) << " - " << char(65 + pair.second.second)  << endl;
    }
    cout << "_______________________" << endl << endl;
}

vector<vector<int>> create_edge_graph(const map<int, pair<int, int>>& connections) {
    int num_vertices = 0;
    int num_edges = connections.size();

    // Determine the maximum vertex index
    for (const auto& pair : connections) {
        int vertex1 = pair.second.first;
        int vertex2 = pair.second.second;
        num_vertices = max(num_vertices, max(vertex1, vertex2) + 1);
    }

    vector<vector<int>> incidence_matrix(num_vertices, vector<int>(num_edges, 0));

    for (const auto& pair : connections) {
        int edge_index = pair.first - 1;  // Edge indices start from 0
        int vertex1 = pair.second.first;
        int vertex2 = pair.second.second;

        incidence_matrix[vertex1][edge_index] = 1;
        incidence_matrix[vertex2][edge_index] = 1;
    }
    return incidence_matrix;
}

int main()
{
    vector<vector<int>> IncMatrix(vertices, vector<int>(edges));
    int i;
    int j;
    setlocale(LC_ALL, "RUSSIAN");
    ifstream in("graph.txt");

    if (in.is_open())
    {
        int count = 0;
        int temp;
        while (!in.eof())
        {
            in >> temp;
            count++;
        }
        in.seekg(0, ios::beg);
        in.clear();
        int count_space = 0;
        char symbol;
        while (!in.eof())
        {
            in.get(symbol);
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }
        in.seekg(0, ios::beg);
        in.clear();
        vertices = count / (count_space + 1);
        edges = count_space + 1;
        vector<vector<int>> IncMatrix(vertices, vector<int>(edges));
        for (i = 0; i < vertices; i++)
            for (j = 0; j < edges; j++)
                in >> IncMatrix[i][j];
        
        for (i = 0; i < vertices; i++) {
            
            for (j = 0; j < edges; j++)
                cout << IncMatrix[i][j] << " ";
            cout << "\n";
        }
        in.close();
        find_adjacent_edges(IncMatrix);
        vector<vector<int>> incidence_matrix = create_edge_graph(connection);
        for (const auto& row : incidence_matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Файл не найден." << endl;
    }
    system("pause");
    return 0;
}
```
## Разбор блоков кода
Код состоит из 3-ух основных частей:
- 1-ая пользовательская функция, которая ищет пары смежных ребер в начальном неориентированном графе и выводит их
- 2-ая пользовательская функция, которая составляет новую матрицу инцидентности для реберного графа по данным, полученным из 1-ой функции
- Вывод и вызов прошлых заданных функций в функции main
  
Разберем каждую из них:
## 1: 
```C++
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int edges;
int vertices;
map<int, pair<int, int>> connection;

void find_adjacent_edges(const vector<vector<int>>& matrix) {
    int rows = vertices;    // Number of vertices
    int columns = edges;  // Number of edges

    int num = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns-1; j++) {
            if (matrix[i][j] == 1) {
                for (int k = j + 1; k < columns; k++) {
                    if (matrix[i][k] == 1) {
                        connection[num] = make_pair(j, k);
                        num++;
                    }
                }
            }
        }
    }

    // Print connections
    cout  << endl << endl;
    vector<vector<int>> AdjacentEdges;
    for (const auto& pair : connection) {
        cout << pair.first << 'e' << " :  " << char(65 + pair.second.first) << " - " << char(65 + pair.second.second)  << endl;
    }
    cout  << endl << endl;
}
```
В данной функции использован контейнер `map<key,digit>`, состоящий из некоторого целого ключа и пары элементов (пара смежных ребер) в качестве значения. Далее запущен цикл, который проходит по всей матрице, и пытается найти две единицы в какой-либо строке. Т.к. строки матрицы инцидентности отвечают вершинам графа, а столбцы отвечают ребрам графа, то если существуют хотя бы 2 единицы в какой либо строке матрицы, значит хотя бы 2 ребра являются смежными, что нам и надо. Соотвественно при нахождении пары единиц в строке, строковые индексы соответсвующих единиц заносятся в пару `pair<int,int>`. При завершении цикла происходит вывод созданных контейнеров `map`.
## 2:
```C++
vector<vector<int>> create_edge_graph(const map<int, pair<int, int>>& connections) {
    int num_vertices = 0;
    int num_edges = connections.size();

    // Determine the maximum vertex index
    for (const auto& pair : connections) {
        int vertex1 = pair.second.first;
        int vertex2 = pair.second.second;
        num_vertices = max(num_vertices, max(vertex1, vertex2) + 1);
    }

    vector<vector<int>> graph_IncMatrix(num_vertices, vector<int>(num_edges, 0));

    for (const auto& pair : connections) {
        int edge_index = pair.first - 1;  // Edge indices start from 0
        int vertex1 = pair.second.first;
        int vertex2 = pair.second.second;

        graph_IncMatrix[vertex1][edge_index] = 1;
        graph_IncMatrix[vertex2][edge_index] = 1;
    }
    return graph_IncMatrix;
}
```
В данной функции происходит создание новой матрицы инцидентности для реберного графа на основе полученных смежных ребер из первой матрицы инцидентности. В первом цикле функции задаются параметры матрицы инцидентности, функция определяет кол-во строк и столбцов матрицы. Во втором цикле функции происходит заполнение матрицы единицами, элементам с соответствующими индексами `[vertex1][edge_index]` и `[vertex2][edge_index]` присваивается значение `1`, все остальные элементы остаются неизменными (`0`). В конце функция возвращает свой тип, а именно составленную матрицу.
## 3:
```C++
int main()
{
    vector<vector<int>> IncMatrix(vertices, vector<int>(edges));
    int i;
    int j;
    setlocale(LC_ALL, "RUSSIAN");
    ifstream in("graph.txt");

    if (in.is_open())
    {
        int count = 0;
        int temp;
        while (!in.eof())
        {
            in >> temp;
            count++;
        }
        in.seekg(0, ios::beg);
        in.clear();
        int count_space = 0;
        char symbol;
        while (!in.eof())
        {
            in.get(symbol);
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }
        in.seekg(0, ios::beg);
        in.clear();
        vertices = count / (count_space + 1);
        edges = count_space + 1;
        vector<vector<int>> IncMatrix(vertices, vector<int>(edges));
        for (i = 0; i < vertices; i++)
            for (j = 0; j < edges; j++)
                in >> IncMatrix[i][j];
        
        for (i = 0; i < vertices; i++) {
            
            for (j = 0; j < edges; j++)
                cout << IncMatrix[i][j] << " ";
            cout << "\n";
        }
        in.close();
        find_adjacent_edges(IncMatrix);
        vector<vector<int>> incidence_matrix = create_edge_graph(connection);
        for (const auto& row : incidence_matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Файл не найден." << endl;
    }
    system("pause");
    return 0;
}
```
В теле главной функции происходит чтение матрицы из данного файла, посредством библиотеки C++ <fstream>, и параллельное определение параметров матрицы, таких как кол-во строк и столбцов. Далее идет последовательный вызов функций и вывод получившейся матрицы.
