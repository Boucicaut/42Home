#include <stdio.h>
#include "ft_printf.h"

void	roundednine(char *str, int i)
{
	int	ii;
	ii = i;
	while (str[i] != '.' && str[i] == '9')
	{
		str[i] = '0';
		i--;
	}
	if (str[i] == '.')
		i--;
	str[i]++;
}

void	roundit(char *nbchar, int lim2, int z, int d)
{
	int	i;
	int	fullzero;

	fullzero = 1;
	i = 0;
	while (nbchar[i])
		i++;
	i--;
	if (nbchar[i] != '0')
			fullzero = 0;
	if (fullzero == 0 && d > 15)
		nbchar[i] = fullzero == 1 ? nbchar[i] : nbchar[i]++;
	else if (nbchar[i] == '9') //&& d+z >= 16)
		roundednine(nbchar, i);
	else if (fullzero == 0 && z > 15 && z+d >= 16 && z > 0 && lim2 < 16)
		nbchar[i]++;
	else if (fullzero == 0 && lim2 < 16)
		nbchar[i]++;
}

int		*setuplim(char *str, int *i, va_list args)
{
	int	*lim;

	if (!(lim = malloc(sizeof(int) * 2)))
		return (NULL);
	lim[0] = 0;
	lim[1] = 0;
	if (str[*i] == '*')
		lim[0] = va_arg(args, int);
	if (str[*i] && ft_isdigit(str[*i])) /* SETUP lim1 */
		lim[0] = ft_atoi(&str[*i]);
	while (str[*i] && str[*i] != 'f')				/* SETUP lim2 */
	{
		if (str[*i] == '.')
		{
			*i = *i + 1;
			if (str[*i] == '*')
				break ;
			lim[1] = ft_atoi(&str[*i]);
		}
		*i = *i + 1;
	}
	if (str[*i] == '*')
		lim[1] = va_arg(args, int);
	if (lim[1] == 0)
		lim[1] = 6;
	return (lim);
}

void	pourcentfNL(va_list args, char *str, int *i)
{
	double	nb;
	char	*nbchar;
	int		neg;
	int		j;
	int		*lim;

	lim = setuplim(str, i, args);
	j = 0;
	neg = 1;
	nb = va_arg(args, double);
	if (nb < 0)
		nb = -nb;
	else
		neg = 0;
	nbchar = ft_itoadouble(nb, lim[1], 16);
	roundit(nbchar, lim[1], ft_qtenb(nb, 'z', 10, 16), ft_qtenb(nb, 'd', 10, 16));
	while (lim[0]-- > (ft_qtenb(nb, 'd', 10, 16) + lim[1] + 1 + neg))
		ft_putchar(' ');
	if (neg == 1)
		ft_putchar('-');
	ft_putstr(nbchar);
	while (ft_isdigit(str[*i]) || str[*i] == 'f')
		*i = *i + 1;
	*i = *i - 1;
	free(lim);
}

void	pourcentfL(va_list args, char *str, int *i)
{
	long double	nb;
	char	*nbchar;
	int		neg;
	int		j;
	int		*lim;

	lim = setuplim(str, i, args);
	j = 0;
	neg = 1;
	nb = va_arg(args, long double);
	if (nb < 0)
		nb = -nb;
	else
		neg = 0;
	nbchar = ft_itoadouble(nb, lim[1], 20);
//printf("\nnb : %Lf, nbchar : %s, qteD : %d, qteZ : %d\n", nb, nbchar, ft_qtebignb(nb, 10), ft_qtenb(nb, 'z', 10, 16));
//printf("\nLim : %d , %d\n", lim[0], lim[1]);
//getchar();
	roundit(nbchar, lim[1], ft_qtenb((int)nb, 'z', 10, 16), ft_qtebignb(nb, 10));
	while (lim[0]-- > (ft_qtebignb(nb, 10) + lim[1] + 1 + neg))
		ft_putchar(' ');
	if (neg == 1)
		ft_putchar('-');
	ft_putstr(nbchar);
	while (ft_isdigit(str[*i]) || str[*i] == 'f')
		*i = *i + 1;
	*i = *i - 1;
	free(lim);
}

void	pourcentf(va_list args, char *str, int *i)
{
	int	j;

	j = *i;
	while (str[*i] == '.' || str[*i] == '*' || ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == 'l' || str[*i] == 'L')
	{
		*i = j;
		pourcentfL(args, str, i);
	}
	else
	{
		*i = j;
		pourcentfNL(args, str, i);
	}
}
