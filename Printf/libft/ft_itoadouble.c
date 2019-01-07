#include "libft.h"
#include <stdio.h>

void	printsave(char *str, int save, int i)
{
	str[i] = save % 10 + '0';
	save = save / 10;
}

void	putdoublechar(long double n, char *str, int size, int max)
{
	long double	save;
	int		i;

	i = size;
	if (str[size - 1] == '.')
		size--;
	i--;
	while (n >= 1)
	{
		save = n;
		while (save > 2147483647)
			save = save - 2000000000;
		printsave(str, (int)save % 10, i);
		i--;
		n = n / 10;
	}
	(void)max;
}

/* on envoie soit 'z' de nb ou le nb de digits a afficher selon ft_printf pour imiter le comportement de printf */
char	*ft_itoadouble(long double nb, int z, int max) // AJOUTER ICI LE NB DE CHIFFRE A AFFICHER APRES LA VIRGULE ('z')
{
	char	*str;
	int		i;
	int		d;
	int		iz;

	iz = ft_qtenb((int)nb, 'z', 10, max);
	d = ft_qtebignb(nb, 10);
//printf("\nMalloc a %d\n", d + z + 2);
	str = malloc(sizeof(char) * d + z + 2);
	str[z + d + 1] = '\0';
	str[d] = '.';
	i = d + 1;
	putdoublechar(nb, str, ft_qtebignb(nb, 10), 9);
	while (nb > 2147483647)			/* gerer n pour enlever left dot part */
		nb = nb - 2000000000.;
	nb = nb - (int)nb;
	while (i < z + d + 1)			/* ici on s'occupe des decimals digits*/
	{
		nb = nb * 10;
		str[i] = (int)nb + '0';
		nb = nb - (int)nb;
		i++;
	}
	return (str);
}
