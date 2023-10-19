echo "Введите число:"
read divisor
pid_list=$(ps -e -o pid,comm --no-header | awk -v divisor="$divisor" '$1 % divisor == 0 {print $2, $1}')
if [ -n "$pid_list" ]; then
  echo "Процессы, PID которых делится нацело на $divisor:"
  echo "$pid_list"
else
  echo "Нет процессов, PID которых делится нацело на $divisor."
  sleep 3
fi

