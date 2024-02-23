# Лабаратоная работа №1
---
### Тема: Структуры данных
### Цель: Исследовать свойства структур данных и разработать библиотеку алгоритмов обработки конкретной структуры данных


### Условие: неориентированный граф. Вставка вершины. Удаление вершины. Вставка дуги. Удаление дуги. Построение дерева обхода вглубину.
---
#### В решении лабараторной граф был представлен списком смежности, создоваемым в единственном конструкторе
![IMG_1](Images/img1.png)

#### Использовавшиеся библиотеки: util.Stack, util.Hashtable, util.ArrayList.

---

### Реализованные функции:

- void ***AddVertex(String name)***, создаёт вершину с названием name передаваемым в аргументе
- void ***AddEdge (String first, String second)***, создаёт ребро между вершинами first и second, названия которых передаются в аргументе
- void ***printAdjacencyList()***, выводит список смежности для каждой вершины
- void ***deleteVertex(String nameOfVertex)***, удаляет вершину с названием nameOfVertex передаваемым в аргументе
- void ***addArc(String fromVertexName, String toVertexName)***, создаёт дугу из fromVertexName в toVertexName, передаваемыми в аргументе
- void ***deleteArc(String fromVertexName, String toVertexName)***, удаляет дугуиз fromVertexName в toVertexName, передаваемыми в аргументе
- void ***DFSTree()***, строит дерево обхода в глубину
---
## Примеры тестов:
### 1.
![IMG_2](Images/img2.png)
#### Результат:
![IMG_3](Images/img3.png)
### 2.
![IMG_4](Images/img4.png)
#### Результат:
![IMG_5](Images/img5.png)
### 3.
![IMG_6](Images/img6.png)
#### Результат:
![IMG_7](Images/img7.png)
### 4.
![IMG_8](Images/img8.png)
#### Результат:
![IMG_9](Images/img9.png)
### 5.
![IMG_10](Images/img10.png)
#### Результат:
![IMG_11](Images/img11.png)

---
## Вывод: исследовал свойства структур данных и разработал библиотеку алгоритмов обработки конкретной структуры данных
