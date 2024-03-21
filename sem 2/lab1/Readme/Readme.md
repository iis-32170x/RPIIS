# Лабараторная работа №1 

## Постановка задачи

1. Разработать библиотеку для работы со структурой данных, указанной в
индивидуальном задании, на любом императивнойм языке
программирования (Pascal, C\C++, Java, C#, Python и др.)
2. Разработать тестовую программу, которая демонстрирует
работоспособность реализованной библиотеки работы со структурой
данных.
3. Разработать систему тестов, которые продемонстрировали бы
работоспособность реализованной библиотеки. Система тестов должна
отвечать требованиям полноты, адекватности и непротиворечивости.
Система тестов должна учитывать не только корректную работу на
правильных данных, но и предусматривать корректное завершение
программы в случае некорректных данных.
4. По результатам выполнения задания составить отчет.

## Задание

### Вариант 18

Дек. Добавление элемента в начало или конец дека. Удаление
элемента из начала или конца дека.

### Ключевые понятия

`Библиотека C++ ` - это набор предопределенных классов, функций и переменных, которые расширяют функциональность языка программирования C++. Она предоставляет различные инструменты и ресурсы для разработки программного обеспечения, такие как ввод-вывод данных, работа с файлами, математические операции, обработка строк и т.д.


`Дек ` -(от англ. "deque", сокращение от double-ended queue) в программировании - это структура данных, которая представляет собой последовательность элементов, в которой можно добавлять и удалять элементы как с начала, так и с конца.
<img src="Deque.png">

`Google Test (или GTest)` - это фреймворк для модульного тестирования на языке программирования C++, разработанный компанией Google. Он предоставляет набор инструментов и функций для написания, организации и запуска автоматических тестов для проверки правильности работы кода.

**Основные операции**, поддерживаемые деком, включают:

Вставка в начало и конец дека: элементы могут быть добавлены как в начало, так и в конец дека. Это позволяет эффективно добавлять и удалять элементы с обоих концов.

Удаление с начала и конца дека: элементы могут быть удалены как с начала, так и с конца дека. Это позволяет эффективно удалять элементы с обоих концов.

## Реализация с примером тестовой программы
Тестовая программа представлена приложением по работе со струтурой дек.
```c++
#include <iostream>
#include "Header.h"
#include <ctime>
using namespace std;


int main(){
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
    Deque d;
    d.head = 0;
    d.tail = 0;
	int vybor; bool stop = 1; bool flag = 0;
    
	while (stop)
	{
		cout << "Выберете операцию:\n 1 - Создать дек \n 2 - Добавить элемент вперед\n 3 - Добавить элемент назад \n 4 - Удалить элемент с начала\n 5 - Удалить элемент с конца\n 6 - просмотр \n 0 - закончить выполнение \n";
		cin >> vybor;
		switch (vybor)
		{
		case(1):
		{
			if (!flag)
			{
				flag = 1;
				cout << "Дек создан" << endl;
			}
			else cout << "Дек уже создан"<< endl;
			break;
		}
		case(2):
		{
			if (flag)
			{
				for (int i = 0; i < 3; i++)
					push_front(&d, rand() % 100);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(3):
		{
			if (flag)
			{
				for (int i = 0; i < 3; i++)
					push_front(&d, rand() % 100);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(4):
		{
			if (flag)
			{
				pop_front(&d);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(5):
		{
			if (flag)
			{
				pop_back(&d);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(6):
		{
			if (flag)
			{
				printDeque(&d);
			}
			else cout << "Сперва создайте дек!\n\n";
			break;
		}
		case(0):
			stop = false;
		}
	}
	cout << "Программа завершена";
	return 1;
}
```
## Реализация заголовочного файла
В загаловочном файлем реализованы основные операции над деком:
1. `push_front` - добавление элемента в начало дека
2. `push_back` - добавление элемента в конец дека
3. `pop_front` - извлечение элемента с начала дека
4. `pop_back` - извлечение элемента с конца дека

А так же его просмотр содержимого стека.
`printDeque` - просмотр дека.
```c++
#pragma once
#include <iostream>
using namespace std;

const int max_elementov = 100;

struct Deque {
    int head, tail;
    int x[max_elementov];
};

void push_front(Deque* d, int value) {
    d->head = (d->head + (max_elementov - 1)) % max_elementov;
    d->x[d->head] = value;
}

void push_back(Deque* d, int value) {

    d->x[d->tail] = value;
    d->tail = (d->tail + 1) % max_elementov;
}

int pop_front(Deque* d) {
    int value = d->x[d->head];
    d->head = (d->head + 1) % max_elementov;
    return value;
}

int pop_back(Deque* d) {
    d->tail = (d->tail + (max_elementov - 1)) % max_elementov;
    int value = d->x[d->tail];
    return value;
}

void printDeque(Deque* d) {
    int i = d->head;
    while (i != d->tail) {
        cout << d->x[i] << " ";
        i = (i + 1) % max_elementov;
    }
    cout << endl;
}
```
## Тестирование
 Система тестов состоит из 5 тестов:

1. `DequeTest::PushBack:` - данный тест проверяет функцию push_back. 
2. `DequeTest::PushFront:`- этот тест проверяет функцию push_front. 
3. `DequeTest::PopFront:` - в данном тесте проверяется функция pop_front. 
4. `DequeTest::PopBack:` - этот тест проверяет функцию pop_back. 
5. `DequeTest::PrintDeque:` - данный тест проверяет функцию printDeque.

## Реализация системы тестов
 ```c++
TEST(DequeTest, PushBack) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);

    EXPECT_EQ(d.x[0], 10);
    EXPECT_EQ(d.x[1], 20);
    EXPECT_EQ(d.tail, 2);
}

TEST(DequeTest, PushFront) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_front(&d, 10);
    push_front(&d, 20);

    EXPECT_EQ(d.x[max_elementov - 1], 10);
    EXPECT_EQ(d.x[max_elementov - 2], 20);
    EXPECT_EQ(d.head, max_elementov - 2);
}

TEST(DequeTest, PopFront) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);
    push_back(&d, 30);

    int value = pop_front(&d);

    EXPECT_EQ(value, 10);
    EXPECT_EQ(d.head, 1);
}

TEST(DequeTest, PopBack) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);
    push_back(&d, 30);

    int value = pop_back(&d);

    EXPECT_EQ(value, 30);
    EXPECT_EQ(d.tail, 2);
}

TEST(DequeTest, PrintDeque) {
    Deque d;
    d.head = 0;
    d.tail = 0;

    push_back(&d, 10);
    push_back(&d, 20);
    push_back(&d, 30);

    testing::internal::CaptureStdout();
    printDeque(&d);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 20 30 \n");
}
 ```
## Все тесты прошли проверку - успешно.

<img src="test.png">

## Вывод
 
В результате выполнения данной работы были получены следующие практические навыки:
- изучены структура Дек и ее основные методы
- изучен фреймворк для тестирования программ Google Test
- изучены базовые знания для создания библиотек
