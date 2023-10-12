# Условие (4 вариант)
На вход пакетному файлу приходит число (как параметр пакетного файла). Если число не задано, то выводить сообщение в консоль “Параметр не задан”.
Создать файл 1.txt в него записать рандомные числа в количестве заданном параметром пакетного файла, каждое число на новой строке. Вывести сообщение “Рандомные числа созданы” в консоль.
# Реализация на BATCH
```batch
@echo off
Setlocal EnableDelayedExpansion
set /p num= Enter number: 
if defined num (echo Number of random numbers = %num%) else (
echo The parameter is not set
pause
exit
)
for /L %%i in (1, 1, %num%) do (
	set /a i = !random!
	echo !i! >> 1.txt
)
pause

```
# Пример запуска
![image](https://github.com/iis-32170x/RPIIS/assets/146393417/e610f135-28c4-4a8b-840e-d77e9f0ddddd)
![image](https://github.com/iis-32170x/RPIIS/assets/146393417/45ff987b-e89c-4dd8-bae2-53389e54e4e2)
![image](https://github.com/iis-32170x/RPIIS/assets/146393417/95a4062c-3573-4537-a554-cecec47ac629)
# Переменные 
- num-число, введённое пользователем(кол-во рандомных чисел, записанных в текстовый файл)
- i-переменная, использующаяся для создания и записывания рандомных чисел в текстовый файл
# Реализация на BASH
```bash
#!/bin/bash
echo "Enter number:"
read number

if [[ -z "$number" ]]; then
   echo "The parametre is not set"
   exit
fi
echo "Number of random numbers is $number"
for ((i=1; i<=$number; i++))
do
num=$RANDOM
echo "$num" >> 1.txt
done

```
# Пример запуска
![image](https://github.com/iis-32170x/RPIIS/assets/146393417/5bb8dc7f-c749-42f3-b662-0560bacd22c9)
![image](https://github.com/iis-32170x/RPIIS/assets/146393417/fcb606c5-6aff-4144-ad03-1d41d7b914e9)
# Переменные 
- number-число, введённое пользователем(кол-во рандомных чисел, записанных в текстовый файл)
- i-Движение по циклу
- num-переменная, использующаяся для создания и записывания рандомных чисел в текстовый файл








