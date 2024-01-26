#include <iostream>
#include <fstream>
#include <string>
#include "Set.h"

using namespace Algorithm;

int main()
{
    setlocale(LC_ALL, "russian");

    int set_size, input;
    set<int> temp;
    vector<Set> sets;

    string file;

    cout << "Введите абсолютный / относительный путь к файлу: ";
    cin >> file;

    ifstream fin;
    fin.open(file);

    cout << "Исходные множества:\n\n";

    while (!fin.eof())
    {
        fin >> set_size;

        cout << "Множество: ";
        for (int i = 0; i < set_size; i++) {
            fin >> input;
            temp.insert(input);
            cout << input << ' ';
        }
        cout << '\n';

        Set newSet(temp);
        sets.push_back(newSet);

        temp.clear();

    }

    set<int> result = Set::symmetrSubtractAll(sets);

    Set setResult(result);

    cout << "\nРезультирующая симметрическая разность всех множеств: " << setResult << '\n';
    return 0;
}
