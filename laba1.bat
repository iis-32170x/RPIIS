@echo off
set /p input="Введите путь к папке: "
if exist "%input%" (
	echo да есть
)	else (
	echo такой папки нет
	timeout 3
	exit
)
if exist "%input%\files" (
	echo все четко
)	else (
	mkdir "%input%/files"
)

for /r "%input%" %%f in (*) do (
	if %%~zf GTR 1048576 (
	move "%%f" "%input%/files"
	echo перемещён файл "%%f"
)
)
pause
