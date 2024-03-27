



















































```c++
#pragma once
struct stack;
void create(stack*& begin, stack*& end, int value);
void add(stack*& b, stack*& e, int value);
void view(stack* p);
void del(stack*& p);
void delStack(stack** p);
void ftext();
```

```c++
  #include <iostream>
#include <conio.h>
#include "Header.h"
using namespace std;

int main()
{
    int value;
    stack* begin = NULL;
    stack* end = NULL;

    while (true)
    {
        ftext();
        switch (_getch())
        {
        case '1':
            cout << "first element value\n";
            cin >> value;
            create(begin, end, value);
            break;

        case '2':
            cout << "Num elements?" << endl;
            int k;
            cin >> k;
            cout << "\nElement?\n";
            for (int i = 0; i < k; i++)
            {
                cin >> value;
                add(begin, end, value);
            }
            break;
        case '3':
            del(begin);
            break;
        case '4':
            if (!begin == NULL)
            {
                view(begin);
                cout << endl;

            }
            else
            {
                cout << "\nClean\n";
            }
            break;
        case '5':
            delStack(&begin);
            break;
        case '6':
            exit(0);
            break;
        }
        system("pause");
        system("cls");

    }
    return 0;
}

```

```c++
  #include <iostream>
#include <conio.h>

using namespace std;

struct stack
{
    int data;
    stack* next;
    stack* prev;
};

void create(stack*& begin, stack*& end, int value)
{
    stack* t = new stack;
    t->data = value;
    t->next = end;
    t->prev = begin;
    begin = end = t;
}

void add(stack*& b, stack*& e, int value)
{
    stack* t = new stack;
    t->data = value;
    t->next = NULL;
    t->prev = e;
    e->next = t;
    e = t;
}

void view(stack* p)
{
    stack* t = p;
    while (t != NULL)
    {
        cout << t->data << endl;
        t = t->next;
    }
    cout << endl;
}

void del(stack*& p)
{
    stack* del = p;
    p = p->next;
    delete del;

}

void delStack(stack** p)
{
    stack* t;
    while (*p != NULL)
    {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}

void ftext()
{
    cout << "1-to create queue\n";
    cout << "2-to add elements\n";
    cout << "3-to delete first element\n";
    cout << "4-to see queue\n";
    cout << "5-to clean queue\n";
    cout << "6-to close programm\n";
}
```
