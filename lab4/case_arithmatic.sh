#case arithmatic 
echo "enter two number"
read n1
read n2
echo "enter operation type + - x / e"
read op

case $op in
"+")
	add=`expr $n1 + $n2`
	echo "addition  = $add  " ;;
"-")
	sub=$(($n1 - $n2))
	echo "subtraction = $sub " ;;
"x")
	mul=`expr $n1 \* $n2`
	echo "Multiplication = $mul" ;;
"/")
	div=`expr $n1 / $n2`
	echo "Divition = $div" ;;
"e") exit 
esac

