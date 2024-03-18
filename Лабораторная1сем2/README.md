# Лабораторная работа N2  


### Условие  
1. Разработать библиотеку для работы со структурой данных, указанной в
индивидуальном задании, на любом императивнойм языке
программирования (Pascal, C\C++, Java, C#, Python и др.)  
2. Разработать тестовую программу, которая демонстрирует
работоспособность реализованной библиотеки работы со структурой
данных.  
3. Разработать систему тестов, которые продемонстрировали бы
работоспособность реализованной библиотеки. Система тестов должна
отвечать требованиям полноты, адекватности и непротиворечивости.
Система тестов должна учитывать не только корректную работу на
правильных данных, но и предусматривать корректное завершение
программы в случае некорректных данных.  
4. По результатам выполнения задания составить отчет.  


Двумерный массив. Сортировка массива. Вставка элемента в
отсортированный массив. Поиск элемента в отсортированном массиве.
Объединение двух отсортированных массивов. Пересечение двухотсортированных массивов.  


### Выполнение


#### Создание двухмерного массива  
----  
```C++
	Massive::Massive(int index1) : m_index1(index1)
	{
		if (m_index1 < 0)
		{
			cout << "Incorrect data type";
			exit(0);
		}
		m_mass = new double* [m_index1];
		m_index2mass = new int[m_index1];
		for (int i = 0; i < m_index1; ++i)
		{
			std::cout << "Enter the number of elements in the " << i + 1 << "- th line\n";
			while (!(std::cin >> m_index2mass[i]) || (std::cin.peek() != '\n')||(m_index2mass[i]<0))
			{
				std::cin.clear();
				std::cin.ignore(99999, '\n');
				std::cout << "Incorrect data type" << std::endl;
			}
			m_mass[i] = new double[m_index2mass[i]];
			for (int j = 0; j < m_index2mass[i]; ++j)
			{
				std::cout << "Enter the " << j + 1 << "- th element in the " << i + 1 << "- th line\n";
				while (!(std::cin >> m_mass[i][j]) || (std::cin.peek() != '\n'))
				{
					std::cin.clear();
					std::cin.ignore(99999, '\n');
					std::cout << "Incorrect data type" << std::endl;
				}
			}
		}
		Sortirovka();
	}
```  


Sortirovka()—Вызов функции сортировки.  
---- 


#### Сортировка двухмерного массива  
----  
```C++
	void Massive::Sortirovka()
	{
		for (int i = 0; i < m_index1; ++i)
			for (int j = 0; j < m_index2mass[i]; ++j)
			{
				int kod = 0;
				for (int a = i; a < m_index1; ++a)
				{
					int b;
					if (kod == 0) b = j;
					else b = 0;
					for (; b < m_index2mass[a]; ++b)
						if (m_mass[i][j] > m_mass[a][b]) std::swap(m_mass[i][j], m_mass[a][b]);
					++kod;
				}
			}
	}
```  


b—переменная,которая отслеживает,с какого столбца a-той строки начинать сортировку.  
kod-переменная,которая отслеживает,на i-той ли строке начинается сортировка.    
----  


#### Вывод двухмерного массива
----  
```C++
	void Massive::Sortirovka()
	{
		for (int i = 0; i < m_index1; ++i)
			for (int j = 0; j < m_index2mass[i]; ++j)
			{
				int kod = 0;
				for (int a = i; a < m_index1; ++a)
				{
					int b;
					if (kod == 0) b = j;
					else b = 0;
					for (; b < m_index2mass[a]; ++b)
						if (m_mass[i][j] > m_mass[a][b]) std::swap(m_mass[i][j], m_mass[a][b]);
					++kod;
				}
			}
	}
```  


----  


#### Добавление нового элемента в массив  
##### Добавление нового элемента в последнюю существующую строку  
----  
```C++  
if (m_index1 == 0)
{
	cout << "There are no rows in the array\n";
	return;
}
double* aux_mass = new double[++m_index2mass[m_index1 - 1]];
for (int j = 0; j < m_index2mass[m_index1 - 1] - 1; ++j)
	aux_mass[j] = m_mass[m_index1 - 1][j];
delete[] m_mass[m_index1 - 1];
m_mass[m_index1 - 1] = aux_mass;
std::cout << "Enter a new element\n";
while (!(std::cin >> m_mass[m_index1 - 1][m_index2mass[m_index1 - 1] - 1]) || (std::cin.peek() != '\n'))
{
	std::cin.clear();
	std::cin.ignore(99999, '\n');
	std::cout << "Incorrect data type" << std::endl;
}
cout << "Do you want to sort:" << endl << "y=yes\n" << "n=no\n";
```  


Строка if (m_index1 == 0) проверяет,есть ли в массиве вообще строки  
aux_mass—вспомогательный массив,с помощью которого высвобождается память для нового элемента в строке(нужен для изменения m_index2mass)  
----  


##### Добавление нового в новую строку  
----  
```C++
	double** aux_mass = new double* [++m_index1];
for (int i = 0; i < m_index1 - 1; ++i)
{
	aux_mass[i] = new double[m_index2mass[i]];
	for (int j = 0; j < m_index2mass[i]; ++j)
		aux_mass[i][j] = m_mass[i][j];
}
for (int i = 0; i < m_index1 - 1; ++i)
	delete[] m_mass[i];
delete[] m_mass;
m_mass = aux_mass;
int* aux_massindex = new int[m_index1];
for (int i = 0; i < m_index1 - 1; ++i)
	aux_massindex[i] = m_index2mass[i];
delete[] m_index2mass;
m_index2mass = aux_massindex;
m_index2mass[m_index1 - 1] = 1;
aux_mass[m_index1 - 1] = new double[m_index2mass[m_index1 - 1]];
std::cout << "Enter a new element\n";
while (!(std::cin >> m_mass[m_index1 - 1][m_index2mass[m_index1 - 1] - 1]) || (std::cin.peek() != '\n'))
{
	std::cin.clear();
	std::cin.ignore(99999, '\n');
	std::cout << "Incorrect data type" << std::endl;
}
```  


aux_mass-вспомогательный массив,с помощью которого создается массив с еще одной строкой
aux_massindex—вспомогательный массив,с помощью которого высвобождается память для нового элемента в строке(нужен для изменения m_index2mass)  
----  


### Объединение массивов
----  
Операция объединения массивов a и b-операция,результатом которой является массив,с количеством строк,равном сумме строк  массивов a и b, и всеми элементами из массивов a и b.Количество столбцов в строке определяется:  
-Если номер строки(начинается с нуля отсчет) меньше m_index1 массива a,то столбцов столько же сколько в соответствующей строке массива a.  
-Если номер строки(начинается с нуля отсчет) больше или равен m_index1 массива a,то столбцов столько же сколько в соответствующей строке массива b(номер строки соответствующей строки массива b равен номер строки - количество строк в массиве a).  
```C++
void Massive::Association(Massive& a)
{
	double** aux_mass = new double* [m_index1 + a.m_index1];
	for (int i = 0; i < m_index1; ++i)
	{
		aux_mass[i] = new double[m_index2mass[i]];
		for (int j = 0; j < m_index2mass[i]; ++j)
			aux_mass[i][j] = m_mass[i][j];
	}
	for (int i = m_index1; i < (a.m_index1 + m_index1); ++i)
	{
		aux_mass[i] = new double[a.m_index2mass[i - m_index1]];
		for (int j = 0; j < a.m_index2mass[i - m_index1]; ++j)
			aux_mass[i][j] = a.m_mass[i - m_index1][j];
	}
	for (int i = 0; i < m_index1; ++i)
		delete[] m_mass[i];
	delete[] m_mass;
	m_mass = aux_mass;
	int* aux_index2 = new int[m_index1 + a.m_index1];
	for (int i = 0; i < m_index1; ++i)
	{
		aux_index2[i] = m_index2mass[i];
	}
	for (int i = m_index1; i < m_index1 + a.m_index1; ++i)
	{
		aux_index2[i] = a.m_index2mass[i - m_index1];
	}
	delete[] m_index2mass;
	m_index2mass = aux_index2;
	m_index1 = m_index1 + a.m_index1;
}
```  


aux_mass-вспомогательный массив,с помощью которого высвобождается память для новых строк+осуществляется переноска значений из первого и второго массива
aux_index2—вспомогательный массив,с помощью которого изменяется m_index2mass.Он начинает отслеживать и добавленные строки.   
----  


### Пересечение массивов
----  
Результат операции пересечения может принимать матрицы разных размеров.Результатом пересечения будет матрица у которой количество строк=min(m1,m2),столбцов=min(m1,m2),значениямм в результирующей матрице будут min(a[i][j],b[i][j]).  
```C++
void Massive::Intersection(Massive& a)
{
	int min_ind1;
	double** aux_intersec;
	if (m_index1 < a.m_index1)
	{
		aux_intersec = new double* [m_index1];
		min_ind1 = m_index1;
	}
	else
	{
		aux_intersec = new double* [a.m_index1];
		min_ind1 = a.m_index1;
	}
	int* min_ind2 = new int[min_ind1];
	for (int i = 0; i < min_ind1; ++i)
	{
		if (m_index2mass[i] < a.m_index2mass[i])
		{
			min_ind2[i] = m_index2mass[i];
			aux_intersec[i] = new double[min_ind2[i]];
		}
		else
		{
			min_ind2[i] = a.m_index2mass[i];
			aux_intersec[i] = new double[min_ind2[i]];
		}
	}
	for (int i = 0; i < min_ind1; ++i)
	{
		for (int j = 0; j < min_ind2[i]; ++j)
		{
			if (m_mass[i][j] < a.m_mass[i][j])
				aux_intersec[i][j] = m_mass[i][j];
			else aux_intersec[i][j] = a.m_mass[i][j];
		}
		delete[] m_mass[i];
	}
	delete[] m_mass;
	delete[] m_index2mass;
	m_mass = aux_intersec;
	m_index1 = min_ind1;
	m_index2mass = min_ind2;
}
```  


aux_intersec-вспомогательный массив,в который записывается результат пересечения массивов.
min_ind2—вспомогательный массив,с помощью которого отслеживается в каком массиве меньше столбцов.  
min_ind1-вспомогательный массив,с помощью которого отслеживается в каком массиве меньше строк.  
----  

### Пример выполнения  
----  
![Пример](/images/Examplepart1.png)  
![Пример](/images/Examplepart2.png)  
----  


## Вывод  
----  
В ходе выполнения работы была реализована статическая библиотека и различные операции над двухмерными массивами(пересечение,объединение,сортировка).  
----  