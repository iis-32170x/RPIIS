# BSUIR_cmd-bash
Данная лабораторная работа была предназначена для ознакомления с командной строкой операционных систем Windows и Linux. В рамках ЛР 1 необходимо создать исполняемый файл .bat и .sh в соответствии с заданным вариантом.
## Условие ЛР 1 (82 вариант)
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/ccad6678-8eec-4af5-a0d9-fbaed95b1c83)
## Описание алгоритма, пример запуска и выполнения программы (.bat файл)
```@echo off
set /a date1 = %date:~0,1%
set /a date2 = %date:~1,1%
set /a date3 = %date:~2,1%
set /a date4 = %date:~3,1%
set /a date5 = %date:~4,1%
set /a date6 = %date:~5,1%
set /a date7 = %date:~6,1%
set /a date8 = %date:~7,1%
if %date1% geq %date1% if %date1% geq %date2% if %date1% geq %date3% if %date1% geq %date4% if %date1% geq %date5% if %date1% geq %date6% if %date1% geq %date7% if %date1% geq %date8% set /a a=%date1%
if %date2% geq %date1% if %date2% geq %date2% if %date2% geq %date3% if %date2% geq %date4% if %date2% geq %date5% if %date2% geq %date6% if %date2% geq %date7% if %date2% geq %date8% set /a a=%date2%
if %date3% geq %date1% if %date3% geq %date2% if %date3% geq %date3% if %date3% geq %date4% if %date3% geq %date5% if %date3% geq %date6% if %date3% geq %date7% if %date3% geq %date8% set /a a=%date3%
if %date4% geq %date1% if %date4% geq %date2% if %date4% geq %date3% if %date4% geq %date4% if %date4% geq %date5% if %date4% geq %date6% if %date4% geq %date7% if %date4% geq %date8% set /a a=%date4%
if %date5% geq %date1% if %date5% geq %date2% if %date5% geq %date3% if %date5% geq %date4% if %date5% geq %date5% if %date5% geq %date6% if %date5% geq %date7% if %date5% geq %date8% set /a a=%date5%
if %date6% geq %date1% if %date6% geq %date2% if %date6% geq %date3% if %date6% geq %date4% if %date6% geq %date5% if %date6% geq %date6% if %date6% geq %date7% if %date6% geq %date8% set /a a=%date6%
if %date7% geq %date1% if %date7% geq %date2% if %date7% geq %date3% if %date7% geq %date4% if %date7% geq %date5% if %date7% geq %date6% if %date7% geq %date7% if %date7% geq %date8% set /a a=%date7%
if %date8% geq %date1% if %date8% geq %date2% if %date8% geq %date3% if %date8% geq %date4% if %date8% geq %date5% if %date8% geq %date6% if %date8% geq %date7% if %date8% geq %date8% set /a a=%date8%
set /a b=%a%/2*2
if %a%==%b% (  echo > d:%a% ) else (echo Hello )
pause
```
### Переменные:
- date1 - 1я цифра даты
- date2 - 2я цифра даты
- date3 - 3я цифра даты
- date4 - 4я цифра даты
- date5 - 5я цифра даты
- date6 - 6я цифра даты
- date7 - 7я цифра даты
- date8 - 8я цифра даты
- a - наибольшая цифра даты
- b - переменная для проверки на четность
### Методы:
- set /a - инициализирует переменную, флаг /а указывает, что строка справа от знака равенства является числовым выражением.
- if - оператор условного выполнения команд.
- geq - оператор сравнения, больше или равно.
- echo - вывод текста на экран консоли, вывод значения переменной в название файла.
- date - значение текущей даты.
### Последовательность действий
1. Присваивание перменным зачения цифр даты
2. Сравнение переменных для поиска наибольшей цифры
3. Проверка на четность
4. Создание файла с максимальной цифрой в названии, если цифра оказалось четной, или вывод Неllo в консоль, если нет
### Пример запуска
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/e3e3b12b-c78c-4971-bb5f-f574d5aafaa6)
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/e6602093-ca91-4933-a335-862d0b9f9700)
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/570ff8f4-3cc2-43f0-b6ae-1cad8dbabbdf)
## Описание алгоритма, пример запуска и выполнения программы (.sh файл)
```
#!/bin/bash
mkdir /home/mayu/Рабочий\ стол/papka
date +%Y-%m-%d > /home/mayu/Рабочий\ стол/papka/data.txt
grep -o "[0-9]" /home/mayu/Рабочий\ стол/papka/data.txt > /home/mayu/Рабочий\ стол/papka/cifri.txt
counter=1
while [ $counter -le 8 ]
do
m[$counter]=`sed -n "$counter"p /home/mayu/Рабочий\ стол/papka/cifri.txt`
((counter++))
done
counter=1
while [ $counter -le 8 ]
do
if (( ${m[$counter]} >= ${m[1]} )) && (( ${m[$counter]} >= ${m[2]} )) && (( ${m[$counter]} >= ${m[3]} )) && (( ${m[$counter]} >= ${m[4]} )) && (( ${m[$counter]} >= ${m[5]} )) && (( ${m[$counter]} >= ${m[6]} )) && (( ${m[$counter]} >= ${m[7]} )) && (( ${m[$counter]} >= ${m[8]} )); then 
				a=${m[$counter]}
				fi
((counter++))
done
let "b=$a/2*2"
			if [ $b == $a ]; then
				echo "Hello"
			else
				echo > /home/mayu/Рабочий\ стол/papka/"$a"
			fi
rm /home/mayu/Рабочий\ стол/papka/data.txt
rm /home/mayu/Рабочий\ стол/papka/cifri.txt
read -p "Press any key"
```
### Переменные:
- counter - счетчик элментов в массиве
- а - наибольшая цифра в дате
- b - переменная для проверки на четность
### Методы:
- mkdir
- date +%Y-%m-%d
- grep -o
- while [] do
- sed -n
- if
- let
- echo
- rm
