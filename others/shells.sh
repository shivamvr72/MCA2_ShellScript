echo "Enter File Name : "
read fname 
echo "Content : " 
cat $fname 
echo "Lines and Words: " 
wc -l -w $fname
