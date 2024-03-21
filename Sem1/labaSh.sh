echo привет
echo -e "\n введите путь к папке:"
read path_to
while [ ! -d "$path_to" ]; do
  echo "Папка $path_to не существует."
  echo  " введите другой путь к папке:"
  read path_to
done
echo -e "\n Количество файлов в папке"
ls  $path_to  | wc -l
VAR1=$(ls  $path_to  | wc -l)
touch C:\\Users\\Глеб\\log.txt
tasklist.exe > C:\\Users\\Глеб\\log.txt 
VAR2=$(wc -c < C:\\Users\\Глеб\\log.txt)
VAR3=$(wc -l < C:\\Users\\Глеб\\log.txt)
touch C:\\"$(date +%F)".txt
let "A = $VAR1 * ($VAR2 - ($VAR3 * 2))"
echo $A > C:\\"$(date +%F)".txt
read -p "Press enter to continue"
