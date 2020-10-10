#!/bin/bash

num=200
for ((file=0;file<14;file++)); do

#echo "${a[i]}"

echo $num

if [ $num -le 900 ]; then
root ALP_${num}.cc

num=$(($num + 100))

else
root ALP_${num}.cc
num=$(($num + 200))



fi

done

