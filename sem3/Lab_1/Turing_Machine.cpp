/**
 * @file Turing_Machine.cpp
 * @brief Реализация методов класса Turing_Machine
 */

#include "Turing_Machine.h"
#include <iostream>

 /**
  * @brief Проверяет, входит ли символ в алфавит
  *
  * @param symbol Символ для проверки
  * @return true Если символ входит в алфавит
  * @return false Если символ не входит в алфавит
  */
bool Turing_Machine::Check_Enter(char symbol) {
	for (char i : alphabet)
		if (i == symbol)
			return true;
	return false;
}

/**
 * @brief Проверяет, предусмотрен ли конец алгоритма
 *
 * @return true Если конец алгоритма предусмотрен
 * @return false Если конец алгоритма не предусмотрен
 */
bool Turing_Machine::Check_End() {
	for (int i = 0; i < rules.size(); i++)
		for (int j = 0; j < rules[i].size(); j++)
			for (char s : rules[i][j])
				if (s == '!')
					return true;
	std::cout << "Не предусмотрен конец алгоритма" << std::endl;
	rules_cond.clear();
	rules.clear();
	return false;
}

/**
 * @brief Проверяет правильность заданного правила
 *
 * @param rule Правило для проверки
 * @return true Если правило правильно
 * @return false Если правило неправильно
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
 * @brief Находит правило для текущего состояния и символа
 *
 * @param rules Вектор правил
 * @param current_cond Текущее состояние
 * @param symbol Символ для поиска правила
 * @return Правило для текущего состояния и символа
 */
string Turing_Machine::Find_Rule(vector<vector<string>> rules, int current_cond, char symbol) {
	for (int i = 0; i < alphabet.size(); i++)
		if (symbol == alphabet[i])
			return rules[current_cond][i];
}

/**
 * @brief Сдвигает головку влево
 */
void Turing_Machine::Left() {
	if (current == 1)
		line = "~" + line;
	current--;
}

/**
 * @brief Сдвигает головку вправо
 */
void Turing_Machine::Right() {
	if (current == line.length() - 2)
		line = line + "~";
	current++;
}

/**
 * @brief Записывает символ на текущую позицию ленты
 *
 * @param i Символ для записи
 */
void Turing_Machine::Symbol(char i) {
	line[current] = i;
}

/**
 * @brief Меняет текущее состояние машины
 *
 * @param num Новое состояние
 */
void Turing_Machine::Change_Cond(int num) {
	current_cond = num;
}

/**
 * @brief Устанавливает количество состояний
 *
 * @param cond Количество состояний
 */
void Turing_Machine::Set_Cond(int cond) {
	this->cond = cond;
}

/**
 * @brief Устанавливает алфавит
 *
 * @param alphabet Алфавит
 */
void Turing_Machine::Set_Alphabet(string alphabet) {
	this->alphabet = alphabet + '~';
}

/**
 * @brief Устанавливает строку на ленту
 *
 * @param line Строка для установки
 * @return true Если строка корректна
 * @return false Если строка некорректна
 */
bool Turing_Machine::Set_Line(string line) {
	for (char i : line)
		if (!Check_Enter(i))
		{
			cout << "Неправильный ввод";
			return false;
		}
	this->line = "~" + line + "~";
	return true;
}

/**
 * @brief Устанавливает правило
 * @param rule Правило для установки
 * @return true Если правило корректно
 * @return false Если правило некорректно
 */
bool Turing_Machine::Set_Rule(string rule) {
	if (!Check_Rule(rule))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	rules_cond.push_back(rule);
	return true;
}

/**
 * @brief Добавляет правила состояния в вектор правил всех состояний
 */
void Turing_Machine::Push_Back() {
	rules.push_back(rules_cond);
	rules_cond.clear();
}

/**
 * @brief Изменяет символ на ленте
 *
 * @param num Индекс символа для изменения
 * @param symbol Новый символ
 * @return true Если символ корректный
 * @return false Если символ некорректный
 */
bool Turing_Machine::Change_Line(int num, char symbol) {
	if (!Check_Enter(symbol))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	line[num] = symbol;
	return true;
}

/**
 * @brief Изменяет правило для заданного состояния и символа
 *
 * @param num Номер состояния
 * @param c Символ
 * @param rule Новое правило
 * @return true Если правило корректно
 * @return false Если правило некорректно
 */
bool Turing_Machine::Change_Rule(int num, char c, string rule) {
	int i;
	if ((num < 0) || (num >= cond))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	if (!Check_Enter(c))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	if (!Check_Rule(rule))
	{
		cout << "Неправильный ввод" << endl;
		return false;
	}
	for (i = 0; alphabet[i] != c;)
		i++;
	rules[num][i] = rule;
	cout << endl;
	return true;
}

/**
 * @brief Показывает таблицу правил
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
 * @brief Показывает текущее состояние ленты
 */
void Turing_Machine::Show_Line() {
	cout << "Слово на ленте: " << line << endl;
}

/**
 * @brief Запускает машину Тьюринга
 *
 * @param c Флаг для отображения информации после каждого шага
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