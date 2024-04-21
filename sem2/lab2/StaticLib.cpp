#include "pch.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

void setData(const string& filepath, int& num_sets, vector<vector<string>>& sets)
{
    setlocale(LC_ALL, "RU");
    ifstream file;
    file.open(filepath);

    if (!file.is_open())
    {
        cout << "Не удалось открыть файл";
        return;
    }

    file >> num_sets;
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    sets.resize(num_sets);

    for (int i = 0; i < num_sets; ++i)
    {
        string line;
        getline(file, line);

        // Удаляем пробелы из строки
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        // Разделяем строку на элементы множества
        stringstream ss(line);
        string element;
        while (getline(ss, element, ','))
        {
            // Если элемент начинается с {, объединяем все элементы до закрывающей }
            if (element[0] == '{')
            {
                string combined_element = element;
                while (element[element.length() - 1] != '}')
                {
                    getline(ss, element, ',');
                    combined_element += ',' + element;
                }
                sets[i].push_back(combined_element);
            }
            else
            {
                sets[i].push_back(element);
            }
        }
    }

    file.close();
}

void cartesianProducts(const vector<vector<string>>& sets, int cur, int& num_sets, vector<vector<string>>& combinations, vector<string>& elements)
{
    for (int i = 0; i < sets[cur].size(); i++)
    {
        elements.push_back(sets[cur][i]);

        if (cur == num_sets - 1)
        {
            combinations.push_back(elements);
        }
        else
        {
            cartesianProducts(sets, cur + 1, num_sets, combinations, elements);
        }

        elements.pop_back();
    }
}

int print(const std::string& filepath){
    int num_sets;
    vector<vector<string>> sets, comb;
    vector<string> el;
    setData(filepath, num_sets, sets);
    cartesianProducts(sets, 0, num_sets, comb, el);
    cout << endl << "{";
    for (int i = 0; i < comb.size(); i++)
    {

        cout << " <";
        for (int j = 0; j < num_sets; j++)

        {
            if (j != 0) cout << "; ";
            cout << comb[i][j];

        }

        cout << ">";
    }
    cout << "}";
    return 0;
}