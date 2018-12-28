#include "libft.h"

int	modef(int base, int i, double nb, char mode)
{
	while (nb >= 0.000001 || nb - (int)nb > 1)
	{
		nb = (nb * 10);
		if ((nb = nb - ((int)nb)) > 0.999999)
			nb--;
		i++;
	/*	printf("nb : %20.10f, (int)nb : %d, d - int : %.10f, i : %d\n", nb, (int)nb, nb - (int)nb, i);*/
	}
	return (i);
}

int	sizenbchar(int base, int i, double nb, char mode)
{
	int		resd;
	double	resf;
	int		nbd;

	nb == 0 ? nb = 1 : nb;
	resd = 1;
	resf = 1;
	nbd = (int)nb;
	while (resd <= nbd)
	{
		i++;
		resd = resd * base;
	}
	if (mode == 'f' || mode == 'z')
	{
		if (mode == 'f')
			i = modef(base, i, nb, 'f');
		else if (mode == 'z')
			i = modef(base, 0, nb, 'z');
	}
	return (i);
}
/*
int	main(void)
{
	printf("total 7: %d\n", sizenbchar(10, 0, 4.234736, 'f'));
	printf("qte2  4: %d\n", sizenbchar(10, 0, 4.234736, 'z'));
	printf("qte  3: %d\n", sizenbchar(10, 0, 4.234736, 'd'));
	return (0);
}
*/
