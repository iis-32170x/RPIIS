#ifndef MASIVV_H
#define MASIVV_H
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Masiv{
public:
    Masiv(int SIZE);
    ~Masiv();
    Masiv(Masiv &other);

    void mkmas(int OT, int DO);
    void Sort(bool napravlen);
    void PushInSort(int x);
    int SearchInSort(int x);
    void UnionSort(Masiv arr1, Masiv arr2);

    int SizeG();
    bool SortG();
    int ElementG(int nomer);
    bool NAPRAVLENG();
    void ShowProperties();
    void ShowMas();

private:
    int size;
    int *mas;
    bool sort{false}, NAPRAVLEN;
    int search(int x);

};

class Masiv2{
public:
    Masiv2(int n, int m);
    ~Masiv2();
    Masiv2(Masiv2 &other);

    void mkmas(int OT, int DO);
    void Sort(bool key, int nomerkey, bool napravlen);
    void PushInSort(Masiv arr);
    int SearchInSort(int x);
    void UnionSort(Masiv2 arr1, Masiv2 arr2);
    void IntersectionSort(Masiv2 arr1, Masiv2 arr2);

    int SizeNG();
    int SizeMG();
    bool SortG();
    bool KEYG();
    bool NAPRAVLENG();
    int NOMERKEYG();
    int ElementG(int nomerN, int nomerM);
    void ShowProperties();
    void ShowMas();

private:
    int sizeN;
    int sizeM;
    int **mas;
    bool sort{false}, KEY, NAPRAVLEN;
    int NOMERKEY;
    void PuzirSortSTR(int nomerkey, bool napravlen);
    void PuzirSortSTO(int nomerkey, bool napravlen);
    int search(int x);

};

class Time{
public:
    Time();
};
#endif