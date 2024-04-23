# Лабораторная работа N2  


### Цель работы  
----  


Изучить основы теории множеств.


### Задача 
----  


Реализовать программу, формирующую множество равное декартовому произведению
произвольного количества исходных множеств.


### Алгоритм  
----  


Рассмотрим алгоритм решения задачи.  
1.Определяем количество заданных пользователем множеств.   
2.Считываем все элементы всех множеств из файла.  
3.Проверяем на корректность ввода данные из файла.  
4.Обрабатываем элементы множества.  
5.Выполняем декартовое произведение.  


#### Определение количества заданных пользователем множеств
----  


В этой функции мы считаем количество строк.
```C++
	int number_of_sets()
{
	int number_of_sets = 0;
	string str;
	ifstream startfile;
	startfile.open("Начальные_данные.txt");
	if (!(startfile.is_open()))
	{
		cout << "File does not open";
		exit(0);
	}
	while (!startfile.eof())
	{
		getline(startfile, str);
		++number_of_sets;
	}
	startfile.close();
	return number_of_sets;
}
```   


#### Считывание всех элементов всех множеств из файла и обработка элементов множества.   
----  

 
В функции read выполняется два пункта алгоритма.Сначала считываются все элементы:  
```C++
	ifstream startfile;
	string elem;
	string* str = new string[number_of_sets];
	startfile.open("Начальные_данные.txt");
	for (int i = 0; i < number_of_sets; ++i)
		getline(startfile, str[i]);
	startfile.close();
```  
Потом вызывается функция proverka,которая проверяет на корректность ввода данные из файла.  
После этого начинается обработка элементов множеств.  
```C++
	int j = 0;
	for (int i = 0; i < number_of_sets; ++i)
	{
		for (; str[i][j] != '='; ++j);
		j = j + 2;
		if (str[i][j - 1] == '{' && str[i][j] == '}')
		{
			cout << "Result:{}";
			exit(0);
		}
		while (j < str[i].length() - 1)
		{
			if (elem == "{")
			{
				string result;
				if (str[i][j] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				int kod = 1;
				while (kod != 0)
				{
					elem += str[i][j];
					if (str[i][j] == '}') --kod;
					if (str[i][j] == '{') ++kod;
					++j;
				}
				if (str[i][j - 2] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				if (str[i][j] != ',' && j != (str[i].length() - 1))
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].subset_sort(elem,result);
				elem.clear();
				a[i].add_element(result);
				++j;
			}
			if (elem == "<")
			{
				if (str[i][j] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				int kod = 1;
				while (kod != 0)
				{
					vector<string> check_elements;
					if (str[i][j] == '{')
					{
						string subset = "{", result = "";
						int kod2 = 1;
						++j;
						while (kod2 != 0)
						{
							subset += str[i][j];
							if (str[i][j] == '}') --kod2;
							if (str[i][j] == '{') ++kod2;
							++j;
						}
						if (str[i][j - 1] == ',')
						{
							cout << "Incorrect data";
							exit(0);
						}
						if (str[i][j] != ',' && j != (str[i].length() - 2)&& str[i][j] != '>')
						{
							cout << "Incorrect data1";
							exit(0);
						}
						a[i].subset_sort(subset, result);
						elem += result;
					}
					else {
						elem += str[i][j];
						if (str[i][j] == '>') --kod;
						if (str[i][j] == '<') ++kod;
						++j;
					}
				}
				if (str[i][j - 2] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				if (str[i][j] != ',' && j != (str[i].length() - 1))
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].add_element(elem);
				elem.clear();
				++j;
			}
			if (str[i][j] == ',')
			{
				for (int i = 0; i < elem.length(); ++i)
				{
					if (elem[i] == '{' || elem[i] == '}' || elem[i] == '<' || elem[i] == '>')
					{
						cout << "Incorrect data";
						exit(0);
					}
				}
				if (static_cast<int>(elem[0]) < 58)
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].add_element(elem);
				elem.clear();
				++j;
			}
			if (j == (str[i].length() - 2))
			{
				while (str[i][j] != '}')
				{
					elem += str[i][j];
					++j;
				}
				for (int i = 0; i < elem.length(); ++i)
				{
					if (elem[i] == '{' || elem[i] == '}' || elem[i] == '<' || elem[i] == '>')
					{
						cout << "Incorrect data";
						exit(0);
					}
				}
				if (static_cast<int>(elem[0]) < 58)
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].add_element(elem);
				break;
			}
			elem += str[i][j];
			++j;
		}
		j = 0;
		elem.clear();
	}
}
```  
Вся функция выглядит так:  
```C++
void read(int number_of_sets, multiplicity* a)
{
	ifstream startfile;
	string elem;
	string* str = new string[number_of_sets];
	startfile.open("Начальные_данные.txt");
	for (int i = 0; i < number_of_sets; ++i)
		getline(startfile, str[i]);
	startfile.close();
	proverka(str, number_of_sets);
	int j = 0;
	for (int i = 0; i < number_of_sets; ++i)
	{
		for (; str[i][j] != '='; ++j);
		j = j + 2;
		if (str[i][j - 1] == '{' && str[i][j] == '}')
		{
			cout << "Result:{}";
			exit(0);
		}
		while (j < str[i].length() - 1)
		{
			if (elem == "{")
			{
				string result;
				if (str[i][j] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				int kod = 1;
				while (kod != 0)
				{
					elem += str[i][j];
					if (str[i][j] == '}') --kod;
					if (str[i][j] == '{') ++kod;
					++j;
				}
				if (str[i][j - 2] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				if (str[i][j] != ',' && j != (str[i].length() - 1))
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].subset_sort(elem,result);
				elem.clear();
				a[i].add_element(result);
				++j;
			}
			//Добавить сортировку в картежах
			if (elem == "<")
			{
				if (str[i][j] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				int kod = 1;
				while (kod != 0)
				{
					vector<string> check_elements;
					if (str[i][j] == '{')
					{
						string subset = "{", result = "";
						int kod2 = 1;
						++j;
						while (kod2 != 0)
						{
							subset += str[i][j];
							if (str[i][j] == '}') --kod2;
							if (str[i][j] == '{') ++kod2;
							++j;
						}
						if (str[i][j - 1] == ',')
						{
							cout << "Incorrect data";
							exit(0);
						}
						if (str[i][j] != ',' && j != (str[i].length() - 2)&& str[i][j] != '>')
						{
							cout << "Incorrect data1";
							exit(0);
						}
						a[i].subset_sort(subset, result);
						elem += result;
					}
					else {
						elem += str[i][j];
						if (str[i][j] == '>') --kod;
						if (str[i][j] == '<') ++kod;
						++j;
					}
				}
				if (str[i][j - 2] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
				if (str[i][j] != ',' && j != (str[i].length() - 1))
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].add_element(elem);
				elem.clear();
				++j;
			}
			if (str[i][j] == ',')
			{
				for (int i = 0; i < elem.length(); ++i)
				{
					if (elem[i] == '{' || elem[i] == '}' || elem[i] == '<' || elem[i] == '>')
					{
						cout << "Incorrect data";
						exit(0);
					}
				}
				if (static_cast<int>(elem[0]) < 58)
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].add_element(elem);
				elem.clear();
				++j;
			}
			if (j == (str[i].length() - 2))
			{
				while (str[i][j] != '}')
				{
					elem += str[i][j];
					++j;
				}
				for (int i = 0; i < elem.length(); ++i)
				{
					if (elem[i] == '{' || elem[i] == '}' || elem[i] == '<' || elem[i] == '>')
					{
						cout << "Incorrect data";
						exit(0);
					}
				}
				if (static_cast<int>(elem[0]) < 58)
				{
					cout << "Incorrect data";
					exit(0);
				}
				a[i].add_element(elem);
				break;
			}
			elem += str[i][j];
			++j;
		}
		j = 0;
		elem.clear();
	}
	for (int i = 0; i < number_of_sets; ++i)
	{
		a[i].sorting_elements();
		a[i].Check_for_identical_elements();
	}
}
```  


#### Проверка на корректность ввода данных из файла  
----  


```C++
	void proverka(string* str, int number_of_sets)
{
	if (number_of_sets < 2)
	{
		cout << "Minimum two sets required";
		exit(0);
	}
	for (int i = 0; i < number_of_sets; ++i)
	{
		int num_of_brackets = 0, number_of_triangle_brackets = 0, kod11 = -1;
		int Number_of_characters_is_equal = 1;
		if (str[i].length() == 0)
		{
			cout << "Incorrect data";
			exit(0);
		}
		if ((str[i][str[i].length() - 2] == ',') || str[i][0] == '=')
		{
			cout << "Incorrect data";
			exit(0);
		}
		for (int j = 0; j < str[i].length(); ++j)
		{
			if (str[i][j] == '{')
			{
				++num_of_brackets;
				++kod11;
			}
			if (str[i][j] == '}') --num_of_brackets;
			if ((num_of_brackets <= 0) && (kod11 > -1) && (j != str[i].length() - 1))
			{
				cout << "Incorrect data";
				exit(0);
			}


			if (str[i][j] == '<') ++number_of_triangle_brackets;
			if (str[i][j] == '>') --number_of_triangle_brackets;
			if (number_of_triangle_brackets < 0)
			{
				cout << "Incorrect data";
				exit(0);
			}

			if (str[i][j] == '=') --Number_of_characters_is_equal;

			if ((static_cast<int>(str[i][j]) < 48 && str[i][j] != ',' && static_cast<int>(str[i][j]) > 32) || (static_cast<int>(str[i][j]) < 97 && static_cast<int>(str[i][j]) > 90) || (static_cast<int>(str[i][j]) < 65 && static_cast<int>(str[i][j]) > 57 && str[i][j] != '<' && str[i][j] != '>' && str[i][j] != '=') || static_cast<int>(str[i][j]) > 125 || str[i][j] == '|')
			{
				cout << "Incorrect data";
				exit(0);
			}
			if (j + 1 < str[i].length())
			{
				if (str[i][j] == '<' && str[i][j + 1] == '>')
				{
					cout << "Incorrect data";
					exit(0);
				}
				if (str[i][j] == ',' && str[i][j + 1] == ',')
				{
					cout << "Incorrect data";
					exit(0);
				}
			}
		}
		if (number_of_triangle_brackets > 0 || num_of_brackets > 0 || Number_of_characters_is_equal < 0|| Number_of_characters_is_equal == 1)
		{
			cout << "Incorrect data";
			exit(0);
		}
	}
}
```  


#### Выполнение декартового произведения  
----  


```C++
	void Cartesian_product(int number_of_sets, multiplicity* a, int i, vector<string>& result)
{
	if (i != number_of_sets - 1)
	{
		for (int j = 0; j < a[i].amount_of_elements(); ++j)
		{
			result.push_back(a[i].get_ellement(j)); result.push_back(",");
			Cartesian_product(number_of_sets, a, i + 1, result);
			result.pop_back(); result.pop_back();
		}
	}
	else
	{
		int n = 0;
		for (int j = 0; j < a[i].amount_of_elements(); ++j)
		{
			cout << "<";
			for (int k = 0; k < result.size(); ++k)
				cout << result[k];
			cout << a[i].get_ellement(j) << ">\n";
		}
	}
}
```  


#### Реализация множеств  
----  


Множество в моей программе это класс,членом которого является вектор,содержащий все элементы множества.А методы взаимодействуют с этим членом добавляя в вектов элементы и получая элементы множества из вектора  
```C++
class multiplicity
{
private:
	vector<string> elements;
public:
	void sorting_elements()
	{
		if (elements.size() == 0) return;
		for (int i = 0; i < (elements.size() - 1); i++)
			for (int j = i + 1; j < elements.size(); j++)
				if (elements[i] > elements[j]) { // Переставляем элементы
					swap(elements[i], elements[j]);
				}
	}

	void Check_for_identical_elements()
	{
		if (elements.size() > 0)
			for (int i = 0; i < (elements.size() - 1); i++)
				for (int j = i + 1; j < elements.size(); j++)
				{
					if (elements[i] == elements[j])
					{
						cout << "You entered the same elements";
						exit(0);
					}
				}
	}
	void subset_sort(string a, string& subset)
	{
		int kod = 0, numelem = 0;
		int increase = 3;
		int position, positionend, position2 = -1, positionend2 = -1;
		string el, submulelem;
		vector<int> bracket_positions;
		vector<string> sortsubmulelem;
		int* shading = new int[a.length()];
		for (int i = 0; i < a.length(); ++i)
			shading[i] = 0;
		for (int i = 0; i < a.length(); ++i)
			if (a[i] == '{')
			{
				bracket_positions.push_back(i);
				++kod;
			}
		while (kod != 0)
		{
			position = bracket_positions.back();
			bracket_positions.pop_back();
			int kod2 = 1;
			int jj = position;
			while (kod2 != 0)
			{
				++jj;
				if (a[jj] == '}') --kod2;
				if (a[jj] == '{') ++kod2;
			}
			positionend = jj;
			int k = positionend - 1;
			while (shading[k] != 0)
				--k;
			if (a[position + 1] == '}' || (k == position))
			{
				subset = '{' + subset + '}';
				for (int i = position; i <= positionend; ++i)
				{
					++shading[i];
				}
			}
			else
			{
				for (int i = position + 1; i < positionend; ++i)
				{
					if (shading[i] != 0) continue;
					el += a[i];
					if (a[i] == '<')
					{
						int num_br = 1;
						while (num_br != 0)
						{
							++i;
							el += a[i];
							shading[i] += increase;
							if (a[i] == '>') --num_br;
							if (a[i] == '<') ++num_br;
						}
						for (int y = 0; y < a.length(); ++y)
							if (shading[y] > (increase))
							{
								int kod = 0;
								int ptr = subset.find(a[y], 0);
								if (ptr < 0) continue;
								if (ptr + 1 < subset.length())
									if (subset[ptr + 1] == ',')
									{
										++kod;
										subset.erase(ptr, 2);
									}
								if (ptr - 1 >= 0)
									if (subset[ptr - 1] == ',' && kod == 0)
									{
										++kod;
										subset.erase(ptr, 2);
									}
								if (kod == 0)subset.erase(ptr, 1);
							}
						increase += increase;
					}
					if (a[i] == ',')
						if (shading[i + 1] == 0) ++numelem;
						else el.erase(i, 1);
				}
				int j = 0;
				for (int i = 0; i < numelem; ++i)
				{
					while (el[j] != ',')
					{
						submulelem += el[j];
						if (submulelem == "<")
						{
							int num_br = 1;
							while (num_br != 0)
							{
								++j;
								submulelem += el[j];
								if (el[j] == '>') --num_br;
								if (el[j] == '<') ++num_br;
							}
						}
						++j;
					}
					if (submulelem != "") sortsubmulelem.push_back(submulelem);
					submulelem.erase(0);
					++j;
				}
				for (; j < el.length(); ++j)
				{
					submulelem += el[j];
				}
				sortsubmulelem.push_back(submulelem);
				submulelem.clear();
				if ((position2 == -1 && positionend2 == -1) || (position<position2 && positionend>positionend2))
				{
					if (subset != "") sortsubmulelem.push_back(subset);
					for (int i = 0; i < (sortsubmulelem.size() - 1); i++)
						for (int j = i + 1; j < sortsubmulelem.size(); j++)
							if (sortsubmulelem[i] > sortsubmulelem[j]) // Переставляем элементы
								swap(sortsubmulelem[i], sortsubmulelem[j]);
					subset = '{';
					for (int i = 0; i < sortsubmulelem.size() - 1; ++i)
						subset += sortsubmulelem[i] + ',';
					subset += sortsubmulelem[sortsubmulelem.size() - 1] + '}';
				}
				else
				{
					string extra;
					vector<string> aux;
					for (int i = 0; i < (sortsubmulelem.size() - 1); i++)
						for (int j = i + 1; j < sortsubmulelem.size(); j++)
							if (sortsubmulelem[i] > sortsubmulelem[j]) // Переставляем элементы
								swap(sortsubmulelem[i], sortsubmulelem[j]);
					extra = '{';
					for (int i = 0; i < sortsubmulelem.size() - 1; ++i)
						extra += sortsubmulelem[i] + ',';
					extra += sortsubmulelem[sortsubmulelem.size() - 1] + '}';
					aux.push_back(extra); aux.push_back(subset);
					for (int i = 0; i < (aux.size() - 1); i++)
						for (int j = i + 1; j < aux.size(); j++)
							if (aux[i] > aux[j]) // Переставляем элементы
								swap(aux[i], aux[j]);
					subset = "";
					for (int i = 0; i < aux.size() - 1; ++i)
						subset += aux[i] + ',';
					subset += aux[aux.size() - 1];
				}
				for (int i = position; i <= positionend; ++i)
				{
					++shading[i];
				}
				if (position > 1)
					if (a[position - 1] == ',') ++shading[position - 1];
				if (position + 1 < a.size())
					if (a[position + 1] == ',') ++shading[position + 1];
				position2 = position;
				positionend2 = positionend;
			}
			--kod;
			sortsubmulelem.clear();
			el.clear();
			numelem = 0;
		}
		delete[] shading;
		for (int i = 0; i < subset.length() - 1; ++i)
			if (subset[i] == ',' && subset[i + 1] == ',')
			{
				subset.erase(i, 1);
				i = -1;
			}
	}
	void view()
	{
		cout << "{";
		for (int i = 0; i < elements.size() - 1; ++i)
			cout << elements[i] << ",";
		cout << elements[elements.size() - 1];
	}
	void add_element(string elem)
	{
		elements.push_back(elem);
	}
	int amount_of_elements()
	{
		return elements.size();
	}
	string get_ellement(int index)
	{
		return elements[index];
	}
};
```  

#### Main
----  


```C++
int main()
{
	int number_sets = number_of_sets();
	multiplicity* a = new multiplicity[number_sets];
	read(number_sets, a);
	cout << "Result:\n" << "{\n";
	vector<string> result;
	Cartesian_product(number_sets, a, 0, result);
	cout << "}";
	return 0;
}
};
``` 


### Примеры выполнения  
----  


![Пример](/images/correctexample.png)  
![Пример](/images/Incorrectdata.png)  
![Пример](/images/Sameelements.png)  


### Вывод  
----  


В ходе выполнения был реализован алгоритм нахождения декартового произведения произвольного количества множеств