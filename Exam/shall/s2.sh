#OUTLINE
#1. CONDITIONAL STATEMENTS 


# if statement
echo "IF BLOCK"
n=2
if [ $n -eq 2 ]
then 
	echo "true"
fi


# if else statement

echo "if else statement"
n1=30
n2=7

if [ $n -eq $n2 ] 
then 
	echo "Number n1 = $n is same as n2 = $n2"
else 
	echo "Number is not same $n != $n2"
fi

# IF ELSE USING DIRECT SIGN OPERATORS 
echo "We can also use simple comparison operators "
n3=30
if (( $n == $n3 ))
then 
	echo "Number n1 = $n is same as n2 = $n2"
else 
	echo "Number is not same $n != $n2"
fi

# IF then ELIF then ELSE
#read = for take input
# AND and OR 
# -a == &&
# -o == ||

echo "Enter age"
read age
if [ $age -gt 18  -a $age -lt 60 ]
then 
	echo "You are above 18 and under 60"
elif [[ $age -lt 18 && $age -gt 0 ]]
then 
	echo "you are under 18"
elif [ $age -gt 60 ] && [ $age -lt 100 ]
then 
	echo "you are above 60 and below 100"
elif [ $age -gt 100 ]
then
	echo "you are super elder"
elif (( age < 0 ))
then
	echo "This is invalid age "
fi


# these is the switch statements

echo "Car you might have " 
read car
case $car in
	1) echo "BMW" ;;
	2) echo "Lamboghini" ;;
	3) echo "Mercedes" ;;
	4) echo "Audi" ;;
	5) echo "Land Rover" ;;
	6) echo "Jaguar" ;;
	7) echo "Ferrari" ;;
	8) echo "Porche" ;;
	9) echo "Meseratti" ;;
esac

