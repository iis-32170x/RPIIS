#ifndef LAB2_H //для предотвращения многократного включения одного и того же заголовочного файла в программу
#define LAB2_H

// вектор.ф.1 (SetRecord)-чтение из файла;
//вектор1 (sets) - полная строчка из файла;
//вектор.ф.2 (CopyingNames) - забираем названия мн-в; 
//вектор2 (Names_of_sets) - названия мн-в;
//вектор.ф.3 (FullRecord) - чтение мноства;
//вектор3 (FULLset) - {1, 2, 3, 4, 5};
//вектор.ф.4 (MakeElements) - формируем элементы элементы;
//вектор4 (elements) - элементы мн-ва, там токены;
//вектор.ф.5 (Intersection) - пересекаем;
//вектор5 (result) -  элементы пересечения;
//вектор.ф.6 (Improove) - выводим крсивый исходник, + пересечение;
//стринг6 (result) - красивое мн-во пересечений;


//
// Created by Сергиевич Дарья on 26.02.24.
//


#include "Header.h"  // Подключение пользовательского заголовочного файла Header.h

#include <iostream>   // Ввод/вывод стандартных потоков данных
#include <fstream>    // Работа с файлами
#include <string>     // Работа со строками
#include <vector>     // Работа с динамическими массивами
#include <sstream>    // Работа с потоками ввода/вывода
#include <algorithm>  // Алгоритмы для работы с контейнерами и итераторами

using namespace std;

constexpr auto OPENSET_SYMBOL = '{';
constexpr auto CLOSESET_SYMBOL = '}';
constexpr auto DELIMITER_SYMBOL = ',';

string path;
ifstream f;

//-----------------------------------------ЧИТАЕМ_ФАЙЛИК---------------------------------------------------

vector<string> SetRecord(string path) {
    f.open(path);
    if (!f.is_open())
        cout << "Error while opening file!" << endl;
    vector<string> sets;
    int line = 0;
    while (!f.eof()) {
        line++;
        string buff;
        getline(f, buff);
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int open = 0;
            int close = 0;
            for (int i = 0; i < buff.length(); i++) {
                if (buff[i] == OPENSET_SYMBOL)
                    open++;
                if (buff[i] == CLOSESET_SYMBOL)
                    close++;
            }
            if (open != close) {
                cout << "Check input for correctness!" << endl;
                cout << "Number of '{' is not equal to number of '}'" << endl;
                exit(0);
            }
            sets.push_back(buff);
        }
        else {
            cout << "Check input for correctness!" << endl;
            exit(0);
            break;
        }
    }
    return sets;
}

//-----------------------------------------ЗАБИРАЕМ_ИМЕНА---------------------------------------------------

vector<string> CopyingNames(vector<string> sets) {
    int numberSets = sets.size();
    vector<string> Names_of_sets(numberSets);
    for (int i = 0; i < numberSets; i++) {
        Names_of_sets[i] = sets[i][0];
    }
    return Names_of_sets;
}

//--------------------------------------------ЧИТАЕМ_МНОСТВА------------------------------------------------

vector<string> FullRecord(vector<string> sets) {
    int numberSets = sets.size();
    vector<string> FULLset(numberSets);
    for (int i = 0; i < numberSets; i++) {
        FULLset[i] = sets[i].substr(2, sets[i].length() - 3);
    }
    return FULLset;
}

//--------------------------------------------ВЫДЕЛЯЕМ_ЭЛЕМЕНТЫ------------------------------------------------

vector<vector<string>> MakeElements(vector<string> sets, char delimiter) {
    int numberSets = sets.size();
    vector<vector<string>> elements(numberSets);
    for (auto i = 0; i < numberSets; i++) {
        string buff;

        buff = sets[i].substr(3, sets[i].length() - 4); // убираем скобки
        stringstream potok(buff); //для разбиения строки на отдельные токены с использованием разделителя
        string token;
        string element = "";
        int setOpened = 0;
        while (getline(potok, token, delimiter)) { //до тех пор, пока из потока potok можно извлечь следующий токен
            element += token + DELIMITER_SYMBOL;
        }
        element.pop_back(); //строка
        stringstream element_potok(element);
        while (getline(element_potok, token, DELIMITER_SYMBOL)) {
            elements[i].push_back(token); //вектор
        }
    }

    vector<string> Names = CopyingNames(sets);
    vector<string> FULLMN = FullRecord(sets);
    int numSetsName = Names.size();
    for (int i = 0; i < numberSets; i++) {                          //проверка наличия совпадений между элементами каждого подмножества 
        for (int k = 0; k < elements[i].size(); k++) {              //и именами вектора Nsmes. Если найдено совпадение 
            for (int j = 0; j < numSetsName; j++) {                 //и это не текущий индекс, то элемент заменяется 
                if ((Names[j] == elements[i][k]) && (j != i)) {     //на соответствующий элемент из вектора FULLMN.
                    elements[i][k] = FULLMN[j];
                }
            }
        }
    }
    return elements;
}

//--------------------------------------------НАХОДМ_ПЕРЕСЕЧЕНИЕ------------------------------------------------

vector<string> Intersection(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result;

    for (const auto& elem : set1) {
        if (find(set2.begin(), set2.end(), elem) != set2.end()) {
            result.push_back(elem);
        }
    }

    return result;
}



string Improove(const vector<string>& set) {
    string result(1, OPENSET_SYMBOL);

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
    CopyingNames(sets);

    vector<vector<string>> elements;
    elements = MakeElements(sets, DELIMITER_SYMBOL);

    if (elements.size() < 2) {
        cout << "Error: Need at least two sets to compute intersection!" << endl;
        return "";
    }

    vector<string> result = Intersection(elements[0], elements[1]);

    cout << "\nIntersection: ";
    cout << Improove(result) << endl;
    return Improove(result);
    f.close();
}

#endif