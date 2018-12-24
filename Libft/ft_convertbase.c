#include "Libft/libft.h"

static int	sizechar(int base, int i)
{
	if (i == 0)
		return (1);
	else
		return (base * sizechar(base, i - 1));
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
		i++;
		nb = -nb;
	}
	while (sizechar(base, i) <= nb)
		i++;
	stres = ft_strnew(i + neg);
	i += neg;
	while (i-- > 0)
	{
		stres[i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	if (neg == 1)
		stres[0] = '-';
	return (stres);
}
