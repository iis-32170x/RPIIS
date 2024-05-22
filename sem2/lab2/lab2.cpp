#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"


int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream file1("input_A.txt");
    std::ifstream file2("input_B.txt");

    if (!file1.is_open() || !file2.is_open())
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 0;
    }

    std::string setString1, setString2;
    std::getline(file1, setString1);
    std::getline(file2, setString2);

    file1.close();
    file2.close();

    std::vector<std::string> set1, set2;
    set1 = parseString(setString1);
    set2 = parseString(setString2);

    std::cout << "Множество А: " << vectorToString(set1) << std::endl << std::endl;
    std::cout << "Множество B: " << vectorToString(set2) << std::endl << std::endl;

    std::vector<std::string> difference = setDifference(set1, set2);

    std::cout << "Множество С (разность А и В): " << vectorToString(difference) << std::endl;

    return 0;
}