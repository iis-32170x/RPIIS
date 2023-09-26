   @echo off
setlocal enabledelayedexpansion
set /p size="input a size"
set txtpath=%C:\pppp\mmmd\file1.txt%
fsutil file createnew %txtpath% %size%
set /p text="input any symbols"
echo %text% > %txtpath%                                       
::set /a count=0
:start              
set text=%text:~1%
if not "%text%"=="" (
set /a count+=1
goto start
) else (
goto exit
)
:exit
set /a count += 1              
echo %count%   
set H=%time:~0,2%
set M=%time:~3,2%               
echo %H% 
echo %M%             
set /a sum1 =%M%+%H% 
set /a sum2 = %sum1%*%count% 
echo %sum2% 

set base_path=C:\pppp

call :create_folders %sum2% 1 "%base_path%"
pause
exit

:create_folders
if %2 gtr %1 goto :eof
set /a current_level=0
                
:loop
    set /a current_level+=1
    md %3\%current_level%
    set folder_path=%3\%current_level%"
    @echo > %folder_path%.%H%.%M%.txt  

    if %current_level% lss %1 (
    call :create_folders %1 %current_level% !folder_path!
    )
goto :eof               
pause                                                                                                             
                                                                                                                                                    
                  
