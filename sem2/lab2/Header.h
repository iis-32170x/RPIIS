//
// Created by Катюша Рублевская on 20.02.24.
//

#ifndef LABA2_HEADER_H
#define LABA2_HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> //для потока ввода-вывода
#include <cstdlib> //динамического управления памятью
#include <algorithm> // Для использования функции std::find
using namespace std;

constexpr auto OPENSET_SYMBOL = '{'; //для обозначения константных выражений, которые могут быть вычислены во время компиляции кода
constexpr auto CLOSESET_SYMBOL = '}';
constexpr auto DELIMITER_SYMBOL = ',';

string inputpath = "input.txt";

ifstream fin;


vector<string> getSets(string inputpath) {
    fin.open(inputpath);
    if (!fin.is_open())
        cout << "Error while opening file (" + inputpath + ")!" << endl; //объединение с ошибкой
    vector<string> sets; //добавляться строки, представляющие множества.
    int line = 0; //Создается переменная line, которая будет использоваться для отслеживания номера строки в файле.
    while (!fin.eof()) {
        line++;
        string buff;
        getline(fin, buff); // считывает строку из файла и сохраняет ее в переменной buff.
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int opens = 0;
            int closes = 0;
            for (int i = 0; i < buff.length(); i++) { //подсчитывается, чтоб кол-во скобок было правильное
                if (buff[i] == OPENSET_SYMBOL)
                    opens++;
                if (buff[i] == CLOSESET_SYMBOL)
                    closes++;
            }
            if (opens != closes) { //проверяет, совпадает ли количество открывающих и закрывающих скобок в строке. Если нет, выводится сообщение об ошибке
                cout << "Check input for correctness! Line: " + to_string(line) + ", File: " + inputpath << endl; //, плюсики используются для конкатенации (соединения) строк и чисел
                cout << "Number of '{' is not equal to number of '}'" << endl;
                exit(0);
            }
            sets.push_back(buff); //используется для добавления строки buff в конец вектора sets.
        }
        else {
            cout << "Check input for correctness! Line: " + to_string(line) + ", File: " + inputpath << endl;
            exit(0);
            break;
        }
    }
    return sets;
}
//содержит имена векторов
vector<string> getNamePlenty(vector<string> sets) {
    int numSets = sets.size(); //определяет количество строк в векторе sets, то есть количество множеств.
    vector<string> namePlenty(numSets); //создает вектор строк namePlenty с размером, равным количеству множеств.
    for (int i = 0; i < numSets; i++) {
        namePlenty[i] = sets[i][0];
    }
    return namePlenty;
}
// извлечения содержимого каждого множества из вектора sets и сохранения этого содержимого
vector<string> saveFillPlenty(vector<string> sets) {
    int numSets = sets.size(); //определяет размер, кол-во множеств
    vector<string> fillPlenty(numSets); //хранить содержимое каждого множества.
    for (int i = 0; i < numSets; i++) {
        fillPlenty[i] = sets[i].substr(2, sets[i].length() - 3); //substr() используется для извлечения подстроки из строки.
    }
    return fillPlenty;
}
//разделения множеств на отдельные элементы
vector<vector<string>> splitSets(vector<string> sets, char delimiter) {
    int numSets = sets.size();
    vector<vector<string>> elements(numSets); //Создает двумерный вектор строк elements с размером, равным количеству множеств в sets.
    // Каждый внутренний вектор будет хранить отдельные элементы множества.
    for (auto i = 0; i < numSets; i++) {
        string buff;

        buff = sets[i].substr(3, sets[i].length() - 4); // Изменено с учетом символов { и }
        stringstream ss(buff); //Создается строковый поток ss, который позволит разбивать строку buff на элементы.
        string token; //для временного хранения элементов множества
        string element = ""; //хранения строки элементов множества.
        int setOpened = 0; //отслеживания, сколько раз открывается множество
        while (getline(ss, token, delimiter)) {
            element += token + ',';
        }
        element.pop_back(); // Убираем лишнюю запятую в конце строки
        stringstream element_ss(element);
        while (getline(element_ss, token, ',')) {
            elements[i].push_back(token); // Добавляем элементы вектора
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

//разность считаем
vector<string> setDifference(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result;

    // Копируем все элементы из первого множества
    result = set1;

    // Удаляем элементы второго множества из результата
    for (const auto &elem : set2) {
        auto it = find(result.begin(), result.end(), elem);
        if (it != result.end()) {
            result.erase(it);
        }
    }

    return result;
}
//«приятном для восприятия») формате
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

string Start(vector<string> sets) {
    getNamePlenty(sets);

    vector<vector<string>> elements;
    elements = splitSets(sets, DELIMITER_SYMBOL);

    // Проверяем, что у нас есть как минимум два множества для вычисления разности
    if (elements.size() < 2) {
        cout << "Error: Need at least two sets to compute difference!" << endl;
        return "";
    }

    // Вычисляем разность между первыми двумя множествами
    vector<string> result = setDifference(elements[0], elements[1]);

    cout << "\nDifference: ";
    cout << prettify(result) << endl;
    return prettify(result);
}

#endif //LABA2_HEADER_H
