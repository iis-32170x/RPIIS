#include "Header.h"
#include<iostream>

void deqqqq::addElfront(deque<char>& deq)
{
    
    int n;
    cout << "Введите количество элементов для добавления в начало: " << endl;
    cin >> n;

    char x;
    cout << endl << "Введите элементы для добавления в начало дека : ";

    for (int i = 0; i < n; i++) {
        cin >> x;

        deq.resize(deq.size() + 1); // Увеличиваем размер контейнера на 1
        for (size_t j = deq.size() - 1; j > 0; j--) {
            deq[j] = deq[j - 1]; // Сдвигаем элементы вправо
        }
        deq[0] = x; // Вставляем новый элемент в начало
    }

    cout << endl << "Дек после добавления элементов в начало: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }

}



void deqqqq::DelElfront(deque<char>& deq)
{
 
   
    
    cout << "Введите  количество элементов для удаления с начала: ";
    int k;
    cin >> k;

    if (k > deq.size()) {
        cout << "Операция не возможна" << endl << "Введите значение заново: ";
        cin >> k;
    } 
    
   

        for (int i = 0; i < k; i++) {
            for (size_t i = 0; i < deq.size() - 1; i++) {
                deq[i] = deq[i + 1]; // Сдвигаем элементы влево 
            }
            deq.resize(deq.size() - 1); // Уменьшаем размер контейнера на 1 
        

    }


    cout << endl << "Дек после удаления элементов с начала: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }

}



void deqqqq::addElback(deque<char>& deq)
{

    int n;
    cout << "Введите количество элементов для добавления в конец дека: " << endl;
    cin >> n;

    cout << endl << "Введите элементы для добавления в конец дека : ";
    char z;
     for(int i = 0; i < n; i++) {
         cin >> z;
        deq.resize(deq.size() + 1); // Увеличиваем размер дека на 1 
        deq[deq.size() - 1] = z; // Вставляем новый элемент в конец дека 
    }

    cout << endl << "Дек после добавления элементов в конец: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }
}



void deqqqq::DelElback(deque<char>& deq)
{
    cout << "Введите  количество элементов для удаления с конца: ";
    int v;
    cin >> v;

    if (deq.size() < v) {

        cout << "Операция невозможна"<< endl << "Введите значение заново: ";
        cin >> v;
    }

    for (int i = 0; i < v; i++) {
        deq.resize(deq.size() - 1); // Уменьшаем размер контейнера на 1 

    }

    cout << endl << "Дек после удаления элементов с конца: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }

}

