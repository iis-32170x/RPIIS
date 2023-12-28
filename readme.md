# Расчетная работа, отчет

 - `Тема` расчётной работы - Графы.
 - `Задача` заключается в разработке алгоритма, который выполняет поставленную задачу, согласно варианту, который необходимо выполнить. 
- `Вариант`  6.1(ми)
### Список понятий, определений:
-  $\{\textit{Граф}}$ - это совокупность непустого множества вершин и множества пар вершин
- `Неориентированный граф` -  это граф, рёбра которого не имеют направления и могут быть проходимыми в обоих направлениях.
- `Матрица ин графа` — одна из форм представления графа, в которой указываются связи между инцидентными элементами графа (ребро(дуга) и вершина). Столбцы матрицы соответствуют ребрам, строки — вершинам. Ненулевое значение в ячейке матрицы указывает связь между вершиной и ребром (их инцидентность).*


### Преобразовать граф, предстравленный в виде матрицы инцидентности, в дерево. “минимальное вершинное связное разрезание” или “вершинное связное разрезание”
1. Инициализация: создать пустое множество вершин, которые должны быть удалены, и список смежных вершин для каждой вершины графа.
2. Найти любую вершину с одной смежной вершиной и добавить ее в множество удаляемых вершин.
3. Для всех оставшихся вершин, выполнить следующие шаги:
   a) Найти количество смежных вершин (степень вершины).
   b)  Если степень вершины равна 2, добавить эту вершину в множество удаляемых вершин
   c) Если степень больше 2, то добавить смежные вершины в список смежных вершин этой вершины.
4. Пока в графе есть вершины с более чем одной смежной вершиной:
   a) Выбрать вершину с максимальным количеством смежных вершин и добавить их в множество удаляемых вершин.
   b) Удалить выбранную вершину и ее смежные ребра из графа.
5. Вернуться к шагу 3, пока в графе не останется только одна компонента связности.
6. Вернуться к шагу 3, пока в графе не останется только одна компонента связности.
## Алгоритм на C++
```
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Функция для удаления вершины из матрицы инцидентности
vector<vector<int>> removeVertex(vector<vector<int>>& matrix, int vertex) {
    int numVertices = matrix.size();
    vector<vector<int>> newMatrix(numVertices - 1, vector<int>(numVertices - 1, 0));

    int row = 0;
    for (int i = 0; i < numVertices; i++) {
        if (i == vertex)
            continue;

        int col = 0;
        for (int j = 0; j < numVertices; j++) {
            if (j == vertex)
                continue;

            newMatrix[row][col] = matrix[i][j];
            col++;
        }
        row++;
    }

    return newMatrix;
}

// Функция для проверки, является ли граф деревом
bool isTree(vector<vector<int>>& matrix) {
    int numVertices = matrix.size();
    int numEdges = matrix[0].size();
    vector<int> degrees(numVertices, 0);

    for (int j = 0; j < numEdges; j++) {
        int count = 0;
        int vertexA = -1, vertexB = -1;
        for (int i = 0; i < numVertices; i++) {
            if (matrix[i][j] == 1) {
                count++;
                if (vertexA == -1)
                    vertexA = i;
                else
                    vertexB = i;
            }
        }

        if (count == 2) {
            degrees[vertexA]++;
            degrees[vertexB]++;
        } else {
            return false;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (degrees[i] == 0)
            return false;
        if (degrees[i] > 2)
            return false;
    }

    return true;
}

// Функция для поиска минимального множества вершин для преобразования графа в дерево
set<int> findMinimumVertexSet(vector<vector<int>>& matrix) {
    int numVertices = matrix.size();
    set<int> vertexSet;

    while (!isTree(matrix)) {
        bool removed = false;

        for (int i = 0; i < numVertices; i++) {
            vector<vector<int>> newMatrix = removeVertex(matrix, i);

            if (isTree(newMatrix)) {
                matrix = newMatrix;
                vertexSet.insert(i);
                removed = true;
                break;
            }
        }

        if (!removed)
            break;
    }

    return vertexSet;
}

int main() {
    int numVertices, numEdges;
    cout << "Введите количество вершин и ребер графа: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> matrix(numVertices, vector<int>(numEdges, 0));
    cout << "Введите матрицу инцидентности графа (0 - нет связи, 1 - есть связь):\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numEdges; j++) {
            cin >> matrix[i][j];
        }
    }

    set<int> vertexSet = findMinimumVertexSet(matrix);

    cout << "Минимальное множество вершин для преобразования графа в дерево: ";
    for (int vertex : vertexSet) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

```
## Разбор кода

### Функция *`функция removeVertex`* 
** Эта функция создает новую матрицу, исключая заданную вершину и связанные с ней ребра. В результате получается матрица, в которой одна вершина и одно ребро исключены.`.**

 ```C++
vector<vector<int>> removeVertex(vector<vector<int>>& matrix, int vertex) {
    int numVertices = matrix.size();
    vector<vector<int>> newMatrix(numVertices - 1, vector<int>(numVertices - 1, 0));

    int row = 0;
    for (int i = 0; i < numVertices; i++) {
        if (i == vertex)
            continue;

        int col = 0;
        for (int j = 0; j < numVertices; j++) {
            if (j == vertex)
                continue;

            newMatrix[row][col] = matrix[i][j];
            col++;
        }
        row++;
    }
 ```
 ### Функция *`isTree`*
 ** Эта функция выполняет следующие проверки:
Для каждого ребра в матрице инцидентности подсчитывается количество смежных вершин. Если количество равно 2, то добавляем 1 к степеням соответствующих вершин. Если количество не равно 2, то граф не является деревом.
Затем мы проверяем каждую вершину графа. Если степень вершины равна 0, то граф не является связным. Если степень вершины больше 2, то граф не является деревом.**
 ``` c++
bool isTree(vector<vector<int>>& matrix) {
    int numVertices = matrix.size();
    int numEdges = matrix[0].size();
    vector<int> degrees(numVertices, 0);

    for (int j = 0; j < numEdges; j++) {
        int count = 0;
        int vertexA = -1, vertexB = -1;
        for (int i = 0; i < numVertices; i++) {
            if (matrix[i][j] == 1) {
                count++;
                if (vertexA == -1)
                    vertexA = i;
                else
                    vertexB = i;
            }
        }

        if (count == 2) {
            degrees[vertexA]++;
            degrees[vertexB]++;
        } else {
            return false;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (degrees[i] == 0)
            return false;
        if (degrees[i] > 2)
            return false;
    }

    return true;
}
}
 ```


 ### Функция *`findMinimumVertexSet`*
 ** Эта функция находит минимальное множество вершин для преобразования графа в дерево:
 Эта функция выполняет следующие действия:
В цикле она проверяет, является ли текущая матрица инцидентности деревом с помощью функции isTree. Если да, то она просто возвращает пустое множество вершин, так как граф уже является деревом.
Если текущая матрица не является деревом, то она пытается удалить каждую вершину по очереди и проверяет, станет ли граф деревом после удаления вершины. Если да, то она обновляет матрицу инцидентности, добавляет удаленную вершину в множество и продолжает процесс, пока граф не станет деревом или не останется возможности удалить вершины.**
 ``` c++

set<int> findMinimumVertexSet(vector<vector<int>>& matrix) {
    int numVertices = matrix.size();
    set<int> vertexSet;

    while (!isTree(matrix)) {
        bool removed = false;

        for (int i = 0; i < numVertices; i++) {
            vector<vector<int>> newMatrix = removeVertex(matrix, i);

            if (isTree(newMatrix)) {
                matrix = newMatrix;
                vertexSet.insert(i);
                removed = true;
                break;
            }
        }

        if (!removed)
            break;
    }

    return vertexSet;
}
```
## Вывод

В результате выполнения данной работы были получены следующие практические навыки:
- изучены основы теории графов
- изучены базовые алгоритмы для работы с графами
