@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION
echo %1
set /A y=0
set /A a=0
IF EXIST %1 GOTO :PROCESS_FILE
echo "File not exist"
GOTO :EOF

:PROCESS_FILE
 echo  "work with file"
set ff=%DATE:~0,2%
if %ff% GEQ 10 GOTO :g
set ff=%DATE:~1,1%
:g
for /F "tokens=* delims=" %%i IN (%1) DO ( 
rem  цикл по строкам в файле
   for %%j IN (%%i) DO (
rem  цикл по словам в строке
 rem присваиваем значению вар значение слово 
 call set var1=%%j 
 rem вызов функции для подсчета символов в слове     
call  :NumSymbols   !var1!
      set /A  a+=!NumSymbols! 
   )
)  
goto :EXIT

rem  подсчет символов в одном слове
rem  результат возвращается в переменной с именем функции
:NumSymbols  
SETLOCAL ENABLEDELAYEDEXPANSION
    call set var=%~1
    call set out=%~0
    call set /A num=0 
  
    :startvarcount
    if defined var (
      rem  удаляем последний символ в слове
      set var=!var:~0,-1!

      set /A  num+=1
      goto startvarcount
    )

endlocal & set %out:~1%=%num%
exit /b

:EXIT

echo File %1 contains %a% symbols.
echo 
 


for /F "tokens=* delims=" %%i IN (%1) DO ( for %%j IN (%%i) DO set /A y+=1 )  
echo kolichestvo slov = %y%
echo day = %ff%
set /A m=%ff%*%a%*%y%
echo proizvedenie = %m%
echo %m% > result.txt
echo otvet zapisan v result.txt
  



 


