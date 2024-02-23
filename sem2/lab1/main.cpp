#include <iostream>
#include "hash_table.h"

using namespace std;

int main()
{
    int arrSize, arr[100];

    string path;
    int ch;
    cout << "Choose a file:\n1. arr1.txt\n2. arr2.txt\n3. arr3.txt\n";
    cin >> ch;
    switch (ch) {
    case 1:
        path = "arr1.txt";
        break;
    case 2:
        path = "arr2.txt";
        break;
    case 3:
        path = "arr3.txt";
        break;
    default:
        cout << "Invalid choice!\n";
    }
    run_testcase(path, arrSize, arr);//передаем пустую переменную arrSize, а потом записываем в нее значение из файла path

    arrSize = 10;
    Node** pTable;
    pTable = create(arrSize);
    for (int i = 0; i < arrSize; i++)
        add(arr[i], arrSize, pTable);

    int choice = 0;
    int searchVal, index = -1;
    while (choice != 4) {
        cout << "Menu:\n1. Add element\n2. Delete element\n3. Search\n4. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter element to add: ";
            cin >> searchVal;
            add(searchVal, arrSize, pTable);
            break;
        case 2:
            cout << "Enter element to delete: ";
            cin >> searchVal;
            remove(searchVal, arrSize, pTable);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> searchVal;
            index = search(searchVal, arrSize, pTable);
            if (index == -1)
                cout << "Element not found" << endl;
            else
                cout << "Index: " << index << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
