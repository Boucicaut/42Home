#include "libft.h"

int	modef(int base, int i, double nb, char mode)
{
	nb = nb - (int)nb;
	while (nb >= 0.0000001)
	{
		nb = nb * 10;
		i++;
		nb = nb - (int)nb;
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
printf("NB = %f\n", nb);
	if (mode == 'f' || mode == 'z')
	{
		if (mode == 'f')
			i = modef(base, i, nb, 'f');
		else if (mode == 'z')
			i = modef(base, 0, nb, 'z');
	}
	return (i);
}
