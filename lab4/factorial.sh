echo "Enter Nubmer for factorial "
read n

if [ $n -le 0 ]
then
	echo "Factorial of negative number is not valid"
	exit 1
fi
i=1
fact=1
while [ $i -le $n ]
	do 
		fact=`expr $fact \* $i`
		i=`expr $i + 1`
	done
echo "factorial: $fact"
