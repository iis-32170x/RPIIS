# BSUIR laba1
Условие программы (вариант 42):
<br />
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит число (как параметр пакетного файла).
В данном числе найти самую максимальную цифру, 
создать ровно столько файлов с расширением txt,
у каждого второго поменять расширение на doc и записать туда сегодняшнюю дату.
<br />
<br />
<br />
## ПРИМЕР РАБОТЫ ФАЙЛА 1.bat
так выглядит код программы :
```bash
@echo off
chcp 65001
echo Введите число не превышающее 100:
set /p a=N=
if %a% gtr 100 (echo НЕВЕРНЫЕ ДАННЫЕ )
if %a% lss 0 (echo НЕВЕРНЫЕ ДАННЫЕ )
set /a ending=%a%%%10
set /a starting=%a%/10
set datetemp=%date:~-10%
cd C:\Users\devert\Documents\LABY\PIVO
md test
cd C:\Users\devert\Documents\LABY\PIVO\test
if %ending% gtr %starting% ( for /l %%i in (1,1,%ending%) do ( echo %datetemp% > %%i.txt )
                                   for /l %%i in (2,2,%ending%) do ( ren %%i.txt %%i.doc ) 
                                             for /l %%i in (1,2,%ending%) do ( del %%i.txt
                                                                     echo тут няма ничога > %%i.txt )
) else ( 
          for /l %%i in (1,1,%starting%) do ( echo %datetemp% > %%i.txt ) 
             for /l %%i in (2,2,%starting%) do ( ren %%i.txt %%i.doc )
                   for /l %%i in (1,2,%starting%) do ( del %%i.txt
                                                         echo тут няма ничога > %%i.txt ) )
pause
```
переменные:
<br />
-a наше число приходящее от пользователя <br />
-ending цифра на которую заканчивается число <br />
-starting цифра на которую начинается число <br />
-datetemp переменная содержащая дату <br />
<br />
на вход пакетному файлу приходит число.
просим ввести число не превышающее 100,если пользователь вводит данные неверно то мы завершаем программу.
далее мы задаем переменные ending и starting которым присваеваем значения начальной и конечной цифры числа.
в строках 10 11 и 12 мы переходим в нужную нам директорию и создаем там папку test в которой происходит дальнейшее выполнение программы
```bash
set /p a=N=
if %a% gtr 100 (echo НЕВЕРНЫЕ ДАННЫЕ )
if %a% lss 0 (echo НЕВЕРНЫЕ ДАННЫЕ )
set /a ending=%a%%%10
set /a starting=%a%/10
```
<br />
Строка 

```bash
if %ending% gtr %starting%
```
сравнивает конечную цифру и начальную.
<br />
<br />
далее если конечная цифра больше начальной запускаем цикл создания файлов до цифры равной конечной
следующий цикл меняет расширение каждого второго файла на doc 
и третий цикл удаляет текст файлов txt и пишет туда текст "тут няма ничога"

```bash 
if %ending% gtr %starting% ( for /l %%i in (1,1,%ending%) do ( echo %datetemp% > %%i.txt )
                                   for /l %%i in (2,2,%ending%) do ( ren %%i.txt %%i.doc ) 
                                             for /l %%i in (1,2,%ending%) do ( del %%i.txt
                                                                     echo тут няма ничога > %%i.txt )
```
если же у нас начальная цифра больше,то делаем до начальной цифры выполняя все те же 3 цикла что и ранее:
```bash
for /l %%i in (1,1,%ending%) do ( echo %datetemp% > %%i.txt )
                                   for /l %%i in (2,2,%ending%) do ( ren %%i.txt %%i.doc ) 
                                             for /l %%i in (1,2,%ending%) do ( del %%i.txt
                                                                     echo тут няма ничога > %%i.txt )
```
Что получаем на выходе?
при вводе числа 87 программа сначала сравнивает цифры числа между собой,находит наибольшее а далее проводит циклы создания файлов и изменения их расширения

![изображение](https://github.com/iis-32170x/RPIIS/assets/144791941/ff62bc0f-b4d0-400e-8980-4f8ead2cc7f5)
![изображение](https://github.com/iis-32170x/RPIIS/assets/144791941/e93d46be-4566-4f76-b1df-1f191d3c6291)


## ПРИМЕР РАБОТЫ ФАЙЛА 1.sh
код программы :
```bash
#!/bin/bash
echo "vvedite chislo menshee 100: "
read N
mkdir testshell
cd testshell 
if [ $N -ge 100 ] 
then 
echo "NEVERNYE DANNYE"
read N
fi
if [ $N -le 0 ]
then 
echo "NEVERNYE DANNYE"
read N
fi
let "a=$N/10"
b=$(($N%10))
if [ $a -gt $b ]
then
     for (( i=1; i <= $a; i++ ))
do
        touch $i.txt
done
     for ((i=2; i<=$a;i=i+2 ))
do
         mv $i.txt $i.doc
		 date > $i.doc
done
else 
     for (( i=1; i <= $b; i++ ))
do
         touch $i.txt
done
     for ((i=2; i<=$b;i=i+2 ))
do
         mv $i.txt $i.doc
		 date > $i.doc
done
fi 
sleep 1m
```
<br />
переменные: 
-N переменная ввод которой с клавиатуры <br />
-a переменная которая является начальной цифрой числа <br />
-b переменная которая является конечной цифрой числа <br />
<br />
В первых строках кода мы задаем входные данные и создаем папку testshell в которой будут храниться наши файлы
также установим некоторые рамки входных данных.Если же пользователь вводит неверные данные останавливаем программу
также вводим переменные равные начальной и конечной цифре числа.

```bash
#!/bin/bash
echo "vvedite chislo menshee 100: "
read N
mkdir testshell
cd testshell 
if [ $N -ge 100 ] 
then 
echo "NEVERNYE DANNYE"
read N
fi
if [ $N -le 0 ]
then 
echo "NEVERNYE DANNYE"
read N
```
далее как и раньше с помощью операции if мы сравниваем цифры числа и ищем наибольшее.Когда программа определяет наибольшее,создаются два цикла.В первом цикле мы создаем файлы txt.Затем меняем их расширение на doc и пишем в каждый doc сегодняшнюю дату.

```bash
if [ $a -gt $b ]
then
     for (( i=1; i <= $a; i++ ))
do
        touch $i.txt
done
     for ((i=2; i<=$a;i=i+2 ))
do
         mv $i.txt $i.doc
		 date > $i.doc
done
else 
     for (( i=1; i <= $b; i++ ))
do
         touch $i.txt
done
     for ((i=2; i<=$b;i=i+2 ))
do
         mv $i.txt $i.doc
		 date > $i.doc
done
fi
```
что имеем на выходе?
при вводе числа 87 программа вначале сравнивает цифры числа и создает нужное количество файлов(в данном случае 8).
далее меняет расширение и пишет туда дату.

![изображение](https://github.com/iis-32170x/RPIIS/assets/144791941/3fc7b54c-23b6-4ad8-acec-3ac1af20ab58)
![изображение](https://github.com/iis-32170x/RPIIS/assets/144791941/b101b9af-18aa-4b05-a88d-b16daf743580)

# ИТОГ
выполнил условие задания и описал все максимально подробно.
