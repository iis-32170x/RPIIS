#ifndef GRAPH_DISTANCE_GRAPHRIDICULOUSNESS_H
#define GRAPH_DISTANCE_GRAPHRIDICULOUSNESS_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class GraphRidiculousness {
public:
    vector<vector<int>> katusha;

    GraphRidiculousness(int V) {
        katusha.resize(V+1);
    }

    void addEdge(int node1, int node2) {
        katusha[node1].push_back(node2);
        katusha[node2].push_back(node1);
    }

    int minimumDistancePeripheralNodes() {
        vector<int> vectorOfMinDistances = distancesPeripheralNodes();

        return *min_element(vectorOfMinDistances.begin(), vectorOfMinDistances.end()); // Минимальное из всех дистанций
    }

    float averageDistancePeripheralNodes() {
        vector<int> vectorOfMinDistances = distancesPeripheralNodes();

        float summary = 0;

        for(const auto& it : vectorOfMinDistances) {
            summary += it;
        }

        return summary / (float)vectorOfMinDistances.size();
    }
private:
    vector<int> findPeripheralNodes() {
        vector<int> peripheralNodes;
        int extrecity = 0, deametor = 0;

        for(int i = 0;i < katusha.size();i++) {
            for(int j = 0;j < katusha.size();j++) {
                extrecity = max(BFS(i, j), extrecity);
            }
            deametor = max(extrecity, deametor);
            extrecity = 0;
        }

        //Значение диаметра получено

        for(int i = 0;i < katusha.size();i++) {
            for(int j = 0;j < katusha.size();j++) {
                extrecity = max(BFS(i, j), extrecity);
            }
            if(extrecity == deametor) {
                peripheralNodes.push_back(i);
            }
            extrecity = 0;
        }

        return peripheralNodes;
    }

    vector<int> distancesPeripheralNodes() {
        vector<int> peripheralNodes = findPeripheralNodes();
        vector<int> vectorOfDistance;

        for (int i = 0; i < peripheralNodes.size(); ++i) {
            for (int j = i + 1; j < peripheralNodes.size(); ++j) {
                vectorOfDistance.push_back(BFS(peripheralNodes[i], peripheralNodes[j]));
            }
        }

        return vectorOfDistance;
    }

    int BFS(int start, int end) {
        int n = katusha.size(); // Количество вершин в графе

        vector<bool> visited(n, false); // Массив для отслеживания посещенных вершин
        vector<int> distance(n, -1);    // Массив для хранения расстояний от стартовой вершины

        queue<int> q;
        q.push(start);
        visited[start] = true;
        distance[start] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : katusha[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    distance[neighbor] = distance[current] + 1;

                    // Если достигнута конечная вершина, возвращаем расстояние
                    if (neighbor == end) {
                        return distance[neighbor];
                    }
                }
            }
        }

        // Если конечная вершина не достигнута
        return -1;
    }

};

#endif //GRAPH_DISTANCE_GRAPHRIDICULOUSNESS_H
