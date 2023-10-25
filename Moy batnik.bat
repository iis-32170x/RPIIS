@echo off
setlocal enabledelayedexpansion

:: Prover'te nalichie dvuh argumentov (kolichestvo fajlov i razmer pervogo fajla)
if "%~2"=="" (
    echo Trebuyutsya dva argumenta: kolichestvo fajlov i razmer pervogo fajla.
    goto :eof
)

:: Преобразование аргументов в числа
set /a "num_files=%~1"
set /a "file_size=%~2"

:: Создание пути к папке на рабочем столе
set "desktop_path=%USERPROFILE%\Desktop\GeneratedFiles"

:: Создание каталога для файлов на рабочем столе
mkdir "%desktop_path%"

:: Если размер файла меньше 10 байт, создаем только один файл
if !file_size! lss 10 (
    echo Generating file 1 with size !file_size!...
    fsutil file createnew "%desktop_path%\File1.txt" !file_size!
) else (
    :: Генерация файлов
    for /l %%i in (1,1,%num_files%) do (
        echo Generating file %%i...
        fsutil file createnew "%desktop_path%\File%%i.txt" !file_size!
        set /a "file_size=file_size-10"
    )
)

echo Fajly byli sozdany!