#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int girth(vector<vector<int>>& matrix, int n, int m) {
    int mingirth = n + 1;

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q; //
        q.push({ i, 0 });//добавляем элемент в конец очереди

        while (!q.empty()) {//проверяет есть ли в очереди хоть какой-нибудь элемент возвращает бул
            int cur = q.front().first;//смотрим на 1 элемент в очереди
            int dist = q.front().second;//смотрим на 2 элемент в очереди
            q.pop();//извлечение первого элемента из очереди

            for (int j = 0; j < m; j++) {
                if (matrix[cur][j] == 1) {
                    for (int neighbor = 0; neighbor < n; neighbor++) {
                        if (matrix[neighbor][j] == -1) {
                            if (neighbor == i) {
                                mingirth = min(mingirth, dist + 1);
                            }
                            else if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                q.push({ neighbor, dist + 1 });//
                            }
                        }
                    }
                }
            }
        }
    }

    if (mingirth == n + 1) {
        return -1;
    }
    else {
        return mingirth;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, m;
    cout << "Введите количество вершин: ";
    cin >> n;
    cout << "Введите количество рёбер: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    cout << "Введите матрицу инцидентности: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int mingirth = girth(matrix, n, m);
    if (mingirth == -1) {
        cout << "Обхват графа: бесконечность" << endl;
    }
    else {
        cout << "Обхват графа: " << mingirth << endl;
    }

    return 0;
}
