# ПОИИС
<p align="center"><a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=900&size=35&pause=1000&color=5CF7F1&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&height=100&lines=%D0%9C%D0%BE%D1%8F+%D0%BB%D0%B0%D0%B1%D0%BE%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%BD%D0%B0%D1%8F+%E2%84%961" alt="Typing SVG" /></a></p>

---

<h3 align="center">~Условие Варианта 19~</h3>

---

**Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит абсолютный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней и ее подкаталогах посчитать количество файлов с различными расширениями. Вывести в файл report.txt отчет в виде: doc - 15 txt - 10 exe - 1. В отчет писать в порядке убывания**

---

<h3 align="center">~Bat~</h3>

---

```
@echo off
chcp 65001

set sumtxt=0
set sumdoc=0
set sumexe=0
set /p name=enter file paht:

if exist %name% (
	echo Такое есть
	goto 1
) else (
	echo такого нет
)

goto 2
:1
For /r "%name%" %%i In (*.txt) Do Set /a sumtxt+=1
For /r "%name%" %%i In (*.doc) Do Set /a sumdoc+=1
For /r "%name%" %%i In (*.exe) Do Set /a sumexe+=1

if %sumtxt% GEQ %sumdoc% if %sumdoc% GEQ %sumexe% echo txt - %sumtxt% doc - %sumdoc% exe - %sumexe% >> C:\Users\Vlad\pioivis\laba1\report.txt
if %sumtxt% GEQ %sumexe% if %sumexe% GEQ %sumdoc% echo txt - %sumtxt% exe - %sumexe% doc - %sumdoc% >> C:\Users\Vlad\pioivis\laba1\report.txt

if %sumdoc% GEQ %sumtxt% if %sumtxt% GEQ %sumexe% echo doc - %sumdoc% txt - %sumtxt% exe - %sumexe% >> C:\Users\Vlad\pioivis\laba1\report.txt
if %sumdoc% GEQ %sumexe% if %sumexe% GEQ %sumtxt% echo doc - %sumdoc% exe - %sumexe% txt - %sumtxt% >> C:\Users\Vlad\pioivis\laba1\report.txt

if %sumexe% GEQ %sumtxt% if %sumtxt% GEQ %sumdoc% echo exe - %sumexe% txt - %sumtxt% doc - %sumdoc% >> C:\Users\Vlad\pioivis\laba1\report.txt
if %sumexe% GEQ %sumdoc% if %sumdoc% GEQ %sumtxt% echo exe - %sumexe% doc - %sumdoc% txt - %sumtxt% >> C:\Users\Vlad\pioivis\laba1\report.txt
:2
pause
```

---

<h3>~Пример выполнения кода~</h3>

---

<h4>Запускаем нашу программу </h4>

![Запуск batника](/imgs/cmd/startcmd.png)

<h4>Вводим корректный путь к файлу </h4>

![Выполнение программы](/imgs/cmd/cmdunerror.png)

<p>Программа выводит "Такое есть"(что говорит нам о том, что введенная папка существует) и завершает свое выполнение.</p>

<h4>Итог </h4>

![Содержимое файла report.txt](/imgs/cmd/result.png)

<p>В файле report.txt видим вывод колличества файлов с различными расширениями в порядке убывания.</p>

<h4>Проверяем </h4>

![Содержимое введенной папки](/imgs/cmd/papkawithfiles.png)

<p>Если подсчитать количество файлов с разными расширениями, то мы можем удостовериться, что программа сработала правильно.</p>

<h4>Вводим НЕкорректный путь к файлу </h4>

![Выполнение программы при некорректном вводе](/imgs/cmd/cmderror.png)

<p>Программа выводит "Такого нет", значит введенной папки не существует.</p>

---
<h3>~Переменные~</h3>

---

<p>
name -- переменная в которую записывается путь к файлу  </br>
sumtxt -- переменная в которую записывается количество файлов с расширением .txt </br>
sumdoc -- переменная в которую записывается количество файлов с расширением .doc </br>
sumexe  -- переменная в которую записывается количество файлов с расширением .exe </br>
</p>

---
<h3 align="center">~Sh~</h3>

---


```
#!/bin/bash

read -p "Enter file path: " name

if [ -e "$name" ]
then
  echo "Такое есть"
else
  echo "такого нет"
  exit 0
fi

sumtxt=0
sumdoc=0
sumexe=0

for i in $(find "$name" -name '*.txt'); do
   sumtxt=$((sumtxt+1))
done
for i in $(find "$name" -name '*.doc'); do
   sumdoc=$((sumdoc+1))
done
for i in $(find "$name" -name '*.exe'); do
   sumexe=$((sumexe+1))
done

if [ $sumtxt -ge $sumdoc ] && [ $sumdoc -ge $sumexe ]
then
   echo "txt - $sumtxt doc - $sumdoc exe - $sumexe" >> /home/vboxuser/Desktop/laba1/report.txt
elif [ $sumtxt -ge $sumexe ] && [ $sumexe -ge $sumdoc ]
then
   echo "txt - $sumtxt exe - $sumexe doc - $sumdoc" >> /home/vboxuser/Desktop/laba1/report.txt
fi

if [ $sumdoc -ge $sumtxt ] && [ $sumtxt -ge $sumexe ]
then
   echo "doc - $sumdoc txt - $sumtxt exe - $sumexe" >> /home/vboxuser/Desktop/laba1/report.txt
elif [ $sumdoc -ge $sumexe ] && [ $sumexe -ge $sumtxt ]
then
   echo "doc - $sumdoc exe - $sumexe txt - $sumtxt" >> /home/vboxuser/Desktop/laba1/report.txt
fi

if [ $sumexe -ge $sumtxt ] && [ $sumtxt -ge $sumdoc ]
then
   echo "exe - $sumexe txt - $sumtxt doc - $sumdoc" >> /home/vboxuser/Desktop/laba1/report.txt
elif [ $sumexe -ge $sumdoc ] && [ $sumdoc -ge $sumtxt ]
then
   echo "exe - $sumexe doc - $sumdoc txt - $sumtxt" >> /home/vboxuser/Desktop/laba1/report.txt
fi

read -p "Press [Enter] key to continue."
```

---

<h3>~Пример выполнения кода~</h3>

---

<h4>Запускаем нашу программу </h4>

![Запуск shника](/imgs/sh/start.png)

<h4>Вводим корректный путь к файлу </h4>

![Выполнение программы](/imgs/sh/luck.png)

<p>Программа выводит "Такое есть"(что говорит нам о том, что введенная папка существует) и завершает свое выполнение.</p>

<h4>Итог </h4>

![Содержимое файла report.txt](/imgs/sh/reportsh.png)

<p>В файле report.txt видим вывод колличества файлов с различными расширениями в порядке убывания.</p>

<h4>Проверяем </h4>

![Содержимое введенной папки](/imgs/sh/papka.png)

<p>Если подсчитать количество файлов с разными расширениями, то мы можем удостовериться, что программа сработала правильно.</p>

<h4>Вводим НЕкорректный путь к файлу </h4>

![Выполнение программы при некорректном вводе](/imgs/sh/unluck.png)

<p>Программа выводит "Такого нет", значит введенной папки не существует.</p>

---
<h3>~Переменные~</h3>

---

<p>
name -- переменная в которую записывается путь к файлу </br>
sumtxt -- переменная в которую записывается количество файлов с расширением .txt  </br>
sumdoc -- переменная в которую записывается количество файлов с расширением .doc  </br>
sumexe  -- переменная в которую записывается количество файлов с расширением .exe  </br>
</p>

---
<h3>~Вывод~</h3>

---

<p>
Научился создавать и работать файлы bat и sh.
</p>
