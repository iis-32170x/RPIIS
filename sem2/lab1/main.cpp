#include <iostream>
#include "mySet.h"

int main() {
    mySet<char> a, b, c;

//    a.add('a'); a.add('b'); a.add('c');  
    a.add('d'); a.add('2');
    printSet(a);

    auto d = boolean(a);
    printSet(d);
    printSet(boolean(d));


    b.add('a'); b.add('b'); b.add('c'); b.add('e'); b.add('1');

    printSet(b);
    b += a;
    printSet(b);

    std::cout << a.getSize() << ' ' << b.getSize() << ' ' << (a < b) << '\n';

    c = a + b;
    printSet(c);

    c.del('d'); c.del('d'); c.del('b'); c.del('b'); c.del('g'); c.del('e');
    printSet(c);
    std::cout << '\n';

    c = intersection(a, b); printSet(c);

    printSet(combining(a, b));
    std::cout << '\n';

    c = a; printSet(c);

    c += b; printSet(c);

    printSet(intersection(a, b));

    mySet<int> s;
    s.add(0); s.add(1); s.add(2); s.add(3); s.add(4); s.add(5); s.add(6);
    s.add(7); s.add(8); s.add(9); s.add(10); s.add(12); s.add(11);
    printSet(s);

    s = s + 13; s += 14; printSet(s);

    s = s - 0; s -= 1;
    std::cout << s << '\n';

    return 0;
}