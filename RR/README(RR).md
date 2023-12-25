# Условие
<p>2. Определить числовую характеристику графа:</p>
 
   7. (4) Число рёберной связности (нг, ог)

Граф задается матрицой смежности.
# Ключевые понятия 
`Граф` —　математическая　абстракция　реальной　системы　любой　природы，　объекты　которой　обладают　парными　связями．

`Реберная связность графа` — это наименьшее количество ребер, удаление которых приводит к несвязному или тривиальному графу.

`Связный граф` — граф,между каждой парой вершин которого есть путь.

﻿`Ориентированный　граф`　—　граф，　рёбрам　которого　присвоено　направление
 
`Неориентированный граф` -граф, в котором все ребра являются звеньями, то есть порядок двух концов ребра графа не существенен.

`Матрица смежности` - это способ представления графа в виде матрицы. В этой матрице каждая строка и столбец соответствуют одной вершине графа. Элемент матрицы на пересечении строки i и столбца j >= 1, если вершины i и j соединены ребром, и =0, если они не соединены.
# Реализация
``` c++
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
int edgeconnectivity(short int** matrix, int v, bool* proof1, bool* proof2, int min, int edg, bool** edges, int level,int skp,bool*proof,int lvl) {
    if (edg != min) {
        if (skp==level) {
            for (int i = 0; i < v - 1; i++) {
                for (int j = i + 1; j < v; j++) {
                   
                        if (matrix[i][j] == 1 ) {
                            matrix[i][j] = 0;
                            matrix[j][i] = 0;
                            proof1 = connectivity(matrix, proof1, proof2, v);
                            for (int t = 0; t < v; t++) {
                                if (proof1[t] == false) {
                                    edg++;
                                    min = edg;
                                    apdate(proof1, v, proof2);
                                    matrix[i][j] = 1;
                                    matrix[j][i] = 1;
                                    i = v; j = v; t = v;
                                    break;
                                }
                            }
                            if (edg != min) {
                                apdate(proof1, v, proof2);
                                matrix[i][j] = 1;
                                matrix[j][i] = 1;
                            }
                        }
                    
                }

            }
        }
        else{
            skp++;
        }
    }
    if (edg != min) {
        edg++;
        again:
        if (level!=edg-1) {
            if (edg < min) {
                for (int i = 0; i < v-1; i++) {
                    for (int j = i+1; j < v; j++) {
                        if (matrix[i][j] == 1) {
                            matrix[i][j] = 0; matrix[j][i] = 0;
                            min=edgeconnectivity(matrix, v, proof1, proof2, min, edg, edges, level,skp,proof,lvl);
                            matrix[i][j] = 1; matrix[j][i] = 1;
                            if (edg == min) {
                                i = v; j = v;
                            }
                        }
                    }
                }
            }
            if (proof[lvl-1] == true) {
                skp--;
                lvl--;
            }
            else {
                if (edg != min) {
                    skp = 1;
                    proof[level] = true;
                    level++;
                    lvl = level;
                    goto again;
                }
            }
        }
        else {
            edg--;
        }
    }
    if (min == edg && level!=1) {
        level--;
    }
    return min;
}
int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("5.txt");
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }
    int v, level = 1, lvl = 1, skp = 1,ways=0,max=0; bool graph=false;
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
    if (ways == 1 && graph==false) {
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
    bool* proof = new bool[min+1];
    bool** edges = new bool* [v];
    int edg = 0;
    for (int i = 0; i < v; i++) {
        proof1[i] = false;
        proof2[i] = false;
    }
    for (int i = 0; i < v; i++) {
        edges[i] = new bool[v];
        for (int j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }
    for (int i = 0; i < min; i++) {
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
    if (graph == false && ways ==0) {
        std::cout << "Реберная связность:" << min;
        goto skip;
    }
    if (min == 1 && graph==true) {
        std::cout << "Реберная связность:" << min;
        goto skip;
    }
    apdate(proof1, v, proof2);
   min=edgeconnectivity(matrix, v, proof1, proof2, min, edg, edges, level,skp,proof,lvl);
   std::cout << "Реберная связность:" << min;
    skip:
    delete[] proof1;
    delete[] proof2;
    delete[] proof;
        for (int i = 0; i < v; i++) {
        delete[]edges[i];
        delete[]matrix[i];
        }
    delete[]matrix;
    delete[]edges;
}
```
# Тестовые значения


