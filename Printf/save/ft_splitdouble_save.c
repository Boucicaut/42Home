#include "libft.h"
#include <stdio.h>

int	verififnine(double *nb) // EST CE QUE 10 EST ASSEZ ? OU TROP ?
{
	int	i;

	i = 10;
	while (i > 0)
	{
		*nb = *nb * 10;
		if ((int)*nb % 10 == 9)
			return (1);
		i--;
	}
	return (0);
}
									// CHECK AVEC IFNINE (VOI NB)
int	*ft_splitdouble(double nb)
{
	int		*tab;
	int 	qte;
	double	cp;
	int		qtef;
	char	*str;
	double	n;
	int		i;

	i = 0;
	qtef = sizenbchar(10, nb, 'f');
	cp = nb;
	n = nb;
	if (!(tab = malloc(sizeof(int) * 3)))
		return (NULL);
	qte = sizenbchar(10, nb, 'z'); // !! 'f' c'est tout, +1 donc si 0...

//--------- itoa double
	str = malloc(sizeof(char) * qte + 2);
	str = ft_strcpy(str, ft_itoa((int)nb));
	str[qte + 2] = '\0';
	str[sizenbchar(10, nb, 'd')] = '.';

	i = sizenbchar(10, nb, 'd') + 1;
	n = n - (int)n;
	while (i < qte + 2)
	{
//printf("Zzzz n : %f &&&&&   i : %d\n", n, i);
		n = n * 10;
		str[i] = (int)n + '0';
		n = n - (int)n;
		i++;
	}
//printf("Zzzz n : %f &&&&&   i : %d\n", n, i);
	if (((int)(n * 10)) == 9)
		str[i - 1] = str[i - 1] + 1;

	printf("\n            > %s <\n", str);
//--------
	tab[0] = (int)nb;
	nb = nb - tab[0];
//printf("NB before tab1 : %f\n", nb);
	nb = nb * ft_tento(10, qte);
//printf("(((((  tab2 : %d, qte : %d, FTsizenb : %d\n", tab[2], qte, sizenbchar(10, nb, 'f'));
//printf("NB f : %.20f\n", nb);

	cp = nb;
//printf("CP : %f\n", cp);

	tab[1] = (int)cp;
	if (verififnine(&nb) == 1)
		tab[1]++;

//printf("NB d : %d\n", (int)nb);
//printf("tab1 : %d\n", tab[1]);

/*	if (tab[0] > 0 && ((int)nb % 10) != 0)
		tab[1]++;
	while (tab[1] != 0 && tab[1] % 10 == 0)
		tab[1] = tab[1] / 10;
*/
	tab[2] = qtef - (sizenbchar(10, tab[0], 'd') + sizenbchar(10, tab[1], 'd'));
//printf("qte : %d, cp : %f, cp_tento : %f, tab[1] : %d\n",qte, cp, cp * ft_tento(10, qte), tab[1]); 

/*
	if ((cp * ft_tento(10, qte) - tab[1] != 0))
		tab[1]++;
*/

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
(void)argv;
double *n = (double*)malloc(sizeof(double) * 50);
ft_bzero(n, sizeof(double) * 50);
printf("NB : %.50f\n", *n);

*n = 4.00521474363465783648;
// *n = 0.3333333333333330;
printf("NB : %.50f\n", *n);

printf("Total : %d\n", sizenbchar(10, *n, 'f'));
printf(">> : %d .\n", sizenbchar(10, *n, 'd'));
printf("<< : %d\n", sizenbchar(10, *n, 'z'));

int *tab = ft_splitdouble(*n);
//int *tab = ft_splitdouble(atof(argv[1]));
//printf("tab2 : %d\n", tab[2]);
	printf("F TAB[0] : %d. ", tab[0]);
	while (tab[1] != 0 && tab[2]-- > 0)
		printf("0");
	printf("TAB[1] : %d\n", tab[1]);
	printf("T %.10f\n", *n);
return (0);
}
