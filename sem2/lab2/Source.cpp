#include "Header.h"
#include "Header.h"
int main() {
    setlocale(LC_ALL, "RU");
    Set generator;
    string set;
    getline(cin, set);
    generator.readSet(set);
    generator.genSet();
    return 0;
}
