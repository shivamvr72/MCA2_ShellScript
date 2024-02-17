# taking cmd arguments by using like $0 $1..

echo $0 #will print the zeroth argument which is actully file name while we excecute

echo $1 #first argument 

arg2=$2
echo "$arg2"

#now working as a array using $@

argsArr=("$@")
echo ${argsArr[1]} ${argsArr[0]}

#it will print all arguments
echo $@

#it will print no of arguments
echo $#




