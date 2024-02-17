
#OUTLINE
#1. OUTPUT ON SCREEN
#2. REDIRECTING OUTPUT INTO FILE AND CREATING FILE 
#3. COMMENTS

#print output on terminal
echo "hello snehshiv" 


#now redirecting to ourput a file
echo "hey sneh..!" > t1.txt

#printing output from t1.txt
echo "o/p from t1.txt using cat"
cat t1.txt

#creating another file and redirecting the output to the file
echo "write something "
cat > t2.txt

#printing output t2.txt
echo "o/p from output t2.txt"
cat t2.txt

#wanted to append into the same fjle
echo "write something into t2.txt"
cat >> t2.txt
echo "o/p from output t2.txt"
cat t2.txt

: '
cat > t2.txt
echo "this is multiline comments "
'

#the here doc is more likely diclaring variable
echo "here doc delimiter"
cat << name
snehal shivam
name



