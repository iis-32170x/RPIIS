@echo off
setlocal EnableDelayedExpansion
chcp 65001
if "%1"=="" (echo Параметр не задан)
echo. >D:/labaPi1/result.txt
if not exist D:/labaPi1/%1 (echo Данной папки нет)
echo. >D:/labaPi1/result.txt
for /R D:/labaPi1/%1 %%t in (*temp*) do (
set fileName= %%t
set /A counter=0
for /F %%s in (!fileName!) do (
if !counter! lss 5 (
echo %%s >>D:/labaPi1/result.txt
set /A counter+=1
)
)
echo. >>D:/labaPi1/result.txt
)
endlocal