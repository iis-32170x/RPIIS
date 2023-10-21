# Проверяем, переданы ли все необходимые аргументы
if [ $# -ne 3 ]; then
  echo "Использование: $0 ПУТЬ_К_КАТАЛОГУ МИНИМАЛЬНЫЙ_PID МАКСИМАЛЬНЫЙ_PID"
  exit 1
fi

# Переменные для аргументов
DIRECTORY="$1"
MIN_PID="$2"
MAX_PID="$3"

# Проверяем, существует ли каталог
if [ ! -d "$DIRECTORY" ]; then
  echo "Каталог $DIRECTORY не существует."
  exit 1
fi

# Получаем список активных процессов и создаем файлы в каталоге
for PID in $(ps -eo pid); do
  if [ "$PID" -ge "$MIN_PID" ] && [ "$PID" -le "$MAX_PID" ]; then
    PROCESS_NAME=$(ps -p "$PID" -o comm=)
    USER=$(ps -p "$PID" -o user=)
    FILENAME="$DIRECTORY/$PID".txt
    echo "Имя процесса: $PROCESS_NAME" > "$FILENAME"
    echo "Пользователь: $USER" >> "$FILENAME"
  fi
done

echo "Файлы созданы в каталоге $DIRECTORY"
