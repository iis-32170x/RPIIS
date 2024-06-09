# Лабораторная работа №2
**Вариант №12**    
12. Реализовать программу, формирующую множество равное симметрической разности
произвольного количества исходных множеств (с учётом кратных вхождений элементов).
## Цели лабораторной работы:
1. Разработать библиотеку для считывания из файла и работы с несколькими мультимножествами на выбранном императивном языке программирования (например, C++, Java, Python).
2. Создать тестовую программу для демонстрации функциональности разработанной библиотеки.
3. Разработать систему тестов для проверки работоспособности и корректности библиотеки, учитывая требования полноты, адекватности и непротиворечивости.
4. Обеспечить обработку некорректных данных, предусмотрев корректное завершение программы при возникновении ошибок.
5. Составить отчет по выполнению лабораторной работы.
   
## Задачи лабораторной работы
1. Изучить спецификацию задачи по работе с множествами.
2. Выбрать язык программирования для реализации библиотеки (например, C++, Java, Python) в соответствии с индивидуальным заданием.
3. Разработать и реализовать библиотеку для считывания из файла и нахождения симметрической разности нескольких мультимножеств.
4. Написать тестовую программу, которая демонстрирует основные сценарии использования библиотеки.
5. Разработать систему тестов, включающую тест-кейсы для проверки различных аспектов работы библиотеки, включая корректность, производительность и обработку ошибок.
6. Провести тестирование разработанной библиотеки, убедившись в ее правильной работе на различных входных данных.
7. Составить подробный отчет, включая описание решения задачи, архитектуры библиотеки, результаты тестирования и выводы.

## Список используемых понятий:
1. **Множество** — набор, совокупность каких-либо объектов
2. **Мультимножество**   — модификация понятия множества, допускающая включение одного и того же элемента в совокупность по нескольку раз.
3. **Симметрическая разность** — это теоретико-множественная операция, результатом которой является новое множество, включающее все элементы исходных множеств, не принадлежащие одновременно обоим исходным множествам.

## Симметрическая разность

```cpp
set** set::Obed(set** mnvo,int n)
{
	element* buff = new element; element* swap = nullptr;
	while (mnvo[0]->root == nullptr)
	{
		if (n == 1)
		{
			return mnvo;
		}
		mnvo[0] = mnvo[n - 1];
		n--;
	}
	while (mnvo[0]->root->prev != nullptr)
		mnvo[0]->root = mnvo[0]->root->prev;
	buff = mnvo[0]->root;
	for (int i = 1; i < n; i++)
	{
		if (mnvo[i]->root == nullptr)
		{
			if (i + 1 < n)
			{
				i++;
			}
			else
			{
				break;
			}
		}
		while (mnvo[i]->root->prev != nullptr)
			mnvo[i]->root = mnvo[i]->root->prev;
		while (mnvo[i]->root->next != nullptr)
		{
			while (mnvo[0]->root->next != nullptr)
			{
				if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr && mnvo[i]->root->side == nullptr)
				{
					goto next;
				}
				else if (mnvo[0]->root->side!=nullptr && mnvo[i]->root->side!=nullptr&&subset(mnvo[0]->root,mnvo[i]->root)==true)
				{
					goto next;
				}
				mnvo[0]->root = mnvo[0]->root->next;
			}
			if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr && mnvo[i]->root->side == nullptr)
			{
				goto next;
			}
			else if (mnvo[0]->root->side != nullptr && mnvo[i]->root->side != nullptr && subset(mnvo[0]->root, mnvo[i]->root) == true) 
			{
				goto next;
			}
			//insert in mnvo[0],remove in mnvo[i]
			if (mnvo[i]->root->prev != nullptr) 
			   mnvo[i]->root->prev->next = mnvo[i]->root->next;
			if(mnvo[i]->root->next!=nullptr)
			   mnvo[i]->root->next->prev = mnvo[i]->root->prev;
			mnvo[0]->root->next = mnvo[i]->root;
			if(mnvo[i]->root->prev!=nullptr)
			   mnvo[i]->root = mnvo[i]->root->prev;
			else 
			{
				mnvo[i]->root = mnvo[i]->root->next;
				mnvo[0]->root->next->prev = mnvo[0]->root;
				mnvo[0]->root->next->next = nullptr;
				goto skip1;
			}
			mnvo[0]->root->next->prev = mnvo[0]->root;
			mnvo[0]->root->next->next = nullptr;
			mnvo[0]->root = buff;
			cout << endl;
			while (mnvo[0]->root->next != nullptr) 
			{
				cout << mnvo[0]->root->field << " ";
				mnvo[0]->root = mnvo[0]->root->next;

			}
			cout << mnvo[0]->root->field << " ";

			goto skip;
		next:
			if (mnvo[i]->root->mult = mnvo[0]->root->mult)
			{
				swap = mnvo[0]->root;
				if (mnvo[0]->root->prev != nullptr)
				{
					mnvo[0]->root = mnvo[0]->root->prev;
					mnvo[0]->root->next = mnvo[0]->root->next->next;
					if(mnvo[0]->root->next!=nullptr)
					mnvo[0]->root->next->prev = mnvo[0]->root;
					delete swap;
				}
				else
				{
					if (mnvo[0]->root->next != nullptr)
					{
						mnvo[0]->root = mnvo[0]->root->next; mnvo[0]->root->prev = nullptr; buff = mnvo[0]->root;
						delete swap;
					}
					else
					{
						delete swap;
						mnvo[0]->root = mnvo[i]->root;
						mnvo[0]->root->prev = nullptr;
						buff = mnvo[0]->root;
					}
				}
			}
			else
			{
				if (mnvo[i]->root->mult > mnvo[0]->root->mult) 
				{
					mnvo[0]->root->mult = mnvo[i]->root->mult - mnvo[0]->root->mult;
				}
				else
				{
					mnvo[0]->root->mult = mnvo[0]->root->mult - mnvo[i]->root->mult;
				}
			}
			skip:
			if(mnvo[i]->root->next!=nullptr)
			mnvo[i]->root = mnvo[i]->root->next;
			skip1:
			mnvo[0]->root = buff;
		}
		while (mnvo[0]->root->next != nullptr)
		{
			if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr&&mnvo[i]->root->side==nullptr)
			{
				goto next1;
			}
			else if (mnvo[0]->root->side != nullptr && mnvo[i]->root->side != nullptr && subset(mnvo[0]->root, mnvo[i]->root) == true) 
			{
				goto next1;
			}
			mnvo[0]->root = mnvo[0]->root->next;
		}
		if (mnvo[0]->root->field == mnvo[i]->root->field && mnvo[0]->root->side == nullptr && mnvo[i]->root->side == nullptr)
		{
			goto next1;
		}
		else if (mnvo[0]->root->side != nullptr && mnvo[i]->root->side != nullptr && subset(mnvo[0]->root, mnvo[i]->root) == true) 
		{
			goto next1;
		}
		if(mnvo[i]->root->prev!=nullptr)
		mnvo[i]->root->prev->next = mnvo[i]->root->next;
		mnvo[0]->root->next = mnvo[i]->root;
		mnvo[0]->root->next->prev = mnvo[0]->root;
		mnvo[0]->root = buff;
		cout << endl;
		while (mnvo[0]->root->next != nullptr)
		{
			cout << mnvo[0]->root->field << " ";
			mnvo[0]->root = mnvo[0]->root->next;

		}
		cout << mnvo[0]->root->field << " ";
		goto skp1;
	next1:
		if (mnvo[i]->root->mult = mnvo[0]->root->mult)
		{
			swap = mnvo[0]->root;
			if (mnvo[0]->root->prev != nullptr)
			{
				mnvo[0]->root = mnvo[0]->root->prev;
				mnvo[0]->root->next = mnvo[0]->root->next->next;
				if (mnvo[0]->root->next != nullptr)
				mnvo[0]->root->next->prev = mnvo[0]->root;
				delete swap;
			}
			else 
			{
				if (mnvo[0]->root->next != nullptr)
				{
					mnvo[0]->root = mnvo[0]->root->next; mnvo[0]->root->prev = nullptr;
					delete swap; buff = mnvo[0]->root;
				}
				else
				{
					delete swap;
					mnvo[0]->root = mnvo[i]->root;
					mnvo[0]->root->prev = nullptr; buff = mnvo[0]->root;
				}
			}
		}
		else
		{
			if (mnvo[i]->root->mult > mnvo[0]->root->mult)
			{
				mnvo[0]->root->mult = mnvo[i]->root->mult - mnvo[0]->root->mult;
			}
			else 
			{
				mnvo[0]->root->mult = mnvo[0]->root->mult - mnvo[i]->root->mult;
			}
		}
		skp1:
		mnvo[0]->root = buff;
	}
	return mnvo;
}

```
