#include "libft.h"

int	*ft_splitdouble(double nb)
{
	int	*tab;
	int	entier;
	char	*dec;
	int qte;

	if (!(tab = malloc(sizeof(int) * 2)))
		return (NULL);
	qte = sizenbchar(10, 0, nb, 'f');
	entier = 0;
	dec = 0;
	tab[0] = (int)nb;
	nb = nb - tab[0];
	nb = nb * ft_tento(10, qte);
	tab[1] = nb;
	if (((int)nb % 10) != 0)
		tab[1]++;
	while (tab[1] != 0 && tab[1] % 10 == 0)
		tab[1] = tab[1] / 10;
	return (tab);
}
