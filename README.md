# Расчетная работа 

## Введение

### Цель
Изучить основы теории графов, способы представления графов, базовые алгоритмы для работы с графами, 
### Задание
1.1 (Дерево)
Реализовать на C++ код, который может определить, является ли граф деревом.

Граф представляется в виде списка смежности(списка инцидентности).

### Ключевые понятия
`Граф` - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

`Дерево` — это связный ациклический граф. Связность означает наличие маршрута между любой парой вершин, ацикличность — отсутствие циклов.

`Неориентированный граф ` —  это математическая структура, состоящая из вершин и ребер, где ребра не имеют направления или ориентации, а вершины связываются попарно ребрами, обозначая отношения или связи между ними.

`Список смежности (инцидентности)` - один из способов представления графа в виде коллекции списков вершин. Каждой вершине графа соответствует список, состоящий из «соседей» этой вершины.

`Обхват графа` — длина наименьшего цикла, содержащегося в данном графе. Если граф не содержит циклов (то есть является ациклическим графом), его обхват по определению равен бесконечности.

`Обход в ширину (breadth-first search, BFS) ` - систематически обходит все вершины графа

`Ациклический неориентированный граф’ - это граф, в котором не существует циклов, то есть путь, который начинается и заканчивается в одной и той же вершине, при этом проходя по другим вершинам по пути.

`Связный граф` - это граф, в котором существует путь между любыми двумя вершинами.

`Родитель вершины` - это та вершина, из которой мы попали в другую при обходе графа.

`Сосед` - обычно используется для описания вершин, которые имеют общее ребро с данной вершиной.

Графический пример обхода в ширину:

![image](https://github.com/iis-32170x/RPIIS/assets/146937077/2e436a9f-4f4b-41ba-9770-ef0feec7a2f8)

Графический пример графа-дерева: 

![image](https://github.com/iis-32170x/RPIIS/assets/146937077/4eb416bb-8873-40a0-936e-b36159e80e74)


## Алгоритм решения

Алгоритм определяет, является ли граф деревом.
1.	Представляем граф в виде списка смежности (инцидентности), для его проверки.

2.	Проверяем, что граф содержит ровно n-1 ребро, где n - количество вершин в графе. Если это условие не выполняется, то граф не может быть деревом, так как дерево с n вершинами имеет ровно n-1 ребро.

3.	Проверяем, что граф не содержит циклов. Для этого можно используем обход графа в ширину (BFS). Начнём обход с вершины 0 и следуем рёбрам графа. Если мы встречаем вершину, которую уже посетили ранее, то граф содержит цикл и не является деревом.

4.	Смотрим, чтоб граф был связный. Это означает, что существует путь между любыми двумя вершинами графа. Используем алгоритм обхода графа (BFS), чтобы проверить связность графа. Если в результате обхода не удалось посетить все вершины, то граф не является связным и не может быть деревом.

5.	Если граф успешно проходит все эти проверки, то он является деревом. Если хотя бы одно из условий не выполняется, то граф не является деревом.
Этот алгоритм работает для неориентированных графов.

Приведём пример работы алгоритма:

Исходный граф:

![image](https://github.com/iis-32170x/RPIIS/assets/146937077/c13a4a70-b250-44f9-8898-84b5ca920332)

 
Теперь представим этот граф в виде списка смежности:

> - `0 -- 1`
> - `2 -- 0`
> - `0 -- 3`
> - `0 -- 4`
> - `5 -- 4`

1. Начинаем с вершины 0:

- Добавляем вершину 0 в дерево.

- Извлекаем вершину 0 из очереди и помечаем ее как посещенную.

- Исследуем всех соседей текущей вершины (вершины 1, 2, 3, 4).

2. Переходим к вершине 1:
   
- Проверяем, была ли вершина уже посещена (нет).

- Помечаем вершину как посещенную.

- Добавляем вершину в очередь.

- Записываем текущую вершину 0 в качестве родителя для вершины 1.

3. Переходим к вершине 2:
   
- Проверяем, была ли вершина уже посещена (нет).

- Помечаем вершину как посещенную.

- Записываем текущую вершину 0 в качестве родителя для вершины 2.

4. Переходим к вершине 3:

- Проверяем, была ли вершина уже посещена (нет).

- Помечаем вершину как посещенную.

- Добавляем вершину в очередь.

- Записываем текущую вершину 0 в качестве родителя для вершины 3.

5. Переходим к вершине 4:

- Проверяем, была ли вершина уже посещена (нет).

- Добавляем вершину в очередь.

- Помечаем вершину как посещенную.

- Записываем текущую вершину 0 в качестве родителя для вершины 4.

- Проверяем вершину на наличие соседей (обнаруживаем вершину 5).
  
- Добавляем её в очередь для дальнейшего обхода.

6. Перебираем всех соседей добавленных в очередь вершин (1, 2, 3, 4):

- Вершина 1 не имеет соседей, удаляем из очереди и переходим к следующей.

- Вершина 2 не имеет соседей, удаляем из очереди и переходим к следующей.

- Вершина 3 не имеет соседей, удаляем из очереди и переходим к следующей.

- Находим и исследуем всех соседей вершины 4 (вершина 5).

7. Переходим к вершине 5:

- Проверяем, была ли вершина уже посещена(нет).

- Добавляем вершину в очередь.

- Помечаем вершину как посещенную.
  
- Записываем текущую вершину 4 в качестве родителя для вершины 5.

- Проверяем, является ли вершина 4 родителем вершины 5 (да).

- Проверяем вершину на наличие соседей (нет).

8. Перебираем соседей добавленной в очередь вершины 5:

- Вершина 5 не имеет соседей, удаляем из очереди.

7. После обхода проверяем, что все вершины были посещены и что все проверки графа-дерева были совершены.

Таким образом, после обхода мы выяснили, что граф не имеет циклов и что все вершины связные. Следовательно, граф является деревом.

## Реализация на C++

Код, выполняющий наш алгоритм:

``` c++
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

bool isTree(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = true;

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = curr;
            }
            else if (parent[curr] != neighbor) {
                return false;
            }
        }
    }

    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    int m; 
    inputFile >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isTree(graph)) {
        outputFile << "Граф является деревом.";
    }
    else {
        outputFile << "Граф не является деревом.";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

```

## Разбор кода:

#include <iostream>: Подключение заголовочного файла iostream, который содержит определение стандартных потоков ввода/вывода (например, cout и cin).

#include <fstream>: Подключение заголовочного файла fstream, который содержит определение классов для работы с файлами.

#include <vector>: Подключение заголовочного файла vector, который содержит определение класса std::vector для работы с динамическими массивами.

#include <queue>: Подключение заголовочного файла queue, который содержит определение класса std::queue для работы с очередями.

using namespace std; Использование пространства имен std для упрощения использования стандартных библиотечных функций и классов.

bool isTree(vector<vector<int>>& graph):  Объявление функции isTree, которая принимает на вход ссылку на двумерный вектор graph, представляющий граф, и возвращает логическое значение true, если граф является деревом, и false в противном случае.

int n = graph.size(): Получение количества вершин в графе путем вызова функции size() для вектора graph.

vector<bool> visited(n, false): Создание вектора visited размером n, заполненного значениями false. Вектор будет использоваться для отслеживания посещенных вершин в процессе обхода графа.

vector<int> parent(n, -1): Создание вектора parent размером n, заполненного значениями -1. Вектор будет использоваться для хранения информации о родителях вершин в процессе обхода графа.

queue<int> q: Создание пустой очереди q для обхода графа в ширину.

q.push(0): Добавление вершины 0 в очередь q. Обход графа начинается с этой вершины.

while (!q.empty()):  Начало цикла, который будет выполняться, пока очередь q не станет пустой. Внутри цикла происходит обход графа в ширину.

int curr = q.front(): Извлечение первого элемента из очереди q и сохранение его в переменной curr.

q.pop(): Удаление первого элемента из очереди q.

visited[curr] = true: Пометка текущей вершины curr как посещенной путем установки соответствующего элемента вектора visited в значение true.

for (int neighbor : graph[curr]): Начало цикла, который перебирает всех соседей текущей вершины curr.

if (!visited[neighbor]): Проверка, был ли сосед уже посещен. Если сосед не был посещен, то выполняется следующий блок кода.

visited[neighbor] = true: Пометка соседа как посещенного.

q.push(neighbor): Добавление соседа в очередь q для дальнейшего обхода.

parent[neighbor] = curr: Запись текущей вершины curr в качестве родителя для соседа.

else if (parent[curr] != neighbor) {: Проверка, является ли сосед родителям текущей вершины curr. Если сосед уже был посещен и не является родителем текущей вершины, то это означает наличие цикла в графе, и функция возвращает значение false.

for (bool v : visited): Начало цикла, который проверяет, что все вершины были посещены.

if (!v): Если найдена непосещенная вершина, выполняется следующий блок кода.

return false: Функция возвращает значение false, так как не все вершины были посещены.

return true: Если все вершины были посещены и не было обнаружено циклов, то функция возвращает значение true, указывая на то, что граф является деревом.

int main(): Определение функции main, которая является точкой входа в программу.

ifstream inputFile("input.txt"): Создание объекта inputFile класса ifstream для чтения данных из файла "input.txt".

ofstream outputFile("output.txt"): Создание объекта outputFile класса ofstream для записи данных в файл "output.txt".

inputFile >> n >> m: Считывание количества вершин и ребер графа из файла.

vector<vector<int>> graph(n): Создание двумерного вектора graph размером n, представляющего граф.

for (int i = 0; i < m; i++): Начало цикла, который считывает ребра графа из файла.

int u, v: Объявление переменных u и v для хранения вершин, соединенных ребром.

inputFile >> u >> v: Считывание вершин u и v из файла.

graph[u].push_back(v): Добавление вершины v в список смежности вершины u.

graph[v].push_back(u): Добавление вершины u в список смежности вершины v.

if (isTree(graph)): Проверка, является ли граф деревом с помощью вызова функции isTree.

outputFile << "Граф является деревом.": Запись сообщения "Граф является деревом." в выходной файл.

outputFile.close(): Закрытие выходного файла.

return 0: Возврат нулевого значения, указывающего на успешное завершение программы.

Код считывает граф из файла, выполняет обход графа в ширину и проверяет, является ли граф деревом или нет. Результат проверки записывается в выходной файл.

## Тестирование
Все тесты производились только через консоль. Скриншоты работы тестов вы можете посмотреть [здесь](https://github.com/iis-32170x/RPIIS/tree/%D0%93%D0%BE%D1%80%D1%8F%D1%87%D0%B5%D0%B2_%D0%98/%D0%A0%D0%A0/tests)

## Вывод
 
В результате выполнения расчётной работы я:
- изучил основы теории графов
- изучил способы представления графов
- изучил базовые алгоритмы для работы с графами
- изучил базовые алгоритмы работы с векторами, очерядими и файлами в C++

## Список литературы
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
