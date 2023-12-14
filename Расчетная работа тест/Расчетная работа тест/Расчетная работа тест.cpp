#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void EC(vector<vector<size_t>>& graph, size_t edges, size_t start, vector<size_t>& solution)
{
    // Выход если рёбер не осталось
    if (solution.size() > edges)
        return;

    // Добавляем текущую вершину в путь
    solution.push_back(start);

    // Поиск непройденных рёбер
    for (size_t i = 0; i < graph.size(); i++)
    {
        if (graph[start][i] > 0)
        {
            // Уменьшаем количество рёбер
            graph[start][i]--;
            graph[i][start]--;

            // Поиск пути
            EC(graph, edges, i, solution);

            // Восстановляем количество рёбер
            graph[start][i]++;
            graph[i][start]++;
        }
    }

    // Если эйлеров цикл не найден убираем вершину из пути
    if (solution.size() <= edges || solution.back() != solution.front())
        solution.pop_back();
}

int main()
{
    // Файл 
    ifstream fin("Graph.txt");
    if (!fin.is_open())
    {
        cout << "Failed to open the file" << endl;
        return 0;
    }

    // Вершины
    string vertices;
    getline(fin, vertices);

    // Кол-во рёбер и стартовая позиция
    size_t edges = 0, start = 0;

    // Матрица смежности
    vector<vector<size_t>> matrix(vertices.size(), vector<size_t>(vertices.size(), 0));

    // Считывание рёбер
    string str;
    while (getline(fin, str))
    {
        // Поиск вершин
        size_t x, y;
        x = vertices.find(str[0]);
        y = vertices.find(str[1]);

        // Добавление ребра 
        if (x != string::npos && y != string::npos)
        {
            matrix[x][y]++;
            matrix[y][x]++;
            edges++;
            start = y;
        }
    }
    fin.close();
    

    // Проверка на наличие рёбер
    if (edges == 0)
    {
        cout << "The graph doesn't contain any edges" << endl;
        return 0;
    }

    // Поиск пути
    vector<size_t> result;
    EC(matrix, edges, start, result);

    // Вывод результата
    for (size_t i = 0; i < result.size(); i++)
        cout << vertices[result[i]];
    if (result.empty())
        cout << "The graph doesn't contain an Eulerian cycle";
    cout << endl;
}