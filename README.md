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
<h3 align="center">~Sh~</h3>
---
