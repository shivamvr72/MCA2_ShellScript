if [ $# -lt 2 ]
then
	echo "Enter two number : "
		read x
		read y
else
	x=$1
	y=$2
fi

if [ $x -gt $y ]
then
	echo "$x is greater "
elif [ $x -lt $y ]
	then
	echo "$y is greater "
else
	echo "both are same"
fi
