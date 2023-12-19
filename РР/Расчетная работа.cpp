#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<int, unordered_set<int>> findGraphIntersection(const vector<unordered_map<int, unordered_set<int>>>& graphs) {
    if (graphs.empty()) {
        return {};
    }

    unordered_map<int, unordered_set<int>> intersectionGraph = graphs[0];

    for (size_t i = 1; i < graphs.size(); ++i) {
        const unordered_map<int, unordered_set<int>>& currentGraph = graphs[i];
        unordered_map<int, unordered_set<int>> newIntersectionGraph;

        for (const auto& vertexNeighbors : currentGraph) {
            int vertex = vertexNeighbors.first;

            if (intersectionGraph.count(vertex) > 0) {
                const unordered_set<int>& neighbors = vertexNeighbors.second;
                unordered_set<int> commonNeighbors;

                for (int neighbor : neighbors) {
                    if (intersectionGraph[vertex].count(neighbor) > 0) {
                        commonNeighbors.insert(neighbor);
                    }
                }

                if (!commonNeighbors.empty()) {
                    newIntersectionGraph[vertex] = commonNeighbors;
                }
            }
        }

        intersectionGraph = std::move(newIntersectionGraph);
    }

    // Добавляем вершины, которые не имеют общих ребер, но являются общими вершинами
    unordered_map<int, unordered_set<int>> finalIntersectionGraph = intersectionGraph;

    for (const auto& vertexNeighbors : graphs[0]) {
        int vertex = vertexNeighbors.first;
        bool isCommonVertex = true;

        for (size_t i = 1; i < graphs.size(); ++i) {
            const unordered_map<int, unordered_set<int>>& currentGraph = graphs[i];
            if (currentGraph.count(vertex) == 0) {
                isCommonVertex = false;
                break;
            }
        }

        if (isCommonVertex && finalIntersectionGraph.count(vertex) == 0) {
            finalIntersectionGraph[vertex] = {};
        }
    }

    return finalIntersectionGraph;
}

int main() {
    setlocale(LC_ALL, "RU");

    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Не удалось открыть входной файл " << inputFileName << endl;
        return 1;
    }

    vector<unordered_map<int, unordered_set<int>>> graphs;
    unordered_map<int, unordered_set<int>> graph;
    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            if (!graph.empty()) {
                graphs.push_back(graph);
                graph.clear();
            }
        }
        else {
            istringstream iss(line);
            int vertex;
            iss >> vertex;
            int neighbor;
            while (iss >> neighbor) {
                graph[vertex].insert(neighbor);
            }
        }
    }
    if (!graph.empty()) {
        graphs.push_back(graph);
    }
    inputFile.close();

    unordered_map<int, unordered_set<int>> intersectionGraph = findGraphIntersection(graphs);

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Не удалось открыть выходной файл: " << outputFileName << endl;
        return 1;
    }

    for (const auto& vertexNeighbors : intersectionGraph) {
        int vertex = vertexNeighbors.first;
        const unordered_set<int>& neighbors = vertexNeighbors.second;

        outputFile << vertex;
        for (int neighbor : neighbors) {
            outputFile << " " << neighbor;
        }
        outputFile << endl;
    }
    outputFile.close();

    cout << "Пересечение графов записано в файл " << outputFileName << endl;

    return 0;
}