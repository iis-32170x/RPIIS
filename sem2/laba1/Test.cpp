#include<iostream>
#include"Header.h"
#include <assert.h>
#include <cassert>


using namespace std;

void test2(const deque<char>& deq)
{
    deqqqq dq;

    assert(deq[0] == 's');
    cout << "Тест1 пройден успешно" << endl;
    

}
void test1(const deque<char>& deq){

assert(deq.size() >= 1);
cout << "Test1 complete" << endl;
}

void test3(const deque<char>& deq)
{
    deqqqq dq;


    assert(deq[1] == 'a' || 'A');
    cout << "Тест3 пройден успешно" << endl;


}


int main() {

	setlocale(LC_ALL, "RU");


    
    int n;
    cout << " Введите размер дека: ";
    cin >> n;

    while (n < 0) {
        
            cout << "Eще раз: ";
            cin >> n;
        
    }



    deque<char> deq(n);

    test1(deq);


    if (!deq.empty()) {

        cout << " Введите элементы дека:\n";

        for (int i = 0; i < n; i++) {
            cin >> deq[i];
        }



        cout << " Введённый дек: ";
        for (int i = 0; i < n; i++) {
            cout << deq[i] << ' ';
        }

        cout << endl;

        test2(deq);


        deqqqq operations;




        char choice;
        do {
            char num;
            cout << "Выберите операцию:\n"
                << "Добавление элементов в начало дека ----- 1\n"
                << "Удаление элементов с начала дека    ----- 2\n"
                << "Добавление элементов в конец дека  ----- 3\n"
                << "Удаление элементов с конца дека     ----- 4\n";
            cin >> num;

            switch (num) {



                // Первый кейс 

            case '1':

                operations.addElfront(deq);
                break;

                // Второй кейс 

            case '2':


                operations.DelElfront(deq);
                break;



                // Третий кейс 

            case '3':

                operations.addElback(deq);
                break;



                // Четвертый кейс    

            case '4':

                operations.DelElback(deq);
                break;


            }

            cout << endl << "Желаете продолжить? (1 - да  |  0 - нет): ";
            cin >> choice;

            if (choice != '1' && choice != '0') {

                cout << "Включите встроенный интеллект и введите нормально число: ";
                cin >> choice;
               

            }

            test3(deq);



        } while (choice == '1' && choice != '0');

        


    }


    else {
        cout << " Дек пустой ";
    }


	return 0;
}
