#include "ft_printf.h"

void	fillcharu(long long int nb, char *str, int j)
{
	while (nb > 9)
	{
		str[j] = (nb % 10) + '0';
		nb = (nb - (nb % 10)) / 10;
		j--;
	}
	str[j] = (nb % 10) + '0';
}


void	pourcentuNLL(va_list args, char *str, int *i)
{
	int	qtenb;
	int	nb;
	int	*tab;
	char	*res;

	tab = setlim(str, i, args);
	nb = va_arg(args, int);
	qtenb = ft_qtenb(nb, 'd', 10, 16);
	if (!(res = malloc(sizeof(char) * qtenb + 1)))
		return ;
	res[qtenb] = '\0';
	fillcharu(nb, res, qtenb - 1);
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	while (tab[0]-- > tab[1])
		ft_putchar(' ');	// ou des '0' a voir
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	ft_putstr(res);
	while (ft_isdigit(str[*i]) || str[*i] == 'u')
		*i = *i + 1;
	*i = *i - 1;
}

void	pourcentuLL(va_list args, char *str, int *i)
{
	int	qtenb;
	long long int	nb;
	int	*tab;
	char	*res;

	tab = setlim(str, i, args);
	nb = va_arg(args, long long int);
	qtenb = ft_qtebignb(nb, 10);
//printf("\nLong : %llu qte : %d\n", nb, qtenb);
	if (!(res = malloc(sizeof(char) * qtenb + 1)))
		return ;
	res[qtenb] = '\0';
	fillcharu(nb, res, qtenb - 1);
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	while (tab[0]-- > tab[1])
		ft_putchar(' ');	// ou des '0' a voir
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	ft_putstr(res);
	while (ft_isdigit(str[*i]) || str[*i] == 'u')
		*i = *i + 1;
	*i = *i - 1;
}

void	pourcentu(va_list args, char *str, int *i)
{
	int	j;

	j = *i;
	while (str[*i] == '.' || str[*i] == '*' || ft_isdigit(str[*i]))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
		*i = j;
		pourcentuLL(args, str, i);
	}
	else
	{
		*i = j;
		pourcentuNLL(args, str, i);
	}
}
