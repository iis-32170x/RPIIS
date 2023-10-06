@echo off
set /p input="Введите путь к папке: "

if not exist "%input%" (
	echo такой папки нет
	timeout 3
	exit
)

if not exist "%input%\files" mkdir "%input%\files"

for /r "%input%" %%f in (*) do (
	if %%~zf GTR 1048576 (
	move "%%f" "%input%/files"
	echo перемещён файл "%%f"
	)
)
pause
