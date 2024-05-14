#include <iostream>
#include <vector>

using namespace std;

bool Dupl(const vector<int>& mnosh) {
    for (int i = 0; i < mnosh.size(); ++i) {
        for (int j = i + 1; j < mnosh.size(); ++j) {
            if (mnosh[i] == mnosh[j]) {
                return true;
            }
        }
    }
    return false;
}

void generateGraphs(vector<vector<int>>& graphs, vector<int>& current, const vector<int>& mnosh, int index = 0) {
    if (index >= mnosh.size()) {
        graphs.push_back(current);
        return;
    }
    
    
    for (int i = 0; i < mnosh.size(); ++i) {
        bool isValid = true;
        for (int j = 0; j < index; ++j) {
            if (current[j] == mnosh[i]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            current[index] = mnosh[i]; 
            generateGraphs(graphs, current, mnosh, index + 1);
        }
    }
}

void Graphs(const vector<vector<int>>& graphs) {
    for (const auto& graph : graphs) {
        cout << "{";
        for (int i = 0; i < graph.size(); ++i) {
            cout << graph[i];
            if (i != graph.size() - 1) {
                cout << " , ";

            }
        }
        cout << "}" << '\n';
    }
}

int main() {

    setlocale(LC_ALL, "RU");

    cout << "Введите размер множества: ";
    int num;
    cin >> num;

    vector<int>  mnosh(num);
    cout << "Введите элементы множетсва:\n";
    for (int i = 0; i < num; ++i) {
        cin >> mnosh[i];
    }

    if (Dupl(mnosh)) {
        cout << "Error: Присутствует дубликат\n";
        return 0;
    }

   vector<int> current(mnosh.size());
   vector<vector<int>> directedGraphs;

    generateGraphs(directedGraphs, current, mnosh, 0);
   cout << "Созданные множества:\n";
    Graphs(directedGraphs);
    return 0;
}
