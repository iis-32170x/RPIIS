# Лабораторная работа №1
## Условие задания (вариант 58)

Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит путь к каталогу, два числа (как параметры пакетного файла) Найти все файлы в указанном каталоге, размером в диапазоне указанных чисел в параметрах (в байтах), создать новый файл, в котором будут содержаться имена этих файлов и даты их создания, отсортированные в алфавитном порядке.

---
![](https://img.shields.io/badge/Файл-bat-blue)

### Код программы

~~~ bash
echo off
setlocal enableextensions
chcp 65001

set /P path="Enter the path to a directory: "
if not exist "%path%" (
     echo this directory does not exist.
     exit /B 1
)
set /P num1="Enter the first smaller number: " 
set /P num2="Enter the second bigger number: "

if /I "%num1%" GEQ "%num2%" (
 set big=%num1%
 set sml=%num2%
) 
if /I "%num2%" GEQ "%num1%" (
 set big=%num2%
 set sml=%num1%
)
set minb=%sml%
set maxb=%big%

echo. 2> "output.txt"
FOR /f "delims=" %%I IN ('dir %path% /A:-D /B /O:N') DO (
 if %%~zI GEQ %minb% if %%~zI LEQ %maxb% echo %%I %%~tI >> "output.txt"
)
~~~

### Пример запуска

1. Запустите командную строку (cmd.exe) на вашем компьютере.
2. Перейдите в каталог, содержащий ваш скрипт.
3. Запустите скрипт, следуя инструкциям в командной строке.

![Снимок](https://github.com/iis-32170x/RPIIS/assets/148317821/96799872-82df-4999-a872-df4a633daf14)



### Описание аргументов

- `chcp 65001`: Эта команда устанавливает кодировку консоли на UTF-8, что позволяет работать с кириллицей.

- `set /P path="Enter the path to a directory: "`: Запрашивает у пользователя ввод пути к директории, в которой нужно искать файлы нужного размера.

- `if not exist %path%`: Проверяет существование указанной папки. Если директории не существует, выводит сообщение "this directory does not exist" и завершает выполнение скрипта.

- `set /P num1="Enter the first smaller number: "`: Запрашивает у пользователя первое число для определения файлов нужного размера.

- `set /P num2="Enter the second bigger number: "`: Запрашивает у пользователя второе число для определения файлов нужного размера.

- `if /I "%num1%" GEQ "%num2%"`: Сравнивает значения чисел. Если первое оказалось больше или равно второму, присваивает значение num1 пременной big, а переменной sml- значение num2.

- `if /I "%num2%" GEQ "%num1%"`: Сравнивает значения чисел. Если второе оказалось больше или равно первому, присваивает значение num1 пременной sml, а переменной big- значение num2.

- `set minb=%sml% set maxb=%big%`: Присваивает значение big пременной maxb, а переменной minb- значение sml. Нужно для повышения читабельности кода.

- `echo. 2> "output.txt"`: Создает новый файл output.txt, содержащий в себе вывод потока ошибок, т.е. являющийся полностью пустым текстовым файлом.

- `FOR /f "delims=" %%I IN ('dir %path% /A:-D /B /O:N') DO`: Начинает цикл отбора нужных файлов.
 
- `if %%~zI GEQ %minb% if %%~zI LEQ %maxb% echo %%I %%~tI >> "output.txt"`: При нахождении файла размером больше или равным minb и меньше или равным maxb добавляет название найденного файла и дату его создания в текстовый файл output.txt  

### Примеры выполнения программы:
#### До выполнения программы

![Снимок2](https://github.com/iis-32170x/RPIIS/assets/148317821/37eeb092-71ab-4d66-ba26-e2937c892ea3)

#### После выполнения программы
Размеры файлов:
- gorisont - 597 байт
- task - 610 байт
- многострадальныйКод - 608 байт

![Снимок3](https://github.com/iis-32170x/RPIIS/assets/148317821/9fb74ce1-9d82-424b-90a5-f87cca9cd586)

---

![](https://img.shields.io/badge/Файл-sh-blue)

### Код программы

~~~ shell
read -rp "Enter the path to a directory: " directory
read -p "Enter first positive smaller number: " num1
read -p "Enter second positive bigger number: " num2

if [[ -e result.txt ]]; then
  rm result.txt
fi

files=$(find "$directory" -type f -size +"$num1"c -size -"$num2"c)

touch result.txt

for file in $files
do
  echo "$(basename $file) $(date -r $file +"%F %T")" >> result.txt  
done

echo "$(sort result.txt)" > result.txt
~~~

### Пример запуска
1. Откройте терминал, соответствующий вашей операционной системе (например, терминал Linux, macOS, Git Bash на Windows).
2. Перейдите в каталог, содержащий ваш скрипт.
3. Запустите скрипт, следуя инструкциям в командной строке.

![111](https://github.com/iis-32170x/RPIIS/assets/148317821/e94de8a5-b972-4d67-9ba4-abdcdfb624e8)

### Описание аргументов

- `read -rp "Enter the path to a directory: " directory`: Запрашивает у пользователя ввести путь в нужную директорию и сохраняет ввод в переменную directory.
- `read -p "Enter first positive smaller number: " num1`: Запрашивает у пользователя ввести первое меньшее число и сохраняет ввод в переменную num1.
- `read -p "Enter second positive bigger number: " num2`: Запрашивает у пользователя ввести второе большее число и сохраняет ввод в переменную num2.
- `if [[ -e result.txt ]]`: Проверяет, существует ли уже файл result.txt
- `then rm result.txt`: Удаляет файл result.txt при его наличии.
- `fi`:  Завершение условной конструкции.
- `files=$(find "$directory" -type f -size +"$num1"c -size -"$num2"c)`: Осуществляет поиск файлов подходящего размера (больше первого и меньше второго чисел) в введенной директории.
- `touch result.txt`: Создает пустой файл с именем result.txt в текущей директории (где был запущен скрипт).
- `for file in $files do echo "$(basename $file) $(date -r $file +"%F %T")" >> result.txt done`: Запускает цикл, выписывающий поочередно имена и даты создания отобранных подходящих файлов в текстовый файл result.txt, который прерывается, когда кончаются подходящие файлы.
- `echo "$(sort result.txt)" > result.txt`: Сортирует файл result.txt в алфавитном порядке.

### Примеры выполнения программы:
#### До выполнения программы

![211](https://github.com/iis-32170x/RPIIS/assets/148317821/d2b16a5c-a4bf-438a-b2de-3648a987ac85)

#### После выполнения программы
Размеры файлов:
- hello - 5344 байт
- rusl - 430 байт
- неоткрывайэтонетотшельник - 414 байт
- щлфн - 167 байт

Вводятся числа 100 и 1000

![311](https://github.com/iis-32170x/RPIIS/assets/148317821/b66d30f9-6d72-4172-a2bf-74871db7c310)

---
