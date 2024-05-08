#include "SymDiff.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    string filename;

    int n;
    int num_sets = 0;
    
    cout << "Выберите файл:\n 1. test1.txt\n 2. test2.txt\n 3. test3.txt\n 4. test4.txt\n 5. test5.txt\n";
    cin >> n;

    if (cin.good()) {
        switch (n) {
        case 1:
            filename = "test1.txt";
            break;
        case 2:
            filename = "test2.txt";
            break;
        case 3:
            filename = "test3.txt";
            break;
        case 4:
            filename = "test4.txt";
            break;
        case 5:
            filename = "test5.txt";
            break;
        default:
            cout << "Неизвестное значение!";
            return 1;
        }
    }
    vector<vector<string>>sets;
    vector<string> symdiff;

    ifstream file(filename);
    string line;
    while (getline(file, line))
        ++num_sets;

    runTestcase(filename, num_sets, sets);

    symDiff(sets, 0, num_sets, symdiff);

    cout << "\n";
    cout << "{";
  
    for (int i = 0; i < symdiff.size(); i++)
    {
        if (i != symdiff.size() - 1) {
            cout << symdiff[i];
            cout << "; ";
        }
        else
            cout << symdiff[i];
    }
    cout << "}";
    return 0;
}