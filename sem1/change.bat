  
	setlocal EnableDelayedExpansion 
	set count=%1
	set folder_name=%2
	md "%folder_name%"  
	for /L %%i in (1,1,%count%) do (
		set "file_name=%%i"
		type nul > "%folder_name%\!file_name!.txt" 
		
		set /a "remainder=%%i %% 3" 
		
		if !remainder! == 0 echo Hello World > "%folder_name%\!file_name!.txt" 
	)
	endlocal
	