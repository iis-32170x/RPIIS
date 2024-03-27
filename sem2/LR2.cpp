#include <vector>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct cell {
    string name;
    int multiplicity = 0;
};

vector<cell> intersection(vector<cell> first, vector<cell> second);
void print(vector<cell> p);
int minimum(cell p, cell t);
string reworkStr_n(cell* p);
int reworkStr_m(cell* p);
int parseCount(string str);
void Parse(string str, vector<cell>* rez);
bool equals(cell first, cell second);
void refineSet(vector<cell>* p);
vector<cell> intersection(vector<cell> first, vector<cell> second);
bool validNotation(string p);

int main(void) {
    fstream file("textfile.txt");

    string str;
    string temp;

    file >> str;
    if (!validNotation(str)) {
        cout << "Wrong input!" << endl;
        return 0;
    }
    vector <cell> first(parseCount(str));
    Parse(str, &first);
    refineSet(&first);
    while (file >> temp) {
        file >> temp;
        if (!validNotation(temp)) {
            cout << "Wrong input!" << endl;
            return 0;
        }
        vector<cell> second(parseCount(temp));
        Parse(temp, &second);
        refineSet(&second);
        first = intersection(first, second);
        print(first);
        second.clear();
    }
    file.close();
    return 0;
}

void print(vector<cell> p) {
    if (p.size() != 0) {
        cout << "{ ";
        for (int i = 0; i < p.size(); ++i) {
            if (i != p.size() - 1) {
                cout << p[i].multiplicity << p[i].name << ", ";
            }
            else {
                cout << p[i].multiplicity << p[i].name << " }" << endl;
            }
        }
    }
}

int minimum(cell p, cell t) {
    return p.multiplicity >= t.multiplicity ? t.multiplicity : p.multiplicity;
}

string reworkStr_n(cell* p) {
    string str;
    bool digitsAreGone = false;
    for (int i = 0; i < (*p).name.size(); ++i) {
        if (digitsAreGone == true)
        {
            str += (*p).name[i];
        }

        if (!isdigit((*p).name[i]) && digitsAreGone == false) {
            str += (*p).name[i];
            digitsAreGone = true;

        }
    }

    (*p).name = str;
    return str;
}

int reworkStr_m(cell* p) {
    int multiplicity = 0;
    vector<int> num;
    for (int i = 0; isdigit((*p).name[i]) && i < (*p).name.length(); ++i) {
        num.push_back(static_cast<int>((*p).name[i]) - '0');
    }
    for (int i = 0; i < num.size(); ++i) {
        multiplicity += num[i] * (int)pow(10, num.size() - 1 - i);
    }
    return multiplicity;
}

int parseCount(string str)
{
    int amountOfEl = 0;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',' || str[i] == '{' || str[i] == '<')
        {
            i++;
            int j = i;
            int unclosed_sets = 0;
            amountOfEl++;
            string found_elem;
            while (str[j] != ',' && str[j] != '}' && str[j] != '>')
            {
                if (((str[j] == '{' && (str[j - 1] == ',' || str[j - 1] == '{')) || (str[j] == '<' && (str[j - 1] == ',' || str[j - 1] == '{'))))
                {
                    do
                    {
                        if (str[j] == '{' || str[j] == '<')
                            unclosed_sets++;
                        else if (str[j] == '}' || str[j] == '>')
                            unclosed_sets--;
                        found_elem += str[j];
                        j++;

                    } while ((str[j - 1] != '}' && str[j - 1] != '>') || unclosed_sets != 0);
                    break;
                }
                found_elem += str[j];
                j++;
            }
            i = j - 1;
        }
    }
    return amountOfEl;
}

void Parse(string str, vector<cell>* rez)
{
    int amount_of_el = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',' || str[i] == '{' || str[i] == '<')
        {
            i++;
            int j = i;
            int unclosed_sets = 0;
            string found_elem;

            while (str[j] != ',' && str[j] != '}' && str[j] != '>')
            {
                if (((str[j] == '{' && (str[j - 1] == ',' || str[j - 1] == '{' || isdigit(str[j - 1]) || str[j - 1] == '<')) || (str[j] == '<' && (str[j - 1] == ',' || str[j - 1] == '{' || isdigit(str[j - 1]) || str[j - 1] == '<'))))
                {
                    do
                    {
                        if (str[j] == '{' || str[j] == '<')
                            unclosed_sets++;
                        else if (str[j] == '}' || str[j] == '>')
                            unclosed_sets--;
                        found_elem += str[j];
                        j++;

                    } while ((str[j - 1] != '}' && str[j - 1] != '>') || unclosed_sets != 0);
                    break;
                }
                found_elem += str[j];
                j++;
            }

            (*rez)[amount_of_el].name = found_elem;
            (*rez)[amount_of_el].name = reworkStr_n(&(*rez)[amount_of_el]);
            string save_name = (*rez)[amount_of_el].name;
            (*rez)[amount_of_el].name = found_elem;
            (*rez)[amount_of_el].multiplicity = reworkStr_m(&(*rez)[amount_of_el]);
            if ((*rez)[amount_of_el].multiplicity == 0)
            {
                (*rez)[amount_of_el].multiplicity = 1;
            }
            (*rez)[amount_of_el].name = save_name;

            found_elem = "";
            i = j - 1;
            amount_of_el++;
        }
    }
}

bool equals(cell first, cell second) {
    if(first.name == second.name){
        return first.name == second.name;
    }
    else if (first.name[0] == '<' && second.name[0] == '<') {
        vector<cell> p(parseCount(first.name)), t(parseCount(second.name));
        Parse(first.name, &p);
        Parse(second.name, &t);
        for (int i = 0; i < p.size(); ++i) {
            bool wasIntersectioned = false;
            for (int k = 0; k < t.size(); ++k) {
                if (p[i].name == t[k].name && p[i].multiplicity == t[k].multiplicity && k == i) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                }
                else if (equals(p[i], t[k]) && k == i) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                }
            }
            if (wasIntersectioned == true)  --i;
        }
        return p.size() == 0 && t.size() == 0;
    }
    else if (first.name[0] == '{' && second.name[0] == '{') {
        vector<cell> p(parseCount(first.name)), t(parseCount(second.name));
        Parse(first.name, &p);
        Parse(second.name, &t);
        for (int i = 0; i < p.size(); ++i) {
            bool wasIntersectioned = false;
            for (int k = 0; k < t.size(); ++k) {
                if (p[i].name == t[k].name && p[i].multiplicity == t[k].multiplicity) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                    break;
                }
                else if (equals(p[i], t[k])) {
                    p.erase(p.begin() + i);
                    t.erase(t.begin() + k);
                    --k;
                    wasIntersectioned = true;
                    break;
                }
            }
            if (wasIntersectioned == true)  --i;
        }
        return p.size() == 0 && t.size() == 0;
    }
}

void refineSet(vector<cell>* p) {
    for (int i = 0; i < (*p).size(); ++i) {
        bool wasIntersectioned = false;
        for (int k = i+1; k < (*p).size(); ++i) {
            if (equals((*p)[i], (*p)[k])) {
                (*p)[i].multiplicity += (*p)[k].multiplicity;
                (*p).erase((*p).begin() + k);
                --k;
                wasIntersectioned = true;
                break;
            }
        }
        if (wasIntersectioned == true) --i;
    }
}

vector<cell> intersection(vector<cell> first, vector<cell> second) {
    vector<cell> temp1 = first;
    vector<cell> temp2 = second;
    vector<cell> res;

    for (int i = 0; i < temp1.size(); ++i) {
        bool wasIntersectioned = false;
        for (int k = 0; k < temp2.size(); ++k) {
            if (equals(temp1[i], temp2[k])) {
                cell p;
                p.name = temp1[i].name;
                p.multiplicity = minimum(temp1[i], temp2[k]);
                res.push_back(p);
                temp1.erase(temp1.begin() + i);
                temp2.erase(temp2.begin() + k);
                --k;
                wasIntersectioned = true;
            }
        }
        if (wasIntersectioned == true)  --i;
    }
    return res;
}

bool validNotation(string p) {
    std::stack<char> st;
    char  m[128];
    m['}'] = '{';
    m['>'] = '<';

    for (const auto c : p)
    {
        if (c == '{' || c == '<')  st.push(c);
        else if (c == '}' || c == '>')
        {
            if (st.empty() || st.top() != m[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}
