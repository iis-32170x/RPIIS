#include "..\Tree\TreeHead.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");

    FenwickTree Test(6);
    Test.array = { 1,2,3,4,5,6 };
    Test.CreateTree();

    cout << "Тест поиска суммы чисел на отрезке массива:" << "\n";
    cout << Test.Sum(0, 5) << "\n";
    cout << Test.Sum(0, 0) << "\n";
    cout << Test.Sum(1, 2) << "\n";
    cout << Test.Sum(4, 5) << "\n";

    cout << "Тест обновления числа в массиве:" << "\n";
    Test.Update(0, 1);
    cout << Test.Sum(0, 0) << "\n";
    Test.Update(1, 2);
    cout << Test.Sum(1, 1) << "\n";
    Test.Update(2, 3);
    cout << Test.Sum(0, 2) << "\n";
    Test.Update(3, 6);
    cout << Test.Sum(2, 3) << "\n";
    Test.Update(4, 5);
    cout << Test.Sum(0, 4) << "\n";

}
