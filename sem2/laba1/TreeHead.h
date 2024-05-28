#pragma once
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class SegmentTree
{

public:

    struct segment
    {
        size_t tl;
        size_t tr;
    };
    vector<int> t;
    vector<int> a;

    void update(segment w, int new_val)
    {
        cout << "Базовый массив:" << endl;
        for (size_t i = 0; i < a.size(); i++)
        {
            cout << a.at(i) << " ";
        }
        cout << endl;
        vector<int> t(2 * a.size() - 1);
        builder(a, t, 0, 0, a.size() - 1);
        cout << "Построенное дерево:" << endl;
        for (size_t i = 0; i < t.size(); i++)
        {
            cout << "t[" << i << "]=" << t.at(i) << " ";
        }
        cout << endl;
        cout << "Изменяем отрезок с " << w.tl << " до " << w.tr << " на " << new_val << endl;
        w.tl = w.tl - 1;
        w.tr = w.tr - 1;
        change(0, a, t, w, new_val);
        cout << "Измененное дерево:" << endl;

        for (size_t i = 0; i < t.size(); i++)
        {
            cout << "t[" << i << "]=" << t.at(i) << " ";
        }
        cout << endl;

        cout << "Измененный массив:" << endl;

        for (int i = 0; i < a.size(); i++)
        {
            cout << a.at(i) << " ";
        }
        cout << endl;
    }

    void count(segment w, int countElement)
    {
        cout << "Базовый массив:" << endl;
        for (size_t i = 0; i < a.size(); i++)
        {
            cout << a.at(i) << " ";
        }
        cout << endl;
        vector<int> t(2 * a.size() - 1);
        builder(a, t, 0, 0, a.size() - 1);
        cout << "Построенное дерево:" << endl;
        for (size_t i = 0; i < t.size(); i++)
        {
            cout << "t[" << i << "]=" << t.at(i) << " ";
        }
        w.tl--;
        w.tr--;
        noun = 0;
        cout << endl;
        cout << "Количество элемента " << countElement << " на отрезке от " << w.tl + 1 << " до " << w.tr + 1 << " равно " << counter(0, a, t, w, countElement);
        cout << endl;
    }



private:

    void builder(vector<int>& a, vector<int>& t, int v, size_t tl, size_t tr) {
        if (tl == tr)
            t.at(v) = a.at(tl);
        else
        {
            size_t range_mid = (tl + tr) / 2;
            builder(a, t, v * 2 + 1, tl, range_mid);
            builder(a, t, v * 2 + 2, range_mid + 1, tr);
            t.at(v) = t.at(v * 2 + 1) + t.at(v * 2 + 2);
        }
    }

    void change(int v, vector<int>& a, vector<int>& t, segment w, int new_val)
    {

        if (w.tl == w.tr)
        {
            size_t number = -1;
            for (size_t i = t.size() / 2; i < t.size(); i++)
            {
                if (t.at(i) == a.at(w.tl)) number = i;
            }
            t.at(number) += new_val;
            a.at(w.tl) += new_val;
        }
        else {
            size_t tm = (w.tl + w.tr) / 2;
            segment z;
            z.tl = w.tl;
            z.tr = tm;
            change(v * 2 + 1, a, t, z, new_val);
            z.tl = tm + 1;
            z.tr = w.tr;
            change(v * 2 + 2, a, t, z, new_val);
            t.at(v) += t.at(2 * v + 1) + t.at(2 * v + 2);
        }
    }
    int noun;
    int counter(int v, vector<int>& a, vector<int>& t, segment w, int countElement)
    {

        if (w.tl == w.tr)
        {
            size_t number = -1;
            for (size_t i = t.size() / 2 - 1; i < t.size(); i++)
            {
                if (t.at(i) == a.at(w.tl)) number = i;
            }
            if (t.at(number) == countElement) noun++;
        }
        else
        {
            size_t tm = (w.tl + w.tr) / 2;
            segment z;
            z.tl = w.tl;
            z.tr = tm;
            counter(2 * v + 1, a, t, z, countElement);
            z.tl = tm + 1;
            z.tr = w.tr;
            counter(2 * v + 2, a, t, z, countElement);
            return noun;
        }
    }

};