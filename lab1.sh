if [ ! -d "$1" ]; then
  echo "Данной папки нет"
  exit 0
elif [ -d "$1" ]; then
  echo ""
  echo "Скрытые файлы .txt найдены:"
  echo ""
  fileCount=$(find "$1" -type f -name "*.txt" -print0 | grep -c "")
  echo "Количество найденных файлов: $fileCount"
fi
