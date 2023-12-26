Напишите код, который определяет, является ли данный граф дерева неориентированным или нет:


```c++
#include <iostream>
#include <vector>
#include <queue>
#include <limits> // Добавлен заголовочный файл для numeric_limits

using namespace std;

// Функция для проверки двудольности графа
bool isBipartite(const vector<vector<int>>& incidenceMatrix, int vertices) {
    vector<int> color(vertices, -1); // -1: не покрашена, 0: цвет 1, 1: цвет 2
    queue<int> q;

    for (int i = 0; i < vertices; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < vertices; ++v) {
                    if (incidenceMatrix[u][v] == 1) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false; // Граф не двудольный
                        }
                    }
                }
            }
        }
    }

    return true; // Граф двудольный
}

int main() {
    int vertices;
    cout << "Введите количество вершин (от 1 до 10): ";
    cin >> vertices;

    // Проверка ввода
    if (vertices < 1 || vertices > 10) {
        cout << "Некорректное количество вершин." << endl;
        return 1;
    }

    vector<vector<int>> incidenceMatrix(vertices, vector<int>(vertices, 0));

    // Заполнение матрицы инцидентности значениями, введенными пользователем
    cout << "Введите матрицу инцидентности (0 или 1) для графа:" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            while (true) {
                cout << "Между вершиной " << i << " и " << j << ": ";
                cin >> incidenceMatrix[i][j];

                if (cin.fail() || (incidenceMatrix[i][j] != 0 && incidenceMatrix[i][j] != 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка ввода. Введите 0 или 1." << endl;
                } else {
                    incidenceMatrix[j][i] = incidenceMatrix[i][j];
                    break;
                }
            }
        }
    }

    // Вывод матрицы инцидентности
    cout << "Матрица инцидентности:" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Проверка на двудольность
    if (isBipartite(incidenceMatrix, vertices)) {
        cout << "Граф двудольный" << endl;
    } else {
        cout << "Граф не двудольный" << endl;
    }

    return 0;
}
```

Попробуем на произвольном графике:


<h1><img width="530" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/148941447/d0dbe436-a519-40f6-a48a-4a033ff58c3c"></h1>



<h1><img width="530" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/148941447/f017ceee-fedb-4711-a594-b8a09fb1ddc8"></h1>




В Результате этот выполняет проверку неориентированного графа на двудольность в соответствии с условием.



