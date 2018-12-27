#include <stdio.h>
#include "libft.h"

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
	if (mode == 'f')
	{
		nb = nb - (int)nb;
		while (nb >= 0.000001)
		{
			nb = nb * 10;
			i++;
			nb = nb - (int)nb;
		}
		i = sizenbchar(base, i, (int)nb, 'd');
	}
	return (i);
}
