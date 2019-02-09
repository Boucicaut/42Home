#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

// Float 7, Double 16, Ldouble 19 

int	nbdecimal(unsigned long long int vl, int id, int max)
{
	int iz;
	int	mod;
	int	nine;
	int zero;
	int back;

	back = 0;
	zero = 0;
	nine = 0;
	iz = 0;
	printf("\n\n");
	printf("NBDECIMAL Vl : %lld\n", vl);

	mod = vl % 10;
	while ((mod == 0 || mod == 9) && vl > 1)
	{
		if (mod == 9)
			nine++;
		vl = vl / 10;
		mod = vl % 10;
		if (vl < 1)
			iz += nine;
	}
	while (vl > 1)
	{
		printf("Vl : %lld, mod : %d, iz : %d, zero : %d, nine : %d\n", vl, mod, iz, zero, nine);
		iz += 1;
		vl = vl / 10;
		mod = vl % 10;
	}
	iz -= id;
	printf("OUPUT IZ : %d\n", iz);
	(void)max;
	return iz;	
}

int	nbdigit(long double vl)
{
	int i;
	i = 0;
	while (vl > 1)
	{
		vl /= (long double)10;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	long double vl = 3.12345678901234;
	int	iz;
	long double	vl2 = 0;
	int	arrondi;

	printf("Vl : %.30Lf\n", (long double)2345.54545);
	printf("Vl : %.30f\n", (double)2345.54545);
	printf("Vl : %.30Lf\n", vl);
	int	id = nbdigit(vl);
	int max = 17;
	iz = 0;
	max = max - id;
	while (max-- > 0)
	{
		vl *= (long double)10;
		printf("Vl2 : %Lf | Vl : %.20Lf\n", vl2, vl);
	}
	printf("STOP| Vl : %.20Lf\n",vl);
	max = 19;
	vl2 = vl * 10.0;
	printf("Vl2 : %Lf", vl2);
	while (vl2 > (unsigned long long int)10000000000000000)
	{
		printf("19 digits %Lf\n", vl);
		vl2 -= (unsigned long long int)10000000000000000;
	}
	arrondi = (unsigned long long int)vl2 % 10;
	printf("Arrondi : %d, Llint : %lld\n", arrondi, (unsigned long long int)vl2);
	printf("Vl : %.20Lf || MaxLLint : %lld\n", vl, LLONG_MAX);
vl += (long double)0.5;
	iz=nbdecimal(vl, id, max);
	printf("Id : %d | Iz : %d\n", id, iz);
	if (iz + id > max)
		iz = (max - id) + 1;
	printf("Max ? Id : %d | Iz : %d | arron : %d\n", id, iz, arrondi);
	(void)argc;
	(void)argv;
	return (0);
}
// si arr >5 mais 9 pas d'arrondi
