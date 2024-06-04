#pragma once

#ifndef LABA2_HEADER_H
#define LABA2_HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cstdlib> 
#include <algorithm> 
using namespace std;

constexpr auto OPENSET_SYMBOL = '{'; //ôèãóðíàÿ îòêðûâàþùàÿñÿ ñêîáêà
constexpr auto CLOSESET_SYMBOL = '}'; //ôèãóðíàÿ çàêðûâàþùàÿñÿ ñêîáêà
constexpr auto DELIMITER_SYMBOL = ','; //çàïÿòàÿ (ðàçäåëèòåëü)

string inputpath = "input.txt";

ifstream fin;

//ñ÷èòûâàíèå èç ôàéëà
vector<string> getSets(string inputpath) {
    fin.open(inputpath);
    if (!fin.is_open())
        cout << "Ïðîèçîøëà îøèáêà ïðè îòêðûòèè ôàéëà (" + inputpath + ")!" << endl;
    vector<string> sets; //â íåãî äîáàâëÿþòñÿ ñòðîêè, ïðåäñòàâëÿþùèå ìíîæåñòâà
    int line = 0; //line äëÿ îòñëåæèâàíèÿ íîìåðà ñòðîêè â ôàéëå
    while (!fin.eof()) { //öèêë ðàáîòàåò, ïîêà íå ïîëó÷èò îøèáêó
        line++;
        string buff;
        getline(fin, buff); //ñ÷èòûâàåò ñòðîêó èç ôàéëà è ñîõðàíÿåò åå â ïåðåìåííîé buff
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int opens = 0;
            int closes = 0;
            for (int i = 0; i < buff.length(); i++) { //ïîäñ÷èòûâàåòñÿ, ÷òîáû êîë-âî ñêîáîê áûëî ïðàâèëüíîå
                if (buff[i] == OPENSET_SYMBOL)
                    opens++;
                if (buff[i] == CLOSESET_SYMBOL)
                    closes++;
            }
            if (opens != closes) { //ïðîâåðÿåò, ñîâïàäàåò ëè êîëè÷åñòâî îòêðûâàþùèõ è çàêðûâàþùèõ ñêîáîê â ñòðîêå. Åñëè íåò, âûâîäèòñÿ ñîîáùåíèå îá îøèáêå
                cout << "Ïðîâåðüòå ïðàâèëüíîñòü ââîäà! Ñòðîêà: " + to_string(line) + ", Ôàéë: " + inputpath << endl; //ïëþñû èñïîëüçóþòñÿ äëÿ ñîåäèíåíèÿ ñòðîê è ÷èñåë
                cout << "Êîëè÷åñòâî '{' íå ðàâíî êîëè÷åñòâó '}'" << endl;
                exit(0);
            }
            sets.push_back(buff); //èñïîëüçóåòñÿ äëÿ äîáàâëåíèÿ ñòðîêè buff â êîíåö âåêòîðà sets
        }
        else {
            cout << "Ïðîâåðüòå ïðàâèëüíîñòü ââîäà! Ñòðîêà: " + to_string(line) + ", Ôàéë: " + inputpath << endl;
            exit(0);
            break;
        }
    }
    return sets;
}

//ñîäåðæèò èìåíà âåêòîðîâ
vector<string> getNamePlenty(vector<string> sets) {
    int numSets = sets.size(); //ðàâíî êîëè÷åñòâó íàéäåííûõ ìíîæåñòâ (ñòðîê â âåêòîðå sets) 
    vector<string> namePlenty(numSets); //âåêòîð ñòðîê ñ ðàçìåðîì, ðàâíûì êîëè÷åñòâó ìíîæåñòâ
    for (int i = 0; i < numSets; i++) {
        namePlenty[i] = sets[i][0];
    }
    return namePlenty;
}

//èçâëå÷åíèå ñîäåðæèìîãî êàæäîãî ìíîæåñòâà èç âåêòîðà sets è ñîõðàíåíèå ýòîãî ñîäåðæèìîãî
vector<string> saveFillPlenty(vector<string> sets) {
    int numSets = sets.size(); //ðàâíî êîëè÷åñòâó íàéäåííûõ ìíîæåñòâ (ñòðîê â âåêòîðå sets)
    vector<string> fillPlenty(numSets); //õðàíèò ñîäåðæèìîå êàæäîãî ìíîæåñòâà
    for (int i = 0; i < numSets; i++) {
        fillPlenty[i] = sets[i].substr(2, sets[i].length() - 3); //äîáàâëÿåò â fillPlenty ñòðîêó èç (sets[i].length() - 3) ñèìâîëîâ, íà÷èíàÿ ñî âòîðîãî ýëåìåíòà èç sets
    }
    return fillPlenty;
}

//ðàçäåëåíèå ìíîæåñòâ íà îòäåëüíûå ýëåìåíòû
vector<vector<string>> splitSets(vector<string> sets, char delimiter) {
    int numSets = sets.size();
    vector<vector<string>> elements(numSets);

    for (auto i = 0; i < numSets; i++) {
        string buff;
        int openBrackets = 0;
        buff = sets[i].substr(3, sets[i].length() - 4);
        stringstream ss(buff);
        string token;
        string element = "";

        while (getline(ss, token, delimiter)) {
            if (token[0] == '{') {
                openBrackets++;
                element += token;
                while (openBrackets > 0 && getline(ss, token, delimiter)) {
                    element += delimiter + token;
                    if (token[0] == '{') {
                        openBrackets++;
                    }
                    else if (token[1] == '}') {
                        openBrackets--;
                    }
                }
                elements[i].push_back(element);
                element = "";
            }
            else {
                elements[i].push_back(token);
            }
        }
    }

    vector<string> list_name = getNamePlenty(sets);
    vector<string> fillPlenty = saveFillPlenty(sets);
    int numSetsName = list_name.size();

    for (int i = 0; i < numSets; i++) {
        for (int k = 0; k < elements[i].size(); k++) {
            for (int j = 0; j < numSetsName; j++) {
                if ((list_name[j] == elements[i][k]) && (j != i)) {
                    elements[i][k] = fillPlenty[j];
                }
            }
        }
    }
    return elements;
}

//âû÷èñëåíèå ðàçíîñòè
vector<string> setDifference(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result; //çíà÷åíèå ðàçíîñòè

    //êîïèðóåì âñå ýëåìåíòû èç ïåðâîãî ìíîæåñòâà
    result = set1;

    //óäàëÿåì ýëåìåíòû âòîðîãî ìíîæåñòâà èç ðåçóëüòàòà   
    for (const auto& elem : set2) {
        auto it = find(result.begin(), result.end(), elem);
        if (it != result.end()) {
            result.erase(it);
        }
    }
    return result;
}

//äåëàåì ïðèÿòíûé äëÿ âîñïðèÿòèÿ ôîðìàò
string prettify(const vector<string>& set) {
    string result = "";
    result += OPENSET_SYMBOL;
    for (int i = 0; i < set.size(); i++) {
        result += set[i];
        if (i != set.size() - 1) {
            result += DELIMITER_SYMBOL;
        }
    }
    result += CLOSESET_SYMBOL;
    return result;
}

//çàïóñê âñåãî ïðîöåññà
string Start(vector<string> sets) {
    getNamePlenty(sets);

    vector<vector<string>> elements;
    elements = splitSets(sets, DELIMITER_SYMBOL);
    
    //ïðîâåðêà, ÷òî åñòü äâà ìíîæåñòâà äëÿ âû÷èñëåíèÿ ðàçíîñòè
    if (elements.size() < 2) {
        cout << "Îøèáêà: äëÿ âû÷èñëåíèÿ ðàçíîñòè íóæíî äâà ìíîæåñòâà!" << endl;
        return "";
    }

    //ðàçíîñòü ìåæäó ïåðâûìè äâóìÿ ìíîæåñòâàìè
    vector<string> result = setDifference(elements[0], elements[1]);

    cout << "\nÐàçíîñòü: ";
    cout << prettify(result) << endl;
    return prettify(result);
}

#endif //LABA2_HEADER_H
