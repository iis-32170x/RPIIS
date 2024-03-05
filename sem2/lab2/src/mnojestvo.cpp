#include "mnojestvo.hpp"

bool format(string name, vector<myset> &mnojestva, string &all_file){
    ifstream fin;
    fin.open(name);
    if (fin.is_open()){
        string temp;
        while (getline(fin, temp))
            all_file += temp + "\n";
        fin.close();

        const regex regular1(FORMA_1);
        const regex regular2(FORMA_2);
        
        while (!regex_match(all_file.c_str(), regular1)){

            const vector<smatch> matches{
                sregex_iterator{C_ALL(all_file), regular2},
                sregex_iterator{}
            };

            if (matches.size() == 0)
                return false;

            string *temps{new string[matches.size()]};
            for (int i{0}; i < matches.size(); i++)
                temps[i] = matches[i].str();
            for (int i{0}; i < matches.size(); i++)
                replace_na_names(all_file, temps[i], add_set(temps[i], mnojestva));

            delete[] temps;
        }
        return regex_match(all_file.c_str(), regular1);
    }
    else
        return false;
}

string add_set(string str, vector<myset> &mnojestva){
    vector<string> new_elements{razbil_na_names(str)};
    bool set_or_kortj{poradoc(str)};
    for (int i{0}; i < mnojestva.size(); i++){
        if (set_or_kortj == mnojestva[i].poradok && new_elements == mnojestva[i].elements)
            return mnojestva[i].name;
    }
    string name{"NEW_" + to_string(mnojestva.size())};
    mnojestva.push_back({name, new_elements, set_or_kortj});
    return name;
}

bool poradoc(string str){
    return str[0] == '{';
}

vector<string> razbil_na_names(string str){
    vector<string> elements;
    elements.push_back("");
    for (int i{1}; i < str.size() - 1; i++){
        if (str[i] == ',')
            elements.push_back("");
        else
            elements[elements.size() - 1] += str[i];
    }
    if (str[0] == '{')
        sort(elements.begin(),elements.end());
    return elements;
}

void replace_na_names(string &text, string old_inf, string new_inf){
    regex old;
    old_inf.pop_back();
    if (old_inf[0] == '{')
        old ="\\" + old_inf + "\\}";
    else
        old ="\\" + old_inf + "\\>";
    text = regex_replace(text, old, new_inf);
}

void replace_na_names(vector<myset> &mnojestva, string old_inf, string new_inf){
    for (int i{0}; i < mnojestva.size(); i++){
        for (int j{0}; j < mnojestva[i].elements.size(); j++){
            if (mnojestva[i].elements[j] == old_inf)
                mnojestva[i].elements[j] == new_inf;
        }
    }
}

void make_sets(string &all_file, vector<myset> &mnojestva){
    bool ravno_nextstroka{true};
    string new_name, elements;
    for (int number{0}; number < all_file.size(); number++){
        if (all_file[number] == '='){
            ravno_nextstroka = false;
            continue;
        }
        else if (all_file[number] == '\n'){
            ravno_nextstroka = true;
            bool flag{true}, set_or_kortj{poradoc(elements)};;
            vector<string> new_elements{razbil_na_names(elements)};
            for (int i{0}; i < mnojestva.size(); i++){
                if (set_or_kortj == mnojestva[i].poradok && new_elements == mnojestva[i].elements){
                    flag = false;
                    replace_na_names(mnojestva, mnojestva[i].name, new_name);
                    replace_na_names(all_file, mnojestva[i].name, new_name);
                    mnojestva[i].name = new_name;
                    break;
                }       
            }
            if (flag)
                mnojestva.push_back({new_name, new_elements, set_or_kortj});
            new_name = elements = "";
            continue;
        }
        if (ravno_nextstroka)
            new_name += all_file[number];
        else
            elements += all_file[number];
    }

}

void union_sets(myset &result_set, vector<myset> &mnojestva){
    for (int i{0}; i < mnojestva.size(); i++){
        if(mnojestva[i].name.substr(0,4) != "NEW_")
            for (string new_element: mnojestva[i].elements){
                bool flag{true};
                for (string element: result_set.elements){
                    if (new_element == element){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    result_set.elements.push_back(new_element);
                }
            }
    }
}

void write_recursiv(myset &set, vector<myset> &mnojestva, ofstream &fout){
    if (set.poradok)
        fout << "{";
    else
        fout << "<";
    for (int i{0}; i < set.elements.size(); i++){
        if (set.elements[i].substr(0,4) == "NEW_"){
            for (int j{0}; j < mnojestva.size(); j++){
                if (mnojestva[j].name == set.elements[i] && set.name != set.elements[i]){
                    write_recursiv(mnojestva[j], mnojestva, fout);
                    if (i < set.elements.size() - 1 )
                        fout << ",";
                    break;
                }
            }
            continue;
        }
        fout << set.elements[i];
        if (i < set.elements.size() - 1)
            fout << ",";
    }
    if (set.poradok)
        fout << "}";
    else
        fout << ">";
}

void write(myset &result_set, vector<myset> &mnojestva, string name){
    ofstream fout;
    name.pop_back(); name.pop_back(); name.pop_back(); name.pop_back();
    fout.open("../sets/RESULT(" + name.substr(8) + ").txt");
    if (fout.is_open()){
        fout << result_set.name << "=";
        write_recursiv(result_set, mnojestva, fout);
    }
    else{
        cout << "Ошибка???\n";
    }
}


void do_all(string name){
    
    vector<myset> mnojestva;
    string all_file;

    if (!format(name, mnojestva, all_file)){
        cout << "Ошибка: проверьте файл с именем " << name << "!\n";
        return;
    }
    make_sets(all_file, mnojestva);

    myset result_set;
    result_set.name = "result";
    result_set.poradok = true;
    union_sets(result_set, mnojestva);
    write(result_set, mnojestva, name);
}