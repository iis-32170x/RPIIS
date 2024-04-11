# Расчётная работа

### Цель

Изучить основы теории графов

### Задание

Реализовать код на выбранном языке программирования, который находит радиус взвешанного ориентированного графа используя список смежности

### Ключевые понятия

`Граф` — математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

` Взвешенно-ориентированный (взвешенно-направленый)` - это граф, имеющий помимо вершин, рёбер и весов ещё и направление ребра.

`Cписок смежности` - это набор неупорядоченных списков, используемых для представления конечного графа.

`Радиус графа` - минимальный эксцентриситет среди всех вершин графа. 

`Эксцентриситет вершины графа` – расстояние до максимально удаленной от нее вершины.


# Алгооитм решения

* Используя алгоритм Дейктсры создётся приоритетная очередь для обработки вершин в порядке возрастания расстояния.
* Для каждой вершины обновляются расстояния до её соседних вершин.
* Выбирается минимальное из максимальных расстояний от начальной вершины до всех остальных, игнорируя расстояния, равные 0.

## Решение на с++
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

typedef pair<int, int> Edge;  // Пара (вершина, вес)

int findRadius(const unordered_map<int, vector<pair<int, int>>>& graph, int start) {
    unordered_map<int, int> distances;
    for (const auto& entry : graph) {
        distances[entry.first] = numeric_limits<int>::max();
    }

    distances[start] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        for (const auto& neighbor : graph.at(currentVertex)) {
            int neighborVertex = neighbor.first;
            int weight = neighbor.second;
            int distance = currentDistance + weight;

            if (distance < distances[neighborVertex]) {
                distances[neighborVertex] = distance;
                pq.push({distance, neighborVertex});
            }
        }
    }

    int radius = numeric_limits<int>::max();
    for (const auto& entry : distances) {
        if (entry.second > 0) {
            radius = min(radius, entry.second);
        }
    }

    return radius;
}

int main() {
    unordered_map<int, vector<pair<int, int>>> graph0 = {
        {1, {{2, 3}, {3,5}}},
        {2, {{3, 4}}},
        {3, {}},
    };

    unordered_map<int, vector<pair<int, int>>> graph1 = {
        {1, {{2, 1}, {3,4}}},
        {2, {{4, 2}}},
        {3, {{4,5}}},
        {4, {}},
    };
    unordered_map<int, vector<pair<int, int>>> graph2 = {
        {1, {{2, 2}}},
        {2, {{3, 3}}},
        {3, {{5, 2}, {4, 1}}},
        {4, {{5, 4}}},
        {5, {}}
    };
    
    unordered_map<int, vector<pair<int, int>>> graph3 = {
        {1, {{2, 3}}},
        {2, {{3, 4}}},
        {3, {}},
    };
    unordered_map<int, vector<pair<int, int>>> graph4 = {
        {1, {{2, 2}}},
        {2, {{3, 3}, {4,4}}},
        {4, {{5,6}}},
        {5, {}}
    };
    
    int startVertex = 1;
    
    cout << "Первый граф:" << endl;
    cout << "A - (3) - B" << endl;
    cout << "\\         /" << endl;
    cout << " (5)    (4)" << endl;
    cout << "  \\     /" << endl;
    cout << "     C" << endl;
    
    int result = findRadius(graph0, startVertex);

    cout << "Его радиус равен " << result << endl;
    
    cout << "___________________________________" << endl;
    
    cout << "Второй граф:" << endl;
    cout << " A - (4) - B" << endl;
    cout << " |         |" << endl;
    cout << "(1)       (5)" << endl;
    cout << " |         |" << endl;
    cout << " C - (2) - D" << endl;
    
    result = findRadius(graph1, startVertex);

    cout << "Его радиус равен " << result << endl;
    
    cout << "___________________________________" << endl;
    
    cout << "Тритий граф: " << endl;
    cout << "A - (2) - B - (3) - C - (2) - D" << endl;
    cout << "                     \\       /" << endl;
    cout << "                      (2)   (4)" << endl;
    cout << "                        \\  /" << endl;
    cout << "                          E" << endl;

    result = findRadius(graph2, startVertex);

    cout << "Его радиус равен " << result << endl;
    
    cout << "___________________________________" << endl;
    
    cout << "Четвёртый граф:" << endl;
    cout << "A - (3) - B - (4) - C" << endl;
    
    result = findRadius(graph3, startVertex);

    cout << "Его радиус равен " << result << endl;
    
    cout << "___________________________________" << endl;
    
    cout << "Пятый граф:" << endl;
    cout << "A - (2) - B - (4) - C - (6) - D" << endl;
    cout << "           \\" << endl;
    cout << "             (3)" << endl;
    cout << "               \\" << endl;
    cout << "                 E" << endl;
    
    result = findRadius(graph4, startVertex);

    cout << "Его радиус равен " << result << endl;
    
    cout << "___________________________________" << endl;
    
    return 0;
}
```

### Вывод

В результате выполнения данной работы были получены следующие практические навыки:

- изучены основы теории графов

- изучены способы представления графов

- изучены базовые алгоритмы для работы с графами

- ## Список литературы
[1] Оре О. Теория графов. – 2-е изд.. – М.: Наука, 1980. – С. 336.

[2] Кормен Т. Х. и др. Часть VI. Алгоритмы для работы с графами // Алгоритмы: построение
и анализ = Introduction to Algorithms. – 2-е изд.. – М.: Вильямс, 2006. – С. 1296.

[3] Харари, Ф. Теория графов / Ф. Харари / Пер. с англ. и предисл. В.П. Козырева. Под ред.
Г.П. Гаврилова. Изд. 2-е. – М.: Едиториал УРСС, 2003. – 269 с.

[4] Нечипуренко, М. И. Алгоритмы и программы решения задач на графах и сетях / М.И.
Нечипуренко, В.К. Попков, С.М. Майнагашев и др. – Новосибирск: Наука. Сиб. отд-ние,
1990. – 515 с.

[5] Емеличев В. А., Мельников О. И., Сарванов В. И., Тышкевич Р. И. Лекции по теории
графов. М.: Наука, 1990. 384с. (Изд.2, испр. М.: УРСС, 2009. 392 с.)

[6] Касьянов, В. Н. Графы в программировании: обработка, визуализация и применение / В.
Н. Касьянов, В. А. Евстигнеева. – СПб. : БХВ-Петербург, 2003.

[7] База знаний по теории графов OSTIS GT [Электронный ресурс] / проект OSTIS, 2012. –
Режим доступа: http://ostisgraphstheo.sourceforge.net. — Дата доступа : 11.09.2012.
