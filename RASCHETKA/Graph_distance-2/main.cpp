#include <iostream>
#include "GraphRidiculousness.h"

using namespace std;

int main() {
    // Пример использования
    GraphRidiculousness g(5);

    // Добавляем вершины
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    // Основная часть
    cout << "Minimum distances of graph: " << g.minimumDistancePeripheralNodes() << endl;
    cout << "Average distances of graph: " << g.averageDistancePeripheralNodes() << endl;

    return 0;
}
