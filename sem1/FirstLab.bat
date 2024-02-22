@echo off
@echo First argument is: %1
setlocal ENABLEDELAYEDEXPANSION
rem Команда SETLOCAL используется для временного изменения значений переменных среды в командных файлах Windows. 
rem ENABLEDELAYEDEXPANSION / DISABLEDELAYEDEXPANSION включает или отключает отложенное расширение переменной среды.
set /a c=%1%%2
for /f "tokens=2 delims==" %%G in ('wmic OS Get localdatetime /value') do set "datetime=%%G"
set "timestamp=%datetime:~8,2%_%datetime:~10,2%_%datetime:~12,2%"
if "%c%"=="0" (
	FOR /L %%A IN (1,1,%1) DO (
  mkdir dir
  cd dir
  echo %timestamp%>> output.txt
)
) else (
	FOR /L %%A IN (1,1,%1) DO (
		set /a randomNum=!random!%%15 + 1
 		echo !randomNum!>> output.txt
)
)