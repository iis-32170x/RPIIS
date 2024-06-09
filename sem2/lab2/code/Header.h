#include <iostream>
#include <string>
#include <fstream>
struct Mnozh {
    struct elem {
        int kratn = 1;
        std::string el;
        int razm = 0;
        bool NeorMN = false;
        bool ProverkaNa1 = false;
    };
    elem El[100];
    int MoshMn = 1;
    int KolMnoz;
    int KolSkob;
    int KolSkobKort;
};


void SortMnozh(Mnozh MultMn[]);
void ViewMnozh(Mnozh MultMn[]);
void SimRaznNM(Mnozh MultMn[]);
void ReadFile(Mnozh MultMn[], std::string path);
