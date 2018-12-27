#include "libft.h"

int	sizenbchar(int base, int i, int nb)
{
	int	res;

	res = 1;
	while (res <= nb)
	{
		i++;
		res = res * base;
	}
	return (i);
}

char		*ft_convertbase(int nb, int base)
{
	int		i;
	char	*stres;
	int		neg;

	neg = 0;
	i = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	i = sizenbchar(base, i, nb);
	stres = ft_strnew(i + neg);
	i = i + neg;
	while (i-- >= 0)
	{
		stres[i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	if (neg == 1)
		stres[0] = '-';
	return (stres);
}
