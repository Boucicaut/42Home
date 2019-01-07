#include "libft/libft.h"
#include <stdio.h>

char		*ft_tryconvertbase(int nb, int cbase, int base)
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
	i = ft_qtenb(nb, 'd', base, 0);
	stres = ft_strnew(i + neg);
	i = i + neg;
	while (i-- >= 0)
	{
		stres[i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
printf("stres[i] : %c ||| nb m base : %d\n", stres[i], nb%base);
		nb = nb / base;
	}
	if (neg == 1)
		stres[0] = '-';
	(void)cbase;
	return (stres);
}

int	main(void)
{
	int	a = 0x7F;
	printf("a : %s et 0xa : %s\n", ft_tryconvertbase(a, 16, 10), ft_tryconvertbase(a, 16, 16)); 
	return (0);
}
