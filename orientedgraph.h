#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class Graph {
private:
    int n;
    int m;
    vector<vector<int>> matrix;
public:
    void InputMatrix()  //предназначена для чтения матрицы из файла и инициализации переменной `matrix` на основе прочитанных данных.
    {   
        string s;
        string namefile;
        cout << "Напишите файл из которого открыть";
        cin >> namefile;
        ifstream in(namefile);
        
        if (in.is_open())
        {
            getline(in, s);
            n = stoi(s.substr(0, s.size() - s.find(" ") - 1));
            m = stoi(s.substr(s.find(" ") + 1, s.size() - s.find(" ") - 1));
        }
        

        matrix.resize(n, vector<int>(m, 0));    //Инициализируем вектор векторов, создается матрица в которой каждая строка(n) имеет массив длинной m
        if (in.is_open())   
        {     
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < m; j++) 
                {
                    in >> matrix[i][j];
                }
            }
        }
        in.close();
    }

    void PrintMatrix() //предназначена для вывода матрицы инцидентности графа на экран.
    {
        cout << endl << "Матрица инцидентности:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void AddVertex() //предназначена для добавления новой вершины в граф, представленный матрицей смежности.
    {
        vector<int> newVertex(m, 0);
        matrix.push_back(newVertex);
        n++;
        cout << "Вершина добавлена." << endl << endl;
    }
   
    void DelVertex()    // предназначена для удаления вершины из графа, представленного матрицей смежности.
    {
        int numVertex;
        cout << endl << "Выберите вершину, которую хотите удалить: " << endl;
        cin >> numVertex;

        if (numVertex >= 0 && numVertex < matrix.size()) {
            matrix.erase(matrix.begin() + numVertex);
            cout << "Вершина " << numVertex << " удалена." << endl;
            n--;
        }
        else {
            cout << "Недопустимый индекс для удаления элемента." << endl;
        }
    }
    
    void AddArc()   //функция AddArc() предназначена для добавления дуги (направленного ребра) в граф, представленный матрицей смежности.
    {
        int fromVertex, toVertex;
        cout << endl << "Введите 2 вершины, от которой и до которой будет проведена дуга: " << endl;
        cin >> fromVertex >> toVertex;

        if ((fromVertex >= 0 && fromVertex < matrix.size()) && (toVertex >= 0 && toVertex < matrix.size()))
        {
            for (int i = 0; i < n; i++)
            {
                if (i == fromVertex - 1)
                {
                    matrix[i].push_back(1);
                }
                else if (i == toVertex - 1)
                {
                    matrix[i].push_back(-1);
                }
                else
                {
                    matrix[i].push_back(0);
                }
            }
            m++;
        }
        cout << "Дуга от вершины " << fromVertex << " до вершины " << toVertex << " добавлена." << endl;
    }
   
    void DelArc()
    {
        int numArc;
        cout << endl << "Введите номер дуги, которую хотите удалить: " << endl;
        cin >> numArc;

        if (numArc >= 0 && numArc < m)
        {
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][numArc] != 0)
                {
                    matrix[i].erase(matrix[i].begin() + numArc);
                }
            }
            m--;
            cout << "Дуга удалена." << endl;
        }
        else
        {
            cout << "Недопустимый индекс дуги." << endl;
        }
    }
    
    int BFS()
    {
        cout << "Начало выполнения функции обхода в ширину:" << endl;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            queue<pair<int, int>> q;
            q.push({ i, 0 });

            while (!q.empty()) {
                int cur = q.front().first;
                int dist = q.front().second;
                q.pop();

                for (int j = 0; j < m; j++) {
                    if (matrix[cur][j] == 1) {
                        for (int neighbor = 0; neighbor < n; neighbor++) {
                            if (matrix[neighbor][j] == -1) {
                                if (neighbor == i) {
                                    cout << "Вершина " << neighbor << " посещена" << endl;
                                }
                                else if (!visited[neighbor]) {
                                    visited[neighbor] = true;
                                    q.push({ neighbor, dist + 1 });
                                    cout << "Вершина " << neighbor << " посещена" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << "Функция обхода в ширину закончена." << endl;
        return 1;
    }
};
