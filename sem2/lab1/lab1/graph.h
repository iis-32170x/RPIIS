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
            cout << "Íàïèøèòå ôàéë èç êîòîðîãî îòêðûòü" << endl;;
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
                cout << "Ôàéë íå íàéäåí." << endl;
            }

        }
        return;
    }

    void PrintMatrix()
    {
        cout << endl << "Ìàòðèöà èíöèäåíòíîñòè:" << endl;
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
        cout << "Âåðøèíà äîáàâëåíà." << endl << endl;
    }

    void DelVertex()
    {

        int numVertex;
        cout << endl << "Âûáåðèòå âåðøèíó, êîòîðóþ õîòèòå óäàëèòü: " << endl;
        cin >> numVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Íåêîððåêòíûé ââîä." << endl;
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
            cout << "Âåðøèíà " << ++numVertex << " óäàëåíà." << endl;
            n--;
        }
        else
        {
            cout << "Íåäîïóñòèìûé èíäåêñ äëÿ óäàëåíèÿ ýëåìåíòà." << endl;
            return;
        }
    }

    void AddArc()
    {
        int fromVertex, toVertex;
        cout << endl << "Ââåäèòå 2 âåðøèíû, îò êîòîðîé è äî êîòîðîé áóäåò ïðîâåäåíà äóãà: " << endl;
        cin >> fromVertex >> toVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Íåêîððåêòíûé ââîä." << endl;
        }

        fromVertex--;
        toVertex--;
        if (fromVertex == toVertex)
        {
            cout << "Íåâîçìîæíî ñîçäàòü ïåòëþ. Ââåäèòå 2 êîððåêòíûõ èíäåêñà." << endl;
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
            cout << "Íåäîïóñòèìûé èíäåêñ." << endl;
            return;
        }
        cout << "Äóãà îò âåðøèíû " << fromVertex + 1 << " äî âåðøèíû " << toVertex + 1 << " äîáàâëåíà." << endl;
    }

    void DelArc()
    {
        int numArc;
        cout << endl << "Ââåäèòå íîìåð äóãè, êîòîðóþ õîòèòå óäàëèòü: " << endl;
        cin >> numArc;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Íåêîððåêòíûé ââîä." << endl;
            return;
        }

        if (numArc >= 0 && numArc <= matrix[0].size())
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i].erase(matrix[i].begin() + numArc - 1);
            }
            m--;
            cout << "Äóãà óäàëåíà." << endl;
        }
        else
        {
            cout << "Íåäîïóñòèìûé èíäåêñ." << endl;
            return;
        }
    }




    void BFS() 
    {
        int firstVertex;
        cout << "Ââåäèòå íîìåð âåðøèíû, ñ êîòîðîé íà÷àòü îáõîä â øèðèíó." << endl;
        cin >> firstVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Íåêîððåêòíûé ââîä." << endl;
            return;
        }

        firstVertex--;
        if ((firstVertex < 0) || (firstVertex >= n))
        {
            cout << "Íåêîððåêòíûé èíäåêñ." << endl;
            return;
        }
        queue<int> q;
        q.push(firstVertex);
        vector<int> d(n, -1); //ïîñåùåííîñòü âåðøèíû
        vector<int> arcs(m, -1); // ïîñåùåííîñòü äóãè
        vector<int> count(n, 0); // ñ÷åò÷èê äëÿ êîëè÷åñòâà ïîñåùåíèé êàæäîé âåðøèíû
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
        //-----------âûâîä
        cout << "Êîëè÷åñòâî äóã íàïðàâëåííûõ â êàæäóþ âåðøèíó:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << count[i] << "  ";
        }
        cout << endl;
        //-----------
        cout << "Äåðåâî îáõîäà â øèðèíó:" << endl;
        d[firstVertex] = -1;
        while(!q.empty())
        {

            int v = q.front();
            q.pop();
            for (int u = 0; u < m; u++) //u ÿâëÿåòñÿ èíäåêñîì äóãè â äàííîé âåðøèíå
            {
                if (matrix[v][u] == 1) //ïîèñê íà÷àëà äóãè
                { 
                    for (int k = 0; k < n; k++) //k ÿâëÿåòñÿ ñòðîêîé â êîòîðîé èùåòñÿ êîíåö äóãè
                    {
                        if (matrix[k][u] == -1) //ïîèñê âåðøèíû ó êîòîðîé â äàííîì èíäåêñå u çíà÷åíèå -1
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
                                        cout << "Èç âåðøèíû " << v + 1 << " â âåðøèíó " << k + 1 << endl;
                                    }

                                }
                            }
                           
                        }
                    }
                }
            }
        }
        cout << "Îáõîä â øèðèíó îêîí÷åí." << endl;
    }

};
