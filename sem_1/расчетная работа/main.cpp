#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

// Граф и его транспонированный граф
vector<vector<int>> g, gt;

// Массив для отслеживания посещенных вершин
vector<char> used;

// Массив для хранения порядка посещения вершин при первом проходе
vector<int> order;

// Массив для хранения компонент сильной связности
vector<int> component;

// Первый проход алгоритма DFS для построения массива order
void dfs1(int v) {
    used[v] = true;
    for (int u : g[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

// Второй проход алгоритма DFS для поиска компонент сильной связности
void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int u : gt[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    // Запросить у пользователя путь и название файла
    cout << "Введите полный путь и название файла: ";
    string filePath;
    cin >> filePath;

    // Открываем файл для чтения
    ifstream inputFile(filePath);

    // Проверяем, успешно ли открыт файл
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return 1; // Возвращаем код ошибки
    }

    // Считываем размер матрицы
    int n;
    inputFile >> n;

    // Инициализация g и gt
    g.resize(n);
    gt.resize(n);

    // Считываем матрицу смежности из файла и добавляем рёбра в граф
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int edge;
            inputFile >> edge;
            if (edge == 1) {
                g[i].push_back(j);
                gt[j].push_back(i);
            }
        }
    }

    // Закрываем файл
    inputFile.close();

    // Выводим считанную матрицу
    cout << "Считанная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Смежные вершины для " << (i + 1) << ": ";
        for (int j = 0; j < g[i].size(); ++j) {
            cout << g[i][j] + 1 << ' ';
        }
        cout << endl;
    }

    // Первый проход алгоритма DFS
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);

    // Второй проход алгоритма DFS и вывод компонент сильной связности
    used.assign(n, false);
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        if (!used[v]) {
            dfs2(v);
            // Вывод очередной component
            for (int u : component)
                cout << u + 1 << ' ';
            cout << endl;

            component.clear();
        }
    }

    return 0;
}
