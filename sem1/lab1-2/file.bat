@echo off 
chcp 1251
if not exist File1.txt type nul>File1.txt
if not exist File2.txt type nul>File2.txt
attrib -h File2.txt
if exist log.txt del log.txt
set /p f1=Введите путь к первому файлу: 
start %f1%
pause
set /p f2=Введите путь ко второму файлу: 
start %f2%
pause
type nul>log.txt
fc /c File1.txt File2.txt>>log.txt
set r=%ERRORLEVEL%
if %r%==0 (
    echo Файлы совпадают, их содержимое:
    echo Файлы совпали>>log.txt
    echo Выводим содержимое первого файла в консоль>>log.txt
    type File1.txt
) else (
    echo Файлы не совпали
    echo Файлы не совпали>>log.txt
    del File1.txt
    echo Удаляем первый файл>>log.txt
    attrib +h File2.txt 
    echo Делаем второй файл скрытым>>log.txt
)
pause
