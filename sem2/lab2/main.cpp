#include <iostream>
#include "myset.h"

int main() {
    mySet<char> a, b, c;

//    a.add('a'); a.add('b'); a.add('c');  
    a.add('d'); a.add('2');
    printSet(a);

    auto d = boolean(a);
    printSet(d);
    printSet(boolean(d));

    return 0;
}