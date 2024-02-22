#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int vertshina;
vector<pair<int, int>> rebra;

void find_sosed_craya(const vector<vector<int>>& spisok) {
    int num = 1;

    // Обход списка смежности
    for (int i = 0; i < vertshina; i++) {
        for (int j = 0; j < spisok[i].size(); j++) {
            int vertshina1 = i + 1;
            int vertshina2 = spisok[i][j];
            rebra.push_back(make_pair(vertshina1, vertshina2)); // Добавляем пару вершин в вектор
            num++;
        }
    }

    cout << "_______________________" << endl << endl;
    cout << "Смежные ребра:" << endl;
    for (int i = 0; i < rebra.size(); i++) {
        cout << i + 1 << " :  " << rebra[i].first << " - " << rebra[i].second << endl; // Выводим информацию о смежных ребрах
    }
    cout << "_______________________" << endl << endl;
}

int main() {
    vector<vector<int>> spisok;

    setlocale(LC_ALL, "RU");
    ifstream file_graph("graph.txt");

    if (file_graph.is_open()) {
        string line;
        while (getline(file_graph, line)) {
            stringstream ss(line);
            string vertshina_str;
            getline(ss, vertshina_str, ':');
            int vertex = stoi(vertshina_str);

            spisok.resize(max(spisok.size(), static_cast<size_t>(vertex)));

            string adjacent_vertices_str;
            getline(ss, adjacent_vertices_str);

            stringstream ss_adj(adjacent_vertices_str);
            string adjacent_vertex_str;
            while (ss_adj >> adjacent_vertex_str) {
                int adjacent_vertex = stoi(adjacent_vertex_str);
                spisok[vertex - 1].push_back(adjacent_vertex); // Добавляем смежную вершину в список смежности
            }
        }

        file_graph.close();

        vertshina = spisok.size();

        cout << "Матрица смежности:" << endl;
        for (int i = 0; i < vertshina; i++) {
            cout << "Вершина " << i + 1 << ": ";
            for (int j = 0; j < spisok[i].size(); j++) {
                cout << spisok[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        find_sosed_craya(spisok);
    }
    else {
        cout << "Файл не найден." << endl;
    }

    system("pause");
    return 0;
}

// ifstream открывает файл 