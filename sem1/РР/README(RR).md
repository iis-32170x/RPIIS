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
    std::ifstream file("4.txt");
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
    int edg = 1, num = 1;
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
    for (int i = 0; i < v; i++) {
        delete[]matrix[i];
    }
    delete[]matrix;
}
```
# Тестовые значения
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/ba641e84-9a16-4d21-a630-f5ffdca701f7)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/bfd656bc-45f1-4784-ab26-ccdb81aca1e2)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/f4e87f4b-e6ca-44bd-a462-e1a112710a11)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/fc3160b2-afe9-454e-a080-520cae2d2831)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/4d7fbbb3-70f0-406a-aa00-64ec250c36be)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/cec6e3c9-3523-4249-ae47-a0b0e3474ee9)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/4c854f0f-4750-48cf-a8eb-63aa1f1f34b7)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/3af24be8-2ea6-4e21-a202-24a2826aab5c)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/85d02136-297d-444f-ad9e-49aa56169961)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/cd81ddb5-8a14-486d-a3d7-82707ee657e4)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/a12aa29b-6d88-4e7f-88a0-78a85193fdcc)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/3e91a0be-cf38-4a93-9a51-5d89fd83c9f9)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/4307e5c8-d815-46cc-9740-7d68419e1fdb)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/e04b908f-acbe-4075-9736-0f306e0d07dd)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/dce2223c-5df5-4a6f-90ee-cd10caf7014a)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/be65c995-fc24-4ad7-86c6-476e6924c141)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/43abd75c-9a94-471b-a88e-81098a007017)
![image](https://github.com/iis-32170x/RPIIS/assets/144935038/9b270d42-1ce8-4984-94a2-73b1c847113b)















