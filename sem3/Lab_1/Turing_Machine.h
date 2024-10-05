/**
 * @file Turing_Machine.h
 * @brief Заголовочный файл для класса Turing_Machine
 */

#pragma once
#include <vector>
#include <string>
using namespace std;

/**
 * @class Turing_Machine
 * @brief Класс, представляющий машину Тьюринга
 */
class Turing_Machine
{
private:
    string line;                      ///< Лента
    string alphabet;                  ///< Алфавит
    int cond;                         ///< Количество состояний
    int current;                      ///< Текущая позиция на ленте
    int current_cond;                 ///< Текущее состояние
    vector<string> rules_cond;        ///< Правила для текущего состояния
    vector<vector<string>> rules;     ///< Вектор правил всех состояний

    bool Check_Rule(string rule);     ///< Проверяет правильность ввода правила
    string Find_Rule(vector<vector<string>> rules, int current_cond, char symbol); ///< Находит правило для текущего состояния
    void Left();                      ///< Сдвигает головку влево
    void Right();                     ///< Сдвигает головку вправо
    void Symbol(char i);              ///< Записывает символ на ленту
    void Change_Cond(int num);        ///< Меняет текущее состояние

public:
    bool Check_Enter(char symbol);    ///< Проверяет, входит ли символ в алфавит
    bool Check_End();                 ///< Проверяет, предусмотрен ли среди правил конец алгоритма
    void Set_Cond(int cond);          ///< Ввод количества состояний
    void Set_Alphabet(string alphabet); ///< Ввод алфавита
    bool Set_Line(string line);        ///< Ввод ленты
    bool Set_Rule(string rule);       ///< Ввод правил для состояния
    void Push_Back();                 ///< Добавляет правила состояния в вектор правил всех состояний.
    bool Change_Line(int num, char symbol); ///< Изменяет символ на ленте
    bool Change_Rule(int num, char c, string rule); ///< Изменяет правило
    void Show_Table();                ///< Выводит таблицу правил
    void Show_Line();                 ///< Выводит ленту
    void Run_Machine(char c);         ///< Запускает машину Тьюринга
};

