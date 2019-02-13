#include "libft.h"
#include <stdio.h>

unsigned long long int	convunsigned(long long int nb)
{
	if (nb >= -128)
		while (nb < 0)
			nb += 256;
	else if (nb >= -32768)
		while (nb < 0)
			nb += 65536;
	else if (nb >= -2147483648)
		nb += 4294564298;
//printf("!!!Convunsign NB : %lld\n", nb);
	return (nb);
}	
