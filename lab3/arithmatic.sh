echo "Enter Two Number for arithmatic : "
read n1
read n2
echo "Enter Operation choice + = 1 ,- = 2,* = 3, / = 4: "
read op

if [ $op -eq 1 ]
then
	add=`expr $n1 + $n2`
	echo $add
elif [[ $op == 2 ]] #these also valid
then
	sub=$(($n1-$n2)) #this also a valid
	echo $sub
elif [ $op -eq 3 ]
then
	mul=`expr $n1 \* $n2`
	echo $mul
elif [ $op -eq 4 ]
then
	div=`expr $n1 / $n2`
	echo $div
else
	echo "error!"
fi
