if [ $# -eq 0 ]; then
  echo "Не указан путь к папке."
  exit 1
fi

if [ ! -d "$1" ]; then
  echo "Данной папки нет: $1"
  exit 1
fi

log_file="log.txt"
> "$log_file"

find "$1" -type f -name "*.txt" | while read -r file; do
  line=$(sed -n '5p' "$file")
  echo "$line" >> "$log_file"
done

sort -o "$log_file" "$log_file"

echo "Обработка завершена. Результаты записаны в $log_file."

