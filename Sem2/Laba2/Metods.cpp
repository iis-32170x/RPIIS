#include "Header.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

void SetMassiv::readSet(string set) {
    inSet.clear();
    int n = size(set);
    if ((set[0] != '<' && set[0] != '{') || (set[n - 1] != '>' && set[n - 1] != '}')) {
        cout << "Error";
        return;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (set[i] == '<' || set[i] == '{') {
            inSet.push_back("<MIN>");
            int skob = 1;
            while (skob != 0) {
                ++i;
                if (isdigit(set[i]) || isalpha(set[i])) {
                    string buff;
                    while (isdigit(set[i]) || isalpha(set[i])) {
                        buff += set[i];
                        ++i;
                    }
                    inSet.push_back(buff);
                }
                if (set[i] == '{' || set[i] == '<') {
                    ++skob;
                    inSet.push_back("<MIN>");
                }
                if (set[i] == '>' || set[i] == '}') {
                    --skob;
                    inSet.push_back("<MAX>");
                }
            }
        }
        else if (isdigit(set[i]) || isalpha(set[i])) {
            string buff;
            while (isdigit(set[i]) || isalpha(set[i])) {
                buff += set[i];
                ++i;
            }
            inSet.push_back(buff);
        }
    }
    string buff; int j = 0;
    for (int i = 0; i < inSet.size()-1; i++)
    {
        if (inSet[i] == "<MIN>" || inSet[i] == "<MAX>") j = i;
        if (inSet[i] > inSet[i + 1] && inSet[i + 1] != "<MAX>" && inSet[i + 1] != "<MIN>" && inSet[i] != "<MAX>" && inSet[i] != "<MIN>")
        {
            buff = inSet[i];
            inSet[i] = inSet[i + 1];
            inSet[i + 1] = buff;
            i = j;
        }
    }
}

 
vector<string> SetMassiv::MassivOutput()
{
    return inSet;
}

void SetMassiv::unionSets(vector<string> set1, vector<string> set2) {
    map<string, int> frequencySet1;
    map<string, int> frequencySet2;

    int subset = 0;
    for (int i = 0; i < set1.size(); i++)
    {
        if (set1[i] == "<MIN>") subset++;
        if (set1[i] == "<MAX>") subset--;
        if (subset == 0 && set1[i] != "<MAX>") ++frequencySet1[set1[i]];
    }

    for (int i = 0; i < set2.size(); i++)
    {
        if (set2[i] == "<MIN>") subset++;
        if (set2[i] == "<MAX>") subset--;
        if (subset == 0 && set2[i] != "<MAX>") ++frequencySet2[set2[i]];
    }

    vector<string> buff;
    vector<string> buff_inSet(100);
    vector<string> buff_inSet2(100);
    int n = 0;
    subset = 0;

    for (int i = 0; i < set1.size(); i++)
    {
        if (set1[i] == "<MIN>") {
            subset++;
        }
        if (subset != 0)
        {
            buff.push_back(set1[i]);
        }
        if (set1[i] == "<MAX>") subset--;
        if (buff.size() != 0 && subset == 0)
        {
            for (int k = 0; k < buff.size(); k++) {
                if (buff[k] == "<MIN>") buff_inSet[n] += "{";
                else
                if (buff[k] == "<MAX>") buff_inSet[n] += "}";
                else
                buff_inSet[n] += buff[k];
                if (k != buff.size() - 1 && buff[k+1] != "<MAX>" && buff[k] != "<MIN>") buff_inSet[n] += ",";
            }
            n++;
            buff.clear();
        }
    }
    buff_inSet.resize(n);

    subset = 0;
    n = 0;
    for (int i = 0; i < set2.size(); i++)
    {
        if (set2[i] == "<MIN>") {
            subset++;
        }
        if (subset != 0)
        {
            buff.push_back(set2[i]);
        }
        if (set2[i] == "<MAX>") subset--;
        if (buff.size() != 0 && subset == 0)
        {
            for (int k = 0; k < buff.size(); k++) {
                if (buff[k] == "<MIN>") buff_inSet2[n] += "{";
                else
                    if (buff[k] == "<MAX>") buff_inSet2[n] += "}";
                    else
                        buff_inSet2[n] += buff[k];
                if (k != buff.size() - 1 && buff[k + 1] != "<MAX>" && buff[k] != "<MIN>") buff_inSet2[n] += ",";
            }
            n++;
            buff.clear();
        }
    }
    buff_inSet2.resize(n);
    inSet.clear();

    for (int i = 0; i < buff_inSet.size(); i++) ++frequencySet1[buff_inSet[i]];
    for (int i = 0; i < buff_inSet2.size(); i++) ++frequencySet2[buff_inSet2[i]];

    for (const auto& elem : frequencySet1) {
        int maxFrequency = max(elem.second, frequencySet2[elem.first]);
        for (int i = 0; i < maxFrequency; ++i) {
            inSet.push_back(elem.first);
        }
    }

    for (const auto& elem : frequencySet2) {
        if (frequencySet1.find(elem.first) == frequencySet1.end()) {
            for (int i = 0; i < elem.second; ++i) {
                inSet.push_back(elem.first);
            }
        }
    }

}

void SetMassiv::printSet() {
    cout << "{";
    string buff;
    for (int i = 0; i < inSet.size()-1; i++)
    {
        if (inSet[i] > inSet[i + 1]) {
            buff = inSet[i];
            inSet[i] = inSet[i + 1];
            inSet[i + 1] = buff;
            i = 0;
        }
    }
    for (int i = 0; i < inSet.size(); i++) {
        if (inSet[i] == "<MIN>") cout << "{";
        else if (inSet[i] == "<MAX>") cout << "}";
        else if (i != inSet.size() - 1) cout << inSet[i] << ",";
        else cout << inSet[i];
    }
    cout << "}" << endl;
}

