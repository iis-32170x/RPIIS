chcp 65001 > nul

dir /s /b /ad %1

IF NOT EXIST %1 (
echo Данной папки нет
exit /b 0
) ELSE IF EXIST %1 (
echo.
echo Скрытые файлы .txt найдены:
echo.
for /f %%A in ('dir /s /b /a:h %1\*.txt ^| find /c /v ""') do set fileCount=%%A
echo Количество найденных файлов: %fileCount%
)

pause
