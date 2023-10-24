echo "test"
setlocal enabledelayedexpansion

set "totalMemory=0"
set "activeProcesses=0"

for /f "skip=3 tokens=2" %%a in ('tasklist /NH') do (
    set /a "totalMemory+=%%a"
    set /a "activeProcesses+=1"
)

echo Суммарный объем памяти: %totalMemory% КБ >> results.txt
echo Число активных процессов: %activeProcesses% >> results.txt
echo Вычисления завершены. Результаты записаны в файл results.txt.

exit 
