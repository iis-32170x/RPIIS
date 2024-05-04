#include "Header.h"

vector<vector<string>> ReadFileToVector(const string& fileName)
{
    vector<vector<string>> sets;
    ifstream file(fileName);

    if (!file.is_open())
    {
        cout << "Error!" << endl << "Failed to open input file: " << fileName << "." << endl;
        return sets;
    }

    string line;
    while (getline(file, line))
    {
        vector<string> row;
        int i = 0;
        while (i < line.length())
        {
            string token, buffer;
            if (line[i] != ' ')
            {
                if (line[i] != '{')
                {
                    buffer += line[i];
                }
                else
                {
                    int braceCount = 1;
                    buffer += line[i];
                    i++;
                    while (i < line.length() && braceCount != 0)
                    {
                        if (line[i] == '{')
                        {
                            braceCount++;
                        }
                        else if (line[i] == '}')
                        {
                            braceCount--;
                        }
                        buffer += line[i];
                        i++;
                    }
                }
            }
            if (!buffer.empty())
            {
                row.push_back(buffer);
                buffer.clear();
            }
            i++;
        }

        if (!row.empty())
        {
            sets.push_back(row);
        }
    }

    file.close();
    return sets;
}

vector<vector<string>> CartesianProduct(const vector<vector<string>>& sets)
{
    vector<vector<string>> temp(1, vector<string>());

    for (const auto& set : sets) 
    {
        vector<vector<string>> newTemp;
        for (const auto& product : temp) 
        {
            for (const auto& element : set) 
            {
                vector<string> tempCopy = product;
                tempCopy.push_back(element);
                newTemp.push_back(tempCopy);
            }
        }
        temp = newTemp;
    }

    return temp;
}

void PrintCartesianProduct(const vector<vector<string>>& product)
{
    for (const auto& combination : product) 
    {
        for (const auto& element : combination)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}


