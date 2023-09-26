# BSUIR cmd-bash
В рамках ЛР 1 необходимо создать файл с разрешением *bat.* и *sh.* в соответствии с заданным вариантом.
Цель данной лаборотоной работы - ознакомится с командными строками операционных систем *Windows* и *Linux*.

## Условие ЛР1 (36 вариант)
![image](https://github.com/Iltsd/pics/assets/144996957/76f710e5-623d-4131-8580-0b6953cbd5ea)

## Описание алгоритма, пример запуска и выполнения программы (.bat)
![image](https://github.com/Iltsd/pics/assets/144996957/094ac61b-d6c1-463d-83b5-e587c2a3dd97)

#### Используемые переменные:
- *size* - переменная хранящая размер создаваемого текстового файла.
- *text* - текст,который записывается в текстовый файл. Затем изменяется для подсчета количества символов.
- *textpath* - путь к создаваемому текстовому файлу.
- *count* - переменная хранящая количество символов в текстовом файле.
- *H* - часы создания файла.
- *M* - минуты создания файла.
- *sum2* - переменная хранящая длинну иерархии папок.
- *base_path* - путь к первой папки иерархии папок.
- *folder_path* - изменияющаяся переменная к новому уровню иерархии.
- *current_level* - название нового уровня иерархии.

## Разбор кода:

      setlocal enabledelayedexpansion
Режим отложенного расширения переменных среды. Позволяет использовать перезаписывающиеся переменные с !...!.
#### Функции:
![image](https://github.com/Iltsd/pics/assets/144996957/80dcfeeb-e819-4ad0-b329-d6eba1fa7d1c)
1. _fsutil file createnew_ - встроенная функция для создания файла определённого размера и пути.
2. _echo "text" > "path"_ - создание файла с записанным текстом.

![image](https://github.com/Iltsd/pics/assets/144996957/db81be29-bcb7-49d0-90d0-5f6d0db58f50)
1. _if not "%text%"=="" - проверка на наличие символов в каждом цикле после _:start_.
2. _else (goto exit)_ - выход при отсуцтвии символов.
3. 
![image](https://github.com/Iltsd/pics/assets/144996957/de6b5f4f-e290-424a-89c3-de6d78f7f5d5)
1. _create_folders_ - созданная функция для создания иерархии папок и добавления текстового файла на каждом уровне.
2. _call_ : create_folders %sum2% 1 "%base_path%" - присвоение функции *create_folders* количество уровней иерархии и пути.
3. _goto: eof_ - перемещение на строку.
4. _md_ - cоздание котолога.
5. *folder_path* - путь к новому уровню иерархии (перезаписывается с каждым повторением функции *create_folders*.

## Пример и алгоритм работы:
    Запуск командной строки 
    
![image](https://github.com/Iltsd/pics/assets/144996957/9eda60b9-f13b-406f-908a-567d481a88dd)

    Открытие .bat файла:
    Переход к папке - _cd_путь к папке_
    Запуск .bat файла - start "Имя файла"

![image](https://github.com/Iltsd/pics/assets/144996957/376a069c-6f9e-4a5e-8e1c-c25f9c178dd9)

    Ввод размера и записываемого текста.
    Вывод значения переменной подсчёта количества символов.
    Вывод времени создания и результата вычисления переменной sum2.

![image](https://github.com/Iltsd/pics/assets/144996957/65d28250-8e6f-4adc-8217-fd561024b8a3)

    Результат работы ввиде текстового файла с записанным текстом 
    и иерархии папок с созданым в них текстовым фалом(название - время создания).

![image](https://github.com/Iltsd/pics/assets/144996957/311232a7-6173-4528-8119-7c6e92183cfa)

![image](https://github.com/Iltsd/pics/assets/144996957/dc9e57ac-a92d-4129-9052-f7f12c16292f)

Работа .bat файла окончена.







  
