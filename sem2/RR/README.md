Расчетная работа
№2.14
Найти количество компонент связности в неориентированном графе

Цели лабораторной работы:

Продемонстрировать графодинамику выполнения алгоритма

Ключевые понятия
Граф - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

Неориентриванный граф  - это граф, в котором ребра не имеют направления или ориентации. В неориентированном графе каждое ребро соединяет две вершины и представляет собой неупорядоченную пару вершин.

Количество компонент связности - это множество вершин графа достижимых попарно и рёбра их связывающие

Описание алгоритма:

1.Задается неориентированный граф

2. Мы начинаем с произвольной вершины в графе. Помечаем ее как "посещенную". Затем мы последовательно переходим ко всем ее смежным (соседним) вершинам, которые еще не были посещены, и помечаем их как "посещенные". Продолжая этот процесс, мы обходим все вершины, связанные с нашей начальной вершиной.

3. Последовательно переходим ко всем ее смежным (соседним) вершинам, которые еще не были посещены, и помечаем их как "посещенные".

4. Продолжая этот процесс, мы обходим все вершины, связанные с нашей начальной вершиной.

5. Когда мы исчерпали все связанные с ней вершины, это означает, что мы нашли одну связную компоненту графа. Мы записываем, что обнаружили очередную связную компоненту.

6. Затем мы ищем следующую непосещенную вершину и повторяем процесс обхода, чтобы найти следующую связную компоненту. Мы продолжаем этот процесс, пока не обойдем все вершины графа.

Результат формализации алгоримта РР
1.Задается неориентированный граф
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/5c9bdb8d-3c3d-4398-bf5f-59a624c79de2)


2. Программа начинает обход по вершинам, начиная с первой заданной пользователем(предположим А)
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/123ef147-a0f1-46c7-ab6c-d05dd575a034)


3. Начинаем обход с вершины A, заносим ее в список visited.
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/023db1e6-0c4a-4e6b-906e-516802158633)



4. Идем к cмежной непосещенной вершине B, убирая ребро AB и записывая B в список visited.
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/46fb11d9-b8c6-41cc-b333-c0bc770e3f88)



5. Повторяем это, пока не доходим до вершины для которой нету смежной. Увеличиваем значение count на 1, т.к найдена компонента связности.
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/0b5ee7ec-7eb2-4dfa-9fb3-e0f831bcde6d)



6. Продолжаем наш алгоритм, переходим к следующей непосещенной вершине и ищем к ней смежные. Когда смежных вершин не остается вновь увеличиваем значение count на 1, в связи с нахождением второй компоненты. 
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/dde23b31-d895-41bf-9ccd-f393817fb822)


Формализация понятия "количество компонент связности":
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/cb8a791f-c29d-4925-a13e-535af4966f36)
Формализацяи понятия "неориентированный граф":
![image](https://github.com/iis-32170x/RPIIS/assets/148707516/0a05ead9-85a0-4486-a262-4fe6f790ac6c)


![image](https://github.com/iis-32170x/RPIIS/assets/148707516/e54b17bd-bb97-4a1a-93fb-77108238dc9c)








