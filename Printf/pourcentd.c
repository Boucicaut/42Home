#include "ft_printf.h"

void	pourcents(va_list args, char *str, int *i)
{
	ft_putstr((char*)va_arg(args, int*));
	(void)i;
	(void)str;
}

void	pourcentc(va_list args, char *str, int *i)
{
	ft_putchar((char)va_arg(args, int));
	(void)i;
	(void)str;
}


void	pourcentdLL(va_list args, char *str, int *i) 
{
	int	qtenb;
	long long int	nb;
	int	*tab;

	tab = setlim(str, i, args);
	nb = va_arg(args, long long int);
	qtenb = ft_qtebignb(nb, 10);
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	while (tab[0]-- > tab[1])
		ft_putchar(' ');	// ou des '0' a voir
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	ft_putbignbr(nb);
	while (ft_isdigit(str[*i]) || str[*i] == 'd')
		*i = *i + 1;
	*i = *i - 1;
}

void	pourcentdNOL(va_list args, char *str, int *i)
{
	int	qtenb;
	int	nb;
	int	*tab;

	tab = setlim(str, i, args);
	nb = va_arg(args, long long int);
	qtenb = ft_qtenb(nb, 'd', 10, 16);
	tab[1] = tab[1] > qtenb ? tab[1] : qtenb;
	while (tab[0]-- > tab[1])
		ft_putchar(' ');	// ou des '0' a voir
	while (tab[1]-- > qtenb)
		ft_putchar('0');
	ft_putnbr(nb);
	while (ft_isdigit(str[*i]) || str[*i] == 'd')
		*i = *i + 1;
	*i = *i - 1;
}

void	pourcentd(va_list args, char *str, int *i)
{
	int	j;

	j = *i;
	while (str[*i] == '.' || str[*i] == '*' || (ft_isdigit(str[*i])))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
		*i = j;	
		pourcentdLL(args,str,i);
	}
	else
	{
		*i = j;	
		pourcentdNOL(args,str,i);
	}
}


