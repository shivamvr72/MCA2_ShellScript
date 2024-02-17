#for loop in shell 
echo "command line args to read"
for var in "$@" ;
do 
	echo "$var"
done


#or 
echo "inside arg"
for i in {1..5}
do 
	echo "$i"
done
