#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include <cctype>

using namespace std;

int input(const string& message) {
    int num;
    cout << message;
    while (!(cin >> num)) {
        cout << "\033[1;31mОшибка ввода! Введите число: \033[0m";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

void ADD(vector<vector<int>>& V) {
    string inputStr;
    cout << "Введите множество в виде {{A1, A2, ...}, {B1, B2, ...}, ...}: ";
    getline(cin, inputStr);

    inputStr = inputStr.substr(1, inputStr.size() - 2);

    vector<int> innerVector;
    stringstream ss(inputStr);
    char ch;
    bool Brackets = false;
    while (ss >> ch) {
        if (ch == '{') {
            innerVector.clear();
            Brackets = true;
        } else if (ch == '}') {
            V.push_back(innerVector);
            Brackets = false;
        } else if (isdigit(ch)) {
            ss.putback(ch);
            int num;
            ss >> num;
            if (Brackets) {
                innerVector.push_back(num);
            } else {
                V.push_back(vector<int>{num});
                if (ss.peek() == ',')
                    ss.ignore();
            }
        }
    }
}

void File(const string& filename) {
    ifstream file(filename); // Открываем файл для чтения

    if (!file.is_open()) {
        cerr << "Невозможно открыть файл." << endl;
        return;
    }

    string line;
    cout << "Содержимое файла " << filename << ":" << endl;
    while (getline(file, line)) { // Читаем файл построчно и выводим на экран
        cout << line << endl;
    }

    file.close();
}

void read(vector<vector<int>>& V, const string& filename) {
    ifstream file(filename);
    string inputStr;
    cout << "Введите множество в виде {{A1, A2, ...}, {B1, B2, ...}, ...}: ";
    getline(cin, inputStr);

    inputStr = inputStr.substr(1, inputStr.size() - 2);

    vector<int> innerVector;
    stringstream ss(inputStr);
    char ch;
    bool Brackets = false;


    cout << "Чтение данных из файла: " << filename << endl;

    string line;
    while (getline(file, line)) {
        inputStr = inputStr.substr(1, inputStr.size() - 2);

        while (ss >> ch) {
            if (ch == '{') {
                innerVector.clear();
                Brackets = true;
            } else if (ch == '}') {
                V.push_back(innerVector);
                Brackets = false;
            } else if (isdigit(ch)) {
                ss.putback(ch);
                int num;
                ss >> num;
                if (Brackets) {
                    innerVector.push_back(num);
                } else {
                    V.push_back(vector<int>{num});
                    if (ss.peek() == ',')
                        ss.ignore();
                }
            }
        }
    }
    cout << "Чтение данных из файла завершено." << endl;
    file.close();
}

bool Check(const vector<int>& A, const vector<int>& B) {
    vector<int> copyA = A;
    vector<int> copyB = B;
    sort(copyA.begin(), copyA.end());
    sort(copyB.begin(), copyB.end());

    return includes(copyA.begin(), copyA.end(), copyB.begin(), copyB.end());
}


int main() {
    setlocale(LC_ALL, "RU");
    int c;
    vector<vector<int>> A;
    vector<vector<int>> B;

    do {
        c = input("Выберите способ ввода (1 - вручную)(2 - из файла): ");
        if (!(c == 1 || c == 2)) {
            cout << "\033[1;31mПовторите ввод: \033[0m";
        }
    } while (!(c == 1 || c == 2));

    cin.ignore();
    if (c == 1) {
        cout << "Ввод множества A:" << endl;
        ADD(A);
        cout << "Ввод множества B:" << endl;
        ADD(B);
    } else if (c == 2) {
        string filename;
        ifstream file;
        bool fileOpened = false;
        do {
            cout << "Введите путь к файлу: ";
            cin >> filename;
            file.open(filename);
            if (!file.is_open()) {
                cout << "\033[1;31mОшибка открытия файла\033[0m" << endl;
            } else {
                fileOpened = true;
            }
        } while (!fileOpened);

        File(filename);
        //read(A, filename);
        //read(B, filename);
        file.close();
    }

    cout << "Результат:" << endl;
    for (const auto& innerVec : A) {
        cout << "{ ";
        for (const auto& num : innerVec) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    cout << "Результат:" << endl;
    for (const auto& innerVec : B) {
        cout << "{ ";
        for (const auto& num : innerVec) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    bool check = false;
    for (const auto& bVector : B) {
        for (const auto& aVector : A) {
            if (aVector.size() == bVector.size()) {
                if (Check(aVector, bVector) || Check(bVector, aVector)) {
                    check = true;
                }
            }
        }
    }

    if (check) {
        cout << "Множество B является подмножеством множества A" << endl;
    } else {
        cout << "Множество B не является подмножеством множества A" << endl;
    }

    return 0;
}
