# BSUIR cmd-bash.
В рамках ЛР 1 необходимо создать файл с разрешением *bat.* и *sh.* в соответствии с заданным вариантом.
Цель данной лаборотоной работы - ознакомится с командными строками операционных систем *Windows* и *Linux*.

## Условие ЛР1 (39 вариант).
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит путь к каталогу и два числа, которые задают диапазон. В каталоге создать файлы (c названием PID), в случае, если из указанного диапазона совпадает PID какого-либо активного процесса в ОС. В каждый файл записать имя процесса и пользователя, который его использует

# Описание алгоритма, пример запуска и выполнения программы (.bat):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20105023.png)

## Перечисление переменных:
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20141712.png)

## Разбор кода:
      chcp 65001 
Команда для кодирования текста на русском языке.

      setlocal enabledelayedexpansion-
Режим отложенного расширения переменных среды. Позволяет использовать перезаписывающиеся переменные с !...!.

### Первый блок кода (6-9 строчки):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20142537.png)

Проверка наличия трех аргументов командной строки (PATH, MIN_PID, MAX_PID) и вывод сообщения об использовании скрипта в случае отсутствия одного или более аргументов.

### Второй блок кода (11-13 строчки):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20142911.png)

Установка значений переменных (DIRECTORY, MIN_PID, MAX_PID) на основе переданных аргументов.

### Третий блок кода (15-18 строчки):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20143133.png)

Проверка существования указанного каталога (DIRECTORY) и вывод сообщения об ошибке, если каталог не существует.

### Четвертый блок кода (20-31 строчки):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20143459.png)

Запуск цикла for, который выполняет команду PowerShell для получения информации о процессах с заданными PID, а затем записывает информацию в файлы, создаваемые на основе PID процессов.

### Пятый блок кода (33 строка):

![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-23%20233753.png)

Вывод сообщения "Файлы созданы" после завершения скрипта.

## Пример и алгоритм работы :
     Запуск cmd.
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20145112.png)

     Переход к папке с .bat файлом.
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20145536.png)

    Запуск файла.Ввод переменных (PATH, MIN_PID, MAX_PID)
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20145904.png)

test-директория , где будут созданы текстовые файлы.

4500-минимальный PID(process ID)

8000-максимальный PID(process ID)

### Проверка работы программы:
    Открываем папку test
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20150458.png)

Файлы созданы.Названия соответствуют PID.
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20151029.png)

    Открываем любой текстовый файл.
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20151322.png)

Содержание файла соответствует поставленной задаче.

# Описание алгоритма, пример запуска и выполнения программы (.sh)

![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20153725.png)

#### Используемые переменные

![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20154121.png)

## Разбор кода

### Первый блок кода (2-5 строчки):

![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20154511.png)

Этот блок выполняет проверку количества переданных аргументов и выводит сообщение об использовании скрипта, если количество аргументов не соответствует ожидаемому.

### Второй блок кода (8-10 строчки):

![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20154751.png)

Установка значений переменных (DIRECTORY, MIN_PID, MAX_PID) на основе переданных аргументов.

### Третий блок кода (13-16 строчки):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20154932.png)

Проверка существования указанного каталога (DIRECTORY) и вывод сообщения об ошибке, если каталог не существует.

### Четвертый блок кода (19-27 строчки):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20155202.png)

Этот блок использует цикл "for" для получения списка активных процессов и создания файлов с данными о процессах в указанном каталоге. Этот блок выполняет основную функцию скрипта.

### Пятый блок кода (29 строка):

![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20155327.png)

Вывод сообщения "Файлы созданы в каталоге" после завершения скрипта.

## Пример и алгоритм работы :
     Запуск cmd.
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20145112.png)

     Переход к папке с .sh файлом.
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20145536.png)

     Включение wsl(windiws subsistem for linux)
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20163445.png)

     Запуск файла.Ввод переменных (PATH, MIN_PID, MAX_PID)
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20163628.png)

test_linux-директория , где будут созданы текстовые файлы.

0-минимальный PID(process ID)

500-максимальный PID(process ID)    

    Открываем папку test_linux
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20163845.png)

    Открываем любой текстовый файл.
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20163944.png)

Содержание файла соответствует поставленной задаче.

# Questions 

1-что такое token и для чего он нужен в .bat файле
2-почему при удалении 22 строки код работает

## Question 1

    Что такое токен?
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20165320.png)
    Для чего он нужен в .bat файле?
Код:
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-22%20012844.png)

В данном коде, "tokens=1,2,3" указывает команде "for" на то, как разбивать строки, полученные из выполнения команды "powershell". Здесь "tokens" определяет, какие части строки будут извлекаться и присваиваться переменным в цикле.
    Блок кода с "tokens":
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20143459.png)

"%%A" будет содержать значение первого токена (Id),
"%%B" будет содержать значение второго токена (ProcessName),
"%%C" будет содержать значение третьего токена (UserName).
Таким образом, этот цикл for выполняет команду "PowerShell" для получения информации о процессах, и затем каждая строка вывода разбивается на токены (Id, ProcessName, UserName), которые затем используются для создания файлов с информацией о процессах в указанном каталоге.

## Question 2
    Почему при удалении 22 строки код работает?
Код работает , только не совсем корректо.Неправильно записывает process_name.
