@echo off
setlocal enabledelayedexpansion

set "folder1=%1%"
set "minFile="
set "minSize="

for %%F in ("%folder1%\*") do (
    if not defined minFile (
        set "minFile=%%~nxF"
        set "minSize=%%~zF"
    ) else (
        if %%~zF lss !minSize! (
            set "minFile=%%~nxF"
            set "minSize=%%~zF"
        )
    )
)

echo name min: %minFile%, size min: %minSize%

set "folder2=%2%"

echo. > result.txt

for %%F in ("%folder2%\*") do (
    echo name: %%~nxF, size: %%~zF
    if %minSize% LSS %%~zF (
        echo %minFile% ^< %%~nxF >> result.txt
    ) else if %minSize% EQU %%~zF (
        echo %minFile% ^= %%~nxF >> result.txt
    ) else (
        echo %minFile% ^> %%~nxF >> result.txt
    )
)

move %folder1%\%minFile% %folder2%\%minFile%
