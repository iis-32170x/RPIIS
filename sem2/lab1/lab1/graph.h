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
    void InputMatrix() {
        string s;
        string namefile;
        bool b = true;
        while (b)
        {
            cout << "Напишите файл из которого открыть" << endl;;
            cin >> namefile;

            ifstream in(namefile);

            if (in.is_open())
            {
                getline(in, s);
                n = stoi(s.substr(0, s.size() - s.find(" ") - 1));
                m = stoi(s.substr(s.find(" ") + 1, s.size() - s.find(" ") - 1));

                matrix.resize(n, vector<int>(m, 0));
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        in >> matrix[i][j];
                    }
                }
                in.close();
                b = false;
            }
            else
            {
                cout << "Файл не найден." << endl;
            }

        }
        return;
    }

    void PrintMatrix()
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

    void AddVertex()
    {
        vector<int> newVertex(m, 0);
        matrix.push_back(newVertex);
        n++;
        cout << "Вершина добавлена." << endl << endl;
    }

    void DelVertex()
    {

        int numVertex;
        cout << endl << "Выберите вершину, которую хотите удалить: " << endl;
        cin >> numVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Некорректный ввод." << endl;
        }

        numVertex--;
        if (numVertex >= 0 && numVertex < n)
        {
            for (int i = matrix[0].size() - 1; i >= 0 ; i--)
            {
                if (matrix[numVertex][i] != 0)
                {
                    for (int k = 0; k < n; k++)
                    {
                        matrix[k].erase(matrix[k].begin() + i);
                    }
                    m--;
                }
            }
            matrix.erase(matrix.begin() + numVertex);
            cout << "Вершина " << ++numVertex << " удалена." << endl;
            n--;
        }
        else
        {
            cout << "Недопустимый индекс для удаления элемента." << endl;
            return;
        }
    }

    void AddArc()
    {
        int fromVertex, toVertex;
        cout << endl << "Введите 2 вершины, от которой и до которой будет проведена дуга: " << endl;
        cin >> fromVertex >> toVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Некорректный ввод." << endl;
        }

        fromVertex--;
        toVertex--;
        if (fromVertex == toVertex)
        {
            cout << "Невозможно создать петлю. Введите 2 корректных индекса." << endl;
            return;
        }
        if ((fromVertex >= 0 && fromVertex < matrix.size()) && (toVertex >= 0 && toVertex < matrix.size()))
        {
            for (int i = 0; i < n; i++)
            {
                if (i == fromVertex)
                {
                    matrix[i].push_back(1);
                }
                else if (i == toVertex)
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
        else
        {
            cout << "Недопустимый индекс." << endl;
            return;
        }
        cout << "Дуга от вершины " << fromVertex + 1 << " до вершины " << toVertex + 1 << " добавлена." << endl;
    }

    void DelArc()
    {
        int numArc;
        cout << endl << "Введите номер дуги, которую хотите удалить: " << endl;
        cin >> numArc;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Некорректный ввод." << endl;
            return;
        }

        if (numArc >= 0 && numArc <= matrix[0].size())
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i].erase(matrix[i].begin() + numArc - 1);
            }
            m--;
            cout << "Дуга удалена." << endl;
        }
        else
        {
            cout << "Недопустимый индекс." << endl;
            return;
        }
    }




    void BFS() 
    {
        int firstVertex;
        cout << "Введите номер вершины, с которой начать обход в ширину." << endl;
        cin >> firstVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Некорректный ввод." << endl;
            return;
        }

        firstVertex--;
        if ((firstVertex < 0) || (firstVertex > n))
        {
            cout << "Некорректный индекс." << endl;
            return;
        }
        queue<int> q;
        q.push(firstVertex);
        vector<int> d(n, -1); //посещенность вершины
        vector<int> arcs(m, -1); // посещенность дуги
        vector<int> count(n, 0); // счетчик для количества посещений каждой вершины
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1)
                {
                    count[i]++;
                }
            }
        }
        //-----------вывод
        cout << "Количество дуг направленных в каждую вершину:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << count[i] << "  ";
        }
        cout << endl;
        //-----------
        cout << "Дерево обхода в ширину:" << endl;
        d[firstVertex] = -1;
        while(!q.empty())
        {

            int v = q.front();
            q.pop();
            for (int u = 0; u < m; u++) //u является индексом дуги в данной вершине
            {
                if (matrix[v][u] == 1) //поиск начала дуги
                { 
                    for (int k = 0; k < n; k++) //k является строкой в которой ищется конец дуги
                    {
                        if (matrix[k][u] == -1) //поиск вершины у которой в данном индексе u значение -1
                        {
                            if (arcs[u] == -1)
                            {
                                arcs[u]++;
                                if (d[k] == -1)
                                {
                                    q.push(k);
                                    if (count[k] == 0)
                                    {

                                        d[k]++;
                                    }
                                    else
                                    {
                                        count[k]--;
                                        cout << "Из вершины " << v + 1 << " в вершину " << k + 1 << endl;
                                    }

                                }
                            }
                           
                        }
                    }
                }
            }
        }
        cout << "Обход в ширину окончен." << endl;
    }

};
