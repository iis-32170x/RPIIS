#pragma once
#include <iostream>
#include <string>
#include <fstream>
struct Mnozh {
    struct elem {
        int kratn = 1;
        std::string el;
        int razm = 0;
        bool NeorMN = false;
    };
    elem El[100];
    int MoshMn = 1;
    int KolMnoz;
    int KolSkob;
    int KolSkobKort;
};

bool ReadFile1(Mnozh MultMn[], std::string path); //для проверки на корректность ввода
void SortMnozh(Mnozh MultMn[]);
void ViewMnozh(Mnozh MultMn[]);
Mnozh SimRaznNM(Mnozh MultMn[]);
Mnozh ReadFile(Mnozh MultMn[], std::string path);