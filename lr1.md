# Лабораторная работа 1
### группа 321701
### Самович Вячеслав
### Вариант 24
## Задание
Двунаправленный список. Вставка элемента в список. Удаление элемента из списка. Сортировка списка. Поиск элемента в списке. Объявление двух списков. Пересечение двух списков.
## 1. Класс, являющийся элементом списка
```c++
class Quenue
{
public:
    int Data;
    Quenue* Next;
    Quenue* Prev;

    Quenue(Quenue* prev, Quenue* next, int data)
    {
        Data = data;
        Next = next;
        Prev = prev;
    }

    Quenue()
    {
    }
};
```
int Data - поле для значений

Quenue* Next - указатель на следующий экземляр класса

Quenue* Prev - указатель на предыдущий экземляр класса

## 2. Описание методов для создания, удаления и вывода в консоль списка
### 2.1 Создание списка из массива int 
```c++
void CreateQuenueFromPtr(int* arr, int n, Quenue** top)
{
    for (int i = 0; i < n; i++)
    {
        Quenue* q = new Quenue(*top, NULL, arr[i]);
        if (*top != NULL)
        {
            (*top)->Next = q;
        }
        *top = q;
    }
}
```
### 2.2 Удаление списка
```c++
void RemoveQuenue(Quenue** q)
{
    do {
        Quenue* temp = *q;
        *q = (*q)->Prev;
        delete temp;
    } while ((*q) != NULL);

}
```
### 2.3 Вывод списка в консоль 
```c++
void ConsoleOutput(Quenue* q)
{
    if (q == NULL) return;
    cout << "Quenue item: " << q->Data << endl;
    ConsoleOutput(q->Prev);
}
```
## 3. Описание методов для сортировки списка, вставки и удаления элементов, объединения и пересечения списков, нахождение индекса данного элемента.

### 3.1 Объединение списков
```c++
Quenue* Join(Quenue* q1, Quenue* q2) 
{
    if (q1 == NULL || q1 == NULL) return NULL;
    Quenue* top = NULL;
    Quenue iterator;
    Quenue* prev = NULL;

    bool isInList = false;
    Quenue* check = top;

    do
    {
        isInList = false;
        check = top;
        while (check)
        {
            if (check->Data == q1->Data)
            {
                isInList = true;
                break;
            }
            check = check->Prev;
        }
        if (!isInList)
        {
            Quenue* q = new Quenue(prev, NULL, q1->Data);
            if (prev != NULL)
            {
                prev->Next = q;
            }
            else
            {
                iterator = *q;
            }
            top = q;
            prev = q;
        }    
        q1 = q1->Prev;
    } while (q1 != NULL);


    do
    {
        do
        {
            if (iterator.Data == q2->Data)
            {
                break;
            }
            if (iterator.Next == NULL)
            {
                isInList = false;
                check = top;
                while (check)
                {
                    if (check->Data == q2->Data)
                    {
                        isInList = true;
                        break;
                    }
                    check = check->Prev;
                }
                if (!isInList)
                {
                    Quenue* q = new Quenue(prev, NULL, q2->Data);
                    prev->Next = q;
                    top = q;
                    prev = q;
                }
            }
            if (iterator.Next == NULL)
            {
                break;
            }
            iterator = *iterator.Next;
        } while (true);
        q2 = q2->Prev;
    } while (q2 != NULL);

    return top;
} 
```

Способ объединения: будем рассматривать данные списки q1 и q2 в качестве множеств, а элементы списков с одинаковым значением поля data будем считать одинаковыми, следовательно повторов элементов в результате операции не будет. 

### 3.2 Пересечение списков 
```c++
Quenue* Intersect(Quenue* q1, Quenue* q2)
{
    if (q1 == NULL || q1 == NULL) return NULL;
    Quenue* top = NULL;
    Quenue* prev = NULL;
    Quenue temp = *q1;
    bool isInList = false;

    Quenue* check = top;

    do
    {
        do
        {
            if (q1->Data == q2->Data)
            {
                
                isInList = false;
                check = top;
                while (check)
                {
                    if (check->Data == q1->Data)
                    {
                        isInList = true;
                        break;
                    }
                    check = check->Prev;
                }
                if (!isInList)
                {
                    Quenue* q = new Quenue(prev, NULL, q2->Data);
                    if (prev != NULL)
                    {
                        prev->Next = q;
                    }
                    top = q;
                    prev = q;
                    break;
                }              
            }
            if (q1->Prev == NULL)
            {
                break;
            }
            q1 = q1->Prev;
        } while (true);
        q1 = &temp;
        q2 = q2->Prev;
    } while (q2 != NULL);

    return top;
}
```
Способ пересечения: будем рассматривать данные списки q1 и q2 в качестве множеств, а элементы списков с одинаковым значением поля data будем считать одинаковыми, следовательно повторов элементов в результате операции не будет.  

### 3.3 Сортировка списков 
```c++
void SortQuenue(Quenue** q)
{
    Quenue* maxSorted = NULL;
    Quenue* Bottom = *q;
    Quenue* temp = NULL;
    Quenue* prev;
    Quenue* current = NULL;
    Quenue* next;

    while (Bottom->Prev != NULL)
    {
        Bottom = Bottom->Prev;
    }

    while (Bottom != maxSorted)
    {
        temp = Bottom;
        while (temp != maxSorted)
        {
            current = temp;
            next = current->Next;
            prev = current->Prev;
            if (next != NULL && current->Data < next->Data)
            {
                if (prev != NULL) prev->Next = next;
                else Bottom = next;
                next->Prev = prev;
                current->Prev = next;
                current->Next = next->Next;
                if (next->Next != NULL)next->Next->Prev = current;
                next->Next = current;
            }
            else
            {
                temp = temp->Next;
            }
            if (next == NULL) *q = current;
        }
        maxSorted = current;
    }
}
```
Будем выполнять пузырьковую сортировку.

### 3.4 Вставка элемента по индексу 
```c++
void InsertAt(Quenue** top, int index, int data)
{
    Quenue* q = *top;
    for (int i = 0; i < index; i++)
    {
        if (q->Prev != NULL)
        {
            q = q->Prev;
        }
    }

    Quenue* insertion = new Quenue(q, q->Next, data);
    q->Next = insertion;
    if (index == 0) *top = insertion;
}
```
Фактически индексация будет происходить с конца списка, откуда выводится первое значение.

### 3.4 Нахождение первого индекса элемента с каким-то значением
```c++
int FindItem(Quenue* q, int value)
{
    if (q == NULL) return -1;
    int index = 0;
    while (q != NULL)
    {
        if (q->Data == value) return index;
        index++;
        q = q->Prev;
    }
    return -1;
}
```
### 3.5 Удаление элемента из списка по индексу
```c++
void RemoveAt(Quenue** Top, int value)
{
    if (*Top == NULL) return;
    if (value < 0) return;
    Quenue* next = NULL;
    Quenue* q = *Top;
    for (int i = 0; i < value; i++)
    {
        if (q->Prev != NULL)
        {
            next = q;
            q = q->Prev;
        }
    }
    if (value == 0)
    {
        *Top = (*Top)->Next;
    }
    if (q->Prev != NULL)
    {
        q->Prev->Next = next;
    }
    if (next != NULL)
    {
        next->Prev = q->Prev;
    }
    delete q;
}
```
# Ввод данных и тестирование

Для тестирования была написана программа, в которой создаётся два списка. Пользователь выбирает способ ввода данных: либо из консоли, либо из текстового файла вида:
```
len = {16};
arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,};
```
После ввода данных пользователю даётся возможность провести операции над списками.

Пример выполнения программы:
```
Select input option: 1 - testfile; 2 - console
1
Enter path
C:\Users\slavikovics\OneDrive\Desktop\pioivis_sem2\tests\test1.txt
len = {16};arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,};
Quenue item: 16
Quenue item: 15
Quenue item: 14
Quenue item: 13
Quenue item: 12
Quenue item: 11
Quenue item: 10
Quenue item: 9
Quenue item: 8
Quenue item: 7
Quenue item: 6
Quenue item: 5
Quenue item: 4
Quenue item: 3
Quenue item: 2
Quenue item: 1
Select input option: 1 - testfile; 2 - console
1
Enter path
C:\Users\slavikovics\OneDrive\Desktop\pioivis_sem2\tests\test2.txt
len = {5};arr = {1,2,3,4,5,};
Quenue item: 5
Quenue item: 4
Quenue item: 3
Quenue item: 2
Quenue item: 1
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
join
Quenue item: 1
Quenue item: 2
Quenue item: 3
Quenue item: 4
Quenue item: 5
Quenue item: 6
Quenue item: 7
Quenue item: 8
Quenue item: 9
Quenue item: 10
Quenue item: 11
Quenue item: 12
Quenue item: 13
Quenue item: 14
Quenue item: 15
Quenue item: 16
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
intersect
Quenue item: 1
Quenue item: 2
Quenue item: 3
Quenue item: 4
Quenue item: 5
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
removeAt
Choose quenue (1 | 2)
1
Enter index
5
Quenue item: 16
Quenue item: 15
Quenue item: 14
Quenue item: 13
Quenue item: 12
Quenue item: 10
Quenue item: 9
Quenue item: 8
Quenue item: 7
Quenue item: 6
Quenue item: 5
Quenue item: 4
Quenue item: 3
Quenue item: 2
Quenue item: 1
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
find
Choose quenue (1 | 2)
1
Enter value
8
Index: 7
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
sort
Choose quenue (1 | 2)
1
Quenue item: 1
Quenue item: 2
Quenue item: 3
Quenue item: 4
Quenue item: 5
Quenue item: 6
Quenue item: 7
Quenue item: 8
Quenue item: 9
Quenue item: 10
Quenue item: 12
Quenue item: 13
Quenue item: 14
Quenue item: 15
Quenue item: 16
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
insertAt
Choose quenue (1 | 2)
1
Enter index and data
8
56
Quenue item: 1
Quenue item: 2
Quenue item: 3
Quenue item: 4
Quenue item: 5
Quenue item: 6
Quenue item: 7
Quenue item: 8
Quenue item: 56
Quenue item: 9
Quenue item: 10
Quenue item: 12
Quenue item: 13
Quenue item: 14
Quenue item: 15
Quenue item: 16
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
sort
Choose quenue (1 | 2)
1
Quenue item: 1
Quenue item: 2
Quenue item: 3
Quenue item: 4
Quenue item: 5
Quenue item: 6
Quenue item: 7
Quenue item: 8
Quenue item: 9
Quenue item: 10
Quenue item: 12
Quenue item: 13
Quenue item: 14
Quenue item: 15
Quenue item: 16
Quenue item: 56
Choose action: join | intersect | removeAt | find | sort | insertAt | exit
exit

C:\Users\slavikovics\OneDrive\Desktop\lr1build\x64\Debug\lr1build.exe (процесс 12524) завершил работу с кодом 0.
Чтобы автоматически закрывать консоль при остановке отладки, включите параметр "Сервис" ->"Параметры" ->"Отладка" -> "Автоматически закрыть консоль при остановке отладки".
Нажмите любую клавишу, чтобы закрыть это окно:
```