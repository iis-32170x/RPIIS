﻿#include <iostream>
#include "Library.h"
#include <stdlib.h>

using namespace std;

void input_fail()
{
    if (cin.fail()) {
        cout << "Ошибка ввода!";
        exit(0);
    }      
}

int main()
{
    setlocale(0, "");
    int* arr1, *arr2;
    int n1;
    cout << "Введите количество элементов первого массива" << endl;
    cin >> n1;
    input_fail();
    if (n1 < 0) {
        cout << "Количество элементов не может быть меньше нуля!" << endl;
        exit(0);
    }
    arr1 = (int*)malloc(sizeof(int) * n1);
    if (n1 != 0) {
        cout << "Введите элементы первого массива" << endl;
        for (int i = 0; i < n1; i++) {
            cin >> arr1[i];
            input_fail();
        }
    }
    int n2;
    cout << "Введите количество элементов второго массива" << endl;
    cin >> n2;
    input_fail();
    if (n2 < 0) {
        cout << "Количество элементов не может быть меньше нуля!" << endl;
        exit(0);
    }
    arr2 = (int*)malloc(sizeof(int) * n2);
    if (n2 != 0) {
        cout << "Введите элементы второго массива" << endl;
        for (int i = 0; i < n2; i++) {
            cin >> arr2[i];
            input_fail();
        }
    }
    cout << "Первый массив: ";
    for (int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;
    cout << "Второй массив: ";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;
    int flag;
    do {
        int key;
        cout << "Выберите действие(введите число):" << endl;
        cout << "1 - сортировка первого массива по возрастанию" << endl;
        cout << "2 - сортировка второго массива по возрастанию" << endl;
        cout << "3 - добавление элемента в первый массив(отсортированный)" << endl;
        cout << "4 - добавление элемента во второй массив(отсортированный)" << endl;
        cout << "5 - поиск элемента в первом массиве(отсортированном)" << endl;
        cout << "6 - поиск элемента во втором массиве(отсортированном)" << endl;
        cout << "7 - объединение двух отсортированных массивов" << endl;
        cout << "8 - пересечение двух отсортированных массивов" << endl;
        cin >> key;
        input_fail();
        switch (key)
        {
            case 1:
                arr_sort_incr(arr1, n1);
                cout << "Первый массив по возрастанию: ";
                for (int i = 0; i < n1; i++)
                    cout << arr1[i] << " ";
                cout << endl;
                break;
            case 2:
                arr_sort_incr(arr2, n2);
                cout << "Второй массив по возрастанию: ";
                for (int i = 0; i < n2; i++)
                    cout << arr2[i] << " ";
                cout << endl;
                break;
            case 3:
                int push1;
                cout << "Введите элемент, который необходимо добавить в первый массив: ";
                cin >> push1;
                arr_push(&arr1, &n1, push1);
                cout << "Новый первый массив: ";
                for (int i = 0; i < n1; i++)
                    cout << arr1[i] << " ";
                cout << endl;
                break;
            case 4:
                int push2;
                cout << "Введите элемент, который необходимо добавить во второй массив: ";
                cin >> push2;
                arr_push(&arr2, &n2, push2);
                cout << "Новый второй массив: ";
                for (int i = 0; i < n2; i++)
                    cout << arr2[i] << " ";
                cout << endl;
                break;
            case 5:
                int find1;
                cout << "Введите элемент, который хотите найти в первом массиве: ";
                cin >> find1;
                if (arr_find(arr1, n1, find1) != -1)
                    cout << "Индекс элемента " << find1 << " в первом массиве - " << arr_find(arr1, n1, find1) << endl;
                break;
            case 6:
                int find2;
                cout << "Введите элемент, который хотите найти во втором массиве: ";
                cin >> find2;
                if (arr_find(arr2, n2, find2) != -1)
                    cout << "Индекс элемента " << find2 << " во втором массиве - " << arr_find(arr2, n2, find2) << endl;
                break;
            case 7:
                arr_union(arr1, n1, arr2, n2);
                break;
            case 8:
                arr_intersection(arr1, n1, arr2, n2);
                break;
            default:
                cout << "Введено число не от 1 до 8!" << endl;
        }
        cout << "Желаете продолжить?(введите число) 1 - да, 2 - нет" << endl;
        cin >> flag;
        input_fail();
        if (flag != 1 and flag != 2) {
            cout << "Введенное число не равно 1 или 2!" << endl;
            exit(0);
        }
    } 
    while (flag == 1);
    /*free(arr1);
    free(arr2);*/
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
