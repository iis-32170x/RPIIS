# Лабораторная работа №1
Вариант 11. Дерево максимумов. Поиск максимума на отрезке массива. Изменение всех чисел на отрезке массива на какое-то значение.

## Цели лабораторной работы:
Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки структур данных.

## Список используемых понятий и алгоритмов:
1. **Библиотека программного обеспечения (Библиотека кода):**
  В программировании библиотека представляет собой совокупность программного кода, предназначенного для решения определенных задач. Этот код может содержать функции, классы, процедуры или другие компоненты, которые разработчики могут повторно использовать в своих программных проектах. Библиотеки упрощают разработку, так как они предоставляют готовые решения для типовых задач.
2. **Дерево максимумов:**
  Дерево максимумов - структура данных, которая может выполнять следующие операции: прибавить число val ко всем элементам из интервала [l, r] (число может быть и отрицательным) и выдавать максимальное значение из интервала [l, r]; эти операции выполняются за O(logN).
3. **Дерево отрезков:**
  Дерево отрезков — это структура данных, которая позволяет эффективно (т.е. за асимптотику O(logN)) реализовать операции следующего вида: нахождение суммы/минимума элементов массива в заданном отрезке (a[l, r], где l и r поступают на вход алгоритма), при этом дополнительно возможно изменение элементов массива: как изменение значения одного элемента, так и изменение элементов на целом подотрезке массива (т.е. разрешается присвоить всем элементам a[l, r] какое-либо значение, либо прибавить ко всем элементам массива какое-либо число).
4. **Бинарное дерево:**
   Двои́чное де́рево — иерархическая структура данных, в которой каждый узел имеет не более двух потомков.

## Алгоритм
### Заголовочный файл RMQ_tree.h

#### Библиотеки для работы с консолью и текстом:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;
```

#### Объявление структуры, описывающей один узел RMQ:
```cpp
struct tree
{
	tree* left_child = NULL;
	tree* right_child = NULL;

	int l_border = 0;
	int r_border = 0;

	int max_value = 0;
	int modification = 0;

	int value = 0;
	int nomer = 0;
};
```
`tree* left_child, right_child;` - указатели на дочерние левый и правый узлы соответственно.

`int l_border, r_border;` - показывают, какой отрезок охватывает данный узел.

`int max_value;` - максимальное значение, которое встречается на этом интервале (будет выбираться из сыновей).

`int modification;` - будет хранить модификацию для всего этого интервала.

`int value;` - значение этого узла.

`int nomer;` - номер узла.

#### Функция создания дерева:
```cpp
void create_tree(tree* node, int section[], int length_of_section, int l_limit, int numeral)
{
	int max = section[0], sum = 0;

	for (int i = 0; i < length_of_section; i++)
	{
		sum += section[i];
		if (section[i] > max)
		{
			max = section[i];
		}
	}

	node->nomer = numeral;
	node->value = sum;
	node->max_value = max;
	node->l_border = l_limit;
	node->r_border = l_limit + length_of_section - 1;

	if (length_of_section != 1)
	{
		int temp = log2(length_of_section);
		int razbienie;

		if (length_of_section != pow(2, temp))
		{
			razbienie = pow(2, temp);
		}
		else
		{
			razbienie = length_of_section / 2;
		}

		if (node->left_child == NULL)
		{
			int* tempmassiv = new int[razbienie];
			for (int i = 0; i < razbienie; i++)
			{
				tempmassiv[i] = section[i];
			}

			node->left_child = new tree;

			create_tree(node->left_child, tempmassiv, razbienie, l_limit, 2 * numeral);

			delete[] tempmassiv;
		}

		if (node->right_child == NULL)
		{
			int* tempmassiv2 = new int[length_of_section - razbienie];
			for (int i = razbienie; i < length_of_section; i++)
			{
				tempmassiv2[i - razbienie] = section[i];
			}

			node->right_child = new tree;

			create_tree(node->right_child, tempmassiv2, length_of_section - razbienie, l_limit + razbienie, 2 * numeral + 1);

			delete[] tempmassiv2;
		}
	}
}
```

В функцию передаем: Указатель на данный узел дерева, массив с числами (листьями на данном отрезке), длина этого массива (количество листьев на данном отрезке), левый предел отрезка, номер узла.

Далее вычисляем и добавляем в структуру: номер узла, значение узла, максимальное значение из массива, левую и правую границы отрезка.

Принцип создания дерева: из полученного исходного количества листьев выделяем 2^n листьев (из 9: 2^3 = 8, из 12: 2^3 = 8, из 19: 2^4 = 16, и т.д.), если количество листьев = 2^n, то делим на 2. В левому потомку передаем массив размером 2^n, правому - "исходное количество листьев - 2^n".


#### Функция изменения 
```cpp
void modify_tree(tree* node, int left_limit, int right_limit, int change)
{
	if (left_limit <= node->l_border && right_limit >= node->r_border)
	{
		node->modification += change;

	}
	else
	{
		if (node->left_child != NULL)
		{
			modify_tree(node->left_child, left_limit, right_limit, change);
		}

		if (node->right_child != NULL)
		{
			modify_tree(node->right_child, left_limit, right_limit, change);
		}
	}

	if ((node->right_child != NULL) && (node->left_child != NULL))
	{
		if (node->left_child->max_value + node->left_child->modification >= node->right_child->max_value + node->right_child->modification)
		{
			node->max_value = node->left_child->max_value + node->left_child->modification;
		}
		else
		{
			node->max_value = node->right_child->max_value + node->right_child->modification;
		}
	}
}
```
Интервал будет разбиваться на две равные половины, и информация об этих половинах будет храниться в сыновьях данного узла. Если при вызове функции modify (прибавление) узел полностью накрывается, то будем прибавлять к его полю modification, число change (то значение, которое прибавляется ко всем элементам). Если узел накрывается интервалом частично, то мы оставляем поле modification неизменным (оно будет отражать только изменение для всего интервала), вызываем функцию изменения рекурсивно для тех потомков, которые накрываются изменяемым интервалом с тем же значением value и с пересчитанным интервалом. В таком случае, на рекурсивном спуске следует пересчитывать значение поля max_value данного узла, заменяя его на максимальное из значений max_value + modification из его сыновей.


#### Функция поиска максимума
```cpp
int find_max(tree* node, int left_limit, int right_limit, int sumadd)
{
	if (node->l_border == left_limit && node->r_border == right_limit)
	{
		return sumadd + node->max_value;
	}
	else
	{
		int res = -INFINITY;
		if (left_limit <= node->left_child->r_border)
		{
			res = max(find_max(node->left_child, left_limit, min(right_limit, node->left_child->r_border), sumadd + node->left_child->modification), res);
		}
		if (right_limit >= node->right_child->l_border)
		{
			res = max(find_max(node->right_child, max(left_limit, node->right_child->l_border), right_limit, sumadd + node->right_child->modification), res);
		}
		return res;
	}
}
```
Теперь рассмотрим функцию максимума для интервала. Вначале введем понятие накопленной суммы (sumadd). Каждый раз, когда на рекурсивном спуске мы будем проходить через какую-то вершину, то будем прибавлять к сумме значение поля modification (таким образом, мы учтем все изменения, которые совершались с данными объектами, которые меняют все элементы, в том числе максимум). Т.е. в каждую функцию в качестве sumadd должна передаваться сумма sumadd и поля modification для узла, обрабатываемого вызываемой функцией. При вызове функции поиска должен передаваться указатель на корень дерева, а значение sumadd должно быть равно полю modification для корня. Если границы текущего интервала совпадают с запросом, то мы возвращаем наверх значение max_value + sumadd (т.е. значение максимального элемента плюс все изменения, которые накладывались на данный интервал). Если же интервал покрывается не полностью, то мы будем вызывать функцию для тех его детей, которые хотя бы частично пересекаются с интервалом и возвращать максимальное из значений, возвращенное этими функциями. Для дерева максимумов мы будем возвращать максимум из возвращенных значений.


#### Функция нахождения суммы на отрезке
```cpp
void sum_tree(tree* node, int left_limit, int right_limit, int* sum)
{
	*sum += (node->modification) * (right_limit - left_limit + 1);

	if (node->left_child && (left_limit <= node->left_child->r_border))
	{
		sum_tree(node->left_child, left_limit, min(right_limit, node->left_child->r_border), sum);
	}
	if (node->right_child && (right_limit >= node->right_child->l_border))
	{
		sum_tree(node->right_child, max(left_limit, node->right_child->l_border), right_limit, sum);
	}
}
```
Рекурсивно проходим все листья на заданном отрезке, на каждом узле добавляя к сумме модификацию данного узла, умноженную на количество листьев, связнных с этой вершиной и в тоже время попадающих в заданный интервал.


#### Дополнительные функции: 1) Вывести дерево; 2) Удалить дерево
```cpp
void show_tree(tree* root, int length)
{
	if (!root)
	{
		cout << "Error!" << endl;
		exit(-1);
	}
	tree* buffroot = root;
	int logN = log2(length);
	int left_dir;
	int right_dir;
	int full_length;

	if (pow(2, logN) != length)
	{
		full_length = pow(2, int(log2(length)) + 1);
	}
	else
	{
		full_length = length;
	}

	int for_setw = 4 * full_length;

	for (int i = 1; i < full_length * 2; i++)
	{
		logN = int(log2(i));

		for (int k = logN; k > 0; k--)
		{
			if (buffroot != NULL)
			{
				left_dir = (buffroot->nomer) * pow(2, k);

				right_dir = (buffroot->nomer) * pow(2, k) + pow(2, k) - 1;


				if (i - left_dir > right_dir - i)
				{
					buffroot = buffroot->right_child;
				}
				if (i - left_dir < right_dir - i)
				{
					buffroot = buffroot->left_child;
				}
			}
		}


		if (pow(2, logN) == i)
		{
			for_setw = for_setw / 2;
			cout << endl;
			cout << setw(for_setw + full_length - 2 * pow(2, logN) / 3);
		}
		else
		{
			cout << setw(2 * for_setw);
		}

		if (buffroot != NULL)
		{
			cout << buffroot->modification << " ";
		}

		buffroot = root;
	}
}

tree* delete_tree(tree* node)
{
	tree* temp_node_l = NULL, * temp_node_r = NULL;
	if (node->left_child != NULL && node->right_child != NULL)
	{
		temp_node_l = node->left_child;
		temp_node_r = node->right_child;
	}
	delete node;
	if (temp_node_l && temp_node_r)
	{
		delete_tree(temp_node_l);
		delete_tree(temp_node_r);
	}
	return NULL;
}
```

### Исходный файл RMQ.cpp

#### Реализация работы всех вышеописанных функций (меню)
```cpp
#include "RMQ_tree.h"
#include <ctime>

int main()
{
	srand(time(NULL));

	tree* root = new tree;

	int amount_of_leaves, swit4 = 1, left_lim, right_lim, modif;

	int for_max_n_sum, * ptr_sum = &for_max_n_sum;

	cout << "Input amount of leaves: ";

	do
	{
		cin >> amount_of_leaves;
	} while (amount_of_leaves < 1);

	int* leaves = new int[amount_of_leaves];

	for (int i = 0; i < amount_of_leaves; i++)
	{
		leaves[i] = /*rand() % 41 - 2*/0;
	}

	create_tree(root, leaves, amount_of_leaves, 0, 1);

	show_tree(root, amount_of_leaves);

	while (swit4)
	{
		cout << endl << endl << "1) Modify tree - 1\n2) Find max - 2\n3) Find sum - 3" << endl;

		do
		{
			cin >> swit4;
		} while (swit4 < 0 || swit4 > 3);

		cout << endl;

		switch (swit4)
		{
		case(1):
		{
			cout << "Define the section, where max value will be changed: [a, b] ([1, " << amount_of_leaves << "])" << endl;

			cout << "a: ";
			do
			{
				cin >> left_lim;
			} while (left_lim < 1 || left_lim > amount_of_leaves);

			cout << "b: ";
			do
			{
				cin >> right_lim;
			} while (right_lim < left_lim || right_lim > amount_of_leaves);

			cout << "Input modification: ";
			cin >> modif;

			modify_tree(root, left_lim - 1, right_lim - 1, modif);
			show_tree(root, amount_of_leaves);

			break;
		}

		case(2):
		{

			cout << "Define the section, where max value will be found: [a, b] ([1, " << amount_of_leaves << "])" << endl;

			cout << "a: ";
			do
			{
				cin >> left_lim;
			} while (left_lim < 1 || left_lim > amount_of_leaves);

			cout << "b: ";
			do
			{
				cin >> right_lim;
			} while (right_lim < left_lim || right_lim > amount_of_leaves);

			for_max_n_sum = find_max(root, left_lim - 1, right_lim - 1, root->modification);

			cout << "Max value on [" << left_lim << ", " << right_lim << "]: " << for_max_n_sum << endl;

			break;
		}
		case(3):
		{
			for_max_n_sum = 0;

			cout << "Define the section, where sum will be found: [a, b] ([1, " << amount_of_leaves << "])" << endl;

			cout << "a: ";
			do
			{
				cin >> left_lim;
			} while (left_lim < 1 || left_lim > amount_of_leaves);

			cout << "b: ";
			do
			{
				cin >> right_lim;
			} while (right_lim < left_lim || right_lim > amount_of_leaves);

			sum_tree(root, left_lim - 1, right_lim - 1, ptr_sum);

			cout << "Sum on [" << left_lim << ", " << right_lim << "]: " << for_max_n_sum << endl;

			break;
		}
		}
	}

	root = delete_tree(root);
	show_tree(root, amount_of_leaves);
}
```


## Тесты
1. Количество листьев: 5;
Модификации (в форме: модификация - отрезок): 6 - [3, 5], 4 - [5, 5], 3 - [1, 2], 9 - [2, 3].

![Получено](https://github.com/iis-32170x/RPIIS/assets/144227421/268b5a57-7555-4ef4-9ea3-b2deb8aab0b4)

Полученное дерево ^^^.

Нахождение максимума (в форме: максимум - отрезок): 15 - [1, 5], 15 - [2, 4], 12 - [1, 2], 3 - [1, 1].

Нахождение суммы (в форме: сумма - отрезок): 30 - [1, 3], 43 - [2, 5], 15 - [1, 2], 10 - [5, 5].

2. Количество листьев: 7;
Модификации (в форме: модификация - отрезок): 6 - [3, 5], 5 - [1, 3], 3 - [1, 2], 8 - [1, 7], 9 - [4, 7]

![Полученно2](https://github.com/iis-32170x/RPIIS/assets/144227421/5a6ba63c-6ff9-433e-956d-b9c96a5b8b4e)

Полученное дерево ^^^.

Нахождение максимума (в форме: максимум - отрезок): 23 - [1, 7], 23 - [3, 4], 16 - [1, 2], 19 - [1, 3], 17 - [6, 7].

Нахождение суммы (в форме: сумма - отрезок): 35 - [2, 3], 65 - [3, 5], 23 - [5, 5], 57 - [5, 7], 131 - [1, 7]




## Вывод
В рамках данной лабораторной работы были изучена структура Дерево максимумов. Была реализована библиотека с основными операциями над Деревом максимумов.


## Источники
1. https://drive.google.com/drive/folders/1U-r54LZD2m_yiPa1TuaaaS4t1hEWxa7q (6 лекция)
2. http://e-maxx.ru/algo/segment_tree
3. https://brestprog.by/topics/segmenttree/
