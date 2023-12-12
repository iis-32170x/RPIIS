read -rp "Enter a path:" path
read -p "Input any string: " string
cd $path

mesyac=$(date +"%m")
minutasus=$(date +"%M")
chassus=$(date +"%H")
symsus=$(((chassus*60)+($minutasus)+2))
echo $symsus

IZM=2
for file in *; do 

    if [ -f "$file" ]; then 
		month=$(stat -c %w $file)
		arrmonth=(${month//-/ })
		if [ $mesyac -eq ${arrmonth[1]} ]; then
		minuta=$(stat -c %y $file)
		
		arrminuta=(${minuta//:**:/ })
		chas=(${arrminuta[1]})
		
		arrminuta=(${minuta//:/ })
		minuta=(${arrminuta[2]})

		sym=$(((chas*60)+($minuta)))
		echo $sym
		 	if [ $symsus -gt $sym ]; then
			# сюда не заходит
			sed -i 's/'$string'/321/g' $file 
			fi
			
		fi
    fi 
done


sleep 15




	

