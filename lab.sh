echo "Введите номер порта:"
read port
pid=$(netstat -ano | grep "$port" | awk '{print $5}')
if [[ -z "$pid" ]]; then
echo "Нет запущенных процессов"
exit 1
else
echo "Процесс запущен"
fi
echo "PID процесса: $pid"
while true; do
read -p "Хотите завершить процесс? [Y/n] " choice
case $choice in
[Yy]* )
if kill -0 $pid >/dev/null 2>&1; then
kill $pid
echo "Процесс завершен"
else
echo "Процесс уже завершен или не существует"
fi
break;;
[Nn]* )
exit 0;;
* )
echo "Некорректный ввод, попробуйте снова";;
esac
done
