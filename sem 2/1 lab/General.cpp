#include <iostream>
#include <vector>
#include <cmath>
#include "Qtree.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    int key, n, c1, res = 0, reso = 0, index = 0, i = 0, j = 0, temp;
    bool fl1 = 1,fl2=1,fl3=1,fl4=1;
    cout << "Выберите действие:" << endl;
    cout << "1-Перевод матрицы в дерево" << endl;
    cout << "2-Перевод дерева в матрицу" << endl;
    cin >> key;
    if (key == 1) {
        cout << "Введите размер матрицы :";
        cin >> n;
        c1 = log2(n);
        if (n != pow(2, c1)) {
            cout << "Вы ввели недопустимое значение, попробуйте снова!!!:(";
            return 0;
        }
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "Введите" << "[" << i + 1 << "]" << "[" << j + 1 << "]" << "элемент матрицы : " << " ";
                cin >> matrix[i][j];
            }
        }
        QuadTree* root = To_tree(matrix);
        vector<vector<int>> ex_matrix(matrix.size(), vector<int>(matrix.size(), 0));
        for (int i = 0; i < ex_matrix.size(); i++) {
            for (int j = 0; j < ex_matrix[i].size(); j++) {
                if (ex_matrix[i][j] != matrix[i][j]) {
                    result = false;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "Итоговое квадродерево:" << endl;
        releaseTree(root, 0);

        return 0;
    }
    if (key == 2) {
        int depth;
        cout << "Введите глубину квадродерева : " << endl;
        cin >> depth;
        vector<vector<int>> matrix(pow(2, depth), vector<int>(pow(2, depth)));
        cout << "Итоговая матрица:" << endl;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
}
