#include "libft.h"
#include <stdio.h>

int	verififnine(double nb)
{
	int	i;

	i = 10;
	while (i > 0)
	{
		nb = nb * 10;
		if ((int)nb % 10 != 9)
			return (0);
		i--;
	}
	return (1);
}
									// CHECK AVEC IFNINE (VOI NB)
int	*ft_splitdouble(double nb)
{
	int		*tab;
	int		entier;
	int 	qte;
	double	cp;

//printf("NB : %.30f\n", nb);
	cp = nb;
	if (!(tab = malloc(sizeof(int) * 3)))
		return (NULL);
	qte = sizenbchar(10, 0, nb, 'z'); // !! 'f' c'est tout, +1 donc si 0...
	entier = 0;
	tab[0] = (int)nb;
	nb = nb - tab[0];
printf("NB before tab1 : %f\n", nb);
	nb = nb * ft_tento(10, qte);
printf("(((((  tab2 : %d, qte : %d, FTsizenb : %d\n", tab[2], qte, sizenbchar(10, 0, nb, 'f'));
printf("NB before tab1 : %f\n", nb);
	tab[1] = nb;
//printf("tab1 : %d\n", tab[1]);
	if (tab[0] > 0 && ((int)nb % 10) != 0)
		tab[1]++;
	while (tab[1] != 0 && tab[1] % 10 == 0)
		tab[1] = tab[1] / 10;

	tab[2] = (sizenbchar(10, 0, cp, 'f') - (sizenbchar(10, 0, tab[0], 'd') + sizenbchar(10, 0, tab[1], 'd')));
//printf("qte : %d, cp : %f, cp_tento : %f, tab[1] : %d\n",qte, cp, cp * ft_tento(10, qte), tab[1]); 


	if ((cp * ft_tento(10, qte) - tab[1] != 0))
		tab[1]++;
/*
	if ((int)((cp * (ft_tento(10, qte))) - tab[1]) % 10 == 0)
	{
	write(1, "W", 1);	
	tab[1]++;
	}*/
//	if (tab[1] != 0 && tab[1] < 9)
//		tab[1]++;
	return (tab);
}

// c'est ok sauf si nb < 0.000001

int	main(int argc, char **argv)
{
(void)argc;
double *n = (double*)malloc(sizeof(double) * 50);
ft_bzero(n, sizeof(double) * 50);
printf("NB : %.50f\n", *n);

*n = 1.345;
// *n = 0.3333333333333330;
printf("NB : %.50f\n", *n);

printf("Total : %d\n", sizenbchar(10, 0, *n, 'f'));
printf(">> : %d .\n", sizenbchar(10, 0, *n, 'd'));
printf("<< : %d\n", sizenbchar(10, 0, *n, 'z'));

int *tab = ft_splitdouble(*n);
//int *tab = ft_splitdouble(atof(argv[1]));
printf("tab2 : %d\n", tab[2]);
	printf("F %d.", tab[0]);
	while (tab[1] != 0 && tab[2]-- > 1)
		printf("0");
	printf("%d\n", tab[1]);
	printf("T %.10f\n", *n);
return (0);
}
