// laba2pivo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;

int main() {
    int ch;
    cout << "Choose a file:\n1. 1.txt\n2. 2.txt\n3. 3.txt\n4. 4.txt\n5. 5.txt\n";
    cin >> ch;
    string path;
    switch (ch) {
    case 1:
        path = "1.txt";
        break;
    case 2:
        path = "2.txt";
        break;
    case 3:
        path = "3.txt";
        break;
    case 4:
        path = "4.txt";
        break;
    case 5:
        path = "5.txt";
        break;
    default:
        cout << "Invalid choice!\n";
        return 1;
    }

    int num_sets;
    vector<vector<string>> sets,cortprod;
    vector<string> el;
    run_testcase(path, num_sets, sets);
    getcort(sets,0,num_sets,cortprod,el);
    for (int i = 0; i < cortprod.size(); i++) 
    {
        cout << "\n";
        for (int j = 0; j < num_sets; j++)
            cout << cortprod[i][j];
    }
        
    return 0;
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
