#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;



int main() {
    setlocale(LC_ALL, "Russian");
    Mnozh MultMn[100];
    string path = "myfile.txt";
    ReadFile(MultMn, path);



    return 0;
}