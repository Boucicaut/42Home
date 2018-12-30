#include "libft.h"
#include <stdio.h>

int	checkzerodec(double nb)
{
	int	i;

	i = 10;
	while (i > 0)
	{
		nb = nb * 10;
		if ((int)nb > 0)
			return (1);
		i--;
	}
	return (0);
}

int	modef(int i, double nb)
{

	//while (nb == 0 || nb >= 0.0000000000000000000000000000001 || nb - (int)nb > 1)
	//printf("(int)nb * 10 : %d\n", (int)(nb * 10));
	while (((int)(nb * 10)) % 10 != 0 || checkzerodec(nb) == 1)
	{
		nb = (nb * 10);
		if ((nb = nb - ((int)nb)) > 0.999999)
			nb--;
		i++;
//		printf("nb : %20.16f, (int)nb : %d, d - int : %.10f, i : %d\n", nb, (int)nb, nb - (int)nb, i);
//	printf("(int)nb * 10 : %d\n", (int)nb * 10);
//getchar();
	}
	return (i);
}

int	sizenbchar(int base, int i, double nb, char mode)
{
	int		resd;
	int		nbd;

	nb == 0 ? nb = 1 : nb;
	resd = 1;
	nbd = (int)nb;
	while (resd <= nbd)
	{
		i++;
		resd = resd * base;
	}
	if (i == 0)
		i = 1;
	if (mode == 'f' || mode == 'z')
	{
		if (mode == 'f')
			i = modef(i, nb);
		else if (mode == 'z')
			i = modef(0, nb);
	}
	return (i);
}
/*
int	main(void)
{
double n = 0.00001;
printf("N : %.30f\n", n);
printf("Double : %.30f\n", 2.000000000000000);
	printf("total 7: %d\n", sizenbchar(10, 0, 0.0012, 'f'));
	printf("qte2  4: %d\n", sizenbchar(10, 0, 0.0012, 'z'));
	printf("qte  3: %d\n", sizenbchar(10, 0, 0.0012, 'd'));
	return (0);
}
*/
