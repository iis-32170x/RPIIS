/**
 * @file Turing_Machine.cpp
 * @brief ���������� ������� ������ Turing_Machine
 */

#include "Turing_Machine.h"
#include <iostream>

 /**
  * @brief ���������, ������ �� ������ � �������
  *
  * @param symbol ������ ��� ��������
  * @return true ���� ������ ������ � �������
  * @return false ���� ������ �� ������ � �������
  */
bool Turing_Machine::Check_Enter(char symbol) {
	for (char i : alphabet)
		if (i == symbol)
			return true;
	return false;
}

/**
 * @brief ���������, ������������ �� ����� ���������
 *
 * @return true ���� ����� ��������� ������������
 * @return false ���� ����� ��������� �� ������������
 */
bool Turing_Machine::Check_End() {
	for (int i = 0; i < rules.size(); i++)
		for (int j = 0; j < rules[i].size(); j++)
			for (char s : rules[i][j])
				if (s == '!')
					return true;
	std::cout << "�� ������������ ����� ���������" << std::endl;
	rules_cond.clear();
	rules.clear();
	return false;
}

/**
 * @brief ��������� ������������ ��������� �������
 *
 * @param rule ������� ��� ��������
 * @return true ���� ������� ���������
 * @return false ���� ������� �����������
 */
bool Turing_Machine::Check_Rule(string rule) {
	if ((rule.size() < 5) || (rule.size() > 6))
		return false;
	if (!Check_Enter(rule[0]))
		return false;
	if ((rule[2] != 'N') && (rule[2] != 'R') && (rule[2] != 'L'))
		return false;
	if ((((rule[4] != 'q') && ((static_cast<int>(rule[5]) - 48) > cond)) || (rule[4] != 'q') || ((static_cast<int>(rule[5]) - 48) >= cond)) && (rule[4] != '!'))
		return false;
	if ((rule[1] != ' ') || (rule[3] != ' ') || ((rule[1] != ' ') && (rule[3] != ' ')))
		return false;
	if (rule.length() > 6)
		return false;
	if ((rule[4] == 'q') && (rule[rule.length() - 1] == 'q') || ((rule[4] == '!') && (rule[rule.length() - 1] != '!')))
		return false;
	if ((rule[rule.length() - 1] == '!') && (rule[rule.length() - 2] == '!'))
		return false;
	return true;
}
/**
 * @brief ������� ������� ��� �������� ��������� � �������
 *
 * @param rules ������ ������
 * @param current_cond ������� ���������
 * @param symbol ������ ��� ������ �������
 * @return ������� ��� �������� ��������� � �������
 */
string Turing_Machine::Find_Rule(vector<vector<string>> rules, int current_cond, char symbol) {
	for (int i = 0; i < alphabet.size(); i++)
		if (symbol == alphabet[i])
			return rules[current_cond][i];
}

/**
 * @brief �������� ������� �����
 */
void Turing_Machine::Left() {
	if (current == 1)
		line = "~" + line;
	current--;
}

/**
 * @brief �������� ������� ������
 */
void Turing_Machine::Right() {
	if (current == line.length() - 2)
		line = line + "~";
	current++;
}

/**
 * @brief ���������� ������ �� ������� ������� �����
 *
 * @param i ������ ��� ������
 */
void Turing_Machine::Symbol(char i) {
	line[current] = i;
}

/**
 * @brief ������ ������� ��������� ������
 *
 * @param num ����� ���������
 */
void Turing_Machine::Change_Cond(int num) {
	current_cond = num;
}

/**
 * @brief ������������� ���������� ���������
 *
 * @param cond ���������� ���������
 */
void Turing_Machine::Set_Cond(int cond) {
	this->cond = cond;
}

/**
 * @brief ������������� �������
 *
 * @param alphabet �������
 */
void Turing_Machine::Set_Alphabet(string alphabet) {
	this->alphabet = alphabet + '~';
}

/**
 * @brief ������������� ������ �� �����
 *
 * @param line ������ ��� ���������
 * @return true ���� ������ ���������
 * @return false ���� ������ �����������
 */
bool Turing_Machine::Set_Line(string line) {
	for (char i : line)
		if (!Check_Enter(i))
		{
			cout << "������������ ����";
			return false;
		}
	this->line = "~" + line + "~";
	return true;
}

/**
 * @brief ������������� �������
 * @param rule ������� ��� ���������
 * @return true ���� ������� ���������
 * @return false ���� ������� �����������
 */
bool Turing_Machine::Set_Rule(string rule) {
	if (!Check_Rule(rule))
	{
		cout << "������������ ����" << endl;
		return false;
	}
	rules_cond.push_back(rule);
	return true;
}

/**
 * @brief ��������� ������� ��������� � ������ ������ ���� ���������
 */
void Turing_Machine::Push_Back() {
	rules.push_back(rules_cond);
	rules_cond.clear();
}

/**
 * @brief �������� ������ �� �����
 *
 * @param num ������ ������� ��� ���������
 * @param symbol ����� ������
 * @return true ���� ������ ����������
 * @return false ���� ������ ������������
 */
bool Turing_Machine::Change_Line(int num, char symbol) {
	if (!Check_Enter(symbol))
	{
		cout << "������������ ����" << endl;
		return false;
	}
	line[num] = symbol;
	return true;
}

/**
 * @brief �������� ������� ��� ��������� ��������� � �������
 *
 * @param num ����� ���������
 * @param c ������
 * @param rule ����� �������
 * @return true ���� ������� ���������
 * @return false ���� ������� �����������
 */
bool Turing_Machine::Change_Rule(int num, char c, string rule) {
	int i;
	if ((num < 0) || (num >= cond))
	{
		cout << "������������ ����" << endl;
		return false;
	}
	if (!Check_Enter(c))
	{
		cout << "������������ ����" << endl;
		return false;
	}
	if (!Check_Rule(rule))
	{
		cout << "������������ ����" << endl;
		return false;
	}
	for (i = 0; alphabet[i] != c;)
		i++;
	rules[num][i] = rule;
	cout << endl;
	return true;
}

/**
 * @brief ���������� ������� ������
 */
void Turing_Machine::Show_Table() {
	cout << "        ";
	for (char i : alphabet)
		cout << i << "         ";
	cout << endl;
	for (int i = 0; i < rules.size(); i++)
	{
		cout << "q" << i << "    ";
		for (string j : rules[i])
			cout << j << "    ";
		cout << endl;
	}
	cout << endl;
}

/**
 * @brief ���������� ������� ��������� �����
 */
void Turing_Machine::Show_Line() {
	cout << "����� �� �����: " << line << endl;
}

/**
 * @brief ��������� ������ ��������
 *
 * @param c ���� ��� ����������� ���������� ����� ������� ����
 */
void Turing_Machine::Run_Machine(char c) {
	string rule;
	int i;
	current_cond = 0;
	current = 1;
	while (true)
	{
		rule = Find_Rule(rules, current_cond, line[current]);
		for (i = 0; i < rule.size(); i++)
		{
			switch (rule[i])
			{
			case 'R':
				Right();
				break;
			case 'L':
				Left();
				break;
			case 'N':
				break;
			case '!':
				break;
			case 'q':
				Change_Cond(static_cast<int>(rule[i + 1]) - 48);
				i++;
				break;
			case ' ':
				break;
			default:
				Symbol(rule[i]);
				break;
			}
		}
		if (rule[i - 1] == '!')
			break;
		if (c == 'Y')
		{
			Show_Line();
			Show_Table();
		}
	}
	cout << endl;
}