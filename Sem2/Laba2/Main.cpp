#include "..\Laba2\Header.h"

int main() {
    setlocale(LC_ALL, "RU");
    SetMassiv generator;
    string set;
    int MassivCount = 1, i = 0;
    cout << "—колько создать массивов?\n";
    cin >> MassivCount;
    if (cin.peek() != EOF) {
        cin.ignore(32789, '\n');
    }
    vector<vector<string>> Vec(MassivCount);
    for (int i = 0; i < MassivCount; i++)
    {
        cout << "¬ведите " << i + 1 << " массив" << endl; 
        getline(cin, set);
        generator.readSet(set);
        Vec[i] = generator.MassivOutput();
    }

    vector<string> Result = Vec[0];
    for (int i = 1; i < MassivCount; i++) {
        generator.unionSets(Result, Vec[i]);
        Result = generator.MassivOutput();
    }

    generator.printSet();

    return 0;
}