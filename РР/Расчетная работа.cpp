#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

vector<unordered_set<int>> readGraphsFromFile(const string& filename) {
    ifstream file(filename);
    vector<unordered_set<int>> graphs;
    unordered_set<int> currentGraph;

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            graphs.push_back(currentGraph);
            currentGraph.clear();
        }
        else {
            istringstream iss(line);
            int vertex;
            while (iss >> vertex) {
                currentGraph.insert(vertex);
            }
        }
    }

    if (!currentGraph.empty()) {
        graphs.push_back(currentGraph);
    }

    return graphs;
}


unordered_set<int> findGraphIntersection(const vector<unordered_set<int>>& graphs) {
    if (graphs.empty()) {
        return unordered_set<int>(); 
    }

    unordered_set<int> intersection = graphs[0];

    for (size_t i = 1; i < graphs.size(); ++i) {
        const unordered_set<int>& currentGraph = graphs[i];
        unordered_set<int> newIntersection;

        
        for (int vertex : currentGraph) {
            if (intersection.count(vertex) > 0) {
                newIntersection.insert(vertex);
            }
        }

       
        intersection = newIntersection;
    }

    return intersection;
}

void writeIntersectionToFile(const string& filename, const unordered_set<int>& intersection) {
    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи." << endl;
        return;
    }

    for (int vertex : intersection) {
        file << vertex << endl;
    }

    file.close();

    cout << "Пересечение графов записано в файл " << filename << endl;
}

int main() {
    string inputFilename = "input.txt"; 
    string outputFilename = "output.txt"; 

    vector<unordered_set<int>> graphs = readGraphsFromFile(inputFilename); 
    unordered_set<int> intersection = findGraphIntersection(graphs); 
    writeIntersectionToFile(outputFilename, intersection);

    return 0;
}