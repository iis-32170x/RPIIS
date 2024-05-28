#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> Read(string path) {
    ifstream f; // Создаем объект для работы с файлом ввода
    f.open(path);
    if (!f.is_open()) {
        cout << "Error while opening file!" << endl;
        exit(0);
    }
    vector<string> sets;
    string buff;
    while (getline(f, buff)) {
        size_t found = buff.find('='); // Ищем позицию символа '=' в текущей строке
        if (found != string::npos) {
            string dataAfterEqualSign = buff.substr(found + 1); // Получаем подстроку, начиная с символа после '='
            sets.push_back(dataAfterEqualSign);
            cout << "Множество: " << dataAfterEqualSign << endl;

            int open = 0, close = 0;
            for (char ch : dataAfterEqualSign) { // ch  поочередно содержать каждый символ из строки 'dataAfterEqualSign'
                if (ch == '{' || ch == '<') open++;//  количество открывающих и закрывающих скобок
                if (ch == '}' || ch == '>') close++;
            }
            if (open != close) {
                cout << "Проверьте правильность ввода!" << endl;
                cout << "Количество '{' не равно количеству '}'" << endl;
                exit(0);
            }
        }
    }
    f.close();
    return sets;
}

vector<string> Write(vector<string> sets, int& number) { // вектор счетчика
    vector<string> FULLset(sets.size());  // Создаем новый вектор строк FULLset, который будет хранить копию переданного вектора sets
    for (int i = 0; i < sets.size(); i++) {
        FULLset[i] = sets[i];
        number++;
    }
    return FULLset;
}

vector<string> Analys(const string& input) {
    vector<string> elements;
    size_t pos = 1;// для отслеживания текущей позиции в строке
    string buffer;
    int openBraces = 1; // для подсчета открывающих скобок
    for (; pos < input.length(); pos++) {     // итерация по каждому символу в строке input
        char c = input[pos];
        if (c == '{' || c == '<') {
            openBraces++;
            if (openBraces == 2 && !buffer.empty()) { // если это вторая открывающая скобка и буфер не пустой
                elements.push_back(buffer);  // добавить содержимое буфера в вектор элементов
                buffer.clear();
            }
            buffer += c; //  текущий символ в буфер
        }
        else if (c == '}' || c == '>') {
            openBraces--;
            if (openBraces > 0) {
                buffer += c;
            }
            if (openBraces == 0) { //количество открывающих скобок стало равно 0 (закончился один элемент)
                elements.push_back(buffer);
                buffer.clear();
            }
        }
        else if (openBraces == 1) { //количество открывающих скобок равно 1 (находимся вне скобок)
            
            if (c == ',') {
                elements.push_back(buffer);
                buffer.clear();
            }
            else {
                buffer += c;
            }
        }
        else {
            buffer += c;
        }
    }
    return elements; // возвращаем вектор строк , содержащий разобранные элементы
}

vector<vector<string>> subsets(vector<string> sets) {
    vector<vector<string>> subsets;
    for (int i = 0; i < sets.size(); i++) {  // итерация по каждому множеству в переданном векторе sets
        subsets.push_back(Analys(sets[i])); // функция Analys для разбора текущего множества, результат в вектор subsets
        for (const auto& element : subsets[i]) { //  элементы подмножества на экран
            cout << element << " ";
        }
        cout << " - Элементы " << i + 1 << " множества." << endl;
    }
    return subsets;
}

string intersection(vector<string>& set1, vector<string>& set2) {
    string result;
    bool isFirstElement = true; //   является ли текущий элемент первым в результирующей строке

    for (auto it1 = set1.begin(); it1 != set1.end();) { //от начала до конца множества 
        bool found = false;
        bool found = false;
        for (auto it2 = set2.begin(); it2 != set2.end();) { 
            if (*it1 == *it2) { 
                if (!isFirstElement) {  // если текущий элемент не первый в результирующей строке, добавляем перед ним запятую
                   
                    result += ",";
                }
                result += *it1;
                isFirstElement = false; //  флаг как false, так как первый элемент добавлен

                it2 = set2.erase(it2); // удаление найденный элемент из второго множества
                found = true;
                break;
            }
            else {
                ++it2;
            }
        }
        if (found) {
            it1 = set1.erase(it1);
        }
        else {
            ++it1;
        }
    }

    if (result.empty()) {
        return "{}";
    }

    return "{" + result + "}";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int sets_q = 0;  // для хранения количества множеств
    string path = "set.txt";
    auto Sets = Write(Read(path), sets_q);
    auto Subsets = subsets(Sets); // функция subsets для создания подмножеств для каждого множества из вектора Sets

    if (Subsets.size() < 2) {
        cout << "Недостаточно множеств для нахождения пересечения!" << endl;
        return 0;
    }

    string result = intersection(Subsets[0], Subsets[1]); //  пересечение первых двух подмножеств

    for (int i = 2; i < sets_q; i++) {
        auto help_intersec = Analys(result); // анализируем  результат на предмет совпадений и сохраняем его в переменную help_intersec
        result = intersection(help_intersec, Subsets[i]);  //  пересечение текущего подмножества с предыдущим результатом и сохраняем результат в переменную result
    }

    cout << result << " - РЕЗУЛЬТАТ" << endl;
    return 0;
}