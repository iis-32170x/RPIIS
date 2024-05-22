#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

struct Array // структура, описывающая множество
{
    string Type,Str;
    int ElementsNum;
    vector<Array*> SubsetItems; 

    Array(string type, int numberOfItems, string str); // конструктор с параметрами
};

Array* ArrayCreation(string str); // Создаём множество из строки
bool InSubset(Array* arr1, Array* arr2); // определяем является ли arr1 подмножеством arr2 (равенство для кортежей)
bool IsCorrect(string str); // проверка на правильность введённой строки
void GetResult(Array* arr1, Array* arr2); // Получение результата
void Remove(Array* arr); // Очистка множества