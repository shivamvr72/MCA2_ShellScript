echo "enter string1: " 
read str1
echo "Enter String2: "
read str2

if [[ $str1 == $str2 ]]
	then 
	echo "Both strings are same "
else
	echo "Both strings are different" 
fi
