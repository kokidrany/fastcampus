#!/bin/sh
if [ "$1" = "fork" ]
then
	echo "fork not allowed"
#	exit
elif [ "$1" = "knife" ]
then
	echo "knife not alloed"
#	exit
else
	echo "fork & knife not allowed"
fi
echo "spoon please"
echo "===================="
echo 
case $1
	in
	"fork") echo "fork not allowed"
	exit;;
"knife") echo "knife not allowed"
	exit;;
*) echo "fork & knife not allowed"
esac

func1(){
for var in 1 2 3 4 5
do
	echo $var
done
}

func2(){
echo "======================"
n=$1
#n=5
while [ "$n" -ne 0 ]
do
	echo $n
	n=`expr $n - 1`
done
}

