#!/bin/sh
RED='\033[0;32m'
BLUE='\033[0;36m'
PURPLE='\033[0;35m'
NC='\033[0m'

if [ $# -eq 2 ];
then
i=0
j=0
nbtest=$2
k=$1
l=0
while [ $i -lt $nbtest ]
do
	#((j += $(ARG=`ruby -e "puts (1..$k).to_a.shuffle.join(' ')"` ; ./push_swap $(echo $ARG) | grep ')' | awk -F')' '{if($0>2)print$1}')))
	((l = $(ARG=`ruby -e "puts (1..$k).to_a.shuffle.join(' ')"` ; ./push_swap $(echo $ARG) | wc -l)))
	((j += l))
	echo "Test #$i avec $l instructions "
	((i++))
done
let j=$j/$i
printf "\n\t${PURPLE}$i${NC} tests ${RED}done${NC} with ${PURPLE}$k${NC} numbers to be sorted.\n"
printf "\tThe average number of instructions is :\n\t\t\t ${BLUE}$j${NC}\n\n"
fi
