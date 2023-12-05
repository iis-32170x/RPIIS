// рр.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int VertexCount, EdgeCount;
    cout << "Enter the number of vertices and edges" << endl;
    cin >> VertexCount >> EdgeCount;

    vector<vector<int>> graph(VertexCount, vector<int>(VertexCount));

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

    int degree;
    cout << "Enter the specific degree" << endl;
    cin >> degree;
    int k = 0;
    for (int i = 0; i < VertexCount; i++)

    {
        k = 0;
        for (int b = 0; b < VertexCount; b++)
        {
            if (graph[i][b] == 1) k++;
        }
         if (k == degree) cout << "Vertex " << i + 1 << " has degree " << degree << endl;
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
