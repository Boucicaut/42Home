#!/bin/sh
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;36m'
PURPLE='\033[0;35m'
NC='\033[0m'

if [ $# -eq 2 ];
then
i=0
j=0
l=0
status=""
while [ $i -lt $2 ]
do
ARG=`ruby -e "puts (-2..$1).to_a.shuffle.join(' ')"`
	echo $ARG
	((l=$(./push_swap $(echo $ARG) | wc -l)))
	status="$(./push_swap $(echo $ARG) | ./checker $(echo $ARG))"
	if [ "$status" = "OK" ]; then
		echo "Test #$i : ${BLUE}$l${NC} instructions || ${GREEN}$status${NC}"
	else
		echo "Test #$i : ${BLUE}$l${NC} instructions || ${RED}$status${NC}"
		echo "FAIL !"
		exit 1
	fi
	
	((j += l))
	((i++))
done
let j=$j/$i
printf "\n\t${PURPLE}$i${NC} tests ${RED}done${NC} with ${PURPLE}$k${NC} numbers to be sorted.\n"
printf "\tThe average number of instructions is :\n\t\t\t--> ${BLUE}$j${NC} <--\n\n"
fi

#	((l = $(ARG=`ruby -e "puts (1..$k).to_a.shuffle.join(' ')"` ; ./push_swap $(echo $ARG) | wc -l)))




#do
#ARG=`ruby -e "puts (1..$k).to_a.shuffle.join(' ')"`
#echo $ARG
#	((l=$(./push_swap -i $ARG | wc -l)))
#	printf "$(./push_swap -i $ARG | ./checker -i $ARG))"
#	((j += l))
#	echo "Test #$i : $l instructions || $status"
#	((i++))
#done
