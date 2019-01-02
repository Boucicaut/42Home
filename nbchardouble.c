#include <stdio.h>

int	nbdecimaldigits(double vl, int max, int id, int base)
{
	int	i = 0;
	double	nine = 0.99999999999999;
	double	one = 0.00000000000001;
	int	iz = 0;
	double	vl2 = 0;
	// si .0 ??

	while (i + id < 16)
	{
		vl2 = vl;
		while (vl > 21748364)
			vl = vl - 20000000;
//printf("vl : %.20f\n", vl);
//printf("vl : %.20f - (int)vl : %d\n", vl, (int)vl);
		vl = vl - (int)vl;
//printf("vl : %.20f\n", vl);
		if (i + id >= max || vl > nine || vl < one) // suivant i	
			return (iz);
		iz++;
		i++;
		vl = vl2 * base;
//printf("NEXT\n");
//printf("Iz : %d , i : %d\n", iz, i);

	nine = nine * 10 - 9;
	one = one * 10;

	}

	vl2 = vl;
	vl = vl - (int)(vl/10) * 10;
	//iz = calcul(vl, 0, 0, 0, 0, 0, 16, id);	

	return (iz);
}

int	nbdigits(double vl, int base)
{
	int	id;

	id = 0;
	if (vl < 1)
	while (vl >= 1)
	{
//printf("DD vl : %f\n", vl);
		vl = vl / base;
		id++;
	}
	return (id > 0 ? id : 1);
}

int	qtenb(double vl, char mode, int base, int max)
{
	int	i;
	int	id;

	id = 0;
	i = 0;
	id = nbdigits(vl, base);
	if (mode == 'z')
		return (nbdecimaldigits(vl, max, id, base));
	if (mode == 'f')
		return (nbdigits(vl, base) + nbdecimaldigits(vl, max, id, base));
	return (id);
}

int	main(void)
{
	double	nb = 0.0123456789;
double	nb2 = nb;
	int		base = 10;
	int		max = 16;

printf("%.20f\n", nb);
printf("ID : %d\n", qtenb(nb, 'd', 10, 16));
printf("IZ : %d\n", qtenb(nb, 'z', 10, 16));
printf("IF : %d\n", qtenb(nb, 'f', 10, 16));
/*
printf("%.14f\n", nb);
nb = nb / 10000;
printf("%.14f\n", nb);
nb = nb * 10000;
printf("%.14f\n", nb);
printf("\n ___________\n");

printf("%.14f\n", nb);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb * 10);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb * 100);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb * 1000);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb * 10000);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb * 100000);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb * 1000000);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb * 10000000);
printf("(int) nb : %d\n", (int)nb);
printf("%.14f\n", nb = nb / 200000000);
	nb = nb2;
printf("%.14f\n", nb / 10);
printf("%.14f\n", nb / 100);
printf("%.14f\n", nb / 1000);
printf("%.14f\n", nb / 10000);
printf("%.14f\n", nb / 100000);
printf("%.14f\n", nb / 1000000);
printf("%.14f\n", nb / 10000000);
printf("%.14f\n", nb / 100000000);
printf("%.14f\n", nb / 10000000000);
printf("%.14f\n", nb / 100000000000);
printf("%.14f\n", nb / 10000000000000);
*/

//	printf("\n\t\t iz : %d\n", iz)

	return (0);
}
