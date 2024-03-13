#include <iostream>
#include <vector>
#include "UnionOfSets.h"

using namespace std;

int main() {
    int ch;
    cout << "Choose a file:\n1. set1.txt\n2. set2.txt\n3. set3.txt\n4. set4.txt\n5. set5.txt\n";
    cin >> ch;
    string path;
    switch (ch) {
    case 1:
        path = "set1.txt";
        break;
    case 2:
        path = "set2.txt";
        break;
    case 3:
        path = "set3.txt";
        break;
    case 4:
        path = "set4.txt";
        break;
    case 5:
        path = "set5.txt";
        break;
    default:
        cout << "Invalid choice!\n";
        return 1;
    }

    int num_sets;
    vector<vector<string>> sets;

    run_testcase(path, num_sets, sets);

    vector<vector<pair<string, int>>> counts = CountMultiplicities(sets);
    vector<pair<string, int>> max_counts = FindMaxMultiplicities(counts);
    OutputResult(max_counts);
    
    return 0;
}
