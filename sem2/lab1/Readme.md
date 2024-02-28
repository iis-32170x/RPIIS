# <p align="center">Лабораторная работа №1</p>

Вариант 26. Неориентированный граф. Вставка вершины. Удаление вершины.
Вставка дуги. Удаление дуги. Построение дерева обхода в глубину.

## <p align="center">Цели лабораторной работы:</p>
1. Разработать библиотеку для работы с неориентированным графом на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.
   
## <p align="center">Список используемых понятий и алгоритмов:</p>
1. **Библиотека программного обеспечения (Библиотека кода):**
В программировании библиотека представляет собой совокупность программного кода, предназначенного для решения определенных задач. Этот код может содержать функции, классы, процедуры или другие компоненты, которые разработчики могут повторно использовать в своих программных проектах. Библиотеки упрощают разработку, так как они предоставляют готовые решения для типовых задач.

2. **Граф** – совокупность двух множеств — множества самих объектов и множества их парных связей.

3. **Нериентированный граф**  — граф, рёбрам которого не присвоено направление.

4. **Ребро графа** — это то, что соединяет две вершины.

5. **Список смежности** — один из способов представления графа в виде коллекции списков вершин. Каждой вершине графа соответствует список, состоящий из «соседей» этой вершины.

6. **Поиск в глубину (Deep First Search, DFS)** — алгоритм обхода графа, который движется от начальной вершины как можно дальше сначала по первому ребру, потом по второму, и так далее.

## <p align="center">Описание используемых алгоритмов:</p>
Для представления графа используется *список смежности* для более удобной работы. Реализация списка основана на библиотеках map и set на С++.

```cpp
map<int, std::set<int>> graph;
```
где `int` - вершина, а в `set<int>` записаны все соседи вершины.

1. **Вставка вершины :** добавление в список новую вершину, если таковой не имелось.

```cpp
void Ngraph::AddVertex(int a) {
    if ((graph.find(a) == graph.end())&&a>0) {
        graph[a] = std::set<int>();
    }
}
```

2. **Вставка ребра:** добавление ребра в списки смежностей обеих вершин, если вершины существуют в графе. Ошибка если вершины не существует.

```cpp
void Ngraph::AddEdge(int a, int b) {
    if (!VertexExists(a) || !VertexExists(b)) {
        throw std::invalid_argument("This vertex(es) is not exist");
    }
    graph[a].insert(b);
    graph[b].insert(a);
}
```
   
3. **Удаление вершины:** удаление вершины из списка, а так же всех связанных рёбер.

```cpp
void Ngraph::DeleteVertex(int a)
{
    graph.erase(a);
    
    for (auto& kv : graph) {
        kv.second.erase(a);
    }
}
```

4. **Удаление ребра:** удаление ребра, если таковое имелось.

```cpp
void Ngraph::DeleteEdge(int a, int b)
{
    if (graph.find(a) == graph.end() || graph.find(b) == graph.end() || graph[a].find(b) == graph[a].end()) {
        return;

    }
        graph[a].erase(b);
        graph[b].erase(a);
}
 ```
5. **Дерево обхода в ширину:**

5.1 *Вспомогательная функция DFS* - сама функция обхода в ширину.

```cpp
   void Ngraph::DFS(int a, std::map<int, bool>& visited)
{
    visited[a] = true; 
    std::cout << a << " ";
    for (int neighbor : graph[a]) {
        if (!visited[neighbor]) {
           DFS(neighbor, visited); 
        }
    }
    for (const auto& kv : graph) {
        if (!visited[kv.first]) {
            DFS(kv.first, visited);
        }
    }
}
 ```

Создание контейнера для записи посещенных вершин - `std::map<int, bool>& visited`. Отмечаем первую вершину и после рекурсивно вызываем функцию для соседа. Предусмотрено условие для несвязного графа - если есть хоть одна непосещённая вершина, то DFS запускается из не снова.

5.2 *Функция DFSTree* - Вывод дерева пользователю.

```cpp
void Ngraph::DFSTree(int first)
{
    std::map<int, bool> visited;
    DFS(first, visited);
    std::cout << std::endl;
}
 ```


## <p align="center">Результаты тестирования:</p>
Тестирование проводилось с помощью фреймворка Google test. Система тестов состоит из 6 тестов: 5 тестов на работу всех функций и 1 на ожидаемую ошибку. Все тесты прошли успешно.

<p align="center">
   
  ![tests](https://github.com/iis-32170x/RPIIS/assets/147048129/c8080879-0aba-4a4e-8886-221105d3fdf4)

</p>

**Система тестов:**

```cpp
#include <gtest/gtest.h>
#include "pch.h"
#include "../Undirected graph/undirectedGraph.h"

TEST(NgraphTest, AddVertex) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    EXPECT_TRUE(graph.VertexExists(1));
    EXPECT_TRUE(graph.VertexExists(2));
    EXPECT_TRUE(graph.VertexExists(3));
    EXPECT_FALSE(graph.VertexExists(0));
}

TEST(NgraphTest, AddEdge) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    EXPECT_TRUE(graph.EdgeExists(1, 2));
    EXPECT_TRUE(graph.EdgeExists(2, 1));
    EXPECT_TRUE(graph.EdgeExists(2, 3));
    EXPECT_FALSE(graph.EdgeExists(1, 3));
}

TEST(NgraphTest, DeleteVertex) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    graph.DeleteVertex(2);

    EXPECT_FALSE(graph.VertexExists(2));
    EXPECT_FALSE(graph.EdgeExists(1, 2));
    EXPECT_FALSE(graph.EdgeExists(2, 3));
}

TEST(NgraphTest, DeleteEdge) {
    Ngraph graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);

    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    graph.DeleteEdge(1, 2);

    EXPECT_FALSE(graph.EdgeExists(1, 2));
    EXPECT_FALSE(graph.EdgeExists(2, 1));
    EXPECT_TRUE(graph.EdgeExists(2, 3));
}

TEST(NgraphTest, DFSTreeTest) {
    Ngraph graph;

    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    testing::internal::CaptureStdout();
    graph.DFSTree(1);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "1 2 3 \n");
}
```
## <p align="center">Вывод:</p>

В результате выполнения лабораторной работы были упорядочены знания по теории графов, в частности по работе с неориентированными графами и поиску в глубину. Улучшены навыки работы со стандартными библиотеками С++, а так же получен опыт в создании собственной статической библиотеки, что явно пригодится в будущем при более масштабных работах.

Освоена работа с тестовыми фреймворками для проверки правильности работы программы, в данном случае библиотеки.

## <p align="center">Используемые источники:</p>
1. Алгоритмы: построение и анализ, 2-е издание. : Пер. с англ. – М. :
Издательский дом «Вильямс», 2005. – 1296 с.
2. Лекции М. Густокашина по олимпиадному программированию
3. Олимпиадное программирование в Бресте и Беларуси: [Электронный ресурс]. URL: https://brestprog.by/.
