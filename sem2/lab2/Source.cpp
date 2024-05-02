#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    vector <string> sets;
    sets = SetRecord("in.txt");
    Start(sets);

}