#!/bin/bash

i=0
j=0
nbtest=20
k=500
while [ $i -le $nbtest ]
do
#((j += $(ARG=`ruby -e "puts (1..$k).to_a.shuffle.join(' ')"` ; ./push_swap $(echo $ARG) | grep ')' | awk -F')' '{if($0>2)print$1}')))
((j += $(ARG=`ruby -e "puts (1..$k).to_a.shuffle.join(' ')"` ; ./push_swap $(echo $ARG) | wc -l)))
((i++))
done
let j=$j/$i
echo "$i tests done with $k numbers to be sorted."
echo "The average number of instructions is : $j"
