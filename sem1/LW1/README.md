# БГУИР Лабораторная работа №1

<br />
Условия предоставляемой задачи(вариант 37):
<br />
<br />
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит файл (как параметр пакетного файла), содержащий некоторый список строк. Отсортировать указанный файл. Создать два файла, в первом из которых будут содержаться нечетные строки из входного файла, во втором - четные
<br />
<br />

## Работа файла bat

<br />
Как выглядит код:
<br />

```bash
@echo off
chcp 65001
setlocal enabledelayedexpansion

cd /d "D:\PIOIVIS\LR1"

set inputFile=%~1

if exist %inputFile% (
    sort %inputFile% /O %inputFile%
) else (
    echo Такого файла не существует или что-то введено неверно. Повторите попытку.
	pause
	exit /b 1
)

set oddFile=odd_file_bat.txt
set evenFile=even_file_bat.txt

set "numberLine=0"

for /f "usebackq delims=" %%a in ("%inputFile%") do (
  set /a "remainder=numberLine %% 2"
  if !remainder! equ 0 (
    echo %%a >> "%evenFile%"
  ) else (
    echo %%a >> "%oddFile%"
  )
    set /a "numberLine+=1"
)

pause
```
<br />
Переменные, которые использовались: <br />
inputFile - переменная, которая принимает файл, который нужно будет отсортировать и разбить на четные и нечетные строки <br /><br />
oddFile - переменная, которая принимает файл, который хранит в себе нечетные строки отсортированного файла <br /><br />
evenFile - переменная, которая принимает файл, который хранит в себе четные строки отсортированного файла <br /><br />
numberLine - переменная для определения номера подстроки в файле <br /><br />
remainder - дополнительная переменная, которая хранит в себе остаток от деление переменной numberLine на 2 <br /><br />
<br />
<br />
Начальный текстовый файл, который необходимо отсортировать и разбить на строки
<br />
<br />

![Screenshot_3](https://github.com/iis-32170x/RPIIS/assets/110356280/8d3e8066-0c4d-4572-9787-abb4947151c2)

<br />

## Пример запуска

<br />
<br />
1. Запускаем командную строку Windows(cmd)
<br />
<br />

![Screenshot_17](https://github.com/iis-32170x/RPIIS/assets/110356280/be8c8ca0-720c-4791-9b1d-6ec84aa92948)

<br />
2. Вводим путь к пакетному файлу Windows и, через пробел, текстовый файл, который нужно отсортировать и разбить на четны и нечетные строки
<br />
<br />

![Screenshot_18](https://github.com/iis-32170x/RPIIS/assets/110356280/3b88f746-992a-463c-8bc8-aeb719e4c2c0)

<br />

3. Нажимаем enter и получаем сообщение, что пакетный файл выполнил свою работу
<br />
<br />

![Screenshot_1](https://github.com/iis-32170x/RPIIS/assets/110356280/5a00d02b-237d-4f53-8255-1f6bbef352be)

<br />
4. По итогу в нашей папке появляются два файла: even_file_bat и odd_file_bat. Которые, в свою очередь, имеют четные и нечетные строки
<br />
<br />

![Screenshot_2](https://github.com/iis-32170x/RPIIS/assets/110356280/87dd691b-24dd-4d83-8941-fa065b54c157)

<br />

![Screenshot_4](https://github.com/iis-32170x/RPIIS/assets/110356280/d41e0e28-e3b8-414a-b98b-359254dd4897)

<br />

## Программа выполнена!
<br />

# Работа файла sh

<br />
Как выглядит код:
<br />

```bash
#!/bin/bash

cd /D/PIOIVIS/LR1

inputFile=$1

if [ ! -f "$inputFile" ]; then
  echo "inputFile \"$inputFile\" не существует."
  exit 1
fi

sort "$inputFile" -o "$inputFile"

oddFile="odd_file_sh.txt"
evenFile="even_file_sh.txt"

count=1
while IFS= read -r string; do
  if ((count % 2 == 0)); then
    echo "$string" >> "$evenFile"
  else
    echo "$string" >> "$oddFile"
  fi
  ((count++))
done < "$inputFile"

exit 0
```
<br />
Переменные, которые использовались: <br />
inputFile - переменная, которая принимает файл, который нужно будет отсортировать и разбить на четные и нечетные строки <br /><br />
oddFile - переменная, которая принимает файл, который хранит в себе нечетные строки отсортированного файла <br /><br />
evenFile - переменная, которая принимает файл, который хранит в себе четные строки отсортированного файла <br /><br />
count - переменная для определения номера подстроки в файле <br /><br />
<br />

Начальный текстовый файл, который необходимо отсортировать и разбить на строки
<br />
<br />

![Screenshot_3](https://github.com/iis-32170x/RPIIS/assets/110356280/8d3e8066-0c4d-4572-9787-abb4947151c2)

<br />

## Пример запуска

<br />
<br />
1. Запускаем командную строку Linux(я воспользуюсь git bash)
<br />
<br />

![Screenshot_5](https://github.com/iis-32170x/RPIIS/assets/110356280/5489c72f-d8ee-484d-9a32-8589ecd3fce6)

<br />
2. Вводим путь к Shell Script и, через пробел, текстовый файл, который нужно отсортировать и разбить на четны и нечетные строки
<br />
<br />

![Screenshot_6](https://github.com/iis-32170x/RPIIS/assets/110356280/7a3fee9c-0531-473c-bdd2-9aadbeddc571)

<br />
3. Нажимаем enter и получаем сообщение, что пакетный файл выполнил свою работу
<br />
<br />

![Screenshot_7](https://github.com/iis-32170x/RPIIS/assets/110356280/e826cde1-fdb0-420a-8aa6-7d6bedb7ceb1)

<br />
4. По итогу в нашей папке появляются два файла: even_file_sh и odd_file_sh. Которые, в свою очередь, имеют четные и нечетные строки
<br />
<br />

![Screenshot_8](https://github.com/iis-32170x/RPIIS/assets/110356280/e0632c17-572d-482c-bbd5-8fa63fde442a)

<br />

![Screenshot_9](https://github.com/iis-32170x/RPIIS/assets/110356280/c65c6d58-01a2-4988-9162-0893f8e86d08)

<br />

## Программа выполнена!
<br />

# Итоги
В момент выполнения лабораторной работы №1 были применены навыки работы в командной строке **Windows** и **Linux**. Были созданы программы, выполняющие алгоритмы, соответствующие условиям лабораторной работы №1
