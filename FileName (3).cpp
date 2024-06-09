#include "biblioteka.h"
#include <iostream>

// Вставьте здесь код библиотеки

int main() {
    setlocale(LC_ALL,"Ru");
    // Создание графа с 5 вершинами
    Graph* graph = createGraph(5);

    // Добавление дуг
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    cout << "Обход в ширину (начальная вершина 2): ";
    BFS(graph, 2);

    // Удаление дуги
    removeEdge(graph, 2, 0);
    cout << "\nОбход в ширину после удаления дуги (2, 0): ";
    BFS(graph, 2);

    return 0;
}
