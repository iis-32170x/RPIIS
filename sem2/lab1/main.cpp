// pioivis_11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {

	vector<int> tree;
    vector<int> arr;

    FenwickTree(int size)                   //размер дерева фенвика
    {
        tree.resize(size + 1);
        arr.resize(size + 1);
    }

    void update(int idx, int value)         //обновление значения
    {
        while (idx < tree.size())
        {
            tree[idx] += value;
            idx += idx & -idx;
        }
    }


    void updateArray(int idx, int newValue) {
        int diff = newValue - (arr[idx - 1]); // Вычисляем разницу между новым и старым значением
        arr[idx - 1] = newValue; // Обновляем значение в массиве

        update(idx, diff); // Обновляем соответствующий элемент в дереве Фенвика
    }

    

    int sum(int x) {                        //сумма от 0
        int result = 0;

        while (x > 0) {
            result += tree[x];
            x -= x & -x;
        }
        
        return result;
    }

    int sum(int l, int r) {                 //сумма на отрезке
        if (l>0) {
            return sum(r) - sum(l - 1);
        }
        else {
            return sum(r);
        }
    }

};

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

    for (int i = 0; i < arr.size(); ++i) {      //заполнение дерева фенвика
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
 
    ft.updateArray(idx, val);
    for (int i = 0; i < arr.size(); i++) {
        cout << ft.sum(i + 1, i + 1) << " "; 
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
