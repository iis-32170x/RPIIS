# Расчётная работа

### Цель

Формализовать выполнение алгоритма в виде SCg-кода.

### Задание

Найти объединение множества неориентированных графов.

### Ключевые понятия

`Граф` — математическая абстракция реальной системы любой природы, объекты которой обладают парными связями.

![image](https://github.com/iis-32170x/RPIIS/blob/d995a1d835d442689442e042789aae0cc76c114f/images/UsualGraph.png)
***

`Неориентированный граф` —  это математическая структура, представляющая собой набор вершин и рёбер, где рёбра не имеют направления.

![image](https://github.com/iis-32170x/RPIIS/blob/d995a1d835d442689442e042789aae0cc76c114f/images/NonOrientedGraph.png)
***

`Множество` — простейшая информационная конструкция и математическая структура,
позволяющая рассматривать какие-то объекты как целое, связывая их.
***

`Объединение графов` — операция над графами, в результате которой получается граф, множества вершин и рёбер которого являются объединениями множеств вершин и рёбер исходных графов.


### Алгоритм решения 

1. Создаём множество неориентированных графов (в данном случае множество состоит из двух неориентированных графов `_gragh_1` и `_gragh_2`).
      
![image](https://github.com/iis-32170x/RPIIS/blob/4ef4a095c87d3d258b48648c2d0e5ea04339e255/images/RR.png)
***

2. Создаём пустой `_gragh_3`, который будет отражать результат объединения множества неориентированных графов. В него сразу переносим все вершины графа `_gragh_1`.
     
![image](https://github.com/iis-32170x/RPIIS/blob/4ef4a095c87d3d258b48648c2d0e5ea04339e255/images/RR1.png)  

![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR2.png)     
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR3.png)
***

4. Создаём переменную `not_checked_v`, где будут храниться непосещённые вершины, и `_checked_v`, где будут храниться посещённые вершины.
         
![image](https://github.com/iis-32170x/RPIIS/blob/d40e5881155c5d4fd5dfc6ccbc7fcacc4e9a03ee/images/RR44.png)
***

5. Создаём волну в произвольной вершине и добавляем её в список волн, исключая вершину из множества непосещённых вершин.
6. Пока это возможно, создаём следующую волну на смежной и непосещённой вершине, удаляя её из множества непосещённых вершин. Если волна оказалась на вершине, из которой нельзя выйти на смежную и непосещённую вершину, то мы переходим к пункту (7).
7. Если в графе остались непосещённые вершины, то переходим к пункту (8), если нет - к пункту (9).
8. Если предположить, что мы находимся на i-той волне, то

    8.1. По списку волн переходим на (i-1)-ую волну.

    8.2. Если это волна включает вершину, из которой можно перейти к смежной непосещённой вершине, то переходим к пункту (6), если нет - к пункту (8.1).
          
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR5.png)  
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR6.png)      
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR7.png)
***

9.  Из графа `_graph_2` берём начальную вершину обхода (в данном случаем вершина B).
10. Сравниваем с каждой вершиной графа `_graph_1`:

   10.1. Если в результате сравнение было найдено совпадение вершины второго графа с вершиной первого, то берём следующую вершину графа `_graph_2` и переходим к пункту (10)

   10.2 Если в результате сравнение не было найдено совпадение вершины второго графа с вершиной первого, то добавляем вершину графа `_gragh_2` к `_gragh_3`.

11. Если в графе `_gragh_2` остались ещё вершины, которые не сравнивались,то берём следующую такую и переходим к пункту 10.
12. Если в графе `_gragh_2` не осталось вершин, которые не сравнивались,то переходим к пункту 13.
      
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR8.png)
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR9.png)
***
Объединение всех вершин множества неориентированных графов `_graph_1` и `_graph_2`
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR10.png)
***

13. Переносим все рёбра графа `_graph_1`.
    
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR11.png)
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR12.png)
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR13.png)
***

14. Создаём переменную `not_checked_e`, где будут храниться непосещённые рёбра, и `_checked_е`, где будут храниться посещённые рёбра.
         
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR14.png)
***

15. Создаём волну в произвольном ребре и добавляем его в список волн, исключая ребро из множества непосещённых рёбер.
16. Пока это возможно, создаём следующую волну на следующем непосещённом ребре, удаляя его из множества непосещённых рёбер. 
          
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR15.png)   
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR16.png)
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR17.png)
***

17.  Из графа `_graph_2` берём начальное ребро обхода (в данном случаем вершина BА).
18. Сравниваем с каждым ребром графа `_graph_1`:

   18.1. Если в результате сравнение было найдено совпадение ребра второго графа с ребром первого, то берём следующее ребро графа `_graph_2` и переходим к пункту (18)

   18.2 Если в результате сравнение не было найдено совпадение ребра второго графа с ребром первого, то добавляем ребро графа `_gragh_2` к `_gragh_3`.

19. Если в графе `_gragh_2` остались ещё рёбра, которые не сравнивались,то берём следующее такое и переходим к пункту (18).
20. Если в графе `_gragh_2` не осталось рёбер, которые не сравнивались,то переходим к пункту (21).
      
![image](https://github.com/iis-32170x/RPIIS/blob/bf7f1dfbc6def2260f6418b8b9b922a53cf56556/images/RR19.png)
***

21. Если есть ещё неориентированный граф в исходном множестве,то переходим к этому графу и переходим к пункту (4).

22. Если в исходном множестве неориентированных гграфов больше нет, переходим к пункту (23).

23. Выводим получившееся объединение множества неориентированных графов.
      
![image](https://github.com/iis-32170x/RPIIS/blob/93f681bde2e2875d0e8638a18202a83cc2881530/images/RRres.png)
***

### Тестовые примеры

#### Тест №1

##### Входные данные
![image](https://github.com/iis-32170x/RPIIS/blob/4ef4a095c87d3d258b48648c2d0e5ea04339e255/images/test1.png)


##### Выходные данные
![image](https://github.com/iis-32170x/RPIIS/blob/93f681bde2e2875d0e8638a18202a83cc2881530/images/test1result.png)
***

#### Тест №2

##### Входные данные
![image](https://github.com/iis-32170x/RPIIS/blob/4ef4a095c87d3d258b48648c2d0e5ea04339e255/images/test2.png)


##### Выходные данные
![image](https://github.com/iis-32170x/RPIIS/blob/93f681bde2e2875d0e8638a18202a83cc2881530/images/test2result.png)
***

#### Тест №3

##### Входные данные
![image](https://github.com/iis-32170x/RPIIS/blob/4ef4a095c87d3d258b48648c2d0e5ea04339e255/images/test3.png)


##### Выходные данные
![image](https://github.com/iis-32170x/RPIIS/blob/93f681bde2e2875d0e8638a18202a83cc2881530/images/test3result.png)
***

### Понятия погруженные в базу знаний интеллектуальной системы на основе Технологии OSTIS.

##### Граф
![image](https://github.com/iis-32170x/RPIIS/blob/d40e5881155c5d4fd5dfc6ccbc7fcacc4e9a03ee/images/ostis1.jpg)
***

##### Неориентированный граф
![image](https://github.com/iis-32170x/RPIIS/blob/d40e5881155c5d4fd5dfc6ccbc7fcacc4e9a03ee/images/ostis2.jpg)
***

### Вывод

В результате выполнения данной расчётной работы был формализован алгоритм построения *объединения* множества неориентированных графов, были изучены:

- Основы теории графов

- Способы представления графов

- Базовые алгоритмы для работы с графами

- Основы SC-кода и SC-алфавита

- Базовые знания о SCg-коде

- Правила формирования идетификаторов sc-элементов

### Источники

- [Руководство к выполнению РР](https://drive.google.com/drive/folders/1RSriLOZWpxyozHjUa1Kz3uZtIr0PixVh)