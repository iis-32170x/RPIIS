read -p "Input any number: " number
read -rp "Input a path: " path

number=$(echo $number | sed 's/^0*//')

isPassed=1

checkNumber() {
	if [ "$number" == "" ] 
	then
		isPassed=0
		echo "the 'number' variable isn't defined"
	elif ! [[ $number =~ ^-?[0-9]+$ ]]
		then
			isPassed=0
			echo "the 'number' variable doesn't have number type"
	fi
}

checkPath() {
	if [ "$path" == "" ]
	then
		isPassed=0
		echo "the 'path' variable isn't defined"
	elif ! [ -e $path ] 
		then
			isPassed=0
			echo "the entered path doesn't exist"
	fi
}

checkNumber
checkPath

if [ $isPassed -eq 1 ]
then
	fileName="$(printf "%(%d.%m.%Y)T").txt"

	if [ -e $fileName ]; then
   		rm "$fileName"
	fi
	touch "$fileName"

	cat $path | while read line 
	do
	   read -a data <<< "$line"
	   if [[ ${data[0]} -ge $number ]]
	   then
	   	echo "${data[0]} ${data[1]}" >> "$fileName"
	   fi
	done
fi