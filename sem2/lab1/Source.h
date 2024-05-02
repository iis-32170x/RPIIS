#pragma once
struct Drevo {
    int start; //индекс начала отрезка
    int end;   //индекс конца отрезка
    int sum;   //сумма элементов с start по end
    Drevo* left; //указатель на левого потомка
    Drevo* right; //указатель на правого потомка
};
Drevo* build_tree(int* , int , int );
void update(Drevo* , int , int , int );
int sum_on_range(Drevo* , int , int );
