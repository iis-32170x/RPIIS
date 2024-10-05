/**
 * @file Turing_Machine.h
 * @brief ������������ ���� ��� ������ Turing_Machine
 */

#pragma once
#include <vector>
#include <string>
using namespace std;

/**
 * @class Turing_Machine
 * @brief �����, �������������� ������ ��������
 */
class Turing_Machine
{
private:
    string line;                      ///< �����
    string alphabet;                  ///< �������
    int cond;                         ///< ���������� ���������
    int current;                      ///< ������� ������� �� �����
    int current_cond;                 ///< ������� ���������
    vector<string> rules_cond;        ///< ������� ��� �������� ���������
    vector<vector<string>> rules;     ///< ������ ������ ���� ���������

    bool Check_Rule(string rule);     ///< ��������� ������������ ����� �������
    string Find_Rule(vector<vector<string>> rules, int current_cond, char symbol); ///< ������� ������� ��� �������� ���������
    void Left();                      ///< �������� ������� �����
    void Right();                     ///< �������� ������� ������
    void Symbol(char i);              ///< ���������� ������ �� �����
    void Change_Cond(int num);        ///< ������ ������� ���������

public:
    bool Check_Enter(char symbol);    ///< ���������, ������ �� ������ � �������
    bool Check_End();                 ///< ���������, ������������ �� ����� ������ ����� ���������
    void Set_Cond(int cond);          ///< ���� ���������� ���������
    void Set_Alphabet(string alphabet); ///< ���� ��������
    bool Set_Line(string line);        ///< ���� �����
    bool Set_Rule(string rule);       ///< ���� ������ ��� ���������
    void Push_Back();                 ///< ��������� ������� ��������� � ������ ������ ���� ���������.
    bool Change_Line(int num, char symbol); ///< �������� ������ �� �����
    bool Change_Rule(int num, char c, string rule); ///< �������� �������
    void Show_Table();                ///< ������� ������� ������
    void Show_Line();                 ///< ������� �����
    void Run_Machine(char c);         ///< ��������� ������ ��������
};

