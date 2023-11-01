setlocal enabledelayedexpansion

set /A "X=%~1"
set "N=%~2"
set "directory=%~3"
set "q=0" 

 
set /A number=0
for /R "%directory%" %%I in (*.*) do (
    set /A number+=1
)

if !number! geq %N% (
    goto :out
) else (
    goto :end
)

:out
dir "%directory%" /b /on
for /R "%directory%" %%E in (*.*) do (
    set "file=%%E"
    if !q! LSS %N% (
        set /A "q+=1"
        del /Q "!file!"
        goto :out
    ) else (
        goto :w
    )
)

:w
set "q=0"
set /A number=0
for /R "%directory%" %%I in (*.*) do (
    set /A number+=1
)

if !number! geq %N% (
    timeout /T %X%
    goto :out
) else (
    goto :end
)

:end
echo end
