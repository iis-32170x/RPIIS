#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;

class Graph {
private:
    vector<vector<int>> graph;
    string rec;

public:
    Graph(string rec = "") {
        this->rec = rec;
    }
    void RecordGraph(string line) {
        vector<int> rebra;
        int startPos = 2;
        int spacePos = line.find(' ', startPos);
        while (spacePos != string::npos) {
            string elstr = line.substr(startPos, spacePos - startPos);
            int el = stoi(elstr);
                startPos = spacePos + 1;
                spacePos = line.find(' ', startPos);
                rebra.push_back(el);
        }
        string elstr = line.substr(startPos, spacePos - startPos);
        int el = stoi(elstr);
        rebra.push_back(el);
        graph.push_back(rebra);
       
        /*for (auto i = rebra.begin(); i != rebra.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;*/
    }
    void SetRecord(string rec) {
        this->rec = rec;
        int leng = 0;
        int count = 0;
        vector<string> line;
        string linestr;
        ifstream record(rec);
        if (record.is_open()) {
            cout << "OK" << endl;
            while (getline(record, linestr)) {
                if(count >= 1)
                line.push_back(linestr);
                //cout << line[leng] << endl;
                leng++;
                count++;
            }
            for (auto iter = line.begin(); iter != line.end(); iter++)
            {
                RecordGraph(*iter);
            }
        }
        else {
            cout << "Not OK" << endl;
        }
        record.close();
    }
    string StronglyСonnectivityСheck() {
        int length = graph.size();
        vector<bool> visit(length, false);
        for (int i = 0; i < length; i++)
        {
            dfs(visit, i);
        }
        for (int i = 0; i < length; i++)
        {
            if (!visit[i])
                return "Граф не связанный";
        }
        if (TransposeTheGraph(length, visit))
            return "Граф сильно-связанный";
        else return "Граф связанный";
    }
    bool TransposeTheGraph(int &length, vector<bool> &visit) {
        vector<vector<int>> transosegraph(length);
        for (int i = 0; i < length; i++)
        {
            for (int neighbour : graph[i])
            {
                transosegraph[neighbour].push_back(i);
            }
        }
        fill(visit.begin(), visit.end(), false);
        dfs(visit, 0);
        for (int i = 0; i < length; i++)
        {
            if (!visit[i])
                return false;
        }
        return true;
    }

    void dfs(vector<bool>& visit, int current_top) {
        visit[current_top] = true;
        for (int neighbour : graph[current_top])
        {
            if (!visit[neighbour])
                dfs(visit, neighbour);

        }
    }

    string GetInfo() {
        string zapis1;
        int tryi = 0;
        for ( auto it = graph.begin(); it != graph.end() ; it++)
        {
            string zapis2;
            for (auto i= graph[tryi].begin(); i != graph[tryi].end(); i++)
            {
                zapis2 += " " + to_string(*i);
            }
            tryi++;
            zapis1 += to_string(tryi -1)+ " " + zapis2 + '\n';
        }
        cout << zapis1;
        return zapis1;
    }
};
void NeedsToBeWrittenInSomeoneNotebook() {
    ofstream vpis("D:\\labaPi1\\RRwritten.txt", ios_base::out);
    cout << "Будет записано сюда \nD:\\labaPi1\\RRwritten.txt" << endl << "Чтобы завершить ввод поставьте '.' " << endl;
         char str[100];
         cin.getline(str, 100, '.');
         vpis.write(str, strlen(str) + 1);
    vpis.close();
}
int main()
{
    setlocale(LC_ALL, "RU");
    string choise;
    string rec;
    cout << "Будете записывать граф? Если да, напишите " << "yes" << endl;
    cin >> choise;
    if (choise == "yes")
    NeedsToBeWrittenInSomeoneNotebook();
    cout << "Введите ссылку" << endl;
    cin >> rec;
    Graph gr;
    gr.SetRecord(rec);
    gr.GetInfo();
    cout << gr.StronglyСonnectivityСheck();
    return 0;
}
 //D:\\labaPi1\\RR.txt
//D:\\labaPi1\\RRwritten.txt