#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



void swap(vector<string>* a, int i, int j)
{
    string s = (*a)[i];
    (*a)[i] = (*a)[j];
    (*a)[j] = s;
}


bool NextSet(vector<string>* a, int n)
{
    int j = n - 2;
    while (j != -1 && (*a)[j] >= (*a)[j + 1]) j--;
    if (j == -1)
        return false; 
    int k = n - 1;
    while ((*a)[j] >= (*a)[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1;
    while (l < r)
        swap(a, l++, r--);
    return true;
}



void SortSet(vector<string>* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((*a)[i] > (*a)[j])
            {
                swap(a, i, j);
            }
        }
    }
}



int Parse(string str, vector<string>* rez)
{
    int amount_of_el = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',' || str[i] == '{')
        {
            i++;
            int j = i;
            int unclosed_sets = 0;
            amount_of_el++;
            string found_elem;
            while (str[j] != ',' && str[j] != '}')
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
                    } while ((str[j-1] != '}' && str[j-1] != '>') || unclosed_sets != 0);
                    break;
                }
                found_elem += str[j];
                j++;
            }
            (*rez).push_back(found_elem);
            found_elem = "";
            i = j-1;
        }
    }
    return amount_of_el;
}

void Print(vector<string> arr, int n)
{
    static int num = 1;

    cout << num++ << ":  " << "{";
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            cout << arr[i] << ", ";
        else
            cout << arr[i];
    }
    cout << "}" << endl;
}

int main()
{
    
    ifstream fl;
    string ab;
    vector<string> parsed_str;

    fl.open("example.txt");
    
    getline(fl, ab);

    fl.close();

    int n = Parse(ab, &parsed_str);

    SortSet(&parsed_str, n);


    Print(parsed_str, n);
    while (NextSet(&parsed_str, n))
    {
        Print(parsed_str, n);
    }

    return 0;
}

