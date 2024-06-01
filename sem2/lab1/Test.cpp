#include <iostream>
#include "..\LabaP1\Header.h";
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size = 0;
    int capacity = 5;
    int* Dek = new int[capacity];
    int a, b;
    a = 0;

    while (a < 6) {
        cout << "1.Добавить в начало, 2.Добавить в конец, 3.Удалить элемент с начала, 4. Удалить элемент с конца, 5.Показать дек, 6.Завершить:" << endl;
        cin >> a;

        switch (a) {
        case 1:
            cin >> b;
            addFront(Dek, size, capacity, b);
            break;
        case 2:
            cin >> b;
            addBack(Dek, size, capacity, b);
            break;
        case 3:
            delfront(Dek, size);
            if (size <= 0) {
                cout << "Дек и так пуст" << endl;
                
            }
            break;
        case 4:
            delback(Dek, size);
            if (size <= 0) {
                cout << "Дек и так пуст" << endl;

            }
            break;
        case 5:
            if (size == 0) {
                cout << "Дек пуст" << endl;
            }
            for (int i = 0; i < size; i++) {
                cout << Dek[i] << " ";
            }
            cout << endl;
            break;
        }
    }

    delete[] Dek;
    return 0;
}
