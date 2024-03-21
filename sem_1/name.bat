@echo off
setlocal enabledelayedexpansion

if "%~2"=="" (
    echo Usage: %0 ^<directory_path^> ^<letter^>
    exit /b 1
)

set "directory_path=%~1"
set "letter=%~2"

if not exist "%directory_path%" (
    echo This folder does not exist
    exit /b 1
)

for /r "%directory_path%" %%f in (*.txt) do (
    findstr /i "\<[a-zA-Z]*%letter%\>" "%%f" >> result.txt
)

echo Words ending with '%letter%' in '*.txt' files have been saved in 'result.txt'

