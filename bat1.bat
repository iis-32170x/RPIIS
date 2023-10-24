echo "test"
set total_memory=0
for /f "skip=1" %%m in ('tasklist /nh') do (
    for /f "tokens=5" %%n in ("%%m") do (
        set /a total_memory+=%%n    )
)
set process_count=0
for /f %%p in ('tasklist /nh ^| find /c /v ""') do (
    set process_count=%%p)
echo Total Memory: %total_memory%
echo Process Count: %process_count%
pause
exit

