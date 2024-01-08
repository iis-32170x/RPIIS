setlocal EnableDelayedExpansion
@echo off
chcp 65001
set /p amountOfLetters=Enter amount of letters 
set /p path=Enter path 
set pastStr=
echo. > "result.txt"
cd "%path%"



for %%f in (*.txt) do (
    call :afunc %%f
)
pause


:afunc 
for /f "tokens=*" %%a in (%1) do (
    set curStr=%%a
    for %%i in (%%a) do (
        call :cfunc %%i
    )
)
exit /b


:cfunc
set "word=%1"
set /a "wordLength=0"
:loop

set "word=!word:~1!"
rem echo %word%
set /a wordLength=!wordLength!+1
rem echo %wordLength%


if DEFINED word goto loop 
set "word=%1"


call :ffunc !wordLength!

exit /b


:ffunc
if !amountOfLetters! EQU %1 (
    if !curStr! NEQ !pastStr! (
        echo %curStr% >> "folder with scripts\result.txt"
        set pastStr=%curStr%

    ) else (
        exit /b
    )
)
exit /b
