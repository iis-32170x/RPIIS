// рр.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int VertexCount, EdgeCount;
    cout << "Enter the number of vertices and edges" << endl;
    cin >> VertexCount >> EdgeCount;

    vector<vector<int>> graph(VertexCount, vector<int>(VertexCount));
    vector <vector<int>> used(VertexCount, vector<int>(VertexCount));

    cout << "Enter a and b" << endl;

    for (int i = 0; i < EdgeCount; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int degree[2];
    cout << "Enter the specific degree" << endl;
    cin >> degree[0] >> degree[1];
    int k = 0;
    vector<int> VertexDegree(VertexCount);

    for (int c = 0; c < VertexCount; c++)
    {
        for (int d = 0; d < VertexCount; d++)
        {
            if (graph[c][d] == 1) k++;
        }
        VertexDegree[c] = k;
        k = 0;
    }

    for (int c = 0; c < VertexCount; c++)
    {
        for (int d = 0; d < VertexCount; d++)
        {
            if ((VertexDegree[c] == degree[0] && VertexDegree[d] == degree[1]) || (VertexDegree[c] == degree[1] && VertexDegree[d] == degree[0]))
            {
                if (graph[c][d] == 1 && used[c][d] == 0 && used[d][c] == 0)
                {
                    cout << "степень " << degree[0] << " и " << degree[1] << " имеет ребро между вершинами " << c + 1 << " и " << d + 1 << endl;
                    used[c][d] = 1;
                }
            }
        }
    }

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
