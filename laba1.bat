@echo off
setlocal enabledelayedexpansion
@chcp 65001

echo Введи путь к папке:
set /p pyt=

del !pyt!\result.txt

for /r "%pyt%" %%b in (*.txt) do (
	if not defined small ( set "small=%%b"
	) else (
		for %%N in ("%%b") do (
			for %%S in ("!small!") do (
			if %%~zN lss %%~zS set "small=%%b"
			)
      )
	)
)
set /a i = 0

for /f "usebackq delims=" %%p in (!small!) do (
	set /a i+=1
	set "s%i%=%%p"
	for /f %%m in ('">$ cmd/v/c echo.!s%i%!& echo $"') do (set/a l=%%~zm-2& del $)
	for /l %%j in (0,1,!l!) do (
		set  "s%i%=!s%i%:~0,%%j!!s%i%:~-1!!s%i%:~%%j,-1!"
		)
	set "s%i%=!s%i%:~0,-1!"
	set "a!i!=!s%i%!"
	)

for /l %%k in (!i!,-1,1) do (
	echo !a%%k!>>!pyt!\result.txt
)

endlocal
pause
