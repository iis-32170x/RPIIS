setlocal enabledelayedexpansion 
set "inputFile=input.txt"
set "lastNameFile=surname_names.txt"
set "firstNameFile=first_names.txt"
set "middleNameFile=middle_names.txt"
type nul > "%lastNameFile%"
type nul > "%firstNameFile%"
type nul > "%middleNameFile%"
echo Струнец Дмитрий Петрович >> "%inputFile%" 
echo Зинович Максим Кактебятам>> "%inputFile%"
echo Позняк Анна Хзэшовна>> "%inputFile%"
sort "%inputFile%" /o "%inputFile%"  
for /f "delims=" %%a in (%inputFile%) do (     
    for /f "tokens=1,2,3" %%b in ("%%a") do (    
        echo %%b>> "%lastNameFile%"
        echo %%c>> "%firstNameFile%"
        echo %%d>> "%middleNameFile%"
    )
)
