echo "Enter three number to find minimum:"
read n1
read n2
read n3

if [ $n1 -gt $n2 -a $n1 -gt $n3 ]
then 
	echo "$n1 is greater 1"
elif [  $n2 -gt $n3 ]
then 
	echo "$n2 is greater 2"
else
	echo "$n3 is greater 3"
fi
	
