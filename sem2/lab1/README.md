# Лабораторная работа №1
**Вариант №2**    
Множество. Добавление элемента во множество. Удаление элемента из
множества. Поиск элемента во множестве. Объединение двух
множеств. Пересечение двух множеств.
## Цели лабораторной работы:
1. Разработать библиотеку для работы с очередью  на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.
   
## Задачи лабораторной работы
1. Изучить спецификацию задачи по работе с множествами.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для работы с множествами, включая операции вставки и удаления элементов.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## Список используемых понятий:
1. **Множество** - набор, совокупность каких-либо объектов
2. **Объединением множеств А и В** называется множество, содержащее все элементы, принадлежащие либо множеству А, либо В, либо им обоим
3. **Пересечением множеств А и В** называется множество, состоящее из всех элементов, принадлежащих одновременно каждому из множеств
А и В.


## <p align="center">Описание используемых алгоритмов:</p>
1. **Алгоритм добавления элемента**
   
   Этот алгоритм добавляет элемент в множество. Добавление сделано так, чтобы элементы множества не повторялись и были различны
```cpp
void Add(Branch*& current, int value) {
	if (!current) {
		current = new Branch(value); //добавляем/создаем элемент
		return;
	}
	else
		if (value < current->data) { 
			Add(current->left, value);
		}
		else if (value > current->data)
		{
			Add(current->right, value);
		}
		else 	return;
}
}
```
2. **Алгоритм удаления элемента**
   
   Этот алгоритм удаляет заданный элемент, если такой имеется. В противном случае ничего не произойдет
```cpp
Branch* findMinNode(Branch* node) {
	if (node == nullptr) {
		return nullptr; // Не найден минимальный узел
	}
	else if (node->left == nullptr) {
		return node; // Мы достигли самого левого узла в дереве
	}
	else {
		return findMinNode(node->left); // Рекурсивно ищем в левом поддереве
	}
}


void removeNode(Branch*& current, int value) {
	if (current == nullptr) {
		return; // Узел не найден
	}
	if (value < current->data) {
		// Ищем в левом поддереве
		removeNode(current->left, value);
	}
	else if (value > current->data) {
		// Ищем в правом поддереве
		removeNode(current->right, value);
	}
	else {
		// Нашли узел
		if (current->left == nullptr) {
			// Узел имеет только правого потомка
			Branch* temp = current;
			current = current->right;
			delete temp;
		}
		else if (current->right == nullptr) {
			// Узел имеет только левого потомка
			Branch* temp = current;
			current = current->left;
			delete temp;
		}
		else {
			// Узел имеет двух потомков, находим и удаляем узел с минимальным значением в правом поддереве
			Branch* minRight = findMinNode(current->right);
			current->data = minRight->data;
			removeNode(current->right, minRight->data);
		}
	}
}
```
3. **Алгоритм поиска элемента**

   Данный алгоритм ищет заданный элемент и возвращает ссылку, если элемент найден
```cpp
Branch* FindElem(Branch* node, int value) {
	if (!node){
		std::cout << "Элемент не найден";
		return NULL;
}
	if (node->data == value) {
		std::cout << "Элемент найден";
		return node;
	}
	if (node->data<value)
		FindElem(node->right, value);
	else 
		FindElem(node->left, value);
}
```

4. **Вывод множества на экран**
```cpp
void print(Branch* node) {
	if (!node) return;
	print(node->left);
	std::cout << node->data << " ";
	print(node->right);
}
```

 5. **Алгоритм объединения**

   ```cpp
void add1(Branch*& current, Branch*& mnozhC) {
	if (!current) return;
	Add(mnozhC, current->data);
	add1(current->right, mnozhC);
	add1(current->left, mnozhC);
}

void Objedinenie(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
	add1(mnozhA, mnozhC); //добавляем элементы множества А
	add1(mnozhB, mnozhC); //добавляем элементы множества В
}
   ```

   6. **Алгоритм пересечения**
	
      В данном алгоритме каждый элемент множества А сравнивается с каждым элементом множества В. При совпадении элемент добавляется в пересечение
   ```cpp
void proverka(int value, Branch* node, Branch*& mnozhC) { 
	if (!node) return;
	if (node->data == value) {
		Add(mnozhC, value);
		return;
	}
	proverka(value, node->left, mnozhC);
	proverka(value, node->right, mnozhC);
}



void Peresechenie(Branch* mnozhA, Branch* mnozhB, Branch*& mnozhC) {
	if (!mnozhA) return;
	proverka(mnozhA->data, mnozhB, mnozhC);

	Peresechenie(mnozhA->left, mnozhB, mnozhC);
	Peresechenie(mnozhA->right, mnozhB, mnozhC);
}
   ```
*****
## <p align="center">Тесты:</p>
![результат тестов](https://github.com/iis-32170x/RPIIS/blob/a1e9b18d66d97691475edbe514a4ce13e9b0220f/sem2/lab1/tests/testresult.png)
******
## <p align="center">Вывод:</p>
В ходе выполнения работы познакомился созданием библиотек в С++, реализоавал библиотеку работы с массивами,а также создал систему тестов,которая проверяет корректность созданной библиотеки, отточил свои навыки в создании структур и функций.
## <p align="center">Используемые источники:</p>
1. [Литература](https://drive.google.com/drive/folders/1rJjlVms04Betx1EkAgaek2xNpHV6c_1j)
2. [Создание библиотеки](https://www.youtube.com/watch?v=pAxEfF2yVlM&t=1s)
****


