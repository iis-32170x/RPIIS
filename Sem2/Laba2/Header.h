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

constexpr auto OPENSET_SYMBOL = '{'; //фигурная открывающаяся скобка
constexpr auto CLOSESET_SYMBOL = '}'; //фигурная закрывающаяся скобка
constexpr auto DELIMITER_SYMBOL = ','; //запятая (разделитель)

string inputpath = "input.txt";

ifstream fin;

//считывание из файла
vector<string> getSets(string inputpath) {
    fin.open(inputpath);
    if (!fin.is_open())
        cout << "Произошла ошибка при открытии файла (" + inputpath + ")!" << endl;
    vector<string> sets; //в него добавляются строки, представляющие множества
    int line = 0; //line для отслеживания номера строки в файле
    while (!fin.eof()) { //цикл работает, пока не получит ошибку
        line++;
        string buff;
        getline(fin, buff); //считывает строку из файла и сохраняет ее в переменной buff
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int opens = 0;
            int closes = 0;
            for (int i = 0; i < buff.length(); i++) { //подсчитывается, чтобы кол-во скобок было правильное
                if (buff[i] == OPENSET_SYMBOL)
                    opens++;
                if (buff[i] == CLOSESET_SYMBOL)
                    closes++;
            }
            if (opens != closes) { //проверяет, совпадает ли количество открывающих и закрывающих скобок в строке. Если нет, выводится сообщение об ошибке
                cout << "Проверьте правильность ввода! Строка: " + to_string(line) + ", Файл: " + inputpath << endl; //плюсы используются для соединения строк и чисел
                cout << "Количество '{' не равно количеству '}'" << endl;
                exit(0);
            }
            sets.push_back(buff); //используется для добавления строки buff в конец вектора sets
        }
        else {
            cout << "Проверьте правильность ввода! Строка: " + to_string(line) + ", Файл: " + inputpath << endl;
            exit(0);
            break;
        }
    }
    return sets;
}

//содержит имена векторов
vector<string> getNamePlenty(vector<string> sets) {
    int numSets = sets.size(); //равно количеству найденных множеств (строк в векторе sets) 
    vector<string> namePlenty(numSets); //вектор строк с размером, равным количеству множеств
    for (int i = 0; i < numSets; i++) {
        namePlenty[i] = sets[i][0];
    }
    return namePlenty;
}

//извлечение содержимого каждого множества из вектора sets и сохранение этого содержимого
vector<string> saveFillPlenty(vector<string> sets) {
    int numSets = sets.size(); //равно количеству найденных множеств (строк в векторе sets)
    vector<string> fillPlenty(numSets); //хранит содержимое каждого множества
    for (int i = 0; i < numSets; i++) {
        fillPlenty[i] = sets[i].substr(2, sets[i].length() - 3); //добавляет в fillPlenty строку из (sets[i].length() - 3) символов, начиная со второго элемента из sets
    }
    return fillPlenty;
}

//разделение множеств на отдельные элементы
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

//вычисление cимметрической разности
vector<string> setDifference(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result; //значение разности
    vector<string> result1;

    //копируем все элементы из первого множества
    result = set1;
    result1 = set2;
    
    for (const auto& elem : set2) {
        auto it = find(result.begin(), result.end(), elem);
        if (it != result.end()) {
            result.erase(it);
        }
    }
    for (const auto& elem : set1) {
        auto it = find(result1.begin(), result1.end(), elem);
        if (it != result1.end()) {
            result1.erase(it);
        }
        
    }
    for (const auto& elem : result1) 
    {
        result.emplace_back(elem);
    }
   
    return result;
 
}

//делаем приятный для восприятия формат
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

//запуск всего процесса
string Start(vector<string> sets) {
    getNamePlenty(sets);

    vector<vector<string>> elements;
    elements = splitSets(sets, DELIMITER_SYMBOL);

    //проверка, что есть два множества для вычисления симметрической разности
    if (elements.size() < 2) {
        cout << "Ошибка: для вычисления разности нужно два множества!" << endl;
        return "";
    }

    //симметрическая разность между первыми двумя множествами
    vector<string> result = setDifference(elements[0], elements[1]);
    vector<string> result1 = setDifference(elements[1], elements[0]);
    cout << "\nСимметрическая разность: ";
    cout << prettify(result) << endl;
    return prettify(result);
   
    

}

#endif //LABA2_HEADER_H
