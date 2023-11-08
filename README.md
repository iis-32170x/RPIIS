# ___Лабораторная работа 1 - Генерация файлов___
---
# __Условие задачи (Вариант 13)__
## __На вход пакетному файлу передаются два числа в качестве параметров. Скрипт создает каталог, в котором будет сгенерировано количество текстовых файлов, заданное первым параметром. Размер первого файла задается вторым параметром в байтах. Последующие сгенерированные файлы создаются на 10 байт меньшего размера. Если первый файл имеет размер меньше 10 байт, то создается только один файл.__
---
# __Реализация bat-файла__
Код:
```
@echo off
setlocal enabledelayedexpansion

:: Prover'te nalichie dvuh argumentov (kolichestvo fajlov i razmer pervogo fajla)
if "%~2"=="" (
    echo Trebuyutsya dva argumenta: kolichestvo fajlov i razmer pervogo fajla.
    goto :eof
)

:: Преобразование аргументов в числа
set /a "num_files=%~1"
set /a "file_size=%~2"

:: Создание пути к папке на рабочем столе
set "desktop_path=%USERPROFILE%\Desktop\GeneratedFiles"

:: Создание каталога для файлов на рабочем столе
mkdir "%desktop_path%"

:: Если размер файла меньше 10 байт, создаём только один файл
if !file_size! lss 10 (
    echo Generating file 1 with size !file_size!...
    fsutil file createnew "%desktop_path%\File1.txt" !file_size!
) else (
    :: Генерация файлов
    for /l %%i in (1,1,%num_files%) do (
        echo Generating file %%i...
        fsutil file createnew "%desktop_path%\File%%i.txt" !file_size!
        set /a "file_size=file_size-10"
    )
)

echo Fajly byli sozdany!
```
## __Переменные в коде bat-файла:__
* num_files - задаёт количество сгенерированных текстовых файлов, введённое пользователем;
* file_size - задаёт размер первого сгнерированного текстового файла, введённый пользователем;
* desktop_path - задаёт путь к папке генерируемых файлов на рабочем столе.
## __Как работает__
* Запускаем bat-файл через командную строку cmd: вводим путь, по которому расположен данный файл ("C:\Users\NoNameUser\Desktop\Moy batnik.bat").

![image](https://github.com/iis-32170x/RPIIS/assets/144939061/4d0276fb-8abf-4396-9020-93987e2e6b58)

* Через пробел вводим параметры скрипта:
  * Введём количество генерируемых файлов (например, 15 файлов);
  * Введём размер первого генерируемого файла в байтах:
    * 1) Если размер первого файла >10 байт (например, 500 байт), то сгенерируется 15 файлов;
    * 2) Если размер первого файла <10 байт (например, 9 байт), то сгенерируется 1 файл введённого пользователем размера.
    * 3) Если размер первого файла =10 байт, то сгенерируется 2 файла размером 10 и 0 байт.
  
    * 1) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/705bc6b2-dae7-4f45-933b-1c8b5b1e01f9)
    
    * 2) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/13f9dd82-53b4-43b6-bd19-51277a5e489e)
    
    * 3) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/4c6b4e86-a0f1-4a90-bded-e36fb3010f44)


* Нажимаем "Enter" и генерируем файлы.

   * 1) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/1a53c3ee-b63b-4af3-a55a-04e9dbe18d68)

   * 2) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/d62f56a9-9596-4d6a-8819-4a1a8831c83b)
  
   * 3) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/19077ddd-4aa5-479f-bf9e-3086fda250c9)

* Файл(ы) сгенерирован(ы), его (их) можно найти на рабочем столе в папке "GeneratedFiles".

 ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/99d0df80-82e4-4c5e-931b-bb57b8b8d8d7)

* Откроем папку и просмотрим её содержимое:
  * 1) Создалось 15 файлов, где размер каждого последующего файла, начиная с первого (его размер мы указали в первом параметре (500 байт)), уменьшается на 10 байт в сравнении с предыдущим:
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/3c6e726a-5229-4278-b2a1-4b771e627802)
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/6f992c70-7497-47d9-9ffb-eb6b7cb31ab4)
   * 2) Создался 1 файл размером 9 байт:
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/da1d8ff0-10f8-4c27-b2a8-889bd8e1ac06)
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/9903cbcd-ffd3-4cc1-8c99-ff1b40f5547c)

   * 3) Создалось 2 файла размером 10 и 0 байт:

![image](https://github.com/iis-32170x/RPIIS/assets/144939061/dc026148-59b9-4081-bf22-235f36c90b15)
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/e0e1c427-b364-45af-b457-abe625779cb5)

# __Реализация sh-файла__
Код:
```
#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Использование: $0 <количество файлов> <размер первого файла в байтах>"
    exit 1
fi

num_files=$1
file_size=$2

if [ $file_size -lt 10 ]; then
    num_files=1
fi

desktop_path="C:/Users/NoNameUser/Desktop"
mkdir -p "$desktop_path/generated_files"

for ((i=0; i<$num_files; i++)); do
    filename="$desktop_path/generated_files/file$i.txt"
    dd if=/dev/urandom of="$filename" bs=$file_size count=1 2>/dev/null
    file_size=$((file_size - 10))
done

echo "Создано $num_files файлов в каталоге $desktop_path/generated_files"
```
## __Переменные в коде sh-файла:__
* num_files - задаёт количество сгенерированных текстовых файлов, введённое пользователем;
* file_size - задаёт размер первого сгнерированного текстового файла, введённый пользователем;
* desktop_path - задаёт путь к папке генерируемых файлов на рабочем столе;
* filename - задаёт путь каждому генерируемому файлу в цикле.
## __Как работает__
* Запускаем sh-файл через Git: переведём текущую директорию в папку "Desktop" командой cd ~/Desktop.

![image](https://github.com/iis-32170x/RPIIS/assets/144939061/8a58cd3f-cb8d-4e95-b6d1-2c154e047a1e)

* Запустим скрипт с помощью команды ./script.sh, введя после него через пробел его параметры:
  * Введём количество генерируемых файлов (например, 15 файлов);
  * Введём размер первого генерируемого файла в байтах:
    * 1) Если размер первого файла >10 байт (например, 500 байт), то сгенерируется 15 файлов;
    * 2) Если размер первого файла <10 байт (например, 9 байт), то сгенерируется 1 файл введённого пользователем размера.
    * 3) Если размер первого файла =10 байт, то сгенерируется 2 файла размером 10 и 0 байт.
  
    * 1) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/8a7907b9-7ae3-403f-b291-e69345e61913)

    * 2) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/cd256a68-04c6-4b66-9b7d-f410e33f12c9)

    * 3) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/24ff57cd-27ec-45a4-8868-07568de10703)

* Нажимаем "Enter" и генерируем файлы.

   * 1) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/a32b43cf-da55-419a-92ac-cca166328adc)

   * 2) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/c5e1f6fe-3feb-4824-af1a-bd30b96775cf)

   * 3) ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/2d87dcb6-0d0e-4a8d-aa62-6f6de8a493c5)

* Файл(ы) сгенерирован(ы), его (их) можно найти на рабочем столе в папке "generated_files".

 ![image](https://github.com/iis-32170x/RPIIS/assets/144939061/d9beed60-63d8-467d-95ec-dc66201bd559)

* Откроем папку и просмотрим её содержимое:
  * 1) Создалось 15 файлов, где размер каждого последующего файла, начиная с первого (его размер мы указали в первом параметре (500 байт)), уменьшается на 10 байт в сравнении с предыдущим:
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/7768759c-8cf7-44b4-b643-9d4fd8120d07)
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/25b27819-84ab-4c73-aed1-816574999ced)
  * 2) Создался 1 файл размером 9 байт:
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/990681fb-e3f7-446a-bd16-611e538436fa)
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/d443dbdc-ec02-42c7-920a-eb8f4dca0b21)

   * 3) Создался 2 файл размером 10 байт:

![image](https://github.com/iis-32170x/RPIIS/assets/144939061/b7b9b3ed-4658-4332-82d5-64aa79e2c543)
![image](https://github.com/iis-32170x/RPIIS/assets/144939061/19594973-b373-45ad-9246-69dc2f31b59e)

Примечание: пути к каталогам и имена файлов могут отличаться в зависимости от операционной системы и настроек окружения.

## __Вывод__
В ходе выполнения данной лабораторной работы были приобретены навыки написания скриптов на batch и bash с помощью cmd и git.
