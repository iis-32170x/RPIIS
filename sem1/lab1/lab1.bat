@Echo off
chcp 65001 >nul
set j=6
set n=0
set put=%1
if not exist %put% (
echo Данной папки нет
pause
exit
) else (
for /f %%i in ('dir /s /b /a-d %put%') do (
set /a n+=1
)
)
echo Количество файлов в данной папке и ее подпапках: %n%
del %n%.txt
pause
set ryad=%date:~0,1% %date:~1,1% %date:~3,1% %date:~4,1% %date:~6,1% %date:~7,1% %date:~8,1% %date:~9,1%
set u=0
for %%a in (%ryad%) do (
if %%a Gtr %j% (
echo Максимальная цифра сегодняшней даты: %%a & set /a u=%%a
) else (
set /a j+=-1
)
)
set /a m=(%n%*%u%)
echo %m% >> %n%.txt
pause