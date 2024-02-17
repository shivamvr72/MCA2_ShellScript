
#OUTLINE 
#LOOPS
#WHILE LOOP
#until
#FOR LOOP
#BREAK AND CONTINUE

echo "Enter Number For table "
read n
echo "printing using while loop"
i=1

#whle loop
#the loop will execute while the condition is true or we rather say while condition becomes false
while [ $i -le 10 ] #less than equal
do 
#	ans=$(( $n * $i)) #we can also write expression like this or
	ans=`expr $n \* $i`
	echo "$n x $i = $ans"
	i=`expr $i + 1` 
done

#until loop
#the loop will excute until the condtion is flase or we rather say until condition becomes true
echo "printing using until loop"
j=1
until [ $j -ge 11 ] #greater than equal
do
	ans=$(( $n * $j)) #we can also write expression like this or
#	ans=`expr $n \* $j`
	echo "$n x $j = $ans"
	j=`expr $j + 1` 
done

#for loop
echo "################### for loop #####################"
# $@ use to take sequncial command line arguments
echo "using cmd arguments"
for i in $@
do
	echo "$i"
done

#for loop using direct taking arg
echo "using direct arguments"
for i in 10 20 30 40 50 "shiv"
do 
	echo "$i"
done
 
#for loop as shall 
echo "using direct arguments directly"
for i in {1..10..2} #from 1 to 10000 increment by 2 {start..end..increment} or {start..end}(10 is also included here) 
do
	echo "$i"
done

#for loop as normal proramming lauguage conditions
echo "for loop as normal programming language"
for ((i=1; i<10000 ; i++))
do
	echo "$i"
done


#break 
echo "break "
for i in {1..10}
do 
	if [ $i -eq 5 ]
	then 
		break #loop will stop the execution
	fi
	
	echo "$i"
done

#continue
echo "continue"
for i in {1..10}
do 
	if [ $i -eq 2  -o $i -eq 7 ]
	then 
		continue #loop will skip if condition becomes true
	fi
	
	echo "$i"
done
