#include"TreeHead.h"

void testUpdate1()
{
    setlocale(LC_ALL, "Russian");
    SegmentTree objekt1; objekt1.a = { 1,2,3,4,5,6,7 };
    SegmentTree::segment q;
    q.tl = 3;
    q.tr = 6;
    objekt1.update(q, 0);
    cout << endl;

}
void testUpdate2()
{
    setlocale(LC_ALL, "Russian");
    SegmentTree objekt1;
    objekt1.a = { 1,2,3,4,5,6,7,8,9 };
    SegmentTree::segment q;
    q.tl = 5;
    q.tr = 8;
    objekt1.update(q, 1);
    cout << endl;

}
void testUpdate3()
{
    setlocale(LC_ALL, "Russian");
    SegmentTree objekt1;
    objekt1.a = { 1,2,3,4 };
    SegmentTree::segment q;
    q.tl = 1;
    q.tr = 2;
    objekt1.update(q, 10);
    cout << endl;

}

void testCount1()
{
    setlocale(LC_ALL, "Russian");
    SegmentTree objekt2;
    SegmentTree::segment q;
    objekt2.a = { 1,8,2,3,3,4,3,5 };
    q.tl = 1;
    q.tr = 5;
    objekt2.update(q, 1);
    SegmentTree::segment s;
    s.tl = 3;
    s.tr = 7;
    objekt2.count(s, 3);
    cout << endl;

}
void testCount2()
{
    setlocale(LC_ALL, "Russian");
    SegmentTree objekt2;
    objekt2.a = { 0,0,1,0 };
    SegmentTree::segment s;
    s.tl = 2;
    s.tr = 4;
    objekt2.count(s, 0);
    cout << endl;

}
void testCount3()
{
    setlocale(LC_ALL, "Russian");
    SegmentTree objekt2;
    objekt2.a = { 8,3,3,6,9 };
    SegmentTree::segment s;
    s.tl = 1;
    s.tr = 4;
    objekt2.count(s, 9);
    cout << endl;
}
int main()
{
    testUpdate1();
    testUpdate2();
    testUpdate3();
    testCount1();
    testCount2();
    testCount3();
}