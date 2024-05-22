#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> q(int n1, int n2) {
    vector<vector<int>> adj2;
    int i = 0;
    int g = 0;
    while (i < n1) {
        vector<int> temp = {i, g};
        adj2.push_back(temp);
        g += 1;
        if (g == n2) {
            g = 0;
            i += 1;
        }
    }

    return adj2;
}


int main() {
    setlocale(LC_ALL,"Rus");
    int n1, n2;
    cout << "Введите количество вершин первого графа ";
    cin >> n1;
    cout << "Введите количество вершин второго графа ";
    cin >> n2;

    
    vector<vector<int>> adj1(n1, vector<int>(n1));
    cout << "Введите матрицу смежности перого графа\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            cin >> adj1[i][j];
        }            

    }

    
    vector<vector<int>> adj2(n2, vector<int>(n2));
    cout << "Введите матрицу смежности второго графа\n";
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            cin >> adj2[i][j];
        }
    }

    
    vector<vector<int>> sum(n1 * n2, vector<int>(n1 * n2));

    for (auto i : q(n1, n2)) {
        for (auto j : q(n1, n2)) {
            if ((adj1[i[0]][j[0]] == 1 and adj2[i[1]][j[1]] == 0 and i[1] == j[1]) or 
                (adj1[i[0]][j[0]] == 0 and adj2[i[1]][j[1]] == 1 and i[0] == j[0])) {

                sum[i[0] + i[1] * n1 ][j[0] + j[1] * n1 ] = 1;
                
            }
            
        }
    }

    cout <<"Выводм матрицы смежности суммы графов\n";
    for (int i = 0; i < n1 * n2; i++) {
        for (int j = 0; j < n1 * n2; j++) {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}