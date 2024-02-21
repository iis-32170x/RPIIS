@echo OFF
@chcp 65001
echo Введите путь к первой папке.
set /p x=
if not exist %x% (
echo Такой папки не существует.
pause
exit /b 1
)
echo Введите путь ко второй папке.
set /p y=
if not exist %y% (
echo Такой папки не существует.
pause
exit /b 1
)
robocopy %y% %x% /MIR
