echo "Enter fruit name "
read fruit
if [ -n $fruit ]
then
	if [ $fruit = "banana" -o $fruit = "mango" ]
	then 
		echo "Tropical fruits"
	elif [ $fruit = "grape" -o $fruit = "watermelon" ]
	then
		echo "Juicy fruits"
	elif [ $fruit = "orange" -o $fruit = "pineapple" ]
	then
		echo "citrus fruits"
	else
		echo "berry fruits"
	fi
else
	echo "string is empty"
fi
