@chcp 65001
@echo off
set /p pyt="Введите путь к папке: "
set /p imya="Введите имя: "
DIR %pyt%\*.txt /b /O:N > c:\test\%imya%.txt 
echo "New file has been created"
pause