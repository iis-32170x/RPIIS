#include <iostream>
#include <fstream>
using namespace std;
void apdate(bool* proof1, int v, bool* proof2) {
    for (int j = 0; j < v; j++)
    {
        proof1[j] = false;
        proof2[j] = false;
    }
}
bool* connectivity(short int** matrix, bool* proof1, bool* proof2, int v) {
    proof1[0] = true;
    for (int j = 0; j < v; j++) {
        proof2[j] = false;
    }
    for (int i = 0; i < v; i++) {
        if (proof1[i] == true && proof2[i] == false) {
            for (int j = 0; j < v; j++) {
                if (matrix[i][j] == 1 && proof1[j] == false) {
                    proof1[j] = true;
                    proof2[j] = true;
                }
            }
        }
    }
    for (int j = 0; j < v; j++) {
        if (proof2[j] == true) {
            return  connectivity(matrix, proof1, proof2, v);
        }
    }
    return proof1;
}
void edgeconnectivity(short int**& matrix, int v, bool* proof1, bool* proof2, int& min, int& edg, int& num,bool& answer) {
    for (int i = 0; i < v - 1; i++) {
        for (int j = i + 1; j < v; j++) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                matrix[j][i] = 0;
                proof1 = connectivity(matrix, proof1, proof2, v);
                for (int t = 0; t < v; t++) {
                    if (proof1[t] == false) {
                        min = edg;
                        answer = true;
                        apdate(proof1, v, proof2);
                        matrix[i][j] = 1;
                        matrix[j][i] = 1;
                        break;
                    }
                }
                apdate(proof1, v, proof2);
                if (num != min) {
                    edg++;
                    num++;
                    edgeconnectivity(matrix, v, proof1, proof2, min, edg, num,answer);

                }
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
    }
    edg--;
    num--;
    return;
}
int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("6.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }
    int v, skp = 1, ways = 0, max = 0,Min; bool graph = false,answer=false;
    file >> v;
    file.seekg(2, std::ios_base::beg);
    short int** matrix = new short int* [v];
    for (int i = 0; i < v; i++) {
        matrix[i] = new short int[v];
    }
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (matrix[i][j] == 1 && matrix[j][i] == 1) {
                graph = true;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int min = 0, amntedges = 0;
    for (int i = 0; i < v; i++) {
        if (matrix[i][0] == 1)
            min++; max++;
    }
    if (min == 0) {
        ways++;
    }
    for (int j = 1; j < v; j++) {
        for (int i = 0; i < v; i++) {
            if (matrix[i][j] == 1)
                amntedges++;
        }
        if (amntedges == 0) {
            ways++;
        }
        if (amntedges > max) {
            max = amntedges;
        }
        if (amntedges < min)
            min = amntedges;
        amntedges = 0;
    }
    if (ways == 1 && graph == false) {
        min = 0;
        for (int i = 0; i < v; i++) {
            if (matrix[i][0] == 1)
                min++;
        }
        if (min == 0) {
            min = max;
        }
        for (int j = 1; j < v; j++) {
            for (int i = 0; i < v; i++) {
                if (matrix[i][j] == 1)
                    amntedges++;
            }
            if (amntedges == 0) {
                amntedges = min;
            }
            if (amntedges < min)
                min = amntedges;
            amntedges = 0;
        }
    }
    bool* proof1 = new bool[v];
    bool* proof2 = new bool[v];
    bool* proof = new bool[min + 1];
    int edg = 1, num = 1;
    for (int i = 0; i < v; i++) {
        proof1[i] = false;
        proof2[i] = false;
    }
    for (int i = 0; i < min + 1; i++) {
        proof[i] = false;
    }
    if (graph == false) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (matrix[i][j] == 1) {
                    matrix[j][i] = 1;
                }
            }
        }

    }
    proof1 = connectivity(matrix, proof1, proof2, v);
    for (int i = 0; i < v; i++) {
        if (proof1[i] == false) {
            std::cout << "Граф несвязный";
            goto skip;
        }
    }
    if (ways > 1) {
        std::cout << "Граф несвязный";
        goto skip;
    }
    if (graph == false && ways == 0) {
        std::cout << "Реберная связность:" << min;
        goto skip;
    }
    if (min == 1 && graph == true) {
        std::cout << "Реберная связность:" << min;
        goto skip;
    }
    apdate(proof1, v, proof2);
    for (int i = 1; i <= min; i++) {
        Min = i;
        edgeconnectivity(matrix, v, proof1, proof2, Min, edg, num,answer);
        edg = 1; num = 1;
        if (answer == true) {
            min = Min;
            break;
        }
    }
    std::cout << "Реберная связность:" << min << endl;

skip:
    delete[] proof1;
    delete[] proof2;
    delete[] proof;
    for (int i = 0; i < v; i++) {
        delete[]matrix[i];
    }
    delete[]matrix;
}