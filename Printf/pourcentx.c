#include "ft_printf.h"

void	hexatolower(char *res)
{
	int	j;

	j = 0;
	while (res[j])
	{
		res[j] = ft_tolower(res[j]);
		j++;
	}
}

int		*setlim(char *str, int *i, va_list args)
{
	int	*tab;
	if (!(tab = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	tab[0] = 0;
	tab[1] = 0;
	if (str[*i] == '*')
		tab[0] = va_arg(args, int);
	else
		tab[0] = ft_atoi(&str[*i]);
	if (str[*i] == '.')
		*i += 1;
	if (str[*i] == '*')
		tab[1] = va_arg(args, int);
	else
		tab[1] = ft_atoi(&str[*i]);
	return (tab);
}

void	hexaprintall(int j, int x, int *lim)
{
	int	jj;

	jj = j;
	lim[1] = lim[1] > 0 ? lim[1] : jj;
	while (j++ + (lim[1] - jj) < lim[0] + (x*2))
		ft_putchar(' ');
	if (x == 1)
		ft_putstr("0x");
	while (lim[1]-- > jj)
		ft_putchar('0');
}

void	pourcentxNOEL(va_list args, char *str, int *i)
{
	int		nb;
	char	*res;
	int		j;
	int		x;
	int		*lim;

	j = *i;
	x = 0;
	if (str[j] == '#')
	{
		j = j + 1;
		x = 1;
	}
	lim = setlim(str, i, args);
	nb = va_arg(args, int);
	res = ft_convertbase(nb, 16);
	j++;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '.' || str[j] == 'l' || str[j] == 'h'))
		j++;
	if (str[j] == 'x')
		hexatolower(res);

	hexaprintall(ft_qtenb(nb, 'd', 16, 16), x, lim);
	ft_putstr(res);	
}

void	pourcentxLL(va_list args, char *str, int *i)
{
	long long int	nb;
	char	*res;
	int		j;
	int		x;
	int		*lim;

	j = *i;
	x = 0;
	if (str[j] == '#')
	{
		j = j + 1;
		x = 1;
	}
	lim = setlim(str, i, args);
	nb = va_arg(args, long long int);
	res = ft_convertbase(nb, 16);
	j++;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '.'))
		j++;
	if (str[j] == 'x')
		hexatolower(res);
	hexaprintall(ft_qtebignb(nb, 16), x, lim);
	ft_putstr(res);	
}


void	pourcentx(va_list args, char *str, int *i)
{
	int	j;

	j = *i;
	while (str[*i] == '.' || str[*i] == '*' || (ft_isdigit(str[*i])))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
		*i = str[*i + 1] == 'l' ? *i + 1 : *i;
		pourcentxLL(args, str, i);
	}
	else
	{
		*i = str[*i + 1] == 'l' ? *i + 1 : *i;
		pourcentxNOEL(args, str, i);
	}
}
