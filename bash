bash
#!/bin/bash

# Очищаем файл result.txt перед выполнением скрипта
echo -n > result.txt

# Получаем список всех процессов и считаем количество повторений
processes=()
count=()
while IFS=',' read -r name _; do
found=false
for ((i=0; i<${#processes[@]}; i++)); do
if [[ $name == ${processes[i]} ]]; then
found=true
((count[i]++))
break
fi
done
if [[ $found == false ]]; then
processes+=("$name")
count+=("1")
fi
done < <(ps -eo comm —no-headers)

# Находим процесс с максимальным количеством повторений
max_count=0
for ((i=0; i<${#processes[@]}; i++)); do
if ((count[i] > max_count)); then
max_count=${count[i]}
max_process=${processes[i]}
fi
done

# Записываем результат в файл result.txt
echo "$max_process $max_count" » result.txt
