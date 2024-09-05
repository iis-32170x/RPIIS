@echo off

if "%~2"=="" (
    echo Usage: %~nx0 ^<directory_path^> ^<attribute^>
    exit /b 1
)

set "DIR=%~1"
set "ATTR=%~2"

if not exist "%DIR%" (
    echo Данной папки нет
    exit /b 1
)

dir /s /b "%DIR%" | for /f "delims=" %%A in ('findstr /m /i /c:%ATTR%') do echo %%A >> result.txt

echo Файлы с атрибутами %ATTR% сохранены в result.txt