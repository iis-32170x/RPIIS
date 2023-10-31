    @echo off
    chcp 65001 > nul
    set /p d1=%1
    set /p d2=%2
 for /f "usebackq" %%S in (`find /c /v ""^<"%d1%"`) do (set /a NumStr1=%%S)

 for /f "usebackq" %%S in (`find /c /v ""^<"%d2%"`) do (set /a NumStr2=%%S)
set /a n1 = 0
set /a n2 = 0

    if %NumStr1% equ %NumStr2% ( echo Количество строк равное ) else (
     echo Количество строк разное

    for /f "usebackq delims=" %%i in ("%d1%") do (
     for %%j in (%%i) do (
      set /a n1+=1

     )
    )

    for /f "usebackq delims=" %%i in ("%d2%") do (
     for %%j in (%%i) do (
      set /a n2+=1

     )
    )
    if %n1% equ %n2% ( echo Количество слов равное )
    if not %n1% equ %n2% ( echo Количество слов разное )
)
timeout 7

