ead -p ""  time
# Получаем текущее время в формате "часы:минуты:секунды"
current_time=$(date +"%H:%M:%S")

# Проверяем, если текущее время совпадает с указанным временем для выполнения кода
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

else
while [[ "$current_time" != "$time" ]]; do
        sleep 1
        current_time=$(date +"%H:%M:%S")

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



    sleep 1

    fi
fi

