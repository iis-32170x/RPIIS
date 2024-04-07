# <p align="center">Лабораторная работа №1</p>

Вариант 27.
Однонаправленный список. Вставка элемента в список. Удаление элемента из списка. Сортировка списка. Поиск элемента в списке.

## <p align="center">Цели лабораторной работы:</p>
1. Разработать библиотеку для работы с очередью  на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.

## <p align="center">Задачи лабораторной работы:</p>
1. Изучить спецификацию задачи по работе с односвязанными списками.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для работы с очередью, включая операции вставки и извлечения элементов.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## <p align="center">Список используемых понятий:</p>
1. **Библиотека программного обеспечения (Библиотека кода):**
В программировании библиотека представляет собой совокупность программного кода, предназначенного для решения определенных задач. Этот код может содержать функции, классы, процедуры или другие компоненты, которые разработчики могут повторно использовать в своих программных проектах. Библиотеки упрощают разработку, так как они предоставляют готовые решения для типовых задач.
2. **Односвязанный список** (singly linked list) - это структура данных, которая представляет собой последовательность элементов, называемых узлами, связанными между собой с помощью ссылок. Каждый узел содержит данные и указатель (ссылку) на следующий узел в списке. Последний узел списка имеет ссылку, указывающую на nullptr, что означает конец списка.
3. **Библиотека cassert** в C++ предоставляет макрос assert, который используется для проверки предположений в программе и обнаружения ошибок во время выполнения.
4. **Класс** - это шаблон или определение, которое описывает состояние и поведение объектов. Он определяет набор свойств (переменных) и методов (функций), которые могут быть использованы для работы с объектами данного класса.

## <p align="center">Описание используемых алгоритмов:</p>
1. **Метод инициализации списка (List() ):**</p>
```cpp
template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
```
2. **Метод деконструкции класса (~List() ):**</p>
```cpp
template<typename T>
List<T>::~List()
{
	clear();
}
```
3. **Метод очистки списка(clear() )**:</p>
```cpp
template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}
```
4. **Метод удаления первого элемента (pop_front() )**:</p>
```cpp
template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}
```
5. **Метод добавления элемента в конец списка (push_back() )**:</p>
```cpp
template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}
```
6. **Метод перегруженного оператора(operator[] )**:</p>
```cpp
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
```
7. **Метод добавления элемента в начало списка (push_front() )**:</p>
```cpp
template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}
```   
8. **Метод вставки элемента по индексу (insert() )**:</p>
```cpp
template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			if (previous == nullptr) {
				cout << "Недопустимый индекс" << endl << endl;
				return;
			}
			else {
				previous = previous->pNext;
			}
		}
			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;
			Size++;
	}
}
```
9. **Метод удаления элемента по индексу (removeAt() )**:</p>
```cpp
template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			if (previous == nullptr) {
				cout << "Недопустимый индекс" << endl << endl;
				return;
			}
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}
```   
10. **Метод сортировки (bubbleSort() )**:</p>
```cpp
template<typename T>
void List<T>::bubbleSort()
{
	if (Size <= 1) {
		// Список пуст или содержит только один элемент, уже отсортирован
		return;
	}

	bool swapped; // Флаг, указывающий наличие перестановок
	Node<T>* current; // Указатель на текущий узел
	Node<T>* nextNode; // Указатель на следующий узел

	do {
		swapped = false;
		current = head;

		while (current->pNext != nullptr) {
			nextNode = current->pNext;

			if (current->data < nextNode->data) {
				// Обмен значениями между текущим и следующим узлом
				T temp = current->data;
				current->data = nextNode->data;
				nextNode->data = temp;
				swapped = true;
			}

			current = current->pNext;
		}
	} while (swapped);
}
```  
11. **Метод объединения двух списков (unit() )**:</p>
```cpp
template<typename T>
void List<T>::unit() {
	int counter = 0;
	for (int i = 0; i < lst.GetSize(); i++) {
		lst_3.push_back(lst[i]);
	}
	for (int i = 0; i < lst_2.GetSize(); i++) {
		for (int j = 0; j < lst_3.GetSize(); j++) {
			if (lst_2[i] != lst_3[j]) {
				counter++;
			}
			if (counter == lst_3.GetSize()) {
				lst_3.push_back(lst_2[i]);
			
			}
		}
		counter = 0;
	}
}
```
11. **Метод пересечения двух списков (cross() )**:</p>
```cpp
template<typename T>
void List<T>::cross() {
	for (int i = 0; i < lst.GetSize(); i++) {
		for (int j = 0; j < lst_2.GetSize(); j++) {
			if (lst[i] == lst_2[j]) {
				lst_3.push_back(lst[i]);
				break;
			}
		}
	}

}
```

## <p align="center">Результаты тестирования:</p>
Тестирование проводилось с помощью библиотеки cassert, которая предоставляет макрос assert, который используется для проверки предположений в программе и обнаружения ошибок во время выполнения.
Когда вы включаете <cassert> в свою программу, вы получаете доступ к макросу assert. Макрос assert принимает выражение в качестве аргумента и проверяет его на истинность. Если выражение является ложным (имеет значение false), то assert генерирует сообщение об ошибке и аварийно завершает программу. Если выражение истинно (имеет значение true), то assert ничего не делает и программа продолжает выполнение.

```cpp
setlocale(LC_ALL, "RU");
lst.push_back(10);
lst.push_back(20);
lst.push_back(30);
lst_2.push_back(40);
lst_2.push_back(50);
cout << "ТЕСТ 1 ПРОЙДЕН" << endl;

assert(lst.GetSize() == 3);
cout << "ТЕСТ 2 ПРОЙДЕН" << endl;

lst.insert(15, 2);

assert(lst[2] == 15);
cout << "ТЕСТ 3 ПРОЙДЕН" << endl;

lst.removeAt(2);

assert(lst[2] != 15);
cout << "ТЕСТ 4 ПРОЙДЕН" << endl;

lst.bubbleSort();

assert(lst[0] == 30);
cout << "ТЕСТ 5 ПРОЙДЕН" << endl;

lst_3.unit();

assert(lst_3.GetSize() == 5);
cout << "ТЕСТ 6 ПРОЙДЕН" << endl;

lst_3.clear();

assert(lst_3.GetSize() == 0);
cout << "ТЕСТ 7 ПРОЙДЕН" << endl;

lst.push_back(40);
lst_3.cross();

assert(lst_3[0] == 40);
cout << "ТЕСТ 8 ПРОЙДЕН" << endl;

```

Результат выполнения:

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/e3935dbe-c2cd-4f61-b3dc-61da204f9932)

## <p align="center">Вывод:</p>
В ходе выполнения работы познакомился созданием библиотек в С++, реализоавал библиотеку для односвязанного списка,а также создал систему тестов,которая проверяет корректность созданной библиотеки, отточил свои навыки в создании классов и функций.

## <p align="center">Используемые источники:</p>
1.https://habr.com/ru/sandbox/153128/ (Про односвязанные списки).
2.https://chat.openai.com (помощь в освоении материала)
3.https://www.youtube.com/watch?v=SajrPhE6FoQ (объснение односвязанного списка)
