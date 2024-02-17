echo "Today's date : `date`"
echo "Home Director : $HOME " 
echo "Current Woking Directoty : `pwd` "

echo "enter value"
read s1
echo "$s1"

echo "Enter File Name: "
read fname
cat $fname

echo "addition..."
read a1 a2
total=`expr $a1 + $a2`
echo "total $total"
