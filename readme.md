# Расчетная работа, отчет

 - `Тема` расчётной работы - Графы.
 - `Задача` заключается в разработке алгоритма, который выполняет поставленную задачу, согласно варианту, который необходимо выполнить. 
- `Вариант`  6.1(ми)
### Список понятий, определений:
-  $\{\textit{Граф}}$ - это совокупность непустого множества вершин и множества пар вершин
- `Неориентированный граф` -  это граф, рёбра которого не имеют направления и могут быть проходимыми в обоих направлениях.
- `Матрица смежности графа` — одна из форм представления графа, в которой указываются связи между инцидентными элементами графа (ребро(дуга) и вершина). Столбцы матрицы соответствуют ребрам, строки — вершинам. Ненулевое значение в ячейке матрицы указывает связь между вершиной и ребром (их инцидентность).*

## Алгоритм на C++
```
#include <iostream>
#include <vector>

using namespace std;

void findPath(vector<vector<int>>& graph, int path, int start, int length,vector<int>&pytb, int startV) {
    if (path == length) {
        cout << startV<<' ';
        for (auto x : pytb)
            cout << pytb[x] << ' ';
        exit(1);
    }

    else if (path < length) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[start][i] != 0  && (path + graph[start][i])<=length){
                pytb.push_back(i);
                path += graph[start][i];
                findPath(graph, path,i , length, pytb,startV);
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int numVertices;
    cout << "Введите количество вершин: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Введите матрицу смежности (0 - отсутствие ребра, вес - вес ребра):" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    int startVertex, desiredLength;
    cout << "Введите начальную вершину: ";
    cin >> startVertex;
    cout << "Введите длину пути: ";
    cin >> desiredLength;

    int path = 0;
    vector <int> pytb;
    findPath(graph, path, startVertex, desiredLength,pytb,startVertex);

    return 0;
}
```
## Разбор кода

### Функция *`findPath`* 
**В функции мы проверяем равен ли пройденный путь заданному, если нет, то перебираем соседние вершины и проверяем вес ребер с соседними вершинами (чтобы сумма не была больше требуемого значения), когда подходящее ребро найденно, мы добваляем в конец вектора `pytb`, который хранит наш путь по вершинам, выбранную вершину, а переменную. `path` увеличиваем на вес ребра, в конце вызываем нашу функцию.Если пройденный путь равен заданному, то выводим все вершины записанные в `pytb`.**

 ```C++
 void findPath(vector<vector<int>>& graph, int path, int start, int length,vector<int>&pytb, int startV) {
    if (path == length) {
        cout << startV<<' ';
        for (auto x : pytb)
            cout << pytb[x] << ' ';
        exit(1);
    }

    else if (path < length) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[start][i] != 0  && (path + graph[start][i])<=length){
                pytb.push_back(i);
                path += graph[start][i];
                findPath(graph, path,i , length, pytb,startV);
            }
        }
    }
};
 ```
 ### Функция *`main`*
 **Функция получает размер матрицы и саму матрицу смежности, запрашивает начальную вершину и искомую длину пути.Далее вызывает функцию `findPath` передавая туда введенные пользователем данные.**
 ``` c++
 int main() {
    setlocale(LC_ALL, "ru");
    int numVertices;
    cout << "Введите количество вершин: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Введите матрицу смежности (0 - отсутствие ребра, вес - вес ребра):" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    int startVertex, desiredLength;
    cout << "Введите начальную вершину: ";
    cin >> startVertex;
    cout << "Введите длину пути: ";
    cin >> desiredLength;

    int path = 0;
    vector <int> pytb;
    findPath(graph, path, startVertex, desiredLength,pytb,startVertex);

    return 0;
}
 ```
## Вывод

В результате выполнения данной работы были получены следующие практические навыки:
- изучены основы теории графов
- изучены базовые алгоритмы для работы с графами
