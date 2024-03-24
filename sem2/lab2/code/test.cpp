#include "myset.h"
int main()
{
    setlocale(LC_ALL, "RU");
    Node<string>* rootA = nullptr;
    Node<string>* rootB = nullptr;
    Node<string>* rootC = nullptr;

    string path1;
    string path2;
    while (true)
    {
        int choose;
        
        cout << "1.- Добавить элементы в первое множество из файла 1.\n" <<
            "2.-Добавить элементы во второе множество из файла 2.\n" <<
            "3.- Симметрическая разность множеств.\n" <<
             endl;
        cin >> choose;
        if (!choose)
        {
           return -1;
        }
        switch (choose) {
        case 1:
            cout << "введите путь к файлу 1: ";
            cin >> path1;
            addFromFile(rootA, path1);
            displaySet(rootA);
            cout << endl;
            break;
        case 2:

            cout << "введите путь к файлу 2: ";
            cin >> path2;
            addFromFile(rootB, path2);
            displaySet(rootB);
            cout << endl;
            break;

        case 3:
            if ((getSize(rootA) == 0 or getSize(rootB) == 0))
            {
                cout << "Нужно создать множество(а)";
                cout << endl;
                break;
            }
            rootC = symmetricDifference(rootA, rootB);
            displaySet(rootC);
            cout << endl;
        
        default:
            break;
        }

    }

    return 0;
}
