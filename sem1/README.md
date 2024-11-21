<<<<<<< HEAD
# ПОИИС
 Репозиторий дисциплины Представление и обработка информации в интеллектуальных системах 
 (Representation and processing of information in intelligent systems) для групп потока 32170х.
 С условиями лабораторных работ можно ознакомиться в папке соответствующего семестра.
=======
# BSUIR ЛР1 
В рамках ЛР 1 необходимо создать файл с разрешением *bat.* и *sh.* в соответствии с заданным вариантом.
Цель данной лаборотоной работы - ознакомится с командными строками операционных систем *Windows* и *Linux*.
## Условие ЛР1 (95 вариант)
![image](https://github.com/iis-32170x/RPIIS/assets/149183642/369e6398-a8fb-4111-a592-16f3132c00cb)

)
# Описание алгоритма, пример запуска и выполнения программы (.bat)
![image](https://github.com/iis-32170x/RPIIS/assets/149183642/6ee62d7f-58a7-4d83-ad4f-f18527eb1887)

## Алгоритм программы
1. Отключиаем вывод команд на экран.
2. Задаем переменную imput_time которая получает время формата ЧЧ:ММ:CC с помощью ввода с консоли
3. Задаем переменную current_time которое получает первые восемь знаков времени из системы
4. Сравниваем время введеное с консоли и текущее время
5. Если время совпадает, то создаем на рабочем столе папку в которой создаем файлы с параметрами сети, системы и запущенными процессами
6. Если время неравно, то возвращаемся к шагу 4
### Переменные
- imput_time: получает время формата ЧЧ:ММ:CC
- current_time: получает первые восемь знаков времени из системы

 ## Разбор кода
1. Строка "chcp 65001 > nul" устанавливает кодировку консоли на UTF-8, чтобы правильно отображать символы.

2. Строка "set /p input_time=Введите время в формате ЧЧ:ММ:СС:" запрашивает у пользователя ввести время в формате ЧЧ:ММ:СС и сохраняет его в переменную "input_time".

3. Метка ":wait" обозначает начало блока кода, который будет выполняться до тех пор, пока условие не будет выполнено.

4. Строка "set current_time=%time%" сохраняет текущее время в переменную "current_time".

5. Строка "set current_time=%current_time:~0,8%" обрезает значение переменной "current_time" до первых 8 символов, чтобы получить только время без дополнительной информации.

6. Условие "if "%input_time%"=="%current_time%" (" проверяет, равно ли значение переменной "input_time" значению переменной "current_time".

7. Если значения равны, то выполняется блок кода внутри скобок:
   - Строка "MD C:\Users\bebra\Desktop\Laba1pivovovovoo" создает новую папку с указанным путем.
   - Строка "ipconfig > C:\Users\bebra\Desktop\Laba1pivovovovoo\network_parameters.txt" записывает вывод команды "ipconfig" в файл "network_parameters.txt" в указанной папке.
   - Строка "systeminfo > C:\Users\bebra\Desktop\Laba1pivovovovoo\system_parameters.txt" записывает вывод команды "systeminfo" в файл "system_parameters.txt" в указанной папке.
   - Строка "tasklist > C:\Users\bebra\Desktop\Laba1pivovovovoo\processes.txt" записывает вывод команды "tasklist" в файл "processes.txt" в указанной папке.
   - Команда "pause" приостанавливает выполнение скрипта и ожидает нажатия клавиши перед продолжением.

8. Если значения не равны, то выполняется блок кода после ключевого слова "else":
   - Строка "timeout /t 1 >nul" задерживает выполнение скрипта на 1 секунду.
   - Команда "goto wait" перенаправляет выполнение скрипта на метку ":wait", чтобы повторить цикл ожидания.
## Пример и алгоритм работы:
 запуск командой строки

 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/9f44d34e-31a9-4944-b426-2a64e1b785bc)

 Открытие .bat файла:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/149183642/5e568095-f6d3-4938-80a7-4495466429f3)

 Результат:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/149183642/82a17365-f4f4-4f92-917d-fe9cb7a668c2)
 

 ![image](https://github.com/iis-32170x/RPIIS/assets/149183642/a9e445af-27d4-446b-b84f-a7bb62a082aa)
 

 ![image](https://github.com/iis-32170x/RPIIS/assets/149183642/3d36fe6b-ab89-49f8-9b1c-b68e2b4fdafc)





 # Описание алгоритма, пример запуска и выполнения программы (.sh)
```
 read -p ""  time
 
 // Получаем текущее время в формате "часы:минуты:секунды"
 
 current_time=$(date +"%H:%M:%S")


//Проверяем, если текущее время совпадает с указанным временем для выполнения кода

if [[ "$current_time" == "$time" ]]; then

    # Создаем папку на рабочем столе с текущей датой и временем
    
    folder_name=$(date +"%Y-%m-%d_%H-%M-%S")
    mkdir ~/Desktop/$folder_name

    # Создаем файл внутри папки для записи данных
    
    file_path=~/Desktop/$folder_name/network_os_processes.txt
    touch $file_path

    # Записываем данные сети в файл
    
    echo "=== Network Information ===" >> $file_path
    ipconfig >> $file_path

    # Записываем данные ОС в файл
    
    echo -e "\n=== Operating System Information ===" >> $file_path
    uname -a >> $file_path

    # Записываем запущенные процессы в файл
    
    echo -e "\n=== Running Processes ===" >> $file_path
    ps aux >> $file_path


  
    sleep 1

else
while [[ "$current_time" != "$time" ]]; do
        sleep 1
        current_time=$(date +"%H:%M:%S")
        echo $time
        echo $current_time
    done
  if [[ "$current_time" == "$time" ]]; then
    # Создаем папку на рабочем столе с текущей датой и временем
    folder_name=$(date +"%Y-%m-%d_%H-%M-%S")
    mkdir ~/Desktop/$folder_name

    # Создаем файл внутри папки для записи данных
    file_path=~/Desktop/$folder_name/network_os_processes.txt
    touch $file_path

    # Записываем данные сети в файл
    echo "=== Network Information ===" >> $file_path
    ipconfig >> $file_path

    # Записываем данные ОС в файл
    echo -e "\n=== Operating System Information ===" >> $file_path
    uname -a >> $file_path

    # Записываем запущенные процессы в файл
    echo -e "\n=== Running Processes ===" >> $file_path
    ps aux >> $file_path


    echo complete123
    sleep 1

    fi
fi

```
 
 


 ## Алгоритм программы
  1. Отключиаем вывод команд на экран.
  2. Задаем переменную imput_time которая получает время формата ЧЧ:ММ:CC с помощью ввода с консоли
  3. Задаем переменную current_time которое получает первые восемь знаков времени из системы
  4. Сравниваем время введеное с консоли и текущее время
  5. Если время совпадает, то создаем на рабочем столе папку в которой создаем файлы с параметрами сети, системы и запущенными процессами
  6. Если время неравно, то возвращаемся к шагу 4
 ### Переменные
 - time: получает время формата ЧЧ:ММ:CC
 - current_time: получает первые восемь знаков времени из системы
 
## Пример и алгоритм работы:
 Запуск sh и файла:
 
 Открываем gitbash:
 
 ![image](https://github.com/iis-32170x/RPIIS/assets/148707516/37b8b821-ef15-42ae-88eb-33a4677435cf)

Вводим время в консоль

![image](https://github.com/iis-32170x/RPIIS/assets/149183642/c44728f8-b52b-4b6c-9b43-fde791d9e145)

Результат:

![image](https://github.com/iis-32170x/RPIIS/assets/149183642/1793f95f-25a3-4b78-8ef0-6cc36da20963)

![image](https://github.com/iis-32170x/RPIIS/assets/149183642/cd82b897-22b3-44a4-a8da-a0de44b4f136)



 # Вывод
 Приобрел навыки работы с командной строкой. Разработал программы, выполняющие соответсвующее задание.
>>>>>>> d158e15 (README.md)
