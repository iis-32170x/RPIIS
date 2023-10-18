@echo off
set /p n=Enter number 
set /a s= n %% 2
for /f %%a in ('wmic path win32_LocalTime get * /value') do >nul set "%%a"
if %n% lss 0 echo %Month%.%Day%.%Year% 
 if %n% gtr 0  if %s%  == 0  echo %Month%/%Day%/%Year% 
if %n% gtr 0  if %s% == 1  echo %Month% 
pause
