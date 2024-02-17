#for loop usage 2
#will take runtime data 
echo "Enter file name  " 
read fname
for i in $(cat $fname);
do 
	echo $i
done
