#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ifstream file1("input_A.txt");
    ifstream file2("input_B.txt");

    if (!file1.is_open() || !file2.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 0;
    }

    string setString1, setString2;
    getline(file1, setString1);
    getline(file2, setString2);

    file1.close();
    file2.close();

    vector<string> set1, set2;
    set1 = parseString(setString1);
    set2 = parseString(setString2);

    cout << "Множество А: " << vectorToString(set1) << endl << endl;
    cout << "Множество B: " << vectorToString(set2) << endl << endl;

    vector<string> difference = setDifference(set1, set2);

    cout << "Множество С (разность А и В): " << vectorToString(difference) << endl;

    return 0;
}