
![фото бат](https://github.com/iis-32170x/RPIIS/assets/148863144/2b6b8aa0-0e08-43dc-8c0a-a7b6f41ca770)
...c++
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
   for %%j IN (%%i) DO (
 call set var1=%%j     
call  :NumSymbols   !var1!
      set /A  a+=!NumSymbols! 
   )
)  
goto :EXIT
:NumSymbols  
SETLOCAL ENABLEDELAYEDEXPANSION
    call set var=%~1
    call set out=%~0
    call set /A num=0 
  
    :startvarcount
    if defined var (
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
...
