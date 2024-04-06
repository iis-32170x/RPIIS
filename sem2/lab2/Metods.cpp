#include "Header.h"
ofstream fout;
void Set::readSet(string set) {
    int n = size(set);
    if ((set[0] != '<' && set[0] != '{') || (set[n-1] != '>' && set[n-1] != '}'))
    {
        cout << "Error";
        return;
    }
    for (int i = 1; i < n-1; i++)
    {
        if ((set[i-1] == ',' || set[i-1] == '<' || set[i - 1] == '{') && set[i] == ',')
        {
            cout << "Error";
            return;
        }
        if (set[i] != ',' && (!isalnum(set[i])))
        {
            cout << "Error";
            return;
        }
        if ((set[i + 1] == '>' || set[i + 1] == '}') && set[i] == ',')
        {
            cout << "Error";
            return;
        }
    }
    int buff= 0;
    for (int i = 1; i < n; i ++)
    {
        if (set[i - 1] == ',')
        {
            buff = set[i] - '0';
        }
        else if (set[i] == ','|| set[i] == '>' || set[i] == '}')
        {
            inSet.push_back(buff);
            buff = 0;
        }
        else
        {
            buff *= 10;
            buff += set[i]- '0';
        }
    }
}
void Set::genSet() {
    fout.open("test.txt");
    sort(inSet.begin(), inSet.end());
    do {
        for (int i = 0; i < size(inSet); i++) {
            cout << inSet[i] << " ";
        }
        cout << endl;
    } while (next_permutation(inSet.begin(), inSet.end()));
}
