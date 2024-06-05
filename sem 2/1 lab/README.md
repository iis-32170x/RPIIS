# 🧑‍💻Лабораторная работа №1 
![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%88%D0%B5%D0%BD%D0%BE%D0%B2_%D0%95/Screens/800px-Point_quadtree.svg.png)
## 🤖Условие (вариант №15) :
Квадродерево. Перевод матрицы в дерево. Перевод дерева в матрицу.
## 🎯Цель:
Исследовать свойства структур данных и разработать
библиотеку алгоритмов обработки структур данных.

## 📜Список ключевых понятий:

- `Квадродерево`- дерево, в котором у каждого внутреннего узла ровно 4 потомка. 
- Квадродеревья часто используются для рекурсивного разбиения двухмерного пространства по 4 квадранта (области).Области представляют собой квадраты, прямоугольники или имеют произвольную форму.
- Англоязычный термин `quadtree` был придуман Рафаэлем Финкелем и Джоном Бентли  в 1974 году. Аналогичное разбиение пространства известно как Q-дерево.
- Квадродеревья могут быть классифицированы в соответствии с типом данных, который они представляют — пространством, точками, прямыми, кривыми. Также их можно разделить по тому, зависит ли форма дерева от порядка обработки данных. 

####Структура узла####
Узел квадродерева, хранящего информацию о точках плоскости, аналогичен узлу бинарного дерева лишь с той оговоркой, что узел первого имеет четыре потомка (по одному на каждый квадрант) вместо двух («правого» и «левого»). Ключ узла состоит из двух компонент (для координат x и y). Таким образом, узел дерева содержит следующую информацию:

4 указателя: quad[`NorthWest`], quad[`NorthEast`], quad[`SouthWest`], и quad[`SouthEast`],
- *точка, описываемая следующим образом:*
- **ключ key, обычно выражает координаты x и y,**
- **значение value, например, имя.**
## Алгоритм
### Построение дерева из матрицы
Для построения квадродерева из матрицы воспользуемся разбиением матрицы на 4 равные части. Так будем делать до тех пор, пока все части не будут разбиты до минимального размера (1 на 1, то есть само значение) либо же определенная часть не будет содержать одинаковые значения (т. к. дальнейшее разбиение будет бессмысленным). В зависимости от того, какое количество раз мы будем разбивать определенную четверть матрицы, будет зависить глубина определенного узла. Для удобства каждая  `-` будет обозначать одну единицу глубины.
![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%88%D0%B5%D0%BD%D0%BE%D0%B2_%D0%95/Screens/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202024-03-20%20222600.png)
### Построение матрицы из дерева 
Для построения матрицы из дерева сначала дадим пользователю ввести глубину дерева, что позволит нам сразу определить размер матрицы по формуле `N=pow(2,depth)`. Далее для каждой `-` создадим функцию деления определенной четверти матрицы на глубину. Например: для `--` разобьём матрицу размером 8 на 8 до куска размером 2 на 2, матрицу 4 на 4 до куска размером 1 на 1 и т.д. 
![image](https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%88%D0%B5%D0%BD%D0%BE%D0%B2_%D0%95/Screens/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202024-03-20%20223751.png)
## Источники
[youtube.library](https://www.youtube.com/watch?v=5mD-rhaYF4U&list=LL&index=9)
[stackoverflow](https://ru.stackoverflow.com/search?q=%5Bc%2B%2B%5D+%D0%BF%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BD%D0%B8%D0%B5+%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%B0)
[vikikonspect](https://neerc.ifmo.ru/wiki/index.php?title=%D0%9A%D0%B2%D0%B0%D0%B4%D1%80%D0%BE%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D1%8C%D1%8F)
[viki.osnova](https://en.wikipedia.org/wiki/Quadtree)