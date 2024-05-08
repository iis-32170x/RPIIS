#include "SymDiff.h"

using namespace std;

void runTestcase(string filename, int& num_sets, vector<vector<string>>& sets) {
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Файл не открыт!\n";
    }
    else
    {
        char h;

        sets.resize(num_sets);
        for (int i = 0; i < num_sets; ++i)
        {
            char line[100];

            string element;
            int j = 0, t = 0;
            file >> h;

            file.getline(line, 100, '\n');

            for (t; line[t] != '\0'; t++);
            while (line[j] != '{')
                j++;
            j++;
            while (j < t) {
                switch (line[j]) {

                case '{':
                    while (line[j] != '}')
                        element += line[j++];
                    element += line[j];
                    if (!element.empty())
                    {
                        sets[i].push_back(element);
                        element.clear();
                    }
                    break;

                default:
                    while ((line[j] != ',') && (line[j] != '}') && (line[j] != '\0')) {
                        element += line[j];
                        j++;
                    }
                    if (!element.empty())
                    {
                        sets[i].push_back(element);
                        element.clear();
                    }
                    j++;
                    break;
                }
            }
        }
    }
    file.close();
}

void symDiff(vector<vector<string>>& sets, int cur, int& num_sets, vector<string>& symdiff) {
    for (int i = 0; i < sets[cur].size(); i++) {
        int k = 0;
        for (int j = 0; j < sets[cur + 1].size(); j++) {
            if (sets[cur][i] != sets[cur + 1][j])
                k++;
        }
        if (k == sets[cur + 1].size())
            symdiff.push_back(sets[cur][i]);
    }
    for (int i = 0; i < sets[cur + 1].size(); i++) {
        int k = 0;
        for (int j = 0; j < sets[cur].size(); j++) {
            if (sets[cur + 1][i] != sets[cur][j])
                k++;
        }
        if (k == sets[cur].size())
            symdiff.push_back(sets[cur + 1][i]);
    }
    if (cur != num_sets - 2) {
        sets.at(cur + 1) = symdiff;
        symdiff.clear();
        symDiff(sets, cur + 1, num_sets, symdiff);
    }
}