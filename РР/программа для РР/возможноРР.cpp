#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Функция, которая возвращает сумму модулей элементов вектора
int sum_abs(vector<int> v) {
    int sum = 0;
    for (int i : v) {
        sum += abs(i);
    }
    return sum;
}

// Функция, которая возвращает индекс вектора с максимальной суммой модулей элементов из списка векторов
int max_sum_abs_index(vector<vector<int>> v) {
    int max_index = 0;
    int max_sum = sum_abs(v[0]);
    for (int i = 1; i < v.size(); i++) {
        int curr_sum = sum_abs(v[i]);
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            max_index = i;
        }
    }
    return max_index;
}

// Функция, которая удаляет столбец с заданным индексом из матрицы
void delete_column(vector<vector<int>>& v, int index) {
    for (int i = 0; i < v.size(); i++) {
        v[i].erase(v[i].begin() + index);
    }
}

// Функция, которая прибавляет второй вектор к первому поэлементно
void add_vectors(vector<int>& v1, vector<int>& v2) {
    for (int i = 0; i < v1.size(); i++) {
        v1[i] = abs(v1[i])+abs(v2[i]);
    }
}

// Функция, которая выполняет алгоритм из задания
int algorithm(vector<vector<int>> v) {
    // Пока количество строк больше 2
    while (v.size() > 2) {
        // Находим 2 строки, суммы модулей чисел в которых максимальны
        int i1 = max_sum_abs_index(v);
        vector<int> v1 = v[i1];
        v.erase(v.begin() + i1);
        int i2 = max_sum_abs_index(v);
        vector<int> v2 = v[i2];
        v.erase(v.begin() + i2);

        // Проверяем есть ли в этих строках на одинаковых местах равные числа
        bool equal_found = false;
        do {
            equal_found = false;
            for (int i = 0; i < v1.size(); i++) {
                if (abs(v1[i]) == abs(v2[i])) {
                    // Если такие числа есть, удалить столбец с номером этого места
                    delete_column(v, i);
                    v1.erase(v1.begin() + i);
                    equal_found = true;
                    break;
                }
            }
            // Если нет - вместо второй строки взять следующую по сумме модулей элементов
            if (!equal_found) {
                i2 = max_sum_abs_index(v);
                v2 = v[i2];
                v.erase(v.begin() + i2);
            }
        } while (!equal_found);

        // Прибавить вторую строку к первой
        add_vectors(v1, v2);

        // Удалить вторую строку
        v2.clear();
    }

    // Найти сумму модулей чисел первой строки в получившейся матрице
    int result = sum_abs(v[0]);

    // Вернуть эту сумму
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите количество вершин в графе: ";
    cin >> n;
    cout << "Введите количество рёбер в графе: "; 
    cin >> m;
    vector<vector<int>> v(n, vector<int>(m));
    cout << "Введите матрицу инцидентности: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int result = algorithm(v);
    cout << "Размер минимального разреза данного графа равен: " << result;
    return 0;
}