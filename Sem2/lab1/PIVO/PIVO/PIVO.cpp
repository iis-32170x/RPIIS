
#include "Header.h"
int main()
{
    setlocale(LC_ALL, "ru");
    make_set(2);
    make_set(4);
    make_set(7);
    make_set(3);
        union_sets(7,4);
        union_sets(3, 4);
        union_sets(14, 3);
        cout << find_set(2);
        cout << find_set(4);
        cout << find_set(7);
        cout << find_set(3);
        
    make_set(101);
}
