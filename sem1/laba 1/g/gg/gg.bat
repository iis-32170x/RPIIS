echo "baobab"
chcp 65001 > nul
setlocal
timeout /t -1

set "folder=%~2"
set "resultFile=results.txt"

if not exist "%folder%" (
    echo Данной папки нет.
    exit /b
)

echo Каталог, суммарный размер файлов, число просмотренных файлов > %resultFile%
call :processFolder "%folder%" %resultFile%

echo Результаты вычислений сохранены в файле %resultFile%
exit /b

:processFolder
set "folder=%~1"
set "resultFile=%~2"
set "totalSize=0"
set "fileCount=0"

for /r "%folder%" %%A in (*) do (
    set /a "totalSize+=%%~zA"
    set /a "fileCount+=1"
)

echo %folder%, %totalSize%, %fileCount% >> %resultFile%

for /d %%B in ("%folder%\*") do (
    call :processFolder "%%B" %resultFile%
)

exit /b
