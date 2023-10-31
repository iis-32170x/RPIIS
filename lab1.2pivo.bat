@echo off
setlocal enabledelayedexpansion
chcp 65001 > nul
 
echo Введите абсолютный путь.
set /p mpath= 
set count=
set sum=

for /f %%a in ('type "%mpath%" ^| find /c "+"') do set "count=%%a"

echo Всего %count% знака(ов) "+"

set /a check=%count% %% 2
if %check% == 0 (
  set /a sum=%date:~0,1%+%date:~1,1%+%date:~3,1%+%date:~4,1%+%date:~6,1%+%date:~7,1%+%date:~8,1%+%date:~9,1%
  echo Сумма цифр: !sum!
) else (
  set /a multi=%date:~,1%*%date:~1,1%*%date:~3,1%*%date:~4,1%*%date:~6,1%*%date:~7,1%*%date:~8,1%*%date:~9,1%
  echo Произведение цифр: !multi!
)
  
endlocal
pause
