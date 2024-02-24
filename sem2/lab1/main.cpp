#include <iostream>
#include "library.h"
using namespace std;

int main()
{
    int value;
    int x=0;
    const int n = 10;
    int arr[n];
    int b[n];

    cout << "Введите элементы массива: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;

    // Построение дерева из массива
    Node* root = buildTree(arr, 0, n - 1);

    // Вывод дерева
    cout << "Дерево: " << endl;
    printTree(root);
    cout << endl;

        while (x != 5)
        {
            cout << "Выберите операцию:\n" << " 1.Вставка элемента в дерево\n" << " 2.Поиск элемента\n" << " 3.Удаление элемента\n" << " 4.Обходы дерева\n" << " 5.Выйти\n";
            cin >> x;

            switch (x)
            {
            case 1:
            {
                cout << "Введите элемент: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Дерево: " << endl;
                printTree(root);
                cout << endl;
                break;
            }
            case 2:
            {
                int a;
                cout << "Введите элемент: ";
                cin >> a;
                cout << endl;
                search(root, a);
                break;
            }
            case 3:
            {
                int a;
                cout << "Введите элемент: ";
                cin >> a;
                cout << endl;
                root = deleteNode(root, a);
                printTree(root);
                cout << endl;
                break;
            }
            case 4:
            {
                cout << "Обход дерева в прямом порядке: ";
                preOrderTraversal(root);
                cout << endl;

                cout << "Обход дерева в симметричном порядке: ";
                inOrderTraversal(root);
                cout << endl;

                cout << "Обход дерева в обратном порядке: ";
                postOrderTraversal(root);
                cout << endl;
            }
            case 5:
            {
            default:;
            }
            }
            cout << endl;
        }

        void clearTree(Node * root);

    return 0;
}
