#include <iostream>
#include "Set.h"

using namespace std;
//Множество. Добавление элемента во множество. Удаление элемента из
//множества.Поиск элемента во множестве.Объединение двух
//множеств.Пересечение двух множеств.
int main() {
    setlocale(LC_ALL, "RU");
    MySet set;

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Создание нового множества" << endl;
        cout << "2. Добавление элемента во множество" << endl;
        cout << "3. Удаление элемента из множества" << endl;
        cout << "4. Поиск элемента во множестве" << endl;
        cout << "5. Просмотр множества" << endl;
        cout << "6. Пересечение и объединение множеств" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int size;
            cout << "Введите размер множества: ";
            cin >> size;

            for (int i = 0; i < size; i++) {
                int element;
                cout << "Введите элемент " << i + 1 << " множетсва: ";
                cin >> element;
                set.insert(element);
            }
            set.print();

            break;
        case 2:
            int element;
            cout << "Введите элемент : ";
            cin >> element;
            set.insert(element);
            set.print();
            
            break;
        case 3:
            cout << "Введите элемент для поиска: ";
            cin >> element;
            if (set.contains(element)) {
                set.remove(element);
                cout << "Элемент удалён";
                set.print();
            }
            else {
                cout << "Элемент " << element << " не найден в множестве." << endl;
            }

            break;
        case 4:
            cout << "Введите элемент для поиска: ";
            cin >> element;

            if (set.contains(element)) {
                cout << "Элемент " << element << " найден в множестве." << endl;
            }
            else {
                cout << "Элемент " << element << " не найден в множестве." << endl;
            }
          
            break;
        case 5:
            set.print();
            break;
        case 6: {
            MySet set1;
            MySet set2;

            int size1;
            cout << "Введите размер множества 1: ";
            cin >> size1;

            for (int i = 0; i < size1; i++) {
                int element;
                cout << "Введите элемент " << i + 1 << " первого множества: ";
                cin >> element;
                set1.insert(element);
            }

            int size2;
            cout << "Введите размер множества 2: ";
            cin >> size2;

            for (int i = 0; i < size2; i++) {
                int element;
                cout << "Введите элемент " << i + 1 << " второго множества: ";
                cin >> element;
                set2.insert(element);
            }

            MySet intersectionSet = set1.intersection(set2);
            cout << "Пересечение множеств: ";
            intersectionSet.print();

            MySet unionSet = set1.unionWith(set2);
            cout << "Обьединение множеств: ";
            unionSet.print();
        }
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный пункт меню. Попробуйте еще раз." << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}