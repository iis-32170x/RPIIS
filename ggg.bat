@echo off
chcp 65001
set /p ppk=Write path to your folder:
(for /f %%I in ('findstr /m "txt" %ppk%\*.*') do (
(dir /tc %%I > vremennii.txt)&(echo %%~nI)&(
	for /f "skip=5" %%k in (vremennii.txt) do (
		echo %%k) 
) 
) 
) > prome.txt
(for /f %%I in ('findstr /xv "1" prome.txt') do (echo %%I)) > vremennii.txt
del prome.txt
(for /f %%I in ('findstr /xv "0" vremennii.txt') do (echo %%I)) > result.txt
del vremennii.txt
pause