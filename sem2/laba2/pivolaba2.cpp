#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;

int main() {
    int ch;
    cout << "Choose a file:\n1. 1.txt\n2. 2.txt\n3. 3.txt\n4. 4.txt\n5. 5.txt\n";
    cin >> ch;
    string path;
    switch (ch) {
    case 1:
        path = "1.txt";
        break;
    case 2:
        path = "2.txt";
        break;
    case 3:
        path = "3.txt";
        break;
    case 4:
        path = "4.txt";
        break;
    case 5:
        path = "5.txt";
        break;
    default:
        cout << "Invalid choice!\n";
        return 1;
    }

    int num_sets;
    vector<vector<string>> sets, cortprod;
    vector<string> el;
    sozdmn(path, num_sets, sets);
    dekpr(sets, 0, num_sets, cortprod, el);
    for (int i = 0; i < cortprod.size(); i++)
    {
        cout << "\n";
        cout << "{";
        for (int j = 0; j < num_sets; j++)

        {
            if (j != 0) cout << ", ";
            cout << cortprod[i][j];

        }

        cout << "}";
    }
    return 0;
}