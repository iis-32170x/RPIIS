#include "Header.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void sozdmn(const string& path, int& num_sets, vector<vector<string>>& sets)
{
    ifstream file;
    file.open(path);

    if (!file.is_open())
    {
        cout << "File is not open\n";
    }
    else
    {

        file >> num_sets;
        char h;

        sets.resize(num_sets);
        for (int i = 0; i < num_sets; ++i)
        {
            char line[100];
            char ch;

            string element;
            int j = 0, cl = 0, t = 0;
            file >> h;

            file.getline(line, 100, '\n');

            for (t; line[t] != '\0'; t++);
            while (line[j] != '{')
                j++;
            j++;
            while (j < t) {
                switch (line[j]) {

                case '{':
                    cl++;

                    while (line[j] != '}')
                        element += line[j++];
                    element += line[j++];
                    j++;
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

void dekpr(const vector<vector<string>>& sets, int cur, int& num_sets, vector<vector<string>>& proizv, vector<string>& el)
{
    for (int i = 0; i < sets[cur].size(); i++)
    {
        el.push_back(sets[cur][i]);

        if (cur == num_sets - 1)
        {
            proizv.push_back(el);

        }
        else
            dekpr(sets, cur + 1, num_sets, proizv, el);
        el.pop_back();
    }
}
