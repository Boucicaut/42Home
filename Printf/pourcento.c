#include "ft_printf.h"

void	octprintall(int j, int *lim)
{
	int	jj;

	jj = j;
	lim[1] = lim[1] > 0 ? lim[1] : jj;
	while (j++ + (lim[1] - jj) < lim[0])
		ft_putchar(' ');
	while (lim[1]-- - jj > 0)
		ft_putchar('0');
}

void	pourcentoNOLL(va_list args, char *str, int *i)
{
	int		nb;
	char	*res;
	int		j;

	j = *i;
	nb = va_arg(args, int);
	res = ft_convertbase(nb, 8);
	j++;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '.'))
		j++;
	octprintall(ft_qtenb(nb, 'd', 8, 16), setlim(str, i, args));
	ft_putstr(res);	
}

void	pourcentoLL(va_list args, char *str, int *i)
{
	unsigned long long int	nb;
	char	*res;
	int		j;

	j = *i;
	nb = va_arg(args, unsigned long long int);
	res = ft_convertbase(nb, 8);
	j++;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '.'))
		j++;
	octprintall(ft_qtebignb(nb, 8), setlim(str, i, args));
	ft_putstr(res);	
}

void	pourcento(va_list args, char *str, int *i)
{
	int		j;

	j = *i;
	while (str[*i] == '.' || str[*i] == '*' || ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
		*i = j;
		pourcentoLL(args, str, i);
	}
	else
	{
		*i = j;
		pourcentoNOLL(args, str, i);
	}
}
