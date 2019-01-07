#include "libft.h"
#include <stdio.h>

int	nbdecimaldigits(double vl, int max, int id, int base)
{
	int	i = 0;
	double	nine = 0.9999999999999;
	double	one = 0.0000000000001;
	int	iz = 0;
	double	vl2 = 0;

	while (i + id < 16)
	{
		vl2 = vl;
		while (vl > 21748364)
			vl = vl - 20000000;
		vl = vl - (int)vl;
//printf("vl : %.18f || iz : %d || nine : %f || one : %.16f\n", vl, iz, nine, one);
		if (i + id >= max || vl > nine || vl < one) // IF VL != 0 ?? pour le cas 12345.123456789999
			return (iz);
		iz++;
		i++;
		vl = vl2 * base;
		nine = nine * 10 - 9;
		one = one * 10;


	}
	vl2 = vl;
	vl = vl - (int)(vl/10) * 10;
	return (iz);
}

int	nbdigits(double vl, int base)
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

int	ft_qtenb(double vl, char mode, int base, int max)
{
	int	i;
	int	id;
	int	neg;

	neg = vl > 0 ? 0 : 1;
	vl = vl > 0 ? vl : -vl;
	id = 0;
	i = 0;
	id = nbdigits(vl, base);
	if (mode == 'z')
		return (nbdecimaldigits(vl, max, id, base));
	if (mode == 'f')
		return (neg + nbdigits(vl, base) + nbdecimaldigits(vl, max, id, base));
	return (neg + id);
}
