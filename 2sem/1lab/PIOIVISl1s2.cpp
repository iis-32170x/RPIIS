// PIOIVIS_lab1sem2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "queue.h"
#include <fstream>

using namespace std;


int main()
{


 
     
     

    queue* a= new queue;
    a->qh = 0;
    a->qt = 0;
    int inf, maxn = 100, choice = 0;

    ifstream fr;

    while (true) {
        cout << "Menu:\n1. Add element\n2. Extract element\n3. Cout queue \n4. Exit\n5. From file\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to add: ";
            cin >> inf;
            enq(a, inf, maxn);

            break;
        case 2:
            if (a->qh != a->qt)
                cout << deq(a, maxn)<< "\n";
            else cout << "queue is empty\n";
            break;
        case 3:
            if (a->qh != a->qt) {
                for (int j = a->qh; j < a->qt; j++)
                    cout << a->val[j] << "  ";
                cout << "\n";
            }
            else cout << "queue is empty\n";
            break;
        case 4:

            return 0;
        case 5:
            int ch;
            cout << "Choose a file:\n1. 1.txt\n2. 2.txt\n3. 3.txt\n4. 4.txt\n";
            cin >> ch;
            
            
            switch (ch) {
            case 1:
                fr.open("1.txt");
                break;
            case 2:
                fr.open("2.txt");
                break;
            case 3:
                fr.open("3.txt");
                break; 
            case 4:
                    fr.open("4.txt");
                    break;
            default:
                cout << "Invalid choice!\n";
            }
            int n,k;
            char w;
            char b;
            fr >>n;
           
            for (int i = 0; i < n; i++) {
                fr>>k;
                enq(a, k, maxn);
            }
            fr>>n ;
            for (int i = 0; i < n; i++) {
                deq(a, maxn);
            }
            fr.close();

            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 