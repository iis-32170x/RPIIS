#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

vector<string> readSets(string path) {
    ifstream f;
    f.open(path);
    if (!f.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(0);
    }
    vector<string> sets;
    int line = 0;
    while (!f.eof()) {
        line++;
        int n = 0;
        string buff;
        bool foundEqualSign = false;
        string dataAfterEqualSign;
        while (getline(f, buff)) {
            
            n++;
            size_t found = buff.find('=');
            if (found != string::npos) {
                foundEqualSign = true;
                dataAfterEqualSign = buff.substr(found + 1); 
                cout << n <<" Множество: " << dataAfterEqualSign << endl;
            }
          

            int open = 0;
            int close = 0;
            for (int i = 0; i < dataAfterEqualSign.length(); i++) {
                if (dataAfterEqualSign[i] == '{')
                    open++;
                if (dataAfterEqualSign[i] == '}')
                    close++;
                if (dataAfterEqualSign[i] == '<')
                    open++;
                if (dataAfterEqualSign[i] == '>')
                    close++;
            }
            if (open != close) {
                cout << "Check input for correctness!" << endl;
                cout << "Number of '{' is not equal to number of '}'" << endl;
                exit(0);
            }
            sets.push_back(dataAfterEqualSign);
            if (line == 0) {

                cout << "Check input for correctness!" << endl;
                exit(0);
                break;
            }
        }
    }
    return sets;
}

vector<string> writeSets(vector<string> sets,int&number) {
    int numberSets = sets.size();
    vector<string> FULLset(numberSets);
    for (int i = 0; i < numberSets; i++) {
        FULLset[i] = sets[i];
        number++;
    }

    cout << endl;
    return FULLset;
}

vector<string> parseSet(const string& input) {
    vector<string> elements;
    size_t pos = 1;
    string buffer;
    int openBraces = 1;
    int i = 0;
    for (; pos < input.length(); pos++) {
        char c = input[pos];
        if (c == '{' || c == '<') {
            openBraces++;
            if (openBraces == 2) {
                if (!buffer.empty()) {
                    elements.push_back(buffer);
                }
                buffer.clear();

            }
            buffer += c;
        }
        else if (c == '}' || c == '>') {
            openBraces--;
            if (openBraces > 0) {
                buffer += c;
            }
            if (openBraces == 0) {
                elements.push_back(buffer);
                buffer.clear();
            }
        }
        else if (openBraces == 1) {
            if (c == ',') {
                elements.push_back(buffer);
                buffer.clear();
            }
            else {
                buffer += c;
            }
        }
        else if (openBraces > 0) {
            buffer += c;
        }

    }
    return elements;
}

vector <vector<string>> subsets(vector <string> sets) {
    vector <vector<string>> subsets;
    for (int i = 0; i < sets.size(); i++) {
        subsets.push_back(parseSet(sets[i]));
        for (const auto& element : subsets[i]) {
            cout << element << " ";
        }
        cout << " - Элементы " << i+1 << " множества." << endl;
    }

    return subsets;
}


string intersection(vector<string>& set1, vector<string>& set2) {
    string result;
    int count = 1;
    vector<string> copy;
    vector<string> copy1;
    vector<string> copy2;
    bool isFirstElement = true;
    auto iter = set1.begin();
    auto iter2 = set2.begin();
    while (iter != set1.end()) {
        if ((find(set2.begin(), set2.end(), *iter) != set2.end())) {
            if (!isFirstElement) {
                result += ",";
            }
            result += *iter;
            isFirstElement = false;
            iter = set1.erase(iter);
        }
        else if ((*iter).size() == 1 || (*iter)[0] == '<') {
            iter = set1.erase(iter);
        }
        else {
            iter++;
        }
    }

    while (iter2 != set2.end()) {
        
        if ((*iter2).size() == 1 || (*iter2)[0] == '<') {
            iter2 = set2.erase(iter2);
        }
        else {
            iter2++;
        }
    }


    if (!set1.empty()) {

       
        for (const auto& element1 : set1) {
            auto copy1 = parseSet(element1);
       
       
            for (const auto& element2 : set2) {
                auto copy2 = parseSet(element2);
            
                auto intersected = intersection(copy1, copy2);
                if (intersected == element1) {
                    if (intersected == "{}") {
                        break;
                    }
                    if (!result.empty()) {
                        result += ",";
                    }
                    result += intersected;

                }
                copy2.clear();

      
            }
            copy1.clear();

        }

    }

   

    result = "{" + result + "}";
    return result;
}

int main()
{   size_t pos = 1;
    int sets_q = 0;
    string path = "C:\\Users\\golov\\source\\repos\\LabWorkIntersection\\LabWorkIntersection\\set.txt";
    auto Sets = writeSets(readSets(path),sets_q);
    auto Subsets = subsets(Sets);

   
    string result = intersection(Subsets[0], Subsets[1]);

    for (int i = 2; i < sets_q; i++) {
        auto help_intersec = parseSet(result);
        result = intersection(help_intersec,Subsets[i]);
    }
   
  
    cout << result;
    cout << " - РЕЗУЛЬТАТ" << endl;

}

