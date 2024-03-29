#include <iostream>
#include "symm_diff.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    Set MultiSet[123];
    string path = "abobik.txt";

    Do_Symm_Diff(MultiSet, path);

    return 0;
}

