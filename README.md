# Лабораторная работа №1

## Условие задания (вариант 43)

![image](https://github.com/iis-32170x/RPIIS/assets/145385006/ff268d87-240d-43ef-8cf1-3c2237c5eeb0)


---

Bat-файл

### Код программы

```bash
    	@echo off
SetLocal EnableExtensions EnableDelayedExpansion
@chcp 65001>nul
set curmon=%date:~3,2%
set curyear=%date:~6,4%
set /a mins=%time:~3,2%
set /a hrs=%time:~0,2%
set /a val=%mins%+60*%hrs%
echo val=%val%
set h=2
set Temporary=Temp.Tmp
Set find=123
Set replace=321
set /p path_="Enter: "
cd %path_%
pause
echo.>%Temporary%

for %%a in (*.txt) do (
	set File=%%~fa
    	for /f "tokens=1* delims=," %%a in ('wmic datafile where "name='!File:\=\\!'" get 'CreationDate' /format:csv ^| find /i "%ComputerName%"') do (set CreationDate=%%b)
    	set cYear=!CreationDate:~0,4!
    	set cMonth=!CreationDate:~4,2!
    	set cDay=!CreationDate:~6,2!
   	set cHour=!CreationDate:~8,2!
    	set cMinutes=!CreationDate:~10,2!
   	set TimeStamp=!cDay!.!cMonth!.!cYear! !cHour!:!cMinutes!
    	Echo %%a !TimeStamp! !cMinutes!
	if %curmon%==!cMonth! (
		
		if %curyear%==!cYear! (
			
 			set h=1
			echo !h!
			pause
		)
	)
		
	if !h!==1 (
		
		for /f "tokens=1-5 delims=.: " %%j in ("%%~ta") do (
  			set mydate=%%l.%%k.%%j
  			set mytime=%%m-%%n
			set /a fval=%%m*60+%%n+2
			if %val% GEQ !fval! (
				set /a h=3

			)
			echo !h!
			
 		)
	ECHO !mytime!
	echo !fval!
)
	if !h!==3 (
		
		
		
		::проверка для изменения и создания
		for /F "UseBackQ delims=" %%n in (%%a) do ( 

			

			set "LINE=%%n"
			echo=!LINE:%find%=%replace%!>"%Temporary%"
		)
	
		echo.>%%a
	
		for /F "UseBackQ delims=" %%m in ("%Temporary%") do ( 
			set "LINE=%%m"
			echo=!LINE!>>%%a
		)
	)
	echo файл %%a был обработан
	pause
set /a h=2	
)

del %Temporary%
pause
```

### Пример запуска

1. Запустите командную строку (cmd.exe) на вашем компьютере.
2. Перейдите в каталог, содержащий ваш скрипт.
3. Запустите скрипт, следуя инструкциям в командной строке.

![image](https://github.com/iis-32170x/RPIIS/assets/145385006/98689af1-aba2-4d1d-9cbb-c254161cd23c)





### Описание аргументов

- `@chcp 65001>nul`: Эта команда устанавливает кодировку консоли на UTF-8, что позволяет работать с кириллицей.

- `set /p path_="Enter: "`: Запрашивает у пользователя ввод абсолютного пути к папке, в которой нужно удалить файлы .txt.

- `for %%a in (*.txt) do (`: Начинает цикл для поиска файлов .txt в указанной папке.

- `Echo %%a !TimeStamp! !cMinutes!`: Выводит название файла, и дату создания.

- `if %curmon%==!cMonth! ( if %curyear%==!cYear! (`: Сравниваем дату создания, чтобы "быть" в текущем месяце
- `if %val% GEQ !fval! (`: Сравниваем системное время и (время изменения файла + 2 минуты)

- `echo=!LINE:%find%=%replace%!>"%Temporary%"`: Находим и перезаписываем измененную строку в временный файл, из которого уже измененную строку возвращаем обратно в файл, а сам временный файл в конце удаляем.

### Примеры выполнения программы:
#### До выполнения программы
![image](https://github.com/iis-32170x/RPIIS/assets/145385006/6c48b562-65eb-4938-b5e8-12fca6e71070)

#### После выполнения программы
![image](https://github.com/iis-32170x/RPIIS/assets/145385006/653122d8-2e7c-4bae-b5f6-c272ee9146af)


---

Shell
### Код программы

```bash
read -rp "Enter a path:" path
read -p "Input any string: " string
cd $path

mesyac=$(date +"%m")
minutasus=$(date +"%M")
chassus=$(date +"%H")
symsus=$(((chassus*60)+($minutasus)+2))
echo $symsus

IZM=2
for file in *; do 

    if [ -f "$file" ]; then 
		month=$(stat -c %w $file)
		arrmonth=(${month//-/ })
		if [ $mesyac -eq ${arrmonth[1]} ]; then
		minuta=$(stat -c %y $file)
		
		arrminuta=(${minuta//:**:/ })
		chas=(${arrminuta[1]})
		
		arrminuta=(${minuta//:/ })
		minuta=(${arrminuta[2]})

		sym=$(((chas*60)+($minuta)))
		echo $sym
		 	if [ $symsus -gt $sym ]; then
			# сюда не заходит
			sed -i 's/'$string'/321/g' $file 
			fi
			
		fi
    fi 
done


sleep 15
```
### Пример запуска
1. Откройте терминал, соответствующий вашей операционной системе (например, терминал Linux, macOS, Git Bash на Windows).
2. Перейдите в каталог, содержащий ваш скрипт.
3. Запустите скрипт, следуя инструкциям в командной строке.

![image](https://github.com/iis-32170x/RPIIS/assets/145385006/919e2a3f-db81-4beb-b39e-2d3f85e97bc6)


### Описание аргументов

- `#!/bin/bash`: Эта строка обозначает, что это скрипт, который будет выполняться в оболочке Bash.
- `echo 'Введите абсолютный путь:`: Эта строка выводит на экран текст "Введите абсолютный путь: ".
- `read var1`: Эта строка читает ввод пользователя и сохраняет его в переменной var1.
- `if [ -e $var1 ]`: Начало условной конструкции. Проверяется существование пути, указанного в переменной var1. Если путь существует, выполняется следующий блок команд.
- `touch log.txt`: Создает пустой файл с именем "log.txt" в текущей директории (где был запущен скрипт).
- `cd $var1`: Меняет текущую рабочую директорию на путь, указанный в переменной var1. Теперь скрипт будет выполнять операции в этой директории.
- `find -type f -name "*.doc" | sort -r --output=log.txt`: Эта строка команд ищет все файлы с расширением ".doc" в текущей директории и её поддиректориях с помощью find, затем сортирует их имена в обратном порядке с помощью sort, и результат сохраняет в файле "log.txt".
- `rm $var1/*.doc`: Эта строка удаляет все файлы с расширением ".doc" в указанной директории (путь к которой хранится в переменной var1).
- `else`: Если проверка существования пути (if [ -e $var1 ]) вернет "ложь", то выполнится следующий блок команд.
- `echo 'Данная папка не существует`: Эта строка выводит сообщение "Данная папка не существует", если путь, указанный пользователем, не существует.
- `fi`:  Завершение условной конструкции.
- `$SHELL`: Эта строка запускает текущую оболочку скрипта. Она может использоваться, чтобы перезапустить текущую оболочку после выполнения скрипта.

### Примеры выполнения программы:
#### До выполнения программы
![image](https://github.com/iis-32170x/RPIIS/assets/145385006/0d7dd862-f194-4908-89d3-db5cabe11f01)


#### После выполнения программы:
![image](https://github.com/iis-32170x/RPIIS/assets/145385006/2f3bd099-a3ab-4aa1-88d6-04d903cddec2)

