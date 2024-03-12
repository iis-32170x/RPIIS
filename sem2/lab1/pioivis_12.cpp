// pioivis_12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "fenwick_tree1.h"





int main()
{
    vector<int> arr;
    int size;
    cout << "Enter size" << endl;
    cin >> size;
    arr.resize(size);
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
    FenwickTree ft(arr.size());

    for (int i = 0; i < arr.size(); ++i) {      
        ft.update(i + 1, arr[i]);
    }

    int l, r;
    cout << "Enter the range" << endl;
    cin >> l >> r;
    if (l <= size && r <= size)
        cout << ft.sum(l, r) << endl;
    else
        cout << "Enter correctly" << endl;




    int idx, val;
    cout << "Enter index and value" << endl;
    cin >> idx >> val;

    ft.updateArr(idx, val);
    for (int i = 0; i < arr.size(); i++) {
        cout << ft.sum(i + 1, i + 1) << " ";
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
