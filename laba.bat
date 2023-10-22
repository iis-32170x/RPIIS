@echo off
chcp 65001
set /a B=512000
set /p a="Введите путь папки:"
if not exist %a% (
echo Данной папки не существует
pause
) else (
setlocal EnableDelayedExpansion
set /a S=%B%
for /r %a% %%G in (*.txt) do (
    if %%~zG LSS !S! (
            set /a S=%%~zG
		)
	)
)
for /r %a% %%G in (*.txt) do (
	if %%~zG EQU %S%  (
	del /q %%G
	echo %%G удален
	)
)
pause