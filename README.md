<h1 align="center"> Лабораторная работа <a href="https://daniilshat.ru/" target="_blank">№2</a> 

<h3 align="center">Условие 1 лабораторной работы (вариант 19): Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит абсолютный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней и ее подкаталогах посчитать количество файлов с различными расширениями. Вывести в файл report.txt отчет в виде: doc - 15 txt - 10 exe - 1. В отчет писать в порядке убывания
</h3>
<h1 align="center">Пример запуска и выполнения программы ( .bat )</h1>
1) <h3 align>Создаем папку с файлами с различными расширениями</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/3.png"/>
2) <h3 align>Запускаем bat файл</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(9).png"/>
3) <h3 align>Вводим путь к папке</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(7).png"/>
4) <h3 align>Создается report файл с различными расширениями</h3>
<img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(6).png"/>
<h1 align="center">Описание алгоритма ( .bat )</h1>
<h3 align>1) В этой переменной содержится абсолюный путь к папке с текстовыми файлами.<a href="https://daniilshat.ru/" target="_blank"> - folder</a> 
<h3 align>2) Этой переменной присваивается значение "report.txt"<a href="https://daniilshat.ru/" target="_blank"> - report</a> 
<h3 align>3) В эту переменную сохраняется расширение файла, а также принимает значения ключей массива count<a href="https://daniilshat.ru/" target="_blank"> - ext</a> 
  <h1 align="center">Последовательность действий:</h1>
 <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(1).png"/>
 <h4 align>1)@echo off - отключает вывод команд в консольный интерфейс.</h4>
<h4 align>2)chcp 65001 > nul - устанавливает кодировку консоли на UTF-8.</h4>
<h4 align>3)setlocal enabledelayedexpansion - включает отложенное разрешение переменных.</h4>
<h4 align>4)set /p "folder=Введите путь к папке: " - запрашивает у пользователя путь к папке и сохраняет его в переменную folder.</h4>
<h4 align>5)set "report=report.txt" - устанавливает имя файла отчета в переменную report.</h4>
<h4 align>6)if not exist "%folder%"  - проверяет, существует ли указанная папка.</h4>
<h4 align>7)echo Данной папки нет! - если папки не существует, выводит сообщение об ошибке.</h4>
<h4 align>8)exit /b - завершает выполнение скрипта.</h4>
<h4 align>9)for /r "%folder%" %%f in (*) do ( - проходит рекурсивно по всем файлам в указанной папке и ее подпапках.</h4>
<h4 align>10)set "ext=%%~xf" - сохраняет расширение текущего файла в переменную ext.</h4>
<h4 align>11)set /a "count[!ext!]+=1" - увеличивает счетчик файлов с данным расширением в массиве count.</h4>
<h4 align>12)(for /f "tokens=2,3 delims=[]=" %%a in ('set count[') do ( - проходит по всем элементам массива count и выводит их значения в формате "расширение - количество".</h4>
<h4 align>13)| sort /r > "%report%" - сортирует отчет по убыванию количества файлов каждого типа и записывает его в файл report.txt.</h4>
<h4 align>14)endlocal - завершает локальную область видимости переменных.</h4>
<h4 align>15)pause - останавливает выполнение скрипта до нажатия пользователем любой клавиши.</h4>
<h1 align="center">Пример запуска и выполнения программы ( .sh )</h1>
1) <h3 align>Создаем папку с файлами с различными расширениями</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/3.png"/>
2) <h3 align>Запускаем sh файл</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(8).png"/>
3) <h3 align>Вводим путь к папке</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/photo_2023-10-19_09-34-09.jpg"/>
4) <h3 align>Создается report файл с различными расширениями</h3>
  <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/3.png"/>
<h1 align="center">Описание алгоритма ( .sh )</h1>
<h3 align>1) В этой переменной содержится абсолюный путь к папке с текстовыми файлами.<a href="https://daniilshat.ru/" target="_blank"> - folder</a> 
<h3 align>2) Этой переменной присваивается значение "report.txt"<a href="https://daniilshat.ru/" target="_blank"> - report</a> 
<h3 align>3) В эту переменную сохраняется расширение файла, а также принимает значения ключей массива count<a href="https://daniilshat.ru/" target="_blank"> - ext</a> 
 <h1 align="center">Последовательность действий:<h1 align="center">
 <img src="https://github.com/iis-32170x/RPIIS/blob/%D0%9F%D1%83%D1%88%D0%BA%D0%BE_%D0%9C/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%20(1).png"/>
<h4 align>1)#!/bin/bash - указывает на то, что используется интерпретатор bash.</h4>
<h4 align>2)read -p "Введите путь к папке: " folder - выводит на экран сообщение "Введите путь к папке:" и принимает ввод от пользователя, сохраняя его в переменную folder.
</h4>
<h4 align>3)report="report.txt" - создает переменную report и присваивает ей значение "report.txt".
</h4>
<h4 align>4)
if [ ! -d "$folder" ]; then - проверяет, существует ли папка, указанная пользователем. Если папки не существует, выводит сообщение "Данной папки нет!" и завершает выполнение скрипта с кодом ошибки 1.</h4>
<h4 align>5)declare -A count - создает ассоциативный массив count.</h4>
<h4 align>6)while IFS= read -r -d '' file; do - начинает цикл, в котором переменная file будет принимать значения файлов, найденных в папке, указанной пользователем.
</h4>
<h4 align>7)ext="${file##*.}" - определяет расширение файла и сохраняет его в переменную ext.</h4>
<h4 align>8)((count[$ext]++)) - увеличивает значение элемента массива count с ключом ext на 1.</h4>
<h4 align>9)done < <(find "$folder" -type f -print0) - заканчивает цикл и использует команду find для поиска файлов в папке, указанной пользователем. Ключ -type f означает поиск только файлов, а ключ -print0 разделяет найденные файлы символом NULL, чтобы избежать проблем с пробелами и другими специальными символами в именах файлов.</h4>
<h4 align>10)for ext in "${!count[@]}"; do - начинает цикл, в котором переменная ext будет принимать значения ключей массива count.</h4>
<h4 align>11)printf "%s - %d\n" "$ext" "${count[$ext]}" - выводит на экран расширение файла и количество файлов с этим расширением.
</h4>
<h4 align>12)done | sort -rn > "$report" - заканчивает цикл, сортирует вывод по убыванию количества файлов и сохраняет его в файл report.
</h4>
<h4 align>13)echo "Отчет сохранен в файл $report." - выводит на экран сообщение "Отчет сохранен в файл report.txt.".</h4>
<h1 align="center"># Итог</h1>
<h3 align>В ходе работы были получены и приобретены навыки работы в командной строке **Windows** и **Linux**.А так же команды для работы в **GitHub**.</h3>
[![trophy](https://github-profile-trophy.vercel.app/?MaXuMeRum=ryo-ma)](https://github.com/ryo-ma/github-profile-trophy)
[![Readme Quotes](https://quotes-github-readme.vercel.app/api?type=horizontal&theme=dark)](https://github.com/piyushsuthar/github-readme-quotes)
