#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Float 7, Double 16, Ldouble 19 

int	nbdecimal(long long int vl, int id, int max)
{
	int iz;
	int	mod;
	int	nine;
	int zero;
	int back;

	back = 0;
	zero = 1;
	nine = 1;
	iz = 0;
printf("\n\n");
	while (vl > 1)
	{
printf("Vl : %lld, mod : %d, iz : %d, zero : %d, nine : %d\n", vl, mod, iz, zero, nine);
		mod = vl % 10;
		if (mod == 9)
			nine++;
		if (id + iz > max)
		{
			iz += nine - 1;
			nine = 0;
		}
		else if (mod == 0 && zero)	
			zero = 1;
		else
		{	
			iz++;
			zero = 0;
			nine = 0;	
		}
		vl = vl / 10;
	}
	if (nine)
		iz += nine - 1;
printf("iz : %d\n", iz);
	return iz;	
}

int	nbdigit(long double vl)
{
	int i;
	i = 0;
	while (vl > 1)
	{
vl /=10;
i++;
}
return (i);
}

int	main(int argc, char **argv)
{
	long double vl = atof(argv[1]);
int	iz;
	long double	vl2;
	int	arrondi;
	//int mod : ;
	printf("Vl : %.20Lf\n", vl);
	int	id = nbdigit(vl);
	int max = 16;
	max = max - id;
	while (max-- > 0)
	{
		vl *= 10;
printf("Vl2 : %Lf | Vl : %Lf\n", vl2, vl);
	}
	max = 16;
	vl2 = vl * 10;
printf("Vl2 : %Lf", vl2);
	while (vl2 > 1000000000000000)
	{
		printf("%Lf\n", vl);
		vl2 -= 1000000000000000;
	}
	arrondi = (long long int)vl2 % 10;
	printf("Vl : %.20Lf\n", vl);
printf("Arrondi : %d, Llint : %lld\n", arrondi, (long long int)vl2);
	iz=nbdecimal(vl, id, 16) - id;
	if (iz + id > max)
		iz = max - id + 1;
	printf("Id : %d | Iz : %d\n", id, iz);
return (0);
}
// si arr >5 mais 9 pas d'arrondi
