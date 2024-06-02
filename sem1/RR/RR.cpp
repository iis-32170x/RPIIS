#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Graph {
private:
    vector<vector<int>> Matrix_smezh;
public:
    Graph(int razmer = 0) {
        Matrix_smezh.resize(razmer, vector<int>(razmer, 0));
    }

    void addRebro(int v1, int v2, int ves) {
        if (v1 < Matrix_smezh.size() && v2 < Matrix_smezh.size()) {
            Matrix_smezh[v1][v2] = ves;
            Matrix_smezh[v2][v1] = ves; // Для неориентированного графа
        }
    }

    void UnionGraphs(const Graph& drugoy) {
        int maxSize = max(Matrix_smezh.size(), drugoy.Matrix_smezh.size());
        resizeMatrix(maxSize);
        for (int i = 0; i < drugoy.Matrix_smezh.size(); ++i) {
            for (int j = 0; j < drugoy.Matrix_smezh[i].size(); ++j) {
                if (drugoy.Matrix_smezh[i][j]) {
                    Matrix_smezh[i][j] = drugoy.Matrix_smezh[i][j];
                }
            }
        }
    }

    void displayGraph() const {
        cout << "Матрица смежности:" << endl;
        for (const auto& row : Matrix_smezh) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void resizeMatrix(int newSize) {
        Matrix_smezh.resize(newSize);
        for (auto& row : Matrix_smezh) {
            row.resize(newSize, 0);
        }
    }

    const vector<vector<int>>& getMatrix_smezh() const {
        return Matrix_smezh;
    }
};

void writeGraphToFile(const Graph& graph, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл для записи: " << filename << endl;
        return;
    }
    const auto& Matrix_smezh = graph.getMatrix_smezh();
    file << Matrix_smezh.size() << endl;
    for (const auto& row : Matrix_smezh) {
        for (int val : row) {
            file << val << " ";
        }
        file << endl;
    }
    file.close();
    cout << "Граф записан в файл " << filename << endl;
}

void readGraphFromFile(Graph& graph, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filename << endl;
        return;
    }
    int size;
    file >> size;
    Graph tempGraph(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int edge;
            file >> edge;
            tempGraph.addRebro(i, j, edge);
        }
    }
    graph.UnionGraphs(tempGraph);
    file.close();
}

Graph inputGraph() {
    int size;
    cout << "Введите размер матрицы смежности: ";
    cin >> size;
    Graph graph(size);
    cout << "Введите матрицу смежности (по " << size << " чисел в каждой строке):" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int rebro;
            cin >> rebro;
            graph.addRebro(i, j, rebro);
        }
    }
    return graph;
}

int main() {
    Graph unionGraph;
    char vybor;
    setlocale(0, "");
    cout << "Хотите ввести новые графы? (y/n): ";
    cin >> vybor;
    if (vybor == 'y' || vybor == 'Y') {
        // Ввод и сохранение первого графа
        cout << "Введите данные для первого графа." << endl;
        Graph g1 = inputGraph();
        cout << "Хотите сохранить первый граф в файл? (y/n): ";
        cin >> vybor;
        if (vybor == 'y' || vybor == 'Y') {
            string filename;
            cout << "Введите имя файла для первого графа без расширения: ";
            cin >> filename;
            if (filename.substr(filename.size() - 4) != ".txt") {
                filename += ".txt";
            }
            writeGraphToFile(g1, filename);
        }
        // Ввод и сохранение второго графа
        cout << "Введите данные для второго графа." << endl;
        Graph g2 = inputGraph();
        cout << "Хотите сохранить второй граф в файл? (y/n): ";
        cin >> vybor;
        if (vybor == 'y' || vybor == 'Y') {
            string filename;
            cout << "Введите имя файла для второго графа без расширения: ";
            cin >> filename;
            if (filename.substr(filename.size() - 4) != ".txt") {
                filename += ".txt";
            }
            writeGraphToFile(g2, filename);
        }
        // Объединение введенных графов
        unionGraph.UnionGraphs(g1);
        unionGraph.UnionGraphs(g2);
    }
    else {
        // Чтение графов из файлов
        readGraphFromFile(unionGraph, "graph1.txt");
        readGraphFromFile(unionGraph, "graph2.txt");
    }
    cout << "Объединенный граф:" << endl;
    unionGraph.displayGraph();
    return 0;
}
