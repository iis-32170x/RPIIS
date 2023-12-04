#ifndef GRAPH_DISTANCE_GRAPHNODE_H
#define GRAPH_DISTANCE_GRAPHNODE_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class GraphNode {
protected:
    class Node {
    public:
        int data;
        int extrencity;
        vector<Node*> neighbors;

        Node(int value) : data(value) {}
    };

public:
    vector<Node*> nodes;

    // Добавление вершины в граф
    void addNode(int value) {
        Node* newNode = new Node(value);
        nodes.push_back(newNode);
    }

    // Добавление ребра между вершинами
    void addEdge(Node* node1, Node* node2) {
        node1->neighbors.push_back(node2);
        node2->neighbors.push_back(node1);
    }

    int minimumDistancePeripheralNodes() {
        vector<int> vectorOfMinDistances = distancesPeripheralNodes();

        return *min_element(vectorOfMinDistances.begin(), vectorOfMinDistances.end()); // Минимальное из всех дистанций
    }

    // Нахождение среднего расстояния между периферийными вершинами
    float averageDistancePeripheralNodes() {
        vector<int> vectorOfMinDistances = distancesPeripheralNodes();

        float summary = 0;

        for(const auto& it : vectorOfMinDistances) {
            summary += it;
        }

        return summary / (float)vectorOfMinDistances.size();
    }
private:
    // Поиск периферийных вершин
    vector<Node*> findPeripheralNodes() {
        vector<Node*> peripheralNodes;
        int exentrcity, deametor;

        for(int i = 0;i < nodes.size();i++) {
            exentrcity = BFS(nodes[i], nodes[0]);
            for(int j = 1;j < nodes.size();j++) {
                exentrcity = max(BFS(nodes[i], nodes[j]), exentrcity);
            }
            nodes[i]->extrencity = exentrcity;
            deametor = max(exentrcity, deametor);
        }

        for(int i = 0;i < nodes.size();i++) {
            if(nodes[i]->extrencity == deametor) {
                peripheralNodes.push_back(nodes[i]);
            }
        }

        return peripheralNodes;
    }

    // Нахождение расстояний между периферийными вершинами
    vector<int> distancesPeripheralNodes() {
        vector<Node*> peripheralNodes = findPeripheralNodes();
        vector<int> vectorOfDistance;

        for (int i = 0; i < peripheralNodes.size(); ++i) {
            for (int j = i + 1; j < peripheralNodes.size(); ++j) {
                vectorOfDistance.push_back(BFS(peripheralNodes[i], peripheralNodes[j]));
            }
        }

        return vectorOfDistance;
    }

    // Нахождение минимального расстояния между вершинами с использованием BFS
    int BFS(Node* start, Node* end) {
        vector<bool> visited(nodes.size(), false);
        vector<int> distance(nodes.size(), INT_MAX);

        queue<Node*> q;
        q.push(start);
        visited[start->data] = true;
        distance[start->data] = 0;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                if (!visited[neighbor->data]) {
                    visited[neighbor->data] = true;
                    q.push(neighbor);
                    distance[neighbor->data] = distance[current->data] + 1;

                    if (neighbor == end) {
                        return distance[neighbor->data];
                    }
                }
            }
        }

        return -1; // Вершина end не достигнута, что-то пошло не так
    }
};

#endif //GRAPH_DISTANCE_GRAPHNODE_H
