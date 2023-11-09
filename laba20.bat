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