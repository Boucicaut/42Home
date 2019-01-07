#include "libft.h"
#include <stdio.h>

int	bignbdigits(long long int vl, int base)
{
	int	id;

	id = 0;
	while (vl > 0.999999)
	{
		vl = vl / base;
		id++;
	}
	return (id > 0 ? id : 1);
}

int	ft_qtebignb(long long int vl, int base)
{
	int	id;
	int	neg;

	neg = vl > 0 ? 0 : 1;
	vl = vl > 0 ? vl : -vl;
	id = 0;
	id = bignbdigits(vl, base);
	return (neg + id);
}
