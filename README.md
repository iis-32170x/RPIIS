# Лабораторная работа №1

## Вариант 35
Условие:
> На вход пакетному файлу приходит путь к каталогу (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то найти в заданном каталоге и всех его подкаталогах все файлы заданного размера и принадлежащие определённому пользователю. Диапазон (min - max) размеров файлов задаётся пользователем в качестве второго и третьего параметра пакетного файла. Имя владельца задаётся пользователем в качестве четвёртого параметра пакетного файла. Скрипт выводит результаты поиска в файл в виде "полный путь, имя файла, его размер", в конец файла выводится общее число просмотренных файлов

## Параметры запуска
1. Путь к папке, с которой будет вестись работа.
2. Минимально допустимый размер файла в папке.
3. Максимально допустимый размер файла в папке.
4. Какой должен быть у файла владелец.

## Словесное описание алгоритма
1. Пользователь одновременно с запуском скрипта вводит 4 указанных выше параметра.
2. Проверка на существование папки, указанной в первом параметре.
   - Если папка не существует, программа завершает свою работу.
3. Проход по папке и её подпапкам.
4. Вывод полного и краткого имени, а также размера тех файлов в папке и её подпапках, которые удовлетворяют следующим условиям:
   - Размер находится в диапазоне, заданном во втором и третьем параметрах;
   - Владелец файла совпадает с указанным в четвёртом параметре.

## Полный код скрипта
CMD:
```batchfile
@echo off
rem Кодировка - UTF-8
chcp 65001 >nul
rem Для корректной работы переменных
setlocal EnableDelayedExpansion

rem Если папки, указанной в первом параметре, не существует:
if not exist %1%\ (
echo Данной папки нет
pause

rem В противном случае:
) else (

rem Проход по файлам в данной папке, в т.ч. и подпапках:
for /f "delims=" %%i in ('dir /a-d/b/s %1') do (

rem Т.к. в bat нет встроенной функции определения владельца файла,
rem необходимо вызвать скрипт PowerShell, в котором данная функция есть.
PowerShell.Exe -executionpolicy bypass -File "findowner.ps1" "%%i" >op.tmp
set /p owner=<op.tmp
del op.tmp

rem Если размер файла входит в заданный диапазон и у него подходящий владелец,
rem произвести вывод его полного названия, краткого названия и его размера:
if %%~zi leq %3 if %%~zi geq %2 if "!owner!" equ "%4" echo %%i %%~nxi %%~zi>con)

rem Отдельным циклом произвести подсчёт всех файлов в папке и её подпапках:
set ff=0 & for /f "delims=" %%i in ('dir /a-d/b/s %1') do @(set /a ff+=1 >nul)

rem Вывод количества файлов:
echo Всего файлов прочитано: !ff! && set "ff="
pause
)
```
		
Вспомогательный алгоритм findowner.ps1:
```powershell
param ($thefile)
(Get-Acl $thefile).Owner
```


Shell:
```shell
#!bin/bash

# Если данной папки не существует:
if ! test -d "$1"
then
	echo Данной папки нет

# Если папка существует:
else
	# Переменная подсчёта количества файлов:
	count=0
			
	# Если в папке есть подпапки:
	if test -d $1/**/
	then
		# Поиск файлов в папке и её подпапках.
		for file in $1/*.* $1/**/*.*
		do
			# Подсчёт количества файлов:
			let count=count+1
			
			# Размер файла
			fsize=`cat $file | wc -c`
			# Владелец файла
			fuser=`stat --format '%U' $file`
					
			# Если у файла размер в заданном диапазоне и у него подходящий владелец:
			if [[ $fsize -le $3 && $fsize -ge $2 && $4=$fuser ]]
			then
				# Вывод полного имени файла, краткого имени файла и его размера:
				echo $file `basename $file` $fsize
			fi
		done
	
	# Если в папке нет подпапок:
	else
		# Поиск файлов только в этой папке, т.к. подпапок нет.
		for file in $1/*.*
		do
			# Подсчёт количества файлов:
			let count=count+1
			
			# Размер файла
			fsize=`cat $file | wc -c`
			# Владелец файла
			fuser=`stat --format '%U' $file`
			
			# Если у файла размер в заданном диапазоне и у него подходящий владелец:
			if [[ $fsize -le $3 && $fsize -ge $2 && "$4"="$fuser" ]]
			then
				# Вывод полного имени файла, краткого имени файла и его размера:
				echo $file `basename $file` $fsize
			fi
		done
	fi
			
	# Вывод количества файлов в папке и подпапках:
	echo Всего файлов прочитано: $count
fi
```

## Пример запуска
Дана следующая папка:

![Изображение папки](img/test_folder.png)
![Изображение подпапки](img/test_subfolder.png)

Запуск команды с путём к этой папке в качестве параметра:

![Изображение команды (bat)](img/test_command_bat.png)

![Изображение команды (sh)](img/test_command_sh.png)
