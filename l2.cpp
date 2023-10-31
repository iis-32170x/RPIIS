#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    float x, y, f, a, s, b;
    int k;
    cout << "Введите Х: \n";
    cin >> x;
    cout << "Введите Y: \n";
    cin >> y;
    cout << "Введите B: \n";
    cin >> b;
    cout << "Выберите вид функции:\n 1 - sh(x)\n 2 - x^2\n 3 - exp(x)\n";
    cin >> k;

    switch (k)
    {
    case 1: f = sinh(x); cout << "Выбрана функция sh(x)"; break;
    case 2: f = pow(x, 2); cout << "Выбрана функция x^2"; break;
    case 3: f = exp(x); cout << "Выбрана функция exp(x)"; break;
    default: cout << "Функция не выбрана";
        return 1;
    }

    a = x * b;
    if (a > 1 && a < 10)
    {
        cout << "\nБыла выбрана первая ветвь вычислений";
        s = exp(k);
    }
    else if (a > 12 && a < 40)
    {
        cout << "\nБыла выбрана вторая ветвь вычислений";
        float sum = fabs(f + 4 * y);
        s = pow(sum, 1 / 3.0);
    }
    else
    {
        cout << "\nБыла выбрана третья ветвь вычислений";
        s = y * pow(f, 2);
    }
    cout << "\nВаш результат: " << s;
    return 0;
}
+