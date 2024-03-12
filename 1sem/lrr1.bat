setlocal enabledelayedexpansion
if not exist %1 goto error1
FOR /F %%i IN ('dir %1 /s /a-d /b /os') DO set f=%%i
call :size %f%
goto end
:size
echo размер файла= > result.txt
echo %~z1% >> result.txt
set /a count=0
set /a countlet=0
set /a ln=0
echo количество слов= >> result.txt
For /F "usebackq delims=" %%i In ("%1") Do (
    FOR %%j IN (%%i) DO (
     set /a count=!count!+1
     echo %%j>tempfile.txt
     for %%? IN (tempfile.txt) DO (
	 set /a countlet=!countlet!+%%~z?-2"
	)
    )
  )
echo %count% >> result.txt
echo количество букв= >> result.txt
echo %countlet% >> result.txt
echo количество строк= >> result.txt
find /c /v "" <"%~1" >> result.txt
goto end

:error1
echo Folder do not exist
goto end

:end
