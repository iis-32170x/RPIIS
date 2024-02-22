#include <iostream>
#include "myset.h"

int main() {
    mySet<char> a, b, c;

    a.add('a');
    a.add('b');
//    a.add('c');
//    a.add('d');
//    a.add('2');

    printSet(a);




    auto d = boolean(a);


    printSet(d);
    printSet(boolean(d));


//    for (int i = 0; i < d.getSize(); i += 1) {
//        d.printSet();
//    }


    b.add('a');
    b.add('b');
    b.add('c');
    b.add('e');
    b.add('1');


    printSet(b);
    b += a;
    printSet(b);


    std::cout << a.getSize() << ' ' << b.getSize() << ' ' << (a < b) << '\n';


    c = a +  b;
    printSet(c);


    c.del('d');
    c.del('d');
    c.del('b');
    c.del('b');
    c.del('g');
    c.del('e');

    printSet(c);

    std::cout << '\n';



    c = intersection(a, b);     printSet(c);



    printSet(a);
    printSet(b);


    printSet(combining(a, b));

    std::cout << '\n';



    c = a;

    printSet(c);


//    c += b;

    printSet(c);


    std::cout << '\n';


    printSet(intersection(a, b));


//    std::cout << a[10] << '\n';

    mySet<int> seettt;
    seettt.add(0);
    seettt.add(1);
    seettt.add(2);
    seettt.add(3);
    seettt.add(4);
    seettt.add(5);
    seettt.add(6);
    seettt.add(7);
    seettt.add(8);
    seettt.add(9);
    seettt.add(10);
    seettt.add(12);
    seettt.add(11);


    printSet(seettt);


    seettt = seettt + 13;
    seettt += 14;


    printSet(seettt);


    seettt = seettt - 0;
    seettt -= 1;
    printSet(seettt);




//    mySet<mySet<int>> obj1;
//    mySet<int> obj2;
//    std::cout << std::is_same<decltype(obj1), decltype(obj2)>::value << '\n';


//    std::cout << typeid(a).name()<< '\n';
//    std::cout << typeid(d).name();

    return 0;
}
