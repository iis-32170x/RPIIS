# Расчетная работа

## Вариант 5.10(внг)

### Нахождение максимального простого разрева в взвешенном неориентированном графе

#### Алгоритм:

##### 1.Инициализация
```
 int bfs(int source, int sink, int n) {
    memset(parent, -1, sizeof(parent));
    parent[source] = source;

    queue<pair<int, int>> q;
    q.push({source, INT_MAX});
 ```

memset(parent, -1, sizeof(parent))- Инициализирует массив parent значениями -1, чтобы отслеживать пути в графе.
parent[source] = source- Устанавливает источник как своего собственного родителя.
queue<pair<int, int>> q- Очередь для выполнения поиска в ширину. В каждом элементе очереди хранится текущая вершина и минимальная пропускная способность пути до нее.
  ##### 2. Поиск увеличивающего пути:
  ```
while (!q.empty()) {
        int cur = q.front().first;
        int minCapacity = q.front().second;
        q.pop();

        for (int next = 0; next < n; ++next) {
            if (parent[next] == -1 && graph[cur][next] > 0) {
                parent[next] = cur;
                int updatedCapacity = min(minCapacity, graph[cur][next]);
                if (next == sink) {
                    return updatedCapacity;
                }
                q.push({next, updatedCapacity});
            }
        }
    }
```
Внутри цикла выполняется поиск в ширину по графу.
Проверяется каждая вершина, соединенная с текущей (cur), которая еще не была посещена (parent[next] == -1).
Если есть ребро (graph[cur][next] > 0), то обновляется массив parent, и если достигнут сток (next == sink), возвращается минимальная пропускная способность пути.
  ##### 3. Обновление графа:
  ```
int edmondsKarp(int source, int sink, int n) {
        int maxFlow = 0;
        int pathFlow;

        while ((pathFlow = bfs(source, sink, n)) > 0) {
            maxFlow += pathFlow;

            int cur = sink;
            while (cur != source) {
                int prev = parent[cur];
                graph[prev][cur] -= pathFlow;
                graph[cur][prev] += pathFlow;
                cur = prev;
            }
        }

        return maxFlow;
    }
```
  Функция edmondsKarp вызывает bfs для поиска увеличивающего пути.
Если увеличивающий путь найден (pathFlow > 0), обновляется максимальный поток.
Затем обновляется сам граф, уменьшая пропускные способности на пути и увеличивая обратные ребра.
Процесс повторяется до тех пор, пока не будет найден максимальный поток в графе.
## Примеры работы программы:

### 1
![Снимок экрана 2023-12-21 132826](https://github.com/iis-32170x/RPIIS/assets/144949092/c67810f4-cedb-45c4-aada-0d25395f7b0f)

### 2
![Снимок экрана 2023-12-27 235756](https://github.com/iis-32170x/RPIIS/assets/144949092/15d8737d-6f0d-46ce-af39-218211e461e9)

### 3
![Снимок экрана 2023-12-27 235955](https://github.com/iis-32170x/RPIIS/assets/144949092/3894bc01-17a2-4766-baa0-b903bbb2f287)

  ## Заключение:
  Алгоритм Эдмондса-Карпа повторяет поиск увеличивающего пути и обновление графа до тех пор, пока не удастся найти больше увеличивающих путей.
  В конце работы алгоритма возвращается значение максимального потока, которое также представляет собой максимальный простой разрез в графе
