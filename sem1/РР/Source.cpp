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
    proof1[0] = true; proof2[0] = true; bool newlvl = false;
    again:
    for (int i = 0; i < v; i++) {
        if (proof2[i] == true&&proof1[i]==true) {
            for (int j = 0; j < v; j++) {
                if (matrix[i][j] == 1 && proof1[j] == false) {
                    newlvl = true;
                    proof2[j] = true;
                }
            }
            proof2[i] = false;
        }
    }
    if (newlvl == true) {
        for (int i = 0; i < v; i++) {
            if (proof2[i] == true) {
                proof1[i] = true;
            }
        }
        newlvl = false; goto again;
    }
    return proof1;
}
void edgeconnectivity(short int**& matrix, int v, bool* proof1, bool* proof2,bool& answer,int lvl,int& edg) {
    edg++;
    for (int i = 0; i < v - 1; i++) {
        for (int j = i + 1; j < v; j++) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                matrix[j][i] = 0;
                if (edg != lvl) {
                    edgeconnectivity(matrix, v, proof1, proof2, answer, lvl, edg);
                    matrix[i][j] = 1;
                    matrix[j][i] = 1;
                    if (answer == true) {
                        edg--;
                        return;
                    }
                }
                proof1 = connectivity(matrix, proof1, proof2, v);
                for (int t = 0; t < v; t++) {
                    if (proof1[t] == false) {
                        answer = true;
                        apdate(proof1, v, proof2);
                        matrix[i][j] = 1;
                        matrix[j][i] = 1;
                        edg--;
                        return;
                    }
                }
                apdate(proof1, v, proof2);
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
    }
    edg--;
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
    int min = 0, amntedges = 0;
    for (int i = 0; i < v; i++) {
        if (matrix[i][0] == 1) {
            min++;
        }
        for (int j = 0; j < v; j++) {
            if (matrix[i][j] == 1 && matrix[j][i] == 1) {
                graph = true;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }// graph=true-non oriented graph.
    max = min;
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
        }else
        if (amntedges > max) {
            max = amntedges;
        }else
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
    for (int i = 0; i < v; i++) {
        proof1[i] = false;
        proof2[i] = false;
    }
    if (graph == false) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (matrix[i][j] == 1) {
                    matrix[j][i] = 1;
                }
            }
        }

    }int edg = 0;
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
        edgeconnectivity(matrix, v, proof1, proof2,answer,i,edg);
        if (answer == true) {
            min = i;
            break;
        }
    }
    std::cout << "Реберная связность:" << min << endl;
skip:
    delete[] proof1;
    delete[] proof2;
    for (int i = 0; i < v; i++) {
        delete[]matrix[i];
    }
    delete[]matrix;
}