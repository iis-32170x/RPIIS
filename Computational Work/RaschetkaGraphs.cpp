#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int edges;
int vertices;
map<int, pair<int, int>> connection;

void find_adjacent_edges(const vector<vector<int>>& matrix) {
    int rows = vertices;    // Number of vertices
    int columns = edges;  // Number of edges

    int num = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++) {
            if (matrix[i][j] == 1) {
                for (int k = j + 1; k < columns; k++) {
                    if (matrix[i][k] == 1) {
                        connection[num] = make_pair(j, k);
                        num++;
                    }
                }
            }
        }
    }

    // Print connections
    cout << "_______________________" << endl << endl;
    cout << "Смежные ребра:" << endl;
    vector<vector<int>> AdjacentEdges;
    for (const auto& pair : connection) {
        cout << pair.first << 'e' << " :  " << char(65 + pair.second.first) << " - " << char(65 + pair.second.second)  << endl;
    }
    cout << "_______________________" << endl << endl;
}

vector<vector<int>> create_edge_graph(const map<int, pair<int, int>>& connections) {
    int num_vertices = 0;
    int num_edges = connections.size();

    // Determine the maximum vertex index
    for (const auto& pair : connections) {
        int vertex1 = pair.second.first;
        int vertex2 = pair.second.second;
        num_vertices = max(num_vertices, max(vertex1, vertex2) + 1);
    }

    vector<vector<int>> incidence_matrix(num_vertices, vector<int>(num_edges, 0));

    for (const auto& pair : connections) {
        int edge_index = pair.first - 1;  // Edge indices start from 0
        int vertex1 = pair.second.first;
        int vertex2 = pair.second.second;

        incidence_matrix[vertex1][edge_index] = 1;
        incidence_matrix[vertex2][edge_index] = 1;
    }
    return incidence_matrix;
}

int main()
{
    vector<vector<int>> IncMatrix(vertices, vector<int>(edges));
    int i;
    int j;
    setlocale(LC_ALL, "RUSSIAN");
    ifstream in("graph.txt");

    if (in.is_open())
    {
        int count = 0;
        int temp;
        while (!in.eof())
        {
            in >> temp;
            count++;
        }
        in.seekg(0, ios::beg);
        in.clear();
        int count_space = 0;
        char symbol;
        while (!in.eof())
        {
            in.get(symbol);
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }
        in.seekg(0, ios::beg);
        in.clear();
        vertices = count / (count_space + 1);
        edges = count_space + 1;
        vector<vector<int>> IncMatrix(vertices, vector<int>(edges));
        for (i = 0; i < vertices; i++)
            for (j = 0; j < edges; j++)
                in >> IncMatrix[i][j];
        
        for (i = 0; i < vertices; i++) {
            
            for (j = 0; j < edges; j++)
                cout << IncMatrix[i][j] << " ";
            cout << "\n";
        }
        in.close();
        find_adjacent_edges(IncMatrix);
        vector<vector<int>> incidence_matrix = create_edge_graph(connection);
        for (const auto& row : incidence_matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Файл не найден." << endl;
    }
    system("pause");
    return 0;
}