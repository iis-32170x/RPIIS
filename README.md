# Рассмотрим пример формализации понятия Систематическое программирование из этой [статьи](https://konference.nvsu.ru/konffiles/357/Fursova_K.A.,_Kalinin_YU.D.,_Babicheva_N.B._45.pdf)

Для начала поищем в стандарте и монографии всё, что может быть связано с выбранным понятием. Например, убедимся, что понятие не  формализовано.

Далее нам нужно ответственно подойти к выбору дополнительных источников (статей, книг) для формализации понятия. Для этого необходимо сделать как можно более полный обзор литературы, где это понятие описывается с разных точек зрения. Найти что-то общее (оно вероятней всего будет достоверным) и использовать его для своей формализации.

***

## Шаг 1. 
Запишем название понятия с помощью \scnheader{понятие}


![image](https://github.com/Dashulik10/1-/assets/144939580/c56e372b-89ee-4abe-a7bf-a4df5cd495eb)


## Шаг 2. 
Поищем в статье синонимы к выбранному понятию (можно поискать их в других источниках). Нам нужно найти наиболее точное описание объекта. То есть найти его идентификаторы. Будем использовать \scnidtf{идентификатор}: 

![image](https://github.com/Dashulik10/1-/assets/144939580/4503005f-dfbb-443d-8446-a478b1bbe21e)



## Шаг 3. 
Находим чёткое определение понятие, если таковое имеется. Записываем с помощью структуры \scnrelfromset{отношение}{}

![image](https://github.com/Dashulik10/1-/assets/144939580/154c7495-f9ac-43f5-a1a7-7934a78dd0c7)

## Шаг 4.
Не менее важный шаг - это пояснение к тексту. Зачастую бывает так, что определение понятия, следствие или причина написано на тяжёлом математическом языке или просто нуждается в пояснении(уточнении). Для того, чтобы сделать текст понятнее мы его дополняем. 

![image](https://github.com/Dashulik10/1-/assets/144939580/0d6aae4b-0caa-4f57-8013-b326983e270a)

### Так же используем примечания
![image](https://github.com/Dashulik10/1-/assets/144939580/985ac19a-721f-4d1c-a2c5-99e8297a69e7)
![image](https://github.com/Dashulik10/1-/assets/144939580/c4423719-9d13-4897-a265-afc4f022b344)

## Шаг 5.
В нашей статье говорится про разные методы системного программирования. Эту информацию мы также будем использовать в нашем тексте. Для этого мы сформулируем зависимость между системным программирование и его методами в качестве декомпозиции. (Так как мы НЕ можем утверждать, что методы не могут пересекаться друг с другом, полностью исключать друг друга). 
### Здесь же поясняем в чём состоит суть методов и какие их достоинства и недостатки. 

![image](https://github.com/Dashulik10/1-/assets/144939580/082c4ef4-a01b-436e-a4ab-ebf54c42438a)

Описываем так каждый метод. 


## Шаг 6. 
Когда основа готова мы начинаем думать, какие связи мы можем добавить с уже существующими в стандарте понятиями. Для добавления используем значки принадлжености, строго подмножества, строго надмножества и тд. Например: 

```
\scnidtf{синонимичный идентификатор}
\scniselement{принадлежность}
\scnhaselement{принадлежность}
\scnsuperset{строгое надмножество --- <<включает в себя>>}
\scnsubset{cтрогое подмножество --- <<включено в>>}
```
