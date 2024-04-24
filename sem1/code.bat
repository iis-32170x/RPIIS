@echo off
chcp 65001

setlocal enabledelayedexpansion
set dp=%~dp0
set p=%1
if not exist %dp%%p% echo папка не существует
set "InputLetter="

for /r %dp%%p% %%f in (*.txt) do (
    set /p InputLetter="Удалить файл %%f Y/n (Для предварительного просмотра нажмите O) "
    echo InputLetter = !InputLetter!
    if not exist %%f EXIT /B
        if "!InputLetter!" == "Y" (
        echo файл будет удалён
        del "%%f"
    )

    if "!InputLetter!" == "n" (
        echo файл не будет удалён
    )

    if "!InputLetter!" == "O" (
        echo Содержимое файла:
        type "%%f"
        echo+
        set "InputLetter="
        call :function "%%f"
    )
    if not "!InputLetter!" == "Y" (
        if not "!InputLetter!" == "n" (
            if not "!InputLetter!" == "O" (
                set "InputLetter="
                call :function "%%f"
            )
        )
    )
set "InputLetter="
)
endlocal

:function
if not exist %~1 EXIT /B
set /p InputLetter="Удалить файл %~1 Y/n (Для предварительного просмотра нажмите O) "
echo InputLetter = !InputLetter!

if "!InputLetter!" == "Y" (
    echo файл будет удалён
    del "%~1"
)

if "!InputLetter!" == "n" (
    echo файл не будет удалён
)
if "!InputLetter!" == "O" (
    echo Содержимое файла:
    type "%~1"
    echo+
    set "InputLetter="
    call :function "%~1"
)
if not "!InputLetter!" == "Y" (
    if not "!InputLetter!" == "n" (
        if not "!InputLetter!" == "O" (
            set "InputLetter="
            call :function "%~1"
        )
    )
)

EXIT /B 0

pause