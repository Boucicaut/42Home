#include "libft.h"

char		*ft_convertbase(long long int nb, int base)
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
	i = ft_qtebignb(nb, base);
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
