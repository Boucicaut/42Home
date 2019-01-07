#include "ft_printf.h"

void	pprintall(int j, int *lim)
{
	int	jj;

	jj = lim[1] > j ? lim[1] : j;
	while (lim[0]-- - 1 > jj)
		ft_putchar(' '); // ou des '0'
}

void	pourcentp(va_list args, char *str, int *i)
{
	long	*nb;
	int		j;
	char	*res;

	j = -1;
	nb = va_arg(args, void*);
	res = ft_convertbase((long)(nb), 16);
	while (res[j++])
		res[j] = ft_tolower(res[j]);
	pprintall(j, setuplim(str, i, args));
	ft_putstr("0x");
	ft_putstr(res);
	while (str[*i] != 'p')
		*i = *i + 1;
	*i = *i + 1;
}
