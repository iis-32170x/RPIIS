#include "symmetric_difference.hpp"
using namespace std;

vector<string> readSets(const string &filepath) {
    vector<string> sets;
    ifstream file(filepath);
    if (!file.is_open()) {
        throw runtime_error("Ошибка при открытии файла.");
    }
    string line;
    while (getline(file, line)) {
        if (line.find(' ') != string::npos) {
            throw runtime_error("Строка содержит пробелы.");
        }
        sets.push_back(line);
    }
    file.close();
    return sets;
}

bool bracketsBalance(const string& line) {
    stack<char> bracketStack;
    for (char ch : line) {
        if (ch == '{' || ch == '<') {
            bracketStack.push(ch);
        }
        else if (ch == '}' || ch == '>') {
            if (bracketStack.empty() || (ch == '}' && bracketStack.top() != '{') || (ch == '>' && bracketStack.top() != '<')) {
                return false;
            }
            else {
                bracketStack.pop();
            }
        }
    }
    return bracketStack.empty();
}

bool stringsAreEqual(const string &str1, const string &str2) {
    if (str1.front() == '{' && str2.front() == '{') {
        vector<string> vec1 = parseString(str1);
        vector<string> vec2 = parseString(str2);
        set<string> set1(vec1.begin(), vec1.end());
        set<string> set2(vec2.begin(), vec2.end());
        return set1 == set2;
    }
    return str1 == str2;
}

vector<string> parseString(const string &str)
{
    vector<string> result;
    if(str.empty()) return result;
    string set = str.substr(1, str.length() - 2);
    stringstream ss(set);
    string elem;
    char c;
    int depth = 0;

    while (ss.get(c))
    {
        if (c == ',' && depth == 0)
        {
            if (!elem.empty())
            {   
                result.push_back(elem);
                elem.clear();
            }
        }
        else
        {
            if (c == '<' || c == '{')
            {
                depth++;
            }
            else if (c == '>' || c == '}')
            {
                depth--;
            }
            elem += c;
        }
    }
    if (!elem.empty())
    {
        result.push_back(elem);
    }
    return result;
}

bool elemInSet(const string &elem, vector<string> set)
{
    for (size_t k = 0; k < set.size(); k++)
    {
        if (set[k] == elem)
        { 
            return true;
        }
    }
    return false;
}

void removeMultiOccurence(vector<string> &set)
{
    for (size_t i = 0; i < set.size(); i++)
    {
        for (size_t j = i + 1; j < set.size(); j++)
        {
            if (stringsAreEqual(set[i], set[j]))
            {
                set.erase(set.begin() + j);
                j--;
            }
        }
    }
}

void removeDuplicatesRecursive(vector<string> &set) {
    removeMultiOccurence(set);
    for (string &elem : set) {
        if ((elem.front() == '{' && elem.back() == '}') || (elem.front() == '<' && elem.back() == '>')) {
            vector<string> subset = parseString(elem);
            removeDuplicatesRecursive(subset);
            string newElem(1, elem.front());
            for (size_t i = 0; i < subset.size(); ++i) {
                newElem += subset[i];
                if (i != subset.size() - 1) {
                    newElem += ",";
                }
            }
            newElem += elem.back();
            elem = newElem;
        }
    }  
}


vector<string> set_union(const vector<string> &set1, const vector<string> &set2)
{
    vector<string> result = set1;
    for (size_t i = 0; i < set2.size(); i++)
    {
        bool exists = false;
        for (size_t j = 0; j < result.size(); j++)
        {
            if (stringsAreEqual(set2[i], result[j]))
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            result.push_back(set2[i]);
        }
    }
    return result;
}

vector<string> set_difference(const vector<string> &set1, const vector<string> &set2)
{
    vector<string> result;
    for (size_t i = 0; i < set1.size(); i++)
    {
        if (!elemInSet(set1[i], set2))
        {
            result.push_back(set1[i]);
        }
    }
    return result;
}