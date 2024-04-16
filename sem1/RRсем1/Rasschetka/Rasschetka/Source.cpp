
#include <iostream>
#include <math.h> 
#include <fstream>
#include <vector>
using namespace std;
/*void opredelenie(int** graf, int versh, int rebra)//определяем ребра графа и их вес
{
    int v1, v2, ves;
    for (int i = 0; i < rebra; ++i)//реализуем матрицу смежности,но если ребро существует мы присваеваем элементу матрицы значение веса ребра
    {
        cout << "Введите номера вершин,между которыми есть ребро";
        while (!(cin >> v1) || (cin.peek() != '\n') || (v1 > versh) || (v1 <= 0))//проверка на ввод нечислового значения и вершины которой не существует;
        {
            if (v1 > versh) cout << "Такой вершины не существует\n";
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Неправильный тип данных, введите снова" << endl;
        }
        while (!(cin >> v2) || (cin.peek() != '\n') || (v2 > versh) || (v2 <= 0))
        {
            if (v2 > versh) cout << "Такой вершины не существует\n";
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Неправильный тип данных, введите снова" << endl;
        }
        --v1;//нумерация ребер и элементов массива не совпадает
        --v2;
        cout << "Введите 'вес' ребра\n";
        while (!(cin >> ves) || (cin.peek() != '\n') || (ves < 0))
        {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Неправильный тип данных, введите снова" << endl;
        }
        if ((ves > graf[v1][v2]) || (ves > graf[v2][v1]))//если есть несколько кратных ребер,то мы берем только ребро с наибольшим весом.
        {
            graf[v1][v2] = ves;
            graf[v2][v1] = ves;
        }
    }
}
*/
int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
    return (row * numberOfColumnsInArray) + col;
}
void rasschet(int** graf, int versh, int reb)
{
    int count, cvikl, prov, max, i1, j1, v,fix;
    int schet = 0;
    i1 = 2 * versh;
    j1 = 2 * versh;
    v = 0;
    int* dist = new int[10 * reb];
    int* kraska = new int[versh];
    bool* kraska2 = new bool[versh];
    for (int r = 0; r < 10 * reb; ++r)
    {
        for (int i = 0; i < versh; ++i)
            kraska[i] = 0;
        for (int i = 0; i < versh; ++i)
            kraska2[i] = 0;
        count = 0;
        prov = 0;
        cvikl = 0;
        dist[r] = 0;
        fix = 0;
        for (int i = v; i < versh; ++i)
        {
            if (kraska[v] % 2 == 1)//Обрабатываем случай если граф приходит в вершину номер 1
            {
                for (int j = 0; j < versh; ++j)
                    if ((graf[v][j] > 0) && (j != i1) && (v != j))
                    {
                        if ((kraska[v] == 3) && (kraska[j] == 2))
                        {
                            ++schet;
                            continue;
                        }
                        ++cvikl;
                        dist[r] += graf[v][j];
                        i1 = v;
                        j1 = j;
                        kraska[v] += 1;//красим точки
                        kraska[j] += 1;
                        schet = 0;//для избежания выхода из цикла
                        i = j;
                        break;
                    }
                    else ++schet;
                if (schet == versh) break;
                schet = 0;
            }
            if (i > v)
            {
                if (kraska[i] % 2 == 1)
                {
                    ++schet;
                    if (schet == 2) break;
                }
                if (kraska[i] % 2 == 0) continue;
            }
            for (int j = 0; j < versh; ++j)
            {
                for (int m = 0; m < versh; ++m)//ищем петли
                {
                    if (graf[m][i] > 0 && m == i && (kraska2[m] != 1))
                    {
                        ++cvikl;
                        dist[r] += graf[m][m];
                        kraska2[m] = 1;
                    }
                }
                if ((graf[i][j] > 0) && ((i != j1) || (j != i1)) && (i != j))//избегаем зачета одного ребра 2 раза 
                {
                    if ((kraska[i]==3)&&(kraska[j]==2)) continue;
                    ++cvikl;
                    dist[r] += graf[i][j];
                    i1 = i;
                    j1 = j;
                    kraska[i] += 1;//красим точки
                    kraska[j] += 1;
                    schet = 0;//для избежания выхода из цикла
                    i = v;
                    break;
                }
            }
            if (fix == 0)
            {
                kraska[v] += 1;
                ++fix;
            }
        }
        fix = 0;
        schet = 0;
        for (int i = 0; i < versh; ++i)
            kraska[i] = 0;
        for (int i = 0; i < versh; ++i)
            kraska2[i] = 0;
        for (int i = v; i < versh; ++i)
        {
            if (kraska[v] % 2 == 1)//Обрабатываем случай если граф приходит в вершину номер 1
            {
                for (int j = 0; j < versh; ++j)
                    if ((graf[v][j] > 0) && (j != i1) && (v != j))
                    {
                        if ((kraska[v] == 3) && (kraska[j] == 2))
                        {
                            ++schet;
                            continue;
                        }
                        ++prov;
                        if (prov == cvikl) graf[v][j] = 0;
                        i1 = v;
                        j1 = j;
                        kraska[v] += 1;//красим точки
                        kraska[j] += 1;
                        schet = 0;//для избежания выхода из цикла
                        i = j;
                        break;
                    }
                    else ++schet;
                if (schet == versh) break;//Для выхода из цикла
                schet = 0;
            }
            if (i > v)
            {
                if (kraska[i] % 2 == 1)
                {
                    ++schet;
                    if (schet == 2) break;
                }
                if (kraska[i] % 2 == 0) continue;
            }
            for (int j = 0; j < versh; ++j)
            {
                for (int m = 0; m < versh; ++m)//ищем петли
                {
                    if (graf[m][i] > 0 && m == i && (kraska2[m] != 1))
                    {
                        ++prov;
                        if (prov == cvikl) graf[m][m] = 0;
                        kraska2[m] = 1;
                        ++count;
                    }
                }

                if ((graf[i][j] > 0) && ((i != j1) || (j != i1)) && (i != j))//избегаем зачета одного ребра 2 раза 
                {
                    if ((kraska[i] == 3) && (kraska[j] == 2)) continue;
                    ++prov;
                    if (prov == cvikl)
                    {
                        graf[i][j] = 0;
                        graf[j][i] = 0;
                    }
                    i1 = i;
                    j1 = j;
                    kraska[i] += 1;//красим точки
                    kraska[j] += 1;
                    schet = 0;//для избежания выхода из цикла
                    i = v;
                    ++count;
                    break;
                }
            }
            if (fix == 0)
            {
                kraska[v] += 1;
                ++fix;
            }  
            if (prov == cvikl) break;
        }
        schet = 0;
        if (count == 0) ++v;
    }
    //Сравниваем пути
    max = dist[0];
    for (int i = 0; i < 10 * reb; ++i)
        if (dist[i] > max) max = dist[i];
    cout << "Максимальный путь между заданными вершинами:" << max << endl;
    delete[] dist;
    delete[] kraska;
    delete[] kraska2;
}
int main()
{
    setlocale(LC_ALL, "Russian");//Вводим русский
    int versh, rebra, a, ves;
    rebra = 0;
    /*cout << "Введите количество вершин графа\n";
    while (!(cin >> versh) || (cin.peek() != '\n'))//проверка на ввод нечислового значения
    {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Неправильный тип данных, введите снова" << endl;
    }
    cout << "Введите количество ребер графа\n";
    while (!(cin >> rebra) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Неправильный тип данных, введите снова" << endl;
    }
    int** graf = new int* [versh];//создаем матрицу
    for (int i = 0; i < versh; ++i)
        graf[i] = new int[versh];
    for (int i = 0; i < versh; ++i)//присваеваем всем элементам матрицы значение 0;нужно для сравнения в ф.opredelenie
        for (int j = 0; j < versh; ++j)
            graf[i][j] = 0;
    opredelenie(graf, versh, rebra);
    */
    vector<bool> array;
    ifstream matrix;
    matrix.open("matrixinfile.txt");
    if (!matrix.is_open())
        cout << "Ошибка открытия файла\n";
    else cout << "Файл открыт\n";
    while (!matrix.eof())
    {
        matrix >> a;
        array.push_back(a);
    }
    versh = sqrt(array.size());
    int** graf = new int* [versh];
    for (int i = 0; i < versh; ++i)
        graf[i] = new int[versh];
    for (int i = 0; i < versh; ++i)
        for (int j = 0; j < versh; ++j)
            graf[i][j] = array[getSingleIndex(i, j, versh)];
    for (int i = 0; i < versh; ++i)
        for (int j = 0; j < versh; ++j)
            if (graf[i][j] == 1)
            {
                cout << "Введите вес ребра между ребрами" << i + 1 << " и " << j + 1 << endl;
                while (!(cin >> ves) || (cin.peek() != '\n') || (ves < 0))
                {
                    cin.clear();
                    cin.ignore(99999, '\n');
                    cout << "Неправильный тип данных, введите снова" << endl;
                }
                graf[i][j] = ves;
                graf[j][i] = ves;
                ++rebra;
            }
    rasschet(graf, versh, rebra);
    for (int count = 0; count < versh; ++count)
        delete[] graf[count];
    delete[] graf;
}