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
        cout << "1. Добавление элементов во множество" << endl;
        cout << "2. Удаление элемента из множества" << endl;
        cout << "3. Поиск элемента во множестве" << endl;
        cout << "4. Просмотр множества" << endl;
        cout << "5. Пересечение и объединение множеств" << endl;
        cout << "0. Выход из программы." << endl;
        cout << "Выберите пункт меню: ";
        while (!(cin >> choice)) {
            cout << "Ошибка. Введено нечисловое значение." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            int size;
            cout << "Введите количество добавляемых элементов: ";
            while (!(cin >> size)) {
                cout << "Ошибка. Введено нечисловое значение." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 1; i <= size; i++) {
                int element;
                cout << "Введите элемент " << set.size() + 1 << " множества: ";
                while (!(cin >> element)) {
                    cout << "Ошибка. Введено нечисловое значение." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                set.insert(element);
            }

            set.print();
        }
            break;
        case 2:
            int element;
            cout << "Введите элемент для удаления: ";
            while (!(cin >> element)) {
                cout << "Ошибка. Введено нечисловое значение." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (set.contains(element)) {
                set.remove(element);
                cout << "Элемент удалён"<<endl;
                set.print();
            }
            else {
                cout << "Элемент " << element << " не найден в множестве." << endl;
            }

            break;
        case 3:
            cout << "Введите элемент для поиска: ";
            while (!(cin >> element)) {
                cout << "Ошибка. Введено нечисловое значение." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (set.contains(element)) {
                cout << "Элемент " << element << " найден в множестве под номером " << set.contains2(element) + 1 << endl;
            }
            else {
                cout << "Элемент " << element << " не найден в множестве." << endl;
            }
          
            break;
        case 4:
            set.print();
            break;
        case 5: {
            MySet set1;
            MySet set2;

            int size1;
            cout << "Введите размер множества 1: ";
            while (!(cin >> size1)) {
                cout << "Ошибка. Введено нечисловое значение." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 0; i < size1; i++) {
                int element;
                cout << "Введите элемент " << i + 1 << " первого множества: ";
                while (!(cin >> element)) {
                    cout << "Ошибка. Введено нечисловое значение." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                set1.insert(element);
            }

            int size2;
            cout << "Введите размер множества 2: ";
            while (!(cin >> size2)) {
                cout << "Ошибка. Введено нечисловое значение." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 0; i < size2; i++) {
                int element;
                cout << "Введите элемент " << i + 1 << " второго множества: ";
                while (!(cin >> element)) {
                    cout << "Ошибка. Введено нечисловое значение." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
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