# <p align="center">Лабораторная работа №1</p>

Вариант 7. Суффиксный массив. Построение суффиксного массива из строки.
Нахождение наименьшего циклического сдвига строки. Наибольший
общий префикс двух подстрок.

## <p align="center">Цели лабораторной работы:</p>
1. Разработать библиотеку для работы с суффиксным массивом и строками на любом императивнойм языкепрограммирования (Pascal, C\C++, Java, C#, Python и др.)
2. Разработать тестовую программу, которая демонстрирует работоспособность реализованной библиотеки.
3. Разработать систему тестов, которые продемонстрировали быработоспособность реализованной библиотеки. Система тестов должна отвечать требованиям полноты, адекватности и непротиворечивости.
4. По результатам выполнения задания составить отчет.

## <p align="center">Задачи лабораторной работы:</p>
1. Изучить спецификацию задачи по работе с деревом Фенвика.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для работы с суффиксным массивом и строками, включая нахождение суффиксного массива, наименьшего циклического сдвига, наибольшего общего префикса.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## <p align="center">Список используемых понятий и алгоритмов:</p>
1. **Библиотека программного обеспечения (Библиотека кода):**
В программировании библиотека представляет собой совокупность программного кода, предназначенного для решения определенных задач. Этот код может содержать функции, классы, процедуры или другие компоненты, которые разработчики могут повторно использовать в своих программных проектах. Библиотеки упрощают разработку, так как они предоставляют готовые решения для типовых задач.

 **Суффиксный массив**

![image](https://github.com/iis-32170x/RPIIS/assets/147256759/8d07b80e-4dec-4994-82b1-f1389d07e12f)


  Суффиксным массивом строки называется перестановка индексов начал её суффиксов, которая задаёт их порядок в порядке лексикографической сортировки. 


## <p align="center">Описание используемых алгоритмов:</p>
1. **Суффиксный массив**
  SufMassiv(): Этот алгоритм создает массив суффиксов для введенной строки. Он сначала инициализирует массив так, чтобы индекс каждого элемента соответствовал его позиции в строке. Затем он проходит через массив, сравнивая суффиксы, начинающиеся с каждой позиции. Если суффикс в текущей позиции больше следующего суффикса, они меняются местами. Этот процесс повторяется, пока все суффиксы не будут упорядочены в лексикографическом порядке.
```cpp
    string Laba1::Suf(int n, int m, string Mas)
{
	string Suffix;
	Suffix.resize(100);
	int i = 0;
	while (n < m)
	{
		Suffix[i] = Mas[n];
		i++;
		n++;
	}
	return Suffix;
}
```
   и далее сравниваем суффиксы
```cpp
 for (int i = 0; i < m - 1; i++)
{

	Suffix1 = laba1.Suf(SufMas[i], m, Mas);
	Suffix2 = laba1.Suf(SufMas[i + 1], m, Mas);
	
	if (laba1.Sravn(Suffix1, Suffix2, m) == 1)
	{
		Bufer = SufMas[i + 1];
		SufMas[i + 1] = SufMas[i];
		SufMas[i] = Bufer;
		i = -1;

	}

}
```
2. **Нахождение минимального циклического сдвига строки**
   
Sdvig(): Этот алгоритм находит наименьший циклический сдвиг введенной строки. Он сначала устанавливает исходную строку как минимальную, а затем генерирует все возможные циклические сдвиги строки. Если сгенерированный сдвиг меньше текущего минимального, он становится новым минимальным.


```cpp
        for (int i = 0; i < m; i++)
{
	Sdvig = laba1.SdvigMas(Mas, i, m);
	if (laba1.Sravn(Sdvig, Min, m) == 0)
	{
		Min = Sdvig;
	}
}
```
  3. **Нахождение наибольшего общего префикса**
     Prefix(): Этот алгоритм находит наибольший общий префикс всех подстрок введенной строки. Он сначала генерирует все подстроки строки, а затем сравнивает каждую пару подстрок, чтобы найти их наибольший общий префикс. Наибольший из всех найденных общих префиксов выводится на экран.

     Сначала находим все подстроки
```cpp
vector<string> substrings = laba1.generateSubstrings(str);
```
а после находим наибольший общий префикс

```cpp
string longestPrefix = "";
for (int i = 0; i < substrings.size(); i++) {
	for (int j = i + 1; j < substrings.size(); j++) {
		string prefix = laba1.longestCommonPrefix(substrings[i], substrings[j]);
		if (prefix.size() > longestPrefix.size()) {
			longestPrefix = prefix;
		}
	}
}
```
 
## <p align="center">Тестирование:</p>
Входные данные:
```
Строка: baaba
```
Выходные данные:
```
Суффиксный массив: 4 1 2 3 0
Наименьший циклический сдвиг: aabab
Наибольший общий префикс дувх подстрок: baab
```
Остальные тестовые программы расположены в директории `/tests`.

## <p align="center">Вывод:</p>
В рамках данной лабораторной работы были изучены способы работы со строками и создания суффиксного массива. Была реализована библиотека для работы со строками, а именно создание суффиксного массива, нахождение минимального циклического сдвига и наибольшего общего префикса двух подстрок

## <p align="center">Используемые источники:</p>
1.https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D1%83%D1%84%D1%84%D0%B8%D0%BA%D1%81%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2
2. https://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=23&id_topic=241&id_problem=1562
