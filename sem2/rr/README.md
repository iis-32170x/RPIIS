# Расчетная работа

**№1.1**  
Определить, является ли граф деревом.

## Цели лабораторной работы:

1.Продемонстрировать графодинамику выполнения алгоритма

### Ключевые понятия

`Граф` - математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

`Неориентриванный граф ` - это граф, в котором ребра не имеют направления или ориентации. В неориентированном графе каждое ребро соединяет две вершины и представляет собой неупорядоченную пару вершин.

`Дерево ` - это особый случай графа, в котором нет циклов или замкнутых путей.

## Описание алгоритма:

1.Задается неориентированный граф

2.С помощью алгоритма DFS определяем, является ли граф деревом или нет

### Результат формализации алгоримта РР

1.Задается неориентированный граф.

![https://github.com/iluxa313/iluxa313/blob/main/rr1.png](https://github.com/iluxa313/iluxa313/blob/main/rr1.png)

2.Начинаем обход графа с вершины 1.

![https://github.com/iluxa313/iluxa313/blob/main/rr2.png](https://github.com/iluxa313/iluxa313/blob/main/rr2.png)

3.Помечаем вершину 1 как посещенную.

![https://github.com/iluxa313/iluxa313/blob/main/3rr.png](https://github.com/iluxa313/iluxa313/blob/main/3rr.png)
4.Переходим к соседним вершинам 2 и 3, и записываем их в посещенные вершины.

![https://github.com/iluxa313/iluxa313/blob/main/4rr.png](https://github.com/iluxa313/iluxa313/blob/main/4rr.png)

5.Посещаем соседей вершины 2 - вершины 4 и 5, если они еще не посещены, и записываем их в посещенные вершины.

![https://github.com/iluxa313/iluxa313/blob/main/5rr.png](https://github.com/iluxa313/iluxa313/blob/main/5rr.png)

6.Посещаем соседей вершины 3 – вершину 6, если она еще не посещена, и записываем её в посещенные вершины.

![https://github.com/iluxa313/iluxa313/blob/main/6rr.png](https://github.com/iluxa313/iluxa313/blob/main/6rr.png)

7.Все вершины посещены. Обход графа в ширину завершен.
Таким образом, мы посетили все вершины графа и не обнаружили циклов. Граф является деревом.

![https://github.com/iluxa313/iluxa313/blob/main/7rr.png](https://github.com/iluxa313/iluxa313/blob/main/7rr.png)

*Завершаем программу

## Вывод
Формализовал алгоритм определения графа на дерево.

## Тесты
### Тест 1
![https://github.com/iluxa313/iluxa313/blob/main/t1.png](https://github.com/iluxa313/iluxa313/blob/main/t1.png)

Результат: граф не является деревом

### Тест 2
![https://github.com/iluxa313/iluxa313/blob/main/t2.png](https://github.com/iluxa313/iluxa313/blob/main/t2.png)

Результат: граф не является деревом

### Тест 3
![https://github.com/iluxa313/iluxa313/blob/main/t3.png](https://github.com/iluxa313/iluxa313/blob/main/t3.png)

Результат: граф является деревом
