#!/bin/bash

num=300
for ((c=0;c<13;c++)); do

#echo "${a[i]}"

echo $num

if [ $num -le 900 ]; then
cp ./ALP_200.cc ./ALP_${num}.cc
sed -i -e "s/200/${num}/g"  ./ALP_${num}.cc
rm ./ALP_${num}.cc-e

num=$(($num + 100))

else
cp ./ALP_200.cc ./ALP_${num}.cc
sed -i -e "s/200/${num}/g"  ./ALP_${num}.cc
rm ./ALP_${num}.cc-e
num=$(($num + 200))

fi

done

