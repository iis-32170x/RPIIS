# Лабораторная работа №1
# Цель
Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки конкретной структуры данных.
# Задача
Организовать структуру данных Бор (Префиксное дерево), написать функции добавления, удаления и поиска строки в нём.
# Список используемых понятий
`Бор` — структура данных для хранения набора строк, представляющая из себя подвешенное дерево с символами на рёбрах. Строки получаются последовательной записью всех символов, хранящихся на рёбрах между корнем бора и терминальной вершиной.(источник:
https://neerc.ifmo.ru/wiki/index.php?title=%D0%91%D0%BE%D1%80)
# Описание алгоритмов
## Описание структуры узла
```C++
class Node
{
public:
	std::vector<Node*> front_ptrs = { nullptr };//Вектор указателей на потомков данного узла
	Node* back_ptr;//Указатель на предка данного узла
	char c;//Символ, хранящийся в этом узле
	int num = 0;//Количество потомков
	bool is_root = false;//Обозначение, является ли узел корнем
	bool end = false;//Обозначение, является ли этот узел концом слова
	Node()//Конструктор для корневого узла
  {
	  is_root = true;
  }
	Node(char c)//Конструктор для обычного узла (с указанием символа, хранящегося в нём)
  {
	this->c = c;
  }
	Node(Node* p)//Конструктор для узла, предшествующего корневому
  {
	this->front_ptrs[0] = p;
  }
};
```
## Функция добавления строки в дерево
```С++
void AddString(string s, Node* root)
{
	Node* current = root;//Текущая вершина при обходе дерева
	Node* ptr;//Вспомогательный указатель
	int i, j;//Счётчики
	bool fnd;//Вспомогательное обозначение
	for (i = 0; i < s.size(); i++)//Обход введённой строки
	{
		fnd = false;
		for (j = 0; j < current->front_ptrs.size(); j++)//Обход указателей текущего узла
		{
			ptr = current->front_ptrs[j];
			if (ptr != nullptr)
			{
				if (s[i] == ptr->c)//Если среди потомков найден узел, содержащий текущий символ строки, просто переходим на него 
				{
					current = current->front_ptrs[j];
					fnd = true;
					break;
				}
			}
		}
		if (fnd == false)//Если не найден, создаём новый узел
		{
			if (current->num == 0)
				current->front_ptrs[current->num] = new Node(s[i]);
			else
				current->front_ptrs.push_back(new Node(s[i]));
			current->num++;
			ptr = current->front_ptrs[current->num - 1];
			ptr->back_ptr = current;//Присваем указателю на предка его адрес
			current = current->front_ptrs[current->num - 1];
		}
		if (i == s.size() - 1)//Если дошли до конца строки, помечаем текущий узел, как конец слова
			current->end = true;
	}
	cout << "Строка добавлена" << endl << endl;
}
```
## Функция удаления строки
```C++
int DelString(string s, Node* root)
{
	Node* current = root;
	Node* ptr;
	int i, j;
	bool fnd = false;
	for (i = 0; i < s.size(); i++)//Обход строки для попадания в её конец и проверка на существование слова в боре
	{
		for (j = 0; j < current->front_ptrs.size(); j++)
		{

			ptr = current->front_ptrs[j];
			if (ptr == nullptr)//Если наткнулись на nullptr, раньше конца слова, строки в боре нет
			{
				cout << "Строка не найдена" << endl << endl;
				return 1;
			}
			if (s[i] == ptr->c)//Если нашли потомка со следующим в строке символом, переходим на него
			{
				current = current->front_ptrs[j];
				fnd = true;
				break;
			}
		}
		if (fnd == false)//Если не нашли, строки в боре нет
		{
			cout << "Строка не найдена" << endl << endl;
			return 1;
		}
	}
	if (current->end != true)//Если дошли до последнего символа в строке, но текущий узел не помеченым концом, строка в бор не добавлялась
	{
		cout << "Строка не найдена" << endl << endl;
		return 1;
	}
	for (i = s.size() - 1; i >= 0; i--)//Начинаем удаление с последнего симсвола
	{
		if (current->num < 1 && current->end == false)//Если этот узел не имел предков кроме удалённого и не является концом другого слова, производим его удаление
		{
			current = current->back_ptr;
			for (j = 0; j < current->front_ptrs.size(); j++)
			{
				ptr = current->front_ptrs[j];
				if (s[i] == ptr->c)
				{
					delete current->front_ptrs[j];
					current->front_ptrs.erase(current->front_ptrs.begin() + j);
					break;
				}
			}
			current->num--;
		}
		else
		{
			if (i == s.size() - 1)//Если не можем удалить последний узел слова, обозначаем, что это больше не его конец
				current->end = false;
			break;
		}
	}
	cout << "Строка удалена" << endl << endl;
	return 0;
}
```
