# Формализация расчетной работы.
## Декартово произведение 2 неориентированных графов

1. Задаем 2 неориентированных графа:

![Screenshot 2024-05-29 095344](https://github.com/iis-32170x/RPIIS/assets/144227421/0af2d906-fb61-4d7a-8350-0b36ab1eff9e)


2. Выбираем вершину, с которой начнем выполнять декартово произведение:

![Screenshot 2024-05-29 095419](https://github.com/iis-32170x/RPIIS/assets/144227421/e1e906a7-b51f-4d1c-9a46-f2205f894f85)


3. Перемножаем вершины и получаем новые, которые заносим в новый граф (для вершины В делаем то же самое):

![Screenshot 2024-05-29 095440](https://github.com/iis-32170x/RPIIS/assets/144227421/fcc09fcf-2772-4638-b982-a1dd8eeca49a)


4. Соединяем новые вершины дугами: если 1ые компоненты равны, а 2ые не равны, то соединяем вершины; если 2ые компоненты равны, а 1ые не равны, то соединяем вершины:

![Screenshot 2024-06-01 183349](https://github.com/iis-32170x/RPIIS/assets/144227421/2051c546-2d3e-4e36-83f4-04347edffce5)


5. Полный алгоритм:

![Screenshot 2024-06-01 193610](https://github.com/iis-32170x/RPIIS/assets/144227421/49f5f505-3903-4202-b71f-4076398395ad)



## Формализация понятий

Неориентированный граф:

![Screenshot 2024-06-01 184812](https://github.com/iis-32170x/RPIIS/assets/144227421/34d818f3-94bd-4947-bf04-f8a31237168a)


Декартово произведение:

![Screenshot 2024-06-01 193931](https://github.com/iis-32170x/RPIIS/assets/144227421/27159632-a74b-42e3-93fe-3dda038dda9c)



## Данные, загруженные в OSTIS

![Screenshot 2024-06-01 194956](https://github.com/iis-32170x/RPIIS/assets/144227421/b268bff1-694a-4116-b1fa-500f96599a8a)


![Screenshot 2024-06-01 195133](https://github.com/iis-32170x/RPIIS/assets/144227421/1ef63f58-8a0a-46f4-bc87-659c9faa2386)


![Screenshot 2024-06-01 195207](https://github.com/iis-32170x/RPIIS/assets/144227421/822f2bbc-d3bc-4cff-87ff-9c08cf42b95a)


## Примеры тестов

![Screenshot 2024-06-01 195812](https://github.com/iis-32170x/RPIIS/assets/144227421/92d07e58-f143-4f2a-a035-a800011854f8)


![Screenshot 2024-06-01 200031](https://github.com/iis-32170x/RPIIS/assets/144227421/0576aef4-cfd2-478d-8753-4ab39132f0a8)

