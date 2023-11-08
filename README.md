# Цель лабораторной работы №1

- Ознакомиться с командной строкой операционных систем _Windows_ и _Linux_.
- Создать исполняемые файлы _.bat_ и _.sh_ в соответствии с заданными правилами.

## Условие лабораторной работы. [Вариант 10]()

![photo](6.png)

# Реализация кода на [bash]()

~~~sh
#!/bin/bash

directory=$1
size=$2

if [ ! -d "$directory" ]; then
  echo "Данной папки нет"
  exit 1
fi

output_file="laboratory1.txt"

find "$directory" -type f -size "-$size"c -exec basename {} \; > "$output_file"

echo "Файлы размером меньше $size байт:"
cat "$output_file"
~~~
 ## Запуск кода в консоли 
![photo2](4.png)
## Пример работы программы
![photo3](5.png)
---
![photo4](7.png)

## Описание строчек кода

```sh
#!/bin/bash
````
Это обязательная первая строка в bash-скриптах, указывающая на то, что скрипт должен быть выполнен с помощью интерпретатора bash.

````sh
directory=$1
size=$2
````

Строка определяет две переменные `$directory` и `$size`. Они принимают значения из переданных скрипту аргументов: `$1` - первый аргумент, `$2` - второй аргумент.

````sh
if [ ! -d "$directory" ]; then
  echo "Данной папки нет"
  exit 1
fi
````
Строка проверяет, существует ли указанная папка `$directory`. Если папка не существует, выводится сообщение "Данной папки нет", и скрипт завершает свою работу с кодом выхода 1.
```sh
output_file="laboratory1.txt"
```
Строка определяет переменную `$output_file` со значением "laboratory1.txt". Это будет имя файла, в который будет записан результат.

````sh
find "$directory" -type f -size "-$size"c -exec basename {} \; > "$output_file"
```````
Строка использует команду `find` для поиска файлов в директории `$directory`. Затем используется фильтр `-type f`, чтобы найти только файлы, а не директории. Фильтр `-size "-$size"c` означает поиск файлов, размер которых меньше указанного значения `$size` в байтах. Опция `-exec basename {} \;` используется для вывода только имен файлов (без пути). Результат записывается в файл `$output_file`.


```sh
echo "Файлы размером меньше $size байт:"
cat "$output_file"
```
Строка выводит сообщение **"Файлы размером меньше $size байт:"**. Затем команда `cat` используется для показа содержимого файла `$output_file`.

# Реализация кода в [batch]()
```bat
@echo off
setlocal
chcp 868
set "directory=%~1"
set "size=%~2"

if not exist "%directory%" (
  echo Данной папки нет
  exit /b 1
)

set "output_file=laboratornaya.txt"

for /r "%directory%" %%F in (*) do (
  if %%~zF LSS %size% (
    echo %%~nxF >> "%output_file%"
  )
)

echo Файлы размером меньше %size% байт:
type "%output_file%"

endlocal
```
## Запуск кода
![photo5](1.png)
## Пример работы программы
![photo6](2.png)








