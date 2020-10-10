#!/usr/bin/bash


set i=300
set n=300
set total=600
echo "Hello"
while [ $i = $total ]
do
	set num = `printf "%d\n" $i`
	echo $num
	/cp ./ALP_200.cc ./ALP_${num}.cc
	n = num - 100	
	sed -i -e "s/${n}/${num}/g" ./ALP_${num}.cc
	i=`expr 100 + $i`
	echo "Hello"

done
