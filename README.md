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

### Пятый блок кода (32 строка):
![image](https://github.com/Zubabubal/ads/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-10-21%20143836.png)

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
